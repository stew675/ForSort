//                              FORSORT
//
// Author: Stew Forster (stew675@gmail.com)     Copyright (C) 2021-2025
//
// This is my implementation of what I believe to be an O(nlogn) time-complexity
// O(logn) space-complexity, in-place and adaptive merge-sort style algorithm.


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

#define CONCAT(x, y) x ## _ ## y
#define MAKE_STR(x, y) CONCAT(x,y)
#define NAME(x) MAKE_STR(x, VAR)
#define CALL(x) NAME(x)

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
//                Start of merge_sort() code
//-----------------------------------------------------------------

// Experimentally, 7 appears best as the sprint activation value
#define SPRINT_ACTIVATE         7
#define SPRINT_EXIT_PENALTY     2

static void
NAME(single_up)(VAR *pa, VAR *pe, size_t es)
{
        VAR  *pb = pa + ES;

        while (pb < pe) {
                SWAP(pa, pb);
                pa = pb;
                pb += ES;
        }
}


static void
NAME(single_down)(VAR *pa, VAR *pe, size_t es)
{
        VAR  *pb = pa - ES;

        while (pa > pe) {
                SWAP(pa, pb);
                pa = pb;
                pb -= ES;
        }
}


static void
NAME(reverse_rotate)(VAR *pa, VAR *pb, VAR *pe, size_t es)
{
#if 1
	size_t  na = NITEM(pb - pa), nb = NITEM(pe - pb);

	if (na == nb)
		return CALL(swap_block)(pa, pb, pb, es);

	if (na > nb) {
		CALL(reverse_block)(pa, pb, es);
		CALL(reverse_block)(pa + nb, pb, es);
		CALL(reverse_block)(pa, pa + nb, es);
		CALL(swap_block)(pa, pa + nb, pb, es);
	} else {
		CALL(reverse_block)(pb, pe, es);
		CALL(reverse_block)(pe - na, pe, es);
		CALL(reverse_block)(pb, pe - na, es);
		CALL(swap_block)(pa, pb, pe - na, es);
	}
#else
	CALL(reverse_block)(pa, pb, es);
	CALL(reverse_block)(pb, pe, es);
	CALL(reverse_block)(pa, pe, es);
#endif
} // reverse_rotate


// I looked at shift_merge_in_place() and though that a block rotate should
// look just like that, just without the comparisons.  This is that.
// In concept it's basically Gries-Mills, just expressed differently
static void
NAME(rotate_block)(VAR *pa, VAR *pb, VAR *pe, size_t es)
{
	size_t  na = NITEM(pb - pa), nb = NITEM(pe - pb);

	// Handle empty list possibilities
	if (!na || !nb)
		return;

	// Triple reverse faster for small sets
	if ((na <= 16) && (nb <= 128))
		return CALL(reverse_rotate)(pa, pb, pe, es);

	if ((nb <= 16) && (na <= 128))
		return CALL(reverse_rotate)(pa, pb, pe, es);

	for (;;) {
		// Roll all of PA->PB up as far as we can until it doesn't fit
		if (na < 2) {
			if (na == 1)
				CALL(single_up)(pa, pb + (nb * ES), es);
			return;
		}

		while (na <= nb) {
			CALL(swap_block)(pa, pb, pb, es);
			pa = pb;
			pb += (na * ES);
			nb -= na;
		}

		// Okay, so what's in A doesn't fit.  Swap a B sized
		// portion at the end of A, with B, and reloop
		if (nb < 2) {
			if (nb == 1)
				CALL(single_down)(pb, pa, es);
			return;
		}

		while (nb <= na) {
			VAR  *sp = pb - (nb * ES);
			CALL(swap_block)(sp, pb, pb, es);
			pb = sp;
			na -= nb;
		}
	}
} // rotate_block


// Giving credit where it's due.  All this sprint-left/right, merge-left/right
// stuff is heavily influenced by TimSort.  I'd already implemented something
// similar, but when I looked at TimSort code I saw a few extra good ideas and
// brought them in.  Basically where you see sprinting, that's very similar to
// TimSort's galloping
//
// We're looking for leftmost element within pa->pe that is greater than, or
// equal to, what pt is pointing at
static VAR *
NAME(sprint_left)(VAR *pa, VAR *pe, VAR *pt, int direction, COMMON_PARAMS)
{
	size_t	max = NITEM(pe - pa);
	size_t	min = 0, pos;
	VAR	*sp;

	if (direction == LEAP_LEFT) {
		// First leap-frog our way to find our search range
		// Here we're scanning backwards from PE
		for (pos = 0; pos < max; pos = (pos << 1) + 1) {
			sp = pe - ((pos + 1) * ES);
			if (IS_LT(sp, pt))
				break;
		}

		// Setup min and max, relative to PE, unless if pos
		// exceeded max, in which case choosing pos/2 is best
		if (pos > max) {
			max = pos >> 1;
		} else {
			min = max - pos;
			max = min + (pos >> 1);
		}
	} else {
		// First leap-frog our way to find the search range
		for (pos = 0; pos < max; pos = (pos << 1) + 1) {
			sp = pa + (pos * ES);
			if (!IS_LT(sp, pt))
				break;
		}

		// Now adjust our min and max, to keep them within limits
		// as well as ensure 2^n-1 elements is the range that
		// we will be searching against
		if (pos > max) {
			min = max - (pos >> 1);
		} else {
			// The !!pos prevents an increment when pos == 0
			// otherwise we could end up with min > max
			min = (pos >> 1) + !!pos;
			max = pos;
		}
	}

	pos = (min + max) >> 1;
	sp = pa + (pos * ES);
	while (min < max) {
		// The following 3 lines implement this logic
		// if (IS_LT(sp, pt))
		// 	min = pos + 1;
		// else
		// 	max = pos;
		int res = !!(IS_LT(sp, pt));
		max = (max * res) + (!res * pos++);
		min = (min * !res) + (res * pos);

		pos = (min + max) >> 1;
		sp = pa + (pos * ES);
	}
	return sp;
} // sprint_left


// We're looking for rightmost element within pa->pe that is 
// less than, or equal, to what pt is pointing at
static VAR *
NAME(sprint_right)(VAR *pa, VAR *pe, VAR *pt, int direction, COMMON_PARAMS)
{
	size_t	max = NITEM(pe - pa);
	size_t	min = 0, pos = 0;
	VAR	*sp;

	if (direction == LEAP_RIGHT) {
		// First leap-frog our way to find the search range
		for (pos = 0; pos < max; pos = (pos << 1) + 1) {
			sp = pa + (pos * ES);
			if (IS_LT(pt, sp))
				break;
		}

		// Now adjust our min and max, to keep them within limits
		// as well as ensure 2^n-1 elements is the range that
		// we will be searching against
		if (pos > max) {
			min = max - (pos >> 1);
		} else {
			// The !!pos prevents an increment when pos == 0
			// otherwise we could end up with min > max
			min = (pos >> 1) + !!pos;
			max = pos;
		}
	} else {
		// First leap-frog our way to find our search range
		// Here we're scanning backwards from PE
		for (pos = 0; pos < max; pos = (pos << 1) + 1) {
			sp = pe - ((pos + 1) * ES);
			if (!IS_LT(pt, sp))
				break;
		}

		// Setup min and max, relative to PE, unless if pos
		// exceeded max, in which case choosing pos/2 is best
		if (pos > max) {
			max = pos >> 1;
		} else {
			min = max - pos;
			max = min + (pos >> 1);
		}
	}

	pos = (min + max) >> 1;
	sp = pa + (pos * ES);
	while (min < max) {
		// The following 3 lines implement this logic
		// if (IS_LT(pt, sp))
		// 	max = pos;
		// else
		// 	min = pos + 1;
		int	res = !!(IS_LT(pt, sp));
		max = (max * !res) + (res * pos++);
		min = (min * res) + (!res * pos);

		pos = (min + max) >> 1;
		sp = pa + (pos * ES);
	}
	return sp;
} // sprint_right


static void
NAME(merge_left)(VAR *a, size_t na, VAR *b, size_t nb,
			  VAR *w, const size_t nw, COMMON_PARAMS)
{
	size_t	a_run = 0, b_run = 0, sprint = SPRINT_ACTIVATE;
	VAR	*pe = b + (nb * ES), *pw = w;
	VAR	*pb = pe, *pa = b;

	ASSERT(nb <= nw);

	// Now copy everything remaining from B to W
	for (VAR *tb = b; nb--; pw += ES, tb += ES)
		SWAP(pw, tb);

	// We already know the result of the first compare
	pa -= ES;
	pb -= ES;
	SWAP(pb, pa);

	// Now merge rest of W into A
	while ((pa > a) && (pw > w)) {
		if ((a_run | b_run) < sprint) {
			// The following 8 lines implement this logic
			// pb -= ES;
			// if (IS_LT(pw - ES, pa - ES)) {
			//	pa -= ES;
			//	SWAP(pb, pa);
			//	b_run = 0;
			//	a_run++;
			// } else {
			//	pw -= ES;
			//	SWAP(pb, pw);
			//	a_run = 0;
			//	b_run++;
			// }
			VAR	*which[2] = {(pw - ES), (pa - ES)};
			int	res = !!(IS_LT(pw - ES, pa - ES));
			pb = pb - ES;
			SWAP(pb, which[res]);
			pa = pa - (res * ES);
			pw = pw - (!res * ES);
			a_run = (a_run + res) * res;
			b_run = (b_run + !res) * !res;
			continue;
		}

		do {
			sprint -= !!(sprint > 2);

			// Stuff from A is sprinting
			if (a_run) {
				VAR *ta = CALL(sprint_right)(a, pa, pw - ES, LEAP_LEFT, COMMON_ARGS);
				a_run = NITEM(pa - ta);
				for (size_t num = a_run; num--; ) {
					pa -= ES;  pb -= ES;
					SWAP(pa, pb);
				}
				if (pa == a)
					goto merge_done;
				b_run += !b_run;
			}

			// Stuff from B/Workspace is sprinting
			if (b_run) {
				VAR *tw = CALL(sprint_left)(w, pw, pa - ES, LEAP_LEFT, COMMON_ARGS);
				b_run = NITEM(pw - tw);
				for (size_t num = b_run; num--; ) {
					pw -= ES;  pb -= ES;
					SWAP(pw, pb);
				}
				if (pw == w)
					goto merge_done;
				a_run += !a_run;
			}
		} while ((a_run >= SPRINT_ACTIVATE) || (b_run >= SPRINT_ACTIVATE));

		// Reset sprint mode
		sprint += SPRINT_EXIT_PENALTY;
		a_run = 0;
		b_run = 0;
	}
merge_done:
	// Swap back any remainder
	ASSERT(w <= pw);
	for ( ; w != pw; w += ES, a += ES)
		SWAP(a, w);
} // merge_left


static void
NAME(merge_right)(VAR *a, size_t na, VAR *b, size_t nb,
			  VAR *w, const size_t nw, COMMON_PARAMS)
{
	VAR	*pe = b + (nb * ES);
	VAR	*pw = w;

	ASSERT(na <= nw);

	// Now copy everything in A to W
	for (VAR *ta = a; na--; pw += ES, ta += ES)
		SWAP(pw, ta);

	// We already know that the first B is smaller, so swap it now
	SWAP(a, b);
	a += ES;
	b += ES;

	// Now merge rest of W into B. Set up sprint values
	size_t a_run = 0, b_run = 0, sprint = SPRINT_ACTIVATE;

	while ((b < pe) && (w < pw)) {
		if ((a_run | b_run) < sprint) {
			// The following 8 lines implement this logic
			// if(IS_LT(b, w)) {
			//	SWAP(a, b);
			//	b += ES;
			//	a_run = 0;
			//	b_run++;
			// } else {
			//	SWAP(a, w);
			//	w += ES;
			//	a_run++;
			//	b_run = 0;
			// }
			VAR	*which[2] = {w, b};
			int	res = !!(IS_LT(b, w));
			SWAP(a, which[res]);
			b += res * ES;
			w += !res * ES;
			a_run = (a_run + !res) * !res;
			b_run = (b_run + res) * res;
			a += ES;
			continue;
		}

		do {
			sprint -= !!(sprint > 2);

			// Stuff from A/workspace is sprinting
			VAR	*tw = CALL(sprint_right)(w, pw, b, LEAP_RIGHT, COMMON_ARGS);
			a_run = NITEM(tw - w);
			if (a_run) {
				for (size_t num = a_run; num--; w += ES, a += ES)
					SWAP(a, w);
				if (w >= pw)
					goto merge_done;
			}

			// Stuff from B is sprinting
			VAR	*tb = CALL(sprint_left)(b, pe, w, LEAP_RIGHT, COMMON_ARGS);
			b_run = NITEM(tb - b);
			if (b_run) {
				for (size_t num = b_run; num--; b += ES, a += ES)
					SWAP(a, b);
				if (b >= pe)
					goto merge_done;
			}
		} while ((a_run >= SPRINT_ACTIVATE) || (b_run >= SPRINT_ACTIVATE));

		// Reset sprint mode
		sprint += SPRINT_EXIT_PENALTY;
		a_run = 0;
		b_run = 0;
	}
merge_done:
	// Swap back any remainder
	ASSERT(w <= pw);
	for ( ; w != pw; w += ES, a += ES)
		SWAP(a, w);
} // merge_right


// Prepares A and B for merging via merge_left or merge_right
// Assumes both NA and NB are > zero on entry
static void
NAME(merge_using_workspace)(VAR *a, size_t na, VAR *b, size_t nb,
			  VAR *w, const size_t nw, COMMON_PARAMS)
{
	ASSERT(na > 0);
	ASSERT(nb > 0);

	// Check if we need to do anything at all!
	if (!IS_LT(b, b - ES))
		return;

	VAR	*pe = b + (nb * ES);

	// Skip initial part of A if the opportunity arises
	if (!IS_LT(b, a)) {
		if (na > 10) {
			size_t	min = 1, max = na;
			size_t	pos = max >> 1;
			VAR	*sp = a + (pos * ES);

			while (min < max) {
				// The following 3 lines implement this logic
				// if (IS_LT(b, sp))
				//	max = pos;
				// else
				//	min = pos + 1;
				int res = !!(IS_LT(b, sp));
				max = (max * !res) + (res * pos++);
				min = (min * res) + (!res * pos);

				pos = (min + max) >> 1;
				sp = a + (pos * ES);
			}
			a = sp;
			na -= pos;
		} else {
			do {
				a += ES;
				na--;
			} while (!IS_LT(b, a));
		}
		ASSERT(na > 0);
		ASSERT((a + (na * ES)) < pe);	// Catch underflow
	}

	// Skip last part of B if the opportunity arises
	VAR	*sp = pe - ES;
	VAR	*tb = b - ES;
	if (!IS_LT(sp, tb)) {
		if (nb > 10) {
			size_t  min = 0, max = nb;
			size_t  pos = max >> 1;

			sp = b + (pos * ES);
			while (min < max) {
				// The following 3 lines implement this logic
				// if (IS_LT(sp, b - ES))
				//	min = pos + 1;
				// else
				//	max = pos;
				int res = !!(IS_LT(sp, b - ES));
				max = (res * max) + (!res * pos++);
				min = (!res * min) + (res * pos);

				pos = (min + max) >> 1;
				sp = b + (pos * ES);
			}
			nb = pos;
		} else {
			do {
				sp -= ES;
				nb--;
			} while (!IS_LT(sp, tb));
		}
		ASSERT(nb > 0);
		ASSERT((b + (nb * ES)) <= pe);	// Catch underflow
	}

	// Use merge-left if nb is smaller than na
	if (nb < na)
		CALL(merge_left)(a, na, b, nb, w, nw, COMMON_ARGS);
	else
		CALL(merge_right)(a, na, b, nb, w, nw, COMMON_ARGS);
} // merge_using_workspace


// This function's job to merge two arrays together, given whatever
// size workspace is given.  It'll always make it work...eventually!
static void
NAME(merge_workspace_constrained) (VAR *pa, size_t na, VAR *pb, size_t nb,
			  VAR *ws, const size_t nw, COMMON_PARAMS)
{
	VAR	*pe = pb + (nb * ES);

	while (na > nw) {
		size_t	min = 0, max = nb, pos = max >> 1;
		VAR	*rp, *sp;	// Rotate + Split pointers

		// RP now tracks the point of block rotation
		// PB now points at the end of the part of A
		// that fits into the available workspace 
		rp = pb;
		pb = pa + nw * ES;
			
		// Find where in the B array we can split to rotate the
		// remainder of A into.  Use binary search for speed
		sp = rp + (pos * ES);
		while (min < max) {
			// if (IS_LT(sp, pb - ES))
			//	min = pos + 1;
			// else
			//	max = pos;
			int res = !!(IS_LT(sp, pb - ES));
			max = (res * max) + (!res * pos++);
			min = (!res * min) + (res * pos);

			pos = (min + max) >> 1;
			sp = rp + (pos * ES);
		}

		// Rotate the part of A that doesn't fit into the workspace
		// with everything in B that is less than where we split A at
		CALL(rotate_block)(pb, rp, sp, es);

		// Adjust the rotation pointer after the rotate and fix up sizes
		rp = pb + (sp - rp);
		na = nw;
		nb = NITEM(rp - pb);

		// We now have 4 arrays.
		// - PA->PB  is the part of A the same size as our workspace.
		// - PB->RP  is the portion of the original B array whose
		//           entries all compare less than where A was split
		// - RP->SP  is the remainder of A that could not fit into
		//           the available workspace
		// - SP->PE  is the rest of B that is >= where A was split

		// Now merge PA ->PB with PB -> RP.  The
		// rotation can make nb be 0, so check it
		if (nb > 0)
			CALL(merge_using_workspace)(pa, na, pb, nb, ws, nw, COMMON_ARGS);

		// Now set PA and PB, to be RP and SP respectively, and loop
		// This sets us up to process RP->SP as A, and SP->PE as B
		pa = rp;
		pb = sp;
		na = NITEM(sp - rp);
		nb = NITEM(pe - sp);
	}
	ASSERT(na > 0);		// It should never be possible that na == 0

	// The rotations can make nb be 0, so check it!
	if (nb > 0)
		CALL(merge_using_workspace)(pa, na, pb, nb, ws, nw, COMMON_ARGS);
} // merge_workspace_constrained


static void
NAME(sort_using_workspace)(VAR *pa, size_t n, VAR * const ws,
			   const size_t nw, COMMON_PARAMS)
{
	// Handle small array size inputs with insertion sort
	if ((n <= INSERT_SORT_MAX) || (n <= 8))
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	ASSERT(ws != NULL);
	ASSERT(nw > 0);

	// The standard merge-sort algorithm is mathematically best
	// when splitting the work up completely evenly (50:50 split)
	// In practise though, in a world of CPU's with caches, there
	// may exist a more optimal split due to data localisation.
	// This ratio is controlled by the MERGE_SKEW #define
	size_t	na = (n * MERGE_SKEW) / 100;
	size_t	nb = n - na;

	VAR	*pb = pa + (na * ES);

	// First sort A
	CALL(sort_using_workspace)(pa, na, ws, nw, COMMON_ARGS);

	// Now sort B
	CALL(sort_using_workspace)(pb, nb, ws, nw, COMMON_ARGS);

	// Use the constrained workspace algorithm to merge the array pair
	CALL(merge_workspace_constrained)(pa, na, pb, nb, ws, nw, COMMON_ARGS);
} // sort_using_workspace


// Base merge-sort algorithm - I'm all 'bout that speed baby!
// It logically follows that if this is given unique items to sort
// then the result will naturally yield a sort-stable result
static void
NAME(merge_sort_in_place)(VAR * const pa, const size_t n, VAR * const ws,
	      const size_t nw, COMMON_PARAMS)
{
	// Handle small array size inputs with insertion sort
	if ((n <= INSERT_SORT_MAX) || (n <= 8))
		return CALL(insertion_sort)(pa, n, COMMON_ARGS);

	// If we were handed a workspace, then just use that
	if (ws && (nw > 0))
		return CALL(sort_using_workspace)(pa, n, ws, nw, COMMON_ARGS);

	// Otherwise we need to create our own workspace from the data given
	// 9 appears to be close to optimal, but anything from 3-20 works
	size_t	na = n / WSRATIO;

	// Enforce a sensible minimum
	if (na < 4)
		na = 4;

	VAR	*pe = pa + (n * ES);
	VAR	*pb = pa + (na * ES);
	size_t	nb = n - na;

	// Sort B using A as the workspace
	CALL(sort_using_workspace)(pb, nb, pa, na, COMMON_ARGS);

	// Now recursively sort the workspace we had split off
	CALL(merge_sort_in_place)(pa, na, NULL, 0, COMMON_ARGS);

	// Now merge the workspace and the main sets together
#if LOW_STACK
	CALL(split_merge_in_place)(pa, pb, pe, COMMON_ARGS);
#else
	CALL(shift_merge_in_place)(pa, pb, pe, COMMON_ARGS);
#endif
} // merge_sort_in_place


//-----------------------------------------------------------------
//                        #define cleanup
//-----------------------------------------------------------------

#undef SPRINT_ACTIVATE
#undef SPRINT_EXIT_PENALTY
#undef SWAP
#undef CONCAT
#undef MAKE_STR
#undef NAME
#undef CALL
#pragma GCC diagnostic pop
