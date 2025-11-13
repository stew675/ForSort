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


        ALGORITHM                    TIME (us)      COMPARES      ns/item
ForSort Workspace Stable[2]
100                                      2.291           653       22.909
1000                                    27.052          9707       27.052
10000                                  329.862        131803       32.986
100000                                4051.666       1613995       40.517
1000000                              46621.897      19269046       46.622
10000000                            528303.381     224527023       52.830
100000000                          6093108.276    2522421876       60.931

ForSort No Workspace Unstable
100                                      2.381           679       23.806
1000                                    30.843         10168       30.843
10000                                  367.787        135691       36.779
100000                                4406.135       1670645       44.061
1000000                              50003.965      19740918       50.004
10000000                            558282.486     228692890       55.828
100000000                          6378674.653    2589479599       63.787

ForSort In-Place Stable[3]
100                                      2.807           840       28.075
1000                                    34.406         10871       34.406
10000                                  391.139        141504       39.114
100000                                4624.911       1727402       46.249
1000000                              52184.073      20575940       52.184
10000000                            588740.639     239222227       58.874
100000000                          6800782.635    2695845640       68.008

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
100                                      3.134           832       31.342
1000                                    56.056         14329       56.056
10000                                  798.514        202673       79.851
100000                               10380.701       2605785      103.807
1000000                             126564.877      31763249      126.565
10000000                           1498201.608     374313526      149.820
100000000                         17555403.126    4308330381      175.554

NOTES:
[1]   This is the raw ForSort merge algorithm implemented in its most basic manner
      It is sort-stable and in-place, but isn't using any techniques to speed it up.
[2]    This is the Unstable Algorithm, but given a workspace of 12.5% (ie. 1/8th) of
      the size of the data to be sorted, which makes the algorithm be Sort Stable.
[3]   Forsort In-Place Stable uses Insertion Sort Only up to 79 items
[4]   Bentley required gcc for best results, all other algorithms were fastest with clang
```

What about on mostly sorted data sets?


Here's the speeds when given data that has been disordered by 25% (ie. 1 in 4 items are out of order)

```
        ALGORITHM                    TIME       COMPARES (M)
ForSort Workspace Stable            0.423s        146.613
ForSort No Workspace Unstable       0.434s        154.652
ForSort In-Place Stable             0.452s        155.582
TimSort                             0.585s        139.026
WikiSort                            0.639s        249.697
GrailSort In-Place                  0.666s        232.446
GLibC Qsort                         0.689s        218.019
Bentley/McIlroy QuickSort           0.702s        228.052
ForSort Basic                       0.859s        223.881
```

Here's the speeds when given data that has been disordered by 5% (ie. 1 in 20 items are out of order)

```
        ALGORITHM                    TIME       COMPARES (M)
ForSort Workspace Stable            0.193s         63.733
ForSort No Workspace Unstable       0.208s         70.062
TimSort                             0.217s         59.739
ForSort In-Place Stable             0.222s         72.413
WikiSort                            0.372s        204.729
Bentley/McIlroy QuickSort           0.354s        214.906
ForSort Basic                       0.370s        131.408
GLibC Qsort                         0.412s        199.491
GrailSort In-Place                  0.461s        201.531
```

And here are the results for 1% disordering (1 in 100 items out of order).

Here TimSort pulls a small lead due to the way it processes the input data.  The In-Place
Stable ForSort is still very close though

```
        ALGORITHM                    TIME       COMPARES (M)
TimSort                             0.092s         29.032
ForSort Workspace Stable            0.110s         35.013
ForSort No Workspace Unstable       0.114s         36.419
ForSort In-Place Stable             0.126s         39.936
ForSort Basic                       0.211s         93.412
WikiSort                            0.251s        161.786
Bentley/McIlroy QuickSort           0.298s        212.017
GLibC Qsort                         0.336s        178.719
GrailSort In-Place                  0.354s        167.276
```

What about reversed data ordering (still with potential duplicates)?  ForSort
doesn't make any explicit checks for fully reversed ordering, but it still runs quickly.

```
        ALGORITHM                    TIME       COMPARES (M)
ForSort No Workspace Unstable       0.132s         57.187
TimSort                             0.134s         39.874
ForSort Workspace Stable            0.136s         60.684
ForSort In-Place Stable             0.146s         60.038
ForSort Basic                       0.148s         53.161
WikiSort                            0.159s         63.018
GrailSort In-Place                  0.214s         84.024
GLibC Qsort                         0.311s        120.241
Bentley/McIlroy QuickSort           0.405s        264.937
```

...and finally when using wholly sorted data, to demonstrate adaptability.
The Stable In-Place algorithm still needs to extract and prepare a working
space, even though it never uses it, which incurs an overhead here.

```
        ALGORITHM                    TIME       COMPARES (M)
TimSort                             0.009s          9.999
ForSort Workspace Stable            0.013s         10.000
ForSort No Workspace Unstable       0.014s         10.001
ForSort Basic                       0.017s          9.999
WikiSort                            0.023s         20.128
ForSort In-Place Stable             0.024s         12.480
GrailSort In-Place                  0.183s         79.283
GLibC Qsort                         0.212s        114.434
Bentley/McIlroy QuickSort           0.259s        209.620
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
