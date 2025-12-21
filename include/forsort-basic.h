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

#if 0
#define	SWAP(_xa_, _xb_)			\
	{					\
		VAR xa = *(VAR *)(_xa_);	\
		*(VAR *)(_xa_) = *(VAR *)(_xb_);\
		*(VAR *)(_xb_) = xa;		\
	}

#else

#define	SWAP(_xa_, _xb_)			\
	{					\
		VAR xa = *(VAR *)(_xa_);	\
		VAR xb = *(VAR *)(_xb_);	\
		*(VAR *)(_xb_) = xa;		\
		*(VAR *)(_xa_) = xb;		\
	}
#endif
#endif

//--------------------------------------------------------------------------
//                    basic_sort() implementation
//--------------------------------------------------------------------------

static void
NAME(bubble_one)(VAR *restrict pa, VAR *restrict pe, size_t es)
{
	pe -= ES;
	size_t len = ((char *)pe) - ((char *)pa);

#ifdef UNTYPED
	char	buf[es];

	memcpy(buf, pa, es);
	memmove(pa, pa + es, len);
	memcpy(pe, buf, es);
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
		return pb + !!IS_LT(pb, pa) * es;
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
		return pb + !!IS_LT(pb, pa);
	} else {
		for ( ; (pb != pe) && IS_LT(pb, pa); pb++);
		return pb;
	}
} // binary_search_rotate
#endif


// This algorithm appears to be viable now that I added the triple_shift_v2()
// block rotation to Forsort.  I had tried this algorithm before, but with the
// older block rotation it performed badly.  In fact this algorithm now
// performs so well that I've retired the shift/split merge in place functions
static void
NAME(rotate_merge_in_place)(VAR *pa, VAR *pb, VAR *pe, COMMON_PARAMS)
{
	ASSERT((pb > pa) && (pe > pb));

	// Check if we need to do anything at all
	if (!IS_LT(pb, pb - ES))
		return;

	// The stack_size is * 3 due to three pointers per stack entry.  Even
	// if we're asked to merge 2^64 items, the stack will be 1536 bytes
	// in size (assuming pointers are 8 bytes in size)
	size_t	bs, split_size, stack_size = msb64(NITEM(pb - pa)) * 3;
	_Alignas(64) VAR *stack_space[stack_size];
	VAR	**work_stack = stack_space, *spa, *spb, *rp;

rotate_again:
	// Special case handling of single item merges
	if ((bs = (pb - pa)) == ES) {
		rp = CALL(binary_search_rotate)(pa, pb, pe, COMMON_ARGS);
		if ((rp - pb) > (ES << 2)) {
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

			if (pos2 < pe)
				CALL(rotate_merge_in_place)(pos1, pos2, pos3, COMMON_ARGS);
		}
	}
} // basic_bottom_up_sort


// Top-down merge sort with a bias to smaller left-side arrays as this appears
// to help the in-place merge algorithm a little bit,  This makes it a hair
// faster than the bottom-up merge version of basic_sort().  basic_sort()  is
// slow (about half the speed of merge_sort_in_place) but it is sort-stable,
// and the stable_sort() function uses this to help find a set of unique items.
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

	CALL(rotate_merge_in_place)(pa, pb, pe, COMMON_ARGS);
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
