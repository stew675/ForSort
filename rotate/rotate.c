#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

size_t	num_swaps = 0;

#define SWAP(_a_, _b_)			\
	{				\
		size_t t = *(_a_);	\
		*(_a_) = *(_b_);	\
		*(_b_) = t;		\
		num_swaps++;		\
	}
#if 1
void trinity_rotation(size_t *array, size_t left, size_t right)
{
	if (left < 8 || right < 8)
	{
		size_t swap[7];

		if (left < 8)
		{
			memcpy(swap, array, left * sizeof(size_t));
			memmove(array, array + left, right * sizeof(size_t));
			memcpy(array + right, swap, left * sizeof(size_t));
			num_swaps += right;
		}
		else
		{
			memcpy(swap, array + left, right * sizeof(size_t));
			memmove(array + right, array, left * sizeof(size_t));
			memcpy(array, swap, right * sizeof(size_t));
			num_swaps += left;
		}
	}
	else
	{
		size_t *pta, *ptb, *ptc, *ptd, swap;
		size_t loop;

		pta = array;
		ptb = pta + left;
		ptc = ptb;
		ptd = ptc + right;

		if (left >= right)
		{
			loop = right / 2;

			while (loop--)
			{
				swap = *--ptb; *ptb = *pta; *pta++ = *ptc; *ptc++ = *--ptd; *ptd = swap;
				num_swaps += 3;
			}

			loop = (ptb - pta) / 2;

			while (loop--)
			{
				swap = *--ptb; *ptb = *pta; *pta++ = *--ptd; *ptd = swap;
				num_swaps += 2;
			}
		}
		else
		{
			loop = left / 2;

			while (loop--)
			{
				swap = *--ptb; *ptb = *pta; *pta++ = *ptc; *ptc++ = *--ptd; *ptd = swap;
				num_swaps += 3;
			}

			loop = (ptd - ptc) / 2;

			while (loop--)
			{
				swap = *ptc; *ptc++ = *--ptd; *ptd = *pta; *pta++ = swap;
				num_swaps += 2;
			}
		}

		loop = (ptd - pta) / 2;

		while (loop--)
		{
			swap = *pta; *pta++ = *--ptd; *ptd = swap;
			num_swaps++;
		}
	}
}
#endif

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

static void
single_up(size_t *pa, size_t *pe)
{
	size_t	*pb = pa + 1;

	while (pb < pe) {
		SWAP(pa, pb);
		pa = pb;
		pb++;
	}
}

static void
single_down(size_t *pa, size_t *pe)
{
	size_t	*pb = pa - 1;

	while (pa > pe) {
		SWAP(pa, pb);
		pa = pb;
		pb--;
	}
}

#if 0

#if 1
// Half Reverse Rotate
void
rotate_block(size_t *pa, size_t *pb, size_t *pe)
{
	size_t	na = pb - pa;
	size_t	nb = pe - pb;

	if ((pa >= pb) || (pb >= pe))
		return;

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

#else

// Classic triple-reverse rotate
void
rotate_block(size_t *pa, size_t *pb, size_t *pe)
{
	size_t	na = pb - pa;
	size_t	nb = pe - pb;

	if ((pa >= pb) || (pb >= pe))
		return;

	reverse_block(pa, pb);
	reverse_block(pb, pe);
	reverse_block(pa, pe);
} // rotate_block

#endif

#else

#if 1
// A Gries-Mills inspired block rotate.  I notice that
// this is remarkably similar to shift_merge_in_place()
static void
rotate_block(size_t *pa, size_t *pb, size_t *pe)
{
	size_t	na = pb - pa, nb = pe - pb;

	// Handle empty list possibilities
	if (!na || !nb)
		return;

	if (na < 8 || nb < 8)
	{
		size_t swap[7];

		if (na < 8)
		{
			memcpy(swap, pa, na * sizeof(size_t));
			memmove(pa, pa + na, nb * sizeof(size_t));
			memcpy(pa + nb, swap, na * sizeof(size_t));
			num_swaps += nb;
		}
		else
		{
			memcpy(swap, pa + na, nb * sizeof(size_t));
			memmove(pa + nb, pa, na * sizeof(size_t));
			memcpy(pa, swap, nb * sizeof(size_t));
			num_swaps += na;
		}
		return;
	}

	while (na > 1) {
		// Roll all of PA->PB up as far as we can until it doesn't fit
		while (na <= nb) {
			swap_block(pa, pb, pb);
			pa = pb;
			pb += na;
			nb -= na;
		}

		if (nb < 2)
			break;

		// Okay, so what's in A doesn't fit.  Swap a B sized
		// portion at the end of A, with B, and reloop
		while (nb <= na) {
			size_t	*sp = pb - nb;
			swap_block(sp, pb, pb);
			pb = sp;
			na -= nb;
		}
	}

	// Just bubble single items, either up...
	// pe == pb + nb
	if (na == 1)
		return single_up(pa, pb + nb);

	// ...or down
	if (nb == 1)
		return single_down(pb, pa);
} // rotate_block

#else

// A Gries-Mills inspired Block Rotation
static void
rotate_block(size_t *a, size_t *b, size_t *e)
{
	size_t	na = b - a, nb = e - b, off;

	if (na < 8 || nb < 8)
	{
		size_t swap[7];

		if (na < 8)
		{
			memcpy(swap, a, na * sizeof(size_t));
			memmove(a, a + na, nb * sizeof(size_t));
			memcpy(a + nb, swap, na * sizeof(size_t));
			num_swaps += nb;
		}
		else
		{
			memcpy(swap, a + na, nb * sizeof(size_t));
			memmove(a + nb, a, na * sizeof(size_t));
			memcpy(a, swap, nb * sizeof(size_t));
			num_swaps += na;
		}
		return;
	}

	int	flag = (na > 1) & (nb > 1);

	while (flag) {
		if (na >= nb) {
			// s = source, d = destination.  Not that
			// source and dest makes sense when swapping
			swap_block(b, e, a);
			na -= nb;
			flag &= (na > 1);
			a = a + nb;
		} else {
			// na < nb
			swap_block(a + nb, e, a);
			nb -= na;
			flag &= (nb > 1);
			e = b + nb;
		}
	}

	if (na == 1)
		return single_up(a, e);

	if (nb == 1)
		return single_down(b, a);
} // rotate_block
#endif
#endif


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

	for (size_t j = 0; j < 10000000; j++) {
		for (size_t i = 1; i < SZ; i++)
#if 0
			trinity_rotation(a, i, SZ - i);
#else
			rotate_block(a, a + i, a + SZ);
#endif
	}

	clock_gettime(CLOCK_MONOTONIC, &end);

	free(a);

	printf("Num Swaps = %lu\n", num_swaps / SZ);

	double tim = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

	printf("Time Taken = %.3fs\n", tim);
} // main
