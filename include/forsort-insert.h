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

static void
NAME(insertion_sort)(VAR *pa, const size_t n, COMMON_PARAMS)
{
	VAR	*pe = pa + (n * ES);

	for (VAR *ta = pa + ES; ta != pe; ta += ES)
		for (VAR *tb = ta; tb != pa && IS_LT(tb, tb - ES); tb -= ES)
			SWAP(tb, tb - ES);
} // insertion_sort_char

static void
NAME(sort_seven)(VAR *pa, COMMON_PARAMS)
{
	return CALL(insertion_sort)(pa, 7, COMMON_ARGS);
} // sort_six

static void
NAME(sort_six)(VAR *pa, COMMON_PARAMS)
{
	return CALL(insertion_sort)(pa, 6, COMMON_ARGS);
} // sort_six

static void
NAME(sort_five)(VAR *pa, COMMON_PARAMS)
{
	return CALL(insertion_sort)(pa, 5, COMMON_ARGS);
} // sort_five

static void
NAME(sort_four)(VAR *pa, COMMON_PARAMS)
{
	return CALL(insertion_sort)(pa, 4, COMMON_ARGS);
} // sort_five

static void
NAME(sort_three)(VAR *pa, COMMON_PARAMS)
{
	return CALL(insertion_sort)(pa, 3, COMMON_ARGS);
} // sort_five

static void
NAME(sort_two)(VAR *pa, COMMON_PARAMS)
{
	return CALL(insertion_sort)(pa, 2, COMMON_ARGS);
} // sort_five

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

// ta -> where to start sorting from
static void
NAME(insertion_sort_regular)(VAR *pa, VAR *ta, const size_t n, COMMON_PARAMS)
{
	for (VAR *pe = pa + n; ta < pe; ta++) {
		if (IS_LT(ta, ta - 1)) {
			VAR t[1] = {*ta}, *tb = ta - 1, *tc = ta;
			do {
				*tc-- = *tb--;
			} while ((tc != pa) && IS_LT(t, tb));
			*tc = *t;
		}
	}
} // insertion_sort_regular

extern void print_array(void *, size_t);

// ta -> where to start sorting from
static void
NAME(insertion_sort_binary)(VAR *pa, VAR *ta, const size_t n, COMMON_PARAMS)
{
	for (VAR *pe = pa + n; ta < pe; ta++) {
		if (IS_LT(ta, ta - 1)) {
			// Find where to insert it
			VAR   t = *ta, *restrict tc = pa;
			uint32_t max = (ta - pa) - 1;

			for (uint32_t val; (val = (max >> 1)); max -= val)
				tc = IS_LT(ta, tc + val) ? tc : tc + val;

			tc += !IS_LT(ta, tc);
			memmove(tc + 1, tc, (ta - tc) * es);
			*tc = t;
		}
	}
} // insertion_sort_binary


// Experimentally 13 appears to be the best general purpose value
#define BINARY_INSERTION_MIN    13

static void
NAME(insertion_sort)(VAR *pa, const size_t n, COMMON_PARAMS)
{
	size_t	rn = MIN(n, BINARY_INSERTION_MIN);

	CALL(insertion_sort_regular)(pa, pa + 1, rn, COMMON_ARGS);

	if (n > BINARY_INSERTION_MIN)
		CALL(insertion_sort_binary)(pa, pa + rn, n, COMMON_ARGS);
} // insertion_sort

#define	BRANCHLESS_SWAP(_xa_, _xb_)				\
	{							\
		VAR xa = *(VAR *)(_xa_);			\
		VAR xb = *(VAR *)(_xb_);			\
		res = !IS_LT(_xb_, _xa_);			\
		*(VAR *)(_xa_) = branchless(res) ? xa : xb;	\
		*(VAR *)(_xb_) = branchless(res) ? xb : xa;	\
	}

static void
NAME(sort_two)(VAR *p1, COMMON_PARAMS)
{
	VAR	*p2 = p1 + 1;
	int	res;

	BRANCHLESS_SWAP(p1, p2);
} // sort_two


static void
NAME(sort_three)(VAR *p1, COMMON_PARAMS)
{
	VAR	*p2 = p1 + 1, *p3 = p1 + 2;
	int	res;

	BRANCHLESS_SWAP(p1, p2);

	BRANCHLESS_SWAP(p2, p3);
	if (res)
		return;

	BRANCHLESS_SWAP(p1, p2);
} // sort_three


static void
NAME(sort_four)(VAR *p1, COMMON_PARAMS)
{
	VAR	*p2 = p1 + 1, *p3 = p1 + 2, *p4 = p1 + 3;
	int	res;

	BRANCHLESS_SWAP(p1, p2);
	BRANCHLESS_SWAP(p3, p4);

	BRANCHLESS_SWAP(p2, p3);
	if (res)
		return;

	BRANCHLESS_SWAP(p1, p2);	// p1 guaranteed in place
	BRANCHLESS_SWAP(p3, p4);	// p4 guaranteed in place
	BRANCHLESS_SWAP(p2, p3);	// p2/p3 guaranteed in place
} // sort_four


static void
NAME(sort_five)(VAR *p1, COMMON_PARAMS)
{
	VAR	*p2 = p1 + 1, *p3 = p1 + 2;
	VAR	*p4 = p1 + 3, *p5 = p1 + 4;
	int	res;

#if 0
	// (Near) branchless stable sort of 5 items
	BRANCHLESS_SWAP(p1, p2);
	BRANCHLESS_SWAP(p4, p5);
	BRANCHLESS_SWAP(p2, p3);
	int res2 = res;
	BRANCHLESS_SWAP(p3, p4);
	if (res & res2)
		return;

	BRANCHLESS_SWAP(p2, p3);
	res2 = res;
	BRANCHLESS_SWAP(p4, p5);	// P5 now guaranteed in place
	BRANCHLESS_SWAP(p1, p2);	// P1 now guaranteed in place
	if (res & res2)
		return;

	BRANCHLESS_SWAP(p3, p4);
	BRANCHLESS_SWAP(p2, p3);	// P2 now guaranteed in place
	BRANCHLESS_SWAP(p3, p4);	// P3 & P4 now guaranteed in place
#else
	// Appears to be the best tradeoff for random and near-sorted performance
	BRANCHLESS_SWAP(p1, p2);
	BRANCHLESS_SWAP(p3, p4);

	BRANCHLESS_SWAP(p2, p3);
	if (!res) {
		BRANCHLESS_SWAP(p1, p2);
		BRANCHLESS_SWAP(p3, p4);
		BRANCHLESS_SWAP(p2, p3);
	}

	BRANCHLESS_SWAP(p4, p5);
	if (!res) {
		BRANCHLESS_SWAP(p3, p4);
		BRANCHLESS_SWAP(p2, p3);
		BRANCHLESS_SWAP(p1, p2);
	}
#endif
} // sort_five


static void
NAME(sort_six)(VAR *p1, COMMON_PARAMS)
{
	VAR	*p2 = p1 + 1, *p3 = p1 + 2, *p4 = p1 + 3;
	VAR	*p5 = p1 + 4, *p6 = p1 + 5;
	int	res, res2;

	BRANCHLESS_SWAP(p1, p2);
	BRANCHLESS_SWAP(p3, p4);
	BRANCHLESS_SWAP(p5, p6);

	BRANCHLESS_SWAP(p2, p3);
	res2 = res;
	BRANCHLESS_SWAP(p4, p5);
	if (res & res2)
		return;

	BRANCHLESS_SWAP(p3, p4);
	BRANCHLESS_SWAP(p2, p3);
	BRANCHLESS_SWAP(p4, p5);

	BRANCHLESS_SWAP(p1, p2);	// p1 guaranteed in place
	res2 = res;
	BRANCHLESS_SWAP(p5, p6);	// p6 guaranteed in place
	if (res & res2)
		return;

	BRANCHLESS_SWAP(p2, p3);
	BRANCHLESS_SWAP(p4, p5);

	BRANCHLESS_SWAP(p3, p4);
	if (res)
		return;

	BRANCHLESS_SWAP(p4, p5);	// p5 guaranteed in place
	BRANCHLESS_SWAP(p2, p3);	// p2 guaranteed in place
	BRANCHLESS_SWAP(p3, p4);	// p3/p4 guaranteed in place
} // sort_six

static void
NAME(sort_seven)(VAR *p1, COMMON_PARAMS)
{
	VAR	*p2 = p1 + 1, *p3 = p1 + 2, *p4 = p1 + 3;
	VAR	*p5 = p1 + 4, *p6 = p1 + 5, *p7 = p1 + 6;
	int	res, res2;

	BRANCHLESS_SWAP(p1, p2);
	res2 = res;
	BRANCHLESS_SWAP(p6, p7);
	res2 &= res;
	BRANCHLESS_SWAP(p2, p3);
	res2 &= res;
	BRANCHLESS_SWAP(p5, p6);
	res2 &= res;
	BRANCHLESS_SWAP(p3, p4);
	res2 &= res;
	BRANCHLESS_SWAP(p4, p5);
	if (res & res2)
		return;

	BRANCHLESS_SWAP(p3, p4);
	res2 = res;
	BRANCHLESS_SWAP(p5, p6);
	res2 &= res;
	BRANCHLESS_SWAP(p2, p3);
	res2 &= res;
	BRANCHLESS_SWAP(p6, p7);	// p7 now in place
	res2 &= res;
	BRANCHLESS_SWAP(p1, p2);	// p1 now in place
	if (res & res2)
		return;

	BRANCHLESS_SWAP(p5, p6);
	res2 = res;
	BRANCHLESS_SWAP(p2, p3);
	res2 &= res;
	BRANCHLESS_SWAP(p4, p5);
	res2 &= res;
	BRANCHLESS_SWAP(p3, p4);
	if (res & res2)
		return;

	BRANCHLESS_SWAP(p4, p5);
	BRANCHLESS_SWAP(p2, p3);	// p2 now in place
	BRANCHLESS_SWAP(p5, p6);	// p5 now in place

	BRANCHLESS_SWAP(p4, p5);
	BRANCHLESS_SWAP(p3, p4);	// p3 now in place
	BRANCHLESS_SWAP(p4, p5);	// p4/p5 in place
} // sort_seven

#undef BRANCHLESS_SWAP
#undef BINARY_INSERTION_MIN
#endif

//--------------------------------------------------------------------------
//                          #define cleanup
//--------------------------------------------------------------------------

#undef SWAP
#undef CONCAT
#undef MAKE_STR
#undef NAME
#undef CALL
#pragma GCC diagnostic pop
