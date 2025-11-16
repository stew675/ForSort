//				FORSORT
//
// Author: Stew Forster (stew675@gmail.com)	Copyright (C) 2021-2025
//
// This is my implementation of what I believe to be an O(nlogn) in-place
// adaptive merge-sort style algorithm.
//
// There is (almost) nothing new under the sun, and this is certainly an
// evolution of the work of many others.  It has its roots in the following:
//
// - Merge Sort
// - Insertion Sort
// - Block Sort
// - Grail Sort
// - Powermerge - https://koreascience.kr/article/CFKO200311922203087.pdf
//
// This originally started out with me experimenting with sorting algorithms,
// and I thought that I had stumbled onto something new, but all I'd done was
// independently rediscover Powermerge (see link above)
//
// Here's a link to a StackOverflow answer I gave many years back some time
// after I'd found my version of the solution:
// https://stackoverflow.com/a/68603446/16534062
//
// Still, Powermerge has a number of glaring flaws, which I suspect is why
// it hasn't been widely adopted, and the world has more or less coalesced
// around Block Sort and its variants like GrailSort, and so on.  Its biggest
// issue is that recursion stack depth is unbounded, and it's rather easy to
// construct degenerate scenarios where the call stack will overflow in short
// order.
//
// I worked to solve those issues, but the code grew in complexity, and then
// started to slow down to point of losing all its benefits.  While messing
// about with solutions, I created what I call SplitMergeInPlace().  To date
// I've not found an algorithm that implements exactly what it does, but it
// does have a number of strong similarities to what BlockSort does.
//
// Unlike ShiftMerge(), SplitMerge() doesn't bury itself in the details of
// finding the precise optimal place to split a block being merged, but rather
// uses a simple division algorithm to choose where to split.  In essence it
// takes a "divide and conquer" approach to the problem of merging two arrays
// together in place, and deposits fixed sized chunks, saves where that chunk
// is on a work stack, and then continues depositing chunks.  When all chunks
// are placed, it goes back and splits each one up again in turn into smaller
// chunks, and continues.
//
// In doing so, it achieves a stack requirement of 16*log16(N) split points,
// where N is the size of the left side array being merged.  The size of the
// right-side array doesn't matter to the SplitMerge algorithm.  This stack
// growth is very slow.  A stack size of 160 can account for over 10^12 items,
// and a stack size of 240 can track over 10^18 items.
//
// SplitMerge() is about 30% slower than ShiftMerge() in practise though,
// but it makes for an excellent fallback to the faster ShiftMerge()
// algorithm for when ShiftMerge() gets lost in the weeds of chopping up
// chunks and runs its work stack out of memory.
//
// I then read about how GrailSort and BlockSort use unique items as a work
// space, which is what allows those algorithms to achieve sort stability.  I
// didn't look too deeply into how either of those algorithms extract unique
// items, preferring the challenge of coming up with my own solution to that
// problem.  extract_uniques() is my solution that also takes a divide and
// conquer approach to split an array of items into uniques and duplicates,
// and then uses a variant of the Gries-Mills Block Swap algorithm to quickly
// move runs of duplicates into place:
//
// Ref: https://en.wikipedia.org/wiki/Block_swap_algorithms
//
// extract_uniques() moves all duplicates, which are kept in sorted order, to
// the left side of the main array, which creates a sorted block that can be
// merged in at the end.  When enough unique items are gathered, they are then
// used as the scratch work-space to invoke the adaptive merge sort in place
// algorithm to efficiently sort that which remains.

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include "forsort.h"


//				TUNING KNOBS!
//
// INSERT_SORT_MAX defines the number of items below which we'll resort to
// simply using Insertion Sort.  Anything from 8-30 seems reasonable, with
// values around 20+ giving best speeds at the expense of more swaps/compares
// Drop this to 8 if you want to minimise comparisons, but the overall
// algorithm will run a bit slower if you do so.
#define	INSERT_SORT_MAX		10

#define	BASIC_INSERT_MAX	32

// For shift_merge_in_place(), 1 work stack position holds 3 pointers (24
// bytes on 64-bit machines). A stack size of 80 requires a hair under 4K on
// the call stack.  I choose 160 (~8K) as this appears to cover all but the
// most degenerate of scenarios up to 10^12 items.  It will always fall back
// to the memory bounded split_merge_in_place() algorithm though as needed.
// If stack is super tight, this can be dropped to 40 without issue.  If
// stack memory is even tighter, just use split_merge_in_place() instead.
#define	SHIFT_STACK_SIZE	160

// SKEW defines the split ratio when doing top-down division of the array
// A SKEW of 50 is a classic merge sort 50:50 split, which would be better
// for larger element sizes, an expensive comparison function, for highly
// ordered inputs, or for low available stack memory deployments.
// A very mild skew of 47:53 appears to help the CPU branch predictor just
// enough to give a small boost for a small (~0.1%) increase in comparisons
#define	MERGE_SKEW		50

// While shift_merge_in_place and split_merge_in_place can definitely merge
// any two sorted arrays together in linear O(M+N) time, experimentally there
// is an observable performance bias to be had when the first array, M, is
// appreciably smaller than the second array, N.  While the total number of
// comparisons and swaps are not affected significantly, a roughly 1:4 ratio
// is observed to perform about 5-10% better than a 1:1 ratio.  Since the
// stable merge-in-place algorithm relies heavily on this basic sort to form
// its initial working sets, it's best that this skew ratio is managed
// independently from the main merge-sort skew.  Experimentally, a 20:80
// split appears to offer the best overall performance.
#define	BASIC_SKEW		20

// WSRATIO defines the split ratio when choosing how much of the array to
// use as a makeshift workspace when no workspace is provided
// Experimentally anything from 3-20 works okay, but 9 appears optimal
// Using 3 would mirror a closest approximation of classic merge sort
#define	WSRATIO			9

// STABLE_WSRATIO controls the behaviour of the stable sorting "front end" to
// the main algorithm.  It has to dig out unique values from the sort space
// to use as a workspace for the main algorithm.  Since doing so isn't "free"
// there's a trade-off between spending more time digging out uniques, as
// opposed to just using what we can find.  A good value appears to be anywhere
// from 1.5x to 3x of what WSRATIO is set to,
// 17 to 18 appears near optimal
#define	STABLE_WSRATIO		24

// WSTRIES is the maximum number of attempts that the stable_sort() front-end
// will try to attempt to achieve a suitably sized workspace to pass to the
// in-place merge sort.  The interesting thing though is that the uniques
// extraction system can wind up sorting the entire input in degenerate cases,
// and it will do it very quickly too!
#define	WSTRIES			24

// Set the following to 1 to enable low-stack mode, whereby we will not use
// shift_merge_in_place(), and ONLY use split_merge_in_place algorithm.  This
// will also use the bottom up merge implementation.  An average this is about
// a 4% speed penalty, which admittedly isn't a whole lot
#define	LOW_STACK		0

// Sparingly used to guide compiling optimization
#define likely(x)	__builtin_expect(!!(x), 1)
#define unlikely(x)	__builtin_expect(!!(x), 0)

// Handy defines to keep code looking cleaner
#define	COMMON_ARGS	es, swaptype, is_lt
#define	COMMON_PARAMS	const size_t es, int swaptype, int (*is_lt)(const void *, const void *)

// Construct a 128-bit type
typedef struct {
	uint64_t	a;
	uint64_t	b;
} xb16_t;

enum swap_type_t {
	SWAP_WORDS_128 = 0,
	SWAP_WORDS_64,
	SWAP_WORDS_32,
	SWAP_BYTES
};


static enum swap_type_t
get_swap_type (void *const pbase, size_t size)
{
	if (((size & (sizeof (uint32_t) - 1)) == 0) && ((uintptr_t) pbase) % __alignof__ (uint32_t) == 0) {
		if (size == sizeof (uint32_t)) {
			return SWAP_WORDS_32;
		} else if (size == sizeof (uint64_t) && ((uintptr_t) pbase) % __alignof__ (uint64_t) == 0) {
			return SWAP_WORDS_64;
		} else if (size == sizeof (xb16_t) && ((uintptr_t) pbase) % __alignof__ (xb16_t) == 0) {
			return SWAP_WORDS_128;
		}
	}
	return SWAP_BYTES;
} // get_swap_type


// The get index of the most significant bit of a 64 bit value
static int
msb64(uint64_t v)
{
	static const uint64_t dbm64 = (uint64_t)0x03f79d71b4cb0a89ULL;
	static const uint8_t dbi64[64] = {
		 0, 47,  1, 56, 48, 27,  2, 60, 57, 49, 41, 37, 28, 16,  3, 61,
		54, 58, 35, 52, 50, 42, 21, 44, 38, 32, 29, 23, 17, 11,  4, 62,
		46, 55, 26, 59, 40, 36, 15, 53, 34, 51, 20, 43, 31, 22, 10, 45,
		25, 39, 14, 33, 19, 30,  9, 24, 13, 18,  8, 12,  7,  6,  5, 63
	};

	if (!v)
		return -1;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v |= v >> 32;
	return dbi64[(v * dbm64) >> 58];
}

#if 0
static int
msb32(uint32_t v)
{
	static const uint32_t dbm32 = (uint32_t)0x07C4ACDDUL;
	static const uint8_t dbi32[32] = {
		0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30,
		8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31
	};

	if (!v)
		return -1;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	return dbi32[(v * dbm32) >> 27];
}

// A relatively quick integer square root estimator.  Borrowed
// from here: https://stackoverflow.com/a/31120562/16534062
static size_t
isqrt(size_t val) {
	size_t temp, g=0, b = 0x8000, bshft = 15;
	do {
		if (val >= (temp = (((g << 1) + b) << bshft--))) {
			g += b;
			val -= temp;
		}
	} while (b >>= 1);
	return g;
} // isqrt


static inline size_t
ceil_log_base_16(size_t n)
{
	size_t	result = 0;

	for ( ; n ; n >>= 4, result++);

	return (result + !result);	// Don't return a 0
} // ceil_log_base_16
#endif

extern void print_array(void *a, size_t n);

#define ES 1
#define	NITEM(_x_)		(_x_)
#define	VAR xb16_t
#include "forsort-macro.h"
#undef VAR
#undef NITEM
#undef ES

#define ES 1
#define	NITEM(_x_)		(_x_)
#define	VAR uint64_t
#include "forsort-macro.h"
#undef VAR
#undef NITEM
#undef ES

#define ES 1
#define	NITEM(_x_)		(_x_)
#define	VAR uint32_t
#include "forsort-macro.h"
#undef VAR
#undef NITEM
#undef ES

#define ES es
#define	NITEM(_x_)		((_x_) / es)
#define	VAR char
#define UNTYPED
#include "forsort-macro.h"
#undef UNTYPED
#undef VAR
#undef NITEM
#undef ES

void	    
forsort_basic(void *a, const size_t n, const size_t es,
	int (*is_lt)(const void *, const void *))
{	       
	int     swaptype = get_swap_type(a, es);
	
	if (swaptype == SWAP_WORDS_64) {
		basic_top_down_sort_uint64_t((uint64_t *)a, n, COMMON_ARGS);
	} else if (swaptype == SWAP_WORDS_32) {
		basic_top_down_sort_uint32_t((uint32_t *)a, n, COMMON_ARGS);
	} else if (swaptype == SWAP_WORDS_128) {
		basic_top_down_sort_xb16_t((xb16_t *)a, n, COMMON_ARGS);
	} else {
		basic_top_down_sort_char((char *)a, n, COMMON_ARGS);
	}
} // forsort_basic
	
		
void	    
forsort_stable(void *a, const size_t n, const size_t es,
	int (*is_lt)(const void *, const void *))
{       
	int     swaptype = get_swap_type(a, es);
		
	if (swaptype == SWAP_WORDS_64) {
		stable_sort_uint64_t((uint64_t *)a, n, COMMON_ARGS);
	} else if (swaptype == SWAP_WORDS_32) {
		stable_sort_uint32_t((uint32_t *)a, n, COMMON_ARGS);
	} else if (swaptype == SWAP_WORDS_128) {
		stable_sort_xb16_t((xb16_t *)a, n, COMMON_ARGS);
	} else {
		stable_sort_char((char *)a, n, COMMON_ARGS);
	}
} // forsort_simple     
			

void		    
forsort_inplace(void *a, const size_t n, const size_t es,
	int (*is_lt)(const void *, const void *),
	void *workspace, size_t worksize)
{
	int     swaptype = get_swap_type(a, es);
	int	dynamic = 0;

	if ((workspace == NULL) && (worksize == 1))
		dynamic = 1;

	if (dynamic) {
		// Allocate a workspace that is 1/8 of the total array size
		worksize = (n * es) / 8;
		workspace = malloc(worksize);
	}

	if (swaptype == SWAP_WORDS_64) {
		merge_sort_in_place_uint64_t((uint64_t *)a, n, (uint64_t *)workspace, worksize / es, COMMON_ARGS);
	} else if (swaptype == SWAP_WORDS_32) {
		merge_sort_in_place_uint32_t((uint32_t *)a, n, (uint32_t *)workspace, worksize / es, COMMON_ARGS);
	} else if (swaptype == SWAP_WORDS_128) {
		merge_sort_in_place_xb16_t((xb16_t *)a, n, (xb16_t *)workspace, worksize / es, COMMON_ARGS);
	} else {
		merge_sort_in_place_char((char *)a, n, (char *)workspace, worksize / es, COMMON_ARGS);
	}

	if (dynamic && (workspace != NULL))
		free(workspace);
} // forsort_inplace
