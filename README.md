# ForSort

ForSort - An adaptive, O(nlogn) time, O(logn) space, stable, in-place, sorting algorithm


Author: Stew Forster (stew675@gmail.com)

Copyright (C) 2021-2025


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


# Speed

ForSort is fast.  Here's a comparison of the time taken to sort 10,000,000
random items on an AMD 9800X3D CPU

```
        ALGORITHM                    TIME       COMPARES (M)
GLibC Qsort                         1.103s        220.067
Bentley/McIlroy QuickSort           0.938s        237.131
ForSort Basic*                      1.488s        374.199
ForSort In-Place Stable             0.581s        238.844
ForSort No Workspace Unstable       0.555s        228.655
ForSort Workspace Stable**          0.530s        224.526
GrailSort In-Place                  0.836s        236.936
TimSort                             1.041s        213.811
WikiSort                            0.994s        266.882

*  This is the raw ForSort merge algorithm implemented in its most basic manner
   It is sort-stable and in-place, but isn't using any techniques to speed it up.
** This is the Unstable Algorithm, but given a workspace of 25% of the size of the
   data to be sorted, which makes the algorithm be Sort Stable.
```

What about on mostly sorted data sets?


Here's the speeds when given data that has been disordered by 25% (ie. 1 in 4 items are out of order)

```
        ALGORITHM                    TIME       COMPARES (M)
GLibC Qsort                         0.689s        218.019
Bentley/McIlroy QuickSort           0.702s        228.052
ForSort Basic                       0.859s        223.881
ForSort In-Place Stable             0.452s        155.582
ForSort No Workspace Unstable       0.434s        154.652
ForSort Workspace Stable            0.423s        146.613
GrailSort In-Place                  0.666s        232.446
TimSort                             0.585s        139.026
WikiSort                            0.639s        249.697
```

Here's the speeds when given data that has been disordered by 5% (ie. 1 in 20 items are out of order)

```
        ALGORITHM                    TIME       COMPARES (M)
GLibC Qsort                         0.412s        199.491
Bentley/McIlroy QuickSort           0.354s        214.906
ForSort Basic                       0.370s        131.408
ForSort In-Place Stable             0.222s         72.413
ForSort No Workspace Unstable       0.208s         70.062
ForSort Workspace Stable            0.193s         63.733
GrailSort In-Place                  0.461s        201.531
TimSort                             0.217s         59.739
WikiSort                            0.372s        204.729
```

And here are the results for 1% disordering (1 in 100 items out of order).  Here's where
TimSort can pull a small lead due to the way it processes the input data.  The In-Place
Stable ForSort is still very close though

```
        ALGORITHM                    TIME       COMPARES (M)
GLibC Qsort                         0.336s        178.719
Bentley/McIlroy QuickSort           0.298s        212.017
ForSort Basic                       0.211s         93.412
ForSort In-Place Stable             0.126s         39.936
ForSort No Workspace Unstable       0.114s         36.419
ForSort Workspace Stable            0.110s         35.013
GrailSort In-Place                  0.354s        167.276
TimSort                             0.092s         29.032
WikiSort                            0.251s        161.786
```

What about reversed data ordering (still with potential duplicates)?  ForSort
doesn't make any explicit checks for fully reversed ordering, but it still runs quickly.

```
        ALGORITHM                    TIME       COMPARES (M)
GLibC Qsort                         0.311s        120.241
Bentley/McIlroy QuickSort           0.405s        264.937
ForSort Basic                       0.148s         53.161
ForSort In-Place Stable             0.146s         60.038
ForSort No Workspace Unstable       0.132s         57.187
ForSort Workspace Stable            0.136s         60.684
GrailSort In-Place                  0.214s         84.024
TimSort                             0.134s         39.874
WikiSort                            0.159s         63.018
```

...and finally when using wholly sorted data, to demonstrate adaptability.
The Stable In-Place algorithm still needs to extract and prepare a working
space, even though it never uses it, which incurs a ~25% overhead here.

```
        ALGORITHM                    TIME       COMPARES (M)
GLibC Qsort                         0.212s        114.434
Bentley/McIlroy QuickSort           0.259s        209.620
ForSort Basic                       0.017s          9.999
ForSort In-Place Stable             0.024s         12.480
ForSort No Workspace Unstable       0.014s         10.001
ForSort Workspace Stable            0.013s         10.000
GrailSort In-Place                  0.183s         79.283
TimSort                             0.009s          9.999
WikiSort                            0.023s         20.128
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
overflow in short order.  That algorithm is implemented by shift_merge_in_place()

I worked to solve those issues, but the code grew in complexity, and then
started to slow down to point of losing all its benefits.  While messing
about with solutions, I created what I call split_merge_in_place().  To date
I've not found an algorithm that implements exactly what it does, but it
does have a number of strong similarities to what BlockSort does.

Unlike shift_merge_in_place(), the split_merge_in_place() algorithm doesn't
bury itself in the details of
finding the precise optimal place to split a block being merged, but rather
uses a simple division algorithm to choose where to split.  In essence it
takes a "divide and conquer" approach to the problem of merging two arrays
together in place, and deposits fixed sized chunks, saves where that chunk
is on a work stack, and then continues depositing chunks.  When all chunks
are placed, it goes back and splits each one up again in turn into smaller
chunks, and continues.

In doing so, it achieves a stack requirement of just 15*log16(N) split points,
where N is the size of the left side array being merged.  The size of the
right-side array doesn't matter to the split_merge_in_place algorithm.  This stack
growth is very slow.  A stack size of 120 can account for over 10^12 items,
and a stack size of 240 can track 2^64 items.

This makes it an O(logN) space complexity algorithm, but there are a good
number of of O(1) algorithms that allocate a much larger amount of static
memory than ForSort ever will, and those algorithms still call themselves
O(1).  The devil is, as always, in the details.

split_merge_in_place() is about 30% slower than shift_merge_in_place() in
practise though, but it makes for an excellent fallback to the faster
shift_merge_in_place() algorithm for when that algorithm gets lost in the
weeds of chopping up chunks and runs its work stack out of memory.

I then read about how GrailSort and BlockSort use unique items as a work
space, which is what allows those algorithms to achieve sort stability.  I
didn't look too deeply into how either of those algorithms extract unique
items, preferring the challenge of coming up with my own solution to that
problem.  extract\_uniques() is my solution that also takes a divide and
conquer approach to split an array of items into uniques and duplicates,
and then uses a variant of the Gries-Mills Block Swap algorithm to quickly
move runs of duplicates into place:

Ref: https://en.wikipedia.org/wiki/Block_swap_algorithms

extract\_uniques() moves all duplicates, which are kept in sorted order, to
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
