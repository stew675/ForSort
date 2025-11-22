#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

size_t	num_swaps = 0;

#if 0
#define SWAP(_a_, _b_)			\
	{				\
		size_t xa = *(_a_);	\
		*(_a_) = *(_b_);	\
		*(_b_) = xa;		\
	}
#else

#define SWAP(_a_, _b_)			\
	{				\
		size_t xa = *(_a_);	\
		size_t xb = *(_b_);	\
		*(_a_) = xb;		\
		*(_b_) = xa;		\
	}

//		num_swaps++;		\

#endif

#if 0
#define ROT3L(_a_, _b_, _c_)		\
	{				\
		size_t xa = *(_a_);	\
		*(_a_) = *(_b_);	\
		*(_b_) = *(_c_);	\
		*(_c_) = xa;		\
	}

#else

#define ROT3L(_a_, _b_, _c_)		\
	{				\
		size_t xa = *(_a_);	\
		size_t xb = *(_b_);	\
		size_t xc = *(_c_);	\
		*(_a_) = xb;		\
		*(_b_) = xc;		\
		*(_c_) = xa;		\
	}

//		num_swaps += 2;		\

#endif


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
#if 1
	if ((na <= 12) && (nb <= 100))
		return half_reverse_rotate(pa, pb, pe);
	if ((nb <= 12) && (na <= 100))
		return half_reverse_rotate(pa, pb, pe);
#else
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
#endif
	for (;;) {
		// Roll all of PA->PB up as far as we can until it doesn't fit
		if (na < 2) {
			if (na == 1)
				single_up(pa, pb + nb);
			return;
		}

		while (na <= nb) {
			swap_block(pa, pb, pb);
			pa = pb;
			pb += na;
			nb -= na;
		}

		if (nb < 2) {
			if (nb == 1)
				single_down(pb, pa);
			return;
		}

		// Okay, so what's in A doesn't fit.  Swap a B sized
		// portion at the end of A, with B, and reloop
		while (nb <= na) {
			size_t	*sp = pb - nb;
			swap_block(sp, pb, pb);
			pb = sp;
			na -= nb;
		}
	}
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

static void
three_way_swap_block(size_t * restrict pa, size_t * restrict pe,
			size_t * restrict pb, size_t * restrict pc)
{
	while (pa < pe) {
#if 0
		ROT3L(pa, pb, pc);
#else
		SWAP(pa, pb);
		SWAP(pb, pc);
#endif
		pc++;
		pb++;
		pa++;
	}
} // three_way_swap_block


#define	SMALL_ROTATE_SIZE	7

static void
rotate_small(size_t *pa, size_t *pb, size_t *pe)
{
	size_t	na = pb - pa, nb = pe - pb;
	size_t	buffer[SMALL_ROTATE_SIZE];
	size_t	*pc = pa + nb;

	if (na < nb) {
		memcpy(buffer, pa, na * sizeof(*pa));
		memmove(pa, pb, nb * sizeof(*pb));
		memcpy(pc, buffer, na * sizeof(*pa));
	} else {
		memcpy(buffer, pb, nb * sizeof(*pb));
		memmove(pc, pa, na * sizeof(*pa));
		memcpy(pa, buffer, nb * sizeof(*pb));
	}
} // rotate_small


static void
triple_shift_rotate(size_t *pa, size_t *pb, size_t *pe)
{
	size_t  na = pb - pa, nb = pe - pb;

	for (;;) {
		if (na <= nb) {
			if (na <= SMALL_ROTATE_SIZE) {
				if (na)
					rotate_small(pa, pb, pe);
				return;
			}

			if ((nb - na) < na) {
				// Overflow scenario
				size_t	nc = nb - na;
				// 0 1 2 3   4 5 6 7 8  -> NC = 1
				three_way_swap_block(pa, pa + nc, pb, pb + nc);
				swap_block(pa + nc, pb, pb + (nc << 1));
				pe -= na;
				nb = nc;
				pa += nc;
				na -= nc;
			} else {
				// Remainder scenario
				three_way_swap_block(pa, pb, pb, pe - na);
				pa = pb;
				pb += na;
				pe -= na;
				nb -= (na + na);
			}
		} else {
			if (nb <= SMALL_ROTATE_SIZE) {
				if (nb)
					rotate_small(pa, pb, pe);
				return;
			}

			if ((na - nb) < nb) {
				// Overflow scenario
				size_t	nc = na - nb;
				// 0 1 2 3 4   5 6 7 8  -> NC = 1
				three_way_swap_block(pb, pb + nc, pb - nc, pa);
				// 5 1 2 3 0   4 6 7 8
				swap_block(pb + nc, pe, pa + nc);
				// 5 6 7 8 0   4 1 2 3
				pa = pb;
				na = nc;
				pb += nc;
				nb -= nc;
			} else {
				// Remainder scenario
				three_way_swap_block(pb, pe, pb - nb, pa);
				pe = pb;
				pb -= nb;
				pa += nb;
				na -= (nb + nb);
			}
		}
	}
} // rotate_block


#define MAX 100000000
int
main()
{
	struct	timespec start, end;
	size_t	SZ = 80;
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
#if 0
			rotate_block(a, a + i, a + SZ);
#else
			triple_shift_rotate(a, a + i, a + SZ);
#endif
#endif
		}
	}

	clock_gettime(CLOCK_MONOTONIC, &end);

	free(a);

	printf("Num Swaps = %lu\n", num_swaps / SZ);

	double tim = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

	printf("Time Taken = %.3fs\n", tim);
} // main
