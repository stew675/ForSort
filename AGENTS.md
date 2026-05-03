# FORSORT - ALGORITHM ANALYSIS & IMPLEMENTATION DOCUMENTATION


## Research Summary

This document provides a comprehensive analysis of the ForSort codebase, including its algorithms, architecture, build system, and usage. The analysis covered all major source files, header files, Makefile, benchmark system, and test infrastructure.

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Key Findings

### Algorithm Architecture

ForSort is a family of adaptive, in-place, stable merge-sort style algorithms with O(n log n) time complexity and O(log n) space complexity. The implementation follows a modular architecture with typed and untyped variants generated through C preprocessor metaprogramming.

### Core Components:

1. forsort.c - Main implementation dispatcher
2. forsort.h - Public API header with three main functions:
      ◦ forsort_basic() - Base stable merge sort
      ◦ forsort_inplace() - Adaptive merge sort with optional workspace
      ◦ forsort_stable() - Fully stable sort using unique key extraction

### Technical Highlights:

• Uses C preprocessor macro metaprogramming for type-specific optimizations
• Supports multiple data sizes: uint128_t, uint64_t, uint32_t, and generic untyped
• Implements custom in-place block rotation with AVX512 acceleration
• Features adaptive merging with sprinting/galloping behavior (TimSort-inspired)

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Algorithms

### 1. ForSort Basic (forsort_basic)

File: src/forsort.c:391-406, include/forsort-basic.h

Description: A basic top-down stable, in-place merge sort using the rotate_merge_in_place() function.

Algorithm:
• Uses hybrid top-down/bottom-up approach
• For small arrays (< 24 items), falls back to insertion sort
• Employs a 29:71 skewed split ratio for better merge performance
• Uses rotate_block() for in-place merging

Key Constants:
• BASIC_INSERT_MAX = 24 - Threshold for insertion sort fallback
• BASIC_SKEW = 29 - 29:71 split ratio

Complexity:
• Time: O(n log n)
• Space: O(log n) - stack for recursion

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

### 2. ForSort In-Place (forsort_inplace)

File: src/forsort.c:428-456, include/forsort-merge.h:870-901

Description: Moderately advanced adaptive merge-sort with optional external workspace support.

Algorithm:
• When workspace provided: uses merge_sort_in_place() with work buffer
• When no workspace: uses 1/6th of array as self-contained workspace
• Recursively sorts workspace until all data is sorted
• Not stable when using self-allocated workspace unless all first 1/6th items have unique keys

Key Constants:
• WSRATIO = 6 - Workspace ratio for self-allocation

Complexity:
• Time: O(n log n)
• Space: O(log n) - workspace-based or stack-based

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

### 3. ForSort Stable (forsort_stable)

File: src/forsort.c:409-424, include/forsort-stable.h

Description: Fully stable sort using unique key extraction mechanism.

Algorithm:
1. Extracts unique values from array portion (slow initial phase)
2. Uses extracted uniques as workspace for merge_sort_in_place()
3. Maintains sorted duplicates list
4. Repeatedly extracts more uniques until sufficient workspace gathered
5. Merges duplicates with sorted workspace at end

Key Constants:
• STABLE_WSRATIO = 29 - Workspace target ratio
• MAX_DUPS = 27 - Maximum merged duplicate blocks

Unique Extraction (extract_uniques):
• Divide-and-conquer approach
• O(n) time complexity with moderate constant factor
• Identifies duplicate runs and moves them to left side
• Unique items remain on right side as workspace candidates

Complexity:
• Time: O(n log n) average, degrades to O(n²) for highly degenerate inputs
• Space: O(log n)

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

### 4. Block Rotation (rotate_block)

File: include/forsort-rotate.h

Algorithm: "Triple Shift Block Rotation" - a novel variant of Gries-Mills block swap.

Approach:
1. Uses overlap between blocks as in-place buffer for streaming transfer
2. AVX512-optimized 64-byte transfers when available
3. Fallback to stack-buffered rotation for small overlaps
4. Supports both ring_positive (forward) and ring_negative (backward) rotations

Optimizations:
• MIN_STREAM_SIZE = 1024 - Minimum overlap for streaming
• Stack-allocated 256-byte buffer for small rotations
• Three-way rotation using AVX512 registers

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

### 5. Sprints/Galloping Merge

File: include/forsort-merge.h:75-204

Algorithm: Inspired by TimSort's galloping mode.

Mechanism:
• sprint_left() - Binary search with exponential probing for left-side items
• sprint_right() - Binary search with exponential probing for right-side items
• Activates after SPRINT_ACTIVATE = 7 consecutive wins
• Deactivates with SPRINT_EXIT_PENALTY = 2 penalty

Purpose: Rapidly skip over runs of items that belong on the same side of merge

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Build System

### Makefile (Makefile)

Compilation Flags:
CC= clang
CC_OPT_FLAGS= -O3 -mtune=native -flto -fno-semantic-interposition -mavx512f
LD_OPT_FLAGS= -O3 -mtune=native -flto -fno-semantic-interposition -mavx512f
DEBUG_FLAGS= -Wall

Source Files:
• forsort.c - Main implementation dispatcher
• main.c - Test harness
• nqsort.c - Bentley/McIlroy Quick Sort (third-party)
• timsort.c - TimSort implementation (third-party)
• blitsort.c - Blit Sort (third-party)
• WikiSort.c - WikiSort implementation (third-party)
• timsort_r.c - Reentrant TimSort variant
• grail_sort.c - Grail Sort implementation

Header Dependencies:
• forsort-rotate.h, forsort-insert.h, forsort-basic.h, forsort-merge.h, forsort-stable.h

Build Targets:
• make - Build ts executable
• make clean - Clean build artifacts
• make benchmark - Run benchmark suite
• make results - Generate Results.md from benchmark data

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Usage

### Command Line Interface

The ts (TestSort) executable provides comprehensive testing capabilities:

./ts [options] <sorttype> <num>

Options:
┌─────────────┬──────────────────────────────────────────┐
│ Option      │ Description                              │
├─────────────┼──────────────────────────────────────────┤
│ -a <seed>   │ Random seed (default=1, 0=random)        │
├─────────────┼──────────────────────────────────────────┤
│ -d <0..100> │ Disorder factor percentage (default=100) │
├─────────────┼──────────────────────────────────────────┤
│ -f          │ Full range keys (0..UINT32_MAX)          │
├─────────────┼──────────────────────────────────────────┤
│ -l <num>    │ Key range 0..(num-1)                     │
├─────────────┼──────────────────────────────────────────┤
│ -l n        │ Key range equals element count           │
├─────────────┼──────────────────────────────────────────┤
│ -o          │ Fully ordered dataset                    │
├─────────────┼──────────────────────────────────────────┤
│ -r          │ Reverse dataset order                    │
├─────────────┼──────────────────────────────────────────┤
│ -u          │ All values unique                        │
├─────────────┼──────────────────────────────────────────┤
│ -v          │ Verbose output                           │
├─────────────┼──────────────────────────────────────────┤
│ -x          │ Extended testing mode                    │
├─────────────┼──────────────────────────────────────────┤
│ -w <num>    │ Workspace size in elements               │
└─────────────┴──────────────────────────────────────────┘

Sort Types:
┌──────┬────────────────────────┬──────────┬──────────┐
│ Code │ Algorithm              │ Stable   │ In-Place │
├──────┼────────────────────────┼──────────┼──────────┤
│ fb   │ ForSort Basic          │ Yes      │ Yes      │
├──────┼────────────────────────┼──────────┼──────────┤
│ fi   │ ForSort In-Place       │ No       │ Yes      │
├──────┼────────────────────────┼──────────┼──────────┤
│ fs   │ ForSort Stable         │ Yes      │ Yes      │
├──────┼────────────────────────┼──────────┼──────────┤
│ fw   │ ForSort With Workspace │ Yes      │ Yes      │
├──────┼────────────────────────┼──────────┼──────────┤
│ is   │ Insertion Sort         │ Yes      │ Yes      │
├──────┼────────────────────────┼──────────┼──────────┤
│ gs   │ Grail Sort             │ Yes      │ Yes      │
├──────┼────────────────────────┼──────────┼──────────┤
│ gq   │ GLibc Quick Sort       │ Unstable │ Yes      │
├──────┼────────────────────────┼──────────┼──────────┤
│ nq   │ Bentley/McIlroy Quick  │ No       │ Yes      │
├──────┼────────────────────────┼──────────┼──────────┤
│ ti   │ TimSort                │ Yes      │ No       │
├──────┼────────────────────────┼──────────┼──────────┤
│ wi   │ WikiSort               │ Yes      │ Yes      │
└──────┴────────────────────────┴──────────┴──────────┘

Example:
./ts -a 5 -d 5 -r fs 1000000

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Performance Characteristics

### Benchmark Results Summary

┌───────────┬───────────────────┬───────────┬──────────────────────────────────────┐
│ Sort Type │ 1M Items Avg (ns) │ Stability │ Notes                                │
├───────────┼───────────────────┼───────────┼──────────────────────────────────────┤
│ fw        │ 16.172            │ Stable    │ Best overall with workspace          │
├───────────┼───────────────────┼───────────┼──────────────────────────────────────┤
│ fi        │ 17.377            │ Unstable  │ Fastest in-place                     │
├───────────┼───────────────────┼───────────┼──────────────────────────────────────┤
│ fs        │ 17.592            │ Stable    │ Fully stable in-place                │
├───────────┼───────────────────┼───────────┼──────────────────────────────────────┤
│ ti        │ 32.167            │ Stable    │ TimSort with workspace               │
├───────────┼───────────────────┼───────────┼──────────────────────────────────────┤
│ wi        │ 32.782            │ Stable    │ WikiSort in-place                    │
├───────────┼───────────────────┼───────────┼──────────────────────────────────────┤
│ gs        │ 37.435            │ Stable    │ GrailSort in-place                   │
├───────────┼───────────────────┼───────────┼──────────────────────────────────────┤
│ nq        │ 35.384            │ Unstable  │ QuickSort in-place                   │
├───────────┼───────────────────┼───────────┼──────────────────────────────────────┤
│ fb        │ 39.831            │ Stable    │ Basic ForSort                        │
├───────────┼───────────────────┼───────────┼──────────────────────────────────────┤
│ gq        │ 44.368            │ Unstable  │ GLibc QuickSort                      │
├───────────┼───────────────────┼───────────┼──────────────────────────────────────┤
│ is        │ 2478.0            │ Stable    │ Insertion Sort (skipped for large n) │
└───────────┴───────────────────┴───────────┴──────────────────────────────────────┘

### Key Observations:

1. ForSort variants consistently outperform competitors
2. Workspace-enabled algorithms (fw) perform best
3. Performance gaps widen with larger datasets
4. Stable ForSort (fs) maintains competitive performance
5. Near-sorted data shows significant speedups

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Source Code Structure

ForSort/
├── Makefile                    # Build system
├── benchmark.sh               # Benchmark automation
├── generate_results.py        # Results generation
├── README.md                  # Project overview
├── RESULTS.md                 # Benchmark results
├── forsort-viz-sound.html     # Visualization/sonification
├── src/
│   ├── forsort.c              # Main dispatcher
│   ├── main.c                 # Test harness (749 lines)
│   ├── nqsort.c               # Bentley/McIlroy QuickSort
│   ├── timsort.c              # TimSort implementation
│   ├── timsort_r.c            # Reentrant variant
│   ├── blitsort.c             # Blit Sort
│   ├── WikiSort.c             # WikiSort
│   └── grail_sort.c           # Grail Sort
├── include/
│   ├── forsort.h              # Public API
│   ├── forsort.h              # Common definitions
│   ├── forsort-rotate.h       # Block rotation (405 lines)
│   ├── forsort-insert.h       # Insertion sort (496 lines)
│   ├── forsort-basic.h        # Basic merge sort (447 lines)
│   ├── forsort-merge.h        # Advanced merge (917 lines)
│   ├── forsort-stable.h       # Stable sort (588 lines)
│   ├── blitsort.h             # Blit Sort header
│   ├── grail_sort.h           # Grail Sort header
│   ├── timsort.h              # TimSort header
│   └── WikiSort.h             # WikiSort header
└── obj/                       # Build output directory

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## API Documentation

### Public Interface (forsort.h)

void forsort_basic(void *base, size_t n, size_t size,
                  int (*is_lt)(const void *, const void *));

void forsort_inplace(void *base, size_t n, size_t size,
                  int (*is_lt)(const void *, const void *),
                  void *workspace, size_t worksize);

void forsort_stable(void *base, size_t n, size_t size,
                  int (*is_lt)(const void *, const void *));

Parameters:
• base - Pointer to array to sort
• n - Number of elements
• size - Size of each element in bytes
• is_lt - Comparison function returning true if first < second
• workspace - Optional work buffer (NULL for auto-allocation)
• worksize - Workspace size in elements

Comparison Function Signature:
int is_lt(const void *a, const void *b);
// Returns non-zero if *a < *b, zero otherwise

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Algorithmic Insights

### Why Three Variants?

1. forsort_basic: Simplest implementation for testing base functionality
2. forsort_inplace: Adaptive performance optimization with workspace trade-offs
3. forsort_stable: Fully stable variant using unique key extraction

### The Unique Key Extraction Mechanism

The stable sort uses an innovative approach to create workspace in-place:

1. Extract Phase: Scan array, identify duplicates (left) and uniques (right)
2. Use Phase: Use unique items as workspace for main merge algorithm
3. Repeat: If insufficient uniques, extract more from remaining data
4. Merge Phase: Combine all duplicate blocks with final workspace

This approach enables:
• Fully stable sorting in-place
• Adaptive workspace generation
• Near-O(n) duplicate handling for low-entropy data

### AVX512 Acceleration

The block rotation implementation uses AVX512 registers when compiled with -mavx512f:

• 64-byte register transfers for large block operations
• Automatic fallback to scalar operations for small overlaps
• 3-way rotation optimization for ring operations

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Testing & Validation

### Test Variants (8 scenarios):

1. fully_random - Completely randomized data
2. 25_percent_disordered - 75% ordered, 25% disorder
3. 10_percent_disordered - 90% ordered, 10% disorder
4. 5_percent_disordered - 95% ordered, 5% disorder
5. 1_percent_disordered - 99% ordered, 1% disorder
6. fully_ordered - Pre-sorted data
7. reverse_ordered_duplicates - Reverse with duplicates
8. reverse_ordered_uniques - Reverse with unique values

### Dataset Sizes:
100, 1,000, 10,000, 100,000, 1,000,000, 10,000,000, 100,000,000 items

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Implementation Details

### Typed vs Untyped Generics

The codebase uses C preprocessor for type-generic programming:

// In forsort.c
#define ES 1
#define VAR uint64_t
#include "forsort-rotate.h"  // Type-specific instantiation
#undef VAR
#define VAR char
#define UNTYPED                // Generic byte-wise operations
#include "forsort-rotate.h"
#undef UNTYPED

This generates type-specific versions for:
• uint128_t (16-byte)
• uint64_t (8-byte)
• uint32_t (4-byte)
• char (generic byte-wise)

### Memory Layout

• forsort_stable: duplicates | uniques | remaining
• forsort_inplace (auto): workspace | sorted_data | remaining
• forsort_basic: In-place divide and conquer

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Recommendations for Use

1. For maximum performance: Use forsort_stable() with pre-allocated workspace
2. For strict in-place constraints: Use forsort_stable() without workspace
3. For nearly-sorted data: Any ForSort variant will excel
4. For stability requirements: Use forsort_stable() or forsort_basic()
5. For unstable sorting: Use forsort_inplace() without workspace

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Performance Optimization Notes

1. Compiler optimizations: Use -O3 -flto -mtune=native -mavx512f
2. Cache locality: Block sizes designed for CPU cache hierarchy
3. Branch prediction: Minimized branches with conditional moves
4. Memory access patterns: Sequential with prefetch hints
5. AVX512: Enabled for 64-byte aligned operations

───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────


## Historical Context

The ForSort algorithm evolved from:
• Merge Sort foundations
• Insertion Sort for small arrays
• Block Sort concepts
• Grail Sort techniques
• Powermerge paper (https://koreascience.kr/article/CFKO200311922203087.pdf)
• StackOverflow insights (https://stackoverflow.com/a/68603446/16534062)

The key innovations are:
• Triple Shift Block Rotation algorithm
• Adaptive unique key extraction
• Sprint-based galloping merge

