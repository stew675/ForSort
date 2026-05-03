# ForSort

ForSort - An adaptive, O(nlogn) time, O(logn) space, stable, in-place, sorting algorithm

Author: Stew Forster (stew675@gmail.com)

Copyright (C) 2021-2025

# Introduction

**forsought**
    *(verb)* - the simple past and past participle of forseek

**forseek** 
    *(verb)* - To seek thoroughly (for); seek out.

The name ForSort is a word-play on the archaic word forsaught, being the past tense
of seeing in advance, which is in turn a joking reference to its speed, because it
"saw" the sorted result before you realised. :p

Its C programming interface is very similar to GLibC QSort, but with a twist that
the comparison routine only need to report if the first value is strictly less than the second.

```
int is_less_than(const void *p1, const void *p2);


void forsort_basic(void base[n * size], size_t n, size_t size,
                  typeof(int (const void [size], const void [size])) *is_less_than);

void forsort_inplace(void base[n * size], size_t n, size_t size,
                  typeof(int (const void [size], const void [size])) *is_less_than,
                  void *work_space, size_t work_size);

void forsort_stable(void base[n * size], size_t n, size_t size,
                  typeof(int (const void [size], const void [size])) *is_less_than);
```

**forsort_basic()** - is the simplest algorithm.  It is a basic top-down stable, in-place,
merge sort that uses the *shift_merge_in_place()* function to merge arrays together.
It is provided primarily as a means of testing the base functionality that the other
two algorithms rely upon to achieve their in-place behaviour.

**forsort_inplace()** - is a moderately advanced adaptive merge-sort implementation that
bears a lot of similarities to how TimSort merges blocks, but it also adds on a
block rotation mechanism that allows it to efficiently sort arrays even with highly
constrained work-space sizes.  It can take an optional *work_space* buffer argument, and
if provided, it will use that work-space for merging.  When operating in this manner
the algorithm is sort-stable. *work_size* is the size of the workspace in bytes.

If no work space buffer is provided, the algorithm will use a portion of the array
to be sorted as its work-space.  The algorithm is fully in-place though, and so it
will not overwrite any data present, merely swapping items back and forth to sort
the rest of the array.  When the rest of the array is sorted, the algorithm recursively
sorts the work-space until it too is sorted.  **forsort_inplace** uses the stable
merging behaviour of *shift_merge_in_place()* function (that **forsort_basic** uses)
to sort the work-space without requiring any additional buffers.

When operating in this manner the algorithm is not sort-stable **UNLESS** all the
items in the first tenth of the array to be sorted all have unique sort "keys".

Understanding **forsort_inplace** is then an excellent segue into what **forsort_stable**
adds to the whole shebang.

**forsort_stable()** - builds on top of *forsort_inplace* by introducing a mechanism
to quickly extract unique sort keys out of the array to be sorted, in a sort-stable
and in-place manner.  It repeatedly scans an increasing amount of the input array
until it finds enough unique keys to be used as a work-space to pass to **forsort_inplace**
in order to sort the rest of the input.

Items with duplicate keys are sorted and "slid" to the start of the main array while
items with unique keys are built up just to the right of the the duplicates.  If the
algorithm cannot find sufficient keys, then it keeps repeating until either it does
find enough keys, or until it ends up sorting the entire input!

This unique key extraction is very quick and runs significantly faster than the
main merge-sort algorithm when there are very few unique keys to extract.  It does
run slower when there are many unique keys though, but by then it will have built
a large enough work-space to pass to **forsort_inplace**.

With a work-space of unique keys extracted, **forsort_inplace** is used to sort the
remainder. When the main input is sorted, the work-space is re-used to quickly
merge up all the blocks of duplicates, and when that is complete, the work-space
itself is passed to **forsort_inplace** to be sorted.  Since it is all unique items,
the result is also sort-stable.  A final merging of the duplicates with the sorted
work-space, and the main sorted array using *shift_merge_in_place* completes the
resultant stable, wholly in-place sort.

**TODO** - Add re-entrent *_r* versions of all interfaces


# Building and Testing

ForSort is written in C.  A Makefile is provided to easily compile and test.
This produces an executable called **ts**   (aka. TestSort)

`ts` can be used to provide a variety of inputs to the sorting algorithms
to test speed, correctness, and sort stability.

```
Usage: ts [options] <sorttype< <num>

[options] is zero or more of the following options
        -a seed     A random number generator seed value to use (default=1)
                    A value of 0 will use a randomly generated seed
        -d <0..100> Disorder the generated set by the percentage given (default=100)
        -f          Data set keys/values range from 0..UINT32_MAX (default)
        -l <num>    Data set keys/values limited in range from 0..(num-1)
        -l n        If the letter 'n' is specified, use the number of elements as the key range
        -o          Use a fully ordered data set (Shorthand for setting disorder factor to 0)
        -r          Reverse the data set order after generating it
        -u          Data set keys/values must all be unique
        -v          Verbose.  Display the data set before sorting it
        -w <num>    Optional workspace size (in elements) to pass to the sorting algorithm

Available Sort Types:
   gq   - GLibc Quick Sort In-Place                  (Stable?[1]/Not-In-Place)
   nq   - Bentley/McIlroy Quick Sort                 (Unstable/In-Place)
   fb   - Basic ForSort Merge Sort In-Place          (Stable/In-Place)
   fi   - Adaptive ForSort Merge Sort In-Place       (Unstable[2]/In-Place)
   fs   - Stable ForSort Merge Sort In-Place         (Stable/In-Place)
   gs   - GrailSort                                  (Stable/In-Place)
   ti   - TimSort                                    (Stable/Not-In-Place)
   wi   - WikiSort                                   (Stable/In-Place)

[1] - GlibC's sorting algorithm's stability is not guaranteed, and can fall back to an
      unstable algorithm for certain inputs
[2] - The Adaptive Forsort algorithm can be provided with an external work-space, which
      if done, will make the algorithm sort-stable
```

For example:

```
./ts -a 5 -d 5 -r fs 1000000
```

will test the Stable ForSort algorithm, with a random seed value of 5, a disordering
factor of 5%, with the data set then reversed.


# Performance Summary

ForSort is fast. Here's a comparison of average sorting performance across all test variants
(excluding reverse-ordered scenarios which are statistical outliers rarely seen in practice).
Lower values indicate better performance.

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------|------------|-------------|--------------|---------------|----------------|-----------------|
| fw | **6.393** | **9.032** | **11.935** | **14.627** | **15.980** | **17.668** | **21.923** |
| fi | 6.925 | 10.567 | 13.465 | 15.628 | 17.243 | 18.889 | 22.250 |
| fs | 8.832 | 11.623 | 14.122 | 16.244 | 17.611 | 19.420 | 23.332 |
| ti | 9.360 | 15.772 | 22.160 | 27.277 | 32.167 | 37.636 | 43.258 |
| wi | 7.699 | 12.839 | 20.634 | 26.695 | 32.782 | 40.019 | 48.014 |
| nq | 11.025 | 16.745 | 22.882 | 29.339 | 35.384 | 41.450 | 47.919 |
| gs | 12.560 | 17.714 | 23.811 | 29.838 | 37.435 | 46.037 | 56.920 |
| fb | 9.606 | 17.934 | 26.361 | 33.551 | 39.831 | 46.564 | 54.424 |
| gq | 13.764 | 21.801 | 29.967 | 36.723 | 44.368 | 53.390 | 62.965 |
| is | 8.222 | 17.046 | 34.950 | 196.14 | 2478.0 | - | - |

**Legend:**
- **fw**: ForSort With Allocated Workspace (Stable)
- **fi**: ForSort Unstable Fully In-Place (Unstable)
- **fs**: ForSort Stable Fully In-Place (Stable)
- **ti**: TimSort with Allocated Workspace (Stable)
- **wi**: WikiSort Fully In-Place (Stable)
- **nq**: Bentley/McIlroy Quick Sort In-Place (Unstable)
- **gs**: GrailSort Fully In-Place (Stable)
- **fb**: ForSort Basic Fully In-Place (Stable)
- **gq**: GLibc Quick Sort Fully In-Place (Unstable)
- **is**: Insertion Sort Fully In-Place (Stable) - skipped for large datasets

## Detailed Performance Analysis

For comprehensive benchmark results and analysis, see **[RESULTS.md](RESULTS.md)** which includes:

1. **[Cross-Category Analysis](RESULTS.md#cross-category-analysis)** - Overall performance ranking averaged across all test variants
2. **[Size Winners Summary](RESULTS.md#size-winners-summary)** - Algorithm performance at each dataset size
3. **[Worst-Case Performance](RESULTS.md#worst-case-performance)** - Algorithm with best worst-case results
4. **[Summary by Dataset Size and Test Variant](RESULTS.md#summary-by-dataset-size-and-test-variant)** - Performance breakdown by each test scenario
5. **[Performance Rankings](RESULTS.md#performance-rankings)** - Detailed rankings at each dataset size and variant
6. **[Detailed Results by Dataset Size](RESULTS.md#detailed-results-by-dataset-size)** - Full breakdown including reverse-ordered scenarios
7. **[Stability Verification](RESULTS.md#stability-verification)** - Stability testing results

