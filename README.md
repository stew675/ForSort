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


# Speed and Comparisons Efficiency

ForSort is fast.  Here's a comparison of the time taken to sort 10,000,000
random items on a stock AMD 9800X3D CPU

```
SET SIZE         SIZE IN BYTES
100                  0.8KB
1000                 7.8KB
10000               78.1KB
100000             781.3KB
1000000              7.6MB
10000000            76.3MB
100000000          762.9MB

Command: ./ts <sort_type> -x <num_items>

        ALGORITHM                    TIME (us)      COMPARES      ns/item
ForSort Workspace Stable[2]
100                                      2.237           653       22.368 *
1000                                    26.701          9707       26.701 *
10000                                  325.803        131803       32.580 *
100000                                4017.225       1613995       40.172 *
1000000                              46906.467      19269059       46.906 *
10000000                            523981.678     224527163       52.398 *
100000000                          6122525.667    2525829104       61.225 *

ForSort No Workspace Unstable
100                                      2.381           679       23.806
1000                                    30.843         10168       30.843
10000                                  367.787        135691       36.779
100000                                4406.135       1670645       44.061
1000000                              50003.965      19740918       50.004
10000000                            558282.486     228692890       55.828
100000000                          6378674.653    2589479599       63.787

ForSort In-Place Stable[3]      (Updated 17/11/2025)
100                                      2.788           833       27.876
1000                                    33.495         11320       33.495
10000                                  385.222        141146       38.522
100000                                4445.343       1776921       44.453
1000000                              51789.343      21040568       51.798
10000000                            579956.735     238413256       57.996
100000000                          6719697.183    2735516131       67.197

GrailSort In-Place
100                                      3.307           737       33.070
1000                                    41.818         10506       41.818
10000                                  519.894        138630       51.989
100000                                6188.937       1692312       61.889
1000000                              71349.709      20161613       71.350
10000000                            855741.627     236963320       85.574
100000000                          9875848.604    2654994928       98.758

Bentley/McIlroy QuickSort[4]
100                                      2.806           645       28.058
1000                                    41.885         10086       41.885
10000                                  550.891        137010       55.089
100000                                6916.392       1731463       69.164
1000000                              81977.499      20939385       81.997
10000000                            954227.635     245055932       95.423
100000000                         10684189.113    2815097308      106.842

WikiSort
100                                      2.498           617       24.976
1000                                    37.136          9510       37.136
10000                                  565.754        143339       56.575
100000                                6976.635       1828539       69.766
1000000                              82802.634      22370423       82.803
10000000                           1001843.271     266856384      100.184
100000000                         11670357.929    3064025483      116.704

TimSort
100                                      2.793           537       27.925
1000                                    43.526          8680       43.526
10000                                  588.039        120355       58.804
100000                                7318.092       1531074       73.181
1000000                              88016.397      18299349       88.016
10000000                           1043981.163     213810995      104.398
100000000                         11970582.053    2435410172      119.706

GLibC Qsort
100                                      3.251           540       32.506
1000                                    48.424          8703       48.424
10000                                  647.427        120413       64.743
100000                                7627.884       1536078       76.279
1000000                              90712.621      18672439       90.714
10000000                           1080529.754     220068878      108.053
100000000                         12415113.613    2532644915      124.151

ForSort Basic[1]
100                                      3.236           863       32.604 *
1000                                    56.628         14597       56.628 *
10000                                  816.766        205182       81.677 *
100000                               10542.463       2635966      105.425 *
1000000                             129945.853      32079394      129.946 *
10000000                           1470725.497     377262856      147.073 *
100000000                         17854415.330    4337484080      178.554 *

NOTES:
[1]   This is the raw ForSort merge algorithm implemented in its most basic manner
      It is sort-stable and in-place, but isn't using any techniques to speed it up.
[2]    This is the Unstable Algorithm, but given a workspace of 12.5% (ie. 1/8th) of
      the size of the data to be sorted, which makes the algorithm be Sort Stable.
[3]   Forsort In-Place Stable uses ForSort Basic only up to, and including, 74 items
[4]   Bentley required gcc for best results, all other algorithms were fastest with clang
```

What about on mostly sorted data sets?


Here's the speeds when given data that has been disordered by 25% (ie. 1 in 4 items are out of order)

```
Command: ./ts <sort_type> -d 25 -x <num_items>

                             (Updated 17/11/2025)

        ALGORITHM                    TIME (us)      COMPARES      ns/item
ForSort No Workspace Unstable
10000000                            435494.648     154320895       43.549

ForSort Workspace Stable
10000000                            438809.492     154708512       43.881

ForSort In-Place Stable
10000000                            441588.708     154707772       44.159

TimSort
10000000                            573999.786     139280585       57.400

Bentley/McIlroy QuickSort
10000000                            583931.735     232441659       58.393

WikiSort
10000000                            641232.849     249330874       64.123

GrailSort In-Place
10000000                            661147.023     232231634       66.115

GLibC Qsort
10000000                            679687.686     218009044       67.969

ForSort Basic
10000000                            876540.473     226391961       87.654
```

Here's the speeds when given data that has been disordered by 5% (ie. 1 in 20 items are out of order)

```
Command: ./ts <sort_type> -d 5 -x <num_items>

                             (Updated 17/11/2025)

        ALGORITHM                    TIME (us)      COMPARES      ns/item
ForSort Workspace Stable
10000000                            194781.262      63832066       19.478

ForSort No Workspace Unstable
10000000                            205648.900      67400486       20.565

ForSort In-Place Stable
10000000                            211786.912      69617445       21.179

TimSort
10000000                            213537.150      59828908       21.354

ForSort Basic
10000000                            359458.429     124731908       35.946

Bentley/McIlroy QuickSort
10000000                            359980.021     218632236       35.998

WikiSort
10000000                            370274.654     204435695       37.027

GLibC Qsort
10000000                            404562.247     199439432       40.456

GrailSort In-Place
10000000                            451696.765     201508283       45.170
```

And here are the results for 1% disordering (1 in 100 items out of order).

Here TimSort pulls a small lead due to the way it processes the input data.
The In-Place Stable ForSort is still very close though

```
Command: ./ts <sort_type> -d 1 -x <num_items>

                             (Updated 17/11/2025)

        ALGORITHM                    TIME (us)      COMPARES      ns/item
TimSort
10000000                             91596.804      29069695        9.160

ForSort Workspace Stable
10000000                            109555.790      35028562       10.956

ForSort No Workspace Unstable
10000000                            114490.369      36004772       11.449

ForSort In-Place Stable
10000000                            117693.110      37733731       11.769

ForSort Basic
10000000                            194250.177      83810555       19.425

WikiSort
10000000                            249037.711     161736014       24.903

Bentley/McIlroy QuickSort
10000000                            299404.357     215110184       29.940

GLibC Qsort
10000000                            321250.798     178608598       32.125

GrailSort In-Place
10000000                            343925.589     166963169       34.394
```

What about ordered unique reversed data ordering?

```
Command: ./ts <sort_type> -o -u -r -x <num_items>

                             (Updated 17/11/2025)

        ALGORITHM                    TIME (us)      COMPARES      ns/item
TimSort [1]
10000000                             10178.726       9999999        1.018 *

ForSort Basic
10000000                             25638.666      19999998        2.564 *

ForSort In-Place Stable
10000000                             30061.171      21007001        3.006 *

WikiSort
10000000                             76870.164      21498750        7.687 *

ForSort Workspace Stable
10000000                             97980.632      60902020        9.789 *

ForSort No Workspace Unstable
10000000                             99535.869      57144448        9.954 *

GrailSort In-Place
10000000                            174085.980      81979307       17.409 *

GLibC Qsort
10000000                            242779.208     118788160       24.278 *

Bentley/McIlroy QuickSort
10000000                            406030.109     290683459       40.603 *

```

...and finally when using wholly sorted unique data.

```
Command: ./ts <sort_type> -o -u -x <num_items>

                             (Updated 17/11/2025)

        ALGORITHM                    TIME (us)      COMPARES      ns/item
ForSort Basic [1]
10000000                              8731.014       9999999        0.873 *

TimSort [1]
10000000                              8880.496       9999999        0.888 *

ForSort In-Place Stable [2]
10000000                             12772.462       9999999        1.277 *

ForSort Workspace Stable
10000000                             13024.626      10000112        1.302 *

ForSort No Workspace Unstable
10000000                             13378.552      10000620        1.338 *

WikiSort
10000000                             27070.154      20122509        2.707 *

GrailSort In-Place
10000000                            170497.552      79189929       17.050 *

GLibC Qsort
10000000                            198828.838     114434624       19.883 *

Bentley/McIlroy QuickSort
10000000                            258623.324     211572877       25.862 *

Notes:
[1]  : Both Basic and TimSort do a pre-sort check for ordering and reversals, which is
       what gives them their speed
[2]  : ForSort In-Place Stable pre-sorts its work-space.  If it discovers the workspace
       was already fully sorted, it conditionally checks to see if the rest of the input
       is sorted.  Ordinarily it doesn't scan the rest of the input.
```

# Discussion

This is my implementation of an O(nlogn) in-place merge-sort algorithm.
There is (almost) nothing new under the sun, and ForSort is certainly an
evolution on the work of many others.  It has its roots in the following:

- Merge Sort
- Insertion Sort
- Block Sort
- Grail Sort
- Powermerge - https://koreascience.kr/article/CFKO200311922203087.pdf

This originally started out with me experimenting with sorting algorithms,
and I thought that I had stumbled onto something new, but all I'd done was
independently rediscover Powermerge (see link above)

Here's a link to a StackOverflow answer I gave many years back some time
after I'd found my version of the solution:

https://stackoverflow.com/a/68603446/16534062

Still, Powermerge has a number of glaring flaws, which I suspect is why
it hasn't been widely adopted, and the world has more or less coalesced
around Block Sort and its variants like GrailSort, and so on.  Powermerge's
biggest issue is that the recursion stack depth is unbounded, and it's
rather easy to construct degenerate scenarios where the call stack will
overflow in short order.  That algorithm is implemented by
*shift_merge_in_place()*.

I worked to solve those issues, but the code grew in complexity, and then
started to slow down to point of losing all its benefits.  While messing
about with solutions, I created what I call *split_merge_in_place()*.  To
date I've not found an algorithm that implements exactly what it does, but
it does have a number of strong similarities to what BlockSort does.

Unlike *shift_merge_in_place()*, the *split_merge_in_place()* algorithm
doesn't bury itself in the details of finding the precise optimal place to
split a block being merged, but rather uses a simple division algorithm to
choose where to split.
In essence it
takes a "divide and conquer" approach to the problem of merging two arrays
together in place, and deposits fixed sized chunks, saves where that chunk
is on a work stack, and then continues depositing chunks.  When all chunks
are placed, it goes back and splits each one up again in turn into smaller
chunks, and continues.

In doing so, it achieves a stack requirement of just `15*log16(N)` split points,
where N is the size of the left side array being merged.  The size of the
right-side array doesn't matter to the *split_merge_in_place* algorithm.
This stack growth is very slow.
A stack size of 120 can account for over 2^32 items,
and a stack size of 240 can track 2^64 items.

This makes it an **O(logN)** space complexity algorithm, but there are a good
number of of **O(1)** algorithms that allocate a much larger amount of static
memory than *ForSort* ever will, and those algorithms still call themselves
**O(1)**.  The devil is, as always, in the details.

*split_merge_in_place()* is about 30% slower than *shift_merge_in_place()*
in practise though, but it makes for an excellent fallback to the faster
*shift_merge_in_place()* algorithm for when that algorithm gets lost in the
weeds of chopping up chunks and runs its work stack out of memory.

I then read about how GrailSort and BlockSort use unique items as a work
space, which is what allows those algorithms to achieve sort stability.  I
didn't look too deeply into how either of those algorithms extract unique
items, preferring the challenge of coming up with my own solution to that
problem.  *extract_uniques()* is my solution that also takes a divide and
conquer approach to split an array of items into uniques and duplicates,
and then uses a variant of the Gries-Mills Block Swap algorithm to quickly
move runs of duplicates into place:

*Ref: https://en.wikipedia.org/wiki/Block_swap_algorithms*

*extract_uniques()* moves all duplicates, which are kept in sorted order, to
the left side of the main array, which creates a sorted block that can be
merged in at the end.  When enough unique items are gathered, they are then
used as the scratch work-space to invoke the adaptive merge sort in place
algorithm to efficiently sort that which remains.  This phase appears to
try MUCH harder than either BlockSort or GrailSort do, as it is still
sorting the array as it performs this unique extraction task.

Of course, if an input is provided with less than 0.5% unique items, then
ForSort will give up and revert back to using the non-adaptive, but
stable, simple sort.  The thing is, if the data set is THAT degenerate,
then the resulting data is very easy to sort, and the slow simple sort
still runs very quickly.
