//				FORSORT
//
// Author: Stew Forster (stew675@gmail.com)	Copyright (C) 2021-2025
//
// This is my implementation of what I believe to be an O(nlogn) in-place
// adaptive merge-sort style algorithm.

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

#define CONCAT(x, y) x ## _ ## y
#define MAKE_STR(x, y) CONCAT(x,y)
#define NAME(x) MAKE_STR(x, VAR)
#define CALL(x) NAME(x)

#ifndef FOR_GLOBAL_DEFS
#define FOR_GLOBAL_DEFS

// Uncomment to turn on debugging output for the uniques extraction and merging system
//#define	DEBUG_UNIQUE_PROCESSING

// Uncomment to turn on general debugging output
// #define	DEBUG

enum {
	LEAP_LEFT = 0,
	LEAP_RIGHT,
};

#define	IS_LT	is_lt

// Sparingly used to guide compiling optimization
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)

// Experimentally 13 appears to be the best binary insertion cutoff
#define	BINARY_INSERTION_MIN	13

// Experimentally, 7 appears best as the sprint activation value
#define	SPRINT_ACTIVATE 	7
#define	SPRINT_EXIT_PENALTY	2

// Since the merge_duplicates algorithm uses a 1:2 split ratio, it's best to
// have MAX_DUPS be an even power of 3, so a value of 27 is perfect here.
// With a MAX_DUPS value of 27, if the data set is so degenerate as to fill up
// the duplicates table, then dropping out and sorting is trivially fast
#define	MAX_DUPS 27
#endif	// FOR_GLOBAL_DEFS

// A structure to manage the state of the stable sort algorithm
struct NAME(stable_state) {
	// All sizes are in numbers of entries, not bytes
	VAR	*merged_dups[MAX_DUPS + 1];	// Merged up duplicates
	size_t	num_merged;			// No. of merged duplicate entries
	VAR	*free_dups[MAX_DUPS];		// Unmerged duplicates
	size_t	num_free;			// No. of unmerged duplicate entries
	VAR	*work_space;			// Work Space
	size_t	work_size;			// Size of work space
	bool	work_sorted;			// If work-space is sorted or not
	VAR	*rest;				// Rest of the main array
	size_t	rest_size;			// Size of the rest
	VAR	*pe;				// End of main array
};


//---------------------------------------------------------------------------//
//----------------- START OF SPECIFIC ELEMENT SIZE DEFINES ------------------//
//---------------------------------------------------------------------------//

#ifdef UNTYPED

// Generic unaligned/odd-byte size handling

static inline void
memswap(void * restrict p1, void * restrict p2, size_t n)
{
	enum { SWAP_GENERIC_SIZE = 32 };

	unsigned VAR tmp[SWAP_GENERIC_SIZE];

	while (n > SWAP_GENERIC_SIZE) {
		mempcpy(tmp, p1, SWAP_GENERIC_SIZE);
		p1 = __mempcpy(p1, p2, SWAP_GENERIC_SIZE);
		p2 = __mempcpy(p2, tmp, SWAP_GENERIC_SIZE);
		n -= SWAP_GENERIC_SIZE;
	}
	while (n > 0) {
		unsigned VAR t = ((unsigned VAR *)p1)[--n];
		((unsigned VAR *)p1)[n] = ((unsigned VAR *)p2)[n];
		((unsigned VAR *)p2)[n] = t;
	}
} // memswap

#define	SWAP(_xa_, _xb_)	memswap((_xa_), (_xb_), ES)

static void
NAME(insertion_sort)(VAR *pa, const size_t n, COMMON_PARAMS)
{
	VAR	*pe = pa + (n * ES);

	for (VAR *ta = pa + ES; ta != pe; ta += ES)
		for (VAR *tb = ta; tb != pa && IS_LT(tb, tb - ES); tb -= ES)
			SWAP(tb, tb - ES);
} // insertion_sort_char

#else

// Type specific object size handling

// This double-assignment swap seems a hair faster than when using a single
// temporary variable.  I suspect that the gcc optimizer is able to re-use the
// registers containing values from before for certain sequences.
// My other suspicion is that memory->register and register->memory is simply
// just faster than memory->memory swaps

#define	SWAP(_xa_, _xb_)			\
	{					\
		VAR xa = *(VAR *)(_xa_);	\
		VAR xb = *(VAR *)(_xb_);	\
		*(VAR *)(_xb_) = xa;		\
		*(VAR *)(_xa_) = xb;		\
	}

static void
NAME(insertion_sort)(VAR *a, const size_t n, COMMON_PARAMS)
{
	VAR *pa = (VAR *)a;
	VAR *ta = pa + ES;
	VAR *pe = pa + n;

	if (n > BINARY_INSERTION_MIN)
		pe = pa + BINARY_INSERTION_MIN;

	// Regular insertion sort for first BINARY_INSERTION_MIN items
	for ( ; ta != pe; ta++) {
		if (IS_LT(ta, ta - ES)) {
			VAR t[ES] = {*ta}, *tb = ta;
			do {
				*tb = *(tb - ES);
			} while ((--tb != pa) && IS_LT(t, tb - ES));
			*tb = *t;
		}
	}

	if (n <= BINARY_INSERTION_MIN)
		return;

	// Now use binary insertion sort to place the elements
	// from the second set into the first
	for (pe = pa + n; ta != pe; ta++) {
		if (IS_LT(ta, ta - ES)) {
			// Find where to insert it
			size_t min = 0, max = (ta - pa) - ES;
			size_t pos = max >> 1;
			VAR *tb = pa + (pos * ES), *tc = ta, t = *ta;

			while (min < max) {
				// The following 3 lines implement
				// this logic in a branchless manner
				// if (IS_LT(ta, tb))
				// 	max = pos;
				// else
				// 	min = pos + 1;
				int result = !!(IS_LT(ta, tb));
				max = (max * !result) + (pos * result);
				min = (min * result) + ((pos + 1) * !result);

				pos = (min + max) >> 1;
				tb = pa + (pos * ES);
			}
			for (size_t num = (ta - tb); num--; tc--)
				*tc = *(tc - ES);
			*tb = t;
		}
	}
} // insertion_sort

#endif

//_____________________________________________________________________________


// Debug sort check testing
static void
NAME(test_sorted)(VAR *pa, size_t n, COMMON_PARAMS)
{
	VAR	*pe = pa + (n * ES);
	for (VAR *sp = pa + ES; sp < pe; sp += ES)
		if (IS_LT(sp, sp - ES)) {
			print_array(pa, n);
			printf("Section isn't sorted\n");
			exit(1);
		}
} // test_sorted


// Swaps two contiguous blocks of differing lengths in place efficiently
// Basically my version of the well known Block Rotate() functionality
// that avoids the use of explicit, or implicit, division or multiplication
static void
NAME(block_rotate)(VAR *a, VAR *b, VAR *e, COMMON_PARAMS)
{
	size_t	gapa = b - a, gapb = e - b;
	while (gapa && gapb) {
		if (gapa < gapb) {
			// s = source, d = destination
			// (Not that source and dest make sense when swapping)
			for (VAR *s = a, *d = a + gapb; d != e; s += ES, d += ES)
				SWAP(s, d);
			e -= gapa;
			gapb = e - b;
		} else {
			for (VAR *s = b, *d = a; s != e; s += ES, d += ES)
				SWAP(s, d);
			a += gapb;
			gapa = b - a;
		}
	}
} // block_rotate


static void __attribute__((noinline))
NAME(block_swap)(VAR *a, VAR *b, size_t n, COMMON_PARAMS)
{
	while (n--) {
		SWAP(a, b);
		a += ES;
		b += ES;
	}
} // block_swap

#ifndef GET_SPLIT_STACK_SIZE
#define GET_SPLIT_STACK_SIZE
static size_t
get_split_stack_size(size_t n)
{
	if (n < 3)
		return 2;

	size_t sz = msb64(n);

	// Stack size needs to be l(2) / l(1.25), which is ~3.1063 times the
	// index of the most significant bit. 28/9 is 3.111.., and so it's a
	// nice integer approximation.
	sz = ((sz * 28) / 9) + 1;

	return sz;
} // get_split_stack_size
#endif

// This in-place split merge algorithm started off life as a variant of ShiftMerge
// below, but I was looking for a way to solve the multiple degenerate scenarios
// where unbounded stack recursion could occur.  In the end, I couldn't fully
// solve some of those without making the code complex and branch inefficient
// and so split_merge_in_place() was born.  On purely random data, this method
// slightly outperforms shift_merge_in_place() below, but on anything remotely
// structured shift_merge() will quickly overtake this function, and this is
// why split_merge() acts as a fall-back.  When shift_merge() gets bogged down.
// then it's split_merge's time to shine!
static void
NAME(split_merge_in_place)(VAR *pa, VAR *pb, VAR *pe, COMMON_PARAMS)
{
	assert(pb > pa);
	assert(pe > pb);

	// Check if we need to do anything at all
	if (!IS_LT(pb, pb - ES))
		return;

	// The stack_size is * 2 due to two pointers per stack entry.  Even
	// if we're asked to merge 2^64 items, the stack will be just 3.2KB
	size_t	bs, ns = NITEM(pb - pa);
	size_t	stack_size = get_split_stack_size(ns) * 2;
	_Alignas(64) VAR *_stack[stack_size];
	VAR	**stack = _stack, *rp, *spa;

split_again:
	bs = pb - pa;		// Determine the size of A

	// Just insert merge single items. We already know that *PB < *PA
	if (bs == ES) {
		do {
			SWAP(pa, pb);
			pa = pb;
			pb += ES;
		} while ((pb != pe) && IS_LT(pb, pa));
		goto split_pop;
	}

	// Split off 1/5th of the items.  Ensure that this formula can never
	// return a 0. We're guaranteed to have at least 2 items though
	// The imbalanced split here improves algorithmic performance.
	ns = ((NITEM(bs) + 3) / 5) * ES;

	// Advance the PA->PB block up as far as we can
	for (rp = pb + bs; (rp < pe) && IS_LT(rp - ES, pa); rp += bs) {
		CALL(block_swap)(pa, pb, NITEM(bs), COMMON_ARGS);
		pa += bs;
		pb += bs;
	}

	// Split the A block into two, and keep trying with the remainder
	spa = pa + ns;
	if (IS_LT(pb, pb - ES)) {
		// Push a new split point to the work stack
		*stack++ = pa;
		*stack++ = spa;

		pa = spa;
		goto split_again;
	}

split_pop:
	while (stack != _stack) {
		pb = *--stack;
		pa = *--stack;

		if (IS_LT(pb, pb - ES))
			goto split_again;
	}
#undef	SPLIT_SIZE
} // split_merge_in_place


// Merges two sorted sub-arrays together using insertion sort
// This is horribly inefficient for all but the smallest arrays
static void
NAME(insertion_merge_in_place)(VAR * pa, VAR * pb,
			 VAR * pe, COMMON_PARAMS)
{
	VAR	*tb = pe;

	do {
		pe = tb - ES; tb = pb - ES; pb = tb;
		while ((tb != pe) && IS_LT(tb + ES, tb)) {
			SWAP(tb + ES, tb);
			tb += ES;
		}
	} while ((pb != pa) && IS_LT(pb, pb - ES));
} // insertion_merge_in_place


#define	SHIFT_STACK_PUSH(s1, s2, s3) 	\
	{ *stack++ = s1; *stack++ = s2; *stack++ = s3; }

#define	SHIFT_STACK_POP(s1, s2, s3) \
	{ s3 = *--stack; s2 = *--stack; s1 = *--stack; }

// This is just the reverse of shift_merge_in_place().  I'll leave
// less comments in this function as a result
static void
NAME(reverse_merge_in_place)(VAR *pa, VAR *pb, VAR *pe, COMMON_PARAMS)
{
	assert(pb > pa);
	assert(pe > pb);

	// Check if we need to do anything at all before proceeding
	if (!IS_LT(pb, pb - ES))
		return;

	size_t	stack_size = get_split_stack_size(NITEM(pe - pb)) * 3;
	_Alignas(64) VAR *_stack[stack_size];
	VAR	**stack = _stack, **maxstack = stack + stack_size;
	VAR	*rp, *sp;
	size_t	bs;

reverse_again:
	// Just insert merge single items. We already know that *PB < *PA
	if ((bs = (pe - pb)) == ES) {
		do {	// Bubble Down
			SWAP(pb, pb - ES);  pb -= ES;
		} while ((pb != pa) && IS_LT(pb, pb - ES));
		goto reverse_pos;
	} else if ((pa + ES) == pb) {
		do {	// Bubble Up
			SWAP(pa, pb);  pa = pb;  pb = pb + ES;
		} while (pb != pe && IS_LT(pb, pa));
		goto reverse_pos;
	}

	// Insertion MIP is slightly faster for very small sorted array pairs
	if ((pe - pa) < (ES << 3)) {
		CALL(insertion_merge_in_place)(pa, pb, pe, COMMON_ARGS);
		goto reverse_pos;
	}

	// Shift entirety of PB->PE down as far as we can
	for (sp = pb - bs; sp >= pa && IS_LT(pe - ES, sp); sp -= bs) {
		CALL(block_swap)(sp, pb, NITEM(bs), COMMON_ARGS);
		pb -= bs;  pe -= bs;
	}

	// Handle scenario where our block cannot fit within what remains
	if (sp < pa) {
		if (pb == pa)
			goto reverse_pos;

		// reverse_merge_in_place() won't re-reverse the direction
		// back to shift_merge_in_place.  This is to prevent
		// potential stack overflows.  Instead it will just persist,
		// and if it runs out of stack, it'll fall back to the
		// fully stack bounded split_merge_in_place().  I've never
		// seen it happen, but that doesn't meant it cannot

		bs = pb - pa;
	}

	// Find spot within PB->PE to split it at.
	if (bs >= (ES << 3)) {	// Binary search on larger sets
		size_t	min = 0, max = NITEM(bs), pos = max >> 1;

		sp = pb - (pos * ES);
		rp = pb + (pos * ES);

		while (min < max) {
			int res = !!(IS_LT(rp, sp - ES));
			min = (!res * min) + (res * (pos + res));
			max = (res * max) + (!res * pos);

			pos = (min + max) >> 1;
			sp = pb - (pos * ES);
			rp = pb + (pos * ES);
		}
	} else {	// Linear scan is faster for smaller sets
		sp = pb - bs;	rp = pb + bs;
		for ( ; (sp != pb) && !IS_LT(rp - ES, sp); sp += ES, rp -= ES);
	}

	// If nothing to swap, we're done here
	if (pb == sp)
		goto reverse_pos;

	// Do a single shift at the split point
	for (VAR *ta = sp, *tb = pb; ta != pb; ta += ES, tb += ES)
		SWAP(ta, tb);

	// See forward_merge_in_place() for an explanation of the following
	// This here is just the reverse direction of that same thing.
	bs = (sp > pa) && IS_LT(sp, sp - ES);
	if (IS_LT(rp, rp - ES)) {
		if (bs) {
			// If our stack is about to over-flow, move to use the
			// slower, but resilient algorithm that handles degenerate
			// scenarios without issue.
			SHIFT_STACK_PUSH(pa, sp, pb);
			if (unlikely(stack == maxstack)) {
				CALL(split_merge_in_place)(pb, rp, pe, COMMON_ARGS);
				goto reverse_pos;
			}
		}

		pa = pb;
		pb = rp;
		goto reverse_again;
	} else if (bs) {
		pe = pb;
		pb = sp;
		goto reverse_again;
	}
reverse_pos:
	if (stack != _stack) {
		SHIFT_STACK_POP(pa, pb, pe);
		goto reverse_again;
	}
} // reverse_merge_in_place


// This is what everything is based on, and I call it shift_merge_in_place()
//
// At its heart, the following algorithm is a variation on PowerMerge that
// solves a number of PowerMerge's glaring issues with unbounded stack
// recursion, and other inefficiencies inherent to the base algorithm.
//
// This is implemented as an iterative function that uses a work stack to
// note the location of split points to be revisited later to merge in.
//
// Assumes NA and NB are greater than zero
static void
NAME(shift_merge_in_place)(VAR *pa, VAR *pb, VAR *pe, COMMON_PARAMS)
{
	assert(pb > pa);
	assert(pe > pb);

	// Check if we need to do anything at all before proceeding
	if (!IS_LT(pb, pb - ES))
		return;

	// The work stack holds 3 pointers per "position" and so the multiplier
	// here must be an even multiple of 3.
	size_t	stack_size = get_split_stack_size(NITEM(pb - pa)) * 6;
	_Alignas(64) VAR *_stack[stack_size];
	VAR	**stack = _stack, **maxstack = stack + stack_size;
	VAR	*rp, *sp;	// Roaming-Pointer, and Split Pointer
	size_t	bs;		// Byte-wise block size of pa->pb

shift_again:
	// Just insert merge single items. We already know that *PB < *PA
	if ((bs = (pb - pa)) == ES) {
		do {	// Bubble Up
			SWAP(pa, pb);
			pa = pb;  pb = pb + ES;
		} while ((pb != pe) && IS_LT(pb, pa));
		goto shift_pop;
	} else if ((pb + ES) == pe) {
		do {	// Bubble Down
			SWAP(pb, pb - ES);
			pb -= ES;
		} while ((pb != pa) && IS_LT(pb, pb - ES));
		goto shift_pop;
	}

	// Insertion MIP is slightly faster for very small sorted array pairs
	if ((pe - pa) < (ES << 3)) {
		CALL(insertion_merge_in_place)(pa, pb, pe, COMMON_ARGS);
		goto shift_pop;
	}

	// Shift entirety of PA->PB up as far as we can
	for (rp = pb + bs; rp <= pe && IS_LT(rp - ES, pa); rp += bs) {
		CALL(block_swap)(pa, pb, NITEM(bs), COMMON_ARGS);
		pa += bs;
		pb += bs;
	}

	// We couldn't shift the full PA->PB block up any further
	// Split the block up, and keep trying with the remainders

	// Handle scenario where our block cannot fit within what remains
	if (rp > pe) {
		if (pb == pe)
			goto shift_pop;

		// If it looks like we're working on merging a much larger array
		// into a smaller one, then reverse the direction
		if ((pb - pa) > ((pe - pb) << 2)) {
			CALL(reverse_merge_in_place)(pa, pb, pe, COMMON_ARGS);
			goto shift_pop;
		}

		bs = (pe - pb);
	}

	// Find spot within PA->PB to split it at.  This means finding
	// the first point in PB->PE that is smaller than the matching
	// point within PA->PB, centered around the PB pivot
	if (bs >= (ES << 3)) {	// Binary search on larger sets
		size_t	min = 0, max = NITEM(bs), pos = max >> 1;

		sp = pb - (pos * ES);
		rp = pb + (pos * ES);

		while (min < max) {
			int res = !!(IS_LT(rp, sp - ES));
			min = (!res * min) + (res * (pos + res));
			max = (res * max) + (!res * pos);

			pos = (min + max) >> 1;
			sp = pb - (pos * ES);
			rp = pb + (pos * ES);
		}
	} else {	// Linear scan is faster for smaller sets
		sp = pb - bs;	rp = pb + bs;
		for ( ; (sp != pb) && !IS_LT(rp - ES, sp); sp += ES, rp -= ES);
	}

	if (sp == pb)
		goto shift_pop;  // Nothing to swap. We're done here

	// Do a single shift at the split point
	// The compiler optimiser REALLY doesn't like us calling block_swap here
	for (VAR *ta = sp, *tb = pb; ta != pb; ta += ES, tb += ES)
		SWAP(ta, tb);

	// We now have 4 arrays
	// - PA->SP - The initial part of A that is less than the split point in B
	// - SP->PB - The initial part of B swapped with the part of A larger than it
	// - PB->RP - The top part of A that is greater than anything in PA->PB
	// - RP->PE - Everything else remaining in B that's larger than PA->PB

	// Oddly enough, the following line helps compiler optimization on gcc
	bs = ((rp != pe) && IS_LT(rp, rp - ES));
	if (IS_LT(sp, sp - ES)) {
		if (bs) {
			// If our stack is about to over-flow, move to use the
			// slower, but resilient algorithm that handles degenerate
			// scenarios without issue.
			SHIFT_STACK_PUSH(pb, rp, pe);
			if (unlikely(stack == maxstack)) {
				CALL(split_merge_in_place)(pa, sp, pb, COMMON_ARGS);
				goto shift_pop;
			}
		}
		// PB forms a hard upper limit on PA->SP->PB, so it is
		// used as the new PE when merging PA->SP->PB together
		pe = pb;
		pb = sp;

		goto shift_again;
	} else if (bs) {
		// Here we continue to merge PB->RP into RP->PE.  PB becomes
		// our new PA, since PB->RP is everything left from A that is
		// still yet to be merged. RP therefore becomes our new PB
		pa = pb;
		pb = rp;
		goto shift_again;
	}
shift_pop:
	if (stack != _stack) {
		SHIFT_STACK_POP(pa, pb, pe);
		goto shift_again;
	}
} // shift_merge_in_place
#undef	SHIFT_STACK_PUSH
#undef	SHIFT_STACK_POP


// Classic bottom-up merge sort
static void
NAME(basic_bottom_up_sort)(VAR *pa, const size_t n, COMMON_PARAMS)
{
	// Handle small array size inputs with insertion sort
	if (n < (INSERT_SORT_MAX * 2))
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	VAR	*pe = pa + (n * ES);

	do {
		size_t	bound = n - (n % INSERT_SORT_MAX);
		VAR	*bpe = pa + (bound * ES);

		// First just do insert sorts on all with size INSERT_SORT_MAX
		for (VAR *pos = pa; pos != bpe; pos += (INSERT_SORT_MAX * ES)) {
			VAR	*stop = pos + (INSERT_SORT_MAX * ES);
			for (VAR *ta = pos + ES, *tb; ta != stop; ta += ES)
				for (tb = ta; tb != pos && IS_LT(tb, tb - ES); tb -= ES)
					SWAP(tb, tb - ES);
		}

		// Insert sort any remainder
		if (n - bound)
			CALL(insertion_sort)(bpe, n - bound, COMMON_ARGS);
	} while (0);

	for (size_t size = INSERT_SORT_MAX; size < n; size += size) {
		VAR	*stop = pa + ((n - size) * ES);
		for (VAR *pos1 = pa; pos1 < stop; pos1 += (size * ES * 2)) {
			VAR *pos2 = pos1 + (size * ES);
			VAR *pos3 = pos1 + (size * ES * 2);

			if (pos3 > pe)
				pos3 = pe;

			if (pos2 < pe) {
#if LOW_STACK
				CALL(split_merge_in_place)(pos1, pos2, pos3, COMMON_ARGS);
#else
				CALL(shift_merge_in_place)(pos1, pos2, pos3, COMMON_ARGS);
#endif
			}
		}
	}
} // basic_bottom_up_sort


// Top-down merge sort with a bias to smaller left-side arrays as this appears
// to help the in-place merge algorithm a little bit,  This makes it a hair
// faster than the bottom-up merge version of basic_sort().  basic_sort()  is
// slow (about half the speed of merge_sort_in_place) but when combined with
// either shift_merge or split_merge, it is actually sort-stable, and the
// stable_sort() function uses this to help find a set of unique items.
static void
NAME(basic_top_down_sort)(VAR *pa, const size_t n, COMMON_PARAMS)
{
#if LOW_STACK
	return CALL(basic_bottom_up_sort)(pa, n, COMMON_ARGS);
#endif
	// Handle small array size inputs with insertion sort
	// Ensure there's no way na and nb could be zero
	if ((n <= INSERT_SORT_MAX) || (n <= 8))
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	size_t	na = (n * BASIC_SKEW) / 100;
	size_t	nb = n - na;
	VAR	*pb = pa + (na * ES);
	VAR	*pe = pa + (n * ES);

	CALL(basic_top_down_sort)(pa, na, COMMON_ARGS);
	CALL(basic_top_down_sort)(pb, nb, COMMON_ARGS);

	CALL(shift_merge_in_place)(pa, pb, pe, COMMON_ARGS);
} // basic_top_down_sort


// Giving credit where it's due.  All this sprint-left/right, merge-left/right
// stuff is heavily influenced by TimSort.  I'd already implemented something
// similar, but when I looked at TimSort code I saw a few extra good ideas and
// brought them in.  Basically where you see sprinting, that's very similar to
// TimSort's galloping
//
// We're looking for leftmost element within pa->pe that is greater than, or
// equal to, what pt is pointing at
static VAR *
NAME(sprint_left)(VAR *pa, VAR *pe, VAR *pt, int direction, COMMON_PARAMS)
{
	size_t	max = NITEM(pe - pa);
	size_t	min = 0, pos;
	VAR	*sp;

	if (direction == LEAP_LEFT) {
		// First leap-frog our way to find our search range
		// Here we're scanning backwards from PE
		for (pos = 0; pos < max; pos = (pos << 1) + 1) {
			sp = pe - ((pos + 1) * ES);
			if (IS_LT(sp, pt))
				break;
		}

		// Setup min and max, relative to PE, unless if pos
		// exceeded max, in which case choosing pos/2 is best
		if (pos > max) {
			max = pos >> 1;
		} else {
			min = max - pos;
			max = min + (pos >> 1);
		}
	} else {
		// First leap-frog our way to find the search range
		for (pos = 0; pos < max; pos = (pos << 1) + 1) {
			sp = pa + (pos * ES);
			if (!IS_LT(sp, pt))
				break;
		}

		// Now adjust our min and max, to keep them within limits
		// as well as ensure 2^n-1 elements is the range that
		// we will be searching against
		if (pos > max) {
			min = max - (pos >> 1);
		} else {
			min = (pos >> 1) + 1;
			max = pos;
		}
	}

	pos = (min + max) >> 1;
	sp = pa + (pos * ES);
	while (min < max) {
		// The following 3 lines implement this logic
		// if (IS_LT(sp, pt))
		// 	min = pos + 1;
		// else
		// 	max = pos;
		int result = !!(IS_LT(sp, pt));
		min = (min * !result) + (result * (pos + 1));
		max = (max * result) + (!result * pos);

		pos = (min + max) >> 1;
		sp = pa + (pos * ES);
	}
	return sp;
} // sprint_left


// We're looking for rightmost element within pa->pe that is 
// less than, or equal, to what pt is pointing at
static VAR *
NAME(sprint_right)(VAR *pa, VAR *pe, VAR *pt, int direction, COMMON_PARAMS)
{
	size_t	max = NITEM(pe - pa);
	size_t	min = 0, pos = 0;
	VAR	*sp;

	if (direction == LEAP_RIGHT) {
		// First leap-frog our way to find the search range
		for (pos = 0; pos < max; pos = (pos << 1) + 1) {
			sp = pa + (pos * ES);
			if (IS_LT(pt, sp))
				break;
		}

		// Now adjust our min and max, to keep them within limits
		// as well as ensure 2^n-1 elements is the range that
		// we will be searching against
		if (pos > max) {
			min = max - (pos >> 1);
		} else {
			min = (pos >> 1) + 1;
			max = pos;
		}
	} else {
		// First leap-frog our way to find our search range
		// Here we're scanning backwards from PE
		for (pos = 0; pos < max; pos = (pos << 1) + 1) {
			sp = pe - ((pos + 1) * ES);
			if (!IS_LT(pt, sp))
				break;
		}

		// Setup min and max, relative to PE, unless if pos
		// exceeded max, in which case choosing pos/2 is best
		if (pos > max) {
			max = pos >> 1;
		} else {
			min = max - pos;
			max = min + (pos >> 1);
		}
	}

	pos = (min + max) >> 1;
	sp = pa + (pos * ES);
	while (min < max) {
		// The following 3 lines implement this logic
		// if (IS_LT(pt, sp))
		// 	max = pos;
		// else
		// 	min = pos + 1;
		int result = !!(IS_LT(pt, sp));
		max = (max * !result) + (result * pos);
		min = (min * result) + (!result * (pos + 1));

		pos = (min + max) >> 1;
		sp = pa + (pos * ES);
	}
	return sp;
} // sprint_right


static void
NAME(merge_left)(VAR *a, size_t na, VAR *b, size_t nb,
			  VAR *w, const size_t nw, COMMON_PARAMS)
{
	VAR	*pe = b + (nb * ES), *pw = w;
	VAR	*pb = pe, *pa = b;

	assert(nb <= nw);

	// Now copy everything remaining from B to W
	for (VAR *tb = b; nb--; pw += ES, tb += ES)
		SWAP(pw, tb);

	// We already know the result of the first compare
	pa -= ES;
	pb -= ES;
	SWAP(pb, pa);

	// Now merge rest of W into A. Set up sprint values
	size_t a_run = 0, b_run = 0, sprint = SPRINT_ACTIVATE;

	while ((pa > a) && (pw > w)) {
		if ((a_run | b_run) < sprint) {
			// The following 8 lines implement this logic
			// pb -= ES;
			// if (IS_LT(pw - ES, pa - ES)) {
			//	pa -= ES;
			//	SWAP(pb, pa);
			//	b_run = 0;
			//	a_run++;
			// } else {
			//	pw -= ES;
			//	SWAP(pb, pw);
			//	a_run = 0;
			//	b_run++;
			// }
			VAR	*which[2] = {(pw - ES), (pa - ES)};
			int	result = !!(IS_LT(pw - ES, pa - ES));
			pb = pb - ES;
			SWAP(pb, which[result]);
			pa = pa - (result * ES);
			pw = pw - (!result * ES);
			a_run = (a_run + result) * result;
			b_run = (b_run + !result) * !result;
			continue;
		}

		do {
			sprint -= !!(sprint > 2);

			// Stuff from A is sprinting
			if (a_run) {
				VAR *ta = CALL(sprint_right)(a, pa, pw - ES, LEAP_LEFT, COMMON_ARGS);
				a_run = NITEM(pa - ta);
				for (size_t num = a_run; num--; ) {
					pa -= ES;  pb -= ES;
					SWAP(pa, pb);
				}
				if (pa == a)
					break;
				b_run += !b_run;
			}

			// Stuff from B/Workspace is sprinting
			if (b_run) {
				VAR *tw = CALL(sprint_left)(w, pw, pa - ES, LEAP_LEFT, COMMON_ARGS);
				b_run = NITEM(pw - tw);
				for (size_t num = b_run; num--; ) {
					pw -= ES;  pb -= ES;
					SWAP(pw, pb);
				}
				if (pw == w)
					break;
				a_run += !a_run;
			}
		} while ((a_run >= SPRINT_ACTIVATE) || (b_run >= SPRINT_ACTIVATE));

		// Reset sprint mode
		sprint += SPRINT_EXIT_PENALTY;
		a_run = 0;
		b_run = 0;
	}

	// Swap back any remainder
	assert(w <= pw);
	for ( ; w != pw; w += ES, a += ES)
		SWAP(a, w);
} // merge_left


static void
NAME(merge_right)(VAR *a, size_t na, VAR *b, size_t nb,
			  VAR *w, const size_t nw, COMMON_PARAMS)
{
	VAR	*pe = b + (nb * ES);
	VAR	*pw = w;

	assert(na <= nw);

	// Now copy everything in A to W
	for (VAR *ta = a; na--; pw += ES, ta += ES)
		SWAP(pw, ta);

	// We already know that the first B is smaller, so swap it now
	SWAP(a, b);
	a += ES;
	b += ES;

	// Now merge rest of W into B. Set up sprint values
	size_t a_run = 0, b_run = 0, sprint = SPRINT_ACTIVATE;

	while ((b < pe) && (w < pw)) {
		if ((a_run | b_run) < sprint) {
			// The following 8 lines implement this logic
			// if(IS_LT(b, w)) {
			//	SWAP(a, b);
			//	b += ES;
			//	a_run = 0;
			//	b_run++;
			// } else {
			//	SWAP(a, w);
			//	w += ES;
			//	a_run++;
			//	b_run = 0;
			// }
			VAR	*which[2] = {w, b};
			int	result = !!(IS_LT(b, w));
			SWAP(a, which[result]);
			b += result * ES;
			w += !result * ES;
			a_run = (a_run + !result) * !result;
			b_run = (b_run + result) * result;
			a += ES;
			continue;
		}

		do {
			sprint -= !!(sprint > 2);

			// Stuff from A/workspace is sprinting
			VAR	*tw = CALL(sprint_right)(w, pw, b, LEAP_RIGHT, COMMON_ARGS);
			a_run = NITEM(tw - w);
			if (a_run) {
				for (size_t num = a_run; num--; w += ES, a += ES)
					SWAP(a, w);
				if (w >= pw)
					break;
			}

			// Stuff from B is sprinting
			VAR	*tb = CALL(sprint_left)(b, pe, w, LEAP_RIGHT, COMMON_ARGS);
			b_run = NITEM(tb - b);
			if (b_run) {
				for (size_t num = b_run; num--; b += ES, a += ES)
					SWAP(a, b);
				if (b >= pe)
					break;
			}
		} while ((a_run >= SPRINT_ACTIVATE) || (b_run >= SPRINT_ACTIVATE));

		// Reset sprint mode
		sprint += SPRINT_EXIT_PENALTY;
		a_run = 0;
		b_run = 0;
	}

	// Swap back any remainder
	assert(w <= pw);
	for ( ; w != pw; w += ES, a += ES)
		SWAP(a, w);
} // merge_right


// Prepares A and B for merging via merge_left or merge_right
// Assumes both NA and NB are > zero on entry
static void
NAME(merge_using_workspace)(VAR *a, size_t na, VAR *b, size_t nb,
			  VAR *w, const size_t nw, COMMON_PARAMS)
{
	assert(na > 0);
	assert(nb > 0);

	// Check if we need to do anything at all!
	if (!IS_LT(b, b - ES))
		return;

	VAR	*pe = b + (nb * ES);

	// Skip initial part of A if the opportunity arises
	if (!IS_LT(b, a)) {
		if (na > 10) {
			size_t	min = 1, max = na;
			size_t	pos = max >> 1;
			VAR	*sp = a + (pos * ES);

			while (min < max) {
				// The following 3 lines implement this logic
				// if (IS_LT(b, sp))
				//	max = pos;
				// else
				//	min = pos + 1;
				int res = !!(IS_LT(b, sp));
				max = (max * !res) + (pos * res);
				min = (min * res) + (!res * (pos + 1));

				pos = (min + max) >> 1;
				sp = a + (pos * ES);
			}
			a = sp;
			na -= pos;
		} else {
			do {
				a += ES;
				na--;
			} while (!IS_LT(b, a));
		}
		assert(na > 0);
		assert((a + (na * ES)) < pe);	// Catch underflow
	}

	// Skip last part of B if the opportunity arises
	VAR	*sp = pe - ES;
	VAR	*tb = b - ES;
	if (!IS_LT(sp, tb)) {
		if (nb > 10) {
			size_t  min = 0, max = nb;
			size_t  pos = max >> 1;

			sp = b + (pos * ES);
			while (min < max) {
				// The following 3 lines implement this logic
				// if (IS_LT(sp, b - ES))
				//	min = pos + 1;
				// else
				//	max = pos;
				int res = !!(IS_LT(sp, b - ES));
				min = (!res * min) + (res * (pos + 1));
				max = (res * max) + (!res * pos);

				pos = (min + max) >> 1;
				sp = b + (pos * ES);
			}
			nb = pos;
		} else {
			do {
				sp -= ES;
				nb--;
			} while (!IS_LT(sp, tb));
		}
		assert(nb > 0);
		assert((b + (nb * ES)) <= pe);	// Catch underflow
	}

	// Use merge-left if nb is smaller than na
	// Fall-back to shift-merge if our work-space would overflow
	if (nb < na)
		CALL(merge_left)(a, na, b, nb, w, nw, COMMON_ARGS);
	else
		CALL(merge_right)(a, na, b, nb, w, nw, COMMON_ARGS);
} // merge_using_workspace


// This function's job to merge two arrays together, given whatever
// workspace it gets.  It'll always make it work....eventually!
static void
NAME(merge_workspace_constrained) (VAR *pa, size_t na, VAR *pb, size_t nb,
			  VAR *ws, const size_t nw, COMMON_PARAMS)
{
	VAR	*pe = pb + (nb * ES);

	while (na > nw) {
		VAR	*rp, *sp;	// Rotate + Split pointers

		// RP now tracks the point of block rotation
		// PB now points at the end of the part of A
		// that fits into the available workspace 
		rp = pb;
		pb = pa + nw * ES;
			
		// Find where in the B array we can split to rotate the
		// remainder of A into.  Use binary search for speed
		do {
			size_t	min = 0, max = nb;
			size_t	pos = max >> 1;

			sp = rp + (pos * ES);

			while (min < max) {
				if (IS_LT(sp, pb - ES))
					min = pos + 1;
				else
					max = pos;

				pos = (min + max) >> 1;
				sp = rp + (pos * ES);
			}
		} while(0);

		// Rotate the part of A that doesn't fit into the workspace
		// with everything in B that is less than where we split A at
		CALL(block_rotate)(pb, rp, sp, COMMON_ARGS);

		// Adjust the rotation pointer after the rotate and fix up sizes
		rp = pb + (sp - rp);
		na = nw;
		nb = NITEM(rp - pb);

		// We now have 4 arrays.
		// - PA->PB  is the part of A the same size as our workspace.
		// - PB->RP  is the portion of the original B array that is
		//           less than where we split A at
		// - RP->SP  is the remainder of A that was larger than the
		//           workspace
		// - SP->PE  is the rest of B that is >= where we split A at

		// Now merge A with B - the rotation can make nb be 0, so check
		if (nb > 0) {
			CALL(merge_using_workspace)(pa, na, pb, nb, ws, nw, COMMON_ARGS);
//			CALL(test_sorted)(pa, na + nb, COMMON_ARGS);
		}

		// Now set PA and PB, to be RP and SP respectively, and loop
		pa = rp;
		pb = sp;
		na = NITEM(sp - rp);
		nb = NITEM(pe - sp);
	}
	assert(na > 0);		// It should never be possible that na == 0

	// The rotations can make nb be 0, so check it!
	if (nb > 0)
		CALL(merge_using_workspace)(pa, na, pb, nb, ws, nw, COMMON_ARGS);
} // merge_workspace_constrained


static void
NAME(sort_using_workspace)(VAR *pa, size_t n, VAR * const ws,
			   const size_t nw, COMMON_PARAMS)
{
	// Handle small array size inputs with insertion sort
	if ((n <= INSERT_SORT_MAX) || (n <= 8))
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	assert(ws != NULL);
	assert(nw > 0);

	// The standard merge-sort algorithm is mathematically best
	// when splitting the work up completely evenly (50:50 split)
	// In practise though, in a world of CPU's with caches, there
	// may exist a more optimal split due to data localisation.
	// This ratio is controlled by the MERGE_SKEW #define
	size_t	na = (n * MERGE_SKEW) / 100;
	size_t	nb = n - na;

	VAR	*pb = pa + (na * ES);

	// First sort A
	CALL(sort_using_workspace)(pa, na, ws, nw, COMMON_ARGS);

	// Now sort B
	CALL(sort_using_workspace)(pb, nb, ws, nw, COMMON_ARGS);

	// Use the constrained workspace algorithm to merge the array pair
	CALL(merge_workspace_constrained)(pa, na, pb, nb, ws, nw, COMMON_ARGS);
} // sort_using_workspace


// Base merge-sort algorithm - I'm all 'bout that speed baby!
// It logically follows that if this is given unique items to sort
// then the result will naturally yield a sort-stable result
static void
NAME(merge_sort_in_place)(VAR * const pa, const size_t n, VAR * const ws,
	      const size_t nw, COMMON_PARAMS)
{
	// Handle small array size inputs with insertion sort
	if ((n <= INSERT_SORT_MAX) || (n <= 8))
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	// If we were handed a workspace, then just use that
	if (ws && (nw > 0))
		return CALL(sort_using_workspace)(pa, n, ws, nw, COMMON_ARGS);

	// Otherwise we need to create our own workspace from the data given
	// 9 appears to be close to optimal, but anything from 3-20 works
	size_t	na = n / WSRATIO;

	// Enforce a sensible minimum
	if (na < 4)
		na = 4;

	VAR	*pe = pa + (n * ES);
	VAR	*pb = pa + (na * ES);
	size_t	nb = n - na;

	// Sort B using A as the workspace
	CALL(sort_using_workspace)(pb, nb, pa, na, COMMON_ARGS);

	// Now recursively sort what we used as work-space
	CALL(merge_sort_in_place)(pa, na, NULL, 0, COMMON_ARGS);

	// Now merge them together
#if LOW_STACK
	CALL(split_merge_in_place)(pa, pb, pe, COMMON_ARGS);
#else
	CALL(shift_merge_in_place)(pa, pb, pe, COMMON_ARGS);
#endif
} // merge_sort_in_place


// Designed for efficiently processing smallish sets of items
// Note that the last item is always guaranteed to be unique
//
// Returns a pointer to the list of unique items positioned
// to the right-side of the array.  All duplicates are located
// at the start (left-side) of the array (A)
//  A -> PU = Duplicates
// PU -> PE = Unique items
static VAR *
NAME(extract_unique_sub)(VAR * const a, VAR * const pe, VAR *ph, COMMON_PARAMS)
{
	VAR	*pu = a;	// Points to list of unique items

	// Sanitize our hints pointer
	if (ph == NULL)
		ph = pe;

	// Process everything up to the hints pointer
	for (VAR *pa = a + ES; pa < ph; pa += ES) {
		if (IS_LT(pa - ES, pa))
			continue;

		// The item before our position is a duplicate.  Mark it.
		VAR *dp = pa - ES;

		// Now find the end of the run of duplicates
		for (pa += ES; (pa < ph) && !IS_LT(pa - ES, pa); pa += ES);
		pa -= ES;

		// pa now points at the last item of the duplicate run
		// Roll the duplicates down
		if ((pa - dp) > ES) {
			// Multiple duplicates. block_rotate them into position
			if (dp > pu)
				CALL(block_rotate)(pu, dp, pa, COMMON_ARGS);
			pu += (pa - dp);
		} else {
			// Single item, just bubble it down
			while (dp > pu) {
				SWAP(dp, dp - ES);
				dp -= ES;
			}
			pu += ES;
		}
		pa += ES;
	}

	if (ph < pe) {
		// Everything (ph - es) to (pe - es) is a duplicate
		CALL(block_rotate)(pu, ph - ES, pe - ES, COMMON_ARGS);
		pu += (pe - ph);
	}

	return pu;
} // extract_unique_sub


// Returns a pointer to the list of unique items positioned
// to the right-side of the array.  All duplicates are located
// at the start (left-side) of the array (A)
//  A -> PU = Duplicates
// PU -> PE = Unique items
//
// Assumptions:
// - The list we're passed is already sorted
static VAR *
NAME(extract_uniques)(VAR * const a, const size_t n, VAR *hints, COMMON_PARAMS)
{
	VAR	*pe = a + (n * ES);

	// I'm not sure what a good value should be here, but 40 seems okay
	if (n < 40)
		return CALL(extract_unique_sub)(a, pe, hints, COMMON_ARGS);

	if (hints == NULL)
		hints = pe;

	// Divide and conquer!  This algorithm appears to operate in close
	// to an O(n) time complexity, albeit with a moderately high K factor
	VAR	*pa = a;
	size_t	na = (n + 3) >> 2;	// Looks to be about right
	VAR	*pb = pa + (na * ES);

	VAR	*ps = pb;	// Records original intended split point

	// First find where to split at, which basically means, find the
	// end of any duplicate run that we may find ourselves in
	while ((pb < pe) && !IS_LT(pb - ES, pb))
		pb += ES;

	// If we couldn't find a sub-split, just process what we have
	if (pb == pe)
		return CALL(extract_unique_sub)(a, pe, ps, COMMON_ARGS);

	// Recalculate our size
	na = NITEM(pb - pa);
	size_t	nb = n - na;

	if (hints < pb)
		hints = pe;

	// Note that there is ALWAYS at least one unique to be found
	VAR	*apu = CALL(extract_uniques)(pa, na, ps, COMMON_ARGS);
	VAR	*bpu = CALL(extract_uniques)(pb, nb, hints, COMMON_ARGS);

	// Coalesce non-uniques together
	if (bpu > pb) {
		CALL(block_rotate)(apu, pb, bpu, COMMON_ARGS);
	}
	pb = apu + (bpu - pb);

	// PA->BP now contains non-uniques and BP->PE are uniques
	return pb;
} // extract_uniques


// Takes a list of pointers to blocks, and merges them together using a 1:2
// merge ratio.  pe points after the end of the last block on the list
static VAR *
NAME(merge_duplicates)(struct NAME(stable_state) *state, VAR **list, size_t n, VAR *pe, COMMON_PARAMS)
{
	if (n == 1)
		return list[0];

	size_t	n1 = (n + 1) / 3;
	size_t	n2 = n - n1;

	VAR	*m1 = CALL(merge_duplicates)(state, list, n1, list[n1], COMMON_ARGS);
	VAR	*m2 = CALL(merge_duplicates)(state, list + n1, n2, pe, COMMON_ARGS);

	size_t	nm1 = NITEM(m2 - m1);	// Number of items in m1
	size_t	nm2 = NITEM(pe - m2);	// Number of items in m2

	VAR	*ws = state->work_space;
	size_t	nw = state->work_size;

#ifdef	DEBUG_UNIQUE_PROCESSING
	printf("Merging %lu with %lu\n", nm1, nm2);
#endif
	if (nm1 > (nw * WSRATIO)) {
		// Use in-place merging
#if LOW_STACK
		CALL(split_merge_in_place)(m1, m2, pe, COMMON_ARGS);
#else
		CALL(shift_merge_in_place)(m1, m2, pe, COMMON_ARGS);
#endif
	} else {
		// Do a faster work-space based merge
		CALL(merge_workspace_constrained)(m1, nm1, m2, nm2, ws, nw, COMMON_ARGS);
		state->work_sorted = false;
	}

	return m1;
} // merge_duplicates


// Maintains the set of duplicate entries.  When a duplicate entry is added
// to the free list, it checks against the length of the merged list.
// This two stage system means that for 2 * MAX_DUPS entries of space,
// we can actually maintain MAX_DUPS^2 worth of duplicate entries.  This then
// means we can collate a lot of duplicates for a small (fixed) overhead
static void
NAME(add_duplicate)(struct NAME(stable_state) *state, VAR *new_dup, COMMON_PARAMS)
{
	state->free_dups[state->num_free++] = new_dup;
	if (state->num_free < MAX_DUPS)
		return;

	VAR	**list = state->free_dups;
	size_t	n = state->num_free;
	VAR	*ws = state->work_space;

	// Merge up the free duplicates
	VAR	*mf = CALL(merge_duplicates)(state, list, n, ws, COMMON_ARGS);

	state->merged_dups[state->num_merged++] = mf;
	state->free_dups[0] = NULL;
	state->num_free = 0;
} // add_duplicate


static void
NAME(stable_sort_finisher)(struct NAME(stable_state) *state, COMMON_PARAMS)
{
	VAR	*ws = state->work_space;
	size_t	nw = state->work_size;

#ifdef	DEBUG_UNIQUE_PROCESSING
	printf("Num Merged = %lu, Num Free = %lu\n", state->num_merged, state->num_free);
#endif
	// Merge up the free duplicates
	if (state->num_free > 0) {
		VAR	**list = state->free_dups;
		size_t	n = state->num_free;
		VAR	*mf = CALL(merge_duplicates)(state, list, n, ws, COMMON_ARGS);

		// merged_dups has a bonus spot just for this occasion
		state->merged_dups[state->num_merged++] = mf;
		state->free_dups[0] = NULL;
		state->num_free = 0;
	}

	// Merge up the merged duplicates
	VAR	*md = NULL;
	if (state->num_merged > 0) {
		VAR	**list = state->merged_dups;
		size_t	n = state->num_merged;

		md = CALL(merge_duplicates)(state, list, n, ws, COMMON_ARGS);
	}

	// Now sort our workspace if it's required
	if (state->work_sorted == false)
		CALL(merge_sort_in_place)(ws, nw, NULL, 0, COMMON_ARGS);

	// Now we have the following chunks
	// md - A potentially very lerge chunk of merged and sorted duplicates
	// work_space - Our work-space of unique values, which is sorted
	// rest - The sorted rest of the input

	VAR	*pr = state->rest;
	VAR	*pe = state->pe;
	size_t	nm = 0;

	if (md)
		nm = NITEM(ws - md);

#ifdef	DEBUG_UNIQUE_PROCESSING
	printf("md = %p, ws = %p, pr = %p\n", md, ws, pr);
	printf("nm = %lu, nw = %lu, nr = %lu\n", nm, nw, state->rest_size);
#endif

#if LOW_STACK
	if ((nm > 0) && (nm < nw)) {
		CALL(split_merge_in_place)(md, ws, pr, COMMON_ARGS);
		CALL(split_merge_in_place)(md, pr, pe, COMMON_ARGS);
	} else {
		CALL(split_merge_in_place)(ws, pr, pe, COMMON_ARGS);
		if (nm > 0)
			CALL(split_merge_in_place)(md, ws, pe, COMMON_ARGS);
	}
#else
	if ((nm > 0) && (nm < nw)) {
		CALL(shift_merge_in_place)(md, ws, pr, COMMON_ARGS);
		CALL(shift_merge_in_place)(md, pr, pe, COMMON_ARGS);
	} else {
		CALL(shift_merge_in_place)(ws, pr, pe, COMMON_ARGS);
		if (nm > 0)
			CALL(shift_merge_in_place)(md, ws, pe, COMMON_ARGS);
	}
#endif
	// and....we're done!
} // stable_sort_finisher


// This essentially operates as a "front end" to the main shift-merge-sort
// sequence.  Its primary role is to extract unique values from the main
// data set, which in turn allows us to use these as a workspace to pass
// to the main algorithm.  Doing so preserves sort stability.  While it is
// generating the set of uniques, it is also still sorting by generating a
// sorted set of duplicates that were disqualified.  There exists certain
// inputs where we can sort the entire set just through doing this alone!
static void
NAME(stable_sort)(VAR * const pa, const size_t n, COMMON_PARAMS)
{
	struct NAME(stable_state )state_real = {0}, *state = &state_real;
	VAR	*pe = pa + (n * ES), *ws, *pr;
	size_t	nr, nw;

#ifdef	DEBUG_UNIQUE_PROCESSING
	printf("size of stable state processing structure = %lu bytes\n",
			sizeof(struct NAME(stable_state)));
#endif
	// 80 items appears to be about the cross-over
	// That 2-stage binary insertion sort holds up pretty well!
	if (n < 80)
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	// We start with a workspace candidate size that is intentionally
	// small, as we need to use the slower basic_sort() algorithm to
	// kick start the process.  The idea here is to then use the
	// initial unique values that we extract to drive use of the
	// merge-sort algorithm, to help us find more uniques faster!
	nw = (n >> 6) + STABLE_WSRATIO;
	nr = n - nw;
	pr = pa + (nw * ES);	// Pointer to rest

	// Determine how much workspace we're aiming for
	size_t	wstarget = nr / STABLE_WSRATIO;

	// First sort our candidate work-space chunk
	CALL(basic_top_down_sort)(pa, nw, COMMON_ARGS);

	// Now pull out our first set of unique values
	ws = CALL(extract_uniques)(pa, nw, NULL, COMMON_ARGS);

	// Recalculate size of work_space after duplicates were extracted
	nw = NITEM(pr - ws);

	// Initialise state structure
	state->work_space = ws;
	state->work_size = nw;
	state->work_sorted = true;
	state->rest = pr;
	state->rest_size = nr;
	state->pe = pe;

	// PA->WS is pointing at (sorted) non-uniques
	// WS->PR is a set of uniques we can use as workspace
	// PR->PE is everything else that we still need to sort

	// If there were duplicates (PA->WS), then add them to the list
	// The first set of duplicates is a special case, as it is often
	// very large, so it goes straight to the set of merged duplicates
	if (ws > pa) {
		state->merged_dups[0] = pa;
		state->num_merged = 1;
	}

	// If we couldn't find enough work-space we'll keep trying until our
	// duplicate management system fill up. Despite this seeming excessive,
	// with each try we're still sorting more of the array any way, so in
	// the end it all balances out.  Swings and roundabouts :)
	while ((nw < wstarget) && (state->num_merged < MAX_DUPS)) {
		// It can be fun to activate the following printf and watch
		// the unique extractor do its thing with increasingly
		// degenerate inputs.  It's possible for stable_sort() to
		// completely sort the input in this extraction phase alone!
#ifdef	DEBUG_UNIQUE_PROCESSING
		printf("Not enough workspace. Wanted: %ld  Got: %ld  "
		       "Duplicates: %ld, Remaining Items = %lu\n",
		       wstarget, nw, NITEM(ws - pa), nr);
#endif
		// Estimate how much of the remaining that we need to grab
		// to get enough uniques to satsify our minimum.  First work
		// out what the current ratio of uniques is
		size_t	nd = NITEM(ws - pa);	// Num Duplicates
		double	ratio = nw;
		ratio /= (nw + nd);		// Ratio of uniques
		size_t	grab = wstarget - nw;	// How much we're short by
		grab = grab / ratio;		// Estimate of how much to grab
		grab = (grab * 9) >> 3;		// Add a fudge factor

		// Don't grab less than 1/32th. This is to avoid creeping up to
		// the target too slowly as we get close to it
		if (grab < (nr >> 5))
			grab = nr >> 5;

		// Don't grab more than we can efficiently sort
		if (grab > (nw * STABLE_WSRATIO))
			grab = nw * STABLE_WSRATIO;

		// Don't grab more than 1/8th of what's remaining.  We only
		// want to be doing this for as long as we absolutely need to be
		if (grab > (nr >> 3))
			grab = nr >> 3;

		// Section off the new workspace candidates from the rest
		VAR	*nws = pr;	// New workspace candidates
		nr -= grab;
		pr = pr + (grab * ES);

		// Update state with new rest of array changes
		state->rest = pr;
		state->rest_size = nr;

		// Determine how much work-space to use for sorting.  Doing so
		// means we need to sort less of it afterwards, and saves time
		size_t tnw = grab / STABLE_WSRATIO;

		// Sort new work-space candidates using our current workspace
		CALL(merge_sort_in_place)(nws, grab, ws, tnw, COMMON_ARGS);

		// Our current work-space is now jumbled, so sort that too
		CALL(merge_sort_in_place)(ws, tnw, NULL, 0, COMMON_ARGS);
		state->work_sorted = true;

		// Merge current workspace with the new set
#if LOW_STACK
		CALL(split_merge_in_place)(ws, nws, pr, COMMON_ARGS);
#else
		CALL(shift_merge_in_place)(ws, nws, pr, COMMON_ARGS);
#endif

		// We may have picked up new duplicates.  Separate them out
		nws = ws;
		ws = CALL(extract_uniques)(ws, nw + grab, NULL, COMMON_ARGS);
		nw = NITEM(pr - ws);

		// Update state with work-space changes
		state->work_space = ws;
		state->work_size = nw;

		// Append any new duplicates to the list of duplicates.
		if (ws > nws)
			CALL(add_duplicate)(state, nws, COMMON_ARGS);

		// Recalculate the new work-space size target.  If it's just
		// trivial amounts of unsorted data left, then just leave!
		// This avoid an overly degenerate merging scenario later
		if (nr < (n >> 4))
			break;

		// Short-circuit the search if we have even just barely enough!
		if ((nr < ((n * 3)>>2)) && (nw >= (nr >> 7)))
			break;

		wstarget = nr / STABLE_WSRATIO;
	}

	// Now sort the remaining unsorted data

	// Here we will bypass the wstarget so long as nw > nr/128.  The work
	// space based merge algorithm will still outpace the in-place merge
	// even when given that reduced amount.  wstarget acted more as an ideal
	if ((nw < wstarget) && (nw < (nr >> 7))) {
		// Give up and fall back to good old basic_sort().  If the input
		// data is THAT degenerate, then basic_sort is very fast anyway
		CALL(basic_top_down_sort)(pr, nr, COMMON_ARGS);
	} else {
		// Sort the remainder using the workspace we extracted
		CALL(merge_sort_in_place)(pr, nr, ws, nw, COMMON_ARGS);
		state->work_sorted = false;
	}

	// Now do the final merge up!
	CALL(stable_sort_finisher)(state, COMMON_ARGS);
} // stable_sort

#undef SWAP
#undef CONCAT
#undef MAKE_STR
#undef NAME
#undef CALL
#pragma GCC diagnostic pop
