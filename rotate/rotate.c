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
		}
		else
		{
			memcpy(swap, array + left, right * sizeof(size_t));
			memmove(array + right, array, left * sizeof(size_t));
			memcpy(array, swap, right * sizeof(size_t));
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


static void
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

#if 0
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
	// Handle empty list possibilities
	if ((pa == pb) || (pb == pe))
		return;

	for (;;) {
		// Just bubble single items, either up...
		if ((pa + 1) == pb)
			return single_up(pa, pe);

		// ...or down
		if ((pb + 1) == pe)
			return single_down(pb, pa);

		// Roll all of PA->PB up as far as we can until it doesn't fit
		for (size_t bs = pb - pa; bs <= (pe - pb); pa += bs, pb += bs)
			swap_block(pa, pb, pb);

		// Check if it was a perfect fit
		if (pb < pe) {
			// Okay, so what's in A doesn't fit.  Swap a B sized
			// portion at the end of A, with B, and reloop
			size_t	*sp = pb - (pe - pb);
			swap_block(sp, pb, pb);
			pe = pb;
			pb = sp;
		} else
			return;
	}
} // rotate_block

#else

// A Gries-Mills inspired Block Rotation
static void
rotate_block(size_t *a, size_t *b, size_t *e)
{
	size_t	na = b - a, nb = e - b;

	// Handle empty list possibilities
	if ((a == b) || (b == e))
		return;

	for (;;) {
		if (na >= nb) {
			if (nb > 1) {
				// s = source, d = destination.  Not that
				// source and dest makes sense when swapping
				swap_block(b, e, a);
				a += nb;
				na = b - a;
				if (!na)
					return;
			} else {
				// Just bubble single items.
				// Going down!
				return single_down(b, a);
			}
		} else {
			if (na > 1) {
				// na < nb
				swap_block(a + nb, e, a);
				e -= na;
				nb = e - b;
				if (!nb)
					return;
			} else {
				// Just bubble single items.
				// Going up!
				return single_up(a, e);
			}
		}
	}
} // rotate_block
#endif
#endif


int
main()
{
	struct	timespec start, end;
	size_t	SZ = 1000000;
	size_t	*a;

	a = malloc(sizeof(*a) * SZ);
	if (!a) {
		printf("malloc() failure\n");
		exit(1);
	}
	for (size_t i = 0; i < SZ; i++)
		a[i] = i;

	clock_gettime(CLOCK_MONOTONIC, &start);

	for (size_t i = 1; i < SZ; i++)
#if 1
		trinity_rotation(a, i, SZ - i);
#else
		rotate_block(a, a + i, a + SZ);
#endif

	clock_gettime(CLOCK_MONOTONIC, &end);

	free(a);

	printf("Num Swaps = %lu\n", num_swaps / SZ);

	double tim = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

	printf("Time Taken = %.3fs\n", tim);
} // main
