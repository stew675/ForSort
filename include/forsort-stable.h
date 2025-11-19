//                              FORSORT
//
// Author: Stew Forster (stew675@gmail.com)     Copyright (C) 2021-2025
//
// This is my implementation of what I believe to be an O(nlogn) time-complexity
// O(logn) space-complexity, in-place and adaptive merge-sort style algorithm.

#define CONCAT(x, y) x ## _ ## y
#define MAKE_STR(x, y) CONCAT(x,y)
#define NAME(x) MAKE_STR(x, VAR)
#define CALL(x) NAME(x)

//-----------------------------------------------------------------
//                         SWAP macros
//-----------------------------------------------------------------

#ifdef UNTYPED

#define	SWAP(_xa_, _xb_)	memswap((_xa_), (_xb_), ES)

#else

#define	SWAP(_xa_, _xb_)			\
	{					\
		VAR xa = *(VAR *)(_xa_);	\
		VAR xb = *(VAR *)(_xb_);	\
		*(VAR *)(_xb_) = xa;		\
		*(VAR *)(_xa_) = xb;		\
	}

#endif

//-----------------------------------------------------------------
//            Start of stable_sort() implementation
//-----------------------------------------------------------------

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

// Since the merge_duplicates algorithm uses a 1:2 split ratio, it's best to
// have MAX_DUPS be an even power of 3, so a value of 27 is perfect here.
// With a MAX_DUPS value of 27, if the data set is so degenerate as to fill up
// the duplicates table, then dropping out and sorting is trivially fast
#define MAX_DUPS 27

// Uncomment to turn on debugging output for the uniques extraction and merging system
//#define       DEBUG_UNIQUE_PROCESSING

// A structure to manage the state of the stable sort algorithm
struct NAME(stable_state) {
	// All sizes are in numbers of entries, not bytes
	VAR	*merged_dups[MAX_DUPS];		// Merged up duplicates
	VAR	*free_dups[MAX_DUPS];		// Unmerged duplicates
	VAR	*work_space;			// Work Space
	VAR	*rest;				// Rest of the main array
	VAR	*pe;				// End of main array
	size_t	num_merged;			// No. of merged duplicate entries
	size_t	num_free;			// No. of unmerged duplicate entries
	size_t	work_size;			// Size of work space
	size_t	rest_size;			// Size of the rest
	bool	work_sorted;			// If work-space is sorted or not
};

// Designed for efficiently processing smallish sets of items
// Note that the last item is always guaranteed to be unique
//
// Returns a pointer to the list of unique items positioned
// to the right-side of the array.  All duplicates are located
// at the start (left-side) of the array (A)
//  A -> PU = Duplicates
// PU -> PE = Unique items
static VAR *
NAME(extract_unique_sub)(VAR * const a, VAR * const pe, VAR *ph, COMMON_PARAMS)
{
	VAR	*pu = a;	// Points to list of unique items

	// Sanitize our hints pointer
	if (ph == NULL)
		ph = pe;

	// Process everything up to the hints pointer
	for (VAR *pa = a + ES; pa < ph; pa += ES) {
		if (IS_LT(pa - ES, pa))
			continue;

		// The item before our position is a duplicate.  Mark it.
		VAR *dp = pa - ES;

		// Now find the end of the run of duplicates
		for (pa += ES; (pa < ph) && !IS_LT(pa - ES, pa); pa += ES);
		pa -= ES;

		// pa now points at the last item of the duplicate run
		// Roll the duplicates down
		if ((pa - dp) > ES) {
			// Multiple duplicates. block_rotate them into position
			if (dp > pu)
				CALL(block_rotate)(pu, dp, pa, es);
			pu += (pa - dp);
		} else {
			// Single item, just bubble it down
			while (dp > pu) {
				SWAP(dp, dp - ES);
				dp -= ES;
			}
			pu += ES;
		}
		pa += ES;
	}

	if (ph < pe) {
		// Everything (ph - es) to (pe - es) is a duplicate
		CALL(block_rotate)(pu, ph - ES, pe - ES, es);
		pu += (pe - ph);
	}

	return pu;
} // extract_unique_sub


// Returns a pointer to the list of unique items positioned
// to the right-side of the array.  All duplicates are located
// at the start (left-side) of the array (A)
//  A -> PU = Duplicates
// PU -> PE = Unique items
//
// Assumptions:
// - The list we're passed is already sorted
static VAR *
NAME(extract_uniques)(VAR * const a, const size_t n, VAR *hints, COMMON_PARAMS)
{
	VAR	*pe = a + (n * ES);

	// I'm not sure what a good value should be here, but 40 seems okay
	if (n < 40)
		return CALL(extract_unique_sub)(a, pe, hints, COMMON_ARGS);

	if (hints == NULL)
		hints = pe;

	// Divide and conquer!  This algorithm appears to operate in close
	// to an O(n) time complexity, albeit with a moderately high K factor
	VAR	*pa = a;
	size_t	na = (n + 3) >> 2;	// Looks to be about right
	VAR	*pb = pa + (na * ES);
	VAR	*ps = pb;	// Records original intended split point

	// First find where to split at, which basically means, find the
	// end of any duplicate run that we may find ourselves in
	while ((pb < pe) && !IS_LT(pb - ES, pb))
		pb += ES;

	// If we couldn't find a sub-split, just process what we have
	if (pb == pe)
		return CALL(extract_unique_sub)(a, pe, ps, COMMON_ARGS);

	// Recalculate our size
	na = NITEM(pb - pa);
	size_t	nb = n - na;

	if (hints < pb)
		hints = pe;

	// Note that there is ALWAYS at least one unique to be found
	VAR	*apu = CALL(extract_uniques)(pa, na, ps, COMMON_ARGS);
	VAR	*bpu = CALL(extract_uniques)(pb, nb, hints, COMMON_ARGS);

	// Coalesce non-uniques together
	if (bpu > pb) {
		CALL(block_rotate)(apu, pb, bpu, es);
	}
	pb = apu + (bpu - pb);

	// PA->BP now contains non-uniques and BP->PE are uniques
	return pb;
} // extract_uniques


// Takes a list of pointers to blocks, and merges them together using a 1:2
// merge ratio.  pe points after the end of the last block on the list
static VAR *
NAME(merge_duplicates)(struct NAME(stable_state) *state, VAR **list, size_t n, VAR *pe, COMMON_PARAMS)
{
	if (n == 1)
		return list[0];

	size_t	n1 = (n + 1) / 3;
	size_t	n2 = n - n1;

	VAR	*m1 = CALL(merge_duplicates)(state, list, n1, list[n1], COMMON_ARGS);
	VAR	*m2 = CALL(merge_duplicates)(state, list + n1, n2, pe, COMMON_ARGS);

	size_t	nm1 = NITEM(m2 - m1);	// Number of items in m1
	size_t	nm2 = NITEM(pe - m2);	// Number of items in m2

	VAR	*ws = state->work_space;
	size_t	nw = state->work_size;

#ifdef	DEBUG_UNIQUE_PROCESSING
	printf("Merging %lu with %lu\n", nm1, nm2);
#endif
	if (nm1 > (nw * WSRATIO)) {
		// Use in-place merging
#if LOW_STACK
		CALL(split_merge_in_place)(m1, m2, pe, COMMON_ARGS);
#else
		CALL(shift_merge_in_place)(m1, m2, pe, COMMON_ARGS);
#endif
	} else {
		// Do a faster work-space based merge
		CALL(merge_workspace_constrained)(m1, nm1, m2, nm2, ws, nw, COMMON_ARGS);
		state->work_sorted = false;
	}

	return m1;
} // merge_duplicates


// Maintains the set of duplicate entries.  When a duplicate entry is added
// to the free list, it checks against the length of the merged list.
// This two stage system means that for 2 * MAX_DUPS entries of space,
// we can actually maintain MAX_DUPS^2 worth of duplicate entries.  This then
// means we can collate a lot of duplicates for a small (fixed) overhead
static void
NAME(add_duplicate)(struct NAME(stable_state) *state, VAR *new_dup, COMMON_PARAMS)
{
	state->free_dups[state->num_free++] = new_dup;
	if (state->num_free < MAX_DUPS)
		return;

	VAR	**list = state->free_dups;
	size_t	n = state->num_free;
	VAR	*ws = state->work_space;

	// Merge up the free duplicates
	VAR	*mf = CALL(merge_duplicates)(state, list, n, ws, COMMON_ARGS);

	state->merged_dups[state->num_merged++] = mf;
	state->free_dups[0] = NULL;
	state->num_free = 0;
} // add_duplicate


static void
NAME(stable_sort_finisher)(struct NAME(stable_state) *state, COMMON_PARAMS)
{
	VAR	*ws = state->work_space;
	size_t	nw = state->work_size;

#ifdef	DEBUG_UNIQUE_PROCESSING
	printf("Num Merged = %lu, Num Free = %lu\n", state->num_merged, state->num_free);
#endif
	// Merge up the free duplicates
	if (state->num_free > 0) {
		VAR	**list = state->free_dups;
		size_t	n = state->num_free;
		VAR	*mf = CALL(merge_duplicates)(state, list, n, ws, COMMON_ARGS);

		// If merged dups is full, there will never be any unmerged frees
		// If there are unmerged frees, then merged dups won't be full.
		// Therefore, the following operation is perfectly bounded
		ASSERT(state->num_merged < MAX_DUPS);
		state->merged_dups[state->num_merged++] = mf;
		state->free_dups[0] = NULL;
		state->num_free = 0;
	}

	// Merge up the merged duplicates
	VAR	*md = NULL;
	if (state->num_merged > 0) {
		VAR	**list = state->merged_dups;
		size_t	n = state->num_merged;

		md = CALL(merge_duplicates)(state, list, n, ws, COMMON_ARGS);
	}

	// Sort our workspace now (if it's required)
	if (state->work_sorted == false)
		CALL(merge_sort_in_place)(ws, nw, NULL, 0, COMMON_ARGS);

	// Now we have the following chunks
	// md - A potentially very lerge chunk of merged and sorted duplicates
	// work_space - Our work-space of unique values, which is sorted
	// rest - The sorted rest of the input

	VAR	*pr = state->rest;
	VAR	*pe = state->pe;
	size_t	nm = 0;

	if (md)
		nm = NITEM(ws - md);

#ifdef	DEBUG_UNIQUE_PROCESSING
	printf("md = %p, ws = %p, pr = %p\n", md, ws, pr);
	printf("nm = %lu, nw = %lu, nr = %lu\n", nm, nw, state->rest_size);
#endif

#if LOW_STACK
	if ((nm > 0) && (nm < nw)) {
		CALL(split_merge_in_place)(md, ws, pr, COMMON_ARGS);
		CALL(split_merge_in_place)(md, pr, pe, COMMON_ARGS);
	} else {
		CALL(split_merge_in_place)(ws, pr, pe, COMMON_ARGS);
		if (nm > 0)
			CALL(split_merge_in_place)(md, ws, pe, COMMON_ARGS);
	}
#else
	if ((nm > 0) && (nm < nw)) {
		CALL(shift_merge_in_place)(md, ws, pr, COMMON_ARGS);
		CALL(shift_merge_in_place)(md, pr, pe, COMMON_ARGS);
	} else {
		CALL(shift_merge_in_place)(ws, pr, pe, COMMON_ARGS);
		if (nm > 0)
			CALL(shift_merge_in_place)(md, ws, pe, COMMON_ARGS);
	}
#endif
	// and....we're done!
} // stable_sort_finisher


// This essentially operates as a "front end" to the main shift-merge-sort
// sequence.  Its primary role is to extract unique values from the main
// data set, which in turn allows us to use these as a workspace to pass
// to the main algorithm.  Doing so preserves sort stability.  While it is
// generating the set of uniques, it is also still sorting by generating a
// sorted set of duplicates that were disqualified.  There exists certain
// inputs where we can sort the entire set just through doing this alone!
static void
NAME(stable_sort)(VAR * const pa, const size_t n, COMMON_PARAMS)
{
	struct NAME(stable_state )state_real = {0}, *state = &state_real;
	VAR	*pe = pa + (n * ES), *ws, *pr;
	size_t	nr, nw;

#ifdef	DEBUG_UNIQUE_PROCESSING
	printf("size of stable state processing structure = %lu bytes\n",
			sizeof(struct NAME(stable_state)));
#endif
	// 75 items appears to be about the cross-over between using only
	// basic_sort(), and going on to use the main stable_sort() sequence
	if (n < 75)
		return (void)(CALL(basic_sort)(pa, n, COMMON_ARGS));

	// We start with a workspace candidate size that is intentionally
	// small, as we need to use the slower basic_sort() algorithm to
	// kick start the process.  The idea here is to then use the
	// initial unique values that we extract to drive use of the
	// merge-sort algorithm, to help us find more uniques faster!
	nw = (n >> 7) + STABLE_WSRATIO;
	if (nw > (n >> 2))	// Cap work-space size to 1/4 of n
		nw = n >> 2;
	nr = n - nw;
	pr = pa + (nw * ES);	// Pointer to rest

	// Determine how much workspace we're really aiming for
	size_t	wstarget = nr / STABLE_WSRATIO;

	// First sort our candidate work-space chunk
	size_t reversals = CALL(basic_sort)(pa, nw, COMMON_ARGS);

	// Check if it looks like the input may benefit from a reversal
	if ((nw - reversals) <= (nw >> 5)) {
#ifdef	DEBUG_UNIQUE_PROCESSING
		printf("stable_sort() - Input is likely reversed: nw = %lu, "
		       "reversals = %lu\n", nw, reversals);
#endif
		CALL(dereverse)(pr, nr, COMMON_ARGS);
	} else if (reversals == 0) {
		// Check if entire input wasn't already fully sorted
		reversals = CALL(dereverse)(pr - ES, nr + 1, COMMON_ARGS);
		if (reversals == 0) {
#ifdef	DEBUG_UNIQUE_PROCESSING
			printf("stable_sort() - Input was fully sorted\n");
#endif
			return;
		}
	}

	// Now pull out our first set of unique values
	ws = CALL(extract_uniques)(pa, nw, NULL, COMMON_ARGS);

	// Recalculate size of work_space after duplicates were extracted
	nw = NITEM(pr - ws);

	// Initialise state structure
	state->work_space = ws;
	state->work_size = nw;
	state->work_sorted = true;
	state->rest = pr;
	state->rest_size = nr;
	state->pe = pe;

	// PA->WS is pointing at (sorted) non-uniques
	// WS->PR is a set of uniques we can use as workspace
	// PR->PE is everything else that we still need to sort

	// If there were duplicates (PA->WS), then add them to the list
	// If the first set of duplicates is very large, just add it
	// directly to the set of merged duplicates.
	if ((ws - pa) > (pr - ws)) {
		state->merged_dups[0] = pa;
		state->num_merged = 1;
	} else if (ws > pa) {
		state->free_dups[0] = pa;
		state->num_free = 1;
	}

	// If we couldn't find enough work-space we'll keep trying until our
	// duplicate management storage fills up. Despite this seeming excessive,
	// with each try we're still sorting more of the array any way, so in
	// the end it all balances out.  Swings and roundabouts :)
	while ((nw < wstarget) && (state->num_merged < MAX_DUPS)) {
		// It can be fun to activate the following printf and watch
		// the unique extractor do its thing with increasingly
		// degenerate inputs.  It's possible for stable_sort() to
		// completely sort the input in this extraction phase alone!
#ifdef	DEBUG_UNIQUE_PROCESSING
		printf("Not enough workspace. Wanted: %ld  Got: %ld  "
		       "Duplicates: %ld, Remaining Items = %lu\n",
		       wstarget, nw, NITEM(ws - pa), nr);
#endif
		// Estimate how much of the remaining that we need to grab
		// to get enough uniques to satsify our minimum.  First work
		// out what the current ratio of uniques is
		size_t	nd = NITEM(ws - pa);	// Num Duplicates
		double	ratio = nw;
		ratio /= (nw + nd);		// Ratio of uniques
		size_t	grab = wstarget - nw;	// How much we're short by
		grab = grab / ratio;		// Estimate of how much to grab
		grab = (grab * 9) >> 3;		// Add a fudge factor of 1/8th

		// Don't grab less than 1/32th. This is to avoid creeping up to
		// the target too slowly as we get close to it
		if (grab < (nr >> 5))
			grab = nr >> 5;

		// Don't grab more than we can efficiently sort though
		if (grab > (nw * STABLE_WSRATIO))
			grab = nw * STABLE_WSRATIO;

		// Also don't grab more than 1/8th of what's remaining.  We only
		// want to be doing this for as long as we absolutely need to be
		if (grab > (nr >> 3))
			grab = nr >> 3;

		// Section off the new workspace candidates from the rest
		VAR	*nws = pr;	// New workspace candidates
		nr -= grab;
		pr = pr + (grab * ES);

		// Update state with new rest of array changes
		state->rest = pr;
		state->rest_size = nr;

		// Determine how much work-space to use for sorting.  Doing so
		// means we need to sort less of it afterwards, and saves time
		size_t tnw = grab / STABLE_WSRATIO;

		// Sort new work-space candidates using our current workspace
		CALL(merge_sort_in_place)(nws, grab, ws, tnw, COMMON_ARGS);

		// Our current work-space is now jumbled, so sort just
		// the portion that was used to sort the candidates
		CALL(merge_sort_in_place)(ws, tnw, NULL, 0, COMMON_ARGS);
		state->work_sorted = true;

		// Merge current workspace with the new workspace candidates
		// We cannot use the faster merge algorithm here or we will
		// end up breaking sort stability.
#if LOW_STACK
		CALL(split_merge_in_place)(ws, nws, pr, COMMON_ARGS);
#else
		CALL(shift_merge_in_place)(ws, nws, pr, COMMON_ARGS);
#endif

		// We may have picked up new duplicates.  Separate them out
		nws = ws;
		ws = CALL(extract_uniques)(ws, nw + grab, NULL, COMMON_ARGS);
		nw = NITEM(pr - ws);

		// Update stable state with new work-space changes
		state->work_space = ws;
		state->work_size = nw;

		// Append any new duplicates to the lists of duplicates.
		if (ws > nws)
			CALL(add_duplicate)(state, nws, COMMON_ARGS);

		// Recalculate the new work-space size target.  If it's just
		// trivial amounts of unsorted data left, then just leave!
		// This avoids an overly degenerate merging scenario later
		if (nr < (n >> 4))
			break;

		wstarget = nr / STABLE_WSRATIO;

		// Short-circuit the search if we have even just barely enough!
		// The merge sort can run at near full speed with just 1/128th
		// as work-space, and so it's faster to just break out if we're
		// close enough, than it is to continue searching for more.
		if ((nr < ((n * 3)>>2)) && (nw >= (nr >> 7)))
			break;
	}

	// Now sort the remaining unsorted data

	// Here we will bypass the wstarget so long as nw > nr/128.  The work
	// space based merge algorithm will still outpace the in-place merge
	// even when given that reduced amount.  wstarget acted more as an ideal
	if ((nw < wstarget) && (nw < (nr >> 7))) {
		// Give up and fall back to good old basic_sort().  If the input
		// data is THAT degenerate, then basic_sort is very fast anyway
		CALL(basic_sort)(pr, nr, COMMON_ARGS);
	} else {
		// Sort the remainder using the workspace we extracted
		CALL(merge_sort_in_place)(pr, nr, ws, nw, COMMON_ARGS);
		state->work_sorted = false;
	}

	// Now do the final merge up!
	CALL(stable_sort_finisher)(state, COMMON_ARGS);
} // stable_sort

//-----------------------------------------------------------------
//                      #DEF  cleanup!
//-----------------------------------------------------------------

#ifdef DEBUG_UNIQUE_PROCESSING
#undef DEBUG_UNIQUE_PROCESSING
#endif

#undef MAX_DUPS
#undef SWAP
#undef CONCAT
#undef MAKE_STR
#undef NAME
#undef CALL
#pragma GCC diagnostic pop
