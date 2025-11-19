//				FORSORT
//
// Author: Stew Forster (stew675@gmail.com)	Copyright (C) 2021-2025
//
// This is my implementation of what I believe to be an O(nlogn) time-complexity
// O(logn) space-complexity, in-place and adaptive merge-sort style algorithm.

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

#define CONCAT(x, y) x ## _ ## y
#define MAKE_STR(x, y) CONCAT(x,y)
#define NAME(x) MAKE_STR(x, VAR)
#define CALL(x) NAME(x)


#ifdef UNTYPED

#define	SWAP(_xa_, _xb_)	memswap((_xa_), (_xb_), ES)

// Merges two sorted sub-arrays together using insertion sort
// This is horribly inefficient for all but the smallest arrays
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

// Merges two sorted sub-arrays together using insertion sort
// This is horribly inefficient for all but the smallest arrays
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


// ta -> where to start sorting from
static void
NAME(insertion_sort_binary)(VAR *pa, VAR *ta, const size_t n, COMMON_PARAMS)
{
	for (VAR *pe = pa + n; ta < pe; ta++) {
		if (IS_LT(ta, ta - 1)) {
			// Find where to insert it
			VAR	t = *ta, *tb = ta - 1, *tc = ta, *where = pa;
			uint32_t max = tb - pa, min = 0, pos = max >> 1;

			do {
				// The following 3 lines implement
				// this logic in a branchless manner
				// if (IS_LT(ta, where + pos))
				// 	max = pos;
				// else
				// 	min = pos + 1;
				int res = !!(IS_LT(ta, where + pos));
				max = (!res * max) + (res * pos++);
				min = (res * min) + (!res * pos);

				pos = (min + max) >> 1;
			} while (min < max);

			for (where += pos; tc != where; *tc-- = *tb--);
			*where = t;
		}
	}
} // insertion_sort_binary


static void
NAME(insertion_sort)(VAR *pa, const size_t n, COMMON_PARAMS)
{
	size_t	rn = MIN(n, BINARY_INSERTION_MIN);

	CALL(insertion_sort_regular)(pa, pa + 1, rn, COMMON_ARGS);

	if (n > BINARY_INSERTION_MIN)
		CALL(insertion_sort_binary)(pa, pa + rn, n, COMMON_ARGS);
} // insertion_sort

#endif

#undef CONCAT
#undef MAKE_STR
#undef NAME
#undef CALL
#pragma GCC diagnostic pop
