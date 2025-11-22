//                              FORSORT
//
// Author: Stew Forster (stew675@gmail.com)     Copyright (C) 2021-2025
//
// This is my implementation of what I believe to be an O(nlogn) time-complexity
// O(logn) space-complexity, in-place and adaptive merge-sort style algorithm.
//
//                             rotate_block()
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
// a ~20% speed penalty.  The impact that this has on the sort algorithm is
// barely measurable however.
//
// I've tried many block swap variants now, and this one appears to be the most
// performant for the Forsort algorithm's typical block swap patterns.  I am
// not claiming that this is the fastest algorithm for all use cases. It is just
// apparently the fastest for ForSort.

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

#define CONCAT(x, y) x ## _ ## y
#define MAKE_STR(x, y) CONCAT(x,y)
#define NAME(x) MAKE_STR(x, VAR)
#define CALL(x) NAME(x)

#ifdef UNTYPED

#define	SWAP(_xa_, _xb_)	memswap((_xa_), (_xb_), ES)

#else

#define	SWAP(_xa_, _xb_)				\
	{						\
		VAR xa = *(VAR *)(_xa_);		\
		VAR xb = *(VAR *)(_xb_);		\
		*(VAR *)(_xa_) = xb;			\
		*(VAR *)(_xb_) = xa;			\
	}

#endif

//-----------------------------------------------------------------
//                Start of rotate_block() code
//-----------------------------------------------------------------

// rotate_small() and rotate_overlap() can use a small number of items worth of
// stack space as a buffer to speed up the rotate_block() algorithm.  If
// LOW_STACK and arbitrary object sizes are set, then rotate_small() won't get
// used.
//
// The rotate_block() algorithm will run about 20% slower on average, if no
// stack space is allowed.  If arbitrary item sizes are set, but LOW_STACK is
// not, then we will allocate 1 item in size on the stack.
//
// If we have specific types set, then since the item sizes are well bounded so
// we'll use up to 16 items worth (256 bytes at most), which enables the
// rotate_block() algorithm to run at good pace.
//
// In general, the higher you make this value, the faster the algorithm will
// run, but beyond about 16 items the gains do start to aymptote, and so a
// value of 16 here is a decent tradeoff between speed and minimal stack use.
#ifdef UNTYPED
#if LOW_STACK
#define SMALL_ROTATE_SIZE       0
#else
#define SMALL_ROTATE_SIZE       1
#endif
#else
#define SMALL_ROTATE_SIZE       16
#endif

static void NAME(two_way_swap_block)(VAR * restrict pa, VAR * restrict pe, VAR * restrict pb, size_t es);

// Completely optional function to handle degenerate scenario of rotating a
// tiny block with a larger block
static void
NAME(rotate_small)(VAR *pa, VAR *pb, VAR *pe, size_t es)
{
	size_t	na = NITEM(pb - pa), nb = NITEM(pe - pb);

	if (na == nb)
		return CALL(two_way_swap_block)(pa, pb, pb, es);

	VAR	buffer[ES * SMALL_ROTATE_SIZE];
	VAR	*pc = pa + (nb * ES);

	// Steps are:
	// 1.  Copy out the smaller of the two arrays into the buffer entirely
	// 2.  Move the larger of the arrays over to where the smaller was
	// 3.  Copy the smaller array data back to the hole created by the move
	//
	// Must use actual 'es' within the mem*() calls to get sizes in bytes
	if (na < nb) {
		memcpy(buffer, pa, na * es);
		memmove(pa, pb, nb * es);
		memcpy(pc, buffer, na * es);
	} else if (nb < na) {
		memcpy(buffer, pb, nb * es);
		memmove(pc, pa, na * es);
		memcpy(pa, buffer, nb * es);
	}
} // rotate_small


// Uses a limited amount of stack space to rotate two blocks that overlap by
// only a small amount.  It's basically a special variant of rotate_small()
static void
NAME(rotate_overlap)(VAR *pa, VAR *pb, VAR *pe, size_t es)
{
	size_t	na = NITEM(pb - pa), nb = NITEM(pe - pb);

	if (na == nb)
		return CALL(two_way_swap_block)(pa, pb, pb, es);

	VAR	buffer[ES * SMALL_ROTATE_SIZE];

	// Must use actual 'es' within the mem*() calls to get sizes in bytes
	if (na < nb) {
		size_t	nc = nb - na;
		VAR	*pc = pb + (nc * ES);

		// Steps are:
		// 1.  Copy out the overlapping amount from the end of B into the buffer
		// 2.  memmove() B over to the end of the array
		// 3.  Swap A with B
		// 4.  Copy the buffer back to the end of where B is now
		memcpy(buffer, pe - (nc * ES), nc * es);
		memmove(pc, pb, na * es);
		CALL(two_way_swap_block)(pa, pb, pc, es);
		memcpy(pb, buffer, nc * es);
	} else if (nb < na) {
		size_t	nc = na - nb;
		VAR	*pc = pb - (nc * ES);

		// Steps are:
		// 1.  Copy out the overlapping amount from the end of A into the buffer
		// 2.  memmove() B over to the end of A, where A is reduced by the overlap
		// 3.  Swap A with B
		// 4.  Copy the buffer back to the end of where A now is
		memcpy(buffer, pc, nc * es);
		memmove(pc, pb, nb * es);
		CALL(two_way_swap_block)(pa, pc, pc, es);
		memcpy(pe - (nc * ES), buffer, nc * es);
	}
} // rotate_overlap

// The following 3 functions, and the SWAP macro,  are the only functions
// actually required for the block rotate algorithm to do its thing.  The
// rotate_small() and rotate_overlap() functions act more as optional
// "helpers" to handle a small handful of degenerate corner cases.

// Swaps PA with PB, and then PB with PC. Terminates when PA reaches PE
static void
NAME(two_way_swap_block)(VAR * restrict pa, VAR * restrict pe,
		        VAR * restrict pb, size_t es)
{
	while (pa < pe) {
		SWAP(pa, pb);
		pb += ES;
		pa += ES;
	}
} // two_way_swap_block


// Swaps PA with PB, and then PB with PC. Terminates when PA reaches PE
static void
NAME(three_way_swap_block)(VAR * restrict pa, VAR * restrict pe,
		        VAR * restrict pb, VAR * restrict pc, size_t es)
{
	while (pa < pe) {
		SWAP(pa, pb);
		SWAP(pb, pc);
		pc += ES;
		pb += ES;
		pa += ES;
	}
} // three_way_swap_block


static void
NAME(rotate_block)(VAR *pa, VAR *pb, VAR *pe, size_t es)
{
	size_t  na = NITEM(pb - pa), nb = NITEM(pe - pb);

	for (;;) {
		if (na <= nb) {
			size_t  nc = nb - na;

			if (na <= SMALL_ROTATE_SIZE) {
				if (na)
					CALL(rotate_small)(pa, pb, pe, es);
				return;
			}

			if (nc < na) {
				// Overflow scenario
				size_t	bsc = nc * ES;	// Block Size C

				if ((nc > 2) && (nc <= SMALL_ROTATE_SIZE))
					return CALL(rotate_overlap)(pa, pb, pe, es);

				CALL(three_way_swap_block)(pb - bsc, pb, pb, pe - bsc, es);
				CALL(two_way_swap_block)(pa, pb - bsc, pb + bsc, es);
				na -= nc;
				pe = pb;
				pb -= bsc;
				nb = nc;
			} else {
				// Remainder scenario
				size_t	bsa = pb - pa;	// Block Size A

				CALL(three_way_swap_block)(pa, pb, pb, pe - bsa, es);
				pa = pb;
				pb += bsa;
				pe -= bsa;
				nb -= (na << 1);
			}
		} else {
			size_t  nc = na - nb;

			if (nb <= SMALL_ROTATE_SIZE) {
				if (nb)
					CALL(rotate_small)(pa, pb, pe, es);
				return;
			}

			if (nc < nb) {
				// Overflow scenario
				size_t	bsc = nc * ES;	// Block Size C

				if ((nc > 2) && (nc <= SMALL_ROTATE_SIZE))
					return CALL(rotate_overlap)(pa, pb, pe, es);

				CALL(three_way_swap_block)(pb, pb + bsc, pb - bsc, pa, es);
				CALL(two_way_swap_block)(pb + bsc, pe, pa + bsc, es);
				pa = pb;
				na = nc;
				pb += bsc;
				nb -= nc;
			} else {
				// Remainder scenario
				size_t	bsb = pe - pb;	// Block Size B

				CALL(three_way_swap_block)(pb, pe, pb - bsb, pa, es);
				pe = pb;
				pb -= bsb;
				pa += bsb;
				na -= (nb << 1);
			}
		}
	}
} // rotate_block


//-----------------------------------------------------------------
//                        #define cleanup
//-----------------------------------------------------------------

#undef SMALL_ROTATE_SIZE
#undef SWAP
#undef CONCAT
#undef MAKE_STR
#undef NAME
#undef CALL
#pragma GCC diagnostic pop
