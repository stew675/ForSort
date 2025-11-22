/*
               Copyright (C) 2025 Stew Forster stew675@gmail.com
*/

/*
        Permission is hereby granted, free of charge, to any person obtaining
        a copy of this software and associated documentation files (the
        "Software"), to deal in the Software without restriction, including
        without limitation the rights to use, copy, modify, merge, publish,
        distribute, sublicense, and/or sell copies of the Software, and to
        permit persons to whom the Software is furnished to do so, subject to
        the following conditions:

        The above copyright notice and this permission notice shall be
        included in all copies or substantial portions of the Software.

        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
        EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
        MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
        IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
        CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
        TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
        SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

#include "rotate.h"
#include "triple-shift-rotate.h"

typedef void rotate_function(int *array, size_t left, size_t right);

typedef struct {
	rotate_function		*rotate;
	char			*name;
} rotate_function_t;

rotate_function_t rotations[] = {
	{griesmills_rotation, "Gries-Mills Rotation"},
	{reversal_rotation, "Triple-Reverse Rotate"},
	{piston_rotation, "Piston Rotation"},
	{grail_rotation, "Grail Rotation"},
	{contrev_rotation, "ContRev Rotation"},
	{auxiliary_rotation, "Auxiliary Rotation"},
	{bridge_rotation, "Bridge Rotation"},
	{trinity_rotation, "Trinity Rotation"},
	{triple_shift_rotate, "Triple Shift Rotate"},
	{NULL, "End Of List"}
};


rotate_function_t *
get_next_function(int i)
{
	for (int j = 0; j < i; j++)
		if (rotations[j].rotate == NULL)
			return NULL;
	if (rotations[i].rotate == NULL)
		return NULL;
	return rotations + i;
} // get_next_function 

#define MAX 100000000000ULL
int
main()
{
	struct	timespec start, end;
	size_t	MAXSZ = 10000000;
	int32_t	*a;

	a = malloc(sizeof(*a) * MAXSZ);
	if (!a) {
		printf("malloc() failure\n");
		exit(1);
	}
	for (size_t i = 0; i < MAXSZ; i++)
		a[i] = i;

	for (size_t SZ = 10; ((SZ * SZ) <= (MAX * 10)) && (SZ < MAXSZ); SZ *= 10) {
		printf("\n");
		printf("=======================================================\n");
		printf("         NAME                 ITEMS     TIME/ROTATE (s)\n");
		printf("=======================================================\n");
		for (int fno = 0; ; fno++) {
			rotate_function_t *f = get_next_function(fno);
			if (f == NULL)
				break;

			size_t	stop = MAX / (SZ * SZ);

			// The following applies a fudge factor to speed up the
			// testing of very small arrays
			size_t	div = 200 / SZ;
			if (div < 1)
				div = 1;

			// Figure out how many loops we're going to do
			stop /= div;
			if (stop < 1)
				stop = 1;

			size_t	runs = 0;
			clock_gettime(CLOCK_MONOTONIC, &start);

			for (size_t j = 0; j < stop; j++) {
				for (size_t i = 1; i < SZ; i++) {
					f->rotate(a, i, SZ - i);
					runs++;
				}
			}

			clock_gettime(CLOCK_MONOTONIC, &end);

			double tim = ((end.tv_sec - start.tv_sec) * 1000000000) + (end.tv_nsec - start.tv_nsec);
			printf("%-24s    %7lu        %10.3fns\n", f->name, SZ, tim/runs);
		}
	}

	free(a);
} // main
