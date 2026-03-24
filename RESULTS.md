# ForSort Benchmark Results

## Overview

This document contains comprehensive benchmark results for all sorting algorithms implemented in the ForSort library. Results are organized by dataset size and test variant with intelligent ranking and cross-category analysis.

**Test Configuration:**
- Random seed: 42
- All tests run with `-a 42` flag for reproducibility
- Workspace-enabled variants use `-w 1`


## Sort Types

| Code | Name | Stability |
|------|------|-----------|
| fb | ForSort Basic Fully In-Place | Stable |
| fi | ForSort Unstable Fully In-Place | Unstable |
| fs | ForSort Stable Fully In-Place | Stable |
| fw | ForSort With Allocated Workspace | Stable |
| gs | GrailSort Fully In-Place | Stable |
| gq | GLibc Quick Sort Fully In-Place | Unstable |
| nq | Bentley/McIlroy Quick Sort In-Place | Unstable |
| ti | TimSort with Allocated Workspace | Stable |
| wi | WikiSort Fully In-Place | Stable |
| is | Insertion Sort Fully In-Place | Stable |


## Test Variants

| Variant | Description |
|---------|-------------|
| fully_random | Fully Random Data |
| 25_percent_disordered | 75% Ordered, 25% disorder |
| 10_percent_disordered | 90% Ordered, 10% disorder |
| 5_percent_disordered | 95% Ordered, 5% disorder |
| 1_percent_disordered | 99% Ordered, 1% disorder |
| fully_ordered | Fully Ordered |
| reverse_ordered_duplicates | Reverse Ordered with Duplicate Values |
| reverse_ordered_uniques | Reverse Ordered with Unique Values |


## Cross-Category Analysis

### Overall Performance Ranking (Weighted Average)

| Rank | Sort Type | Name | Weighted Rank | Wins | Top 3 |
|------|-----------|------|---------------|------|-------|
| 1 | **fw** | ForSort With Allocated Workspace | 1.95 | 27 | 39 |
| 2 | **fi** | ForSort Unstable Fully In-Place | 2.65 | 1 | 36 |
| 3 | **fs** | ForSort Stable Fully In-Place | 3.89 | 0 | 32 |
| 4 | ti | TimSort with Allocated Workspace | 4.36 | 21 | 24 |
| 5 | wi | WikiSort Fully In-Place | 5.41 | 3 | 12 |
| 6 | fb | ForSort Basic Fully In-Place | 6.27 | 0 | 14 |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 6.40 | 0 | 0 |
| 8 | gs | GrailSort Fully In-Place | 7.46 | 0 | 3 |
| 9 | is | Insertion Sort Fully In-Place | 7.67 | 4 | 8 |
| 10 | gq | GLibc Quick Sort Fully In-Place | 8.95 | 0 | 0 |

*Rankings based on weighted average finish position across all test categories. Reversed test scenarios weighted at 0.05x, all others at 1.0x. Skipped results (e.g., Insertion Sort for large datasets) counted as last place.*

### Recommendations by Use Case

- **Best Stable Sort:** fs (ForSort Stable Fully In-Place) - Avg: 18.541 ns/item (1M-100M items)
- **Best Unstable Sort:** fi (ForSort Unstable Fully In-Place) - Avg: 21.032 ns/item (1M-100M items)
- **Best for Nearly-Sorted Data:** fw (ForSort With Allocated Workspace) - Avg: 6.838 ns/item
- **Best for Random Data:** fw (ForSort With Allocated Workspace) - Avg: 23.480 ns/item


## Size Winners Summary

| Dataset Size | 1st Place | Avg (ns/item) | 2nd Place | Avg (ns/item) | 3rd Place | Avg (ns/item) |
|--------------|-----------|---------------|-----------|---------------|-----------|---------------|
| 100 | **fw**<br>ForSort With Allocated Workspace | 6.463 | **wi**<br>WikiSort Fully In-Place | 7.060 | **fi**<br>ForSort Unstable Fully In-Place | 7.223 |
| 1000 | **fw**<br>ForSort With Allocated Workspace | 8.772 | **fi**<br>ForSort Unstable Fully In-Place | 10.042 | **fs**<br>ForSort Stable Fully In-Place | 10.185 |
| 10000 | **fw**<br>ForSort With Allocated Workspace | 11.662 | **fs**<br>ForSort Stable Fully In-Place | 12.236 | **fi**<br>ForSort Unstable Fully In-Place | 12.925 |
| 100000 | **fs**<br>ForSort Stable Fully In-Place | 14.126 | **fw**<br>ForSort With Allocated Workspace | 14.454 | **fi**<br>ForSort Unstable Fully In-Place | 15.363 |
| 1000000 | **fs**<br>ForSort Stable Fully In-Place | 15.666 | **fw**<br>ForSort With Allocated Workspace | 16.579 | **fi**<br>ForSort Unstable Fully In-Place | 17.675 |
| 10000000 | **fs**<br>ForSort Stable Fully In-Place | 17.772 | **fw**<br>ForSort With Allocated Workspace | 18.824 | **fi**<br>ForSort Unstable Fully In-Place | 20.183 |
| 100000000 | **fs**<br>ForSort Stable Fully In-Place | 22.183 | **fw**<br>ForSort With Allocated Workspace | 24.081 | **fi**<br>ForSort Unstable Fully In-Place | 25.239 |


## Worst-Case Performance

This section identifies which algorithm has the best *worst-case* performance across all test variants except reverse-ordered scenarios (statistical outliers rarely seen in practice). Lower rank indicates better performance in the worst scenario encountered.

| Rank | Sort Type | Name | Worst Rank | Scenarios |
|------|-----------|------|------------|-----------|
| 1 | **fi** | ForSort Unstable Fully In-Place | 5 | 2 |
| 2 | **fw** | ForSort With Allocated Workspace | 6 | 2 |
| 3 | **fs** | ForSort Stable Fully In-Place | 7 | 2 |
| 4 | wi | WikiSort Fully In-Place | 7 | 10 |
| 5 | ti | TimSort with Allocated Workspace | 7 | 12 |
| 6 | gs | GrailSort Fully In-Place | 9 | 13 |
| 7 | fb | ForSort Basic Fully In-Place | 10 | 2 |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 10 | 2 |
| 9 | is | Insertion Sort Fully In-Place | 10 | 9 |
| 10 | gq | GLibc Quick Sort Fully In-Place | 10 | 17 |

*Worst rank indicates the highest (poorest) position achieved across all test categories. Lower worst rank = better worst-case performance.*


## Summary by Dataset Size and Test Variant

### Fully Random

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****15.613** | *****16.575** | *****18.473** | *****22.811** | *****25.563** | *****29.007** | *****36.316** |
| fi | ****18.049** | ****20.640** | ****22.800** | ****26.030** | ****29.678** | ****33.149** | ****39.335** |
| fs | ***23.018** | ***23.668** | ***23.849** | ***27.248** | ***29.892** | ***34.083** | ***42.307** |
| gs | 29.642 | 38.028 | 47.123 | 54.088 | 63.430 | 75.376 | 90.196 |
| wi | 21.458 | 32.976 | 50.223 | 60.256 | 73.756 | 89.125 | 104.92 |
| nq | 24.508 | 37.101 | 50.375 | 62.143 | 73.915 | 86.332 | 98.438 |
| ti | 27.642 | 43.668 | 59.498 | 73.206 | 88.149 | 104.96 | 120.74 |
| gq | 32.521 | 48.706 | 64.757 | 77.331 | 92.929 | 110.46 | 127.09 |
| fb | 29.557 | 48.210 | 69.245 | 86.789 | 105.49 | 124.58 | 147.04 |
| is | 27.480 | 49.297 | 116.78 | 962.84 | 13325.2 | - | - |

### 25 Percent Disordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****10.167** | *****16.994** | *****20.938** | *****23.907** | *****26.357** | *****28.787** | *****34.307** |
| fi | ****11.137** | ****18.878** | ****22.563** | ****25.299** | ****27.527** | ****30.216** | ****34.592** |
| fs | ***14.877** | ***21.537** | ***24.315** | ***26.594** | ***28.737** | ***31.185** | ***36.421** |
| nq | 13.411 | 20.806 | 28.878 | 36.683 | 44.802 | 52.514 | 60.589 |
| wi | 10.962 | 19.080 | 30.154 | 38.629 | 45.998 | 55.754 | 64.624 |
| ti | 13.644 | 25.020 | 35.369 | 42.749 | 49.135 | 58.794 | 67.324 |
| gs | 15.914 | 25.690 | 33.611 | 42.577 | 50.730 | 60.381 | 72.027 |
| gq | 18.149 | 29.871 | 39.898 | 49.087 | 57.422 | 69.404 | 81.187 |
| fb | 15.554 | 30.995 | 42.985 | 54.169 | 62.620 | 72.494 | 83.668 |
| is | 12.031 | 26.692 | 40.955 | 128.61 | 1255.5 | - | - |

### 10 Percent Disordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****4.822** | *****10.869** | *****15.480** | *****18.546** | *****19.414** | *****21.241** | *****25.569** |
| fi | ****5.193** | ****12.764** | ****16.967** | ****19.067** | ****20.610** | ****22.242** | ****25.609** |
| fs | ***6.746** | ***12.534** | ***17.419** | ***19.816** | ***20.730** | ***22.797** | ***26.656** |
| ti | 6.848 | 13.102 | 19.606 | 23.951 | 27.229 | 30.722 | 35.490 |
| nq | 8.576 | 13.101 | 18.599 | 24.137 | 29.585 | 34.811 | 40.307 |
| wi | 5.382 | 11.522 | 19.168 | 25.338 | 30.790 | 38.729 | 46.483 |
| fb | 5.759 | 15.406 | 23.331 | 29.855 | 34.397 | 40.316 | 46.928 |
| gs | 9.497 | 15.115 | 23.314 | 30.965 | 39.475 | 48.321 | 59.842 |
| gq | 10.187 | 18.931 | 27.166 | 32.441 | 40.056 | 47.670 | 57.400 |
| is | 4.622 | 14.772 | 23.660 | 37.755 | 190.29 | - | - |

### 5 Percent Disordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****3.332** | *****6.500** | *****11.611** | *****14.560** | *****15.203** | *****16.759** | *****20.535** |
| fi | ****3.243** | ****7.656** | ****12.815** | ****14.910** | ****16.101** | ****17.337** | ****20.276** |
| fs | ***4.210** | ***7.610** | ***12.983** | ***14.981** | ***16.519** | ***17.593** | ***20.762** |
| ti | 4.798 | 8.428 | 13.225 | 16.541 | 19.254 | 21.474 | 24.558 |
| fb | 3.413 | 9.057 | 15.805 | 20.450 | 24.102 | 27.915 | 32.537 |
| nq | 7.303 | 11.054 | 15.381 | 20.373 | 25.045 | 29.581 | 34.280 |
| wi | 3.654 | 7.597 | 15.089 | 20.582 | 25.866 | 31.983 | 40.065 |
| is | 2.733 | 8.508 | 19.788 | 27.011 | 70.275 | - | - |
| gq | 8.091 | 14.076 | 22.131 | 27.298 | 33.086 | 40.546 | 49.066 |
| gs | 7.797 | 11.298 | 18.286 | 25.513 | 34.272 | 43.034 | 54.319 |

### 1 Percent Disordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| ti | *****2.279** | *****3.599** | *****4.479** | *****6.433** | *****8.430** | *****9.061** | *****10.660** |
| fw | ****2.334** | ****2.033** | ****4.226** | ****6.928** | ****8.197** | ****9.319** | ****12.877** |
| fi | ***2.103** | ***2.291** | ***4.723** | ***7.444** | ***8.474** | ***9.486** | ***12.258** |
| fs | 2.855 | 3.204 | 4.998 | 7.662 | 8.505 | 9.601 | 12.655 |
| fb | 2.221 | 2.946 | 5.831 | 9.170 | 11.539 | 13.271 | 15.572 |
| is | 1.379 | 2.021 | 7.535 | 19.717 | 25.683 | - | - |
| wi | 2.499 | 3.320 | 6.640 | 12.954 | 17.726 | 22.519 | 29.706 |
| nq | 6.305 | 9.497 | 12.445 | 16.799 | 20.262 | 23.960 | 28.057 |
| gs | 6.549 | 8.503 | 11.253 | 15.773 | 24.292 | 32.872 | 43.103 |
| gq | 6.930 | 9.920 | 14.094 | 20.307 | 26.187 | 32.300 | 39.397 |

### Fully Ordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| ti | *****0.951** | *****0.813** | *****0.782** | *****0.779** | *****0.803** | *****0.803** | *****0.779** |
| fb | ****1.132** | ****0.993** | ****0.970** | ****0.874** | ****0.834** | ****0.806** | ****0.794** |
| is | ***1.084** | ***0.983** | ***0.976** | ***0.882** | ***0.836** | - | - |
| fi | 1.823 | 1.174 | 0.920 | 1.018 | 1.070 | 0.902 | 1.431 |
| fs | 1.283 | 1.185 | 1.168 | 1.165 | 1.284 | 1.262 | 1.190 |
| fw | 2.089 | 1.222 | 0.885 | 1.013 | 1.148 | 0.896 | 1.935 |
| wi | 2.240 | 2.542 | 2.531 | 2.413 | 2.558 | 2.005 | 2.280 |
| gs | 5.960 | 7.649 | 9.282 | 10.113 | 12.409 | 16.236 | 22.032 |
| gq | 6.707 | 9.300 | 11.758 | 13.875 | 16.527 | 19.960 | 23.645 |
| nq | 6.048 | 8.913 | 11.614 | 15.900 | 18.692 | 21.502 | 25.844 |

### Reverse Ordered Duplicates

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| ti | *****9.405** | *****9.705** | *****9.893** | *****10.056** | *****10.387** | *****12.322** | *****16.200** |
| wi | ****7.287** | ****7.754** | ****9.809** | ****11.335** | ****12.197** | ****15.504** | ****20.564** |
| fw | ***7.361** | ***8.221** | ***11.272** | ***14.312** | ***18.687** | ***22.613** | ***30.781** |
| gs | 15.004 | 13.550 | 14.256 | 15.023 | 17.521 | 20.103 | 27.204 |
| fi | 9.041 | 9.452 | 12.099 | 15.276 | 19.629 | 24.238 | 34.478 |
| fs | 15.127 | 10.693 | 12.100 | 14.462 | 18.486 | 24.444 | 35.912 |
| nq | 11.645 | 16.412 | 21.218 | 21.834 | 25.920 | 30.691 | 31.675 |
| fb | 17.477 | 19.834 | 21.683 | 24.120 | 28.259 | 32.767 | 53.605 |
| gq | 20.211 | 25.192 | 32.451 | 37.197 | 37.408 | 43.196 | 49.997 |
| is | 10.434 | 22.584 | 212.77 | 2434.3 | 31000.9 | - | - |

### Reverse Ordered Uniques

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| ti | *****1.070** | *****0.948** | *****0.912** | *****0.915** | *****0.985** | *****0.951** | *****1.048** |
| fb | ****1.179** | ****1.012** | ****1.018** | ****1.041** | ****1.072** | ****1.062** | ****1.238** |
| fs | ***1.265** | ***1.050** | ***1.052** | ***1.082** | ***1.176** | ***1.213** | ***1.564** |
| wi | 2.997 | 3.660 | 4.423 | 5.033 | 5.995 | 7.047 | 12.590 |
| gs | 6.245 | 7.651 | 9.412 | 10.704 | 13.603 | 16.296 | 22.748 |
| fw | 5.984 | 7.762 | 10.411 | 13.559 | 18.062 | 21.972 | 30.327 |
| fi | 7.191 | 7.478 | 10.517 | 13.857 | 18.308 | 23.894 | 33.934 |
| gq | 9.447 | 11.702 | 14.472 | 16.919 | 19.866 | 24.920 | 31.454 |
| nq | 11.498 | 17.069 | 22.470 | 21.707 | 26.443 | 31.630 | 30.852 |
| is | 9.000 | 22.736 | 210.84 | 2356.1 | 30667.4 | - | - |


## Performance Rankings

### 100 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 15.613 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 18.049 | 15.6% | No |
| 3 | **wi** | WikiSort Fully In-Place | 21.458 | 37.4% | Yes |
| 4 | fs | ForSort Stable Fully In-Place | 23.018 | 47.4% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 24.508 | 57.0% | No |
| 6 | is | Insertion Sort Fully In-Place | 27.480 | 76.0% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 27.642 | 77.0% | Yes |
| 8 | fb | ForSort Basic Fully In-Place | 29.557 | 89.3% | Yes |
| 9 | gs | GrailSort Fully In-Place | 29.642 | 89.9% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 32.521 | 108.3% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 10.167 | 0.0% | Yes |
| 2 | **wi** | WikiSort Fully In-Place | 10.962 | 7.8% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 11.137 | 9.5% | No |
| 4 | is | Insertion Sort Fully In-Place | 12.031 | 18.3% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 13.411 | 31.9% | No |
| 6 | ti | TimSort with Allocated Workspace | 13.644 | 34.2% | Yes |
| 7 | fs | ForSort Stable Fully In-Place | 14.877 | 46.3% | Yes |
| 8 | fb | ForSort Basic Fully In-Place | 15.554 | 53.0% | Yes |
| 9 | gs | GrailSort Fully In-Place | 15.914 | 56.5% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 18.149 | 78.5% | No |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort Fully In-Place | 4.622 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 4.822 | 4.3% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 5.193 | 12.4% | No |
| 4 | wi | WikiSort Fully In-Place | 5.382 | 16.4% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 5.759 | 24.6% | Yes |
| 6 | fs | ForSort Stable Fully In-Place | 6.746 | 46.0% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 6.848 | 48.2% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 8.576 | 85.5% | No |
| 9 | gs | GrailSort Fully In-Place | 9.497 | 105.5% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 10.187 | 120.4% | No |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort Fully In-Place | 2.733 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 3.243 | 18.7% | No |
| 3 | **fw** | ForSort With Allocated Workspace | 3.332 | 21.9% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 3.413 | 24.9% | Yes |
| 5 | wi | WikiSort Fully In-Place | 3.654 | 33.7% | Yes |
| 6 | fs | ForSort Stable Fully In-Place | 4.210 | 54.0% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 4.798 | 75.6% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 7.303 | 167.2% | No |
| 9 | gs | GrailSort Fully In-Place | 7.797 | 185.3% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 8.091 | 196.0% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort Fully In-Place | 1.379 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 2.103 | 52.5% | No |
| 3 | **fb** | ForSort Basic Fully In-Place | 2.221 | 61.1% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 2.279 | 65.3% | Yes |
| 5 | fw | ForSort With Allocated Workspace | 2.334 | 69.3% | Yes |
| 6 | wi | WikiSort Fully In-Place | 2.499 | 81.2% | Yes |
| 7 | fs | ForSort Stable Fully In-Place | 2.855 | 107.0% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 6.305 | 357.2% | No |
| 9 | gs | GrailSort Fully In-Place | 6.549 | 374.9% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 6.930 | 402.5% | No |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.951 | 0.0% | Yes |
| 2 | **is** | Insertion Sort Fully In-Place | 1.084 | 14.0% | Yes |
| 3 | **fb** | ForSort Basic Fully In-Place | 1.132 | 19.0% | Yes |
| 4 | fs | ForSort Stable Fully In-Place | 1.283 | 34.9% | Yes |
| 5 | fi | ForSort Unstable Fully In-Place | 1.823 | 91.7% | No |
| 6 | fw | ForSort With Allocated Workspace | 2.089 | 119.7% | Yes |
| 7 | wi | WikiSort Fully In-Place | 2.240 | 135.5% | Yes |
| 8 | gs | GrailSort Fully In-Place | 5.960 | 526.7% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 6.048 | 536.0% | No |
| 10 | gq | GLibc Quick Sort Fully In-Place | 6.707 | 605.3% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **wi** | WikiSort Fully In-Place | 7.287 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 7.361 | 1.0% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 9.041 | 24.1% | No |
| 4 | ti | TimSort with Allocated Workspace | 9.405 | 29.1% | Yes |
| 5 | is | Insertion Sort Fully In-Place | 10.434 | 43.2% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 11.645 | 59.8% | No |
| 7 | gs | GrailSort Fully In-Place | 15.004 | 105.9% | Yes |
| 8 | fs | ForSort Stable Fully In-Place | 15.127 | 107.6% | Yes |
| 9 | fb | ForSort Basic Fully In-Place | 17.477 | 139.8% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 20.211 | 177.4% | No |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 1.070 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.179 | 10.2% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.265 | 18.2% | Yes |
| 4 | wi | WikiSort Fully In-Place | 2.997 | 180.1% | Yes |
| 5 | fw | ForSort With Allocated Workspace | 5.984 | 459.3% | Yes |
| 6 | gs | GrailSort Fully In-Place | 6.245 | 483.6% | Yes |
| 7 | fi | ForSort Unstable Fully In-Place | 7.191 | 572.1% | No |
| 8 | is | Insertion Sort Fully In-Place | 9.000 | 741.1% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 9.447 | 782.9% | No |
| 10 | nq | Bentley/McIlroy Quick Sort In-Place | 11.498 | 974.6% | No |

### 1000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 16.575 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 20.640 | 24.5% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 23.668 | 42.8% | Yes |
| 4 | wi | WikiSort Fully In-Place | 32.976 | 99.0% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 37.101 | 123.8% | No |
| 6 | gs | GrailSort Fully In-Place | 38.028 | 129.4% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 43.668 | 163.5% | Yes |
| 8 | fb | ForSort Basic Fully In-Place | 48.210 | 190.9% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 48.706 | 193.9% | No |
| 10 | is | Insertion Sort Fully In-Place | 49.297 | 197.4% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 16.994 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 18.878 | 11.1% | No |
| 3 | **wi** | WikiSort Fully In-Place | 19.080 | 12.3% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort In-Place | 20.806 | 22.4% | No |
| 5 | fs | ForSort Stable Fully In-Place | 21.537 | 26.7% | Yes |
| 6 | ti | TimSort with Allocated Workspace | 25.020 | 47.2% | Yes |
| 7 | gs | GrailSort Fully In-Place | 25.690 | 51.2% | Yes |
| 8 | is | Insertion Sort Fully In-Place | 26.692 | 57.1% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 29.871 | 75.8% | No |
| 10 | fb | ForSort Basic Fully In-Place | 30.995 | 82.4% | Yes |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 10.869 | 0.0% | Yes |
| 2 | **wi** | WikiSort Fully In-Place | 11.522 | 6.0% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 12.534 | 15.3% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 12.764 | 17.4% | No |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 13.101 | 20.5% | No |
| 6 | ti | TimSort with Allocated Workspace | 13.102 | 20.5% | Yes |
| 7 | is | Insertion Sort Fully In-Place | 14.772 | 35.9% | Yes |
| 8 | gs | GrailSort Fully In-Place | 15.115 | 39.1% | Yes |
| 9 | fb | ForSort Basic Fully In-Place | 15.406 | 41.7% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 18.931 | 74.2% | No |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 6.500 | 0.0% | Yes |
| 2 | **wi** | WikiSort Fully In-Place | 7.597 | 16.9% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 7.610 | 17.1% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 7.656 | 17.8% | No |
| 5 | ti | TimSort with Allocated Workspace | 8.428 | 29.7% | Yes |
| 6 | is | Insertion Sort Fully In-Place | 8.508 | 30.9% | Yes |
| 7 | fb | ForSort Basic Fully In-Place | 9.057 | 39.3% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 11.054 | 70.1% | No |
| 9 | gs | GrailSort Fully In-Place | 11.298 | 73.8% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 14.076 | 116.6% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort Fully In-Place | 2.021 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 2.033 | 0.6% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 2.291 | 13.4% | No |
| 4 | fb | ForSort Basic Fully In-Place | 2.946 | 45.8% | Yes |
| 5 | fs | ForSort Stable Fully In-Place | 3.204 | 58.5% | Yes |
| 6 | wi | WikiSort Fully In-Place | 3.320 | 64.3% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 3.599 | 78.1% | Yes |
| 8 | gs | GrailSort Fully In-Place | 8.503 | 320.7% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 9.497 | 369.9% | No |
| 10 | gq | GLibc Quick Sort Fully In-Place | 9.920 | 390.8% | No |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.813 | 0.0% | Yes |
| 2 | **is** | Insertion Sort Fully In-Place | 0.983 | 20.9% | Yes |
| 3 | **fb** | ForSort Basic Fully In-Place | 0.993 | 22.1% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 1.174 | 44.4% | No |
| 5 | fs | ForSort Stable Fully In-Place | 1.185 | 45.8% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 1.222 | 50.3% | Yes |
| 7 | wi | WikiSort Fully In-Place | 2.542 | 212.7% | Yes |
| 8 | gs | GrailSort Fully In-Place | 7.649 | 840.8% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 8.913 | 996.3% | No |
| 10 | gq | GLibc Quick Sort Fully In-Place | 9.300 | 1043.9% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **wi** | WikiSort Fully In-Place | 7.754 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 8.221 | 6.0% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 9.452 | 21.9% | No |
| 4 | ti | TimSort with Allocated Workspace | 9.705 | 25.2% | Yes |
| 5 | fs | ForSort Stable Fully In-Place | 10.693 | 37.9% | Yes |
| 6 | gs | GrailSort Fully In-Place | 13.550 | 74.7% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 16.412 | 111.7% | No |
| 8 | fb | ForSort Basic Fully In-Place | 19.834 | 155.8% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 22.584 | 191.3% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 25.192 | 224.9% | No |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.948 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.012 | 6.8% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.050 | 10.8% | Yes |
| 4 | wi | WikiSort Fully In-Place | 3.660 | 286.1% | Yes |
| 5 | fi | ForSort Unstable Fully In-Place | 7.478 | 688.8% | No |
| 6 | gs | GrailSort Fully In-Place | 7.651 | 707.1% | Yes |
| 7 | fw | ForSort With Allocated Workspace | 7.762 | 718.8% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 11.702 | 1134.4% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 17.069 | 1700.5% | No |
| 10 | is | Insertion Sort Fully In-Place | 22.736 | 2298.3% | Yes |

### 10000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 18.473 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 22.800 | 23.4% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 23.849 | 29.1% | Yes |
| 4 | gs | GrailSort Fully In-Place | 47.123 | 155.1% | Yes |
| 5 | wi | WikiSort Fully In-Place | 50.223 | 171.9% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 50.375 | 172.7% | No |
| 7 | ti | TimSort with Allocated Workspace | 59.498 | 222.1% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 64.757 | 250.5% | No |
| 9 | fb | ForSort Basic Fully In-Place | 69.245 | 274.8% | Yes |
| 10 | is | Insertion Sort Fully In-Place | 116.78 | 532.2% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 20.938 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 22.563 | 7.8% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 24.315 | 16.1% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort In-Place | 28.878 | 37.9% | No |
| 5 | wi | WikiSort Fully In-Place | 30.154 | 44.0% | Yes |
| 6 | gs | GrailSort Fully In-Place | 33.611 | 60.5% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 35.369 | 68.9% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 39.898 | 90.6% | No |
| 9 | is | Insertion Sort Fully In-Place | 40.955 | 95.6% | Yes |
| 10 | fb | ForSort Basic Fully In-Place | 42.985 | 105.3% | Yes |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 15.480 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 16.967 | 9.6% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 17.419 | 12.5% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort In-Place | 18.599 | 20.1% | No |
| 5 | wi | WikiSort Fully In-Place | 19.168 | 23.8% | Yes |
| 6 | ti | TimSort with Allocated Workspace | 19.606 | 26.7% | Yes |
| 7 | gs | GrailSort Fully In-Place | 23.314 | 50.6% | Yes |
| 8 | fb | ForSort Basic Fully In-Place | 23.331 | 50.7% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 23.660 | 52.8% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 27.166 | 75.5% | No |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 11.611 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 12.815 | 10.4% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 12.983 | 11.8% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 13.225 | 13.9% | Yes |
| 5 | wi | WikiSort Fully In-Place | 15.089 | 30.0% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 15.381 | 32.5% | No |
| 7 | fb | ForSort Basic Fully In-Place | 15.805 | 36.1% | Yes |
| 8 | gs | GrailSort Fully In-Place | 18.286 | 57.5% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 19.788 | 70.4% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 22.131 | 90.6% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 4.226 | 0.0% | Yes |
| 2 | **ti** | TimSort with Allocated Workspace | 4.479 | 6.0% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 4.723 | 11.8% | No |
| 4 | fs | ForSort Stable Fully In-Place | 4.998 | 18.3% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 5.831 | 38.0% | Yes |
| 6 | wi | WikiSort Fully In-Place | 6.640 | 57.1% | Yes |
| 7 | is | Insertion Sort Fully In-Place | 7.535 | 78.3% | Yes |
| 8 | gs | GrailSort Fully In-Place | 11.253 | 166.3% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 12.445 | 194.5% | No |
| 10 | gq | GLibc Quick Sort Fully In-Place | 14.094 | 233.5% | No |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.782 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 0.885 | 13.2% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 0.920 | 17.6% | No |
| 4 | fb | ForSort Basic Fully In-Place | 0.970 | 24.0% | Yes |
| 5 | is | Insertion Sort Fully In-Place | 0.976 | 24.8% | Yes |
| 6 | fs | ForSort Stable Fully In-Place | 1.168 | 49.4% | Yes |
| 7 | wi | WikiSort Fully In-Place | 2.531 | 223.7% | Yes |
| 8 | gs | GrailSort Fully In-Place | 9.282 | 1087.0% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 11.614 | 1385.2% | No |
| 10 | gq | GLibc Quick Sort Fully In-Place | 11.758 | 1403.6% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **wi** | WikiSort Fully In-Place | 9.809 | 0.0% | Yes |
| 2 | **ti** | TimSort with Allocated Workspace | 9.893 | 0.9% | Yes |
| 3 | **fw** | ForSort With Allocated Workspace | 11.272 | 14.9% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 12.099 | 23.3% | No |
| 5 | fs | ForSort Stable Fully In-Place | 12.100 | 23.4% | Yes |
| 6 | gs | GrailSort Fully In-Place | 14.256 | 45.3% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 21.218 | 116.3% | No |
| 8 | fb | ForSort Basic Fully In-Place | 21.683 | 121.1% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 32.451 | 230.8% | No |
| 10 | is | Insertion Sort Fully In-Place | 212.77 | 2069.2% | Yes |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.912 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.018 | 11.6% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.052 | 15.4% | Yes |
| 4 | wi | WikiSort Fully In-Place | 4.423 | 385.0% | Yes |
| 5 | gs | GrailSort Fully In-Place | 9.412 | 932.0% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 10.411 | 1041.6% | Yes |
| 7 | fi | ForSort Unstable Fully In-Place | 10.517 | 1053.2% | No |
| 8 | gq | GLibc Quick Sort Fully In-Place | 14.472 | 1486.8% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 22.470 | 2363.8% | No |
| 10 | is | Insertion Sort Fully In-Place | 210.84 | 23019.0% | Yes |

### 100000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 22.811 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 26.030 | 14.1% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 27.248 | 19.5% | Yes |
| 4 | gs | GrailSort Fully In-Place | 54.088 | 137.1% | Yes |
| 5 | wi | WikiSort Fully In-Place | 60.256 | 164.2% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 62.143 | 172.4% | No |
| 7 | ti | TimSort with Allocated Workspace | 73.206 | 220.9% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 77.331 | 239.0% | No |
| 9 | fb | ForSort Basic Fully In-Place | 86.789 | 280.5% | Yes |
| 10 | is | Insertion Sort Fully In-Place | 962.84 | 4120.9% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 23.907 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 25.299 | 5.8% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 26.594 | 11.2% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort In-Place | 36.683 | 53.4% | No |
| 5 | wi | WikiSort Fully In-Place | 38.629 | 61.6% | Yes |
| 6 | gs | GrailSort Fully In-Place | 42.577 | 78.1% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 42.749 | 78.8% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 49.087 | 105.3% | No |
| 9 | fb | ForSort Basic Fully In-Place | 54.169 | 126.6% | Yes |
| 10 | is | Insertion Sort Fully In-Place | 128.61 | 438.0% | Yes |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 18.546 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 19.067 | 2.8% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 19.816 | 6.8% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 23.951 | 29.1% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 24.137 | 30.1% | No |
| 6 | wi | WikiSort Fully In-Place | 25.338 | 36.6% | Yes |
| 7 | fb | ForSort Basic Fully In-Place | 29.855 | 61.0% | Yes |
| 8 | gs | GrailSort Fully In-Place | 30.965 | 67.0% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 32.441 | 74.9% | No |
| 10 | is | Insertion Sort Fully In-Place | 37.755 | 103.6% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 14.560 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 14.910 | 2.4% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 14.981 | 2.9% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 16.541 | 13.6% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 20.373 | 39.9% | No |
| 6 | fb | ForSort Basic Fully In-Place | 20.450 | 40.5% | Yes |
| 7 | wi | WikiSort Fully In-Place | 20.582 | 41.4% | Yes |
| 8 | gs | GrailSort Fully In-Place | 25.513 | 75.2% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 27.011 | 85.5% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 27.298 | 87.5% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 6.433 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 6.928 | 7.7% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 7.444 | 15.7% | No |
| 4 | fs | ForSort Stable Fully In-Place | 7.662 | 19.1% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 9.170 | 42.5% | Yes |
| 6 | wi | WikiSort Fully In-Place | 12.954 | 101.4% | Yes |
| 7 | gs | GrailSort Fully In-Place | 15.773 | 145.2% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 16.799 | 161.1% | No |
| 9 | is | Insertion Sort Fully In-Place | 19.717 | 206.5% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 20.307 | 215.7% | No |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.779 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 0.874 | 12.2% | Yes |
| 3 | **is** | Insertion Sort Fully In-Place | 0.882 | 13.2% | Yes |
| 4 | fw | ForSort With Allocated Workspace | 1.013 | 30.0% | Yes |
| 5 | fi | ForSort Unstable Fully In-Place | 1.018 | 30.7% | No |
| 6 | fs | ForSort Stable Fully In-Place | 1.165 | 49.6% | Yes |
| 7 | wi | WikiSort Fully In-Place | 2.413 | 209.8% | Yes |
| 8 | gs | GrailSort Fully In-Place | 10.113 | 1198.2% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 13.875 | 1681.1% | No |
| 10 | nq | Bentley/McIlroy Quick Sort In-Place | 15.900 | 1941.1% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 10.056 | 0.0% | Yes |
| 2 | **wi** | WikiSort Fully In-Place | 11.335 | 12.7% | Yes |
| 3 | **fw** | ForSort With Allocated Workspace | 14.312 | 42.3% | Yes |
| 4 | fs | ForSort Stable Fully In-Place | 14.462 | 43.8% | Yes |
| 5 | gs | GrailSort Fully In-Place | 15.023 | 49.4% | Yes |
| 6 | fi | ForSort Unstable Fully In-Place | 15.276 | 51.9% | No |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 21.834 | 117.1% | No |
| 8 | fb | ForSort Basic Fully In-Place | 24.120 | 139.9% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 37.197 | 269.9% | No |
| 10 | is | Insertion Sort Fully In-Place | 2434.3 | 24107.3% | Yes |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.915 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.041 | 13.8% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.082 | 18.3% | Yes |
| 4 | wi | WikiSort Fully In-Place | 5.033 | 450.1% | Yes |
| 5 | gs | GrailSort Fully In-Place | 10.704 | 1069.8% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 13.559 | 1381.9% | Yes |
| 7 | fi | ForSort Unstable Fully In-Place | 13.857 | 1414.4% | No |
| 8 | gq | GLibc Quick Sort Fully In-Place | 16.919 | 1749.1% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 21.707 | 2272.3% | No |
| 10 | is | Insertion Sort Fully In-Place | 2356.1 | 257396.3% | Yes |

### 1000000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 25.563 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 29.678 | 16.1% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 29.892 | 16.9% | Yes |
| 4 | gs | GrailSort Fully In-Place | 63.430 | 148.1% | Yes |
| 5 | wi | WikiSort Fully In-Place | 73.756 | 188.5% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 73.915 | 189.1% | No |
| 7 | ti | TimSort with Allocated Workspace | 88.149 | 244.8% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 92.929 | 263.5% | No |
| 9 | fb | ForSort Basic Fully In-Place | 105.49 | 312.7% | Yes |
| 10 | is | Insertion Sort Fully In-Place | 13325.2 | 52027.0% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 26.357 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 27.527 | 4.4% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 28.737 | 9.0% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort In-Place | 44.802 | 70.0% | No |
| 5 | wi | WikiSort Fully In-Place | 45.998 | 74.5% | Yes |
| 6 | ti | TimSort with Allocated Workspace | 49.135 | 86.4% | Yes |
| 7 | gs | GrailSort Fully In-Place | 50.730 | 92.5% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 57.422 | 117.9% | No |
| 9 | fb | ForSort Basic Fully In-Place | 62.620 | 137.6% | Yes |
| 10 | is | Insertion Sort Fully In-Place | 1255.5 | 4663.5% | Yes |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 19.414 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 20.610 | 6.2% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 20.730 | 6.8% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 27.229 | 40.3% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 29.585 | 52.4% | No |
| 6 | wi | WikiSort Fully In-Place | 30.790 | 58.6% | Yes |
| 7 | fb | ForSort Basic Fully In-Place | 34.397 | 77.2% | Yes |
| 8 | gs | GrailSort Fully In-Place | 39.475 | 103.3% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 40.056 | 106.3% | No |
| 10 | is | Insertion Sort Fully In-Place | 190.29 | 880.2% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 15.203 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 16.101 | 5.9% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 16.519 | 8.7% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 19.254 | 26.6% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 24.102 | 58.5% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 25.045 | 64.7% | No |
| 7 | wi | WikiSort Fully In-Place | 25.866 | 70.1% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 33.086 | 117.6% | No |
| 9 | gs | GrailSort Fully In-Place | 34.272 | 125.4% | Yes |
| 10 | is | Insertion Sort Fully In-Place | 70.275 | 362.2% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 8.197 | 0.0% | Yes |
| 2 | **ti** | TimSort with Allocated Workspace | 8.430 | 2.8% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 8.474 | 3.4% | No |
| 4 | fs | ForSort Stable Fully In-Place | 8.505 | 3.8% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 11.539 | 40.8% | Yes |
| 6 | wi | WikiSort Fully In-Place | 17.726 | 116.2% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 20.262 | 147.2% | No |
| 8 | gs | GrailSort Fully In-Place | 24.292 | 196.4% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 25.683 | 213.3% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 26.187 | 219.5% | No |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.803 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 0.834 | 3.9% | Yes |
| 3 | **is** | Insertion Sort Fully In-Place | 0.836 | 4.1% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 1.070 | 33.3% | No |
| 5 | fw | ForSort With Allocated Workspace | 1.148 | 43.0% | Yes |
| 6 | fs | ForSort Stable Fully In-Place | 1.284 | 59.9% | Yes |
| 7 | wi | WikiSort Fully In-Place | 2.558 | 218.6% | Yes |
| 8 | gs | GrailSort Fully In-Place | 12.409 | 1445.3% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 16.527 | 1958.2% | No |
| 10 | nq | Bentley/McIlroy Quick Sort In-Place | 18.692 | 2227.8% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 10.387 | 0.0% | Yes |
| 2 | **wi** | WikiSort Fully In-Place | 12.197 | 17.4% | Yes |
| 3 | **gs** | GrailSort Fully In-Place | 17.521 | 68.7% | Yes |
| 4 | fs | ForSort Stable Fully In-Place | 18.486 | 78.0% | Yes |
| 5 | fw | ForSort With Allocated Workspace | 18.687 | 79.9% | Yes |
| 6 | fi | ForSort Unstable Fully In-Place | 19.629 | 89.0% | No |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 25.920 | 149.5% | No |
| 8 | fb | ForSort Basic Fully In-Place | 28.259 | 172.1% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 37.408 | 260.1% | No |
| 10 | is | Insertion Sort Fully In-Place | 31000.9 | 298358.4% | Yes |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.985 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.072 | 8.8% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.176 | 19.4% | Yes |
| 4 | wi | WikiSort Fully In-Place | 5.995 | 508.6% | Yes |
| 5 | gs | GrailSort Fully In-Place | 13.603 | 1281.0% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 18.062 | 1733.7% | Yes |
| 7 | fi | ForSort Unstable Fully In-Place | 18.308 | 1758.7% | No |
| 8 | gq | GLibc Quick Sort Fully In-Place | 19.866 | 1916.9% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 26.443 | 2584.6% | No |
| 10 | is | Insertion Sort Fully In-Place | 30667.4 | 3113339.2% | Yes |

### 10000000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 29.007 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 33.149 | 14.3% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 34.083 | 17.5% | Yes |
| 4 | gs | GrailSort Fully In-Place | 75.376 | 159.9% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 86.332 | 197.6% | No |
| 6 | wi | WikiSort Fully In-Place | 89.125 | 207.3% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 104.96 | 261.9% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 110.46 | 280.8% | No |
| 9 | fb | ForSort Basic Fully In-Place | 124.58 | 329.5% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 28.787 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 30.216 | 5.0% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 31.185 | 8.3% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort In-Place | 52.514 | 82.4% | No |
| 5 | wi | WikiSort Fully In-Place | 55.754 | 93.7% | Yes |
| 6 | ti | TimSort with Allocated Workspace | 58.794 | 104.2% | Yes |
| 7 | gs | GrailSort Fully In-Place | 60.381 | 109.8% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 69.404 | 141.1% | No |
| 9 | fb | ForSort Basic Fully In-Place | 72.494 | 151.8% | Yes |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 21.241 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 22.242 | 4.7% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 22.797 | 7.3% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 30.722 | 44.6% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 34.811 | 63.9% | No |
| 6 | wi | WikiSort Fully In-Place | 38.729 | 82.3% | Yes |
| 7 | fb | ForSort Basic Fully In-Place | 40.316 | 89.8% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 47.670 | 124.4% | No |
| 9 | gs | GrailSort Fully In-Place | 48.321 | 127.5% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 16.759 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 17.337 | 3.4% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 17.593 | 5.0% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 21.474 | 28.1% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 27.915 | 66.6% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 29.581 | 76.5% | No |
| 7 | wi | WikiSort Fully In-Place | 31.983 | 90.8% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 40.546 | 141.9% | No |
| 9 | gs | GrailSort Fully In-Place | 43.034 | 156.8% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 9.061 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 9.319 | 2.8% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 9.486 | 4.7% | No |
| 4 | fs | ForSort Stable Fully In-Place | 9.601 | 6.0% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 13.271 | 46.5% | Yes |
| 6 | wi | WikiSort Fully In-Place | 22.519 | 148.5% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 23.960 | 164.4% | No |
| 8 | gq | GLibc Quick Sort Fully In-Place | 32.300 | 256.5% | No |
| 9 | gs | GrailSort Fully In-Place | 32.872 | 262.8% | Yes |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.803 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 0.806 | 0.4% | Yes |
| 3 | **fw** | ForSort With Allocated Workspace | 0.896 | 11.6% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 0.902 | 12.3% | No |
| 5 | fs | ForSort Stable Fully In-Place | 1.262 | 57.2% | Yes |
| 6 | wi | WikiSort Fully In-Place | 2.005 | 149.7% | Yes |
| 7 | gs | GrailSort Fully In-Place | 16.236 | 1921.9% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 19.960 | 2385.7% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 21.502 | 2577.7% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 12.322 | 0.0% | Yes |
| 2 | **wi** | WikiSort Fully In-Place | 15.504 | 25.8% | Yes |
| 3 | **gs** | GrailSort Fully In-Place | 20.103 | 63.1% | Yes |
| 4 | fw | ForSort With Allocated Workspace | 22.613 | 83.5% | Yes |
| 5 | fi | ForSort Unstable Fully In-Place | 24.238 | 96.7% | No |
| 6 | fs | ForSort Stable Fully In-Place | 24.444 | 98.4% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 30.691 | 149.1% | No |
| 8 | fb | ForSort Basic Fully In-Place | 32.767 | 165.9% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 43.196 | 250.6% | No |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.951 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.062 | 11.7% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.213 | 27.5% | Yes |
| 4 | wi | WikiSort Fully In-Place | 7.047 | 641.0% | Yes |
| 5 | gs | GrailSort Fully In-Place | 16.296 | 1613.6% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 21.972 | 2210.4% | Yes |
| 7 | fi | ForSort Unstable Fully In-Place | 23.894 | 2412.5% | No |
| 8 | gq | GLibc Quick Sort Fully In-Place | 24.920 | 2520.4% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 31.630 | 3226.0% | No |

### 100000000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 36.316 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 39.335 | 8.3% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 42.307 | 16.5% | Yes |
| 4 | gs | GrailSort Fully In-Place | 90.196 | 148.4% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 98.438 | 171.1% | No |
| 6 | wi | WikiSort Fully In-Place | 104.92 | 188.9% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 120.74 | 232.5% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 127.09 | 250.0% | No |
| 9 | fb | ForSort Basic Fully In-Place | 147.04 | 304.9% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 34.307 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 34.592 | 0.8% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 36.421 | 6.2% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort In-Place | 60.589 | 76.6% | No |
| 5 | wi | WikiSort Fully In-Place | 64.624 | 88.4% | Yes |
| 6 | ti | TimSort with Allocated Workspace | 67.324 | 96.2% | Yes |
| 7 | gs | GrailSort Fully In-Place | 72.027 | 109.9% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 81.187 | 136.6% | No |
| 9 | fb | ForSort Basic Fully In-Place | 83.668 | 143.9% | Yes |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 25.569 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 25.609 | 0.2% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 26.656 | 4.3% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 35.490 | 38.8% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 40.307 | 57.6% | No |
| 6 | wi | WikiSort Fully In-Place | 46.483 | 81.8% | Yes |
| 7 | fb | ForSort Basic Fully In-Place | 46.928 | 83.5% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 57.400 | 124.5% | No |
| 9 | gs | GrailSort Fully In-Place | 59.842 | 134.0% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fi** | ForSort Unstable Fully In-Place | 20.276 | 0.0% | No |
| 2 | **fw** | ForSort With Allocated Workspace | 20.535 | 1.3% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 20.762 | 2.4% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 24.558 | 21.1% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 32.537 | 60.5% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 34.280 | 69.1% | No |
| 7 | wi | WikiSort Fully In-Place | 40.065 | 97.6% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 49.066 | 142.0% | No |
| 9 | gs | GrailSort Fully In-Place | 54.319 | 167.9% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 10.660 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 12.258 | 15.0% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 12.655 | 18.7% | Yes |
| 4 | fw | ForSort With Allocated Workspace | 12.877 | 20.8% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 15.572 | 46.1% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 28.057 | 163.2% | No |
| 7 | wi | WikiSort Fully In-Place | 29.706 | 178.7% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 39.397 | 269.6% | No |
| 9 | gs | GrailSort Fully In-Place | 43.103 | 304.3% | Yes |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.779 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 0.794 | 1.9% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.190 | 52.8% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 1.431 | 83.7% | No |
| 5 | fw | ForSort With Allocated Workspace | 1.935 | 148.4% | Yes |
| 6 | wi | WikiSort Fully In-Place | 2.280 | 192.7% | Yes |
| 7 | gs | GrailSort Fully In-Place | 22.032 | 2728.2% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 23.645 | 2935.3% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 25.844 | 3217.6% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 16.200 | 0.0% | Yes |
| 2 | **wi** | WikiSort Fully In-Place | 20.564 | 26.9% | Yes |
| 3 | **gs** | GrailSort Fully In-Place | 27.204 | 67.9% | Yes |
| 4 | fw | ForSort With Allocated Workspace | 30.781 | 90.0% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 31.675 | 95.5% | No |
| 6 | fi | ForSort Unstable Fully In-Place | 34.478 | 112.8% | No |
| 7 | fs | ForSort Stable Fully In-Place | 35.912 | 121.7% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 49.997 | 208.6% | No |
| 9 | fb | ForSort Basic Fully In-Place | 53.605 | 230.9% | Yes |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 1.048 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.238 | 18.1% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.564 | 49.2% | Yes |
| 4 | wi | WikiSort Fully In-Place | 12.590 | 1101.3% | Yes |
| 5 | gs | GrailSort Fully In-Place | 22.748 | 2070.6% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 30.327 | 2793.8% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 30.852 | 2843.9% | No |
| 8 | gq | GLibc Quick Sort Fully In-Place | 31.454 | 2901.3% | No |
| 9 | fi | ForSort Unstable Fully In-Place | 33.934 | 3138.0% | No |


## Detailed Results by Dataset Size

### 100 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000001561** | 670 | **15.613** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000001805** | 704 | **18.049** | Yes | 2 |
| wi | WikiSort Fully In-Place | **0.000002146** | 617 | **21.458** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.000002302 | 868 | 23.018 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000002451 | 645 | 24.508 | Yes | 5 |
| is | Insertion Sort Fully In-Place | 0.000002748 | 737 | 27.480 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000002764 | 537 | 27.642 | Yes | 7 |
| fb | ForSort Basic Fully In-Place | 0.000002956 | 917 | 29.557 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000002964 | 737 | 29.642 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000003252 | 540 | 32.521 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000001017** | 423 | **10.167** | Yes | 1 |
| wi | WikiSort Fully In-Place | **0.000001096** | 483 | **10.962** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000001114** | 441 | **11.137** | Yes | 3 |
| is | Insertion Sort Fully In-Place | 0.000001203 | 579 | 12.031 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000001341 | 568 | 13.411 | Yes | 5 |
| ti | TimSort with Allocated Workspace | 0.000001364 | 399 | 13.644 | Yes | 6 |
| fs | ForSort Stable Fully In-Place | 0.000001488 | 554 | 14.877 | Yes | 7 |
| fb | ForSort Basic Fully In-Place | 0.000001555 | 508 | 15.554 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000001591 | 538 | 15.914 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000001815 | 421 | 18.149 | Yes | 10 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort Fully In-Place | **0.000000462** | 269 | **4.622** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.000000482** | 216 | **4.822** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000000519** | 220 | **5.193** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000000538 | 307 | 5.382 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.000000576 | 278 | 5.759 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.000000675 | 307 | 6.746 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000000685 | 302 | 6.848 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000000858 | 537 | 8.576 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000000950 | 428 | 9.497 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000001019 | 341 | 10.187 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort Fully In-Place | **0.000000273** | 169 | **2.733** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000000324** | 159 | **3.243** | Yes | 2 |
| fw | ForSort With Allocated Workspace | **0.000000333** | 163 | **3.332** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.000000341 | 217 | 3.413 | Yes | 4 |
| wi | WikiSort Fully In-Place | 0.000000365 | 258 | 3.654 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.000000421 | 241 | 4.210 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000000480 | 248 | 4.798 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000000730 | 531 | 7.303 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000000780 | 400 | 7.797 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000000809 | 325 | 8.091 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort Fully In-Place | **0.000000138** | 111 | **1.379** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000000210** | 127 | **2.103** | Yes | 2 |
| fb | ForSort Basic Fully In-Place | **0.000000222** | 184 | **2.221** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.000000228 | 151 | 2.279 | Yes | 4 |
| fw | ForSort With Allocated Workspace | 0.000000233 | 133 | 2.334 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.000000250 | 233 | 2.499 | Yes | 6 |
| fs | ForSort Stable Fully In-Place | 0.000000286 | 205 | 2.855 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000000631 | 523 | 6.305 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000000655 | 386 | 6.549 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000000693 | 317 | 6.930 | Yes | 10 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000000095** | 99 | **0.951** | Yes | 1 |
| is | Insertion Sort Fully In-Place | **0.000000108** | 99 | **1.084** | Yes | 2 |
| fb | ForSort Basic Fully In-Place | **0.000000113** | 99 | **1.132** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.000000128 | 99 | 1.283 | Yes | 4 |
| fi | ForSort Unstable Fully In-Place | 0.000000182 | 121 | 1.823 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.000000209 | 128 | 2.089 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.000000224 | 228 | 2.240 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000000596 | 384 | 5.960 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000000605 | 520 | 6.048 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000000671 | 316 | 6.707 | Yes | 10 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| wi | WikiSort Fully In-Place | **0.000000729** | 365 | **7.287** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.000000736** | 431 | **7.361** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000000904** | 492 | **9.041** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.000000941 | 419 | 9.405 | Yes | 4 |
| is | Insertion Sort Fully In-Place | 0.000001043 | 780 | 10.434 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000001165 | 780 | 11.645 | No | 6 |
| gs | GrailSort Fully In-Place | 0.000001500 | 520 | 15.004 | Yes | 7 |
| fs | ForSort Stable Fully In-Place | 0.000001513 | 683 | 15.127 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 0.000001748 | 786 | 17.477 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000002021 | 369 | 20.211 | Yes | 10 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000000107** | 99 | **1.070** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000000118** | 99 | **1.179** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000000126** | 99 | **1.265** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000000300 | 271 | 2.997 | Yes | 4 |
| fw | ForSort With Allocated Workspace | 0.000000598 | 421 | 5.984 | Yes | 5 |
| gs | GrailSort Fully In-Place | 0.000000625 | 400 | 6.245 | Yes | 6 |
| fi | ForSort Unstable Fully In-Place | 0.000000719 | 498 | 7.191 | Yes | 7 |
| is | Insertion Sort Fully In-Place | 0.000000900 | 782 | 9.000 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.000000945 | 356 | 9.447 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000001150 | 953 | 11.498 | Yes | 10 |

### 1000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000016575** | 9575 | **16.575** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000020640** | 10218 | **20.640** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000023668** | 10464 | **23.668** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000032976 | 9510 | 32.976 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000037101 | 10085 | 37.101 | Yes | 5 |
| gs | GrailSort Fully In-Place | 0.000038028 | 10506 | 38.028 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000043668 | 8680 | 43.668 | Yes | 7 |
| fb | ForSort Basic Fully In-Place | 0.000048210 | 15120 | 48.210 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.000048706 | 8703 | 48.706 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.000049297 | 10912 | 49.297 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000016994** | 7392 | **16.994** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000018878** | 7689 | **18.878** | Yes | 2 |
| wi | WikiSort Fully In-Place | **0.000019080** | 8748 | **19.080** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000020806 | 9187 | 20.806 | Yes | 4 |
| fs | ForSort Stable Fully In-Place | 0.000021537 | 8173 | 21.537 | Yes | 5 |
| ti | TimSort with Allocated Workspace | 0.000025020 | 7036 | 25.020 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.000025690 | 9002 | 25.690 | Yes | 7 |
| is | Insertion Sort Fully In-Place | 0.000026692 | 10649 | 26.692 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.000029871 | 7947 | 29.871 | Yes | 9 |
| fb | ForSort Basic Fully In-Place | 0.000030995 | 9141 | 30.995 | Yes | 10 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000010869** | 4437 | **10.869** | Yes | 1 |
| wi | WikiSort Fully In-Place | **0.000011522** | 7000 | **11.522** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000012534** | 5039 | **12.534** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.000012764 | 4835 | 12.764 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000013101 | 8522 | 13.101 | Yes | 5 |
| ti | TimSort with Allocated Workspace | 0.000013102 | 4668 | 13.102 | Yes | 6 |
| is | Insertion Sort Fully In-Place | 0.000014772 | 9777 | 14.772 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000015115 | 6633 | 15.115 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 0.000015406 | 5767 | 15.406 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000018931 | 6438 | 18.931 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000006500** | 2843 | **6.500** | Yes | 1 |
| wi | WikiSort Fully In-Place | **0.000007597** | 5001 | **7.597** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000007610** | 3431 | **7.610** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.000007656 | 3137 | 7.656 | Yes | 4 |
| ti | TimSort with Allocated Workspace | 0.000008428 | 3567 | 8.428 | Yes | 5 |
| is | Insertion Sort Fully In-Place | 0.000008508 | 6333 | 8.508 | Yes | 6 |
| fb | ForSort Basic Fully In-Place | 0.000009057 | 4094 | 9.057 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000011054 | 8358 | 11.054 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000011298 | 5504 | 11.298 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000014076 | 5560 | 14.076 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort Fully In-Place | **0.000002021** | 1620 | **2.021** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.000002033** | 1255 | **2.033** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000002291** | 1344 | **2.291** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.000002946 | 2203 | 2.946 | Yes | 4 |
| fs | ForSort Stable Fully In-Place | 0.000003204 | 2189 | 3.204 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.000003320 | 2798 | 3.320 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000003599 | 2045 | 3.599 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000008503 | 4877 | 8.503 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000009497 | 8249 | 9.497 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000009920 | 4983 | 9.920 | Yes | 10 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000000813** | 999 | **0.813** | Yes | 1 |
| is | Insertion Sort Fully In-Place | **0.000000983** | 999 | **0.983** | Yes | 2 |
| fb | ForSort Basic Fully In-Place | **0.000000993** | 999 | **0.993** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.000001174 | 1052 | 1.174 | Yes | 4 |
| fs | ForSort Stable Fully In-Place | 0.000001185 | 999 | 1.185 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.000001222 | 1028 | 1.222 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.000002542 | 2530 | 2.542 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000007649 | 4790 | 7.649 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000008913 | 8191 | 8.913 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000009300 | 4932 | 9.300 | Yes | 10 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| wi | WikiSort Fully In-Place | **0.000007754** | 4601 | **7.754** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.000008221** | 6564 | **8.221** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000009452** | 6498 | **9.452** | No | 3 |
| ti | TimSort with Allocated Workspace | 0.000009705 | 4456 | 9.705 | Yes | 4 |
| fs | ForSort Stable Fully In-Place | 0.000010693 | 5887 | 10.693 | Yes | 5 |
| gs | GrailSort Fully In-Place | 0.000013550 | 5699 | 13.550 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000016412 | 12038 | 16.412 | No | 7 |
| fb | ForSort Basic Fully In-Place | 0.000019834 | 8563 | 19.834 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.000022584 | 10978 | 22.584 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000025192 | 5237 | 25.192 | Yes | 10 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000000948** | 999 | **0.948** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000001012** | 999 | **1.012** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000001050** | 999 | **1.050** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000003660 | 3287 | 3.660 | Yes | 4 |
| fi | ForSort Unstable Fully In-Place | 0.000007478 | 6407 | 7.478 | Yes | 5 |
| gs | GrailSort Fully In-Place | 0.000007651 | 5112 | 7.651 | Yes | 6 |
| fw | ForSort With Allocated Workspace | 0.000007762 | 6614 | 7.762 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.000011702 | 5044 | 11.702 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000017069 | 14222 | 17.069 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.000022736 | 10980 | 22.736 | Yes | 10 |

### 10000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000184732** | 126138 | **18.473** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000228002** | 133078 | **22.800** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000238487** | 133577 | **23.849** | Yes | 3 |
| gs | GrailSort Fully In-Place | 0.000471228 | 138632 | 47.123 | Yes | 4 |
| wi | WikiSort Fully In-Place | 0.000502229 | 143339 | 50.223 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000503748 | 137018 | 50.375 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000594982 | 120354 | 59.498 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.000647567 | 120414 | 64.757 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 0.000692454 | 208536 | 69.245 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.001167832 | 143513 | 116.78 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000209379** | 100880 | **20.938** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000225630** | 104341 | **22.563** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000243154** | 105422 | **24.315** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000288776 | 127117 | 28.878 | Yes | 4 |
| wi | WikiSort Fully In-Place | 0.000301537 | 131330 | 30.154 | Yes | 5 |
| gs | GrailSort Fully In-Place | 0.000336106 | 126396 | 33.611 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000353687 | 93923 | 35.369 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.000398985 | 115308 | 39.898 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.000409553 | 143045 | 40.955 | Yes | 9 |
| fb | ForSort Basic Fully In-Place | 0.000429852 | 124779 | 42.985 | Yes | 10 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000154798** | 65568 | **15.480** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000169671** | 69597 | **16.967** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000174189** | 67720 | **17.419** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000185990 | 119571 | 18.599 | Yes | 4 |
| wi | WikiSort Fully In-Place | 0.000191683 | 110231 | 19.168 | Yes | 5 |
| ti | TimSort with Allocated Workspace | 0.000196060 | 56011 | 19.606 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.000233140 | 106235 | 23.314 | Yes | 7 |
| fb | ForSort Basic Fully In-Place | 0.000233310 | 79245 | 23.331 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.000236598 | 142148 | 23.660 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000271657 | 102552 | 27.166 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000116110** | 46485 | **11.611** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000128151** | 50064 | **12.815** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000129829** | 50987 | **12.983** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.000132246 | 41460 | 13.225 | Yes | 4 |
| wi | WikiSort Fully In-Place | 0.000150894 | 95325 | 15.089 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000153815 | 116696 | 15.381 | Yes | 6 |
| fb | ForSort Basic Fully In-Place | 0.000158050 | 60799 | 15.805 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000182857 | 90191 | 18.286 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.000197883 | 141273 | 19.788 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000221306 | 92080 | 22.131 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000042263** | 20651 | **4.226** | Yes | 1 |
| ti | TimSort with Allocated Workspace | **0.000044785** | 20074 | **4.479** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000047232** | 22039 | **4.723** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.000049977 | 24641 | 4.998 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.000058310 | 32462 | 5.831 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.000066399 | 45936 | 6.640 | Yes | 6 |
| is | Insertion Sort Fully In-Place | 0.000075351 | 63430 | 7.535 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000112531 | 61179 | 11.253 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000124453 | 112922 | 12.445 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000140945 | 69193 | 14.094 | Yes | 10 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000007818** | 9999 | **0.782** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.000008849** | 10049 | **0.885** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000009200** | 10091 | **0.920** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.000009703 | 9999 | 0.970 | Yes | 4 |
| is | Insertion Sort Fully In-Place | 0.000009762 | 9999 | 0.976 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.000011680 | 9999 | 1.168 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.000025313 | 23662 | 2.531 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000092817 | 53332 | 9.282 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000116140 | 111538 | 11.614 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000117578 | 64608 | 11.758 | Yes | 10 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| wi | WikiSort Fully In-Place | **0.000098089** | 44655 | **9.809** | Yes | 1 |
| ti | TimSort with Allocated Workspace | **0.000098927** | 39935 | **9.893** | Yes | 2 |
| fw | ForSort With Allocated Workspace | **0.000112718** | 97315 | **11.272** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.000120985 | 93306 | 12.099 | No | 4 |
| fs | ForSort Stable Fully In-Place | 0.000121003 | 82495 | 12.100 | Yes | 5 |
| gs | GrailSort Fully In-Place | 0.000142565 | 60796 | 14.256 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000212180 | 166725 | 21.218 | No | 7 |
| fb | ForSort Basic Fully In-Place | 0.000216825 | 86921 | 21.683 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.000324509 | 70411 | 32.451 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.002127730 | 143610 | 212.77 | Yes | 10 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000009116** | 9999 | **0.912** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000010175** | 9999 | **1.018** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000010520** | 9999 | **1.052** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000044231 | 25008 | 4.423 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.000094116 | 57076 | 9.412 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.000104114 | 98010 | 10.411 | Yes | 6 |
| fi | ForSort Unstable Fully In-Place | 0.000105167 | 93366 | 10.517 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.000144721 | 69008 | 14.472 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000224697 | 192779 | 22.470 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.002108454 | 143612 | 210.84 | Yes | 10 |

### 100000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.002281095** | 1621733 | **22.811** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.002602984** | 1649584 | **26.030** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.002724750** | 1701935 | **27.248** | Yes | 3 |
| gs | GrailSort Fully In-Place | 0.005408850 | 1692292 | 54.088 | Yes | 4 |
| wi | WikiSort Fully In-Place | 0.006025556 | 1828537 | 60.256 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.006214264 | 1731596 | 62.143 | No | 6 |
| ti | TimSort with Allocated Workspace | 0.007320635 | 1531065 | 73.206 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.007733061 | 1536077 | 77.331 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 0.008678928 | 2643459 | 86.789 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.096283957 | 1768782 | 962.84 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.002390729** | 1237287 | **23.907** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.002529869** | 1269667 | **25.299** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.002659371** | 1267523 | **26.594** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.003668341 | 1622424 | 36.683 | No | 4 |
| wi | WikiSort Fully In-Place | 0.003862920 | 1718044 | 38.629 | Yes | 5 |
| gs | GrailSort Fully In-Place | 0.004257676 | 1631676 | 42.577 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.004274893 | 1094151 | 42.749 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.004908656 | 1507288 | 49.087 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 0.005416929 | 1537142 | 54.169 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.012861317 | 1768030 | 128.61 | Yes | 10 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.001854617** | 793760 | **18.546** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.001906719** | 837048 | **19.067** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.001981589** | 807849 | **19.816** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.002395071 | 678065 | 23.951 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.002413734 | 1538407 | 24.137 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.002533847 | 1482326 | 25.338 | Yes | 6 |
| fb | ForSort Basic Fully In-Place | 0.002985461 | 949090 | 29.855 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.003096513 | 1432845 | 30.965 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.003244107 | 1388145 | 32.441 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.003775514 | 1766493 | 37.755 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.001456028** | 611646 | **14.560** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.001491039** | 643549 | **14.910** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.001498145** | 599749 | **14.981** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.001654082 | 521668 | 16.541 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.002037270 | 1517046 | 20.373 | Yes | 5 |
| fb | ForSort Basic Fully In-Place | 0.002045026 | 735014 | 20.450 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.002058153 | 1317922 | 20.582 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.002551281 | 1279980 | 25.513 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.002701131 | 1764005 | 27.011 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.002729814 | 1297186 | 27.298 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000643322** | 255910 | **6.433** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.000692841** | 295454 | **6.928** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000744375** | 311125 | **7.444** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.000766189 | 321290 | 7.662 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.000917027 | 434202 | 9.170 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.001295391 | 949667 | 12.954 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.001577292 | 912819 | 15.773 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.001679862 | 1515703 | 16.799 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.001971731 | 1746872 | 19.717 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.002030687 | 1052827 | 20.307 | Yes | 10 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000077874** | 99999 | **0.779** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000087399** | 99999 | **0.874** | Yes | 2 |
| is | Insertion Sort Fully In-Place | **0.000088174** | 99999 | **0.882** | Yes | 3 |
| fw | ForSort With Allocated Workspace | 0.000101333 | 100078 | 1.013 | Yes | 4 |
| fi | ForSort Unstable Fully In-Place | 0.000101832 | 100167 | 1.018 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.000116495 | 99999 | 1.165 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.000241260 | 240530 | 2.413 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.001011284 | 608786 | 10.113 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.001387507 | 815024 | 13.875 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.001590004 | 1524581 | 15.900 | Yes | 10 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.001005551** | 423410 | **10.056** | Yes | 1 |
| wi | WikiSort Fully In-Place | **0.001133534** | 566125 | **11.335** | Yes | 2 |
| fw | ForSort With Allocated Workspace | **0.001431246** | 1228340 | **14.312** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.001446214 | 1049641 | 14.462 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.001502343 | 653665 | 15.023 | Yes | 5 |
| fi | ForSort Unstable Fully In-Place | 0.001527594 | 1195726 | 15.276 | No | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.002183387 | 1775189 | 21.834 | No | 7 |
| fb | ForSort Basic Fully In-Place | 0.002412023 | 874227 | 24.120 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.003719726 | 866158 | 37.197 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.243428885 | 1768916 | 2434.3 | Yes | 10 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000091482** | 99999 | **0.915** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000104143** | 99999 | **1.041** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000108159** | 99999 | **1.082** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000503258 | 284046 | 5.033 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.001070400 | 627299 | 10.704 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.001355869 | 1235508 | 13.559 | Yes | 6 |
| fi | ForSort Unstable Fully In-Place | 0.001385749 | 1201428 | 13.857 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.001691890 | 853904 | 16.919 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.002170656 | 1935567 | 21.707 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.235609063 | 1768918 | 2356.1 | Yes | 10 |

### 1000000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.025563153** | 19344396 | **25.563** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.029678094** | 20006051 | **29.678** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.029892494** | 20144081 | **29.892** | Yes | 3 |
| gs | GrailSort Fully In-Place | 0.063429849 | 20161685 | 63.430 | Yes | 4 |
| wi | WikiSort Fully In-Place | 0.073756366 | 22370582 | 73.756 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.073914736 | 20932120 | 73.915 | No | 6 |
| ti | TimSort with Allocated Workspace | 0.088149370 | 18299251 | 88.149 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.092929283 | 18672458 | 92.929 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 0.105493738 | 31933366 | 105.49 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 13.325227264 | 20951223 | 13325.2 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.026356530** | 14556327 | **26.357** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.027526674** | 15101830 | **27.527** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.028736667** | 14974493 | **28.737** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.044801601 | 19732057 | 44.802 | No | 4 |
| wi | WikiSort Fully In-Place | 0.045998147 | 21147276 | 45.998 | Yes | 5 |
| ti | TimSort with Allocated Workspace | 0.049134788 | 12452195 | 49.135 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.050729917 | 19798089 | 50.730 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.057422286 | 18496846 | 57.422 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 0.062620374 | 17998911 | 62.620 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 1.255528082 | 20950078 | 1255.5 | Yes | 10 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.019414366** | 9379522 | **19.414** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.020610436** | 10065937 | **20.610** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.020729617** | 9542124 | **20.730** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.027228698 | 7732374 | 27.229 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.029585085 | 18776212 | 29.585 | No | 5 |
| wi | WikiSort Fully In-Place | 0.030789803 | 18761675 | 30.790 | Yes | 6 |
| fb | ForSort Basic Fully In-Place | 0.034397349 | 10738012 | 34.397 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.039474850 | 18049573 | 39.475 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.040055755 | 17422431 | 40.056 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.190288154 | 20947569 | 190.29 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.015202988** | 7222235 | **15.203** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.016101182** | 7722200 | **16.101** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.016518678** | 7267373 | **16.519** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.019253688 | 6046022 | 19.254 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.024101767 | 8208316 | 24.102 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.025044561 | 18501998 | 25.045 | No | 6 |
| wi | WikiSort Fully In-Place | 0.025866075 | 17097566 | 25.866 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.033086320 | 16566898 | 33.086 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.034272278 | 16619326 | 34.272 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.070275181 | 20943886 | 70.275 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.008196654** | 3358592 | **8.197** | Yes | 1 |
| ti | TimSort with Allocated Workspace | **0.008430490** | 3178814 | **8.430** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.008473999** | 3575369 | **8.474** | No | 3 |
| fs | ForSort Stable Fully In-Place | 0.008505181 | 3657664 | 8.505 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.011538599 | 4900541 | 11.539 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.017725739 | 13259432 | 17.726 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.020262027 | 18249004 | 20.262 | No | 7 |
| gs | GrailSort Fully In-Place | 0.024291887 | 13140271 | 24.292 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.025682968 | 20920992 | 25.683 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.026186502 | 14446138 | 26.187 | Yes | 10 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000803306** | 999999 | **0.803** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000834043** | 999999 | **0.834** | Yes | 2 |
| is | Insertion Sort Fully In-Place | **0.000835616** | 999999 | **0.836** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.001070040 | 1000212 | 1.070 | Yes | 4 |
| fw | ForSort With Allocated Workspace | 0.001148349 | 1000058 | 1.148 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.001284420 | 999999 | 1.284 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.002557739 | 2595342 | 2.558 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.012408641 | 7019424 | 12.409 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.016527376 | 9884992 | 16.527 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.018692242 | 18196494 | 18.692 | No | 10 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.010386553** | 4402872 | **10.387** | Yes | 1 |
| wi | WikiSort Fully In-Place | **0.012196917** | 6204289 | **12.197** | Yes | 2 |
| gs | GrailSort Fully In-Place | **0.017520835** | 7770828 | **17.521** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.018486441 | 13911676 | 18.486 | Yes | 4 |
| fw | ForSort With Allocated Workspace | 0.018686625 | 16348396 | 18.687 | Yes | 5 |
| fi | ForSort Unstable Fully In-Place | 0.019629364 | 15717566 | 19.629 | No | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.025919865 | 21892882 | 25.920 | No | 7 |
| fb | ForSort Basic Fully In-Place | 0.028258799 | 8712694 | 28.259 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.037408016 | 10249901 | 37.408 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 31.000875152 | 20951405 | 31000.9 | Yes | 10 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000985393** | 999999 | **0.985** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.001072194** | 999999 | **1.072** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.001176052** | 999999 | **1.176** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.005995378 | 3273489 | 5.995 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.013602954 | 7551070 | 13.603 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.018061636 | 16420327 | 18.062 | Yes | 6 |
| fi | ForSort Unstable Fully In-Place | 0.018308192 | 15784214 | 18.308 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.019865576 | 10066432 | 19.866 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.026443119 | 24025703 | 26.443 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 30.667375719 | 20951408 | 30667.4 | Yes | 10 |

### 10000000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.290067023** | 225429485 | **29.007** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.331487670** | 232322602 | **33.149** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.340826735** | 235553171 | **34.083** | Yes | 3 |
| gs | GrailSort Fully In-Place | 0.753762400 | 236971730 | 75.376 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.863320599 | 244978728 | 86.332 | No | 5 |
| wi | WikiSort Fully In-Place | 0.891250983 | 266857618 | 89.125 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 1.049622382 | 213811193 | 104.96 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 1.104598763 | 220067062 | 110.46 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 1.245795867 | 373601936 | 124.58 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.287872836** | 166172477 | **28.787** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.302164817** | 174390819 | **30.216** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.311849024** | 171184488 | **31.185** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.525142417 | 232362806 | 52.514 | No | 4 |
| wi | WikiSort Fully In-Place | 0.557541613 | 249321112 | 55.754 | Yes | 5 |
| ti | TimSort with Allocated Workspace | 0.587939801 | 139281719 | 58.794 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.603807102 | 232117264 | 60.381 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.694043745 | 218005542 | 69.404 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 0.724935985 | 205438284 | 72.494 | Yes | 9 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.212413773** | 108135098 | **21.241** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.222421592** | 115602839 | **22.242** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.227971276** | 111447909 | **22.797** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.307216273 | 80920121 | 30.722 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.348111956 | 221653993 | 34.811 | No | 5 |
| wi | WikiSort Fully In-Place | 0.387293604 | 222869681 | 38.729 | Yes | 6 |
| fb | ForSort Basic Fully In-Place | 0.403156517 | 118996129 | 40.316 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.476701311 | 208077387 | 47.670 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.483212567 | 215559595 | 48.321 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.167586333** | 83611057 | **16.759** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.173372070** | 88487239 | **17.337** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.175933368** | 86686382 | **17.593** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.214739905 | 59835512 | 21.474 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.279149281 | 89626849 | 27.915 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.295812668 | 218615245 | 29.581 | No | 6 |
| wi | WikiSort Fully In-Place | 0.319831009 | 204455453 | 31.983 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.405461390 | 199428468 | 40.546 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.430336964 | 201540433 | 43.034 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.090612244** | 29069889 | **9.061** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.093193560** | 42835886 | **9.319** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.094863231** | 44720976 | **9.486** | No | 3 |
| fs | ForSort Stable Fully In-Place | 0.096006101 | 45660414 | 9.601 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.132708780 | 52344963 | 13.271 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.225192807 | 161738605 | 22.519 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.239598594 | 215103159 | 23.960 | No | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.323004477 | 178584358 | 32.300 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.328723861 | 166960984 | 32.872 | Yes | 9 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.008034472** | 9999999 | **0.803** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.008058137** | 9999999 | **0.806** | Yes | 2 |
| fw | ForSort With Allocated Workspace | **0.008964851** | 10000089 | **0.896** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.009021113 | 10000304 | 0.902 | Yes | 4 |
| fs | ForSort Stable Fully In-Place | 0.012619661 | 9999999 | 1.262 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.020047988 | 20122539 | 2.005 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.162356036 | 79190466 | 16.236 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.199596402 | 114434624 | 19.960 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.215015078 | 211563145 | 21.502 | No | 9 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.123222952** | 39878319 | **12.322** | Yes | 1 |
| wi | WikiSort Fully In-Place | **0.155040951** | 68476895 | **15.504** | Yes | 2 |
| gs | GrailSort Fully In-Place | **0.201028005** | 84028632 | **20.103** | Yes | 3 |
| fw | ForSort With Allocated Workspace | 0.226128624 | 197266474 | 22.613 | Yes | 4 |
| fi | ForSort Unstable Fully In-Place | 0.242377857 | 190716448 | 24.238 | No | 5 |
| fs | ForSort Stable Fully In-Place | 0.244442209 | 177389048 | 24.444 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.306911024 | 264938294 | 30.691 | No | 7 |
| fb | ForSort Basic Fully In-Place | 0.327668670 | 87261366 | 32.767 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.431957531 | 120242932 | 43.196 | Yes | 9 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.009505338** | 9999999 | **0.951** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.010624341** | 9999999 | **1.062** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.012126155** | 9999999 | **1.213** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.070474969 | 21498750 | 7.047 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.162960232 | 81979307 | 16.296 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.219719515 | 197985849 | 21.972 | Yes | 6 |
| fi | ForSort Unstable Fully In-Place | 0.238939968 | 191369358 | 23.894 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.249201867 | 118788160 | 24.920 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.316297538 | 290683459 | 31.630 | Yes | 9 |

### 100000000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **3.631627976** | 2621033638 | **36.316** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **3.933451892** | 2635149973 | **39.335** | No | 2 |
| fs | ForSort Stable Fully In-Place | **4.230746486** | 2743966108 | **42.307** | Yes | 3 |
| gs | GrailSort Fully In-Place | 9.019552970 | 2655115103 | 90.196 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 9.843841393 | 2813381791 | 98.438 | No | 5 |
| wi | WikiSort Fully In-Place | 10.492428646 | 3064030624 | 104.92 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 12.073936125 | 2435414127 | 120.74 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 12.709472568 | 2532645582 | 127.09 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 14.704274868 | 4275252865 | 147.04 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **3.430666901** | 1862546846 | **34.307** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **3.459198890** | 1935889163 | **34.592** | No | 2 |
| fs | ForSort Stable Fully In-Place | **3.642055074** | 1923143086 | **36.421** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort In-Place | 6.058883946 | 2673756547 | 60.589 | No | 4 |
| wi | WikiSort Fully In-Place | 6.462432725 | 2854539037 | 64.624 | Yes | 5 |
| ti | TimSort with Allocated Workspace | 6.732373081 | 1534823448 | 67.324 | Yes | 6 |
| gs | GrailSort Fully In-Place | 7.202731996 | 2634706912 | 72.027 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 8.118661626 | 2514386491 | 81.187 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 8.366754864 | 2304610106 | 83.668 | Yes | 9 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **2.556932185** | 1190172561 | **25.569** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **2.560897266** | 1271687406 | **25.609** | No | 2 |
| fs | ForSort Stable Fully In-Place | **2.665630130** | 1225562532 | **26.656** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 3.549045135 | 885227488 | 35.490 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 4.030723093 | 2556059938 | 40.307 | No | 5 |
| wi | WikiSort Fully In-Place | 4.648267903 | 2589557822 | 46.483 | Yes | 6 |
| fb | ForSort Basic Fully In-Place | 4.692767711 | 1303210370 | 46.928 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 5.739973044 | 2425069297 | 57.400 | Yes | 8 |
| gs | GrailSort Fully In-Place | 5.984210983 | 2496323648 | 59.842 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fi | ForSort Unstable Fully In-Place | **2.027578957** | 982330734 | **20.276** | No | 1 |
| fw | ForSort With Allocated Workspace | **2.053517676** | 925917312 | **20.535** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **2.076190190** | 974524636 | **20.762** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 2.455842347 | 659572049 | 24.558 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 3.253694343 | 967973077 | 32.537 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 3.428036930 | 2520784966 | 34.280 | No | 6 |
| wi | WikiSort Fully In-Place | 4.006508981 | 2411074399 | 40.065 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 4.906647696 | 2341700849 | 49.066 | Yes | 8 |
| gs | GrailSort Fully In-Place | 5.431933373 | 2358423063 | 54.319 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **1.066018853** | 324496683 | **10.660** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **1.225825884** | 549880575 | **12.258** | No | 2 |
| fs | ForSort Stable Fully In-Place | **1.265544466** | 547263352 | **12.655** | Yes | 3 |
| fw | ForSort With Allocated Workspace | 1.287719936 | 515995154 | 12.877 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 1.557156544 | 550858695 | 15.572 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 2.805740082 | 2503094341 | 28.057 | No | 6 |
| wi | WikiSort Fully In-Place | 2.970568501 | 1989970645 | 29.706 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 3.939681435 | 2138241987 | 39.397 | Yes | 8 |
| gs | GrailSort Fully In-Place | 4.310270590 | 2022641308 | 43.103 | Yes | 9 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.077920992** | 99999999 | **0.779** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.079436309** | 99999999 | **0.794** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.118980518** | 99999999 | **1.190** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.143129325 | 100000429 | 1.431 | Yes | 4 |
| fw | ForSort With Allocated Workspace | 0.193546060 | 100000101 | 1.935 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.227993083 | 223276977 | 2.280 | Yes | 6 |
| gs | GrailSort Fully In-Place | 2.203237033 | 840205773 | 22.032 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 2.364520825 | 1314447104 | 23.645 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 2.584375772 | 2523415216 | 25.844 | No | 9 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **1.620018979** | 418701728 | **16.200** | Yes | 1 |
| wi | WikiSort Fully In-Place | **2.056417704** | 736637378 | **20.564** | Yes | 2 |
| gs | GrailSort Fully In-Place | **2.720371769** | 916679743 | **27.204** | Yes | 3 |
| fw | ForSort With Allocated Workspace | 3.078092344 | 2232941532 | 30.781 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 3.167525679 | 2805397135 | 31.675 | No | 5 |
| fi | ForSort Unstable Fully In-Place | 3.447778443 | 2171401168 | 34.478 | No | 6 |
| fs | ForSort Stable Fully In-Place | 3.591152225 | 2027889676 | 35.912 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 4.999685311 | 1363129466 | 49.997 | Yes | 8 |
| fb | ForSort Basic Fully In-Place | 5.360527615 | 871236038 | 53.605 | Yes | 9 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.104849460** | 99999999 | **1.048** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.123838466** | 99999999 | **1.238** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.156446791** | 99999999 | **1.564** | Yes | 3 |
| wi | WikiSort Fully In-Place | 1.259024800 | 266513829 | 12.590 | Yes | 4 |
| gs | GrailSort Fully In-Place | 2.274759396 | 896694624 | 22.748 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 3.032656767 | 2240136721 | 30.327 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 3.085241214 | 2921036489 | 30.852 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 3.145355958 | 1351335168 | 31.454 | Yes | 8 |
| fi | ForSort Unstable Fully In-Place | 3.393423958 | 2176935091 | 33.934 | Yes | 9 |


## Stability Verification

| Sort Type | Name | Stable |
|-----------|------|--------|
| fb | ForSort Basic Fully In-Place | Yes |
| fi | ForSort Unstable Fully In-Place | No |
| fs | ForSort Stable Fully In-Place | Yes |
| fw | ForSort With Allocated Workspace | Yes |
| gs | GrailSort Fully In-Place | Yes |
| gq | GLibc Quick Sort Fully In-Place | Yes |
| nq | Bentley/McIlroy Quick Sort In-Place | No |
| ti | TimSort with Allocated Workspace | Yes |
| wi | WikiSort Fully In-Place | Yes |
| is | Insertion Sort Fully In-Place | Yes |

---
*Generated automatically from benchmark_results.csv*
