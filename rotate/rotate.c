#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

#include "forsort-rotate.h"

static size_t	num_swaps = 0;

#define SWAP(_xa_, _xb_)				\
	{						\
		int32_t xa = *(int32_t *)(_xa_);	\
		int32_t xb = *(int32_t *)(_xb_);	\
		*(int32_t *)(_xa_) = xb;		\
		*(int32_t *)(_xb_) = xa;		\
	}

#define MAX_AUX 8

void trinity_rotation(size_t *array, size_t left, size_t right)
{
	size_t *pta, *ptb, *ptc, *ptd, swap[MAX_AUX];
	size_t loop;

	if (left < right)
	{
		if (left <= MAX_AUX)
		{
			memcpy(swap, array, left * sizeof(size_t));
			memmove(array, array + left, right * sizeof(size_t));
			memcpy(array + right, swap, left * sizeof(size_t));
		}
		else
		{
			pta = array;
			ptb = pta + left;

			loop = right - left;

			if (loop <= MAX_AUX && loop > 3)
			{
				ptc = pta + right;
				ptd = ptc + left;

				memcpy(swap, ptb, loop * sizeof(size_t));

				while (left--)
				{
					*--ptc = *--ptd; *ptd = *--ptb;
				}
				memcpy(pta, swap, loop * sizeof(size_t));
			}
			else
			{
				ptc = ptb;
				ptd = ptc + right;

				loop = left / 2;

				while (loop--)
				{
					*swap = *--ptb; *ptb = *pta; *pta++ = *ptc; *ptc++ = *--ptd; *ptd = *swap;
				}

				loop = (ptd - ptc) / 2;

				while (loop--)
				{
					*swap = *ptc; *ptc++ = *--ptd; *ptd = *pta; *pta++ = *swap;
				}

				loop = (ptd - pta) / 2;

				while (loop--)
				{
					*swap = *pta; *pta++ = *--ptd; *ptd = *swap;
				}
			}
		}
	}
	else if (right < left)
	{
		if (right <= MAX_AUX)
		{
			memcpy(swap, array + left, right * sizeof(size_t));
			memmove(array + right, array, left * sizeof(size_t));
			memcpy(array, swap, right * sizeof(size_t));
		}
		else
		{
			pta = array;
			ptb = pta + left;

			loop = left - right;

			if (loop <= MAX_AUX && loop > 3)
			{
				ptc = pta + right;
				ptd = ptc + left;

				memcpy(swap, ptc, loop * sizeof(size_t));

				while (right--)
				{
					*ptc++ = *pta; *pta++ = *ptb++;
				}
				memcpy(ptd - loop, swap, loop * sizeof(size_t));
			}
			else
			{
				ptc = ptb;
				ptd = ptc + right;

				loop = right / 2;

				while (loop--)
				{
					*swap = *--ptb; *ptb = *pta; *pta++ = *ptc; *ptc++ = *--ptd; *ptd = *swap;
				}

				loop = (ptb - pta) / 2;

				while (loop--)
				{
					*swap = *--ptb; *ptb = *pta; *pta++ = *--ptd; *ptd = *swap;
				}

				loop = (ptd - pta) / 2;

				while (loop--)
				{
					*swap = *pta; *pta++ = *--ptd; *ptd = *swap;
				}
			}
		}
	}
	else
	{
		pta = array;
		ptb = pta + left;

		while (left--)
		{
			*swap = *pta; *pta++ = *ptb; *ptb++ = *swap;
		}
	}
}

#undef MAX_AUX

static void
reverse_block(size_t * restrict pa, size_t * restrict pe)
{
	for (pe--; pa < pe; pa++, pe--)
		SWAP(pa, pe);
} // reverse_block


static inline void
swap_block(size_t * restrict pa, size_t * restrict pe, size_t * restrict pb)
{
	for ( ; pa < pe; pa++, pb++)
		SWAP(pa, pb);
}

// Half Reverse Rotate
void
half_reverse_rotate(size_t *pa, size_t *pb, size_t *pe)
{
	size_t	na = pb - pa, nb = pe - pb;

	if (na == nb)
		return swap_block(pa, pb, pb);

	if (na > nb) {
		reverse_block(pa, pb);
		reverse_block(pa, pa + nb);
		reverse_block(pa + nb, pb);
		swap_block(pa, pa + nb, pb);
	} else {
		reverse_block(pb, pe);
		reverse_block(pb, pe - na);
		reverse_block(pe - na, pe);
		swap_block(pa, pb, pe - na);
	}
}

// Classic triple-reverse rotate
void
reverse_rotate(size_t *pa, size_t *pb, size_t *pe)
{
	size_t	na = pb - pa, nb = pe - pb;

	reverse_block(pa, pb);
	reverse_block(pb, pe);
	reverse_block(pa, pe);
} // rotate_block

#undef SWAP

#define MAX 100000000
int
main()
{
	struct	timespec start, end;
	size_t	SZ = 200;
	size_t	*a;

	a = malloc(sizeof(*a) * SZ);
	if (!a) {
		printf("malloc() failure\n");
		exit(1);
	}
	for (size_t i = 0; i < SZ; i++)
		a[i] = i;

	clock_gettime(CLOCK_MONOTONIC, &start);

	size_t	stop = MAX / SZ;

	for (size_t j = 0; j < stop; j++) {
		for (size_t i = 1; i < SZ; i++) {
#if 0
			trinity_rotation(a, i, SZ - i);
#else
			triple_shift_rotate(a, a + i, a + SZ);
#endif
		}
	}

	clock_gettime(CLOCK_MONOTONIC, &end);

	printf("Num Swaps = %lu\n", num_swaps / SZ);

	double tim = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

	printf("Time Taken = %.3fs\n", tim);

	free(a);
} // main
