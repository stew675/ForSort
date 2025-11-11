#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include <x86intrin.h>
#include "timsort.h"

#define DATA_SET_REVERSED	0x04
#define DATA_SET_UNIQUE		0x08

// Set to 1 to activate 32-bit item sizes, however sort
// stability verification is lost when this is done
#define	USE32BIT		0

static	int	disorder_factor = 100;
static	int	data_set_ops = 0;
static	uint32_t data_set_limit = UINT32_MAX;
static	uint32_t random_seed = 1;
static	bool	verbose = false;
static	bool	correct = true;
#if (USE32BIT == 0)
static	bool	stable = true;
#endif
static	size_t	numcmps = 0;
static	size_t	worksize = 0;
static	bool	supports_workspace = false;

struct item {
	uint32_t	value;
#if (USE32BIT == 0)
	uint32_t	order;
#endif
};

#include "forsort.h"

extern void grailSortInPlace(void *a, const size_t n, const size_t es,
	int (*cmp)(const void *, const void *));

extern void nqsort(void *a, const size_t n, const size_t es,
	int (*cmp)(const void *, const void *));

extern void WikiSort(void *a, const size_t n,
	int (*cmp)(struct item, struct item));

enum {
	GLIBC_QSORT = 1,
	BENTLEY_QSORT,
	TIM_SORT,
	WIKI_SORT,
	GRAIL_SORT,
	FORSORT_INPLACE,
	FORSORT_BASIC,
	FORSORT_STABLE,
	SORT_UNKNOWN
};

static	int	sorttype = SORT_UNKNOWN;
static	char	*sortname = NULL;

static int __attribute__((noinline))
wiki_compare(struct item p1, struct item p2)
{
	numcmps++;
	return p1.value < p2.value;
} // wiki_compare

// Used to determine if the first uint32_t pointed at, is less than
// the second uint32_t that is pointed at
static int __attribute__((noinline))
is_less_than_uint32(const void *p1, const void *p2)
{
	numcmps++;
	return (((struct item *)p1)->value < ((struct item *)p2)->value);
} // is_less_than_uint32

// Used to compare two uint32_t values pointed at by the pointers given
static int __attribute__((noinline))
compare_uint32(const void *p1, const void *p2)
{
	const uint32_t av = ((struct item *)p1)->value;
	const uint32_t bv = ((struct item *)p2)->value;

	numcmps++;
	return (av == bv) ? 0 : (av < bv) ? -1 : 1;
} // compare_uint32


void
print_array(struct item a[], size_t n)
{
	printf("\nDATA_SET = [");
	for(size_t i = 0; i < n; i++) {
		if ((i % 20) == 0) {
			printf("\n");
		}
		printf("%5u,", a[i].value);
	}
	printf("\n];\n");
} // print_array


void
print_value(struct item *a)
{
	printf("%5u\n", a->value);
} // print_value


static void
test_sort(struct item a[], size_t n)
{
	if (data_set_ops & DATA_SET_UNIQUE) {
		for(size_t i = 1; i < n; i++)
			if(a[i-1].value >= a[i].value) {
				correct = false;
				return;
			}
	} else {
		for(size_t i = 1; i < n; i++)
			if(a[i-1].value > a[i].value) {
				correct = false;
				return;
			}
	}
} // test_sort

static void
test_stability(struct item a[], size_t n)
{
#if (USE32BIT == 0)
	stable = true;
	for(size_t i = 1; i < n; i++)
		if(a[i-1].value == a[i].value)
			if (a[i-1].order > a[i].order) {
				stable = false;
				return;
			}
#endif
} // test_stability

static inline uint64_t
get_cycles()
{
	_mm_lfence();
	return __rdtsc();
}

static void
usage(char *prog, char *msg)
{
	fprintf(stderr, "\nError: %s\n", msg);
	fprintf(stderr, "\nUsage: %s [options] <sorttype< <num>\n", prog);
	fprintf(stderr, "\n[options] is zero or more of the following options\n");
	fprintf(stderr, "\t-a seed     A random number generator seed value to use (default=1)\n");
	fprintf(stderr, "\t	    A value of 0 will use a randomly generated seed\n");
	fprintf(stderr, "\t-d <0..100> Disorder the generated set by the percentage given (default=100)\n");
	fprintf(stderr, "\t-f	  Data set keys/values range from 0..UINT32_MAX (default)\n");
	fprintf(stderr, "\t-l <num>    Data set keys/values limited in range from 0..(num-1)\n");
	fprintf(stderr, "\t-l n	If the letter 'n' is specified, use the number of elements as the key range\n");
	fprintf(stderr, "\t-o	  Use a fully ordered data set (Shorthand for setting disorder factor to 0)\n");
	fprintf(stderr, "\t-r	  Reverse the data set order after generating it\n");
	fprintf(stderr, "\t-u	  Data set keys/values must all be unique\n");
	fprintf(stderr, "\t-v	  Verbose.  Display the data set before sorting it\n");
	fprintf(stderr, "\t-w <num>    Optional workspace size (in elements) to pass to the sorting algorithm\n");
	fprintf(stderr, "\nAvailable Sort Types:\n");
	fprintf(stderr, "   fb   - Basic Forsort In-Place                 (Stable)\n");
	fprintf(stderr, "   fi   - Adaptive Forsort In-Place              (Unstable)\n");
	fprintf(stderr, "   fs   - Stable Forsort In-Place                (Stable)\n");
	fprintf(stderr, "   gs   - Grail Sort In-Place                    (Stable)\n");
	fprintf(stderr, "   gq   - GLibc Quick Sort In-Place              (Stability Not Guaranteed)\n");
	fprintf(stderr, "   nq   - Bentley/McIlroy Quick Sort In-Place    (Unstable)\n");
	fprintf(stderr, "   ti   - TimSort                                (Stable)\n");
	fprintf(stderr, "   wi   - WikiSort                               (Stable)\n");
	exit(-1);
} // usage


void
parse_sort_type(char *opt)
{
	if (strcmp(opt, "gs") == 0) {
		sortname = "GrailSort";
		sorttype =  GRAIL_SORT;
		return;
	}

	if (strcmp(opt, "wi") == 0) {
		sortname = "WikiSort";
		sorttype =  WIKI_SORT;
		return;
	}

	if (strcmp(opt, "ti") == 0) {
		sortname = "TimSort";
		sorttype =  TIM_SORT;
		return;
	}

	if (strcmp(opt, "gq") == 0) {
		sortname = "GLibc QuickSort";
		sorttype =  GLIBC_QSORT;
		return;
	}

	if (strcmp(opt, "nq") == 0) {
		sortname = "Bentley/McIlroy QuickSort";
		sorttype =  BENTLEY_QSORT;
		return;
	}

	if (strcmp(opt, "fb") == 0) {
		sortname = "Basic Forsort In Place";
		sorttype =  FORSORT_BASIC;
		return;
	}

	if (strcmp(opt, "fs") == 0) {
		sortname = "Stable Forsort In Place";
		sorttype =  FORSORT_STABLE;
		return;
	}

	if (strcmp(opt, "fi") == 0) {
		sortname = "Adaptive Forsort In Place";
		sorttype =  FORSORT_INPLACE;
		supports_workspace = true;
		return;
	}

	sorttype = SORT_UNKNOWN;
	return;
} // parse_sort_type


static int
parse_control_opt(char *argv[])
{
	if (*argv[0] != '-') {
		parse_sort_type(argv[0]);
		return 1;
	}

	// The srandom seed value
	if (!strcmp(argv[0], "-a")) {
		random_seed = atoi(argv[1]);
		return 2;	// We grabbed 2 options
	}

	if (!strcmp(argv[0], "-d")) {
		int factor;

		factor = atoi(argv[1]);
		if (factor < 0 || factor > 100) {
			fprintf(stderr, "Please specify a disorder factor between [0..100] (inclusive)\n");
			return 2;
		}
		disorder_factor = factor;
		return 2;
	}
	if (!strcmp(argv[0], "-f")) {
		data_set_limit = UINT32_MAX;
		return 1;
	}
	if (!strcmp(argv[0], "-l")) {
		size_t limit;
		if (!strcmp(argv[1], "n")) {
			data_set_limit = 0;
			return 2;
		}
		limit = atol(argv[1]);
		if (limit > UINT32_MAX)
			limit = UINT32_MAX;
		if (limit == 0) {
			fprintf(stderr, "Bad value specified for the key/value limit\n");
			return 2;
		}
		data_set_limit = limit;
		return 2;	// We grabbed 2 options
	}
	if (!strcmp(argv[0], "-o")) {
		disorder_factor = 0;
		return 1;
	}
	if (!strcmp(argv[0], "-r")) {
		data_set_ops |= DATA_SET_REVERSED;
		return 1;
	}
	if (!strcmp(argv[0], "-u")) {
		data_set_ops |= DATA_SET_UNIQUE;
		return 1;
	}
	if (!strcmp(argv[0], "-v")) {
		verbose = true;
		return 1;
	}
	if (!strcmp(argv[0], "-w")) {
		worksize = atol(argv[1]);
		if (worksize > UINT32_MAX)
			worksize = UINT32_MAX;
		return 2;
	}

	fprintf(stderr, "Unsupported option: %s\n", argv[0]);
	return 1;
} // parse_control_opt


void
reverse_set(struct item *a, size_t n)
{
	struct item t;

	for (size_t i = 0; i < (n / 2); i++) {
		t = a[(n - i) - 1];
		a[(n - i) - 1] = a[i];
		a[i] = t;
	}
} // reverse_set


// Perform a disorder on the set
void
disorder_set(struct item *a, size_t n)
{
	if (disorder_factor <= 0)
		return;
	if (disorder_factor > 100)
		disorder_factor = 100;

	// Fowards pass
	for (size_t i = 0; i < (n - 1); i++) {
		size_t target, range;
		struct item t;

		// Determine if we will disorder this element
		// We halve the disorder factor because we do
		// a second reverse pass just below
		if ((random() % 100) >= ((disorder_factor + 1) / 2))
			continue;

		// Establish the range for the disorder
		range = (n - i) - 1;
		range *= disorder_factor;
		range /= 100;
		range += 1;
		do {
			target = i + (random() % range) + 1;
		} while (target >= n);

		// We have our target. Swap ourselves with that
		t = a[i];
		a[i] = a[target];
		a[target] = t;
	}

	// Backwards pass
	for (size_t i = n - 1; i > 0; i--) {
		size_t target, range;
		struct item t;

		// Determine if we will disorder this element
		if ((random() % 100) >= ((disorder_factor + 1) / 2))
			continue;

		// Establish the range for the disorder
		range = i - 1;
		range *= disorder_factor;
		range /= 100;
		range += 1;
		do {
			target = (i - (random() % range)) - 1;
		} while (target >= n);

		// We have our target. Swap ourselves with that
		t = a[i];
		a[i] = a[target];
		a[target] = t;
	}
} // disorder_set


uint32_t
get_next_val(uint32_t val, size_t pos, size_t n)
{
	uint32_t vals_left = data_set_limit - val;
	size_t togo = n - pos;
	double step;

	// Bump step by 1 if it's >1, and if we're not generating
	// unique numbers. This reduces the chance we'll generate
	// masses of 0-value increments if step is, for example, 1.1
	// at this point. If it was, then 90% of the time it would
	// not increment val, whereas if we do this, then we will
	// at least ~53% of the time
	if (data_set_ops & DATA_SET_UNIQUE) {
		if (vals_left < togo) {
			fprintf(stderr, "Data set requested is larger than the unique\n");
			fprintf(stderr, "set of values that can be generated. Aborting\n");
			exit(1);
		}
		step = vals_left - 1;
		step /= togo;
		step += 1;
		if (step > vals_left) {
			step = vals_left;
		}
	} else {
		vals_left -= 1;
		if (vals_left > 0) {
			step = data_set_limit;
			step /= n;
			if (vals_left > togo) {
				step += 2;
			} else {
				step += 1;
			}
			if (step > (vals_left + 1)) {
				step = vals_left + 1;
			}
		} else {
			step = 0;
		}
	}

	// Generate a decimal value in the range 0..1 (but excluding 1 itself)
	double r = (double)random(), rm = RAND_MAX;
	rm += 1;
	r /= rm;

	step *= r;

	if (pos == 0) {
		if (data_set_ops & DATA_SET_UNIQUE) {
			if (step > 2) {
				return (step - 1);
			} else {
				return 0;
			}
		}
		return (uint32_t)step;
	}

	if (data_set_ops & DATA_SET_UNIQUE) {
		if (step < 1)
			step = 1;
	}

	return val + (uint32_t)step;
} // get_next_val


void
fillset(struct item *a, size_t n)
{
	// First fill the set in an ordered manner
	a[0].value = get_next_val(0, 0, n);
	for (size_t i = 1; i < n; i++) {
		a[i].value = get_next_val(a[i-1].value, i, n);
	}

	// Disorder the set according to the disorder factor
	disorder_set(a, n);

	// Reverse the data set if asked to
	if (data_set_ops & DATA_SET_REVERSED)
		reverse_set(a, n);

#if (USE32BIT == 0)
	// Apply stability tagging
	for (uint32_t i = 0; i < n; i++)
		a[i].order = i;

	stable = true;
#endif
} // fillset


int
main(int argc, char *argv[])
{
	size_t		n;
	struct item	*a;
	int		optpos = 1;

	if(argc < 3) {
		usage(argv[0], "Incorrect number of arguments");
	}

	while ((strlen(argv[optpos]) == 2) && !isdigit(argv[optpos][0])) {
		optpos += parse_control_opt(argv + optpos);
	}

	if (sorttype == SORT_UNKNOWN)
		usage(argv[0], "Unknown sort type");

	// Determine the size of the array we'll be sorting
	if ((n = atol(argv[optpos++])) < 1) {
		fprintf(stderr, "Please use values of 1 or greater for the number of elements\n");
		exit(-1);
	}
	if (n >= INT32_MAX) {
		fprintf(stderr, "Please use values less than %d for the number of elements\n", INT32_MAX);
		exit(-1);
	}

	// If data_set_limit is 0 at this point, it means we should set it to n
	if (data_set_limit == 0) {
		data_set_limit = n;
	}

	// Just print a clear line before everything else
	printf("\n");

	// Set up the random number generator
	if (random_seed <= 0) {
		struct timespec now;

		clock_gettime(CLOCK_MONOTONIC, &now);
		random_seed = (uint32_t)((now.tv_sec ^ now.tv_nsec) & 0xffffffff);
		printf("Using a randomly generated random seed value\n");
	}
	printf("Seeding Random Generator with:  %u\n", random_seed);
	srandom(random_seed);

	// Allocate up the array to sort
	if ((a = (struct item *)aligned_alloc(4096, n * sizeof(*a))) == NULL) {
		fprintf(stderr, "alloc failed - out of memory\n");
		exit(-1);
	}
	memset(a, 0, n * sizeof(*a));

	// Now populate the array according to the command line options
	printf("\nPopulating array of size: %lu\n\n", n);
	printf("Data value range is 0..%u (inclusive)\n", data_set_limit - 1);
	if (disorder_factor == 0) {
		printf("Data set is ordered\n");
	} else {
		printf("Data set is disordered with factor: %d%%\n", disorder_factor);
	}
	if (data_set_ops & DATA_SET_UNIQUE) {
		printf("All data values are unique\n");
	} else {
		printf("Duplicate data values are allowed in the set\n");
	}
	if (data_set_ops & DATA_SET_REVERSED) {
		printf("Data set is reversed\n");
	}

#if USE32BIT
	printf("Using 32-bit items. Sort stability testing is disabled\n");
#else
	printf("Using 64-bit items. Sort stability testing is enabled\n");
#endif

	char *workspace = NULL;

	if (worksize > 0) {
		if (supports_workspace) {
			printf("Providing a pre-allocated scratch workspace of %ld items in size\n", worksize);

			worksize *= sizeof(*a);
			if(worksize > 0)
				workspace = (char *)malloc(worksize);
		} else {
			printf("Ignoring workspace option as the selected sort does not support it\n");
		}
	}

	fillset(a, n);
	if (verbose) {
		print_array(a, n);
	}

	// Let's finally do this thing!
	struct timespec start, end;
	uint64_t startc = 0, endc = 0;
	printf("\nStarting %s\n", sortname);
	clock_gettime(CLOCK_MONOTONIC, &start);
	startc = get_cycles();

	switch (sorttype) {
	case GLIBC_QSORT:
		qsort(a, n, sizeof(*a), compare_uint32);
		break;
	case BENTLEY_QSORT:
		nqsort(a, n, sizeof(*a), compare_uint32);
		break;
	case WIKI_SORT:
		WikiSort(a, n, wiki_compare);	// Wiki-Sort only accepts 64-bit items
		break;
	case TIM_SORT:
		timsort(a, n, sizeof(*a), compare_uint32);
		break;
	case GRAIL_SORT:
		grailSortInPlace(a, n, sizeof(*a), compare_uint32);
		break;
	case FORSORT_BASIC:
		forsort_basic(a, n, sizeof(*a), is_less_than_uint32);
		break;
	case FORSORT_INPLACE:
		forsort_inplace(a, n, sizeof(*a), is_less_than_uint32, workspace, worksize);
		break;
	case FORSORT_STABLE:
		forsort_stable(a, n, sizeof(*a), is_less_than_uint32);
		break;
	default:
		printf("ERROR: Unknown sort type\n");
		exit(1);
	}

	endc = get_cycles();
	clock_gettime(CLOCK_MONOTONIC, &end);

	if (workspace) {
		free(workspace);
		worksize = 0;
		workspace = NULL;
	}

	if (verbose) {
		print_array(a, n);
	}

	// Did it sort correctly?
	test_sort(a, n);

	// Was sort stable?
	test_stability(a, n);

	// Stats time!
	double tim = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
	printf("\n");
	printf("Time taken to sort   : %.9fs\n", tim);
	printf("Number of Compares   : %lu\n", numcmps);
	printf("Number of CPU Cycles : %lu\n", (endc - startc));
	printf("Data Is Sorted       : %s\n", correct ? "TRUE" : "FALSE");
#if USE32BIT
	printf("Sort is Stable       : %s\n", "UNKNOWN");
#else
	printf("Sort is Stable       : %s\n", stable ? "TRUE" : "FALSE");
#endif
	printf(" ");
	printf(" ");
	printf("\n");

	free(a);
} /* main */
