//                             rotate_block()
//
// Author: Stew Forster (stew675@gmail.com)            Copyright (C) 2025
//
// I believe this to be a new variant of a block rotate algorithm.  Until I find
// otherwise, I'm going to name it the "Triple Shift Block Rotation" algorithm
//
// It ultimately has its roots in the successive swap Gries-Mills variant, but
// adds an improvement of a 3-way block swap.  When the blocks are close in
// size, it'll work similarly to the successive swap Gries-Mills, but instead
// of reducing the rotation space by the smaller array size per loop, it will
// instead collapse the rotation space by the larger array size.  This nets a
// small, but measurable speed boost that becomes more significant the larger
// the difference in sizes is.
//
// For blocks starting out with vastly different sizes it will collapse the
// rotation space by twice the size of the smaller array per loop.  This nets
// a significant speed boost over the regular successive swap Gries-Mills as 
// it quickly collapses the rotation space with every cycle.
//
// To work around the degenerate case of the two arrays differening by only a
// small amount, which collapses the rotation space by the smallest amount per
// cycle, the (optional) rotate_small() function is used.  rotate_small() will
// allocate space for a small number of items on the stack to copy the items
// out, and shift the memory over with memmove().  rotate_small() limits its
// stack use to 256 bytes however (or the size of 1 element, whichever is the
// larger), but rotate_small() can be disabled entirely in stack-restricted
// scenarios and this rotation algorithm will still run just fine, albeit with
// a ~20% speed penalty.

#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define	SWAP(_xa_, _xb_)				\
	{						\
		size_t xa = *(size_t *)(_xa_);		\
		size_t xb = *(size_t *)(_xb_);		\
		*(size_t *)(_xa_) = xb;			\
		*(size_t *)(_xb_) = xa;			\
	}

#define SMALL_ROTATE_SIZE      16

static void two_way_swap_block(size_t * restrict pa, size_t * restrict pe, size_t * restrict pb);

// Completely optional function to handle degenerate scenario of rotating a
// tiny block with a larger block
static void
rotate_small(size_t *pa, size_t *pb, size_t *pe)
{
	size_t	na = pb - pa, nb = pe - pb;

	if (na == nb)
		return two_way_swap_block(pa, pb, pe);

	size_t	buf[SMALL_ROTATE_SIZE];
	size_t	*pc = pa + nb;

	// Steps are:
	// 1.  Copy out the smaller of the two arrays into the buffer entirely
	// 2.  Move the larger of the arrays over to where the smaller was
	// 3.  Copy the smaller array data back to the hole created by the move
	if (na < nb) {
		memcpy(buf, pa, na * sizeof(*pa));
		memmove(pa, pb, nb * sizeof(*pa));
		memcpy(pc, buf, na * sizeof(*pa));
	} else {
		memcpy(buf, pb, nb * sizeof(*pa));
		memmove(pc, pa, na * sizeof(*pa));
		memcpy(pa, buf, nb * sizeof(*pa));
	}
} // rotate_small


// Uses a limited amount of stack space to rotate two blocks that overlap by
// only a small amount.  It's basically a special variant of rotate_small()
static void
rotate_overlap(size_t *pa, size_t *pb, size_t *pe)
{
	size_t	na = pb - pa, nb = pe - pb;

	if (na == nb)
		return two_way_swap_block(pa, pb, pb);

	size_t	buf[SMALL_ROTATE_SIZE];

	if (na < nb) {
		size_t	nc = nb - na, *pc = pb + nc;

		// Steps are:
		// 1.  Copy out the overlapping amount from the end of B into the buffer
		// 2.  memmove() B over to the end of the array
		// 3.  Swap A with B
		// 4.  Copy the buffer back to the end of where B is now
		memcpy(buf, pe - nc, nc * sizeof(*pa));
		memmove(pc, pb, na * sizeof(*pa));
		two_way_swap_block(pa, pb, pc);
		memcpy(pb, buf, nc * sizeof(*pa));
	} else {
		size_t	nc = na - nb, *pc = pb - nc;

		// Steps are:
		// 1.  Copy out the overlapping amount from the end of A into the buffer
		// 2.  memmove() B over to the end of A, where A is reduced by the overlap
		// 3.  Swap A with B
		// 4.  Copy the buffer back to the end of where A now is
		memcpy(buf, pc, nc * sizeof(*pa));
		memmove(pc, pb, nb * sizeof(*pa));
		two_way_swap_block(pa, pc, pc);
		memcpy(pe - nc, buf, nc * sizeof(*pa));
	}
} // rotate_overlap


// Swaps PA with PB, and then PB with PC. Terminates when PA reaches PE
static void
two_way_swap_block(size_t * restrict pa, size_t * restrict pe,
                   size_t * restrict pb)
{
	while (pa < pe) {
		SWAP(pa, pb);
		pb++;
		pa++;
	}
} // two_way_swap_block


// Swaps PA with PB, and then PB with PC. Terminates when PA reaches PE
static void
three_way_swap_block(size_t * restrict pa, size_t * restrict pe,
                     size_t * restrict pb, size_t * restrict pc)
{
	while (pa < pe) {
		SWAP(pa, pb);
		SWAP(pb, pc);
		pc++;
		pb++;
		pa++;
	}
} // three_way_swap_block

// 3 is good. 4 is very close. 0 seems the same. 1/2 are worse
#define	MIN_OVERLAP	3
static void
triple_shift_rotate(size_t *pa, size_t *pb, size_t *pe)
{
	size_t  na = pb - pa, nb = pe - pb;

	for (;;) {
		if (na <= nb) {
			size_t  nc = nb - na;

			if (na <= SMALL_ROTATE_SIZE) {
				if (na)
					rotate_small(pa, pb, pe);
				return;
			}

			if (nc < na) {
				// Overflow scenario
				if ((nc >= MIN_OVERLAP) && (nc <= SMALL_ROTATE_SIZE))
					return rotate_overlap(pa, pb, pe);

				three_way_swap_block(pb - nc, pb, pb, pe - nc);
				two_way_swap_block(pa, pb - nc, pb + nc);
				na -= nc;  pe = pb;  pb -= nc;  nb = nc;
			} else {
				// Remainder scenario
				three_way_swap_block(pa, pb, pb, pe - na);
				pa = pb;  pb += na;  pe -= na;  nb -= (na << 1);
			}
		} else {
			size_t  nc = na - nb;

			if (nb <= SMALL_ROTATE_SIZE) {
				if (nb)
					rotate_small(pa, pb, pe);
				return;
			}

			if (nc < nb) {
				// Overflow scenario
				if ((nc >= MIN_OVERLAP) && (nc <= SMALL_ROTATE_SIZE))
					return rotate_overlap(pa, pb, pe);

				three_way_swap_block(pb, pb + nc, pb - nc, pa);
				two_way_swap_block(pb + nc, pe, pa + nc);
				pa = pb;  na = nc;  pb += nc;  nb -= nc;
			} else {
				// Remainder scenario
				three_way_swap_block(pb, pe, pb - nb, pa);
				pe = pb;  pb -= nb;  pa += nb;  na -= (nb << 1);
			}
		}
	}
} // triple_shift_rotate


//-----------------------------------------------------------------
//                        #define cleanup
//-----------------------------------------------------------------

#undef SMALL_ROTATE_SIZE
#undef SWAP
