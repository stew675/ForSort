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

*Analysis excludes reverse-ordered test scenarios which are statistical outliers rarely seen in practice.*

### Overall Performance Ranking

| Rank | Sort Type | Name | Avg Rank | Wins | Top 3 |
|------|-----------|------|----------|------|-------|
| 1 | **fw** | ForSort With Allocated Workspace | 1.81 | 27 | 36 |
| 2 | **fi** | ForSort Unstable Fully In-Place | 2.86 | 0 | 34 |
| 3 | **fs** | ForSort Stable Fully In-Place | 3.69 | 0 | 26 |
| 4 | fb | ForSort Basic Fully In-Place | 4.12 | 3 | 8 |
| 5 | ti | TimSort with Allocated Workspace | 5.02 | 7 | 11 |
| 6 | wi | WikiSort Fully In-Place | 5.93 | 1 | 3 |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 6.83 | 0 | 0 |
| 8 | is | Insertion Sort Fully In-Place | 7.71 | 4 | 8 |
| 9 | gs | GrailSort Fully In-Place | 7.76 | 0 | 0 |
| 10 | gq | GLibc Quick Sort Fully In-Place | 9.26 | 0 | 0 |

*Rankings based on average finish position across all test categories (excluding reverse-ordered scenarios). Skipped results (e.g., Insertion Sort for large datasets) counted as last place.*

### Recommendations by Use Case

- **Best Stable Sort:** fs (ForSort Stable Fully In-Place) - Avg: 15.692 ns/item (1M-100M items)
- **Best Unstable Sort:** fi (ForSort Unstable Fully In-Place) - Avg: 20.824 ns/item (1M-100M items)
- **Best for Nearly-Sorted Data:** fw (ForSort With Allocated Workspace) - Avg: 6.487 ns/item
- **Best for Random Data:** fw (ForSort With Allocated Workspace) - Avg: 24.320 ns/item


## Size Winners Summary

*Excludes reverse-ordered scenarios which are statistical outliers.*

| Dataset Size | 1st Place | Avg (ns/item) | 2nd Place | Avg (ns/item) | 3rd Place | Avg (ns/item) |
|--------------|-----------|---------------|-----------|---------------|-----------|---------------|
| 100 | **fb**<br>ForSort Basic Fully In-Place | 6.627 | **fw**<br>ForSort With Allocated Workspace | 7.159 | **fi**<br>ForSort Unstable Fully In-Place | 7.572 |
| 1000 | **fw**<br>ForSort With Allocated Workspace | 8.998 | **fi**<br>ForSort Unstable Fully In-Place | 10.442 | **fb**<br>ForSort Basic Fully In-Place | 10.831 |
| 10000 | **fw**<br>ForSort With Allocated Workspace | 11.796 | **fi**<br>ForSort Unstable Fully In-Place | 13.452 | **fs**<br>ForSort Stable Fully In-Place | 13.999 |
| 100000 | **fw**<br>ForSort With Allocated Workspace | 14.703 | **fi**<br>ForSort Unstable Fully In-Place | 15.676 | **fs**<br>ForSort Stable Fully In-Place | 16.186 |
| 1000000 | **fw**<br>ForSort With Allocated Workspace | 16.172 | **fi**<br>ForSort Unstable Fully In-Place | 17.377 | **fs**<br>ForSort Stable Fully In-Place | 17.592 |
| 10000000 | **fw**<br>ForSort With Allocated Workspace | 17.509 | **fi**<br>ForSort Unstable Fully In-Place | 19.050 | **fs**<br>ForSort Stable Fully In-Place | 19.454 |
| 100000000 | **fw**<br>ForSort With Allocated Workspace | 20.835 | **fi**<br>ForSort Unstable Fully In-Place | 21.567 | **fs**<br>ForSort Stable Fully In-Place | 22.402 |


## Worst-Case Performance

This section identifies which algorithm has the best *worst-case* performance across all test variants except reverse-ordered scenarios (statistical outliers rarely seen in practice). Lower rank indicates better performance in the worst scenario encountered.

| Rank | Sort Type | Name | Worst Rank | Scenarios |
|------|-----------|------|------------|-----------|
| 1 | **fi** | ForSort Unstable Fully In-Place | 6 | 1 |
| 2 | **fw** | ForSort With Allocated Workspace | 6 | 1 |
| 3 | **fb** | ForSort Basic Fully In-Place | 7 | 1 |
| 4 | wi | WikiSort Fully In-Place | 7 | 16 |
| 5 | fs | ForSort Stable Fully In-Place | 8 | 1 |
| 6 | ti | TimSort with Allocated Workspace | 8 | 8 |
| 7 | gs | GrailSort Fully In-Place | 9 | 14 |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 10 | 2 |
| 9 | gq | GLibc Quick Sort Fully In-Place | 10 | 20 |
| 10 | is | Insertion Sort Fully In-Place | 10 | 20 |

*Worst rank indicates the highest (poorest) position achieved across all test categories. Lower worst rank = better worst-case performance.*


## Summary by Dataset Size (All Variants)

Averages across all test variants (excluding reverse-ordered scenarios which are statistical outliers). Lower values indicate better performance.

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|------------|------------|------------|------------|------------|------------|------------|
| fw | *****7.159** | *****8.998** | *****11.796** | *****14.703** | *****16.172** | *****17.509** | *****20.835** |
| fi | ****7.572** | ****10.442** | ****13.452** | ****15.676** | ****17.377** | ****19.050** | ****21.567** |
| fs | ***8.322** | ***11.599** | ***13.999** | ***16.186** | ***17.592** | ***19.454** | ***22.402** |
| fb | 6.627 | 10.831 | 15.663 | 22.144 | 28.287 | 34.558 | 42.100 |
| ti | 9.528 | 15.853 | 22.196 | 27.646 | 32.501 | 37.687 | 43.385 |
| wi | 7.910 | 12.760 | 20.802 | 27.212 | 33.210 | 40.952 | 49.279 |
| nq | 11.173 | 16.961 | 23.198 | 29.561 | 35.959 | 41.867 | 48.155 |
| gs | 12.907 | 17.977 | 24.183 | 30.168 | 38.107 | 46.559 | 57.259 |
| gq | 13.858 | 22.209 | 30.283 | 36.640 | 44.310 | 53.537 | 63.134 |
| is | 8.234 | 16.837 | 34.593 | 195.57 | 2454.3 | - | - |


## Summary by Dataset Size and Test Variant

### Fully Random

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****19.417** | *****17.205** | *****18.581** | *****23.899** | *****26.034** | *****29.048** | *****36.057** |
| fi | ****21.540** | ****20.726** | ****22.614** | ****26.869** | ****30.142** | ****33.502** | ****38.895** |
| fs | ***21.498** | ***23.534** | ***23.889** | ***27.495** | ***29.729** | ***34.348** | ***41.713** |
| fb | 15.409 | 20.705 | 27.549 | 47.933 | 66.723 | 86.221 | 107.08 |
| gs | 30.553 | 38.399 | 47.336 | 56.314 | 66.149 | 77.385 | 91.972 |
| wi | 21.894 | 32.195 | 49.119 | 61.693 | 74.287 | 91.485 | 106.65 |
| nq | 25.394 | 37.787 | 50.360 | 62.808 | 75.460 | 87.763 | 100.08 |
| ti | 27.581 | 43.660 | 59.659 | 74.351 | 88.799 | 104.66 | 121.17 |
| gq | 32.389 | 48.791 | 65.082 | 77.021 | 91.701 | 109.74 | 126.32 |
| is | 27.644 | 48.386 | 116.31 | 963.58 | 13204.3 | - | - |

### 25 Percent Disordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****12.030** | *****17.121** | *****20.217** | *****24.044** | *****26.842** | *****28.213** | *****33.764** |
| fi | ****12.600** | ****18.969** | ****22.135** | ****25.048** | ****27.747** | ****29.672** | ****33.879** |
| fs | ***14.260** | ***22.224** | ***23.913** | ***26.420** | ***28.623** | ***31.673** | ***35.437** |
| fb | 11.809 | 20.238 | 26.854 | 34.307 | 44.140 | 52.776 | 64.186 |
| nq | 13.305 | 21.299 | 29.651 | 37.345 | 45.769 | 53.572 | 62.041 |
| wi | 11.481 | 19.062 | 31.127 | 38.757 | 46.462 | 56.127 | 67.054 |
| ti | 14.001 | 24.814 | 35.380 | 43.337 | 49.716 | 58.523 | 67.205 |
| gs | 16.443 | 26.450 | 35.278 | 42.614 | 52.291 | 61.010 | 72.613 |
| gq | 18.173 | 30.187 | 40.383 | 47.935 | 56.913 | 69.370 | 81.218 |
| is | 11.966 | 26.802 | 40.064 | 124.34 | 1235.1 | - | - |

### 10 Percent Disordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****4.709** | *****10.587** | *****15.299** | *****18.443** | *****19.800** | *****21.057** | *****24.440** |
| fi | ****4.809** | ****12.286** | ****17.123** | ****19.147** | ****20.588** | ****23.011** | ****24.883** |
| fs | ***6.481** | ***12.302** | ***17.223** | ***19.628** | ***21.396** | ***22.605** | ***25.408** |
| fb | 5.707 | 12.401 | 19.213 | 22.716 | 26.699 | 31.421 | 37.978 |
| ti | 7.057 | 13.391 | 19.642 | 23.807 | 27.181 | 30.852 | 35.891 |
| nq | 8.525 | 13.104 | 19.098 | 24.170 | 30.288 | 35.413 | 40.334 |
| wi | 5.495 | 11.688 | 19.450 | 26.390 | 31.772 | 40.152 | 47.572 |
| gs | 9.662 | 15.360 | 23.681 | 30.942 | 39.438 | 49.257 | 60.339 |
| gq | 10.422 | 19.448 | 27.275 | 32.641 | 39.573 | 48.010 | 57.707 |
| is | 4.684 | 14.419 | 23.805 | 37.969 | 189.93 | - | - |

### 5 Percent Disordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****3.047** | *****6.221** | *****11.614** | *****13.938** | *****15.296** | *****16.468** | *****18.834** |
| fi | ****2.960** | ****7.381** | ****13.182** | ****14.635** | ****16.207** | ****17.418** | ****19.591** |
| fs | ***4.043** | ***7.359** | ***12.934** | ***15.088** | ***16.130** | ***17.679** | ***19.565** |
| ti | 5.137 | 8.731 | 13.208 | 16.791 | 19.857 | 22.151 | 24.532 |
| fb | 3.518 | 7.808 | 14.004 | 17.647 | 19.910 | 23.511 | 27.693 |
| nq | 7.330 | 11.045 | 15.832 | 20.396 | 25.078 | 29.830 | 34.459 |
| wi | 3.704 | 7.618 | 15.814 | 20.908 | 26.020 | 33.167 | 41.428 |
| is | 2.660 | 8.433 | 19.115 | 27.018 | 70.042 | - | - |
| gs | 8.004 | 11.582 | 18.395 | 25.539 | 34.052 | 42.725 | 53.590 |
| gq | 8.336 | 14.743 | 22.329 | 27.682 | 33.858 | 41.128 | 49.466 |

### 1 Percent Disordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****1.985** | *****1.838** | *****4.155** | *****7.035** | *****8.153** | *****9.387** | *****10.973** |
| ti | ****2.430** | ****3.707** | ****4.503** | ****6.812** | ****8.545** | ****9.123** | ****10.719** |
| fi | ***1.874** | ***2.193** | ***4.737** | ***7.494** | ***8.716** | ***9.827** | ***11.236** |
| fs | 2.537 | 3.173 | 5.033 | 7.516 | 8.655 | 9.594 | 11.486 |
| fb | 2.216 | 2.837 | 5.396 | 9.391 | 11.391 | 12.616 | 14.874 |
| is | 1.371 | 1.998 | 7.297 | 19.633 | 25.455 | - | - |
| wi | 2.587 | 3.416 | 6.671 | 12.984 | 18.161 | 22.738 | 30.568 |
| nq | 6.313 | 9.566 | 12.519 | 16.637 | 20.507 | 23.608 | 27.495 |
| gs | 6.729 | 8.409 | 11.327 | 15.378 | 24.112 | 32.870 | 42.977 |
| gq | 7.046 | 10.224 | 14.618 | 20.510 | 26.404 | 32.477 | 39.783 |

### Fully Ordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| ti | *****0.964** | *****0.814** | *****0.784** | *****0.781** | *****0.905** | *****0.817** | *****0.791** |
| fb | ****1.104** | ****0.994** | ****0.962** | ****0.868** | ****0.857** | ****0.804** | ****0.791** |
| is | ***1.080** | ***0.981** | ***0.967** | ***0.872** | ***0.830** | - | - |
| fs | 1.115 | 1.001 | 1.001 | 0.969 | 1.020 | 0.828 | 0.806 |
| fi | 1.651 | 1.096 | 0.920 | 0.863 | 0.864 | 0.873 | 0.920 |
| fw | 1.763 | 1.018 | 0.911 | 0.858 | 0.905 | 0.879 | 0.945 |
| wi | 2.301 | 2.582 | 2.629 | 2.542 | 2.556 | 2.045 | 2.401 |
| gs | 6.053 | 7.663 | 9.083 | 10.223 | 12.597 | 16.105 | 22.063 |
| gq | 6.781 | 9.862 | 12.010 | 14.053 | 17.413 | 20.494 | 24.308 |
| nq | 6.171 | 8.965 | 11.730 | 16.007 | 18.654 | 21.013 | 24.515 |

### Reverse Ordered Duplicates

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fb | *****4.769** | *****4.128** | *****4.121** | *****3.862** | *****3.880** | *****3.967** | *****4.074** |
| fs | ****8.745** | ****5.593** | ****4.863** | ****4.608** | ****4.638** | ****5.040** | ****6.182** |
| ti | ***9.843** | ***10.088** | ***9.828** | ***10.374** | ***10.783** | ***12.508** | ***16.397** |
| wi | 7.166 | 7.823 | 9.948 | 11.396 | 12.483 | 15.736 | 21.152 |
| fw | 10.804 | 7.989 | 11.823 | 14.042 | 18.370 | 22.690 | 28.257 |
| gs | 14.704 | 13.343 | 14.196 | 14.876 | 17.068 | 19.754 | 26.726 |
| fi | 11.825 | 9.324 | 12.098 | 14.698 | 18.901 | 24.328 | 33.507 |
| nq | 11.770 | 16.564 | 21.386 | 22.214 | 26.376 | 30.562 | 31.040 |
| gq | 20.504 | 25.349 | 32.689 | 38.483 | 37.593 | 42.882 | 50.385 |
| is | 10.394 | 22.737 | 213.59 | 2403.4 | 31225.9 | - | - |

### Reverse Ordered Uniques

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| ti | *****1.095** | *****0.963** | *****0.910** | *****0.930** | *****1.030** | *****0.975** | *****1.056** |
| fb | ****1.184** | ****1.015** | ****1.019** | ****1.013** | ****1.077** | ****1.096** | ****1.237** |
| fs | ***1.285** | ***1.083** | ***1.052** | ***1.101** | ***1.212** | ***1.270** | ***1.576** |
| wi | 3.028 | 3.504 | 4.450 | 5.017 | 5.973 | 6.906 | 12.612 |
| gs | 6.456 | 7.999 | 9.519 | 10.617 | 13.242 | 15.678 | 22.880 |
| fw | 7.587 | 7.046 | 10.533 | 12.876 | 17.554 | 21.959 | 27.392 |
| fi | 8.509 | 7.324 | 10.501 | 13.343 | 18.087 | 23.531 | 33.459 |
| gq | 9.613 | 11.837 | 14.865 | 17.217 | 19.770 | 25.100 | 31.903 |
| nq | 11.382 | 17.187 | 22.776 | 21.643 | 26.162 | 31.098 | 29.682 |
| is | 8.855 | 22.005 | 215.94 | 2432.2 | 31213.1 | - | - |


## Performance Rankings

### 100 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | ForSort Basic Fully In-Place | 15.409 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 19.417 | 26.0% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 21.498 | 39.5% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 21.540 | 39.8% | No |
| 5 | wi | WikiSort Fully In-Place | 21.894 | 42.1% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 25.394 | 64.8% | No |
| 7 | ti | TimSort with Allocated Workspace | 27.581 | 79.0% | Yes |
| 8 | is | Insertion Sort Fully In-Place | 27.644 | 79.4% | Yes |
| 9 | gs | GrailSort Fully In-Place | 30.553 | 98.3% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 32.389 | 110.2% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **wi** | WikiSort Fully In-Place | 11.481 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 11.809 | 2.9% | Yes |
| 3 | **is** | Insertion Sort Fully In-Place | 11.966 | 4.2% | Yes |
| 4 | fw | ForSort With Allocated Workspace | 12.030 | 4.8% | Yes |
| 5 | fi | ForSort Unstable Fully In-Place | 12.600 | 9.7% | No |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 13.305 | 15.9% | No |
| 7 | ti | TimSort with Allocated Workspace | 14.001 | 21.9% | Yes |
| 8 | fs | ForSort Stable Fully In-Place | 14.260 | 24.2% | Yes |
| 9 | gs | GrailSort Fully In-Place | 16.443 | 43.2% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 18.173 | 58.3% | No |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort Fully In-Place | 4.684 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 4.709 | 0.5% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 4.809 | 2.7% | No |
| 4 | wi | WikiSort Fully In-Place | 5.495 | 17.3% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 5.707 | 21.8% | Yes |
| 6 | fs | ForSort Stable Fully In-Place | 6.481 | 38.4% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 7.057 | 50.7% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 8.525 | 82.0% | No |
| 9 | gs | GrailSort Fully In-Place | 9.662 | 106.3% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 10.422 | 122.5% | No |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort Fully In-Place | 2.660 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 2.960 | 11.3% | No |
| 3 | **fw** | ForSort With Allocated Workspace | 3.047 | 14.5% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 3.518 | 32.3% | Yes |
| 5 | wi | WikiSort Fully In-Place | 3.704 | 39.2% | Yes |
| 6 | fs | ForSort Stable Fully In-Place | 4.043 | 52.0% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 5.137 | 93.1% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 7.330 | 175.6% | No |
| 9 | gs | GrailSort Fully In-Place | 8.004 | 200.9% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 8.336 | 213.4% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort Fully In-Place | 1.371 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 1.874 | 36.7% | No |
| 3 | **fw** | ForSort With Allocated Workspace | 1.985 | 44.8% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 2.216 | 61.6% | Yes |
| 5 | ti | TimSort with Allocated Workspace | 2.430 | 77.2% | Yes |
| 6 | fs | ForSort Stable Fully In-Place | 2.537 | 85.0% | Yes |
| 7 | wi | WikiSort Fully In-Place | 2.587 | 88.7% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 6.313 | 360.5% | No |
| 9 | gs | GrailSort Fully In-Place | 6.729 | 390.8% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 7.046 | 413.9% | No |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.964 | 0.0% | Yes |
| 2 | **is** | Insertion Sort Fully In-Place | 1.080 | 12.0% | Yes |
| 3 | **fb** | ForSort Basic Fully In-Place | 1.104 | 14.5% | Yes |
| 4 | fs | ForSort Stable Fully In-Place | 1.115 | 15.7% | Yes |
| 5 | fi | ForSort Unstable Fully In-Place | 1.651 | 71.3% | No |
| 6 | fw | ForSort With Allocated Workspace | 1.763 | 82.9% | Yes |
| 7 | wi | WikiSort Fully In-Place | 2.301 | 138.7% | Yes |
| 8 | gs | GrailSort Fully In-Place | 6.053 | 527.9% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 6.171 | 540.1% | No |
| 10 | gq | GLibc Quick Sort Fully In-Place | 6.781 | 603.4% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | ForSort Basic Fully In-Place | 4.769 | 0.0% | Yes |
| 2 | **wi** | WikiSort Fully In-Place | 7.166 | 50.3% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 8.745 | 83.4% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 9.843 | 106.4% | Yes |
| 5 | is | Insertion Sort Fully In-Place | 10.394 | 117.9% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 10.804 | 126.5% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 11.770 | 146.8% | No |
| 8 | fi | ForSort Unstable Fully In-Place | 11.825 | 148.0% | No |
| 9 | gs | GrailSort Fully In-Place | 14.704 | 208.3% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 20.504 | 329.9% | No |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 1.095 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.184 | 8.1% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.285 | 17.4% | Yes |
| 4 | wi | WikiSort Fully In-Place | 3.028 | 176.5% | Yes |
| 5 | gs | GrailSort Fully In-Place | 6.456 | 489.6% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 7.587 | 592.9% | Yes |
| 7 | fi | ForSort Unstable Fully In-Place | 8.509 | 677.1% | No |
| 8 | is | Insertion Sort Fully In-Place | 8.855 | 708.7% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 9.613 | 777.9% | No |
| 10 | nq | Bentley/McIlroy Quick Sort In-Place | 11.382 | 939.5% | No |

### 1000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 17.205 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 20.705 | 20.3% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 20.726 | 20.5% | No |
| 4 | fs | ForSort Stable Fully In-Place | 23.534 | 36.8% | Yes |
| 5 | wi | WikiSort Fully In-Place | 32.195 | 87.1% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 37.787 | 119.6% | No |
| 7 | gs | GrailSort Fully In-Place | 38.399 | 123.2% | Yes |
| 8 | ti | TimSort with Allocated Workspace | 43.660 | 153.8% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 48.386 | 181.2% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 48.791 | 183.6% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 17.121 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 18.969 | 10.8% | No |
| 3 | **wi** | WikiSort Fully In-Place | 19.062 | 11.3% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 20.238 | 18.2% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 21.299 | 24.4% | No |
| 6 | fs | ForSort Stable Fully In-Place | 22.224 | 29.8% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 24.814 | 44.9% | Yes |
| 8 | gs | GrailSort Fully In-Place | 26.450 | 54.5% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 26.802 | 56.5% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 30.187 | 76.3% | No |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 10.587 | 0.0% | Yes |
| 2 | **wi** | WikiSort Fully In-Place | 11.688 | 10.4% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 12.286 | 16.0% | No |
| 4 | fs | ForSort Stable Fully In-Place | 12.302 | 16.2% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 12.401 | 17.1% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 13.104 | 23.8% | No |
| 7 | ti | TimSort with Allocated Workspace | 13.391 | 26.5% | Yes |
| 8 | is | Insertion Sort Fully In-Place | 14.419 | 36.2% | Yes |
| 9 | gs | GrailSort Fully In-Place | 15.360 | 45.1% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 19.448 | 83.7% | No |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 6.221 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 7.359 | 18.3% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 7.381 | 18.6% | No |
| 4 | wi | WikiSort Fully In-Place | 7.618 | 22.5% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 7.808 | 25.5% | Yes |
| 6 | is | Insertion Sort Fully In-Place | 8.433 | 35.6% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 8.731 | 40.3% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 11.045 | 77.5% | No |
| 9 | gs | GrailSort Fully In-Place | 11.582 | 86.2% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 14.743 | 137.0% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 1.838 | 0.0% | Yes |
| 2 | **is** | Insertion Sort Fully In-Place | 1.998 | 8.7% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 2.193 | 19.3% | No |
| 4 | fb | ForSort Basic Fully In-Place | 2.837 | 54.4% | Yes |
| 5 | fs | ForSort Stable Fully In-Place | 3.173 | 72.6% | Yes |
| 6 | wi | WikiSort Fully In-Place | 3.416 | 85.9% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 3.707 | 101.7% | Yes |
| 8 | gs | GrailSort Fully In-Place | 8.409 | 357.5% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 9.566 | 420.5% | No |
| 10 | gq | GLibc Quick Sort Fully In-Place | 10.224 | 456.3% | No |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.814 | 0.0% | Yes |
| 2 | **is** | Insertion Sort Fully In-Place | 0.981 | 20.5% | Yes |
| 3 | **fb** | ForSort Basic Fully In-Place | 0.994 | 22.1% | Yes |
| 4 | fs | ForSort Stable Fully In-Place | 1.001 | 23.0% | Yes |
| 5 | fw | ForSort With Allocated Workspace | 1.018 | 25.1% | Yes |
| 6 | fi | ForSort Unstable Fully In-Place | 1.096 | 34.6% | No |
| 7 | wi | WikiSort Fully In-Place | 2.582 | 217.2% | Yes |
| 8 | gs | GrailSort Fully In-Place | 7.663 | 841.4% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 8.965 | 1001.4% | No |
| 10 | gq | GLibc Quick Sort Fully In-Place | 9.862 | 1111.5% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | ForSort Basic Fully In-Place | 4.128 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 5.593 | 35.5% | Yes |
| 3 | **wi** | WikiSort Fully In-Place | 7.823 | 89.5% | Yes |
| 4 | fw | ForSort With Allocated Workspace | 7.989 | 93.5% | Yes |
| 5 | fi | ForSort Unstable Fully In-Place | 9.324 | 125.9% | No |
| 6 | ti | TimSort with Allocated Workspace | 10.088 | 144.4% | Yes |
| 7 | gs | GrailSort Fully In-Place | 13.343 | 223.2% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 16.564 | 301.3% | No |
| 9 | is | Insertion Sort Fully In-Place | 22.737 | 450.8% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 25.349 | 514.1% | No |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.963 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.015 | 5.4% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.083 | 12.5% | Yes |
| 4 | wi | WikiSort Fully In-Place | 3.504 | 263.9% | Yes |
| 5 | fw | ForSort With Allocated Workspace | 7.046 | 631.7% | Yes |
| 6 | fi | ForSort Unstable Fully In-Place | 7.324 | 660.5% | No |
| 7 | gs | GrailSort Fully In-Place | 7.999 | 730.6% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 11.837 | 1129.2% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 17.187 | 1684.7% | No |
| 10 | is | Insertion Sort Fully In-Place | 22.005 | 2185.0% | Yes |

### 10000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 18.581 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 22.614 | 21.7% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 23.889 | 28.6% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 27.549 | 48.3% | Yes |
| 5 | gs | GrailSort Fully In-Place | 47.336 | 154.8% | Yes |
| 6 | wi | WikiSort Fully In-Place | 49.119 | 164.4% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 50.360 | 171.0% | No |
| 8 | ti | TimSort with Allocated Workspace | 59.659 | 221.1% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 65.082 | 250.3% | No |
| 10 | is | Insertion Sort Fully In-Place | 116.31 | 526.0% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 20.217 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 22.135 | 9.5% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 23.913 | 18.3% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 26.854 | 32.8% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 29.651 | 46.7% | No |
| 6 | wi | WikiSort Fully In-Place | 31.127 | 54.0% | Yes |
| 7 | gs | GrailSort Fully In-Place | 35.278 | 74.5% | Yes |
| 8 | ti | TimSort with Allocated Workspace | 35.380 | 75.0% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 40.064 | 98.2% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 40.383 | 99.7% | No |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 15.299 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 17.123 | 11.9% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 17.223 | 12.6% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort In-Place | 19.098 | 24.8% | No |
| 5 | fb | ForSort Basic Fully In-Place | 19.213 | 25.6% | Yes |
| 6 | wi | WikiSort Fully In-Place | 19.450 | 27.1% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 19.642 | 28.4% | Yes |
| 8 | gs | GrailSort Fully In-Place | 23.681 | 54.8% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 23.805 | 55.6% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 27.275 | 78.3% | No |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 11.614 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 12.934 | 11.4% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 13.182 | 13.5% | No |
| 4 | ti | TimSort with Allocated Workspace | 13.208 | 13.7% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 14.004 | 20.6% | Yes |
| 6 | wi | WikiSort Fully In-Place | 15.814 | 36.2% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 15.832 | 36.3% | No |
| 8 | gs | GrailSort Fully In-Place | 18.395 | 58.4% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 19.115 | 64.6% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 22.329 | 92.3% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 4.155 | 0.0% | Yes |
| 2 | **ti** | TimSort with Allocated Workspace | 4.503 | 8.4% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 4.737 | 14.0% | No |
| 4 | fs | ForSort Stable Fully In-Place | 5.033 | 21.1% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 5.396 | 29.9% | Yes |
| 6 | wi | WikiSort Fully In-Place | 6.671 | 60.6% | Yes |
| 7 | is | Insertion Sort Fully In-Place | 7.297 | 75.6% | Yes |
| 8 | gs | GrailSort Fully In-Place | 11.327 | 172.6% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 12.519 | 201.3% | No |
| 10 | gq | GLibc Quick Sort Fully In-Place | 14.618 | 251.8% | No |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.784 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 0.911 | 16.2% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 0.920 | 17.3% | No |
| 4 | fb | ForSort Basic Fully In-Place | 0.962 | 22.7% | Yes |
| 5 | is | Insertion Sort Fully In-Place | 0.967 | 23.3% | Yes |
| 6 | fs | ForSort Stable Fully In-Place | 1.001 | 27.7% | Yes |
| 7 | wi | WikiSort Fully In-Place | 2.629 | 235.3% | Yes |
| 8 | gs | GrailSort Fully In-Place | 9.083 | 1058.5% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 11.730 | 1396.2% | No |
| 10 | gq | GLibc Quick Sort Fully In-Place | 12.010 | 1431.9% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | ForSort Basic Fully In-Place | 4.121 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 4.863 | 18.0% | Yes |
| 3 | **ti** | TimSort with Allocated Workspace | 9.828 | 138.5% | Yes |
| 4 | wi | WikiSort Fully In-Place | 9.948 | 141.4% | Yes |
| 5 | fw | ForSort With Allocated Workspace | 11.823 | 186.9% | Yes |
| 6 | fi | ForSort Unstable Fully In-Place | 12.098 | 193.6% | No |
| 7 | gs | GrailSort Fully In-Place | 14.196 | 244.5% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 21.386 | 419.0% | No |
| 9 | gq | GLibc Quick Sort Fully In-Place | 32.689 | 693.2% | No |
| 10 | is | Insertion Sort Fully In-Place | 213.59 | 5083.0% | Yes |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.910 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.019 | 12.0% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.052 | 15.6% | Yes |
| 4 | wi | WikiSort Fully In-Place | 4.450 | 389.0% | Yes |
| 5 | gs | GrailSort Fully In-Place | 9.519 | 946.0% | Yes |
| 6 | fi | ForSort Unstable Fully In-Place | 10.501 | 1054.0% | No |
| 7 | fw | ForSort With Allocated Workspace | 10.533 | 1057.5% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 14.865 | 1533.5% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 22.776 | 2402.9% | No |
| 10 | is | Insertion Sort Fully In-Place | 215.94 | 23630.2% | Yes |

### 100000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 23.899 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 26.869 | 12.4% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 27.495 | 15.0% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 47.933 | 100.6% | Yes |
| 5 | gs | GrailSort Fully In-Place | 56.314 | 135.6% | Yes |
| 6 | wi | WikiSort Fully In-Place | 61.693 | 158.1% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 62.808 | 162.8% | No |
| 8 | ti | TimSort with Allocated Workspace | 74.351 | 211.1% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 77.021 | 222.3% | No |
| 10 | is | Insertion Sort Fully In-Place | 963.58 | 3931.9% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 24.044 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 25.048 | 4.2% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 26.420 | 9.9% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 34.307 | 42.7% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 37.345 | 55.3% | No |
| 6 | wi | WikiSort Fully In-Place | 38.757 | 61.2% | Yes |
| 7 | gs | GrailSort Fully In-Place | 42.614 | 77.2% | Yes |
| 8 | ti | TimSort with Allocated Workspace | 43.337 | 80.2% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 47.935 | 99.4% | No |
| 10 | is | Insertion Sort Fully In-Place | 124.34 | 417.1% | Yes |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 18.443 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 19.147 | 3.8% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 19.628 | 6.4% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 22.716 | 23.2% | Yes |
| 5 | ti | TimSort with Allocated Workspace | 23.807 | 29.1% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 24.170 | 31.1% | No |
| 7 | wi | WikiSort Fully In-Place | 26.390 | 43.1% | Yes |
| 8 | gs | GrailSort Fully In-Place | 30.942 | 67.8% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 32.641 | 77.0% | No |
| 10 | is | Insertion Sort Fully In-Place | 37.969 | 105.9% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 13.938 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 14.635 | 5.0% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 15.088 | 8.3% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 16.791 | 20.5% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 17.647 | 26.6% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 20.396 | 46.3% | No |
| 7 | wi | WikiSort Fully In-Place | 20.908 | 50.0% | Yes |
| 8 | gs | GrailSort Fully In-Place | 25.539 | 83.2% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 27.018 | 93.8% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 27.682 | 98.6% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 6.812 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 7.035 | 3.3% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 7.494 | 10.0% | No |
| 4 | fs | ForSort Stable Fully In-Place | 7.516 | 10.3% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 9.391 | 37.9% | Yes |
| 6 | wi | WikiSort Fully In-Place | 12.984 | 90.6% | Yes |
| 7 | gs | GrailSort Fully In-Place | 15.378 | 125.7% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 16.637 | 144.2% | No |
| 9 | is | Insertion Sort Fully In-Place | 19.633 | 188.2% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 20.510 | 201.1% | No |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.781 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 0.858 | 9.9% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 0.863 | 10.5% | No |
| 4 | fb | ForSort Basic Fully In-Place | 0.868 | 11.1% | Yes |
| 5 | is | Insertion Sort Fully In-Place | 0.872 | 11.7% | Yes |
| 6 | fs | ForSort Stable Fully In-Place | 0.969 | 24.1% | Yes |
| 7 | wi | WikiSort Fully In-Place | 2.542 | 225.5% | Yes |
| 8 | gs | GrailSort Fully In-Place | 10.223 | 1209.0% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 14.053 | 1699.4% | No |
| 10 | nq | Bentley/McIlroy Quick Sort In-Place | 16.007 | 1949.6% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | ForSort Basic Fully In-Place | 3.862 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 4.608 | 19.3% | Yes |
| 3 | **ti** | TimSort with Allocated Workspace | 10.374 | 168.6% | Yes |
| 4 | wi | WikiSort Fully In-Place | 11.396 | 195.1% | Yes |
| 5 | fw | ForSort With Allocated Workspace | 14.042 | 263.6% | Yes |
| 6 | fi | ForSort Unstable Fully In-Place | 14.698 | 280.6% | No |
| 7 | gs | GrailSort Fully In-Place | 14.876 | 285.2% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 22.214 | 475.2% | No |
| 9 | gq | GLibc Quick Sort Fully In-Place | 38.483 | 896.5% | No |
| 10 | is | Insertion Sort Fully In-Place | 2403.4 | 62130.9% | Yes |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.930 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.013 | 8.9% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.101 | 18.4% | Yes |
| 4 | wi | WikiSort Fully In-Place | 5.017 | 439.5% | Yes |
| 5 | gs | GrailSort Fully In-Place | 10.617 | 1041.6% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 12.876 | 1284.5% | Yes |
| 7 | fi | ForSort Unstable Fully In-Place | 13.343 | 1334.7% | No |
| 8 | gq | GLibc Quick Sort Fully In-Place | 17.217 | 1751.3% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 21.643 | 2227.2% | No |
| 10 | is | Insertion Sort Fully In-Place | 2432.2 | 261431.6% | Yes |

### 1000000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 26.034 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 29.729 | 14.2% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 30.142 | 15.8% | No |
| 4 | gs | GrailSort Fully In-Place | 66.149 | 154.1% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 66.723 | 156.3% | Yes |
| 6 | wi | WikiSort Fully In-Place | 74.287 | 185.3% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 75.460 | 189.9% | No |
| 8 | ti | TimSort with Allocated Workspace | 88.799 | 241.1% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 91.701 | 252.2% | No |
| 10 | is | Insertion Sort Fully In-Place | 13204.3 | 50619.4% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 26.842 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 27.747 | 3.4% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 28.623 | 6.6% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 44.140 | 64.4% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 45.769 | 70.5% | No |
| 6 | wi | WikiSort Fully In-Place | 46.462 | 73.1% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 49.716 | 85.2% | Yes |
| 8 | gs | GrailSort Fully In-Place | 52.291 | 94.8% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 56.913 | 112.0% | No |
| 10 | is | Insertion Sort Fully In-Place | 1235.1 | 4501.3% | Yes |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 19.800 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 20.588 | 4.0% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 21.396 | 8.1% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 26.699 | 34.8% | Yes |
| 5 | ti | TimSort with Allocated Workspace | 27.181 | 37.3% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 30.288 | 53.0% | No |
| 7 | wi | WikiSort Fully In-Place | 31.772 | 60.5% | Yes |
| 8 | gs | GrailSort Fully In-Place | 39.438 | 99.2% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 39.573 | 99.9% | No |
| 10 | is | Insertion Sort Fully In-Place | 189.93 | 859.2% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 15.296 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 16.130 | 5.5% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 16.207 | 6.0% | No |
| 4 | ti | TimSort with Allocated Workspace | 19.857 | 29.8% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 19.910 | 30.2% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 25.078 | 64.0% | No |
| 7 | wi | WikiSort Fully In-Place | 26.020 | 70.1% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 33.858 | 121.4% | No |
| 9 | gs | GrailSort Fully In-Place | 34.052 | 122.6% | Yes |
| 10 | is | Insertion Sort Fully In-Place | 70.042 | 357.9% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 8.153 | 0.0% | Yes |
| 2 | **ti** | TimSort with Allocated Workspace | 8.545 | 4.8% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 8.655 | 6.2% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 8.716 | 6.9% | No |
| 5 | fb | ForSort Basic Fully In-Place | 11.391 | 39.7% | Yes |
| 6 | wi | WikiSort Fully In-Place | 18.161 | 122.8% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 20.507 | 151.5% | No |
| 8 | gs | GrailSort Fully In-Place | 24.112 | 195.7% | Yes |
| 9 | is | Insertion Sort Fully In-Place | 25.455 | 212.2% | Yes |
| 10 | gq | GLibc Quick Sort Fully In-Place | 26.404 | 223.9% | No |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort Fully In-Place | 0.830 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 0.857 | 3.3% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 0.864 | 4.1% | No |
| 4 | fw | ForSort With Allocated Workspace | 0.905 | 9.0% | Yes |
| 5 | ti | TimSort with Allocated Workspace | 0.905 | 9.0% | Yes |
| 6 | fs | ForSort Stable Fully In-Place | 1.020 | 22.9% | Yes |
| 7 | wi | WikiSort Fully In-Place | 2.556 | 208.0% | Yes |
| 8 | gs | GrailSort Fully In-Place | 12.597 | 1417.7% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 17.413 | 1998.0% | No |
| 10 | nq | Bentley/McIlroy Quick Sort In-Place | 18.654 | 2147.5% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | ForSort Basic Fully In-Place | 3.880 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 4.638 | 19.5% | Yes |
| 3 | **ti** | TimSort with Allocated Workspace | 10.783 | 177.9% | Yes |
| 4 | wi | WikiSort Fully In-Place | 12.483 | 221.7% | Yes |
| 5 | gs | GrailSort Fully In-Place | 17.068 | 339.9% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 18.370 | 373.5% | Yes |
| 7 | fi | ForSort Unstable Fully In-Place | 18.901 | 387.1% | No |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 26.376 | 579.8% | No |
| 9 | gq | GLibc Quick Sort Fully In-Place | 37.593 | 868.9% | No |
| 10 | is | Insertion Sort Fully In-Place | 31225.9 | 804692.4% | Yes |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 1.030 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.077 | 4.6% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.212 | 17.7% | Yes |
| 4 | wi | WikiSort Fully In-Place | 5.973 | 479.9% | Yes |
| 5 | gs | GrailSort Fully In-Place | 13.242 | 1185.6% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 17.554 | 1604.3% | Yes |
| 7 | fi | ForSort Unstable Fully In-Place | 18.087 | 1656.0% | No |
| 8 | gq | GLibc Quick Sort Fully In-Place | 19.770 | 1819.4% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 26.162 | 2440.0% | No |
| 10 | is | Insertion Sort Fully In-Place | 31213.1 | 3030299.6% | Yes |

### 10000000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 29.048 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 33.502 | 15.3% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 34.348 | 18.2% | Yes |
| 4 | gs | GrailSort Fully In-Place | 77.385 | 166.4% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 86.221 | 196.8% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 87.763 | 202.1% | No |
| 7 | wi | WikiSort Fully In-Place | 91.485 | 214.9% | Yes |
| 8 | ti | TimSort with Allocated Workspace | 104.66 | 260.3% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 109.74 | 277.8% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 28.213 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 29.672 | 5.2% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 31.673 | 12.3% | Yes |
| 4 | fb | ForSort Basic Fully In-Place | 52.776 | 87.1% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 53.572 | 89.9% | No |
| 6 | wi | WikiSort Fully In-Place | 56.127 | 98.9% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 58.523 | 107.4% | Yes |
| 8 | gs | GrailSort Fully In-Place | 61.010 | 116.2% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 69.370 | 145.9% | No |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 21.057 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 22.605 | 7.4% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 23.011 | 9.3% | No |
| 4 | ti | TimSort with Allocated Workspace | 30.852 | 46.5% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 31.421 | 49.2% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 35.413 | 68.2% | No |
| 7 | wi | WikiSort Fully In-Place | 40.152 | 90.7% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 48.010 | 128.0% | No |
| 9 | gs | GrailSort Fully In-Place | 49.257 | 133.9% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 16.468 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 17.418 | 5.8% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 17.679 | 7.4% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 22.151 | 34.5% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 23.511 | 42.8% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 29.830 | 81.1% | No |
| 7 | wi | WikiSort Fully In-Place | 33.167 | 101.4% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 41.128 | 149.7% | No |
| 9 | gs | GrailSort Fully In-Place | 42.725 | 159.4% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 9.123 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 9.387 | 2.9% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 9.594 | 5.2% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 9.827 | 7.7% | No |
| 5 | fb | ForSort Basic Fully In-Place | 12.616 | 38.3% | Yes |
| 6 | wi | WikiSort Fully In-Place | 22.738 | 149.2% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 23.608 | 158.8% | No |
| 8 | gq | GLibc Quick Sort Fully In-Place | 32.477 | 256.0% | No |
| 9 | gs | GrailSort Fully In-Place | 32.870 | 260.3% | Yes |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | ForSort Basic Fully In-Place | 0.804 | 0.0% | Yes |
| 2 | **ti** | TimSort with Allocated Workspace | 0.817 | 1.6% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 0.828 | 3.0% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 0.873 | 8.6% | No |
| 5 | fw | ForSort With Allocated Workspace | 0.879 | 9.3% | Yes |
| 6 | wi | WikiSort Fully In-Place | 2.045 | 154.4% | Yes |
| 7 | gs | GrailSort Fully In-Place | 16.105 | 1903.1% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 20.494 | 2449.0% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 21.013 | 2513.6% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | ForSort Basic Fully In-Place | 3.967 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 5.040 | 27.0% | Yes |
| 3 | **ti** | TimSort with Allocated Workspace | 12.508 | 215.3% | Yes |
| 4 | wi | WikiSort Fully In-Place | 15.736 | 296.7% | Yes |
| 5 | gs | GrailSort Fully In-Place | 19.754 | 398.0% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 22.690 | 472.0% | Yes |
| 7 | fi | ForSort Unstable Fully In-Place | 24.328 | 513.3% | No |
| 8 | nq | Bentley/McIlroy Quick Sort In-Place | 30.562 | 670.4% | No |
| 9 | gq | GLibc Quick Sort Fully In-Place | 42.882 | 981.0% | No |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 0.975 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.096 | 12.4% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.270 | 30.3% | Yes |
| 4 | wi | WikiSort Fully In-Place | 6.906 | 608.3% | Yes |
| 5 | gs | GrailSort Fully In-Place | 15.678 | 1508.0% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 21.959 | 2152.2% | Yes |
| 7 | fi | ForSort Unstable Fully In-Place | 23.531 | 2313.4% | No |
| 8 | gq | GLibc Quick Sort Fully In-Place | 25.100 | 2474.4% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 31.098 | 3089.5% | No |

### 100000000 Items

#### Fully Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 36.057 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 38.895 | 7.9% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 41.713 | 15.7% | Yes |
| 4 | gs | GrailSort Fully In-Place | 91.972 | 155.1% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort In-Place | 100.08 | 177.6% | No |
| 6 | wi | WikiSort Fully In-Place | 106.65 | 195.8% | Yes |
| 7 | fb | ForSort Basic Fully In-Place | 107.08 | 197.0% | Yes |
| 8 | ti | TimSort with Allocated Workspace | 121.17 | 236.1% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 126.32 | 250.3% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 33.764 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 33.879 | 0.3% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 35.437 | 5.0% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort In-Place | 62.041 | 83.7% | No |
| 5 | fb | ForSort Basic Fully In-Place | 64.186 | 90.1% | Yes |
| 6 | wi | WikiSort Fully In-Place | 67.054 | 98.6% | Yes |
| 7 | ti | TimSort with Allocated Workspace | 67.205 | 99.0% | Yes |
| 8 | gs | GrailSort Fully In-Place | 72.613 | 115.1% | Yes |
| 9 | gq | GLibc Quick Sort Fully In-Place | 81.218 | 140.5% | No |

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 24.440 | 0.0% | Yes |
| 2 | **fi** | ForSort Unstable Fully In-Place | 24.883 | 1.8% | No |
| 3 | **fs** | ForSort Stable Fully In-Place | 25.408 | 4.0% | Yes |
| 4 | ti | TimSort with Allocated Workspace | 35.891 | 46.9% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 37.978 | 55.4% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 40.334 | 65.0% | No |
| 7 | wi | WikiSort Fully In-Place | 47.572 | 94.6% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 57.707 | 136.1% | No |
| 9 | gs | GrailSort Fully In-Place | 60.339 | 146.9% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | ForSort With Allocated Workspace | 18.834 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 19.565 | 3.9% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 19.591 | 4.0% | No |
| 4 | ti | TimSort with Allocated Workspace | 24.532 | 30.3% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 27.693 | 47.0% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 34.459 | 83.0% | No |
| 7 | wi | WikiSort Fully In-Place | 41.428 | 120.0% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 49.466 | 162.6% | No |
| 9 | gs | GrailSort Fully In-Place | 53.590 | 184.5% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 10.719 | 0.0% | Yes |
| 2 | **fw** | ForSort With Allocated Workspace | 10.973 | 2.4% | Yes |
| 3 | **fi** | ForSort Unstable Fully In-Place | 11.236 | 4.8% | No |
| 4 | fs | ForSort Stable Fully In-Place | 11.486 | 7.2% | Yes |
| 5 | fb | ForSort Basic Fully In-Place | 14.874 | 38.8% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort In-Place | 27.495 | 156.5% | No |
| 7 | wi | WikiSort Fully In-Place | 30.568 | 185.2% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 39.783 | 271.1% | No |
| 9 | gs | GrailSort Fully In-Place | 42.977 | 300.9% | Yes |

#### Fully Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | ForSort Basic Fully In-Place | 0.791 | 0.0% | Yes |
| 2 | **ti** | TimSort with Allocated Workspace | 0.791 | 0.0% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 0.806 | 1.9% | Yes |
| 4 | fi | ForSort Unstable Fully In-Place | 0.920 | 16.3% | No |
| 5 | fw | ForSort With Allocated Workspace | 0.945 | 19.5% | Yes |
| 6 | wi | WikiSort Fully In-Place | 2.401 | 203.5% | Yes |
| 7 | gs | GrailSort Fully In-Place | 22.063 | 2689.3% | Yes |
| 8 | gq | GLibc Quick Sort Fully In-Place | 24.308 | 2973.1% | No |
| 9 | nq | Bentley/McIlroy Quick Sort In-Place | 24.515 | 2999.2% | No |

#### Reverse Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | ForSort Basic Fully In-Place | 4.074 | 0.0% | Yes |
| 2 | **fs** | ForSort Stable Fully In-Place | 6.182 | 51.7% | Yes |
| 3 | **ti** | TimSort with Allocated Workspace | 16.397 | 302.5% | Yes |
| 4 | wi | WikiSort Fully In-Place | 21.152 | 419.2% | Yes |
| 5 | gs | GrailSort Fully In-Place | 26.726 | 556.0% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 28.257 | 593.6% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 31.040 | 661.9% | No |
| 8 | fi | ForSort Unstable Fully In-Place | 33.507 | 722.5% | No |
| 9 | gq | GLibc Quick Sort Fully In-Place | 50.385 | 1136.7% | No |

#### Reverse Ordered Uniques

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort with Allocated Workspace | 1.056 | 0.0% | Yes |
| 2 | **fb** | ForSort Basic Fully In-Place | 1.237 | 17.1% | Yes |
| 3 | **fs** | ForSort Stable Fully In-Place | 1.576 | 49.2% | Yes |
| 4 | wi | WikiSort Fully In-Place | 12.612 | 1094.3% | Yes |
| 5 | gs | GrailSort Fully In-Place | 22.880 | 2066.7% | Yes |
| 6 | fw | ForSort With Allocated Workspace | 27.392 | 2493.9% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort In-Place | 29.682 | 2710.8% | No |
| 8 | gq | GLibc Quick Sort Fully In-Place | 31.903 | 2921.1% | No |
| 9 | fi | ForSort Unstable Fully In-Place | 33.459 | 3068.5% | No |


## Detailed Results by Dataset Size

### 100 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | ForSort Basic Fully In-Place | **0.000001541** | 758 | **15.409** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.000001942** | 691 | **19.417** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000002150** | 857 | **21.498** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.000002154 | 721 | 21.540 | Yes | 4 |
| wi | WikiSort Fully In-Place | 0.000002189 | 617 | 21.894 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000002539 | 645 | 25.394 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000002758 | 537 | 27.581 | Yes | 7 |
| is | Insertion Sort Fully In-Place | 0.000002764 | 737 | 27.644 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000003055 | 737 | 30.553 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000003239 | 540 | 32.389 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| wi | WikiSort Fully In-Place | **0.000001148** | 483 | **11.481** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000001181** | 502 | **11.809** | Yes | 2 |
| is | Insertion Sort Fully In-Place | **0.000001197** | 579 | **11.966** | Yes | 3 |
| fw | ForSort With Allocated Workspace | 0.000001203 | 408 | 12.030 | Yes | 4 |
| fi | ForSort Unstable Fully In-Place | 0.000001260 | 424 | 12.600 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000001331 | 568 | 13.305 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000001400 | 399 | 14.001 | Yes | 7 |
| fs | ForSort Stable Fully In-Place | 0.000001426 | 548 | 14.260 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000001644 | 538 | 16.443 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000001817 | 421 | 18.173 | Yes | 10 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort Fully In-Place | **0.000000468** | 269 | **4.684** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.000000471** | 206 | **4.709** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000000481** | 207 | **4.809** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000000549 | 307 | 5.495 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.000000571 | 282 | 5.707 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.000000648 | 300 | 6.481 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000000706 | 302 | 7.057 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000000852 | 537 | 8.525 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000000966 | 428 | 9.662 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000001042 | 341 | 10.422 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort Fully In-Place | **0.000000266** | 169 | **2.660** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000000296** | 154 | **2.960** | Yes | 2 |
| fw | ForSort With Allocated Workspace | **0.000000305** | 158 | **3.047** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.000000352 | 224 | 3.518 | Yes | 4 |
| wi | WikiSort Fully In-Place | 0.000000370 | 258 | 3.704 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.000000404 | 237 | 4.043 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000000514 | 248 | 5.137 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000000733 | 531 | 7.330 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000000800 | 400 | 8.004 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000000834 | 325 | 8.336 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort Fully In-Place | **0.000000137** | 111 | **1.371** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000000187** | 126 | **1.874** | Yes | 2 |
| fw | ForSort With Allocated Workspace | **0.000000198** | 132 | **1.985** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.000000222 | 186 | 2.216 | Yes | 4 |
| ti | TimSort with Allocated Workspace | 0.000000243 | 151 | 2.430 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.000000254 | 201 | 2.537 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.000000259 | 233 | 2.587 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000000631 | 523 | 6.313 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000000673 | 386 | 6.729 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000000705 | 317 | 7.046 | Yes | 10 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000000096** | 99 | **0.964** | Yes | 1 |
| is | Insertion Sort Fully In-Place | **0.000000108** | 99 | **1.080** | Yes | 2 |
| fb | ForSort Basic Fully In-Place | **0.000000110** | 99 | **1.104** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.000000111 | 99 | 1.115 | Yes | 4 |
| fi | ForSort Unstable Fully In-Place | 0.000000165 | 121 | 1.651 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.000000176 | 128 | 1.763 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.000000230 | 228 | 2.301 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000000605 | 384 | 6.053 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000000617 | 520 | 6.171 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000000678 | 316 | 6.781 | Yes | 10 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | ForSort Basic Fully In-Place | **0.000000477** | 190 | **4.769** | Yes | 1 |
| wi | WikiSort Fully In-Place | **0.000000717** | 365 | **7.166** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000000874** | 340 | **8.745** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.000000984 | 419 | 9.843 | Yes | 4 |
| is | Insertion Sort Fully In-Place | 0.000001039 | 780 | 10.394 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.000001080 | 615 | 10.804 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000001177 | 780 | 11.770 | No | 7 |
| fi | ForSort Unstable Fully In-Place | 0.000001183 | 641 | 11.825 | No | 8 |
| gs | GrailSort Fully In-Place | 0.000001470 | 520 | 14.704 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000002050 | 369 | 20.504 | Yes | 10 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000000110** | 99 | **1.095** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000000118** | 99 | **1.184** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000000128** | 99 | **1.285** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000000303 | 271 | 3.028 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.000000646 | 400 | 6.456 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.000000759 | 621 | 7.587 | Yes | 6 |
| fi | ForSort Unstable Fully In-Place | 0.000000851 | 658 | 8.509 | Yes | 7 |
| is | Insertion Sort Fully In-Place | 0.000000886 | 782 | 8.855 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.000000961 | 356 | 9.613 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000001138 | 953 | 11.382 | Yes | 10 |

### 1000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000017205** | 9624 | **17.205** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000020705** | 10939 | **20.705** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000020726** | 10249 | **20.726** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.000023534 | 10447 | 23.534 | Yes | 4 |
| wi | WikiSort Fully In-Place | 0.000032195 | 9510 | 32.195 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000037787 | 10085 | 37.787 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.000038399 | 10506 | 38.399 | Yes | 7 |
| ti | TimSort with Allocated Workspace | 0.000043660 | 8680 | 43.660 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.000048386 | 10912 | 48.386 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000048791 | 8703 | 48.791 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000017121** | 7393 | **17.121** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000018969** | 7675 | **18.969** | Yes | 2 |
| wi | WikiSort Fully In-Place | **0.000019062** | 8748 | **19.062** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.000020238 | 8616 | 20.238 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000021299 | 9187 | 21.299 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.000022224 | 8187 | 22.224 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000024814 | 7036 | 24.814 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000026450 | 9002 | 26.450 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.000026802 | 10649 | 26.802 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000030187 | 7947 | 30.187 | Yes | 10 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000010587** | 4425 | **10.587** | Yes | 1 |
| wi | WikiSort Fully In-Place | **0.000011688** | 7000 | **11.688** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000012286** | 4766 | **12.286** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.000012302 | 5044 | 12.302 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.000012401 | 5488 | 12.401 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000013104 | 8522 | 13.104 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000013391 | 4668 | 13.391 | Yes | 7 |
| is | Insertion Sort Fully In-Place | 0.000014419 | 9778 | 14.419 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000015360 | 6633 | 15.360 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000019448 | 6438 | 19.448 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000006221** | 2827 | **6.221** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **0.000007359** | 3442 | **7.359** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000007381** | 3090 | **7.381** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000007618 | 5001 | 7.618 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.000007808 | 3818 | 7.808 | Yes | 5 |
| is | Insertion Sort Fully In-Place | 0.000008433 | 6333 | 8.433 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000008731 | 3567 | 8.731 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000011045 | 8358 | 11.045 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.000011582 | 5504 | 11.582 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000014743 | 5560 | 14.743 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000001838** | 1252 | **1.838** | Yes | 1 |
| is | Insertion Sort Fully In-Place | **0.000001998** | 1620 | **1.998** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000002193** | 1328 | **2.193** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.000002837 | 2209 | 2.837 | Yes | 4 |
| fs | ForSort Stable Fully In-Place | 0.000003173 | 2202 | 3.173 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.000003416 | 2798 | 3.416 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000003707 | 2045 | 3.707 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000008409 | 4877 | 8.409 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000009566 | 8249 | 9.566 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000010224 | 4983 | 10.224 | Yes | 10 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000000814** | 999 | **0.814** | Yes | 1 |
| is | Insertion Sort Fully In-Place | **0.000000981** | 999 | **0.981** | Yes | 2 |
| fb | ForSort Basic Fully In-Place | **0.000000994** | 999 | **0.994** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.000001001 | 999 | 1.001 | Yes | 4 |
| fw | ForSort With Allocated Workspace | 0.000001018 | 1028 | 1.018 | Yes | 5 |
| fi | ForSort Unstable Fully In-Place | 0.000001096 | 1046 | 1.096 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.000002582 | 2530 | 2.582 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000007663 | 4790 | 7.663 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000008965 | 8191 | 8.965 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000009862 | 4932 | 9.862 | Yes | 10 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | ForSort Basic Fully In-Place | **0.000004128** | 1725 | **4.128** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **0.000005593** | 2430 | **5.593** | Yes | 2 |
| wi | WikiSort Fully In-Place | **0.000007823** | 4601 | **7.823** | Yes | 3 |
| fw | ForSort With Allocated Workspace | 0.000007989 | 6108 | 7.989 | Yes | 4 |
| fi | ForSort Unstable Fully In-Place | 0.000009324 | 6149 | 9.324 | No | 5 |
| ti | TimSort with Allocated Workspace | 0.000010088 | 4456 | 10.088 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.000013343 | 5699 | 13.343 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000016564 | 12038 | 16.564 | No | 8 |
| is | Insertion Sort Fully In-Place | 0.000022737 | 10978 | 22.737 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000025349 | 5237 | 25.349 | Yes | 10 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000000963** | 999 | **0.963** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000001015** | 999 | **1.015** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000001083** | 999 | **1.083** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000003504 | 3287 | 3.504 | Yes | 4 |
| fw | ForSort With Allocated Workspace | 0.000007046 | 6144 | 7.046 | Yes | 5 |
| fi | ForSort Unstable Fully In-Place | 0.000007324 | 6024 | 7.324 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.000007999 | 5112 | 7.999 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.000011837 | 5044 | 11.837 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000017187 | 14222 | 17.187 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.000022005 | 10980 | 22.005 | Yes | 10 |

### 10000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000185814** | 126140 | **18.581** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000226144** | 133154 | **22.614** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000238895** | 133510 | **23.889** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.000275495 | 142005 | 27.549 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.000473360 | 138632 | 47.336 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.000491191 | 143339 | 49.119 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000503599 | 137019 | 50.360 | Yes | 7 |
| ti | TimSort with Allocated Workspace | 0.000596587 | 120354 | 59.659 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.000650822 | 120414 | 65.082 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.001163107 | 143513 | 116.31 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000202168** | 101172 | **20.217** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000221353** | 104700 | **22.135** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000239131** | 105253 | **23.913** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.000268544 | 113471 | 26.854 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000296510 | 127116 | 29.651 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.000311270 | 131330 | 31.127 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.000352778 | 126396 | 35.278 | Yes | 7 |
| ti | TimSort with Allocated Workspace | 0.000353796 | 93923 | 35.380 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.000400637 | 143045 | 40.064 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000403826 | 115308 | 40.383 | Yes | 10 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000152995** | 65766 | **15.299** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.000171234** | 69897 | **17.123** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000172229** | 67696 | **17.223** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000190977 | 119571 | 19.098 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.000192125 | 76351 | 19.213 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.000194499 | 110232 | 19.450 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.000196423 | 56011 | 19.642 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000236810 | 106235 | 23.681 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.000238048 | 142148 | 23.805 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000272749 | 102552 | 27.275 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000116140** | 46516 | **11.614** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **0.000129344** | 50997 | **12.934** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000131820** | 50225 | **13.182** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.000132081 | 41460 | 13.208 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.000140035 | 59159 | 14.004 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.000158139 | 95325 | 15.814 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000158315 | 116697 | 15.832 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000183949 | 90192 | 18.395 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.000191146 | 141272 | 19.115 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000223286 | 92080 | 22.329 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.000041545** | 20651 | **4.155** | Yes | 1 |
| ti | TimSort with Allocated Workspace | **0.000045029** | 20074 | **4.503** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000047372** | 22018 | **4.737** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.000050335 | 24683 | 5.033 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.000053956 | 31438 | 5.396 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.000066714 | 45936 | 6.671 | Yes | 6 |
| is | Insertion Sort Fully In-Place | 0.000072970 | 63429 | 7.297 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000113269 | 61179 | 11.327 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000125194 | 112922 | 12.519 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000146185 | 69193 | 14.618 | Yes | 10 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000007841** | 9999 | **0.784** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.000009110** | 10049 | **0.911** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000009202** | 10091 | **0.920** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.000009620 | 9999 | 0.962 | Yes | 4 |
| is | Insertion Sort Fully In-Place | 0.000009673 | 9999 | 0.967 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.000010013 | 9999 | 1.001 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.000026287 | 23662 | 2.629 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.000090827 | 53332 | 9.083 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000117300 | 111538 | 11.730 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.000120098 | 64608 | 12.010 | Yes | 10 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | ForSort Basic Fully In-Place | **0.000041212** | 17103 | **4.121** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **0.000048632** | 21002 | **4.863** | Yes | 2 |
| ti | TimSort with Allocated Workspace | **0.000098285** | 39935 | **9.828** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000099485 | 44654 | 9.948 | Yes | 4 |
| fw | ForSort With Allocated Workspace | 0.000118232 | 97256 | 11.823 | Yes | 5 |
| fi | ForSort Unstable Fully In-Place | 0.000120979 | 92693 | 12.098 | No | 6 |
| gs | GrailSort Fully In-Place | 0.000141958 | 60796 | 14.196 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000213860 | 166725 | 21.386 | No | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.000326890 | 70411 | 32.689 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.002135916 | 143610 | 213.59 | Yes | 10 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000009099** | 9999 | **0.910** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000010190** | 9999 | **1.019** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000010523** | 9999 | **1.052** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000044503 | 25008 | 4.450 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.000095188 | 57076 | 9.519 | Yes | 5 |
| fi | ForSort Unstable Fully In-Place | 0.000105015 | 92504 | 10.501 | Yes | 6 |
| fw | ForSort With Allocated Workspace | 0.000105332 | 97942 | 10.533 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.000148650 | 69008 | 14.865 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.000227759 | 192779 | 22.776 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.002159449 | 143612 | 215.94 | Yes | 10 |

### 100000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.002389888** | 1621926 | **23.899** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.002686885** | 1649884 | **26.869** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.002749454** | 1698640 | **27.495** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.004793294 | 2000354 | 47.933 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.005631395 | 1692280 | 56.314 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.006169310 | 1828537 | 61.693 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.006280815 | 1731630 | 62.808 | No | 7 |
| ti | TimSort with Allocated Workspace | 0.007435058 | 1531064 | 74.351 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.007702100 | 1536078 | 77.021 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.096357541 | 1768782 | 963.58 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.002404386** | 1247036 | **24.044** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.002504763** | 1276432 | **25.048** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.002641992** | 1281015 | **26.420** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.003430706 | 1312292 | 34.307 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.003734523 | 1622405 | 37.345 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.003875722 | 1718048 | 38.757 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.004261359 | 1631684 | 42.614 | Yes | 7 |
| ti | TimSort with Allocated Workspace | 0.004333656 | 1094158 | 43.337 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.004793453 | 1507290 | 47.935 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.012434260 | 1768031 | 124.34 | Yes | 10 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.001844278** | 816089 | **18.443** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.001914730** | 853681 | **19.147** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.001962834** | 840955 | **19.628** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.002271650 | 868865 | 22.716 | Yes | 4 |
| ti | TimSort with Allocated Workspace | 0.002380653 | 678060 | 23.807 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.002416980 | 1538407 | 24.170 | No | 6 |
| wi | WikiSort Fully In-Place | 0.002639015 | 1482335 | 26.390 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.003094211 | 1432847 | 30.942 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.003264106 | 1388145 | 32.641 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.003796913 | 1766493 | 37.969 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.001393827** | 623290 | **13.938** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.001463485** | 649194 | **14.635** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.001508815** | 611274 | **15.088** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.001679082 | 521667 | 16.791 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.001764650 | 687748 | 17.647 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.002039588 | 1517047 | 20.396 | No | 6 |
| wi | WikiSort Fully In-Place | 0.002090824 | 1317909 | 20.908 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.002553914 | 1279991 | 25.539 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.002701773 | 1764005 | 27.018 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.002768173 | 1297186 | 27.682 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000681220** | 255902 | **6.812** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.000703469** | 295443 | **7.035** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000749367** | 310076 | **7.494** | Yes | 3 |
| fs | ForSort Stable Fully In-Place | 0.000751638 | 318736 | 7.516 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.000939099 | 417555 | 9.391 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.001298396 | 949669 | 12.984 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.001537758 | 912808 | 15.378 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.001663708 | 1515705 | 16.637 | No | 8 |
| is | Insertion Sort Fully In-Place | 0.001963286 | 1746872 | 19.633 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.002051013 | 1052825 | 20.510 | Yes | 10 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000078126** | 99999 | **0.781** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.000085764** | 100078 | **0.858** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000086297** | 100167 | **0.863** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.000086776 | 99999 | 0.868 | Yes | 4 |
| is | Insertion Sort Fully In-Place | 0.000087198 | 99999 | 0.872 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.000096920 | 99999 | 0.969 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.000254156 | 240530 | 2.542 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.001022331 | 608786 | 10.223 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.001405347 | 815024 | 14.053 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.001600748 | 1524581 | 16.007 | No | 10 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | ForSort Basic Fully In-Place | **0.000386249** | 169660 | **3.862** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **0.000460805** | 200907 | **4.608** | Yes | 2 |
| ti | TimSort with Allocated Workspace | **0.001037429** | 423410 | **10.374** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.001139587 | 566132 | 11.396 | Yes | 4 |
| fw | ForSort With Allocated Workspace | 0.001404233 | 1187434 | 14.042 | Yes | 5 |
| fi | ForSort Unstable Fully In-Place | 0.001469765 | 1150379 | 14.698 | No | 6 |
| gs | GrailSort Fully In-Place | 0.001487620 | 653664 | 14.876 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.002221434 | 1775189 | 22.214 | No | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.003848344 | 866158 | 38.483 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.240335715 | 1768916 | 2403.4 | Yes | 10 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.000092990** | 99999 | **0.930** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000101299** | 99999 | **1.013** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.000110115** | 99999 | **1.101** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.000501731 | 284046 | 5.017 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.001061705 | 627299 | 10.617 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.001287626 | 1194581 | 12.876 | Yes | 6 |
| fi | ForSort Unstable Fully In-Place | 0.001334283 | 1155465 | 13.343 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.001721651 | 853904 | 17.217 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.002164324 | 1935567 | 21.643 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.243224393 | 1768918 | 2432.2 | Yes | 10 |

### 1000000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.026034348** | 19344602 | **26.034** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **0.029728541** | 20092064 | **29.729** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.030141718** | 20006387 | **30.142** | No | 3 |
| gs | GrailSort Fully In-Place | 0.066149265 | 20161623 | 66.149 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.066723049 | 25429122 | 66.723 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.074287096 | 22370558 | 74.287 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.075460025 | 20932586 | 75.460 | No | 7 |
| ti | TimSort with Allocated Workspace | 0.088799387 | 18299237 | 88.799 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.091701030 | 18672460 | 91.701 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 13.204283035 | 20951223 | 13204.3 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.026841698** | 14575947 | **26.842** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.027746784** | 15101355 | **27.747** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.028623316** | 15181000 | **28.623** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.044139662 | 15180808 | 44.140 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.045769062 | 19732474 | 45.769 | No | 5 |
| wi | WikiSort Fully In-Place | 0.046462266 | 21147341 | 46.462 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.049716109 | 12452195 | 49.716 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.052290930 | 19798003 | 52.291 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.056912743 | 18496933 | 56.913 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 1.235080628 | 20950078 | 1235.1 | Yes | 10 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.019800446** | 9648651 | **19.800** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.020588497** | 10159324 | **20.588** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.021395706** | 9262313 | **21.396** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.026699119 | 9463215 | 26.699 | Yes | 4 |
| ti | TimSort with Allocated Workspace | 0.027181105 | 7732374 | 27.181 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.030287921 | 18776179 | 30.288 | No | 6 |
| wi | WikiSort Fully In-Place | 0.031771736 | 18761861 | 31.772 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.039437581 | 18049573 | 39.438 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.039573011 | 17422103 | 39.573 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.189928496 | 20947569 | 189.93 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.015296173** | 7608556 | **15.296** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **0.016130185** | 7020803 | **16.130** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.016206852** | 7910690 | **16.207** | No | 3 |
| ti | TimSort with Allocated Workspace | 0.019856594 | 6046161 | 19.857 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.019910114 | 7387538 | 19.910 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.025077519 | 18501987 | 25.078 | No | 6 |
| wi | WikiSort Fully In-Place | 0.026020333 | 17097655 | 26.020 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.033857543 | 16566656 | 33.858 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.034051570 | 16619214 | 34.052 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 0.070041666 | 20943884 | 70.042 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.008152672** | 3460456 | **8.153** | Yes | 1 |
| ti | TimSort with Allocated Workspace | **0.008545307** | 3178814 | **8.545** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.008655185** | 3867672 | **8.655** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.008715725 | 3635135 | 8.716 | No | 4 |
| fb | ForSort Basic Fully In-Place | 0.011390808 | 4613596 | 11.391 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.018160773 | 13259182 | 18.161 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.020507446 | 18249037 | 20.507 | No | 7 |
| gs | GrailSort Fully In-Place | 0.024112236 | 13140257 | 24.112 | Yes | 8 |
| is | Insertion Sort Fully In-Place | 0.025455334 | 20920991 | 25.455 | Yes | 9 |
| gq | GLibc Quick Sort Fully In-Place | 0.026404419 | 14446085 | 26.404 | Yes | 10 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort Fully In-Place | **0.000830094** | 999999 | **0.830** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.000857155** | 999999 | **0.857** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.000863774** | 1000212 | **0.864** | Yes | 3 |
| fw | ForSort With Allocated Workspace | 0.000905147 | 1000058 | 0.905 | Yes | 4 |
| ti | TimSort with Allocated Workspace | 0.000904822 | 999999 | 0.905 | Yes | 5 |
| fs | ForSort Stable Fully In-Place | 0.001020150 | 999999 | 1.020 | Yes | 6 |
| wi | WikiSort Fully In-Place | 0.002556397 | 2595342 | 2.556 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.012597206 | 7019424 | 12.597 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.017412649 | 9884992 | 17.413 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.018654200 | 18196494 | 18.654 | No | 10 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | ForSort Basic Fully In-Place | **0.003880046** | 1709616 | **3.880** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **0.004637530** | 1986400 | **4.638** | Yes | 2 |
| ti | TimSort with Allocated Workspace | **0.010783073** | 4402874 | **10.783** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.012483388 | 6200229 | 12.483 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.017067746 | 7770815 | 17.068 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.018370325 | 15856960 | 18.370 | Yes | 6 |
| fi | ForSort Unstable Fully In-Place | 0.018900693 | 15380257 | 18.901 | No | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.026375958 | 21892903 | 26.376 | No | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.037593149 | 10249901 | 37.593 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 31.225945966 | 20951405 | 31225.9 | Yes | 10 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.001030165** | 999999 | **1.030** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.001076720** | 999999 | **1.077** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.001212079** | 999999 | **1.212** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.005973408 | 3273489 | 5.973 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.013242438 | 7551070 | 13.242 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.017553509 | 15928877 | 17.554 | Yes | 6 |
| fi | ForSort Unstable Fully In-Place | 0.018087216 | 15445001 | 18.087 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.019769546 | 10066432 | 19.770 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.026162352 | 24025703 | 26.162 | Yes | 9 |
| is | Insertion Sort Fully In-Place | 31.213116224 | 20951408 | 31213.1 | Yes | 10 |

### 10000000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.290479169** | 225429485 | **29.048** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.335019794** | 232323479 | **33.502** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.343476779** | 234998906 | **34.348** | Yes | 3 |
| gs | GrailSort Fully In-Place | 0.773850909 | 236971730 | 77.385 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.862206199 | 308208229 | 86.221 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.877634193 | 244978728 | 87.763 | No | 6 |
| wi | WikiSort Fully In-Place | 0.914850904 | 266856218 | 91.485 | Yes | 7 |
| ti | TimSort with Allocated Workspace | 1.046568561 | 213811193 | 104.66 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 1.097432109 | 220067062 | 109.74 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.282130943** | 166697520 | **28.213** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.296719095** | 174344599 | **29.672** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.316728183** | 174188725 | **31.673** | Yes | 3 |
| fb | ForSort Basic Fully In-Place | 0.527762952 | 175792156 | 52.776 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.535718642 | 232362806 | 53.572 | No | 5 |
| wi | WikiSort Fully In-Place | 0.561265633 | 249321112 | 56.127 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 0.585231470 | 139281719 | 58.523 | Yes | 7 |
| gs | GrailSort Fully In-Place | 0.610097697 | 232117264 | 61.010 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.693701773 | 218005542 | 69.370 | Yes | 9 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.210565659** | 105396310 | **21.057** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **0.226047408** | 108872034 | **22.605** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **0.230107999** | 113101586 | **23.011** | No | 3 |
| ti | TimSort with Allocated Workspace | 0.308517295 | 80920121 | 30.852 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.314209734 | 104585698 | 31.421 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.354128011 | 221662116 | 35.413 | No | 6 |
| wi | WikiSort Fully In-Place | 0.401519878 | 222873675 | 40.152 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.480102234 | 208077387 | 48.010 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.492574260 | 215559595 | 49.257 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **0.164683718** | 81555558 | **16.468** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **0.174182440** | 86735698 | **17.418** | No | 2 |
| fs | ForSort Stable Fully In-Place | **0.176792819** | 84362366 | **17.679** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 0.221508894 | 59834548 | 22.151 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 0.235110133 | 79683462 | 23.511 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.298296117 | 218613601 | 29.830 | No | 6 |
| wi | WikiSort Fully In-Place | 0.331667640 | 204449500 | 33.167 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.411283830 | 199428468 | 41.128 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.427246994 | 201540433 | 42.725 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.091225486** | 29070075 | **9.123** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **0.093867897** | 45040920 | **9.387** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.095937248** | 45889657 | **9.594** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.098267152 | 47285288 | 9.827 | No | 4 |
| fb | ForSort Basic Fully In-Place | 0.126158328 | 48005733 | 12.616 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.227376638 | 161735505 | 22.738 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.236079736 | 215104626 | 23.608 | No | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.324770732 | 178584358 | 32.477 | Yes | 8 |
| gs | GrailSort Fully In-Place | 0.328703588 | 166960984 | 32.870 | Yes | 9 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | ForSort Basic Fully In-Place | **0.008044872** | 9999999 | **0.804** | Yes | 1 |
| ti | TimSort with Allocated Workspace | **0.008165247** | 9999999 | **0.817** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.008278058** | 9999999 | **0.828** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.008726703 | 10000304 | 0.873 | Yes | 4 |
| fw | ForSort With Allocated Workspace | 0.008787108 | 10000089 | 0.879 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.020450543 | 20122539 | 2.045 | Yes | 6 |
| gs | GrailSort Fully In-Place | 0.161050119 | 79190468 | 16.105 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.204936880 | 114434624 | 20.494 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.210129474 | 211563145 | 21.013 | No | 9 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | ForSort Basic Fully In-Place | **0.039666660** | 17014230 | **3.967** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **0.050395309** | 19769718 | **5.040** | Yes | 2 |
| ti | TimSort with Allocated Workspace | **0.125082324** | 39878287 | **12.508** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.157356439 | 68406097 | 15.736 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.197536698 | 84028632 | 19.754 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.226901139 | 197266414 | 22.690 | Yes | 6 |
| fi | ForSort Unstable Fully In-Place | 0.243283227 | 190082762 | 24.328 | No | 7 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.305622835 | 264938294 | 30.562 | No | 8 |
| gq | GLibc Quick Sort Fully In-Place | 0.428817140 | 120242956 | 42.882 | Yes | 9 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.009753010** | 9999999 | **0.975** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.010955323** | 9999999 | **1.096** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.012702662** | 9999999 | **1.270** | Yes | 3 |
| wi | WikiSort Fully In-Place | 0.069058311 | 21498750 | 6.906 | Yes | 4 |
| gs | GrailSort Fully In-Place | 0.156780620 | 81979307 | 15.678 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 0.219586394 | 197985781 | 21.959 | Yes | 6 |
| fi | ForSort Unstable Fully In-Place | 0.235313287 | 190740147 | 23.531 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 0.251002940 | 118788160 | 25.100 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 0.310981583 | 290683459 | 31.098 | Yes | 9 |

### 100000000 Items

#### Fully Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **3.605732237** | 2621034100 | **36.057** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **3.889485654** | 2635151729 | **38.895** | No | 2 |
| fs | ForSort Stable Fully In-Place | **4.171311801** | 2737947081 | **41.713** | Yes | 3 |
| gs | GrailSort Fully In-Place | 9.197150139 | 2655115103 | 91.972 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort In-Place | 10.008404968 | 2813381791 | 100.08 | No | 5 |
| wi | WikiSort Fully In-Place | 10.665340264 | 3064030624 | 106.65 | Yes | 6 |
| fb | ForSort Basic Fully In-Place | 10.707555170 | 3620014278 | 107.08 | Yes | 7 |
| ti | TimSort with Allocated Workspace | 12.117331195 | 2435414127 | 121.17 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 12.632347379 | 2532645582 | 126.32 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **3.376444243** | 1871465958 | **33.764** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **3.387947963** | 1937567270 | **33.879** | No | 2 |
| fs | ForSort Stable Fully In-Place | **3.543709572** | 1927251602 | **35.437** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort In-Place | 6.204097085 | 2673756547 | 62.041 | No | 4 |
| fb | ForSort Basic Fully In-Place | 6.418575853 | 2004115856 | 64.186 | Yes | 5 |
| wi | WikiSort Fully In-Place | 6.705431699 | 2854539037 | 67.054 | Yes | 6 |
| ti | TimSort with Allocated Workspace | 6.720483434 | 1534823448 | 67.205 | Yes | 7 |
| gs | GrailSort Fully In-Place | 7.261347125 | 2634706912 | 72.613 | Yes | 8 |
| gq | GLibc Quick Sort Fully In-Place | 8.121808151 | 2514386491 | 81.218 | Yes | 9 |

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **2.444036473** | 1213398569 | **24.440** | Yes | 1 |
| fi | ForSort Unstable Fully In-Place | **2.488270752** | 1283084089 | **24.883** | No | 2 |
| fs | ForSort Stable Fully In-Place | **2.540750679** | 1257811933 | **25.408** | Yes | 3 |
| ti | TimSort with Allocated Workspace | 3.589106048 | 885227488 | 35.891 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 3.797842749 | 1153725779 | 37.978 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 4.033374946 | 2556059938 | 40.334 | No | 6 |
| wi | WikiSort Fully In-Place | 4.757169675 | 2589557822 | 47.572 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 5.770685025 | 2425069297 | 57.707 | Yes | 8 |
| gs | GrailSort Fully In-Place | 6.033910965 | 2496323648 | 60.339 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | ForSort With Allocated Workspace | **1.883391082** | 957207476 | **18.834** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **1.956459486** | 983967700 | **19.565** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **1.959127578** | 1004983491 | **19.591** | No | 3 |
| ti | TimSort with Allocated Workspace | 2.453186459 | 659572049 | 24.532 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 2.769314916 | 862929332 | 27.693 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 3.445866061 | 2520784966 | 34.459 | No | 6 |
| wi | WikiSort Fully In-Place | 4.142768048 | 2411074399 | 41.428 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 4.946636317 | 2341700849 | 49.466 | Yes | 8 |
| gs | GrailSort Fully In-Place | 5.358993491 | 2358423063 | 53.590 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **1.071936776** | 324496683 | **10.719** | Yes | 1 |
| fw | ForSort With Allocated Workspace | **1.097294163** | 525105042 | **10.973** | Yes | 2 |
| fi | ForSort Unstable Fully In-Place | **1.123627969** | 551510519 | **11.236** | No | 3 |
| fs | ForSort Stable Fully In-Place | 1.148648449 | 600146281 | 11.486 | Yes | 4 |
| fb | ForSort Basic Fully In-Place | 1.487449018 | 501386868 | 14.874 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort In-Place | 2.749516485 | 2503094341 | 27.495 | No | 6 |
| wi | WikiSort Fully In-Place | 3.056804117 | 1989970645 | 30.568 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 3.978263478 | 2138241987 | 39.783 | Yes | 8 |
| gs | GrailSort Fully In-Place | 4.297721591 | 2022641308 | 42.977 | Yes | 9 |

#### Fully Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | ForSort Basic Fully In-Place | **0.079138106** | 99999999 | **0.791** | Yes | 1 |
| ti | TimSort with Allocated Workspace | **0.079063973** | 99999999 | **0.791** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.080636935** | 99999999 | **0.806** | Yes | 3 |
| fi | ForSort Unstable Fully In-Place | 0.092002377 | 100000429 | 0.920 | Yes | 4 |
| fw | ForSort With Allocated Workspace | 0.094495209 | 100000101 | 0.945 | Yes | 5 |
| wi | WikiSort Fully In-Place | 0.240113323 | 223276977 | 2.401 | Yes | 6 |
| gs | GrailSort Fully In-Place | 2.206300501 | 840205773 | 22.063 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 2.430828293 | 1314447104 | 24.308 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort In-Place | 2.451536093 | 2523415216 | 24.515 | No | 9 |

#### Reverse Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | ForSort Basic Fully In-Place | **0.407378604** | 164457475 | **4.074** | Yes | 1 |
| fs | ForSort Stable Fully In-Place | **0.618193754** | 188352069 | **6.182** | Yes | 2 |
| ti | TimSort with Allocated Workspace | **1.639693318** | 418701728 | **16.397** | Yes | 3 |
| wi | WikiSort Fully In-Place | 2.115178687 | 736637378 | 21.152 | Yes | 4 |
| gs | GrailSort Fully In-Place | 2.672634209 | 916679743 | 26.726 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 2.825718234 | 2190998624 | 28.257 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 3.104010767 | 2805397135 | 31.040 | No | 7 |
| fi | ForSort Unstable Fully In-Place | 3.350743782 | 2136653781 | 33.507 | No | 8 |
| gq | GLibc Quick Sort Fully In-Place | 5.038515170 | 1363129466 | 50.385 | Yes | 9 |

#### Reverse Ordered Uniques

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort with Allocated Workspace | **0.105585892** | 99999999 | **1.056** | Yes | 1 |
| fb | ForSort Basic Fully In-Place | **0.123722492** | 99999999 | **1.237** | Yes | 2 |
| fs | ForSort Stable Fully In-Place | **0.157553721** | 99999999 | **1.576** | Yes | 3 |
| wi | WikiSort Fully In-Place | 1.261178475 | 266513829 | 12.612 | Yes | 4 |
| gs | GrailSort Fully In-Place | 2.288013988 | 896694624 | 22.880 | Yes | 5 |
| fw | ForSort With Allocated Workspace | 2.739209551 | 2198193794 | 27.392 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort In-Place | 2.968237980 | 2921036489 | 29.682 | Yes | 7 |
| gq | GLibc Quick Sort Fully In-Place | 3.190322483 | 1351335168 | 31.903 | Yes | 8 |
| fi | ForSort Unstable Fully In-Place | 3.345919897 | 2143324548 | 33.459 | Yes | 9 |


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
