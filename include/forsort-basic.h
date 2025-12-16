//                              FORSORT
//
// Author: Stew Forster (stew675@gmail.com)     Copyright (C) 2021-2025
//
// This is my implementation of what I believe to be an O(nlogn) time-complexity
// O(logn) space-complexity, in-place and adaptive merge-sort style algorithm.

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

#define CONCAT(x, y) x ## _ ## y
#define MAKE_STR(x, y) CONCAT(x,y)
#define NAME(x) MAKE_STR(x, VAR)
#define CALL(x) NAME(x)

//--------------------------------------------------------------------------
//                SWAP and Insertion Sort Definitions
//--------------------------------------------------------------------------

#ifdef UNTYPED

#define	SWAP(_xa_, _xb_)	memswap((_xa_), (_xb_), ES)

#else

#define	SWAP(_xa_, _xb_)			\
	{					\
		VAR xa = *(VAR *)(_xa_);	\
		VAR xb = *(VAR *)(_xb_);	\
		*(VAR *)(_xb_) = xa;		\
		*(VAR *)(_xa_) = xb;		\
	}
#endif

//--------------------------------------------------------------------------
//                    basic_sort() implementation
//--------------------------------------------------------------------------

#ifdef UNTYPED
// Merges two sorted sub-arrays together using insertion sort
// This is horribly inefficient for all but the smallest arrays
// It is assumed upon entry that the first element of B is less
// than the last element of A.  It is upon the caller to ensure
// this condition
// This is the generic char type implementation
static void
NAME(insertion_merge_in_place)(VAR * pa, VAR * pb, VAR * pe, COMMON_PARAMS)
{
	VAR	*tb = pe;

	do {
		pe = tb - ES; tb = pb - ES; pb = tb;
		do {
			SWAP(tb + ES, tb);
			tb += ES;
		} while ((tb != pe) && IS_LT(tb + ES, tb));
	} while ((pb != pa) && IS_LT(pb, pb - ES));
} // insertion_merge_in_place

#else

// Merges two sorted sub-arrays together using insertion sort
// This is horribly inefficient for all but the smallest arrays
// It is assumed upon entry that the first element of B is less
// than the last element of A.  It is upon the caller to ensure
// this condition
// This is the type-specific implementation
static void
NAME(insertion_merge_in_place)(VAR * pa, VAR * pb, VAR * pe, COMMON_PARAMS)
{
	VAR	*tb = pe;

	do {
		pe = tb - 1; tb = pb - 1; pb = tb;

		VAR	t[1] = {*tb}, *tc = tb + 1;

		do {
			*tb++ = *tc++;
		} while ((tb != pe) && IS_LT(tc, t));

		*tb = *t;
	} while ((pb != pa) && IS_LT(pb, pb - ES));
} // insertion_merge_in_place
#endif


static void
NAME(swap_block)(VAR *restrict pa, VAR *restrict pb, size_t num, size_t es)
{
#if 1
	VAR	*restrict stop = pa + (num * ES);

	while (pa != stop) {
		SWAP(pa, pb);
		pb += ES, pa += ES;
	}
#else
	for ( ; pa < pe; pa += ES, pb += ES)
		SWAP(pa, pb);
#endif
} // swap_block


// Assumes initial condition that *PA < *(PA - ES)
static void
NAME(bubble_down)(VAR *restrict pa, VAR *restrict pe, COMMON_PARAMS)
{
	VAR	*restrict pn = pa - ES;

	// Bubble Element Down
	ASSERT(pa > pe);
	do {
		SWAP(pa, pn);
		pa = pn;
		pn -= ES;
	} while ((pa != pe) && IS_LT(pa, pn));
} // bubble_down


// Assumes initial condition that *PA < *(PA + ES)
static VAR *
NAME(bubble_up)(VAR *restrict pa, VAR *restrict pe, COMMON_PARAMS)
{
	VAR	*restrict pn = pa + ES;

	// Bubble Element Up
	ASSERT(pn < pe);
	do {
		SWAP(pa, pn);
		pa = pn;
		pn += ES;
	} while ((pn != pe) && IS_LT(pn, pa));
	return pa;
} // bubble_up


static void
NAME(bubble_one)(VAR *restrict pa, VAR *restrict pe, size_t es)
{
	pe -= ES;
	size_t len = ((char *)pe) - ((char *)pa);

#ifdef UNTYPED
	char	buf[es];

	memcpy(buf, pa, es);
	memmove(pa, pa + es, len);
	memcpy(pe - es, buf, es);
#else
	VAR	t = *pa;
	memmove(pa, pa + 1, len);
	*pe = t;
#endif
} // bubble_one


#ifdef UNTYPED
static VAR *
NAME(binary_search_rotate)(VAR *restrict pa, VAR *restrict pb, VAR *restrict pe, COMMON_PARAMS)
{
	ASSERT (pb <= pe);

	size_t len = NITEM(pe - pb);

	// Find where to rotate
	if (len > 12) {
		size_t pos = 0, mask = -2;
		do {
			size_t val = (len++ >> 1);
			pos += val;
			size_t res = IS_LT(pb + pos * es, pa) - 1;
			pos -= res & val;
			len >>= 1;
		} while (len & mask);

		pb += (pos * es);
		return pb + IS_LT(pb, pa) * es;
	} else {
		for ( ; (pb != pe) && IS_LT(pb, pa); pb += es);
		return pb;
	}
} // binary_search_rotate
#else
static VAR *
NAME(binary_search_rotate)(VAR *restrict pa, VAR *restrict pb, VAR *restrict pe, COMMON_PARAMS)
{
	ASSERT (pb <= pe);

	size_t len = pe - pb;

	// Find where to rotate
	if (len > 12) {
		size_t pos = 0, mask = -2;

		do {
			size_t val = (len++ >> 1);
			pos += val;
			size_t res = IS_LT(pb + pos, pa) - 1;
			pos -= res & val;
			len >>= 1;
		} while (len & mask);

		pb += pos;
		return pb + IS_LT(pb, pa);
	} else {
		for ( ; (pb != pe) && IS_LT(pb, pa); pb++);
		return pb;
	}
} // binary_search_rotate
#endif


// This algorithm appears to be viable now that I added the triple_shift_v2()
// block rotation to Forsort.  I had tried this algorithm before, but with the
// older block rotation it performed badly. It now appears that this is out
// performing split_merge_in_place() AND requires 1/3 of the stack space.  It
// isn't as fast as shift_merge_in_place() is though, being about 5% slower

static void
NAME(rotate_merge_in_place)(VAR *pa, VAR *pb, VAR *pe, COMMON_PARAMS)
{
	ASSERT((pb > pa) && (pe > pb));

	// Check if we need to do anything at all
	if (!IS_LT(pb, pb - ES))
		return;

	// The stack_size is * 2 due to two pointers per stack entry.  Even if
	// we're asked to merge 2^64 items, the stack will be 1024 bytes in
	// size, if pointers are 8 bytes in size
	size_t	bs, split_size, stack_size = msb64(NITEM(pb - pa)) * 3;
	_Alignas(64) VAR *stack_space[stack_size];
	VAR	**work_stack = stack_space, *spa, *spb, *rp;

rotate_again:
	// Special case handling of single item merges
	if ((bs = (pb - pa)) == ES) {
		rp = CALL(binary_search_rotate)(pa, pb, pe, COMMON_ARGS);
		if ((rp - pb) > (ES * 7)) {
			CALL(bubble_one)(pa, rp, es);
		} else {
			do {
				SWAP(pa, pb);
				pa = pb;
				pb += ES;
			} while (pb < rp);
		}
		goto rotate_pop;
	}

	// Split block into half
	// PA->PB will point at first half
	// SPA->SPB points at second half
	split_size = (NITEM(bs) >> 1) * ES;
	spa = pa + split_size;
	spb = pb;
	pb = spa;

	rp = CALL(binary_search_rotate)(spa, spb, pe, COMMON_ARGS);

	if (rp > spb) {
		// Now rotate the block.  This puts SPA precisely into position
		CALL(rotate_block)(spa, spb, rp, es);
		spa += (rp - spb);
		spb = rp;
	}

	// If SPA->SPB didn't get moved to the end, add it to the work stack
	// It's faster if we defer the check of spb < spb - ES until after
	// we pop the work item off the stack due to memory access patterns
	if ((spb < pe) && ((spb - spa) > ES)) {
		*work_stack++ = spa + ES;
		*work_stack++ = spb;
		*work_stack++ = pe;
	}

	if (IS_LT(pb, pb - ES)) {
		pe = spa;
		goto rotate_again;
	}

rotate_pop:
	while (work_stack != stack_space) {
		pe = *--work_stack;
		pb = *--work_stack;
		pa = *--work_stack;
		if (IS_LT(pb, pb - ES))
			goto rotate_again;
	}
} // rotate_merge_in_place
	

static VAR *
NAME(binary_search_split)(VAR *restrict sp, VAR *restrict pb, COMMON_PARAMS)
{
	ASSERT (sp <= pb);

	size_t	bs = pb - sp;
	VAR *restrict rp;

	if (bs > (ES * 12)) {
		// Binary Search only on larger sets
		size_t mid = NITEM(bs), pos = 0, mask = -2;
		do {
			size_t val = (mid++ >> 1) * ES;
			pos += val;
			size_t res = IS_LT(pb + pos, pb - (pos + ES)) - 1;
			pos -= res & val;
			mid >>= 1;
		} while (mid & mask);

		sp = pb - pos;
		return sp - IS_LT(pb + pos, sp - ES) * ES;
	} else {
		// Linear scans are faster for smaller sets
		rp = pb + bs;
		while (sp != pb) {
			rp -= ES;
			if (IS_LT(rp, sp))
				return sp;
			sp += ES;
		}
		return sp;
	}
} // binary_search_split


#define	SHIFT_STACK_PUSH(s1, s2, s3) 	\
	{ *stack++ = s1; *stack++ = s2; *stack++ = s3; }

#define	SHIFT_STACK_POP(s1, s2, s3) \
	{ s3 = *--stack; s2 = *--stack; s1 = *--stack; }

// This is just the reverse of shift_merge_in_place().  I'll leave less comments
// in this function as a result.  reverse_merge_in_place() won't re-reverse the
// direction back to shift_merge_in_place().  This is to prevent potential stack
// overflows.  Instead it will just persist, and if it runs out of stack, it'll
// fall back to the fully stack bounded split_merge_in_place().  I've never seen
// it happen, but that doesn't meant it cannot
static void
NAME(reverse_merge_in_place)(VAR *pa, VAR *pb, VAR *pe, COMMON_PARAMS)
{
	ASSERT((pb > pa) && (pe > pb));

	// Check if we need to do anything at all before proceeding
	if (!IS_LT(pb, pb - ES))
		return;

	size_t	stack_size = msb64(NITEM(pb - pa)) * 12;
	_Alignas(64) VAR *_stack[stack_size];
	VAR	**stack = _stack, **maxstack = stack + stack_size;
	VAR	*rp, *sp;
	size_t	bs;

reverse_again:
	// Just insert merge single items. We already know that *PB < *PA
	if ((bs = (pe - pb)) == ES) {
		CALL(bubble_down)(pb, pa, COMMON_ARGS);
		goto reverse_pop;
	} else if ((pa + ES) == pb) {
		CALL(bubble_up)(pa, pe, COMMON_ARGS);
		goto reverse_pop;
	}

	// Insertion MIP is slightly faster for very small sorted array pairs
	if ((pe - pa) <= (ES * 11)) {
		CALL(insertion_merge_in_place)(pa, pb, pe, COMMON_ARGS);
		goto reverse_pop;
	}

	// Shift entirety of PB->PE down as far as we can
	for (sp = pb - bs; sp >= pa && IS_LT(pe - ES, sp); sp -= bs) {
		CALL(swap_block)(sp, pb, NITEM(bs), es);
		pb -= bs;  pe -= bs;
	}

	// Handle scenario where our block cannot fit within what remains
	if (sp < pa) {
		if (pb == pa)
			goto reverse_pop;

		// Adjust block size to account for approaching the end of PB->PE
		bs = pb - pa;
	}

	// Find spot within PB->PE to split it at.
	sp = CALL(binary_search_split)(pb - bs, pb, COMMON_ARGS);

	// If nothing to swap, we're done here
	if (sp == pb)
		goto reverse_pop;

	// Adjust rp to match the split point on the other side of pb
	rp = pb + (pb - sp);

	// Do a single shift at the split point
	for (VAR *ta = sp, *tb = pb; ta != pb; ta += ES, tb += ES)
		SWAP(ta, tb);

	// See forward_merge_in_place() for an explanation of the following
	// This here is just the reverse direction of that same thing.
	bs = (sp > pa) && IS_LT(sp, sp - ES);
	if (IS_LT(rp, rp - ES)) {
		if (bs) {
			// If our stack is about to over-flow, just invoke
			// rotate_merge_in_place().  It's a bit slower but
			// we'll only use it until the obstacle has passed
			SHIFT_STACK_PUSH(pa, sp, pb);
			if (unlikely(stack == maxstack)) {
				CALL(rotate_merge_in_place)(pb, rp, pe, COMMON_ARGS);
				goto reverse_pop;
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
reverse_pop:
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
	ASSERT((pb > pa) && (pe > pb));

	// Check if we need to do anything at all before proceeding
	if (!IS_LT(pb, pb - ES))
		return;

	// The work stack holds 3 pointers per "position" and so the
	// multiplier here must be an even multiple of 3.
	size_t	stack_size = msb64(NITEM(pb - pa)) * 12;
	_Alignas(64) VAR *_stack[stack_size];
	VAR	**stack = _stack, **maxstack = stack + stack_size;
	VAR	*rp, *sp;	// Roaming-Pointer, and Split Pointer
	size_t	bs;		// Byte-wise block size of pa->pb

shift_again:
	// The presumption at the start of each loop is that *PB < *(PB - ES)

	// Just bubble merge single items.
	if ((bs = (pb - pa)) == ES) {
		CALL(bubble_up)(pa, pe, COMMON_ARGS);
		goto shift_pop;
	}

	// Just bubble merge single items.
	if ((pb + ES) == pe) {
		CALL(bubble_down)(pb, pa, COMMON_ARGS);
		goto shift_pop;
	}

	// Insertion MIP is faster for very small sorted array pairs
	if ((pe - pa) <= (ES * 12)) {
		CALL(insertion_merge_in_place)(pa, pb, pe, COMMON_ARGS);
		goto shift_pop;
	}

	// Shift entirety of PA->PB up as far as we can
	for (rp = pb + bs; (rp <= pe) && IS_LT(rp - ES, pa); rp += bs) {
		CALL(swap_block)(pa, pb, NITEM(bs), es);
		pa += bs;
		pb += bs;
	}

	// Handle scenario where our block cannot fit within what remains
	if (rp > pe) {
		// Check scenario where our block just perfectly!
		if (pb == pe)
			goto shift_pop;

		// If it looks like we're working on merging a much larger array
		// into a smaller one, then reverse the merge direction
		if ((pb - pa) > ((pe - pb) << 2)) {
			CALL(reverse_merge_in_place)(pa, pb, pe, COMMON_ARGS);
			goto shift_pop;
		}

		// Adjust block size to account for approaching the end of PB->PE
		bs = (pe - pb);
	}

	// We couldn't shift the full PA->PB block up any further
	// Split the block up, and keep trying with the remainders
	// Find spot within PA->PB to split it at.  This means finding
	// the first point in PB->PE that is smaller than the matching
	// point within PA->PB, centered around the PB pivot
	sp = CALL(binary_search_split)(pb - bs, pb, COMMON_ARGS);

       	// If there is nothing to swap then we're done here
	if (sp == pb)
		goto shift_pop;

	// Adjust rp to match the split point on the other side of pb
	rp = pb + (pb - sp);

	// Do a single block swap from the split point.  I don't know why but
	// the compiler optimiser REALLY doesn't like us calling swap_block here
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
			// If our stack is about to over-flow, move to the reverse
			// direction.  Chances are high that we've hit a degenerate
			// pattern that a reversed merge will overcome easily
			SHIFT_STACK_PUSH(pb, rp, pe);
			if (unlikely(stack == maxstack)) {
				CALL(reverse_merge_in_place)(pa, sp, pb, COMMON_ARGS);
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
	if (n < BASIC_INSERT_MAX)
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	VAR	*pe = pa + (n * ES);

	do {
		size_t	bound = n - (n % BASIC_INSERT_MAX);
		VAR	*bpe = pa + (bound * ES);

		// First just do insert sorts on all with size BASIC_INSERT_MAX
		for (VAR *pos = pa; pos != bpe; pos += (BASIC_INSERT_MAX * ES)) {
			VAR	*stop = pos + (BASIC_INSERT_MAX * ES);
			for (VAR *ta = pos + ES, *tb; ta != stop; ta += ES)
				for (tb = ta; tb != pos && IS_LT(tb, tb - ES); tb -= ES)
					SWAP(tb, tb - ES);
		}

		// Insert sort any remainder
		if (n - bound)
			CALL(insertion_sort)(bpe, n - bound, COMMON_ARGS);
	} while (0);

	for (size_t size = BASIC_INSERT_MAX; size < n; size += size) {
		VAR	*stop = pa + ((n - size) * ES);
		for (VAR *pos1 = pa; pos1 < stop; pos1 += (size * ES * 2)) {
			VAR *pos2 = pos1 + (size * ES);
			VAR *pos3 = pos1 + (size * ES * 2);

			if (pos3 > pe)
				pos3 = pe;

			if (pos2 < pe) {
#if LOW_STACK
				CALL(rotate_merge_in_place)(pos1, pos2, pos3, COMMON_ARGS);
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
	// Handle small array size inputs with insertion sort
	// Ensure there's no way na and nb could be zero
	if ((n <= BASIC_INSERT_MAX) || (n <= 8))
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	size_t	na = (n * BASIC_SKEW) / 100;
	size_t	nb = n - na;
	VAR	*pb = pa + (na * ES);
	VAR	*pe = pa + (n * ES);

	CALL(basic_top_down_sort)(pa, na, COMMON_ARGS);
	CALL(basic_top_down_sort)(pb, nb, COMMON_ARGS);

#if 0
	CALL(shift_merge_in_place)(pa, pb, pe, COMMON_ARGS);
#else
	CALL(rotate_merge_in_place)(pa, pb, pe, COMMON_ARGS);
#endif
} // basic_top_down_sort


// Breaking this out into a separate function appears to help the C optimizer
// Reverse from start -> (end - ES)
static void
NAME(reverse_block)(VAR *restrict pa, VAR *restrict pe, size_t es)
{
	while (true) {
		pe -= ES;
		if (pa >= pe)
			return;
		SWAP(pa, pe);
		pa += ES;
	}
} // reverse_block


static VAR *
NAME(process_descending)(VAR *restrict pa, VAR *restrict pe, COMMON_PARAMS)
{
	VAR *restrict prev = pa, *restrict curr = pa + ES;

	ASSERT(pa < pe);
	while ((curr != pe) && IS_LT(curr, prev)) {
		prev = curr;
		curr += ES;
	}
	return curr;
} // process_descending


static VAR *
NAME(process_ascending)(VAR *restrict pa, VAR *restrict pe, COMMON_PARAMS)
{
	VAR *restrict prev = pa, *restrict curr = pa + ES;

	ASSERT(pa < pe);
	while (curr != pe) {
		if (IS_LT(curr, prev))
			return curr;
		prev = curr;
		curr += ES;
	}
	return curr;
} // process_ascending


// Because basic sort is so heavily reliant upon insertion sort, and because
// insertion sort's worst case is reversed input, this is the one time that
// Forsort explicitly does something to handle reversed inputs
static size_t
NAME(dereverse)(VAR * const pa, const size_t n, COMMON_PARAMS)
{
	VAR	*pe = pa + (n * ES), *curr = pa, *start;
	size_t	reversals = 0;

	// I learned a lesson here.  Break out tight loops into their own
	// functions and let the C compiler optimize it.  This allows the
	// compiler to work around CPU UOP cache alignment issues better.
	while (curr != pe) {
		curr = CALL(process_ascending)(curr, pe, COMMON_ARGS);
		if (curr == pe)
			return reversals;
		start = curr;
		curr = CALL(process_descending)(curr, pe, COMMON_ARGS);
		reversals += NITEM(curr - start);
		CALL(reverse_block)(start - ES, curr, es);
	}
	return reversals;
} // dereverse


static size_t
NAME(basic_sort)(VAR *pa, const size_t n, COMMON_PARAMS)
{
	size_t reversals = CALL(dereverse)(pa, n, COMMON_ARGS);

	if (!reversals)		// Already sorted
		return 0;
#if LOW_STACK
	CALL(basic_bottom_up_sort)(pa, n, COMMON_ARGS);
#else
	CALL(basic_top_down_sort)(pa, n, COMMON_ARGS);
#endif
	return reversals;
} // basic_sort


//--------------------------------------------------------------------------
//                          #define cleanup
//--------------------------------------------------------------------------

#undef SWAP
#undef CONCAT
#undef MAKE_STR
#undef NAME
#undef CALL
#pragma GCC diagnostic pop
