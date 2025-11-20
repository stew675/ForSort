#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
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

#if 0
inline void
reverse_block(size_t *pa, size_t *pe)
{
	for (pe--; pa < pe; pa++, pe--)
		SWAP(pa, pe);
} // reverse_block


#if 1
// Half Reverse Rotate
inline void
swap_block(size_t *pa, size_t *pe, size_t *pb)
{
	for ( ; pa < pe; pa++, pb++)
		SWAP(pa, pb);
}

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

#if 0
// Gries-Mills block rotate
static void
rotate_block(size_t *pa, size_t *pb, size_t *pe)
{
	size_t	*sp, *tp;

	// Handle empty list possibilities
	if ((pa == pb) || (pb == pe))
		return;

rotate_again:
	// Just bubble single items, either up...
	if ((pa + 1) == pb) {
		do {
			SWAP(pa, pb);
			pa = pb;
			pb += 1;
		} while (pb < pe);
		return;
	}
	// ...or down
	if ((pb + 1) == pe) {
		do {
			pe = pb;
			pb -= 1;
			SWAP(pb, pe);
		} while (pb > pa);
		return;
	}

	// Roll all of PA->PB up as far as we can until it
	// doesn't fit
	while ((pb - pa) <= (pe - pb)) {
		tp = pb;
		do {
			SWAP(pa, pb);
			pa += 1;
			pb += 1;
		} while (pa < tp);
	}

	// Check if it was a perfect fit
	if (pb == pe)
		return;

	// Okay, so what's in A doesn't fit.  Swap a B sized
	// portion at the end of A, with B, and reloop
	sp = pb - (pe - pb);	// Start of section of A to swap
	pe = pb;		// pb will become our new pe
	tp = sp;		// Record where the split was
	do {
		SWAP(sp, pb);
		sp += 1;
		pb += 1;
	} while (sp < pe);
	pb = tp;		// What was sp becomes our new pb
	goto rotate_again;
} // rotate_block

#else

// Gries-Mills inspired Block Rotation
static void
rotate_block(size_t *a, size_t *b, size_t *e)
{
	size_t	na = b - a, nb = e - b;

	// Handle empty list possibilities
	if ((a == b) || (b == e))
		return;

rotate_again:
	// The following single bubble below statements boost
	// average algorithm speed by 30% all by themselves!
       	if (na >= nb) {
		// Just bubble single items.
		if (nb == 1) {
			// Going down!
			do {
				e = b;
				b--;
				SWAP(b, e);
			} while (b > a);
		} else {
			// s = source, d = destination.  Not that
			// source and dest makes sense when swapping
			for (size_t *s = b, *d = a; s != e; s++, d++)
				SWAP(s, d);
			a += nb;
			if ((na = b - a))
				goto rotate_again;
		}
	} else {
		// Just bubble single items.
		if (na == 1) {
			// Going up!
			do {
				SWAP(a, b);
				a = b;
				b++;
			} while (b < e);
		} else {
			// na < nb
			for (size_t *s = a, *d = a + nb; d != e; s++, d++)
				SWAP(s, d);
			e -= na;
			if ((nb = e - b))
				goto rotate_again;
		}
	}
} // rotate_block
#endif
#endif


int
main()
{
	struct	timespec start, end;
	size_t	SZ = 5000;
	size_t	*a;

	a = malloc(sizeof(*a) * SZ);
	if (!a) {
		printf("malloc() failure\n");
		exit(1);
	}

	clock_gettime(CLOCK_MONOTONIC, &start);

	for (size_t j = 2; j < SZ; j++)
		for (size_t i = 1; i < j; i++)
			rotate_block(a, a + i, a + j);

	clock_gettime(CLOCK_MONOTONIC, &end);

	free(a);

	printf("Num Swaps = %lu\n", num_swaps / (SZ * SZ));

	double tim = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

	printf("Time Taken = %.3fs\n", tim);
} // main
