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
| fb | Forsort Basic In-Place | Stable |
| fi | Forsort Unstable In-Place | Unstable |
| fw | Forsort With Workspace | Stable |
| fs | Forsort Stable In-Place | Stable |
| gs | Grail Sort In-Place | Stable |
| gq | GLibc Quick Sort | Unstable |
| nq | Bentley/McIlroy Quick Sort | Unstable |
| ti | TimSort | Stable |
| wi | WikiSort | Stable |
| is | Insertion Sort | Stable |


## Test Variants

| Variant | Description |
|---------|-------------|
| random_duplicates | Random Data Duplicate Values |
| random_unique | Random Data Unique Values |
| 25_percent_disordered | 75% Ordered, 25% disorder |
| 10_percent_disordered | 90% Ordered, 10% disorder |
| 5_percent_disordered | 95% Ordered, 5% disorder |
| 1_percent_disordered | 99% Ordered, 1% disorder |
| ordered_duplicates | Fully Ordered Duplicate Values |
| ordered_unique | Fully Ordered Unique Values |
| reversed_duplicates | Reverse Ordered with duplicate values |
| reversed_unique | Reverse Ordered with unique values |


## Summary by Dataset Size and Test Variant

### 10 Percent Disordered

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items |
|-----------|----------|----------|----------|----------|----------|
| fw | *****18.976** | *****17.385** | *****18.441** | *****19.579** | *****21.219** |
| fs | ****21.650** | ****20.101** | ****20.245** | ****20.605** | ****22.631** |
| fi | ***23.905** | ***18.981** | ***19.616** | ***20.662** | ***22.738** |
| nq | 15.700 | 22.113 | 29.878 | 30.135 | 34.323 |
| ti | 22.933 | 22.568 | 29.858 | 28.209 | 32.062 |
| wi | 18.355 | 21.148 | 26.176 | 31.419 | 39.890 |
| is | 18.044 | 27.937 | 37.500 | - | - |
| fb | 23.705 | 26.710 | 29.486 | 33.807 | 39.431 |
| gs | 22.603 | 24.432 | 35.646 | 40.173 | 49.208 |
| gq | 22.843 | 51.440 | 43.219 | 42.707 | 47.351 |

### 1 Percent Disordered

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items |
|-----------|----------|----------|----------|----------|----------|
| ti | *****7.625** | *****5.499** | *****6.966** | *****8.580** | *****9.062** |
| fw | ****6.493** | ****5.655** | ****7.248** | ****8.752** | ****10.068** |
| fi | ***8.756** | ***6.147** | ***7.764** | ***8.449** | ***9.533** |
| fs | 9.448 | 6.571 | 12.155 | 8.806 | 9.620 |
| fb | 5.801 | 7.790 | 9.349 | 11.451 | 13.245 |
| is | 3.196 | 7.899 | 19.803 | - | - |
| wi | 9.077 | 8.200 | 13.450 | 18.066 | 22.856 |
| nq | 11.361 | 16.131 | 24.972 | 20.197 | 23.593 |
| gs | 15.038 | 12.131 | 15.924 | 25.149 | 33.252 |
| gq | 14.738 | 20.856 | 19.816 | 28.012 | 33.800 |

### 25 Percent Disordered

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items |
|-----------|----------|----------|----------|----------|----------|
| fw | *****27.021** | *****22.661** | *****25.364** | *****27.081** | *****28.938** |
| fi | ****29.947** | ****24.573** | ****28.119** | ****27.826** | ****30.036** |
| fs | ***32.220** | ***26.024** | ***27.450** | ***28.703** | ***31.203** |
| nq | 23.384 | 29.743 | 40.981 | 45.269 | 52.391 |
| wi | 26.821 | 32.651 | 41.250 | 47.479 | 57.809 |
| gs | 33.703 | 39.024 | 44.741 | 51.964 | 62.754 |
| ti | 34.886 | 39.141 | 50.543 | 52.463 | 59.454 |
| fb | 40.717 | 47.104 | 54.852 | 61.600 | 72.472 |
| gq | 52.820 | 39.105 | 57.951 | 58.319 | 72.079 |
| is | 29.506 | 40.603 | 126.38 | - | - |

### 5 Percent Disordered

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items |
|-----------|----------|----------|----------|----------|----------|
| fw | *****13.365** | *****14.285** | *****14.509** | *****16.025** | *****16.978** |
| fs | ****16.200** | ****15.387** | ****20.299** | ****16.526** | ****17.697** |
| fi | ***17.533** | ***14.725** | ***22.121** | ***16.837** | ***17.381** |
| ti | 15.800 | 15.388 | 17.189 | 19.532 | 22.299 |
| is | 11.581 | 20.057 | 28.837 | - | - |
| nq | 13.325 | 15.630 | 20.657 | 25.591 | 29.257 |
| fb | 14.798 | 17.817 | 26.553 | 24.075 | 27.807 |
| wi | 15.219 | 16.768 | 21.172 | 26.924 | 33.801 |
| gs | 18.024 | 19.322 | 27.880 | 35.557 | 43.143 |
| gq | 19.016 | 39.453 | 33.048 | 37.000 | 40.195 |

### Ordered Duplicates

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items |
|-----------|----------|----------|----------|----------|----------|
| is | *****0.942** | *****0.784** | *****0.768** | - | - |
| fb | ****1.082** | ****0.799** | ****0.770** | ****0.780** | ****0.806** |
| ti | ***1.673** | ***0.861** | ***0.778** | ***0.873** | ***0.822** |
| fs | 1.362 | 0.992 | 1.040 | 0.995 | 0.993 |
| fi | 3.276 | 1.178 | 1.063 | 1.072 | 0.937 |
| fw | 3.657 | 1.174 | 1.331 | 1.532 | 0.896 |
| wi | 5.831 | 3.477 | 2.711 | 2.634 | 2.119 |
| gs | 15.299 | 10.925 | 13.816 | 13.657 | 16.960 |
| gq | 12.103 | 12.516 | 15.250 | 18.723 | 21.899 |
| nq | 12.374 | 12.960 | 20.640 | 21.078 | 22.610 |

### Ordered Unique

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items |
|-----------|----------|----------|----------|----------|----------|
| is | *****0.922** | *****0.784** | *****0.768** | - | - |
| fb | ****1.062** | ****0.797** | ****0.768** | ****0.947** | ****0.809** |
| ti | ***1.713** | ***0.861** | ***0.777** | ***0.923** | ***0.782** |
| fs | 1.232 | 0.997 | 0.960 | 1.026 | 1.002 |
| fi | 3.196 | 1.157 | 1.058 | 1.065 | 0.957 |
| fw | 3.707 | 1.133 | 1.260 | 1.727 | 0.894 |
| wi | 5.610 | 3.137 | 2.607 | 2.571 | 2.046 |
| gs | 11.632 | 9.208 | 10.796 | 14.643 | 15.822 |
| nq | 9.588 | 11.630 | 15.874 | 18.704 | 20.761 |
| gq | 12.304 | 12.645 | 17.194 | 17.867 | 20.657 |

### Random Duplicates

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items |
|-----------|----------|----------|----------|----------|----------|
| fw | *****25.298** | *****20.006** | *****24.007** | *****27.005** | *****30.117** |
| fi | ****32.230** | ****24.276** | ****26.604** | ****29.815** | ****33.626** |
| fs | ***35.988** | ***25.350** | ***32.804** | ***30.405** | ***34.836** |
| nq | 40.036 | 49.105 | 63.636 | 73.787 | 87.728 |
| gs | 47.550 | 66.376 | 56.769 | 65.866 | 77.802 |
| wi | 40.196 | 51.300 | 63.969 | 75.893 | 92.482 |
| ti | 49.243 | 61.142 | 77.216 | 90.253 | 107.44 |
| gq | 49.904 | 62.480 | 78.090 | 94.365 | 112.21 |
| fb | 60.895 | 73.445 | 92.587 | 112.67 | 123.75 |
| is | 50.174 | 115.57 | 967.17 | - | - |

### Random Unique

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items |
|-----------|----------|----------|----------|----------|----------|
| fw | *****28.473** | *****20.121** | *****23.238** | *****27.024** | *****30.668** |
| fi | ****30.137** | ****23.982** | ****25.903** | ****29.914** | ****33.198** |
| fs | ***34.325** | ***25.016** | ***28.026** | ***31.217** | ***34.275** |
| gs | 45.986 | 48.149 | 62.923 | 65.259 | 78.547 |
| nq | 38.713 | 49.886 | 63.931 | 75.926 | 87.656 |
| wi | 38.934 | 50.845 | 63.123 | 75.123 | 90.514 |
| ti | 49.995 | 61.025 | 81.015 | 90.447 | 108.99 |
| gq | 49.794 | 68.573 | 87.486 | 97.034 | 108.27 |
| fb | 59.933 | 71.798 | 92.625 | 105.69 | 124.64 |
| is | 50.676 | 116.24 | 971.50 | - | - |

### Reversed Duplicates

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items |
|-----------|----------|----------|----------|----------|----------|
| ti | *****18.555** | *****11.818** | *****12.378** | *****11.770** | *****13.656** |
| wi | ****13.797** | ****11.849** | ****15.647** | ****12.769** | ****14.789** |
| fw | ***16.000** | ***13.315** | ***16.978** | ***19.804** | ***24.130** |
| fi | 19.988 | 13.335 | 15.469 | 19.616 | 24.341 |
| fs | 22.783 | 13.721 | 15.316 | 18.673 | 23.414 |
| gs | 21.140 | 15.187 | 24.127 | 18.809 | 19.844 |
| nq | 19.327 | 21.599 | 32.450 | 26.704 | 30.618 |
| fb | 29.295 | 24.325 | 24.745 | 28.186 | 32.368 |
| gq | 46.508 | 59.529 | 25.330 | 36.613 | 46.624 |
| is | 23.945 | 260.34 | 2484.1 | - | - |

### Reversed Unique

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items |
|-----------|----------|----------|----------|----------|----------|
| ti | *****1.884** | *****1.017** | *****0.922** | *****1.031** | *****0.999** |
| fb | ****2.885** | ****2.098** | ****1.978** | ****2.018** | ****2.133** |
| fs | ***7.304** | ***2.583** | ***2.344** | ***2.804** | ***2.927** |
| wi | 7.875 | 5.113 | 5.465 | 6.307 | 6.924 |
| gs | 14.207 | 10.195 | 10.736 | 13.369 | 15.796 |
| fw | 14.167 | 10.962 | 14.288 | 18.491 | 22.405 |
| fi | 15.940 | 11.594 | 14.118 | 18.841 | 23.516 |
| gq | 14.267 | 15.784 | 18.695 | 22.182 | 25.400 |
| nq | 18.124 | 22.401 | 30.192 | 26.991 | 31.570 |
| is | 22.924 | 215.56 | 2359.9 | - | - |


## Cross-Category Analysis

### Win Count by Algorithm

| Rank | Sort Type | Name | Wins | Top 3 | Win Rate |
|------|-----------|------|------|-------|----------|
| 1 | **fw** | Forsort With Workspace | 22 | 32 | 44.0% |
| 2 | **ti** | TimSort | 14 | 23 | 28.0% |
| 3 | **is** | Insertion Sort | 7 | 9 | 14.0% |
| 4 | **fb** | Forsort Basic In-Place | 3 | 16 | 6.0% |
| 5 | **nq** | Bentley/McIlroy Quick Sort | 2 | 3 | 4.0% |
| 6 | **wi** | WikiSort | 1 | 6 | 2.0% |
| 7 | **fi** | Forsort Unstable In-Place | 1 | 26 | 2.0% |

### Recommendations by Use Case

- **Best Stable Sort:** fs (Forsort Stable In-Place) - Avg: 16.918 ns/item (1M-100M items)
- **Best Unstable Sort:** fi (Forsort Unstable In-Place) - Avg: 18.518 ns/item (1M-100M items)
- **Best for Nearly-Sorted Data:** fw (Forsort With Workspace) - Avg: 11.338 ns/item


## Performance Rankings

### 1000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **nq** | Bentley/McIlroy Quick Sort | 15.700 | 0.0% | No |
| 2 | **is** | Insertion Sort | 18.044 | 14.9% | Yes |
| 3 | **wi** | WikiSort | 18.355 | 16.9% | Yes |
| 4 | fw | Forsort With Workspace | 18.976 | 20.9% | Yes |
| 5 | fs | Forsort Stable In-Place | 21.650 | 37.9% | Yes |
| 6 | gs | Grail Sort In-Place | 22.603 | 44.0% | Yes |
| 7 | gq | GLibc Quick Sort | 22.843 | 45.5% | No |
| 8 | ti | TimSort | 22.933 | 46.1% | Yes |
| 9 | fb | Forsort Basic In-Place | 23.705 | 51.0% | Yes |
| 10 | fi | Forsort Unstable In-Place | 23.905 | 52.3% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 3.196 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 5.801 | 81.5% | Yes |
| 3 | **fw** | Forsort With Workspace | 6.493 | 103.2% | Yes |
| 4 | ti | TimSort | 7.625 | 138.6% | Yes |
| 5 | fi | Forsort Unstable In-Place | 8.756 | 174.0% | No |
| 6 | wi | WikiSort | 9.077 | 184.0% | Yes |
| 7 | fs | Forsort Stable In-Place | 9.448 | 195.6% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 11.361 | 255.5% | No |
| 9 | gq | GLibc Quick Sort | 14.738 | 361.1% | No |
| 10 | gs | Grail Sort In-Place | 15.038 | 370.5% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **nq** | Bentley/McIlroy Quick Sort | 23.384 | 0.0% | No |
| 2 | **wi** | WikiSort | 26.821 | 14.7% | Yes |
| 3 | **fw** | Forsort With Workspace | 27.021 | 15.6% | Yes |
| 4 | is | Insertion Sort | 29.506 | 26.2% | Yes |
| 5 | fi | Forsort Unstable In-Place | 29.947 | 28.1% | No |
| 6 | fs | Forsort Stable In-Place | 32.220 | 37.8% | Yes |
| 7 | gs | Grail Sort In-Place | 33.703 | 44.1% | Yes |
| 8 | ti | TimSort | 34.886 | 49.2% | Yes |
| 9 | fb | Forsort Basic In-Place | 40.717 | 74.1% | Yes |
| 10 | gq | GLibc Quick Sort | 52.820 | 125.9% | No |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 11.581 | 0.0% | Yes |
| 2 | **nq** | Bentley/McIlroy Quick Sort | 13.325 | 15.1% | No |
| 3 | **fw** | Forsort With Workspace | 13.365 | 15.4% | Yes |
| 4 | fb | Forsort Basic In-Place | 14.798 | 27.8% | Yes |
| 5 | wi | WikiSort | 15.219 | 31.4% | Yes |
| 6 | ti | TimSort | 15.800 | 36.4% | Yes |
| 7 | fs | Forsort Stable In-Place | 16.200 | 39.9% | Yes |
| 8 | fi | Forsort Unstable In-Place | 17.533 | 51.4% | No |
| 9 | gs | Grail Sort In-Place | 18.024 | 55.6% | Yes |
| 10 | gq | GLibc Quick Sort | 19.016 | 64.2% | No |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 0.942 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.082 | 14.9% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.362 | 44.6% | Yes |
| 4 | ti | TimSort | 1.673 | 77.6% | Yes |
| 5 | fi | Forsort Unstable In-Place | 3.276 | 247.8% | No |
| 6 | fw | Forsort With Workspace | 3.657 | 288.2% | Yes |
| 7 | wi | WikiSort | 5.831 | 519.0% | Yes |
| 8 | gq | GLibc Quick Sort | 12.103 | 1184.8% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 12.374 | 1213.6% | No |
| 10 | gs | Grail Sort In-Place | 15.299 | 1524.1% | Yes |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 0.922 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.062 | 15.2% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.232 | 33.6% | Yes |
| 4 | ti | TimSort | 1.713 | 85.8% | Yes |
| 5 | fi | Forsort Unstable In-Place | 3.196 | 246.6% | No |
| 6 | fw | Forsort With Workspace | 3.707 | 302.1% | Yes |
| 7 | wi | WikiSort | 5.610 | 508.5% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 9.588 | 939.9% | No |
| 9 | gs | Grail Sort In-Place | 11.632 | 1161.6% | Yes |
| 10 | gq | GLibc Quick Sort | 12.304 | 1234.5% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 25.298 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 32.230 | 27.4% | No |
| 3 | **fs** | Forsort Stable In-Place | 35.988 | 42.3% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 40.036 | 58.3% | No |
| 5 | wi | WikiSort | 40.196 | 58.9% | Yes |
| 6 | gs | Grail Sort In-Place | 47.550 | 88.0% | Yes |
| 7 | ti | TimSort | 49.243 | 94.7% | Yes |
| 8 | gq | GLibc Quick Sort | 49.904 | 97.3% | No |
| 9 | is | Insertion Sort | 50.174 | 98.3% | Yes |
| 10 | fb | Forsort Basic In-Place | 60.895 | 140.7% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 28.473 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 30.137 | 5.8% | No |
| 3 | **fs** | Forsort Stable In-Place | 34.325 | 20.6% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 38.713 | 36.0% | No |
| 5 | wi | WikiSort | 38.934 | 36.7% | Yes |
| 6 | gs | Grail Sort In-Place | 45.986 | 61.5% | Yes |
| 7 | gq | GLibc Quick Sort | 49.794 | 74.9% | No |
| 8 | ti | TimSort | 49.995 | 75.6% | Yes |
| 9 | is | Insertion Sort | 50.676 | 78.0% | Yes |
| 10 | fb | Forsort Basic In-Place | 59.933 | 110.5% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **wi** | WikiSort | 13.797 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 16.000 | 16.0% | Yes |
| 3 | **ti** | TimSort | 18.555 | 34.5% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 19.327 | 40.1% | No |
| 5 | fi | Forsort Unstable In-Place | 19.988 | 44.9% | No |
| 6 | gs | Grail Sort In-Place | 21.140 | 53.2% | Yes |
| 7 | fs | Forsort Stable In-Place | 22.783 | 65.1% | Yes |
| 8 | is | Insertion Sort | 23.945 | 73.6% | Yes |
| 9 | fb | Forsort Basic In-Place | 29.295 | 112.3% | Yes |
| 10 | gq | GLibc Quick Sort | 46.508 | 237.1% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.884 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 2.885 | 53.1% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 7.304 | 287.7% | Yes |
| 4 | wi | WikiSort | 7.875 | 318.0% | Yes |
| 5 | fw | Forsort With Workspace | 14.167 | 652.0% | Yes |
| 6 | gs | Grail Sort In-Place | 14.207 | 654.1% | Yes |
| 7 | gq | GLibc Quick Sort | 14.267 | 657.3% | No |
| 8 | fi | Forsort Unstable In-Place | 15.940 | 746.1% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 18.124 | 862.0% | No |
| 10 | is | Insertion Sort | 22.924 | 1116.8% | Yes |

#### Overall Winner (Average Across All Variants)

**Winner:** fw (Forsort With Workspace) - Average: 15.716 ns/item

### 10000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 17.385 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 18.981 | 9.2% | No |
| 3 | **fs** | Forsort Stable In-Place | 20.101 | 15.6% | Yes |
| 4 | wi | WikiSort | 21.148 | 21.6% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 22.113 | 27.2% | No |
| 6 | ti | TimSort | 22.568 | 29.8% | Yes |
| 7 | gs | Grail Sort In-Place | 24.432 | 40.5% | Yes |
| 8 | fb | Forsort Basic In-Place | 26.710 | 53.6% | Yes |
| 9 | is | Insertion Sort | 27.937 | 60.7% | Yes |
| 10 | gq | GLibc Quick Sort | 51.440 | 195.9% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 5.499 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 5.655 | 2.8% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 6.147 | 11.8% | No |
| 4 | fs | Forsort Stable In-Place | 6.571 | 19.5% | Yes |
| 5 | fb | Forsort Basic In-Place | 7.790 | 41.7% | Yes |
| 6 | is | Insertion Sort | 7.899 | 43.6% | Yes |
| 7 | wi | WikiSort | 8.200 | 49.1% | Yes |
| 8 | gs | Grail Sort In-Place | 12.131 | 120.6% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort | 16.131 | 193.3% | No |
| 10 | gq | GLibc Quick Sort | 20.856 | 279.3% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 22.661 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 24.573 | 8.4% | No |
| 3 | **fs** | Forsort Stable In-Place | 26.024 | 14.8% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 29.743 | 31.3% | No |
| 5 | wi | WikiSort | 32.651 | 44.1% | Yes |
| 6 | gs | Grail Sort In-Place | 39.024 | 72.2% | Yes |
| 7 | gq | GLibc Quick Sort | 39.105 | 72.6% | No |
| 8 | ti | TimSort | 39.141 | 72.7% | Yes |
| 9 | is | Insertion Sort | 40.603 | 79.2% | Yes |
| 10 | fb | Forsort Basic In-Place | 47.104 | 107.9% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 14.285 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 14.725 | 3.1% | No |
| 3 | **fs** | Forsort Stable In-Place | 15.387 | 7.7% | Yes |
| 4 | ti | TimSort | 15.388 | 7.7% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 15.630 | 9.4% | No |
| 6 | wi | WikiSort | 16.768 | 17.4% | Yes |
| 7 | fb | Forsort Basic In-Place | 17.817 | 24.7% | Yes |
| 8 | gs | Grail Sort In-Place | 19.322 | 35.3% | Yes |
| 9 | is | Insertion Sort | 20.057 | 40.4% | Yes |
| 10 | gq | GLibc Quick Sort | 39.453 | 176.2% | No |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 0.784 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.799 | 1.9% | Yes |
| 3 | **ti** | TimSort | 0.861 | 9.8% | Yes |
| 4 | fs | Forsort Stable In-Place | 0.992 | 26.5% | Yes |
| 5 | fw | Forsort With Workspace | 1.174 | 49.7% | Yes |
| 6 | fi | Forsort Unstable In-Place | 1.178 | 50.3% | No |
| 7 | wi | WikiSort | 3.477 | 343.5% | Yes |
| 8 | gs | Grail Sort In-Place | 10.925 | 1293.5% | Yes |
| 9 | gq | GLibc Quick Sort | 12.516 | 1496.4% | No |
| 10 | nq | Bentley/McIlroy Quick Sort | 12.960 | 1553.1% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 0.784 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.797 | 1.7% | Yes |
| 3 | **ti** | TimSort | 0.861 | 9.8% | Yes |
| 4 | fs | Forsort Stable In-Place | 0.997 | 27.2% | Yes |
| 5 | fw | Forsort With Workspace | 1.133 | 44.5% | Yes |
| 6 | fi | Forsort Unstable In-Place | 1.157 | 47.6% | No |
| 7 | wi | WikiSort | 3.137 | 300.1% | Yes |
| 8 | gs | Grail Sort In-Place | 9.208 | 1074.5% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort | 11.630 | 1383.4% | No |
| 10 | gq | GLibc Quick Sort | 12.645 | 1512.9% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 20.006 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 24.276 | 21.3% | No |
| 3 | **fs** | Forsort Stable In-Place | 25.350 | 26.7% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 49.105 | 145.5% | No |
| 5 | wi | WikiSort | 51.300 | 156.4% | Yes |
| 6 | ti | TimSort | 61.142 | 205.6% | Yes |
| 7 | gq | GLibc Quick Sort | 62.480 | 212.3% | No |
| 8 | gs | Grail Sort In-Place | 66.376 | 231.8% | Yes |
| 9 | fb | Forsort Basic In-Place | 73.445 | 267.1% | Yes |
| 10 | is | Insertion Sort | 115.57 | 477.7% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 20.121 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 23.982 | 19.2% | No |
| 3 | **fs** | Forsort Stable In-Place | 25.016 | 24.3% | Yes |
| 4 | gs | Grail Sort In-Place | 48.149 | 139.3% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 49.886 | 147.9% | No |
| 6 | wi | WikiSort | 50.845 | 152.7% | Yes |
| 7 | ti | TimSort | 61.025 | 203.3% | Yes |
| 8 | gq | GLibc Quick Sort | 68.573 | 240.8% | No |
| 9 | fb | Forsort Basic In-Place | 71.798 | 256.8% | Yes |
| 10 | is | Insertion Sort | 116.24 | 477.7% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 11.818 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 11.849 | 0.3% | Yes |
| 3 | **fw** | Forsort With Workspace | 13.315 | 12.7% | Yes |
| 4 | fi | Forsort Unstable In-Place | 13.335 | 12.8% | No |
| 5 | fs | Forsort Stable In-Place | 13.721 | 16.1% | Yes |
| 6 | gs | Grail Sort In-Place | 15.187 | 28.5% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 21.599 | 82.8% | No |
| 8 | fb | Forsort Basic In-Place | 24.325 | 105.8% | Yes |
| 9 | gq | GLibc Quick Sort | 59.529 | 403.7% | No |
| 10 | is | Insertion Sort | 260.34 | 2102.9% | Yes |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.017 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 2.098 | 106.3% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 2.583 | 154.0% | Yes |
| 4 | wi | WikiSort | 5.113 | 402.8% | Yes |
| 5 | gs | Grail Sort In-Place | 10.195 | 902.5% | Yes |
| 6 | fw | Forsort With Workspace | 10.962 | 977.9% | Yes |
| 7 | fi | Forsort Unstable In-Place | 11.594 | 1040.0% | No |
| 8 | gq | GLibc Quick Sort | 15.784 | 1452.0% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 22.401 | 2102.7% | No |
| 10 | is | Insertion Sort | 215.56 | 21096.2% | Yes |

#### Overall Winner (Average Across All Variants)

**Winner:** fw (Forsort With Workspace) - Average: 12.670 ns/item

### 100000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 18.441 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 19.616 | 6.4% | No |
| 3 | **fs** | Forsort Stable In-Place | 20.245 | 9.8% | Yes |
| 4 | wi | WikiSort | 26.176 | 41.9% | Yes |
| 5 | fb | Forsort Basic In-Place | 29.486 | 59.9% | Yes |
| 6 | ti | TimSort | 29.858 | 61.9% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 29.878 | 62.0% | No |
| 8 | gs | Grail Sort In-Place | 35.646 | 93.3% | Yes |
| 9 | is | Insertion Sort | 37.500 | 103.4% | Yes |
| 10 | gq | GLibc Quick Sort | 43.219 | 134.4% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 6.966 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 7.248 | 4.0% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 7.764 | 11.5% | No |
| 4 | fb | Forsort Basic In-Place | 9.349 | 34.2% | Yes |
| 5 | fs | Forsort Stable In-Place | 12.155 | 74.5% | Yes |
| 6 | wi | WikiSort | 13.450 | 93.1% | Yes |
| 7 | gs | Grail Sort In-Place | 15.924 | 128.6% | Yes |
| 8 | is | Insertion Sort | 19.803 | 184.3% | Yes |
| 9 | gq | GLibc Quick Sort | 19.816 | 184.5% | No |
| 10 | nq | Bentley/McIlroy Quick Sort | 24.972 | 258.5% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 25.364 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 27.450 | 8.2% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 28.119 | 10.9% | No |
| 4 | nq | Bentley/McIlroy Quick Sort | 40.981 | 61.6% | No |
| 5 | wi | WikiSort | 41.250 | 62.6% | Yes |
| 6 | gs | Grail Sort In-Place | 44.741 | 76.4% | Yes |
| 7 | ti | TimSort | 50.543 | 99.3% | Yes |
| 8 | fb | Forsort Basic In-Place | 54.852 | 116.3% | Yes |
| 9 | gq | GLibc Quick Sort | 57.951 | 128.5% | No |
| 10 | is | Insertion Sort | 126.38 | 398.3% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 14.509 | 0.0% | Yes |
| 2 | **ti** | TimSort | 17.189 | 18.5% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 20.299 | 39.9% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 20.657 | 42.4% | No |
| 5 | wi | WikiSort | 21.172 | 45.9% | Yes |
| 6 | fi | Forsort Unstable In-Place | 22.121 | 52.5% | No |
| 7 | fb | Forsort Basic In-Place | 26.553 | 83.0% | Yes |
| 8 | gs | Grail Sort In-Place | 27.880 | 92.2% | Yes |
| 9 | is | Insertion Sort | 28.837 | 98.8% | Yes |
| 10 | gq | GLibc Quick Sort | 33.048 | 127.8% | No |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 0.768 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.770 | 0.3% | Yes |
| 3 | **ti** | TimSort | 0.778 | 1.3% | Yes |
| 4 | fs | Forsort Stable In-Place | 1.040 | 35.4% | Yes |
| 5 | fi | Forsort Unstable In-Place | 1.063 | 38.4% | No |
| 6 | fw | Forsort With Workspace | 1.331 | 73.3% | Yes |
| 7 | wi | WikiSort | 2.711 | 253.0% | Yes |
| 8 | gs | Grail Sort In-Place | 13.816 | 1699.0% | Yes |
| 9 | gq | GLibc Quick Sort | 15.250 | 1885.7% | No |
| 10 | nq | Bentley/McIlroy Quick Sort | 20.640 | 2587.5% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | Forsort Basic In-Place | 0.768 | 0.0% | Yes |
| 2 | **is** | Insertion Sort | 0.768 | 0.0% | Yes |
| 3 | **ti** | TimSort | 0.777 | 1.2% | Yes |
| 4 | fs | Forsort Stable In-Place | 0.960 | 25.0% | Yes |
| 5 | fi | Forsort Unstable In-Place | 1.058 | 37.8% | No |
| 6 | fw | Forsort With Workspace | 1.260 | 64.1% | Yes |
| 7 | wi | WikiSort | 2.607 | 239.5% | Yes |
| 8 | gs | Grail Sort In-Place | 10.796 | 1305.7% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort | 15.874 | 1966.9% | No |
| 10 | gq | GLibc Quick Sort | 17.194 | 2138.8% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 24.007 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 26.604 | 10.8% | No |
| 3 | **fs** | Forsort Stable In-Place | 32.804 | 36.6% | Yes |
| 4 | gs | Grail Sort In-Place | 56.769 | 136.5% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 63.636 | 165.1% | No |
| 6 | wi | WikiSort | 63.969 | 166.5% | Yes |
| 7 | ti | TimSort | 77.216 | 221.6% | Yes |
| 8 | gq | GLibc Quick Sort | 78.090 | 225.3% | No |
| 9 | fb | Forsort Basic In-Place | 92.587 | 285.7% | Yes |
| 10 | is | Insertion Sort | 967.17 | 3928.7% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 23.238 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 25.903 | 11.5% | No |
| 3 | **fs** | Forsort Stable In-Place | 28.026 | 20.6% | Yes |
| 4 | gs | Grail Sort In-Place | 62.923 | 170.8% | Yes |
| 5 | wi | WikiSort | 63.123 | 171.6% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 63.931 | 175.1% | No |
| 7 | ti | TimSort | 81.015 | 248.6% | Yes |
| 8 | gq | GLibc Quick Sort | 87.486 | 276.5% | No |
| 9 | fb | Forsort Basic In-Place | 92.625 | 298.6% | Yes |
| 10 | is | Insertion Sort | 971.50 | 4080.7% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 12.378 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 15.316 | 23.7% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 15.469 | 25.0% | No |
| 4 | wi | WikiSort | 15.647 | 26.4% | Yes |
| 5 | fw | Forsort With Workspace | 16.978 | 37.2% | Yes |
| 6 | gs | Grail Sort In-Place | 24.127 | 94.9% | Yes |
| 7 | fb | Forsort Basic In-Place | 24.745 | 99.9% | Yes |
| 8 | gq | GLibc Quick Sort | 25.330 | 104.6% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 32.450 | 162.2% | No |
| 10 | is | Insertion Sort | 2484.1 | 19968.3% | Yes |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.922 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.978 | 114.5% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 2.344 | 154.2% | Yes |
| 4 | wi | WikiSort | 5.465 | 492.7% | Yes |
| 5 | gs | Grail Sort In-Place | 10.736 | 1064.4% | Yes |
| 6 | fi | Forsort Unstable In-Place | 14.118 | 1431.2% | No |
| 7 | fw | Forsort With Workspace | 14.288 | 1449.7% | Yes |
| 8 | gq | GLibc Quick Sort | 18.695 | 1927.7% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 30.192 | 3174.6% | No |
| 10 | is | Insertion Sort | 2359.9 | 255855.4% | Yes |

#### Overall Winner (Average Across All Variants)

**Winner:** fw (Forsort With Workspace) - Average: 14.666 ns/item

### 1000000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 19.579 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 20.605 | 5.2% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 20.662 | 5.5% | No |
| 4 | ti | TimSort | 28.209 | 44.1% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 30.135 | 53.9% | No |
| 6 | wi | WikiSort | 31.419 | 60.5% | Yes |
| 7 | fb | Forsort Basic In-Place | 33.807 | 72.7% | Yes |
| 8 | gs | Grail Sort In-Place | 40.173 | 105.2% | Yes |
| 9 | gq | GLibc Quick Sort | 42.707 | 118.1% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fi** | Forsort Unstable In-Place | 8.449 | 0.0% | No |
| 2 | **ti** | TimSort | 8.580 | 1.6% | Yes |
| 3 | **fw** | Forsort With Workspace | 8.752 | 3.6% | Yes |
| 4 | fs | Forsort Stable In-Place | 8.806 | 4.2% | Yes |
| 5 | fb | Forsort Basic In-Place | 11.451 | 35.5% | Yes |
| 6 | wi | WikiSort | 18.066 | 113.8% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 20.197 | 139.0% | No |
| 8 | gs | Grail Sort In-Place | 25.149 | 197.7% | Yes |
| 9 | gq | GLibc Quick Sort | 28.012 | 231.5% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 27.081 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 27.826 | 2.8% | No |
| 3 | **fs** | Forsort Stable In-Place | 28.703 | 6.0% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 45.269 | 67.2% | No |
| 5 | wi | WikiSort | 47.479 | 75.3% | Yes |
| 6 | gs | Grail Sort In-Place | 51.964 | 91.9% | Yes |
| 7 | ti | TimSort | 52.463 | 93.7% | Yes |
| 8 | gq | GLibc Quick Sort | 58.319 | 115.4% | No |
| 9 | fb | Forsort Basic In-Place | 61.600 | 127.5% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 16.025 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 16.526 | 3.1% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 16.837 | 5.1% | No |
| 4 | ti | TimSort | 19.532 | 21.9% | Yes |
| 5 | fb | Forsort Basic In-Place | 24.075 | 50.2% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 25.591 | 59.7% | No |
| 7 | wi | WikiSort | 26.924 | 68.0% | Yes |
| 8 | gs | Grail Sort In-Place | 35.557 | 121.9% | Yes |
| 9 | gq | GLibc Quick Sort | 37.000 | 130.9% | No |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | Forsort Basic In-Place | 0.780 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.873 | 11.9% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 0.995 | 27.6% | Yes |
| 4 | fi | Forsort Unstable In-Place | 1.072 | 37.4% | No |
| 5 | fw | Forsort With Workspace | 1.532 | 96.4% | Yes |
| 6 | wi | WikiSort | 2.634 | 237.7% | Yes |
| 7 | gs | Grail Sort In-Place | 13.657 | 1650.9% | Yes |
| 8 | gq | GLibc Quick Sort | 18.723 | 2300.4% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 21.078 | 2602.3% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.923 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.947 | 2.6% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.026 | 11.2% | Yes |
| 4 | fi | Forsort Unstable In-Place | 1.065 | 15.4% | No |
| 5 | fw | Forsort With Workspace | 1.727 | 87.1% | Yes |
| 6 | wi | WikiSort | 2.571 | 178.5% | Yes |
| 7 | gs | Grail Sort In-Place | 14.643 | 1486.5% | Yes |
| 8 | gq | GLibc Quick Sort | 17.867 | 1835.8% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 18.704 | 1926.4% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 27.005 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 29.815 | 10.4% | No |
| 3 | **fs** | Forsort Stable In-Place | 30.405 | 12.6% | Yes |
| 4 | gs | Grail Sort In-Place | 65.866 | 143.9% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 73.787 | 173.2% | No |
| 6 | wi | WikiSort | 75.893 | 181.0% | Yes |
| 7 | ti | TimSort | 90.253 | 234.2% | Yes |
| 8 | gq | GLibc Quick Sort | 94.365 | 249.4% | No |
| 9 | fb | Forsort Basic In-Place | 112.67 | 317.2% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 27.024 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 29.914 | 10.7% | No |
| 3 | **fs** | Forsort Stable In-Place | 31.217 | 15.5% | Yes |
| 4 | gs | Grail Sort In-Place | 65.259 | 141.5% | Yes |
| 5 | wi | WikiSort | 75.123 | 178.0% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 75.926 | 181.0% | No |
| 7 | ti | TimSort | 90.447 | 234.7% | Yes |
| 8 | gq | GLibc Quick Sort | 97.034 | 259.1% | No |
| 9 | fb | Forsort Basic In-Place | 105.69 | 291.1% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 11.770 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 12.769 | 8.5% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 18.673 | 58.6% | Yes |
| 4 | gs | Grail Sort In-Place | 18.809 | 59.8% | Yes |
| 5 | fi | Forsort Unstable In-Place | 19.616 | 66.7% | No |
| 6 | fw | Forsort With Workspace | 19.804 | 68.3% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 26.704 | 126.9% | No |
| 8 | fb | Forsort Basic In-Place | 28.186 | 139.5% | Yes |
| 9 | gq | GLibc Quick Sort | 36.613 | 211.1% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.031 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 2.018 | 95.7% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 2.804 | 172.0% | Yes |
| 4 | wi | WikiSort | 6.307 | 511.7% | Yes |
| 5 | gs | Grail Sort In-Place | 13.369 | 1196.7% | Yes |
| 6 | fw | Forsort With Workspace | 18.491 | 1693.5% | Yes |
| 7 | fi | Forsort Unstable In-Place | 18.841 | 1727.4% | No |
| 8 | gq | GLibc Quick Sort | 22.182 | 2051.5% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 26.991 | 2517.9% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Forsort Stable In-Place) - Average: 15.976 ns/item

### 10000000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 21.219 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 22.631 | 6.7% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 22.738 | 7.2% | No |
| 4 | ti | TimSort | 32.062 | 51.1% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 34.323 | 61.8% | No |
| 6 | fb | Forsort Basic In-Place | 39.431 | 85.8% | Yes |
| 7 | wi | WikiSort | 39.890 | 88.0% | Yes |
| 8 | gq | GLibc Quick Sort | 47.351 | 123.2% | No |
| 9 | gs | Grail Sort In-Place | 49.208 | 131.9% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 9.062 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 9.533 | 5.2% | No |
| 3 | **fs** | Forsort Stable In-Place | 9.620 | 6.2% | Yes |
| 4 | fw | Forsort With Workspace | 10.068 | 11.1% | Yes |
| 5 | fb | Forsort Basic In-Place | 13.245 | 46.2% | Yes |
| 6 | wi | WikiSort | 22.856 | 152.2% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 23.593 | 160.4% | No |
| 8 | gs | Grail Sort In-Place | 33.252 | 266.9% | Yes |
| 9 | gq | GLibc Quick Sort | 33.800 | 273.0% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 28.938 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 30.036 | 3.8% | No |
| 3 | **fs** | Forsort Stable In-Place | 31.203 | 7.8% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 52.391 | 81.0% | No |
| 5 | wi | WikiSort | 57.809 | 99.8% | Yes |
| 6 | ti | TimSort | 59.454 | 105.5% | Yes |
| 7 | gs | Grail Sort In-Place | 62.754 | 116.9% | Yes |
| 8 | gq | GLibc Quick Sort | 72.079 | 149.1% | No |
| 9 | fb | Forsort Basic In-Place | 72.472 | 150.4% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 16.978 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 17.381 | 2.4% | No |
| 3 | **fs** | Forsort Stable In-Place | 17.697 | 4.2% | Yes |
| 4 | ti | TimSort | 22.299 | 31.3% | Yes |
| 5 | fb | Forsort Basic In-Place | 27.807 | 63.8% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 29.257 | 72.3% | No |
| 7 | wi | WikiSort | 33.801 | 99.1% | Yes |
| 8 | gq | GLibc Quick Sort | 40.195 | 136.7% | No |
| 9 | gs | Grail Sort In-Place | 43.143 | 154.1% | Yes |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | Forsort Basic In-Place | 0.806 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.822 | 2.0% | Yes |
| 3 | **fw** | Forsort With Workspace | 0.896 | 11.2% | Yes |
| 4 | fi | Forsort Unstable In-Place | 0.937 | 16.3% | No |
| 5 | fs | Forsort Stable In-Place | 0.993 | 23.2% | Yes |
| 6 | wi | WikiSort | 2.119 | 162.9% | Yes |
| 7 | gs | Grail Sort In-Place | 16.960 | 2004.2% | Yes |
| 8 | gq | GLibc Quick Sort | 21.899 | 2617.0% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 22.610 | 2705.2% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.782 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.809 | 3.5% | Yes |
| 3 | **fw** | Forsort With Workspace | 0.894 | 14.3% | Yes |
| 4 | fi | Forsort Unstable In-Place | 0.957 | 22.4% | No |
| 5 | fs | Forsort Stable In-Place | 1.002 | 28.1% | Yes |
| 6 | wi | WikiSort | 2.046 | 161.6% | Yes |
| 7 | gs | Grail Sort In-Place | 15.822 | 1923.3% | Yes |
| 8 | gq | GLibc Quick Sort | 20.657 | 2541.6% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 20.761 | 2554.9% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 30.117 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 33.626 | 11.7% | No |
| 3 | **fs** | Forsort Stable In-Place | 34.836 | 15.7% | Yes |
| 4 | gs | Grail Sort In-Place | 77.802 | 158.3% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 87.728 | 191.3% | No |
| 6 | wi | WikiSort | 92.482 | 207.1% | Yes |
| 7 | ti | TimSort | 107.44 | 256.7% | Yes |
| 8 | gq | GLibc Quick Sort | 112.21 | 272.6% | No |
| 9 | fb | Forsort Basic In-Place | 123.75 | 310.9% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 30.668 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 33.198 | 8.2% | No |
| 3 | **fs** | Forsort Stable In-Place | 34.275 | 11.8% | Yes |
| 4 | gs | Grail Sort In-Place | 78.547 | 156.1% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 87.656 | 185.8% | No |
| 6 | wi | WikiSort | 90.514 | 195.1% | Yes |
| 7 | gq | GLibc Quick Sort | 108.27 | 253.0% | No |
| 8 | ti | TimSort | 108.99 | 255.4% | Yes |
| 9 | fb | Forsort Basic In-Place | 124.64 | 306.4% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 13.656 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 14.789 | 8.3% | Yes |
| 3 | **gs** | Grail Sort In-Place | 19.844 | 45.3% | Yes |
| 4 | fs | Forsort Stable In-Place | 23.414 | 71.5% | Yes |
| 5 | fw | Forsort With Workspace | 24.130 | 76.7% | Yes |
| 6 | fi | Forsort Unstable In-Place | 24.341 | 78.2% | No |
| 7 | nq | Bentley/McIlroy Quick Sort | 30.618 | 124.2% | No |
| 8 | fb | Forsort Basic In-Place | 32.368 | 137.0% | Yes |
| 9 | gq | GLibc Quick Sort | 46.624 | 241.4% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.999 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 2.133 | 113.5% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 2.927 | 193.0% | Yes |
| 4 | wi | WikiSort | 6.924 | 593.1% | Yes |
| 5 | gs | Grail Sort In-Place | 15.796 | 1481.2% | Yes |
| 6 | fw | Forsort With Workspace | 22.405 | 2142.7% | Yes |
| 7 | fi | Forsort Unstable In-Place | 23.516 | 2254.0% | No |
| 8 | gq | GLibc Quick Sort | 25.400 | 2442.5% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 31.570 | 3060.2% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Forsort Stable In-Place) - Average: 17.860 ns/item


## Detailed Results by Dataset Size

### 1000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| nq | Bentley/McIlroy Quick Sort | **0.000015700** | 8551 | **15.700** | Yes | 1 |
| is | Insertion Sort | **0.000018044** | 9914 | **18.044** | Yes | 2 |
| wi | WikiSort | **0.000018355** | 6814 | **18.355** | Yes | 3 |
| fw | Forsort With Workspace | 0.000018976 | 4638 | 18.976 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.000021650 | 5165 | 21.650 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000022603 | 6681 | 22.603 | Yes | 6 |
| gq | GLibc Quick Sort | 0.000022843 | 6406 | 22.843 | Yes | 7 |
| ti | TimSort | 0.000022933 | 4835 | 22.933 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000023705 | 5943 | 23.705 | Yes | 9 |
| fi | Forsort Unstable In-Place | 0.000023905 | 5175 | 23.905 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000003196** | 1926 | **3.196** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000005801** | 2212 | **5.801** | Yes | 2 |
| fw | Forsort With Workspace | **0.000006493** | 1355 | **6.493** | Yes | 3 |
| ti | TimSort | 0.000007625 | 2235 | 7.625 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.000008756 | 1496 | 8.756 | Yes | 5 |
| wi | WikiSort | 0.000009077 | 2792 | 9.077 | Yes | 6 |
| fs | Forsort Stable In-Place | 0.000009448 | 2744 | 9.448 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.000011361 | 8304 | 11.361 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000014738 | 5016 | 14.738 | Yes | 9 |
| gs | Grail Sort In-Place | 0.000015038 | 4933 | 15.038 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| nq | Bentley/McIlroy Quick Sort | **0.000023384** | 9211 | **23.384** | Yes | 1 |
| wi | WikiSort | **0.000026821** | 8846 | **26.821** | Yes | 2 |
| fw | Forsort With Workspace | **0.000027021** | 7428 | **27.021** | Yes | 3 |
| is | Insertion Sort | 0.000029506 | 10569 | 29.506 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.000029947 | 7835 | 29.947 | Yes | 5 |
| fs | Forsort Stable In-Place | 0.000032220 | 8302 | 32.220 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000033703 | 9042 | 33.703 | Yes | 7 |
| ti | TimSort | 0.000034886 | 7010 | 34.886 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000040717 | 9126 | 40.717 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000052820 | 8064 | 52.820 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000011581** | 7002 | **11.581** | Yes | 1 |
| nq | Bentley/McIlroy Quick Sort | **0.000013325** | 8389 | **13.325** | Yes | 2 |
| fw | Forsort With Workspace | **0.000013365** | 3122 | **13.365** | Yes | 3 |
| fb | Forsort Basic In-Place | 0.000014798 | 4435 | 14.798 | Yes | 4 |
| wi | WikiSort | 0.000015219 | 5635 | 15.219 | Yes | 5 |
| ti | TimSort | 0.000015800 | 3759 | 15.800 | Yes | 6 |
| fs | Forsort Stable In-Place | 0.000016200 | 3521 | 16.200 | Yes | 7 |
| fi | Forsort Unstable In-Place | 0.000017533 | 3455 | 17.533 | Yes | 8 |
| gs | Grail Sort In-Place | 0.000018024 | 5713 | 18.024 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000019016 | 5673 | 19.016 | Yes | 10 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000000942** | 999 | **0.942** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000001082** | 999 | **1.082** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000001362** | 999 | **1.362** | Yes | 3 |
| ti | TimSort | 0.000001673 | 999 | 1.673 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.000003276 | 1052 | 3.276 | Yes | 5 |
| fw | Forsort With Workspace | 0.000003657 | 1028 | 3.657 | Yes | 6 |
| wi | WikiSort | 0.000005831 | 2530 | 5.831 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000012103 | 4932 | 12.103 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000012374 | 7959 | 12.374 | No | 9 |
| gs | Grail Sort In-Place | 0.000015299 | 5139 | 15.299 | Yes | 10 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000000922** | 999 | **0.922** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000001062** | 999 | **1.062** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000001232** | 999 | **1.232** | Yes | 3 |
| ti | TimSort | 0.000001713 | 999 | 1.713 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.000003196 | 1052 | 3.196 | Yes | 5 |
| fw | Forsort With Workspace | 0.000003707 | 1028 | 3.707 | Yes | 6 |
| wi | WikiSort | 0.000005610 | 2530 | 5.610 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.000009588 | 8192 | 9.588 | Yes | 8 |
| gs | Grail Sort In-Place | 0.000011632 | 4790 | 11.632 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000012304 | 4932 | 12.304 | Yes | 10 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000025298** | 9545 | **25.298** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000032230** | 10166 | **32.230** | No | 2 |
| fs | Forsort Stable In-Place | **0.000035988** | 10564 | **35.988** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000040036 | 9551 | 40.036 | No | 4 |
| wi | WikiSort | 0.000040196 | 9532 | 40.196 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000047550 | 10486 | 47.550 | Yes | 6 |
| ti | TimSort | 0.000049243 | 8670 | 49.243 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000049904 | 8702 | 49.904 | Yes | 8 |
| is | Insertion Sort | 0.000050174 | 10897 | 50.174 | Yes | 9 |
| fb | Forsort Basic In-Place | 0.000060895 | 15144 | 60.895 | Yes | 10 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000028473** | 9543 | **28.473** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000030137** | 10128 | **30.137** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000034325** | 10446 | **34.325** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000038713 | 10449 | 38.713 | Yes | 4 |
| wi | WikiSort | 0.000038934 | 9528 | 38.934 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000045986 | 10421 | 45.986 | Yes | 6 |
| gq | GLibc Quick Sort | 0.000049794 | 8699 | 49.794 | Yes | 7 |
| ti | TimSort | 0.000049995 | 8667 | 49.995 | Yes | 8 |
| is | Insertion Sort | 0.000050676 | 10897 | 50.676 | Yes | 9 |
| fb | Forsort Basic In-Place | 0.000059933 | 15138 | 59.933 | Yes | 10 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| wi | WikiSort | **0.000013797** | 4824 | **13.797** | Yes | 1 |
| fw | Forsort With Workspace | **0.000016000** | 6577 | **16.000** | Yes | 2 |
| ti | TimSort | **0.000018555** | 4514 | **18.555** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000019327 | 11921 | 19.327 | No | 4 |
| fi | Forsort Unstable In-Place | 0.000019988 | 6543 | 19.988 | No | 5 |
| gs | Grail Sort In-Place | 0.000021140 | 5709 | 21.140 | Yes | 6 |
| fs | Forsort Stable In-Place | 0.000022783 | 5921 | 22.783 | Yes | 7 |
| is | Insertion Sort | 0.000023945 | 10980 | 23.945 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000029295 | 8586 | 29.295 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000046508 | 5231 | 46.508 | Yes | 10 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000001884** | 999 | **1.884** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000002885** | 1998 | **2.885** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000007304** | 2551 | **7.304** | Yes | 3 |
| wi | WikiSort | 0.000007875 | 3287 | 7.875 | Yes | 4 |
| fw | Forsort With Workspace | 0.000014167 | 6614 | 14.167 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000014207 | 5112 | 14.207 | Yes | 6 |
| gq | GLibc Quick Sort | 0.000014267 | 5044 | 14.267 | Yes | 7 |
| fi | Forsort Unstable In-Place | 0.000015940 | 6407 | 15.940 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000018124 | 14222 | 18.124 | Yes | 9 |
| is | Insertion Sort | 0.000022924 | 10980 | 22.924 | Yes | 10 |

### 10000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000173848** | 65993 | **17.385** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000189809** | 70201 | **18.981** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000201010** | 68128 | **20.101** | Yes | 3 |
| wi | WikiSort | 0.000211479 | 109711 | 21.148 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000221134 | 120049 | 22.113 | Yes | 5 |
| ti | TimSort | 0.000225676 | 56262 | 22.568 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000244321 | 105591 | 24.432 | Yes | 7 |
| fb | Forsort Basic In-Place | 0.000267105 | 79904 | 26.710 | Yes | 8 |
| is | Insertion Sort | 0.000279368 | 142293 | 27.937 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000514401 | 102041 | 51.440 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000054994** | 20318 | **5.499** | Yes | 1 |
| fw | Forsort With Workspace | **0.000056546** | 21323 | **5.655** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000061466** | 22792 | **6.147** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000065714 | 24197 | 6.571 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.000077897 | 32359 | 7.790 | Yes | 5 |
| is | Insertion Sort | 0.000078989 | 66299 | 7.899 | Yes | 6 |
| wi | WikiSort | 0.000081995 | 47827 | 8.200 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000121309 | 60937 | 12.131 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000161311 | 112554 | 16.131 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000208564 | 69350 | 20.856 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000226608** | 101352 | **22.661** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000245734** | 104888 | **24.573** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000260241** | 106432 | **26.024** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000297432 | 126774 | 29.743 | Yes | 4 |
| wi | WikiSort | 0.000326507 | 132042 | 32.651 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000390237 | 127531 | 39.024 | Yes | 6 |
| gq | GLibc Quick Sort | 0.000391048 | 115721 | 39.105 | Yes | 7 |
| ti | TimSort | 0.000391409 | 96274 | 39.141 | Yes | 8 |
| is | Insertion Sort | 0.000406027 | 143007 | 40.603 | Yes | 9 |
| fb | Forsort Basic In-Place | 0.000471039 | 126347 | 47.104 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000142850** | 46217 | **14.285** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000147248** | 49717 | **14.725** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000153870** | 50742 | **15.387** | Yes | 3 |
| ti | TimSort | 0.000153880 | 41101 | 15.388 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000156305 | 116444 | 15.630 | Yes | 5 |
| wi | WikiSort | 0.000167677 | 94710 | 16.768 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.000178167 | 60447 | 17.817 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000193215 | 89970 | 19.322 | Yes | 8 |
| is | Insertion Sort | 0.000200568 | 141517 | 20.057 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000394525 | 91579 | 39.453 | Yes | 10 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000007844** | 9999 | **0.784** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000007985** | 9999 | **0.799** | Yes | 2 |
| ti | TimSort | **0.000008606** | 9999 | **0.861** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000009919 | 9999 | 0.992 | Yes | 4 |
| fw | Forsort With Workspace | 0.000011742 | 10049 | 1.174 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.000011782 | 10091 | 1.178 | Yes | 6 |
| wi | WikiSort | 0.000034765 | 23719 | 3.477 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000109246 | 55113 | 10.925 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000125157 | 64608 | 12.516 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.000129595 | 109572 | 12.960 | No | 10 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000007845** | 9999 | **0.784** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000007965** | 9999 | **0.797** | Yes | 2 |
| ti | TimSort | **0.000008607** | 9999 | **0.861** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000009969 | 9999 | 0.997 | Yes | 4 |
| fw | Forsort With Workspace | 0.000011331 | 10049 | 1.133 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.000011572 | 10091 | 1.157 | Yes | 6 |
| wi | WikiSort | 0.000031369 | 23662 | 3.137 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000092084 | 53332 | 9.208 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000116300 | 111539 | 11.630 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000126449 | 64608 | 12.645 | Yes | 10 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000200058** | 126206 | **20.006** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000242758** | 133040 | **24.276** | No | 2 |
| fs | Forsort Stable In-Place | **0.000253498** | 133710 | **25.350** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000491047 | 130174 | 49.105 | No | 4 |
| wi | WikiSort | 0.000512999 | 143437 | 51.300 | Yes | 5 |
| ti | TimSort | 0.000611415 | 120348 | 61.142 | Yes | 6 |
| gq | GLibc Quick Sort | 0.000624800 | 120379 | 62.480 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000663763 | 138958 | 66.376 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000734447 | 207099 | 73.445 | Yes | 9 |
| is | Insertion Sort | 0.001155662 | 143533 | 115.57 | Yes | 10 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000201210** | 126191 | **20.121** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000239823** | 133036 | **23.982** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000250162** | 133652 | **25.016** | Yes | 3 |
| gs | Grail Sort In-Place | 0.000481489 | 138659 | 48.149 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000498862 | 137009 | 49.886 | Yes | 5 |
| wi | WikiSort | 0.000508450 | 143420 | 50.845 | Yes | 6 |
| ti | TimSort | 0.000610253 | 120349 | 61.025 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000685734 | 120381 | 68.573 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000717976 | 207075 | 71.798 | Yes | 9 |
| is | Insertion Sort | 0.001162425 | 143533 | 116.24 | Yes | 10 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000118183** | 39979 | **11.818** | Yes | 1 |
| wi | WikiSort | **0.000118494** | 51458 | **11.849** | Yes | 2 |
| fw | Forsort With Workspace | **0.000133151** | 97308 | **13.315** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.000133352 | 93311 | 13.335 | No | 4 |
| fs | Forsort Stable In-Place | 0.000137209 | 82441 | 13.721 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000151867 | 60858 | 15.187 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.000215988 | 165488 | 21.599 | No | 7 |
| fb | Forsort Basic In-Place | 0.000243249 | 87160 | 24.325 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000595294 | 70389 | 59.529 | Yes | 9 |
| is | Insertion Sort | 0.002603441 | 143612 | 260.34 | Yes | 10 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000010169** | 9999 | **1.017** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000020979** | 19998 | **2.098** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000025829** | 21910 | **2.583** | Yes | 3 |
| wi | WikiSort | 0.000051126 | 25008 | 5.113 | Yes | 4 |
| gs | Grail Sort In-Place | 0.000101952 | 57076 | 10.195 | Yes | 5 |
| fw | Forsort With Workspace | 0.000109617 | 98010 | 10.962 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.000115939 | 93366 | 11.594 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000157838 | 69008 | 15.784 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000224013 | 192779 | 22.401 | Yes | 9 |
| is | Insertion Sort | 0.002155645 | 143612 | 215.56 | Yes | 10 |

### 100000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.001844099** | 791210 | **18.441** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.001961594** | 831423 | **19.616** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.002024453** | 806980 | **20.245** | Yes | 3 |
| wi | WikiSort | 0.002617630 | 1484398 | 26.176 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.002948617 | 947643 | 29.486 | Yes | 5 |
| ti | TimSort | 0.002985758 | 677520 | 29.858 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.002987777 | 1537075 | 29.878 | No | 7 |
| gs | Grail Sort In-Place | 0.003564610 | 1432235 | 35.646 | Yes | 8 |
| is | Insertion Sort | 0.003750001 | 1766977 | 37.500 | Yes | 9 |
| gq | GLibc Quick Sort | 0.004321891 | 1389495 | 43.219 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000696616** | 254708 | **6.966** | Yes | 1 |
| fw | Forsort With Workspace | **0.000724769** | 293036 | **7.248** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000776436** | 308065 | **7.764** | Yes | 3 |
| fb | Forsort Basic In-Place | 0.000934865 | 431804 | 9.349 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.001215515 | 318465 | 12.155 | Yes | 5 |
| wi | WikiSort | 0.001344985 | 936287 | 13.450 | Yes | 6 |
| gs | Grail Sort In-Place | 0.001592407 | 904672 | 15.924 | Yes | 7 |
| is | Insertion Sort | 0.001980344 | 1743774 | 19.803 | Yes | 8 |
| gq | GLibc Quick Sort | 0.001981592 | 1046328 | 19.816 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.002497195 | 1516043 | 24.972 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.002536379** | 1236866 | **25.364** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.002745003** | 1266212 | **27.450** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.002811940** | 1268232 | **28.119** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.004098078 | 1625332 | 40.981 | No | 4 |
| wi | WikiSort | 0.004124969 | 1724079 | 41.250 | Yes | 5 |
| gs | Grail Sort In-Place | 0.004474117 | 1633206 | 44.741 | Yes | 6 |
| ti | TimSort | 0.005054293 | 1092617 | 50.543 | Yes | 7 |
| fb | Forsort Basic In-Place | 0.005485176 | 1535002 | 54.852 | Yes | 8 |
| gq | GLibc Quick Sort | 0.005795081 | 1511072 | 57.951 | Yes | 9 |
| is | Insertion Sort | 0.012638192 | 1768284 | 126.38 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.001450919** | 625323 | **14.509** | Yes | 1 |
| ti | TimSort | **0.001718906** | 522910 | **17.189** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.002029939** | 599475 | **20.299** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.002065691 | 1515354 | 20.657 | No | 4 |
| wi | WikiSort | 0.002117215 | 1321121 | 21.172 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.002212147 | 656475 | 22.121 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.002655300 | 735032 | 26.553 | Yes | 7 |
| gs | Grail Sort In-Place | 0.002788014 | 1280038 | 27.880 | Yes | 8 |
| is | Insertion Sort | 0.002883665 | 1764569 | 28.837 | Yes | 9 |
| gq | GLibc Quick Sort | 0.003304841 | 1299870 | 33.048 | Yes | 10 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000076816** | 99999 | **0.768** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000077036** | 99999 | **0.770** | Yes | 2 |
| ti | TimSort | **0.000077756** | 99999 | **0.778** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000104037 | 99999 | 1.040 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.000106281 | 100167 | 1.063 | Yes | 5 |
| fw | Forsort With Workspace | 0.000133101 | 100078 | 1.331 | Yes | 6 |
| wi | WikiSort | 0.000271052 | 240768 | 2.711 | Yes | 7 |
| gs | Grail Sort In-Place | 0.001381645 | 616261 | 13.816 | Yes | 8 |
| gq | GLibc Quick Sort | 0.001525019 | 815024 | 15.250 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.002064004 | 1479069 | 20.640 | No | 10 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | Forsort Basic In-Place | **0.000076836** | 99999 | **0.768** | Yes | 1 |
| is | Insertion Sort | **0.000076795** | 99999 | **0.768** | Yes | 2 |
| ti | TimSort | **0.000077707** | 99999 | **0.777** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000095961 | 99999 | 0.960 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.000105810 | 100167 | 1.058 | Yes | 5 |
| fw | Forsort With Workspace | 0.000126038 | 100078 | 1.260 | Yes | 6 |
| wi | WikiSort | 0.000260662 | 240530 | 2.607 | Yes | 7 |
| gs | Grail Sort In-Place | 0.001079609 | 608786 | 10.796 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.001587362 | 1524583 | 15.874 | Yes | 9 |
| gq | GLibc Quick Sort | 0.001719353 | 815024 | 17.194 | Yes | 10 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.002400710** | 1622428 | **24.007** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.002660383** | 1648605 | **26.604** | No | 2 |
| fs | Forsort Stable In-Place | **0.003280357** | 1702536 | **32.804** | Yes | 3 |
| gs | Grail Sort In-Place | 0.005676929 | 1691595 | 56.769 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.006363596 | 1640156 | 63.636 | No | 5 |
| wi | WikiSort | 0.006396878 | 1828864 | 63.969 | Yes | 6 |
| ti | TimSort | 0.007721569 | 1531448 | 77.216 | Yes | 7 |
| gq | GLibc Quick Sort | 0.007808995 | 1536166 | 78.090 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.009258692 | 2642972 | 92.587 | Yes | 9 |
| is | Insertion Sort | 0.096717451 | 1768738 | 967.17 | Yes | 10 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.002323778** | 1622478 | **23.238** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.002590271** | 1649183 | **25.903** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.002802602** | 1703019 | **28.026** | Yes | 3 |
| gs | Grail Sort In-Place | 0.006292341 | 1692166 | 62.923 | Yes | 4 |
| wi | WikiSort | 0.006312328 | 1828495 | 63.123 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.006393101 | 1717336 | 63.931 | Yes | 6 |
| ti | TimSort | 0.008101536 | 1531408 | 81.015 | Yes | 7 |
| gq | GLibc Quick Sort | 0.008748561 | 1536166 | 87.486 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.009262529 | 2645089 | 92.625 | Yes | 9 |
| is | Insertion Sort | 0.097150227 | 1768738 | 971.50 | Yes | 10 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.001237757** | 423392 | **12.378** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.001531638** | 1050201 | **15.316** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.001546931** | 1195859 | **15.469** | No | 3 |
| wi | WikiSort | 0.001564701 | 537302 | 15.647 | Yes | 4 |
| fw | Forsort With Workspace | 0.001697792 | 1228527 | 16.978 | Yes | 5 |
| gs | Grail Sort In-Place | 0.002412733 | 653093 | 24.127 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.002474508 | 874719 | 24.745 | Yes | 7 |
| gq | GLibc Quick Sort | 0.002533033 | 866253 | 25.330 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.003244994 | 1775969 | 32.450 | No | 9 |
| is | Insertion Sort | 0.248405359 | 1768918 | 2484.1 | Yes | 10 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000092184** | 99999 | **0.922** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000197753** | 199998 | **1.978** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000234443** | 210306 | **2.344** | Yes | 3 |
| wi | WikiSort | 0.000546527 | 284046 | 5.465 | Yes | 4 |
| gs | Grail Sort In-Place | 0.001073572 | 627299 | 10.736 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.001411836 | 1201428 | 14.118 | Yes | 6 |
| fw | Forsort With Workspace | 0.001428768 | 1235508 | 14.288 | Yes | 7 |
| gq | GLibc Quick Sort | 0.001869504 | 853904 | 18.695 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.003019207 | 1935567 | 30.192 | Yes | 9 |
| is | Insertion Sort | 0.235990878 | 1768918 | 2359.9 | Yes | 10 |

### 1000000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.019578709** | 9348531 | **19.579** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.020604506** | 9523259 | **20.605** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.020662023** | 10035648 | **20.662** | No | 3 |
| ti | TimSort | 0.028208739 | 7705166 | 28.209 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.030134638 | 18757448 | 30.135 | No | 5 |
| wi | WikiSort | 0.031419466 | 18764583 | 31.419 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.033806516 | 10708135 | 33.807 | Yes | 7 |
| gs | Grail Sort In-Place | 0.040173433 | 17976361 | 40.173 | Yes | 8 |
| gq | GLibc Quick Sort | 0.042707481 | 17436475 | 42.707 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fi | Forsort Unstable In-Place | **0.008448553** | 3524638 | **8.449** | No | 1 |
| ti | TimSort | **0.008580260** | 3191636 | **8.580** | Yes | 2 |
| fw | Forsort With Workspace | **0.008751585** | 3374464 | **8.752** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.008806007 | 3612221 | 8.806 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.011450740 | 4912080 | 11.451 | Yes | 5 |
| wi | WikiSort | 0.018066082 | 13269948 | 18.066 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.020196505 | 18248470 | 20.197 | No | 7 |
| gs | Grail Sort In-Place | 0.025149416 | 13144367 | 25.149 | Yes | 8 |
| gq | GLibc Quick Sort | 0.028012444 | 14447185 | 28.012 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.027081475** | 14553714 | **27.081** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.027826110** | 15090266 | **27.826** | No | 2 |
| fs | Forsort Stable In-Place | **0.028702736** | 14945609 | **28.703** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.045268794 | 19802661 | 45.269 | No | 4 |
| wi | WikiSort | 0.047478989 | 21143567 | 47.479 | Yes | 5 |
| gs | Grail Sort In-Place | 0.051964205 | 19780452 | 51.964 | Yes | 6 |
| ti | TimSort | 0.052463028 | 12434342 | 52.463 | Yes | 7 |
| gq | GLibc Quick Sort | 0.058319220 | 18502661 | 58.319 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.061599833 | 17971590 | 61.600 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.016025099** | 7201084 | **16.025** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.016525614** | 7242401 | **16.526** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.016837462** | 7699280 | **16.837** | No | 3 |
| ti | TimSort | 0.019532120 | 6025478 | 19.532 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.024074536 | 8177254 | 24.075 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.025590989 | 18492866 | 25.591 | No | 6 |
| wi | WikiSort | 0.026923713 | 17053388 | 26.924 | Yes | 7 |
| gs | Grail Sort In-Place | 0.035557172 | 16672002 | 35.557 | Yes | 8 |
| gq | GLibc Quick Sort | 0.036999764 | 16530918 | 37.000 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | Forsort Basic In-Place | **0.000780153** | 999999 | **0.780** | Yes | 1 |
| ti | TimSort | **0.000872517** | 999999 | **0.873** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000994908** | 999999 | **0.995** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.001071844 | 1000212 | 1.072 | Yes | 4 |
| fw | Forsort With Workspace | 0.001532153 | 1000058 | 1.532 | Yes | 5 |
| wi | WikiSort | 0.002634434 | 2596537 | 2.634 | Yes | 6 |
| gs | Grail Sort In-Place | 0.013657462 | 7043925 | 13.657 | Yes | 7 |
| gq | GLibc Quick Sort | 0.018723444 | 9884992 | 18.723 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.021078479 | 17945563 | 21.078 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000922522** | 999999 | **0.923** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000946928** | 999999 | **0.947** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.001026037** | 999999 | **1.026** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.001064710 | 1000212 | 1.065 | Yes | 4 |
| fw | Forsort With Workspace | 0.001726660 | 1000058 | 1.727 | Yes | 5 |
| wi | WikiSort | 0.002570724 | 2595342 | 2.571 | Yes | 6 |
| gs | Grail Sort In-Place | 0.014642688 | 7019410 | 14.643 | Yes | 7 |
| gq | GLibc Quick Sort | 0.017866645 | 9884992 | 17.867 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.018703565 | 18196618 | 18.704 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.027004530** | 19344227 | **27.005** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.029815326** | 20000785 | **29.815** | No | 2 |
| fs | Forsort Stable In-Place | **0.030405300** | 20136481 | **30.405** | Yes | 3 |
| gs | Grail Sort In-Place | 0.065866130 | 20156763 | 65.866 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.073787402 | 20553611 | 73.787 | No | 5 |
| wi | WikiSort | 0.075892618 | 22375013 | 75.893 | Yes | 6 |
| ti | TimSort | 0.090253491 | 18290244 | 90.253 | Yes | 7 |
| gq | GLibc Quick Sort | 0.094364803 | 18671395 | 94.365 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.112674130 | 31924599 | 112.67 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.027024058** | 19344337 | **27.024** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.029914322** | 20003927 | **29.914** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.031216676** | 20144554 | **31.217** | Yes | 3 |
| gs | Grail Sort In-Place | 0.065258528 | 20154575 | 65.259 | Yes | 4 |
| wi | WikiSort | 0.075122574 | 22370399 | 75.123 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.075926289 | 20868688 | 75.926 | Yes | 6 |
| ti | TimSort | 0.090447047 | 18290499 | 90.447 | Yes | 7 |
| gq | GLibc Quick Sort | 0.097034233 | 18671395 | 97.034 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.105689299 | 31940258 | 105.69 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.011769794** | 4401865 | **11.770** | Yes | 1 |
| wi | WikiSort | **0.012768959** | 6525364 | **12.769** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.018672878** | 13913561 | **18.673** | Yes | 3 |
| gs | Grail Sort In-Place | 0.018808596 | 7771207 | 18.809 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.019615817 | 15717682 | 19.616 | No | 5 |
| fw | Forsort With Workspace | 0.019803654 | 16347747 | 19.804 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.026704001 | 21898144 | 26.704 | No | 7 |
| fb | Forsort Basic In-Place | 0.028186461 | 8713098 | 28.186 | Yes | 8 |
| gq | GLibc Quick Sort | 0.036613179 | 10249850 | 36.613 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.001031017** | 999999 | **1.031** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.002018160** | 1999998 | **2.018** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.002804055** | 2088913 | **2.804** | Yes | 3 |
| wi | WikiSort | 0.006306860 | 3273489 | 6.307 | Yes | 4 |
| gs | Grail Sort In-Place | 0.013368642 | 7551070 | 13.369 | Yes | 5 |
| fw | Forsort With Workspace | 0.018490554 | 16420327 | 18.491 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.018841204 | 15784214 | 18.841 | Yes | 7 |
| gq | GLibc Quick Sort | 0.022182005 | 10066432 | 22.182 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.026991293 | 24025703 | 26.991 | Yes | 9 |

### 10000000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.212190237** | 108062257 | **21.219** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.226306165** | 111378588 | **22.631** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.227382463** | 115392550 | **22.738** | No | 3 |
| ti | TimSort | 0.320621459 | 80899342 | 32.062 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.343228960 | 221620434 | 34.323 | No | 5 |
| fb | Forsort Basic In-Place | 0.394309576 | 118907223 | 39.431 | Yes | 6 |
| wi | WikiSort | 0.398904032 | 222638416 | 39.890 | Yes | 7 |
| gq | GLibc Quick Sort | 0.473511623 | 207836717 | 47.351 | Yes | 8 |
| gs | Grail Sort In-Place | 0.492080045 | 215643949 | 49.208 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.090624875** | 29034572 | **9.062** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.095334504** | 44268314 | **9.533** | No | 2 |
| fs | Forsort Stable In-Place | **0.096200361** | 45723521 | **9.620** | Yes | 3 |
| fw | Forsort With Workspace | 0.100680716 | 42894715 | 10.068 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.132453030 | 52321148 | 13.245 | Yes | 5 |
| wi | WikiSort | 0.228560388 | 161674690 | 22.856 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.235930683 | 214985800 | 23.593 | No | 7 |
| gs | Grail Sort In-Place | 0.332520029 | 167107953 | 33.252 | Yes | 8 |
| gq | GLibc Quick Sort | 0.338004308 | 178719900 | 33.800 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.289375908** | 165645932 | **28.938** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.300361469** | 173895640 | **30.036** | No | 2 |
| fs | Forsort Stable In-Place | **0.312029848** | 171498604 | **31.203** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.523906357 | 233347510 | 52.391 | No | 4 |
| wi | WikiSort | 0.578092182 | 249353467 | 57.809 | Yes | 5 |
| ti | TimSort | 0.594535740 | 139122422 | 59.454 | Yes | 6 |
| gs | Grail Sort In-Place | 0.627543945 | 232407212 | 62.754 | Yes | 7 |
| gq | GLibc Quick Sort | 0.720792319 | 218019265 | 72.079 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.724721859 | 205423876 | 72.472 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.169781293** | 83058524 | **16.978** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.173810859** | 87825094 | **17.381** | No | 2 |
| fs | Forsort Stable In-Place | **0.176965856** | 86531834 | **17.697** | Yes | 3 |
| ti | TimSort | 0.222994811 | 59750966 | 22.299 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.278074604 | 89509650 | 27.807 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.292568040 | 218696014 | 29.257 | No | 6 |
| wi | WikiSort | 0.338012264 | 204484322 | 33.801 | Yes | 7 |
| gq | GLibc Quick Sort | 0.401947926 | 199491157 | 40.195 | Yes | 8 |
| gs | Grail Sort In-Place | 0.431433972 | 201569842 | 43.143 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | Forsort Basic In-Place | **0.008055760** | 9999999 | **0.806** | Yes | 1 |
| ti | TimSort | **0.008220862** | 9999999 | **0.822** | Yes | 2 |
| fw | Forsort With Workspace | **0.008960379** | 10000089 | **0.896** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.009370352 | 10000304 | 0.937 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.009933326 | 9999999 | 0.993 | Yes | 5 |
| wi | WikiSort | 0.021190620 | 20127971 | 2.119 | Yes | 6 |
| gs | Grail Sort In-Place | 0.169602813 | 79282702 | 16.960 | Yes | 7 |
| gq | GLibc Quick Sort | 0.218990385 | 114434624 | 21.899 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.226096302 | 209619989 | 22.610 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.007823401** | 9999999 | **0.782** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.008086007** | 9999999 | **0.809** | Yes | 2 |
| fw | Forsort With Workspace | **0.008944910** | 10000089 | **0.894** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.009572313 | 10000304 | 0.957 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.010017896 | 9999999 | 1.002 | Yes | 5 |
| wi | WikiSort | 0.020464349 | 20122509 | 2.046 | Yes | 6 |
| gs | Grail Sort In-Place | 0.158224827 | 79189929 | 15.822 | Yes | 7 |
| gq | GLibc Quick Sort | 0.206565356 | 114434624 | 20.657 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.207612912 | 211572877 | 20.761 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.301173910** | 225441758 | **30.117** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.336261433** | 232288484 | **33.626** | No | 2 |
| fs | Forsort Stable In-Place | **0.348358849** | 235476695 | **34.836** | Yes | 3 |
| gs | Grail Sort In-Place | 0.778015711 | 236936715 | 77.802 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.877276720 | 237131562 | 87.728 | No | 5 |
| wi | WikiSort | 0.924820731 | 266882917 | 92.482 | Yes | 6 |
| ti | TimSort | 1.074393132 | 213811853 | 107.44 | Yes | 7 |
| gq | GLibc Quick Sort | 1.122142440 | 220067417 | 112.21 | Yes | 8 |
| fb | Forsort Basic In-Place | 1.237487885 | 373483234 | 123.75 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.306675017** | 225441805 | **30.668** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.331976464** | 232334009 | **33.198** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.342748457** | 235566350 | **34.275** | Yes | 3 |
| gs | Grail Sort In-Place | 0.785473930 | 236874687 | 78.547 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.876564928 | 244066204 | 87.656 | Yes | 5 |
| wi | WikiSort | 0.905138788 | 266816725 | 90.514 | Yes | 6 |
| gq | GLibc Quick Sort | 1.082702133 | 220067428 | 108.27 | Yes | 7 |
| ti | TimSort | 1.089873136 | 213807264 | 108.99 | Yes | 8 |
| fb | Forsort Basic In-Place | 1.246419495 | 373634696 | 124.64 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.136563583** | 39874238 | **13.656** | Yes | 1 |
| wi | WikiSort | **0.147893978** | 63017582 | **14.789** | Yes | 2 |
| gs | Grail Sort In-Place | **0.198444009** | 84024780 | **19.844** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.234135963 | 177392059 | 23.414 | Yes | 4 |
| fw | Forsort With Workspace | 0.241298834 | 197268472 | 24.130 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.243414350 | 190726110 | 24.341 | No | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.306184177 | 264937278 | 30.618 | No | 7 |
| fb | Forsort Basic In-Place | 0.323675058 | 87246533 | 32.368 | Yes | 8 |
| gq | GLibc Quick Sort | 0.466244958 | 120240926 | 46.624 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.009994701** | 9999999 | **0.999** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.021334533** | 19999998 | **2.133** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.029273504** | 20867892 | **2.927** | Yes | 3 |
| wi | WikiSort | 0.069244068 | 21498750 | 6.924 | Yes | 4 |
| gs | Grail Sort In-Place | 0.157961778 | 81979307 | 15.796 | Yes | 5 |
| fw | Forsort With Workspace | 0.224052013 | 197985849 | 22.405 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.235160168 | 191369358 | 23.516 | Yes | 7 |
| gq | GLibc Quick Sort | 0.254004954 | 118788160 | 25.400 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.315696319 | 290683459 | 31.570 | Yes | 9 |


## Stability Verification

| Sort Type | Name | Expected | Verified (1M random) |
|-----------|------|----------|---------------------|
| fb | Forsort Basic In-Place | Stable | N/A |
| fi | Forsort Unstable In-Place | Unstable | N/A |
| fw | Forsort With Workspace | Stable | N/A |
| fs | Forsort Stable In-Place | Stable | N/A |
| gs | Grail Sort In-Place | Stable | N/A |
| gq | GLibc Quick Sort | Unstable | N/A |
| nq | Bentley/McIlroy Quick Sort | Unstable | N/A |
| ti | TimSort | Stable | N/A |
| wi | WikiSort | Stable | N/A |
| is | Insertion Sort | Stable | N/A |

---
*Generated automatically from benchmark_results.csv*
