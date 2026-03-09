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

// Attempt to determine in a portable fashion if we are able to make use of
// AVX512 for bulk data moves.  Compile with -mavx512f to activate
#if defined(__AVX512F__)
#include <immintrin.h>
#endif

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

#define CONCAT(x, y) x ## _ ## y
#define MAKE_STR(x, y) CONCAT(x,y)
#define NAME(x) MAKE_STR(x, VAR)
#define CALL(x) NAME(x)

#ifdef UNTYPED

#define	SWAP(_xa_, _xb_)	memswap((_xa_), (_xb_), ES)

#else

#if 0
#define	SWAP(_xa_, _xb_)				\
	{						\
		VAR xa = *(VAR *)(_xa_);		\
		*(VAR *)(_xa_) = *(VAR *)(_xb_);	\
		*(VAR *)(_xb_) = xa;			\
	}
#else
#define	SWAP(_xa_, _xb_)				\
	{						\
		VAR xa = *(VAR *)(_xa_);		\
		VAR xb = *(VAR *)(_xb_);		\
		*(VAR *)(_xa_) = xb;			\
		*(VAR *)(_xb_) = xa;			\
	}
#endif
#endif

//-----------------------------------------------------------------
//                Start of rotate_block() code
//-----------------------------------------------------------------

// At their core, both triple_shift_rotate() and triple_shift_rotate_v2() are
// essentially using the overlap between any two blocks as an in-place buffer
// to effectuate a streaming transfer of bytes when exchanging the two blocks
//
// As such, their performance is highly reliant upon the compiler being able
// to optimise and engage SSE/AVX calls behind the scenes to rapidly exchange
// bytes.  When the effective buffer gets too small, the algorithms need to
// drop back to slower byte/word-wise copying, which is exactly why rotating
// a tiny block with a large block, or rotating two blocks that only differ
// in size by a small amount are slow degenerate scenarios.  It's fairly
// common practise, even for in-place algorithms, to have small fixed sized
// temporary buffers allocated on the stack to boost their operational speed.
//
// As such, the MIN_STREAM_SIZE definition below specifies the minimum overlap
// size that will be used for doing data transfers.  Overlaps smaller than
// this number of bytes (note, BYTES and not ITEMS), will instead use the
// stack buffered calls of rotate_small() and rotate_overlap() to speed up
// the handling of small transfers
//
// Suggested values to use here range from 64-1024 bytes.  A size of 0 can
// be set, which forces the algorithms to do all transfers in-place, which
// naturally comes with a performance penalty for small item sizes in the
// scenarios described above.
#define MIN_STREAM_SIZE      1024

// This is done to prevent compiler complaints if SMALL_ROTATE_SIZE is set to 0
#if (MIN_STREAM_SIZE > 0)
#define STREAM_BUF_SIZE MIN_STREAM_SIZE
#else
#define STREAM_BUF_SIZE 1
#endif

#ifdef UNTYPED
#define MIN_STREAM_ITEMS  (STREAM_BUF_SIZE / es)
#else
#define MIN_STREAM_ITEMS  (STREAM_BUF_SIZE / sizeof(VAR))
#endif

// The following 4 functions are completely optional.  They exist to handle
// the degenerate scenario of rotating a tiny block with a larger block
//
// While bridge_up and bridge_down may look superficially similar to both
// ring_up and ring_down, the bridge functions handle memory regions that
// are potentially overlapping, and so we must handle them differently in
// terms of compiler-level optimization directives, and possible AVX512 use

static void
NAME(bridge_down)(VAR * restrict pc, VAR *pd, VAR *pe, size_t num, size_t es)
{
	VAR *stop = pc - (num * ES);

	while (pc > stop) {
		pc -= ES;
		pd -= ES;
		pe -= ES;
		SWAP(pe, pc);
		SWAP(pc, pd);
	}
} // bridge_down


static void
NAME(bridge_up)(VAR * restrict pa, VAR *pb, VAR *pc, size_t num, size_t es)
{
	VAR *stop = pc + (num * ES);

	while (pc < stop) {
		SWAP(pc, pa);
		SWAP(pa, pb);
		pa += ES;
		pb += ES;
		pc += ES;
	}
} // bridge_down


// Uses a limited amount of stack space to rotate two blocks that overlap by
// only a small amount.  It's basically a special variant of rotate_small()
static void
NAME(rotate_overlap)(VAR *pa, VAR *pb, VAR *pe, size_t es)
{
	size_t	na = NITEM(pb - pa), nb = NITEM(pe - pb);
	char	_buf[STREAM_BUF_SIZE];
	void	*buf = (void *)_buf;

	// Must use actual 'es' within the mem*() calls to get sizes in bytes
	if (na < nb) {
		// Steps are:
		// 1.  Copy out the overlapping amount from the end of B into the buffer
		// 2.  Swap A with B, while moving B over to the end of the array
		// 3.  Copy the buffer back to the end of where B is now
		size_t	nc = nb - na;
		VAR	*pc = pb, *pd = pb + (na * ES);

		memcpy(buf, pd, nc * es);
		CALL(bridge_down)(pc, pd, pe, na, es);
		memcpy(pb, buf, nc * es);
	} else if (nb < na) {
		// Steps are:
		// 1.  Copy out the overlapping amount from the end of A into the buffer
		// 2.  Swap non-overlapping portion of A with B, and move B back to PC
		// 3.  Copy the buffer back to the end of where A now is
		size_t	nc = na - nb;
		VAR	*pc = pa + (nb * ES), *pd = pc + (nb * ES);

		memcpy(buf, pc, nc * es);
		CALL(bridge_up)(pa, pb, pc, nb, es);
		memcpy(pd, buf, nc * es);
	}
} // rotate_overlap


static void
NAME(rotate_small)(VAR *pa, VAR *pb, VAR *pe, size_t es)
{
	size_t	na = NITEM(pb - pa), nb = NITEM(pe - pb);
	char	_buf[STREAM_BUF_SIZE];
	void	*buf = (void *)_buf;
	VAR	*pc = pa + (nb * ES);

	// Steps are:
	// 1.  Copy out the smaller of the two arrays into the buffer entirely
	// 2.  Move the larger of the arrays over to where the smaller was
	// 3.  Copy the smaller array data back to the hole created by the move
	//
	// Must use actual 'es' within the mem*() calls to get sizes in bytes
	if (na < nb) {
		memcpy(buf, pa, na * es);
		memmove(pa, pb, nb * es);
		memcpy(pc, buf, na * es);
	} else if (nb < na) {
		memcpy(buf, pb, nb * es);
		memmove(pc, pa, na * es);
		memcpy(pa, buf, nb * es);
	}
} // rotate_small


// Swaps two blocks of equal size.  Contents of PA are swapped
// with the contents of PB. Terminates when PA reaches PE
static void
NAME(two_way_swap_block)(VAR * restrict pa, VAR * restrict pb, size_t num, size_t es)
{
	VAR * restrict stop = pb + (num * ES);

#if defined(__AVX512F__) && !defined(UNTYPED)
	num = (num * es) >> 6;			// Get number of 64-byte blocks

	// We only use AVX-512 if we have at least one full 64-byte block
	if (num) {
		char * restrict cpa = (char *)pa;
		char * restrict cpb = (char *)pb;

		for (size_t i = 0; i < num; i++) {
			// Fill 2 x AVX512 registers
			__m512i v_pa = _mm512_loadu_si512((const void*)cpa);
			__m512i v_pb = _mm512_loadu_si512((const void*)cpb);

			// Execute the 2-way swap via the AVX512 registers
			_mm512_storeu_si512((void*)cpa, v_pb);
			_mm512_storeu_si512((void*)cpb, v_pa);

			cpa += 64; cpb += 64;
		}

		// Re-sync the original pointers for the scalar cleanup
		pa = (VAR *)cpa; pb = (VAR *)cpb;
	}
#endif
	while (pb < stop) {
		SWAP(pa, pb);
		pa += ES;
		pb += ES;
	}
} // two_way_swap_block


static void
NAME(ring_positive)(VAR * restrict pa, VAR * restrict po,
		    VAR * restrict pb, size_t num, size_t es)
{
	VAR	*stop = pb + (num * ES);

#if defined(__AVX512F__) && !defined(UNTYPED)
	num = (num * es) >> 6;			// Get number of 64-byte blocks

	// We only use AVX-512 if we have at least one full 64-byte block
	if (num) {
		char * restrict cpa = (char *)pa;
		char * restrict cpo = (char *)po;
		char * restrict cpb = (char *)pb;

		for (size_t i = 0; i < num; i++) {
			// Fill 3 x AVX512 registers
			__m512i v_pa = _mm512_loadu_si512((const void*)cpa);
			__m512i v_po = _mm512_loadu_si512((const void*)cpo);
			__m512i v_pb = _mm512_loadu_si512((const void*)cpb);

			// Execute the 3-way rotation via registers
			_mm512_storeu_si512((void*)cpa, v_po);
			_mm512_storeu_si512((void*)cpo, v_pb);
			_mm512_storeu_si512((void*)cpb, v_pa);

			cpa += 64; cpo += 64; cpb += 64;
		}

		// Re-sync the original pointers for the scalar cleanup
		pa = (VAR *)cpa; po = (VAR *)cpo; pb = (VAR *)cpb;
	}
#endif
	while (pb < stop) {
		SWAP(pa, po);
		SWAP(po, pb);
		pa += ES;
		po += ES;
		pb += ES;
	}
} // ring_positive


static void
NAME(ring_negative)(VAR * restrict pa, VAR * restrict po,
		    VAR * restrict pb, size_t num, size_t es)
{
	VAR	*stop = pb - (num * ES);

#if defined(__AVX512F__) && !defined(UNTYPED)
	num = (num * es) >> 6;			// Get number of 64-byte blocks

	// We only use AVX-512 if we have at least one full 64-byte block
	if (num) {
		char * restrict cpa = (char *)pa;
		char * restrict cpo = (char *)po;
		char * restrict cpb = (char *)pb;

		for (size_t i = 0; i < num; i++) {
			cpa -= 64; cpo -= 64; cpb -= 64;

			// Fill 3 x AVX512 registers
			__m512i v_pa = _mm512_loadu_si512((const void*)cpa);
			__m512i v_po = _mm512_loadu_si512((const void*)cpo);
			__m512i v_pb = _mm512_loadu_si512((const void*)cpb);

			// Execute the 3-way rotation via registers
			_mm512_storeu_si512((void*)cpa, v_pb);
			_mm512_storeu_si512((void*)cpo, v_pa);
			_mm512_storeu_si512((void*)cpb, v_po);
		}

		// Re-sync the original pointers for the scalar cleanup
		pa = (VAR *)cpa; po = (VAR *)cpo; pb = (VAR *)cpb;
	}
#endif
	while (pb > stop) {
		pa -= ES;
		po -= ES;
		pb -= ES;
		SWAP(pb, po);
		SWAP(po, pa);
	}
} // ring_negative


// The heart of it all
static void
NAME(rotate_block)(VAR *pa, VAR *pb, VAR *pe, size_t es)
{
	size_t na = NITEM(pb - pa), nb = NITEM(pe - pb);

	for ( ; na; nb = NITEM(pe - pb), na = NITEM(pb - pa)) {
		if (na < nb) {
			if (na <= MIN_STREAM_ITEMS)
				return CALL(rotate_small)(pa, pb, pe, es);

			size_t  no = nb - na;

			if (no <= MIN_STREAM_ITEMS)
				return CALL(rotate_overlap)(pa, pb, pe, es);

			for ( ; na > no; pa += (no * ES), na -= no)
				CALL(ring_positive)(pa, pb, pe - (na * ES), no, es);

			CALL(ring_positive)(pa, pb, pe - (na * ES), na, es);

			pa = pb, pe = pb + (no * ES), pb = pb + (na * ES);
		} else if (na == nb) {
			return CALL(two_way_swap_block)(pa, pb, na, es);
		} else if (nb == 0) {
			return;
		} else {
			if (nb <= MIN_STREAM_ITEMS)
				return CALL(rotate_small)(pa, pb, pe, es);

			size_t  no = na - nb;

			if (no <= MIN_STREAM_ITEMS)
				return CALL(rotate_overlap)(pa, pb, pe, es);

			for ( ; nb > no; pe -= (no * ES), nb -= no)
				CALL(ring_negative)(pa + (nb * ES), pb, pe, no, es);

			CALL(ring_negative)(pa + (nb * ES), pb, pe, nb, es);

			pe = pb, pa = pb - (no * ES), pb = pb - (nb * ES);
		}
	}
} // rotate_block


//-----------------------------------------------------------------
//                        #define cleanup
//-----------------------------------------------------------------

#undef MIN_STREAM_ITEMS
#undef MIN_STREAM_SIZE
#undef STREAM_BUF_SIZE
#undef SWAP
#undef CONCAT
#undef MAKE_STR
#undef NAME
#undef CALL
#pragma GCC diagnostic pop
