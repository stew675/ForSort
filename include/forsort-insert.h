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
#if 1
	for (VAR *pe = pa + n; ta < pe; ta++) {
		if (IS_LT(ta, ta - 1)) {
			// Find where to insert it
			VAR	t = *ta, *tb = ta - 1, *where = pa + 1;
			uint32_t mid = (tb - pa), pos = 0, mask = -2;

			do {
				uint32_t val = (mid++ >> 1);
				pos += val;
				pos -= IS_LT(ta, pa + pos) * val;
				mid >>= 1;
			} while (mid & mask);

			where = where + pos - IS_LT(ta, pa + pos);
			memmove(where + 1, where, (ta - where) * es);
			*where = t;
		}
	}
#else
	for (VAR *pe = pa + n; ta < pe; ta++) {
		if (IS_LT(ta, ta - 1)) {
			// Find where to insert it
			VAR	t = *ta, *tb = ta - 1, *where = pa;
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

			where += pos;
			for (VAR *tc = ta; tc != where; *tc-- = *tb--);
			*where = t;
		}
	}
#endif
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
