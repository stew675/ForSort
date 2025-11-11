#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

#define CONCAT(x, y) x ## _ ## y
#define MAKE_STR(x, y) CONCAT(x,y)
#define NAME(x) MAKE_STR(x, ES)
#define CALL(x) NAME(x)

#ifndef FOR_GLOBAL_DEFS
#define FOR_GLOBAL_DEFS

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

#endif	// FOR_GLOBAL_DEFS


//---------------------------------------------------------------------------//
//----------------- START OF SPECIFIC ELEMENT SIZE DEFINES ------------------//
//---------------------------------------------------------------------------//

#ifdef UNTYPED

// Generic unaligned/odd-byte size handling

static inline void
memswap(void * restrict p1, void * restrict p2, size_t n)
{
	enum { SWAP_GENERIC_SIZE = 32 };

	unsigned char tmp[SWAP_GENERIC_SIZE];

	while (n > SWAP_GENERIC_SIZE) {
		mempcpy(tmp, p1, SWAP_GENERIC_SIZE);
		p1 = __mempcpy(p1, p2, SWAP_GENERIC_SIZE);
		p2 = __mempcpy(p2, tmp, SWAP_GENERIC_SIZE);
		n -= SWAP_GENERIC_SIZE;
	}
	while (n > 0) {
		unsigned char t = ((unsigned char *)p1)[--n];
		((unsigned char *)p1)[n] = ((unsigned char *)p2)[n];
		((unsigned char *)p2)[n] = t;
	}
} // memswap

#define	SWAP(_xa_, _xb_)	memswap((_xa_), (_xb_), es)

static void
NAME(insertion_sort)(char *pa, const size_t n, COMMON_PARAMS)
{
	char	*pe = pa + (n * es);

	for (char *ta = pa + es; ta != pe; ta += es)
		for (char *tb = ta; tb != pa && IS_LT(tb, tb - es); tb -= es)
			SWAP(tb, tb - es);
} // insertion_sort_es

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
NAME(insertion_sort)(char *a, const size_t n, COMMON_PARAMS)
{
	VAR *pa = (VAR *)a;
	VAR *ta = pa + 1;
	VAR *pe = pa + n;

	if (n > BINARY_INSERTION_MIN)
		pe = pa + BINARY_INSERTION_MIN;

	// Regular insertion sort for first BINARY_INSERTION_MIN items
	for ( ; ta != pe; ta++) {
		if (IS_LT(ta, ta - 1)) {
			VAR t[1] = {*ta}, *tb = ta;
			do {
				*tb = *(tb - 1);
			} while ((--tb != pa) && IS_LT(t, tb - 1));
			*tb = *t;
		}
	}

	if (n <= BINARY_INSERTION_MIN)
		return;

	// Now use binary insertion sort to place the elements
	// from the second set into the first
	for (pe = pa + n; ta != pe; ta++) {
		if (IS_LT(ta, ta - 1)) {
			// Find where to insert it
			size_t min = 0, max = (ta - pa) - 1;
			size_t pos = max >> 1;
			VAR *tb = pa + pos, *tc = ta, t = *ta;

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
				tb = pa + pos;
			}
			for (size_t num = (ta - tb); num--; tc--)
				*tc = *(tc - 1);
			*tb = t;
		}
	}
} // insertion_sort

#endif

//_____________________________________________________________________________


// Debug sort check testing
static void
NAME(test_sorted)(char *pa, size_t n, COMMON_PARAMS)
{
	char	*pe = pa + (n * ES);
	for (char *sp = pa + ES; sp < pe; sp += ES)
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
NAME(block_rotate)(char *a, char *b, char *e, COMMON_PARAMS)
{
	size_t	gapa = b - a, gapb = e - b;
	while (gapa && gapb) {
		if (gapa < gapb) {
			// s = source, d = destination
			// (Not that source and dest make sense when swapping)
			for (char *s = a, *d = a + gapb; d != e; s += ES, d += ES)
				SWAP(s, d);
			e -= gapa;
			gapb = e - b;
		} else {
			for (char *s = b, *d = a; s != e; s += ES, d += ES)
				SWAP(s, d);
			a += gapb;
			gapa = b - a;
		}
	}
} // block_rotate


static void __attribute__((noinline))
NAME(block_swap)(char *a, char *b, size_t n, COMMON_PARAMS)
{
	while (n--) {
		SWAP(a, b);
		a += ES;
		b += ES;
	}
} // block_swap


// Merges two sorted sub-arrays together using insertion sort
// This is horribly inefficient for all but the smallest arrays
static void
NAME(insertion_merge_in_place)(char * restrict pa, char * restrict pb,
			 char * restrict pe, COMMON_PARAMS)
{
	char	*tb = pe;

	do {
		pe = tb - ES; tb = pb - ES; pb = tb;
		while ((tb != pe) && IS_LT(tb + ES, tb)) {
			SWAP(tb + ES, tb);
			tb += ES;
		}
	} while ((pb != pa) && IS_LT(pb, pb - ES));
} // insertion_merge_in_place


// This in-place split merge algorithm started off life as a variant of ShiftMerge
// below, but I was looking for a way to solve the multiple degenerate scenarios
// where unbounded stack recursion could occur.  In the end, I couldn't fully
// solve some of those without making the code complex and branch inefficient
// and so split_merge_in_place() was born
static void
NAME(split_merge_in_place)(char *pa, char *pb, char *pe, COMMON_PARAMS)
{
	assert(pb > pa);
	assert(pe > pb);

	// Check if we need to do anything at all
	if (!IS_LT(pb, pb - ES))
		return;

	// The work stack needs to track up to 15 * log16(N) splits. Since there
	// are 2 pointers per stack "entry", the stack size equals 30 * log16(N)
	size_t	stack_size = 15 * (ceil_log_base_16((pb - pa) / ES) * 2);
	_Alignas(64) char *_stack[stack_size];
	char	**stack = _stack, *rp, *spa;

	// Determine our initial split size.  Ensure a minimum of 1 element
	// The following macro is why the stack growth is 16*log16(N)
#define	SPLIT_SIZE		(((((pb - pa) / ES) + 15) >> 4) * ES)
	size_t	bs, split_size = SPLIT_SIZE;

split_again:
	bs = pb - pa;		// Determine the byte-wise size of A

	// Just insert merge single items. We already know that *PB < *PA
	if (bs == ES) {
		do {
			SWAP(pa, pb);  pa = pb;  pb += ES;
		} while ((pb != pe) && IS_LT(pb, pa));
		goto split_pop;
	}

	// Advance the PA->PB block up as far as we can
	for (rp = pb + bs; (rp < pe) && IS_LT(rp - ES, pa); rp += bs) {
		CALL(block_swap)(pa, pb, bs / ES, COMMON_ARGS);
		pa += bs;
		pb += bs;
	}

	// Split the A block into two, and keep trying with remainder
	// The imbalanced split here improves algorithmic performance.
	rp = pb - ES;
	spa = pa + split_size;
	if (IS_LT(pb, rp)) {
		// Keep our split point within limits
		char	*which[2] = {spa, rp};
		spa = which[!!(spa > rp)];

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

		if (IS_LT(pb, pb - ES)) {
			split_size = SPLIT_SIZE;
			goto split_again;
		}
	}
#undef	SPLIT_SIZE
} // split_merge_in_place


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
NAME(shift_merge_in_place)(char *pa, char *pb, char *pe, COMMON_PARAMS)
{
	assert(pb > pa);
	assert(pe > pb);

#if LOW_STACK
	return CALL(split_merge_in_place)(ws, nws, pr, COMMON_ARGS);
#endif

#define	SHIFT_STACK_PUSH(s1, s2, s3) 	\
	{ *stack++ = s1; *stack++ = s2; *stack++ = s3; }

#define	SHIFT_STACK_POP(s1, s2, s3) \
	{ s3 = *--stack; s2 = *--stack; s1 = *--stack; }

	// The work stack holds 3 pointers per "position" and so the multiplier
	// here must be an even multiple of 3.  20 positions per log_base16 of
	// the size of the array being merged should be more than enough
	size_t	stack_size = 20 * (ceil_log_base_16((pb - pa) / ES) * 3);
	_Alignas(64) char *_stack[stack_size];
	char	**stack = _stack, **maxstack = stack + stack_size;
	char	*rp, *sp;	// Roaming-Pointer, and Split Pointer
	size_t	bs;		// Byte-wise block size of pa->pb

	// For whoever calls us, check if we need to do anything at all
	if (!IS_LT(pb, pb - ES))
		goto shift_pop;

shift_again:
	// If our stack is about to over-flow, move to use the slower, but more
	// resilient, algorithm that handles degenerate scenarios without issue
	// If the stack is large enough, this should almost never ever happen
	if (unlikely(stack == maxstack)) {
		CALL(split_merge_in_place)(pa, pb, pe, COMMON_ARGS);
		goto shift_pop;
	}

	bs = pb - pa;

	// Just insert merge single items. We already know that *PB < *PA
	if (bs == ES) {
		do {
			SWAP(pa, pb);
			pa = pb;  pb = pb + ES;
		} while (pb != pe && IS_LT(pb, pa));
		goto shift_pop;
	} else if ((pb + ES) == pe) {
		do {
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
		CALL(block_swap)(pa, pb, bs / ES, COMMON_ARGS);
		pa += bs;
		pb += bs;
	}

	// We couldn't shift the full PA->PB block up any further
	// Split the block up, and keep trying with the remainders

	// Handle scenario where our block cannot fit within what remains
	// This occurs about 3% of the time, hence the use of unlikely
	if (unlikely(rp > pe)) {
		if (pb == pe)
			goto shift_pop;
		// Adjust the block size to account for the end limit
		bs = pe - pb;
	}

	// Find spot within PA->PB to split it at.  This means finding
	// the first point in PB->PE that is smaller than the matching
	// point within PA->PB, centered around the PB pivot
	if (bs > (ES << 3)) {	// Binary search on larger sets
		size_t	min = 0, max = bs / ES;
		size_t	pos = max >> 1;

		sp = pb - (pos * ES);
		rp = pb + (pos * ES);

		while (min < max) {
			// The following 3 lines implement this logic
			// if (IS_LT(rp, sp - ES))
			// 	min = pos + 1;
			// else
			// 	max = pos;
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

	if (!(bs = pb - sp))	  // Determine the byte-wise size of the split
		goto shift_pop;  // If nothing to swap, we're done here

	// Do a single shift at the split point
	// The compiler optimiser REALLY doesn't like us calling block_swap here
	for (char *ta = sp, *tb = pb; ta != pb; ta += ES, tb += ES)
		SWAP(ta, tb);

	// PB->RP is the top part of A that was split, and  RP->PE is the rest
	// of the array we're merging into.

	// PA->SP is the part we left behind, and SP->PB is the part of the target
	// array that was swapped in at the split point. PB forms a hard upper
	// limit on the search space for this merge, so it's used as the new PE

	// Oddly enough, the following line helps compiler optimization on gcc
	bs = ((rp != pe) && IS_LT(rp, rp - ES));
	if (IS_LT(sp, sp - ES)) {
		if (bs)
			SHIFT_STACK_PUSH(pb, rp, pe);
		pe = pb;
		pb = sp;
		goto shift_again;
	} else if (bs) {
		pa = pb;
		pb = rp;
		goto shift_again;
	}
shift_pop:
	while (stack != _stack) {
		SHIFT_STACK_POP(pa, pb, pe);
		goto shift_again;
	}
#undef	SHIFT_STACK_PUSH
#undef	SHIFT_STACK_POP
} // shift_merge_in_place


// Classic bottom-up merge sort
static void
NAME(basic_bottom_up_sort)(char *pa, const size_t n, COMMON_PARAMS)
{
	// Handle small array size inputs with insertion sort
	if (n < (INSERT_SORT_MAX * 2))
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	char	*pe = pa + (n * ES);

	do {
		size_t	bound = n - (n % INSERT_SORT_MAX);
		char	*bpe = pa + (bound * ES);

		// First just do insert sorts on all with size INSERT_SORT_MAX
		for (char *pos = pa; pos != bpe; pos += (INSERT_SORT_MAX * ES)) {
			char	*stop = pos + (INSERT_SORT_MAX * ES);
			for (char *ta = pos + ES, *tb; ta != stop; ta += ES)
				for (tb = ta; tb != pos && IS_LT(tb, tb - ES); tb -= ES)
					SWAP(tb, tb - ES);
		}

		// Insert sort any remainder
		if (n - bound)
			CALL(insertion_sort)(bpe, n - bound, COMMON_ARGS);
	} while (0);

	for (size_t size = INSERT_SORT_MAX; size < n; size += size) {
		char	*stop = pa + ((n - size) * ES);
		for (char *pos1 = pa; pos1 < stop; pos1 += (size * ES * 2)) {
			char *pos2 = pos1 + (size * ES);
			char *pos3 = pos1 + (size * ES * 2);

			if (pos3 > pe)
				pos3 = pe;

			if (pos2 < pe)
				CALL(shift_merge_in_place)(pos1, pos2, pos3, COMMON_ARGS);
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
NAME(basic_top_down_sort)(char *pa, const size_t n, COMMON_PARAMS)
{
#if LOW_STACK
	return CALL(basic_bottom_up_sort)(pa, na, COMMON_ARGS);
#endif
	// Handle small array size inputs with insertion sort
	// Ensure there's no way na and nb could be zero
	if ((n <= INSERT_SORT_MAX) || (n <= 8))
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	size_t	na = (n * BASIC_SKEW) / 100;
	size_t	nb = n - na;
	char	*pb = pa + (na * ES);
	char	*pe = pa + (n * ES);

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
static char *
NAME(sprint_left)(char *pa, char *pe, char *pt, int direction, COMMON_PARAMS)
{
	size_t	max = (pe - pa) / ES;
	size_t	min = 0, pos;
	char	*sp;

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
static char *
NAME(sprint_right)(char *pa, char *pe, char *pt, int direction, COMMON_PARAMS)
{
	size_t	max = (pe - pa) / ES;
	size_t	min = 0, pos = 0;
	char	*sp;

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
NAME(merge_left)(char *a, size_t na, char *b, size_t nb,
			  char *w, const size_t nw, COMMON_PARAMS)
{
	char	*pe = b + (nb * ES), *pw = w;
	char	*pb = pe, *pa = b;

	assert(nb <= nw);

	// Now copy everything remaining from B to W
	for (char *tb = b; nb--; pw += ES, tb += ES)
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
			char	*which[2] = {(pw - ES), (pa - ES)};
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
				char *ta = CALL(sprint_right)(a, pa, pw - ES, LEAP_LEFT, COMMON_ARGS);
				a_run = (pa - ta) / ES;
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
				char *tw = CALL(sprint_left)(w, pw, pa - ES, LEAP_LEFT, COMMON_ARGS);
				b_run = (pw - tw) / ES;
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
NAME(merge_right)(char *a, size_t na, char *b, size_t nb,
			  char *w, const size_t nw, COMMON_PARAMS)
{
	char	*pe = b + (nb * ES);
	char	*pw = w;

	assert(na <= nw);

	// Now copy everything in A to W
	for (char *ta = a; na--; pw += ES, ta += ES)
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
			char	*which[2] = {w, b};
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
			char	*tw = CALL(sprint_right)(w, pw, b, LEAP_RIGHT, COMMON_ARGS);
			a_run = (tw - w) / ES;
			if (a_run) {
				for (size_t num = a_run; num--; w += ES, a += ES)
					SWAP(a, w);
				if (w >= pw)
					break;
			}

			// Stuff from B is sprinting
			char	*tb = CALL(sprint_left)(b, pe, w, LEAP_RIGHT, COMMON_ARGS);
			b_run = (tb - b) / ES;
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
NAME(merge_using_workspace)(char *a, size_t na, char *b, size_t nb,
			  char *w, const size_t nw, COMMON_PARAMS)
{
	assert(na > 0);
	assert(nb > 0);

	// Check if we need to do anything at all!
	if (!IS_LT(b, b - ES))
		return;

	char	*pe = b + (nb * ES);

	// Skip initial part of A if the opportunity arises
	if (!IS_LT(b, a)) {
		if (na > 10) {
			size_t	min = 1, max = na;
			size_t	pos = max >> 1;
			char	*sp = a + (pos * ES);

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
	char	*sp = pe - ES;
	char	*tb = b - ES;
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
NAME(merge_workspace_constrained) (char *pa, size_t na, char *pb, size_t nb,
			  char *ws, const size_t nw, COMMON_PARAMS)
{
	char	*pe = pb + (nb * es);

	while (na > nw) {
		char	*rp, *sp;	// Rotate + Split pointers

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
		nb = (rp - pb) / ES;

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
		na = (sp - rp) / ES;
		nb = (pe - sp) / ES;
	}
	assert(na > 0);		// It should never be possible that na == 0

	// The rotations can make nb be 0, so check it!
	if (nb > 0)
		CALL(merge_using_workspace)(pa, na, pb, nb, ws, nw, COMMON_ARGS);
} // merge_workspace_constrained


static void
NAME(sort_using_workspace)(char *pa, size_t n, char * const ws,
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

	char	*pb = pa + (na * ES);

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
NAME(merge_sort_in_place)(char * const pa, const size_t n, char * const ws,
	      const size_t nw, COMMON_PARAMS)
{
	// Handle small array size inputs with insertion sort
	if ((n <= INSERT_SORT_MAX) || (n <= 8))
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	if (ws && (nw > 0))
		return CALL(sort_using_workspace)(pa, n, ws, nw, COMMON_ARGS);

	// 9 appears to be close to optimal, but anything from 3-20 works
	size_t	na = n / WSRATIO;

	// Enforce a sensible minimum
	if (na < 4)
		na = 4;

	char	*pe = pa + (n * ES);
	char	*pb = pa + (na * ES);
	size_t	nb = n - na;

	// Sort B using A as the workspace
	CALL(sort_using_workspace)(pb, nb, pa, na, COMMON_ARGS);

	// Now recursively sort what we used as work-space
	CALL(merge_sort_in_place)(pa, na, NULL, 0, COMMON_ARGS);

	// Now merge them together
	CALL(shift_merge_in_place)(pa, pb, pe, COMMON_ARGS);
} // merge_sort_in_place


// Designed for efficiently processing smallish sets of items
// Note that the last item is always guaranteed to be unique
//
// Returns a pointer to the list of unique items positioned
// to the right-side of the array.  All duplicates are located
// at the start (left-side) of the array (A)
//  A -> PU = Duplicates
// PU -> PE = Unique items
static char *
NAME(extract_unique_sub)(char * const a, char * const pe, char *ph, COMMON_PARAMS)
{
	char	*pu = a;	// Points to list of unique items

	// Sanitize our hints pointer
	if (ph == NULL)
		ph = pe;

	// Process everything up to the hints pointer
	for (char *pa = a + ES; pa < ph; pa += ES) {
		if (IS_LT(pa - ES, pa))
			continue;

		// The item before our position is a duplicate
		// Mark it, and then find the end of the run
		char *dp = pa - ES;

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
static char *
NAME(extract_uniques)(char * const a, const size_t n, char *hints, COMMON_PARAMS)
{
	char	*pe = a + (n * ES);

	// I'm not sure what a good value should be here, but 40 seems okay
	if (n < 40)
		return CALL(extract_unique_sub)(a, pe, hints, COMMON_ARGS);

	if (hints == NULL)
		hints = pe;

	// Divide and conquer!  This algorithm appears to operate in close
	// to an O(n) time complexity, albeit with a moderately high K factor
	char	*pa = a;
	size_t	na = (n + 3) >> 2;	// Looks to be about right
	char	*pb = pa + (na * ES);

	char	*ps = pb;	// Records original intended split point

	// First find where to split at, which basically means, find the
	// end of any duplicate run that we may find ourselves in
	while ((pb < pe) && !IS_LT(pb - ES, pb))
		pb += ES;

	// If we couldn't find a sub-split, just process what we have
	if (pb == pe)
		return CALL(extract_unique_sub)(a, pe, ps, COMMON_ARGS);

	// Recalculate our size
	na = (pb - pa) / ES;
	size_t	nb = n - na;

	if (hints < pb)
		hints = pe;

	// Note that there is ALWAYS at least one unique to be found
	char	*apu = CALL(extract_uniques)(pa, na, ps, COMMON_ARGS);
	char	*bpu = CALL(extract_uniques)(pb, nb, hints, COMMON_ARGS);

	// Coalesce non-uniques together
	if (bpu > pb) {
		CALL(block_rotate)(apu, pb, bpu, COMMON_ARGS);
	}
	pb = apu + (bpu - pb);

	// PA->BP now contains non-uniques and BP->PE are uniques
	return pb;
} // extract_uniques


// I'm not going to say that the following is perfect.  Far from it.  But it
// does an okay-ish job of merging many blocks together in a fashion that
// favors forming larger blocks to the right-side.  This helps to speed up
// the in-place merging algorithm, so for all its clunkiness, it does work.
static void
NAME(merge_duplicates)(char **dups, size_t numd, char *ws, size_t nw,
		       bool ws_sorted, COMMON_PARAMS)
{
	char	*pr = ws + nw * ES;
	char	*mdups[numd];
	size_t	md = 0, start = numd;

	// Merge up everything we can, using the work-space
	while (numd > 1) {
		md = 0;
		dups[numd] = ws;

		for (size_t n = 0; n < numd; ) {
			char	*d1 = dups[n++];
			size_t	nd1 = (dups[n] - d1) / ES;
			if ((n < start) || (n == numd) || (nd1 > nw)) {
				mdups[md++] = d1;
				continue;
			}

			char	*d2 = dups[n++];
			size_t	nd2 = (dups[n] - d2) / ES;
			if (nd2 > nw) {
				mdups[md++] = d1;
				mdups[md++] = d2;
				continue;
			}

			// We have a pair we can merge
//			printf("Merging 1: nd1=%lu, nd2=%lu\n", nd1, nd2);
			CALL(merge_using_workspace)(d1, nd1, d2, nd2, ws, nw, COMMON_ARGS);
			ws_sorted = false;
			mdups[md++] = d1;
		}

		// Copy the pointers back
		for (size_t n = 0; n < md; n++)
			dups[n] = mdups[n];
		numd = md;
		if (start < 1)
			break;
		if (start)
			start--;
	}

	// We can't use the work-space any more so sort it
	if (!ws_sorted)
		CALL(merge_sort_in_place)(ws, nw, NULL, 0, COMMON_ARGS);

	// If there were no duplicates, then we're done here
	if (numd == 0)
		return;

	// Merge the workspace with the last duplicates entry
	CALL(shift_merge_in_place)(dups[numd - 1], ws, pr, COMMON_ARGS);
	dups[numd] = pr;

	// Now we finish up by pairing all the duplicates using merge in place
	do {
		md = 0;
		for (int times = 3; times && (numd > 1); times--) {
			// Force merge the last two in place 3 times
			char	*d1 = dups[numd - 2];
			char	*d2 = dups[numd - 1];
			char	*d3 = pr;
//			size_t	nd1 = (d2 - d1) / ES;
//			size_t	nd2 = (d3 - d2) / ES;
//			printf("Force Merging: nd1=%lu, nd2=%lu\n", nd1, nd2);
			CALL(shift_merge_in_place)(d1, d2, d3, COMMON_ARGS);
			numd--;
			dups[numd] = pr;
		}

		for (size_t n = 0; n < numd; ) {
			char	*d1 = dups[n++];
			size_t	nd1 = (dups[n] - d1) / ES;
			if (n == numd) {
				mdups[md++] = d1;
				continue;
			}

			char	*d2 = dups[n++];
			char	*d3 = dups[n];
			size_t	nd2 = (d3 - d2) / ES;
			if (nd2 < nd1) {
				mdups[md++] = d1;
				n--;
				continue;
			}

			// We have a pair we can merge
//			printf("Merging 2: nd1=%lu, nd2=%lu\n", nd1, nd2);
			CALL(shift_merge_in_place)(d1, d2, d3, COMMON_ARGS);
			mdups[md++] = d1;
		}
		// Copy the pointers back
		for (size_t n = 0; n < md; n++)
			dups[n] = mdups[n];
		numd = md;
	} while (numd > 1);
} // merge_duplicates


// This essentially operates as a "front end" to the main shift-merge-sort
// sequence.  Its primary role is to extract unique values from the main
// data set, which in turn allows us to use these as a workspace to pass
// to the main algorithm.  Doing so preserves sort stability.  While it is
// generating the set of uniques, it is also still sorting by generating a
// sorted set of duplicates that were disqualified.  There exists certain
// inputs where we can sort the entire set just through doing this alone!
static void
NAME(stable_sort)(char * const pa, const size_t n, COMMON_PARAMS)
{
	char	*pe = pa + (n * ES);
	char	*ws, *pr, *dups[WSTRIES + 2] = {0};
	size_t	na, nr, nw, numd = 0;

	// 200 items appears to be about the cross-over
	// That 2-stage binary insertion sort holds up pretty well!
	if (n <= 200)
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	// We start with a workspace candidate size that is intentionally
	// small, as we need to use the slower basic_sort() algorithm to
	// kick start the process.  The idea here is to then use the
	// initial unique values that we extract to drive use of the
	// merge-sort algorithm, to help us find more uniques faster!
	na = (n >> 6) + STABLE_WSRATIO;
	nr = n - na;
	pr = pa + (na * ES);	// Pointer to rest

	// Determine how much workspace we're aiming for
	size_t	wstarget = nr / STABLE_WSRATIO;

	// First sort our candidate work-space chunk
	CALL(basic_top_down_sort)(pa, na, COMMON_ARGS);

	// Now pull out our first set of unique values
	ws = CALL(extract_uniques)(pa, na, NULL, COMMON_ARGS);
	if (ws > pa)
		dups[numd++] = pa;
	nw = (pr - ws) / ES;
	na = na - nw;

	// PA->WS is pointing at (sorted) non-uniques
	// WS->PR is a set of uniques we can use as workspace
	// PR->PE is everything else that we still need to sort

	// If we couldn't find enough work-space we'll try up to num_tries
	// more.  Despite this seeming excessive, with each try we're still
	// sorting more of the array any way, so it balances out in the end.
	for (int tries = WSTRIES; (tries > 0) && (nw < wstarget); tries--) {
		// It can be real fun to activate the following printf and
		// watch the unique extractor do its thing with increasingly
		// degenerate inputs.  It's possible for stable_sort() to
		// completely sort the input in this extraction phase alone!
#if 0
		printf("Not enough workspace. Wanted: %ld  Got: %ld  "
		       "Duplicates: %ld,  Tries Remaining = %d, nr = %lu\n",
		       wstarget, nw, (ws - pa) / es, tries, nr);
#endif
		// Estimate how much of the remaining that we need to grab
		// to get enough uniques to satsify our minimum.  First work
		// out what the current ratio of uniques is
		char	*nws = pr;		// New workspace candidates
		size_t	nd = (ws - pa) / ES;	// Num Duplicates
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

		// If it's trivial amounts left, just leave!
		if (grab < 100)
			break;

		nr -= grab;
		pr = pr + (grab * ES);

		// Determine how much work-space to use for sorting.  Doing so
		// means we need to sort less of it afterwards, and saves time
		size_t tnw = grab / STABLE_WSRATIO;

		// Sort new work-space candidates using our current workspace
		CALL(merge_sort_in_place)(nws, grab, ws, tnw, COMMON_ARGS);

		// Our current work-space is now jumbled, so sort that too
		CALL(merge_sort_in_place)(ws, tnw, NULL, 0, COMMON_ARGS);

		// Merge current workspace with the new set
		CALL(shift_merge_in_place)(ws, nws, pr, COMMON_ARGS);

		// We may have picked up new duplicates.  Separate them out
		nws = CALL(extract_uniques)(ws, nw + grab, NULL, COMMON_ARGS);

		// Append any duplicates to the list of duplicates.  We'll
		// merge them together later, and then merge them back in
		if (nws > ws)
			dups[numd++] = ws;
		ws = nws;
		nw = (pr - ws) / ES;
		wstarget = nr / STABLE_WSRATIO;
	}

	bool	ws_sorted = true;

	// Here we will bypass the wstarget so long as nw > nr/64.  The work
	// space based merge algorithm will still outpace the in-place merge
	// even when given that reduced amount.  wstarget acted more as an ideal
	if ((nw < wstarget) && (nw < (nr >> 6))) {
		// Give up and fall back to good old basic_sort().  If the input
		// data is THAT degenerate, then basic_sort is very fast anyway
		CALL(basic_top_down_sort)(pr, nr, COMMON_ARGS);
	} else {
		// Sort the remainder using the workspace we extracted
		CALL(merge_sort_in_place)(pr, nr, ws, nw, COMMON_ARGS);
		ws_sorted = false;
	}

	// Now merge up all the duplicates using the work-space
	CALL(merge_duplicates)(dups, numd, ws, nw, ws_sorted, COMMON_ARGS);

	// Now merge the lot together
	CALL(shift_merge_in_place)(pa, pr, pe, COMMON_ARGS);
} // stable_sort

#undef SWAP
#undef CONCAT
#undef MAKE_STR
#undef NAME
#undef CALL
#pragma GCC diagnostic pop
