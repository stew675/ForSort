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

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****4.693** | *****10.864** | *****15.586** | *****18.167** | *****19.698** | *****21.184** | *****25.319** |
| fi | ****5.135** | ****12.593** | ****17.230** | ****19.055** | ****20.716** | ****22.668** | ****25.854** |
| fs | ***6.525** | ***12.106** | ***17.221** | ***19.445** | ***20.579** | ***22.259** | ***26.271** |
| ti | 6.869 | 13.164 | 19.654 | 23.747 | 27.192 | 31.586 | 35.888 |
| nq | 8.425 | 12.736 | 18.362 | 23.450 | 28.810 | 33.727 | 39.049 |
| wi | 5.541 | 11.451 | 19.581 | 25.823 | 31.845 | 39.706 | 47.361 |
| fb | 5.722 | 15.316 | 23.349 | 29.062 | 34.082 | 39.270 | 46.189 |
| gs | 9.493 | 15.230 | 23.549 | 30.893 | 40.115 | 49.158 | 59.085 |
| gq | 10.415 | 19.215 | 27.252 | 32.867 | 39.627 | 47.684 | 57.548 |

### 1 Percent Disordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| ti | *****2.315** | *****3.637** | *****4.497** | *****6.485** | *****8.395** | *****9.018** | *****10.619** |
| fw | ****2.166** | ****2.018** | ****4.179** | ****6.949** | ****8.073** | ****9.157** | ****12.841** |
| fi | ***2.050** | ***2.295** | ***4.746** | ***7.490** | ***8.571** | ***9.605** | ***12.368** |
| fs | 2.607 | 3.027 | 4.974 | 7.586 | 8.435 | 9.445 | 12.416 |
| fb | 2.242 | 2.969 | 5.836 | 9.317 | 11.408 | 13.211 | 15.703 |
| wi | 2.573 | 3.286 | 6.670 | 13.019 | 17.614 | 22.760 | 30.225 |
| nq | 6.209 | 9.394 | 12.320 | 16.495 | 19.903 | 23.196 | 26.849 |
| gs | 6.429 | 8.365 | 11.092 | 15.269 | 23.967 | 32.249 | 42.673 |
| gq | 7.165 | 10.882 | 14.415 | 20.574 | 26.517 | 32.645 | 40.236 |

### 25 Percent Disordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****9.949** | *****17.021** | *****21.026** | *****24.043** | *****26.655** | *****28.965** | *****34.709** |
| fi | ****10.926** | ****18.793** | ****22.511** | ****25.152** | ****27.530** | ****30.612** | ****34.723** |
| fs | ***14.442** | ***21.382** | ***23.913** | ***26.571** | ***28.617** | ***31.209** | ***36.517** |
| nq | 13.156 | 20.753 | 28.600 | 35.750 | 43.490 | 51.766 | 59.471 |
| wi | 11.332 | 18.970 | 30.654 | 38.949 | 46.186 | 56.621 | 66.835 |
| ti | 13.880 | 25.013 | 35.431 | 43.254 | 49.896 | 58.151 | 67.678 |
| gs | 16.261 | 26.170 | 34.290 | 42.555 | 51.334 | 61.136 | 72.284 |
| gq | 18.197 | 29.905 | 40.553 | 48.230 | 57.110 | 68.779 | 81.293 |
| fb | 15.405 | 30.225 | 42.476 | 52.750 | 62.488 | 71.671 | 82.765 |

### 5 Percent Disordered

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****3.100** | *****6.433** | *****11.472** | *****13.890** | *****15.110** | *****16.406** | *****20.154** |
| fi | ****3.181** | ****7.653** | ****12.927** | ****15.043** | ****16.136** | ****17.454** | ****20.247** |
| fs | ***4.026** | ***7.361** | ***13.068** | ***14.842** | ***16.108** | ***17.504** | ***20.454** |
| ti | 4.917 | 8.470 | 13.203 | 16.764 | 19.327 | 22.154 | 25.171 |
| fb | 3.447 | 8.947 | 16.038 | 20.452 | 24.226 | 27.842 | 32.916 |
| nq | 7.166 | 10.844 | 15.065 | 19.845 | 24.365 | 28.661 | 33.121 |
| wi | 3.681 | 7.542 | 15.136 | 20.497 | 26.086 | 32.538 | 40.751 |
| gs | 7.611 | 11.291 | 18.334 | 25.455 | 34.218 | 42.734 | 53.703 |
| gq | 8.278 | 15.275 | 22.510 | 27.679 | 34.021 | 40.941 | 50.214 |

### Ordered Duplicates

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| ti | *****0.956** | *****0.811** | *****0.783** | *****0.780** | *****0.859** | *****0.803** | *****0.786** |
| fb | ****1.121** | ****0.990** | ****0.955** | ****0.847** | ****0.820** | ****0.789** | ****0.779** |
| fs | ***1.145** | ***0.989** | ***1.022** | ***1.012** | ***1.281** | ***1.075** | ***0.979** |
| fi | 1.846 | 1.185 | 0.942 | 1.035 | 1.002 | 0.921 | 1.449 |
| fw | 2.019 | 1.188 | 0.877 | 1.009 | 1.150 | 0.900 | 2.091 |
| wi | 2.289 | 2.524 | 2.876 | 2.612 | 2.598 | 2.105 | 2.408 |
| gs | 11.666 | 10.368 | 11.042 | 11.648 | 13.587 | 17.613 | 23.439 |
| gq | 6.839 | 10.001 | 11.787 | 14.112 | 17.024 | 19.976 | 24.553 |
| nq | 7.368 | 10.348 | 12.660 | 17.358 | 19.965 | 21.813 | 25.899 |

### Ordered Unique

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| ti | *****0.968** | *****0.811** | *****0.784** | *****0.780** | *****0.872** | *****0.806** | *****0.779** |
| fb | ****1.111** | ****0.985** | ****0.958** | ****0.844** | ****0.798** | ****0.787** | ****0.781** |
| fs | ***1.140** | ***0.989** | ***1.055** | ***1.009** | ***1.224** | ***1.099** | ***0.977** |
| fi | 1.842 | 1.173 | 0.922 | 1.027 | 1.053 | 0.933 | 1.438 |
| fw | 2.045 | 1.208 | 0.887 | 1.019 | 1.208 | 0.897 | 2.089 |
| wi | 2.294 | 2.525 | 2.573 | 2.478 | 2.522 | 2.046 | 2.352 |
| gs | 5.973 | 7.646 | 9.095 | 10.492 | 12.655 | 16.457 | 22.029 |
| gq | 6.756 | 9.774 | 11.730 | 13.998 | 17.071 | 19.916 | 24.302 |
| nq | 5.956 | 8.835 | 11.512 | 15.724 | 18.342 | 20.789 | 24.354 |

### Random Duplicates

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****15.489** | *****16.631** | *****18.612** | *****22.754** | *****25.572** | *****28.840** | *****36.371** |
| fi | ****17.836** | ****20.888** | ****23.066** | ****26.861** | ****29.680** | ****33.682** | ****39.539** |
| fs | ***23.666** | ***24.025** | ***24.030** | ***27.339** | ***30.076** | ***34.628** | ***42.954** |
| gs | 32.730 | 38.820 | 47.549 | 55.731 | 64.535 | 77.192 | 90.826 |
| nq | 23.218 | 35.583 | 48.074 | 60.203 | 72.170 | 84.060 | 96.011 |
| wi | 21.796 | 32.643 | 49.609 | 61.691 | 74.020 | 89.680 | 105.96 |
| ti | 27.646 | 43.660 | 59.557 | 73.895 | 88.417 | 104.19 | 120.80 |
| gq | 32.727 | 48.904 | 66.182 | 77.649 | 92.033 | 110.01 | 126.48 |
| fb | 29.599 | 48.257 | 68.341 | 86.751 | 105.61 | 123.90 | 145.15 |

### Random Unique

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| fw | *****15.378** | *****16.602** | *****18.537** | *****22.638** | *****25.574** | *****29.297** | *****36.743** |
| fi | ****18.095** | ****20.562** | ****22.521** | ****26.354** | ****29.639** | ****32.896** | ****38.795** |
| fs | ***23.197** | ***24.163** | ***24.163** | ***27.494** | ***30.370** | ***33.936** | ***42.881** |
| gs | 30.619 | 38.577 | 47.335 | 56.029 | 64.751 | 77.165 | 91.126 |
| nq | 24.393 | 36.978 | 49.520 | 62.802 | 75.763 | 85.675 | 97.539 |
| wi | 21.381 | 32.367 | 50.427 | 61.796 | 73.922 | 89.836 | 105.86 |
| ti | 27.590 | 43.338 | 59.394 | 73.587 | 88.009 | 104.09 | 120.87 |
| gq | 32.406 | 49.050 | 65.785 | 77.048 | 92.044 | 108.99 | 126.48 |
| fb | 29.182 | 48.283 | 68.119 | 86.440 | 106.64 | 124.93 | 144.44 |

### Reversed Duplicates

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| ti | *****9.142** | *****9.510** | *****9.455** | *****9.844** | *****10.354** | *****12.000** | *****15.239** |
| wi | ****7.191** | ****7.691** | ****9.856** | ****11.120** | ****12.177** | ****15.519** | ****20.715** |
| fw | ***7.357** | ***8.402** | ***11.390** | ***14.338** | ***18.797** | ***22.648** | ***30.515** |
| gs | 14.900 | 13.423 | 14.197 | 14.935 | 17.217 | 20.020 | 27.015 |
| fi | 9.109 | 9.371 | 12.009 | 14.889 | 19.248 | 24.773 | 34.835 |
| fs | 15.003 | 10.409 | 12.090 | 14.416 | 18.390 | 24.400 | 35.722 |
| nq | 11.588 | 16.360 | 21.176 | 21.976 | 26.113 | 30.305 | 30.893 |
| fb | 17.450 | 19.809 | 21.680 | 24.060 | 27.984 | 32.389 | 52.167 |
| gq | 20.421 | 24.575 | 31.374 | 35.785 | 36.819 | 42.728 | 51.063 |

### Reversed Unique

| Sort Type | 100 items | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|----------|
| ti | *****1.091** | *****0.944** | *****0.912** | *****0.912** | *****0.975** | *****0.926** | *****1.049** |
| fb | ****1.154** | ****1.010** | ****1.005** | ****1.004** | ****1.086** | ****1.079** | ****1.243** |
| fs | ***1.275** | ***1.052** | ***1.050** | ***1.080** | ***1.190** | ***1.259** | ***1.563** |
| wi | 3.054 | 3.480 | 4.372 | 4.963 | 6.067 | 6.970 | 12.426 |
| gs | 6.503 | 8.050 | 9.592 | 10.836 | 13.612 | 16.588 | 23.075 |
| fw | 6.006 | 7.235 | 10.387 | 13.339 | 17.742 | 21.541 | 29.882 |
| fi | 7.404 | 7.527 | 10.558 | 14.011 | 18.267 | 23.824 | 34.549 |
| gq | 9.440 | 11.696 | 14.455 | 16.890 | 19.754 | 24.772 | 31.527 |
| nq | 11.398 | 17.208 | 22.690 | 21.505 | 25.924 | 30.854 | 29.539 |


## Cross-Category Analysis

### Win Count by Algorithm

| Rank | Sort Type | Name | Wins | Top 3 | Win Rate |
|------|-----------|------|------|-------|----------|
| 1 | **fw** | Forsort With Workspace | 38 | 50 | 54.3% |
| 2 | **ti** | TimSort | 24 | 31 | 34.3% |
| 3 | **fb** | Forsort Basic In-Place | 5 | 22 | 7.1% |
| 4 | **wi** | WikiSort | 2 | 14 | 2.9% |
| 5 | **fi** | Forsort Unstable In-Place | 1 | 44 | 1.4% |

### Recommendations by Use Case

- **Best Stable Sort:** fs (Forsort Stable In-Place) - Avg: 18.461 ns/item (1M-100M items)
- **Best Unstable Sort:** fi (Forsort Unstable In-Place) - Avg: 20.434 ns/item (1M-100M items)
- **Best for Nearly-Sorted Data:** fw (Forsort With Workspace) - Avg: 9.425 ns/item


## Performance Rankings

### 100 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 4.693 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 5.135 | 9.4% | No |
| 3 | **wi** | WikiSort | 5.541 | 18.1% | Yes |
| 4 | fb | Forsort Basic In-Place | 5.722 | 21.9% | Yes |
| 5 | fs | Forsort Stable In-Place | 6.525 | 39.0% | Yes |
| 6 | ti | TimSort | 6.869 | 46.4% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 8.425 | 79.5% | No |
| 8 | gs | Grail Sort In-Place | 9.493 | 102.3% | Yes |
| 9 | gq | GLibc Quick Sort | 10.415 | 121.9% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fi** | Forsort Unstable In-Place | 2.050 | 0.0% | No |
| 2 | **fw** | Forsort With Workspace | 2.166 | 5.7% | Yes |
| 3 | **fb** | Forsort Basic In-Place | 2.242 | 9.4% | Yes |
| 4 | ti | TimSort | 2.315 | 12.9% | Yes |
| 5 | wi | WikiSort | 2.573 | 25.5% | Yes |
| 6 | fs | Forsort Stable In-Place | 2.607 | 27.2% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 6.209 | 202.9% | No |
| 8 | gs | Grail Sort In-Place | 6.429 | 213.6% | Yes |
| 9 | gq | GLibc Quick Sort | 7.165 | 249.5% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 9.949 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 10.926 | 9.8% | No |
| 3 | **wi** | WikiSort | 11.332 | 13.9% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 13.156 | 32.2% | No |
| 5 | ti | TimSort | 13.880 | 39.5% | Yes |
| 6 | fs | Forsort Stable In-Place | 14.442 | 45.2% | Yes |
| 7 | fb | Forsort Basic In-Place | 15.405 | 54.8% | Yes |
| 8 | gs | Grail Sort In-Place | 16.261 | 63.4% | Yes |
| 9 | gq | GLibc Quick Sort | 18.197 | 82.9% | No |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 3.100 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 3.181 | 2.6% | No |
| 3 | **fb** | Forsort Basic In-Place | 3.447 | 11.2% | Yes |
| 4 | wi | WikiSort | 3.681 | 18.7% | Yes |
| 5 | fs | Forsort Stable In-Place | 4.026 | 29.9% | Yes |
| 6 | ti | TimSort | 4.917 | 58.6% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 7.166 | 131.2% | No |
| 8 | gs | Grail Sort In-Place | 7.611 | 145.5% | Yes |
| 9 | gq | GLibc Quick Sort | 8.278 | 167.0% | No |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.956 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.121 | 17.3% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.145 | 19.8% | Yes |
| 4 | fi | Forsort Unstable In-Place | 1.846 | 93.1% | No |
| 5 | fw | Forsort With Workspace | 2.019 | 111.2% | Yes |
| 6 | wi | WikiSort | 2.289 | 139.4% | Yes |
| 7 | gq | GLibc Quick Sort | 6.839 | 615.4% | No |
| 8 | nq | Bentley/McIlroy Quick Sort | 7.368 | 670.7% | No |
| 9 | gs | Grail Sort In-Place | 11.666 | 1120.3% | Yes |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.968 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.111 | 14.8% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.140 | 17.8% | Yes |
| 4 | fi | Forsort Unstable In-Place | 1.842 | 90.3% | No |
| 5 | fw | Forsort With Workspace | 2.045 | 111.3% | Yes |
| 6 | wi | WikiSort | 2.294 | 137.0% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 5.956 | 515.3% | No |
| 8 | gs | Grail Sort In-Place | 5.973 | 517.0% | Yes |
| 9 | gq | GLibc Quick Sort | 6.756 | 597.9% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 15.489 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 17.836 | 15.2% | No |
| 3 | **wi** | WikiSort | 21.796 | 40.7% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 23.218 | 49.9% | No |
| 5 | fs | Forsort Stable In-Place | 23.666 | 52.8% | Yes |
| 6 | ti | TimSort | 27.646 | 78.5% | Yes |
| 7 | fb | Forsort Basic In-Place | 29.599 | 91.1% | Yes |
| 8 | gq | GLibc Quick Sort | 32.727 | 111.3% | No |
| 9 | gs | Grail Sort In-Place | 32.730 | 111.3% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 15.378 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 18.095 | 17.7% | No |
| 3 | **wi** | WikiSort | 21.381 | 39.0% | Yes |
| 4 | fs | Forsort Stable In-Place | 23.197 | 50.8% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 24.393 | 58.6% | No |
| 6 | ti | TimSort | 27.590 | 79.4% | Yes |
| 7 | fb | Forsort Basic In-Place | 29.182 | 89.8% | Yes |
| 8 | gs | Grail Sort In-Place | 30.619 | 99.1% | Yes |
| 9 | gq | GLibc Quick Sort | 32.406 | 110.7% | No |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **wi** | WikiSort | 7.191 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 7.357 | 2.3% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 9.109 | 26.7% | No |
| 4 | ti | TimSort | 9.142 | 27.1% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 11.588 | 61.1% | No |
| 6 | gs | Grail Sort In-Place | 14.900 | 107.2% | Yes |
| 7 | fs | Forsort Stable In-Place | 15.003 | 108.6% | Yes |
| 8 | fb | Forsort Basic In-Place | 17.450 | 142.7% | Yes |
| 9 | gq | GLibc Quick Sort | 20.421 | 184.0% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.091 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.154 | 5.8% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.275 | 16.9% | Yes |
| 4 | wi | WikiSort | 3.054 | 179.9% | Yes |
| 5 | fw | Forsort With Workspace | 6.006 | 450.5% | Yes |
| 6 | gs | Grail Sort In-Place | 6.503 | 496.1% | Yes |
| 7 | fi | Forsort Unstable In-Place | 7.404 | 578.6% | No |
| 8 | gq | GLibc Quick Sort | 9.440 | 765.3% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 11.398 | 944.7% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fw (Forsort With Workspace) - Average: 6.820 ns/item

### 1000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 10.864 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 11.451 | 5.4% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 12.106 | 11.4% | Yes |
| 4 | fi | Forsort Unstable In-Place | 12.593 | 15.9% | No |
| 5 | nq | Bentley/McIlroy Quick Sort | 12.736 | 17.2% | No |
| 6 | ti | TimSort | 13.164 | 21.2% | Yes |
| 7 | gs | Grail Sort In-Place | 15.230 | 40.2% | Yes |
| 8 | fb | Forsort Basic In-Place | 15.316 | 41.0% | Yes |
| 9 | gq | GLibc Quick Sort | 19.215 | 76.9% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 2.018 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 2.295 | 13.7% | No |
| 3 | **fb** | Forsort Basic In-Place | 2.969 | 47.1% | Yes |
| 4 | fs | Forsort Stable In-Place | 3.027 | 50.0% | Yes |
| 5 | wi | WikiSort | 3.286 | 62.8% | Yes |
| 6 | ti | TimSort | 3.637 | 80.2% | Yes |
| 7 | gs | Grail Sort In-Place | 8.365 | 314.5% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 9.394 | 365.5% | No |
| 9 | gq | GLibc Quick Sort | 10.882 | 439.2% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 17.021 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 18.793 | 10.4% | No |
| 3 | **wi** | WikiSort | 18.970 | 11.5% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 20.753 | 21.9% | No |
| 5 | fs | Forsort Stable In-Place | 21.382 | 25.6% | Yes |
| 6 | ti | TimSort | 25.013 | 47.0% | Yes |
| 7 | gs | Grail Sort In-Place | 26.170 | 53.8% | Yes |
| 8 | gq | GLibc Quick Sort | 29.905 | 75.7% | No |
| 9 | fb | Forsort Basic In-Place | 30.225 | 77.6% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 6.433 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 7.361 | 14.4% | Yes |
| 3 | **wi** | WikiSort | 7.542 | 17.2% | Yes |
| 4 | fi | Forsort Unstable In-Place | 7.653 | 19.0% | No |
| 5 | ti | TimSort | 8.470 | 31.7% | Yes |
| 6 | fb | Forsort Basic In-Place | 8.947 | 39.1% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 10.844 | 68.6% | No |
| 8 | gs | Grail Sort In-Place | 11.291 | 75.5% | Yes |
| 9 | gq | GLibc Quick Sort | 15.275 | 137.4% | No |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.811 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 0.989 | 21.9% | Yes |
| 3 | **fb** | Forsort Basic In-Place | 0.990 | 22.1% | Yes |
| 4 | fi | Forsort Unstable In-Place | 1.185 | 46.1% | No |
| 5 | fw | Forsort With Workspace | 1.188 | 46.5% | Yes |
| 6 | wi | WikiSort | 2.524 | 211.2% | Yes |
| 7 | gq | GLibc Quick Sort | 10.001 | 1133.2% | No |
| 8 | nq | Bentley/McIlroy Quick Sort | 10.348 | 1176.0% | No |
| 9 | gs | Grail Sort In-Place | 10.368 | 1178.4% | Yes |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.811 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.985 | 21.5% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 0.989 | 21.9% | Yes |
| 4 | fi | Forsort Unstable In-Place | 1.173 | 44.6% | No |
| 5 | fw | Forsort With Workspace | 1.208 | 49.0% | Yes |
| 6 | wi | WikiSort | 2.525 | 211.3% | Yes |
| 7 | gs | Grail Sort In-Place | 7.646 | 842.8% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 8.835 | 989.4% | No |
| 9 | gq | GLibc Quick Sort | 9.774 | 1105.2% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 16.631 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 20.888 | 25.6% | No |
| 3 | **fs** | Forsort Stable In-Place | 24.025 | 44.5% | Yes |
| 4 | wi | WikiSort | 32.643 | 96.3% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 35.583 | 114.0% | No |
| 6 | gs | Grail Sort In-Place | 38.820 | 133.4% | Yes |
| 7 | ti | TimSort | 43.660 | 162.5% | Yes |
| 8 | fb | Forsort Basic In-Place | 48.257 | 190.2% | Yes |
| 9 | gq | GLibc Quick Sort | 48.904 | 194.1% | No |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 16.602 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 20.562 | 23.9% | No |
| 3 | **fs** | Forsort Stable In-Place | 24.163 | 45.5% | Yes |
| 4 | wi | WikiSort | 32.367 | 95.0% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 36.978 | 122.7% | No |
| 6 | gs | Grail Sort In-Place | 38.577 | 132.4% | Yes |
| 7 | ti | TimSort | 43.338 | 161.0% | Yes |
| 8 | fb | Forsort Basic In-Place | 48.283 | 190.8% | Yes |
| 9 | gq | GLibc Quick Sort | 49.050 | 195.4% | No |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **wi** | WikiSort | 7.691 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 8.402 | 9.2% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 9.371 | 21.8% | No |
| 4 | ti | TimSort | 9.510 | 23.7% | Yes |
| 5 | fs | Forsort Stable In-Place | 10.409 | 35.3% | Yes |
| 6 | gs | Grail Sort In-Place | 13.423 | 74.5% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 16.360 | 112.7% | No |
| 8 | fb | Forsort Basic In-Place | 19.809 | 157.6% | Yes |
| 9 | gq | GLibc Quick Sort | 24.575 | 219.5% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.944 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.010 | 7.0% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.052 | 11.4% | Yes |
| 4 | wi | WikiSort | 3.480 | 268.6% | Yes |
| 5 | fw | Forsort With Workspace | 7.235 | 666.4% | Yes |
| 6 | fi | Forsort Unstable In-Place | 7.527 | 697.4% | No |
| 7 | gs | Grail Sort In-Place | 8.050 | 752.8% | Yes |
| 8 | gq | GLibc Quick Sort | 11.696 | 1139.0% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 17.208 | 1722.9% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fw (Forsort With Workspace) - Average: 8.760 ns/item

### 10000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 15.586 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 17.221 | 10.5% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 17.230 | 10.5% | No |
| 4 | nq | Bentley/McIlroy Quick Sort | 18.362 | 17.8% | No |
| 5 | wi | WikiSort | 19.581 | 25.6% | Yes |
| 6 | ti | TimSort | 19.654 | 26.1% | Yes |
| 7 | fb | Forsort Basic In-Place | 23.349 | 49.8% | Yes |
| 8 | gs | Grail Sort In-Place | 23.549 | 51.1% | Yes |
| 9 | gq | GLibc Quick Sort | 27.252 | 74.8% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 4.179 | 0.0% | Yes |
| 2 | **ti** | TimSort | 4.497 | 7.6% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 4.746 | 13.6% | No |
| 4 | fs | Forsort Stable In-Place | 4.974 | 19.0% | Yes |
| 5 | fb | Forsort Basic In-Place | 5.836 | 39.7% | Yes |
| 6 | wi | WikiSort | 6.670 | 59.6% | Yes |
| 7 | gs | Grail Sort In-Place | 11.092 | 165.4% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 12.320 | 194.8% | No |
| 9 | gq | GLibc Quick Sort | 14.415 | 244.9% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 21.026 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 22.511 | 7.1% | No |
| 3 | **fs** | Forsort Stable In-Place | 23.913 | 13.7% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 28.600 | 36.0% | No |
| 5 | wi | WikiSort | 30.654 | 45.8% | Yes |
| 6 | gs | Grail Sort In-Place | 34.290 | 63.1% | Yes |
| 7 | ti | TimSort | 35.431 | 68.5% | Yes |
| 8 | gq | GLibc Quick Sort | 40.553 | 92.9% | No |
| 9 | fb | Forsort Basic In-Place | 42.476 | 102.0% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 11.472 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 12.927 | 12.7% | No |
| 3 | **fs** | Forsort Stable In-Place | 13.068 | 13.9% | Yes |
| 4 | ti | TimSort | 13.203 | 15.1% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 15.065 | 31.3% | No |
| 6 | wi | WikiSort | 15.136 | 31.9% | Yes |
| 7 | fb | Forsort Basic In-Place | 16.038 | 39.8% | Yes |
| 8 | gs | Grail Sort In-Place | 18.334 | 59.8% | Yes |
| 9 | gq | GLibc Quick Sort | 22.510 | 96.2% | No |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.783 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 0.877 | 12.0% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 0.942 | 20.3% | No |
| 4 | fb | Forsort Basic In-Place | 0.955 | 22.0% | Yes |
| 5 | fs | Forsort Stable In-Place | 1.022 | 30.5% | Yes |
| 6 | wi | WikiSort | 2.876 | 267.3% | Yes |
| 7 | gs | Grail Sort In-Place | 11.042 | 1310.2% | Yes |
| 8 | gq | GLibc Quick Sort | 11.787 | 1405.4% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 12.660 | 1516.9% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.784 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 0.887 | 13.1% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 0.922 | 17.6% | No |
| 4 | fb | Forsort Basic In-Place | 0.958 | 22.2% | Yes |
| 5 | fs | Forsort Stable In-Place | 1.055 | 34.6% | Yes |
| 6 | wi | WikiSort | 2.573 | 228.2% | Yes |
| 7 | gs | Grail Sort In-Place | 9.095 | 1060.1% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 11.512 | 1368.4% | No |
| 9 | gq | GLibc Quick Sort | 11.730 | 1396.2% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 18.612 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 23.066 | 23.9% | No |
| 3 | **fs** | Forsort Stable In-Place | 24.030 | 29.1% | Yes |
| 4 | gs | Grail Sort In-Place | 47.549 | 155.5% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 48.074 | 158.3% | No |
| 6 | wi | WikiSort | 49.609 | 166.5% | Yes |
| 7 | ti | TimSort | 59.557 | 220.0% | Yes |
| 8 | gq | GLibc Quick Sort | 66.182 | 255.6% | No |
| 9 | fb | Forsort Basic In-Place | 68.341 | 267.2% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 18.537 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 22.521 | 21.5% | No |
| 3 | **fs** | Forsort Stable In-Place | 24.163 | 30.4% | Yes |
| 4 | gs | Grail Sort In-Place | 47.335 | 155.4% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 49.520 | 167.1% | No |
| 6 | wi | WikiSort | 50.427 | 172.0% | Yes |
| 7 | ti | TimSort | 59.394 | 220.4% | Yes |
| 8 | gq | GLibc Quick Sort | 65.785 | 254.9% | No |
| 9 | fb | Forsort Basic In-Place | 68.119 | 267.5% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 9.455 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 9.856 | 4.2% | Yes |
| 3 | **fw** | Forsort With Workspace | 11.390 | 20.5% | Yes |
| 4 | fi | Forsort Unstable In-Place | 12.009 | 27.0% | No |
| 5 | fs | Forsort Stable In-Place | 12.090 | 27.9% | Yes |
| 6 | gs | Grail Sort In-Place | 14.197 | 50.2% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 21.176 | 124.0% | No |
| 8 | fb | Forsort Basic In-Place | 21.680 | 129.3% | Yes |
| 9 | gq | GLibc Quick Sort | 31.374 | 231.8% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.912 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.005 | 10.2% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.050 | 15.1% | Yes |
| 4 | wi | WikiSort | 4.372 | 379.4% | Yes |
| 5 | gs | Grail Sort In-Place | 9.592 | 951.8% | Yes |
| 6 | fw | Forsort With Workspace | 10.387 | 1038.9% | Yes |
| 7 | fi | Forsort Unstable In-Place | 10.558 | 1057.7% | No |
| 8 | gq | GLibc Quick Sort | 14.455 | 1485.0% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 22.690 | 2387.9% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fw (Forsort With Workspace) - Average: 11.295 ns/item

### 100000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 18.167 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 19.055 | 4.9% | No |
| 3 | **fs** | Forsort Stable In-Place | 19.445 | 7.0% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 23.450 | 29.1% | No |
| 5 | ti | TimSort | 23.747 | 30.7% | Yes |
| 6 | wi | WikiSort | 25.823 | 42.1% | Yes |
| 7 | fb | Forsort Basic In-Place | 29.062 | 60.0% | Yes |
| 8 | gs | Grail Sort In-Place | 30.893 | 70.1% | Yes |
| 9 | gq | GLibc Quick Sort | 32.867 | 80.9% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 6.485 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 6.949 | 7.2% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 7.490 | 15.5% | No |
| 4 | fs | Forsort Stable In-Place | 7.586 | 17.0% | Yes |
| 5 | fb | Forsort Basic In-Place | 9.317 | 43.7% | Yes |
| 6 | wi | WikiSort | 13.019 | 100.8% | Yes |
| 7 | gs | Grail Sort In-Place | 15.269 | 135.5% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 16.495 | 154.4% | No |
| 9 | gq | GLibc Quick Sort | 20.574 | 217.3% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 24.043 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 25.152 | 4.6% | No |
| 3 | **fs** | Forsort Stable In-Place | 26.571 | 10.5% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 35.750 | 48.7% | No |
| 5 | wi | WikiSort | 38.949 | 62.0% | Yes |
| 6 | gs | Grail Sort In-Place | 42.555 | 77.0% | Yes |
| 7 | ti | TimSort | 43.254 | 79.9% | Yes |
| 8 | gq | GLibc Quick Sort | 48.230 | 100.6% | No |
| 9 | fb | Forsort Basic In-Place | 52.750 | 119.4% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 13.890 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 14.842 | 6.9% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 15.043 | 8.3% | No |
| 4 | ti | TimSort | 16.764 | 20.7% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 19.845 | 42.9% | No |
| 6 | fb | Forsort Basic In-Place | 20.452 | 47.2% | Yes |
| 7 | wi | WikiSort | 20.497 | 47.6% | Yes |
| 8 | gs | Grail Sort In-Place | 25.455 | 83.3% | Yes |
| 9 | gq | GLibc Quick Sort | 27.679 | 99.3% | No |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.780 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.847 | 8.6% | Yes |
| 3 | **fw** | Forsort With Workspace | 1.009 | 29.4% | Yes |
| 4 | fs | Forsort Stable In-Place | 1.012 | 29.7% | Yes |
| 5 | fi | Forsort Unstable In-Place | 1.035 | 32.7% | No |
| 6 | wi | WikiSort | 2.612 | 234.9% | Yes |
| 7 | gs | Grail Sort In-Place | 11.648 | 1393.3% | Yes |
| 8 | gq | GLibc Quick Sort | 14.112 | 1709.2% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 17.358 | 2125.4% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.780 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.844 | 8.2% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.009 | 29.4% | Yes |
| 4 | fw | Forsort With Workspace | 1.019 | 30.6% | Yes |
| 5 | fi | Forsort Unstable In-Place | 1.027 | 31.7% | No |
| 6 | wi | WikiSort | 2.478 | 217.7% | Yes |
| 7 | gs | Grail Sort In-Place | 10.492 | 1245.1% | Yes |
| 8 | gq | GLibc Quick Sort | 13.998 | 1694.6% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 15.724 | 1915.9% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 22.754 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 26.861 | 18.0% | No |
| 3 | **fs** | Forsort Stable In-Place | 27.339 | 20.2% | Yes |
| 4 | gs | Grail Sort In-Place | 55.731 | 144.9% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 60.203 | 164.6% | No |
| 6 | wi | WikiSort | 61.691 | 171.1% | Yes |
| 7 | ti | TimSort | 73.895 | 224.8% | Yes |
| 8 | gq | GLibc Quick Sort | 77.649 | 241.3% | No |
| 9 | fb | Forsort Basic In-Place | 86.751 | 281.3% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 22.638 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 26.354 | 16.4% | No |
| 3 | **fs** | Forsort Stable In-Place | 27.494 | 21.5% | Yes |
| 4 | gs | Grail Sort In-Place | 56.029 | 147.5% | Yes |
| 5 | wi | WikiSort | 61.796 | 173.0% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 62.802 | 177.4% | No |
| 7 | ti | TimSort | 73.587 | 225.1% | Yes |
| 8 | gq | GLibc Quick Sort | 77.048 | 240.3% | No |
| 9 | fb | Forsort Basic In-Place | 86.440 | 281.8% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 9.844 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 11.120 | 13.0% | Yes |
| 3 | **fw** | Forsort With Workspace | 14.338 | 45.7% | Yes |
| 4 | fs | Forsort Stable In-Place | 14.416 | 46.4% | Yes |
| 5 | fi | Forsort Unstable In-Place | 14.889 | 51.2% | No |
| 6 | gs | Grail Sort In-Place | 14.935 | 51.7% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 21.976 | 123.2% | No |
| 8 | fb | Forsort Basic In-Place | 24.060 | 144.4% | Yes |
| 9 | gq | GLibc Quick Sort | 35.785 | 263.5% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.912 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.004 | 10.1% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.080 | 18.4% | Yes |
| 4 | wi | WikiSort | 4.963 | 444.2% | Yes |
| 5 | gs | Grail Sort In-Place | 10.836 | 1088.2% | Yes |
| 6 | fw | Forsort With Workspace | 13.339 | 1362.6% | Yes |
| 7 | fi | Forsort Unstable In-Place | 14.011 | 1436.3% | No |
| 8 | gq | GLibc Quick Sort | 16.890 | 1752.0% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 21.505 | 2258.0% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fw (Forsort With Workspace) - Average: 13.815 ns/item

### 1000000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 19.698 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 20.579 | 4.5% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 20.716 | 5.2% | No |
| 4 | ti | TimSort | 27.192 | 38.0% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 28.810 | 46.3% | No |
| 6 | wi | WikiSort | 31.845 | 61.7% | Yes |
| 7 | fb | Forsort Basic In-Place | 34.082 | 73.0% | Yes |
| 8 | gq | GLibc Quick Sort | 39.627 | 101.2% | No |
| 9 | gs | Grail Sort In-Place | 40.115 | 103.7% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 8.073 | 0.0% | Yes |
| 2 | **ti** | TimSort | 8.395 | 4.0% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 8.435 | 4.5% | Yes |
| 4 | fi | Forsort Unstable In-Place | 8.571 | 6.2% | No |
| 5 | fb | Forsort Basic In-Place | 11.408 | 41.3% | Yes |
| 6 | wi | WikiSort | 17.614 | 118.2% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 19.903 | 146.5% | No |
| 8 | gs | Grail Sort In-Place | 23.967 | 196.9% | Yes |
| 9 | gq | GLibc Quick Sort | 26.517 | 228.5% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 26.655 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 27.530 | 3.3% | No |
| 3 | **fs** | Forsort Stable In-Place | 28.617 | 7.4% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 43.490 | 63.2% | No |
| 5 | wi | WikiSort | 46.186 | 73.3% | Yes |
| 6 | ti | TimSort | 49.896 | 87.2% | Yes |
| 7 | gs | Grail Sort In-Place | 51.334 | 92.6% | Yes |
| 8 | gq | GLibc Quick Sort | 57.110 | 114.3% | No |
| 9 | fb | Forsort Basic In-Place | 62.488 | 134.4% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 15.110 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 16.108 | 6.6% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 16.136 | 6.8% | No |
| 4 | ti | TimSort | 19.327 | 27.9% | Yes |
| 5 | fb | Forsort Basic In-Place | 24.226 | 60.3% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 24.365 | 61.3% | No |
| 7 | wi | WikiSort | 26.086 | 72.6% | Yes |
| 8 | gq | GLibc Quick Sort | 34.021 | 125.2% | No |
| 9 | gs | Grail Sort In-Place | 34.218 | 126.5% | Yes |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | Forsort Basic In-Place | 0.820 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.859 | 4.8% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 1.002 | 22.2% | No |
| 4 | fw | Forsort With Workspace | 1.150 | 40.2% | Yes |
| 5 | fs | Forsort Stable In-Place | 1.281 | 56.2% | Yes |
| 6 | wi | WikiSort | 2.598 | 216.8% | Yes |
| 7 | gs | Grail Sort In-Place | 13.587 | 1557.0% | Yes |
| 8 | gq | GLibc Quick Sort | 17.024 | 1976.1% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 19.965 | 2334.8% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | Forsort Basic In-Place | 0.798 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.872 | 9.3% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 1.053 | 32.0% | No |
| 4 | fw | Forsort With Workspace | 1.208 | 51.4% | Yes |
| 5 | fs | Forsort Stable In-Place | 1.224 | 53.4% | Yes |
| 6 | wi | WikiSort | 2.522 | 216.0% | Yes |
| 7 | gs | Grail Sort In-Place | 12.655 | 1485.8% | Yes |
| 8 | gq | GLibc Quick Sort | 17.071 | 2039.2% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 18.342 | 2198.5% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 25.572 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 29.680 | 16.1% | No |
| 3 | **fs** | Forsort Stable In-Place | 30.076 | 17.6% | Yes |
| 4 | gs | Grail Sort In-Place | 64.535 | 152.4% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 72.170 | 182.2% | No |
| 6 | wi | WikiSort | 74.020 | 189.5% | Yes |
| 7 | ti | TimSort | 88.417 | 245.8% | Yes |
| 8 | gq | GLibc Quick Sort | 92.033 | 259.9% | No |
| 9 | fb | Forsort Basic In-Place | 105.61 | 313.0% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 25.574 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 29.639 | 15.9% | No |
| 3 | **fs** | Forsort Stable In-Place | 30.370 | 18.8% | Yes |
| 4 | gs | Grail Sort In-Place | 64.751 | 153.2% | Yes |
| 5 | wi | WikiSort | 73.922 | 189.1% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 75.763 | 196.3% | No |
| 7 | ti | TimSort | 88.009 | 244.1% | Yes |
| 8 | gq | GLibc Quick Sort | 92.044 | 259.9% | No |
| 9 | fb | Forsort Basic In-Place | 106.64 | 317.0% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 10.354 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 12.177 | 17.6% | Yes |
| 3 | **gs** | Grail Sort In-Place | 17.217 | 66.3% | Yes |
| 4 | fs | Forsort Stable In-Place | 18.390 | 77.6% | Yes |
| 5 | fw | Forsort With Workspace | 18.797 | 81.5% | Yes |
| 6 | fi | Forsort Unstable In-Place | 19.248 | 85.9% | No |
| 7 | nq | Bentley/McIlroy Quick Sort | 26.113 | 152.2% | No |
| 8 | fb | Forsort Basic In-Place | 27.984 | 170.3% | Yes |
| 9 | gq | GLibc Quick Sort | 36.819 | 255.6% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.975 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.086 | 11.4% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.190 | 22.1% | Yes |
| 4 | wi | WikiSort | 6.067 | 522.3% | Yes |
| 5 | gs | Grail Sort In-Place | 13.612 | 1296.1% | Yes |
| 6 | fw | Forsort With Workspace | 17.742 | 1719.7% | Yes |
| 7 | fi | Forsort Unstable In-Place | 18.267 | 1773.5% | No |
| 8 | gq | GLibc Quick Sort | 19.754 | 1926.1% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 25.924 | 2558.9% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Forsort Stable In-Place) - Average: 15.627 ns/item

### 10000000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 21.184 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 22.259 | 5.1% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 22.668 | 7.0% | No |
| 4 | ti | TimSort | 31.586 | 49.1% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 33.727 | 59.2% | No |
| 6 | fb | Forsort Basic In-Place | 39.270 | 85.4% | Yes |
| 7 | wi | WikiSort | 39.706 | 87.4% | Yes |
| 8 | gq | GLibc Quick Sort | 47.684 | 125.1% | No |
| 9 | gs | Grail Sort In-Place | 49.158 | 132.1% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 9.018 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 9.157 | 1.5% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 9.445 | 4.7% | Yes |
| 4 | fi | Forsort Unstable In-Place | 9.605 | 6.5% | No |
| 5 | fb | Forsort Basic In-Place | 13.211 | 46.5% | Yes |
| 6 | wi | WikiSort | 22.760 | 152.4% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 23.196 | 157.2% | No |
| 8 | gs | Grail Sort In-Place | 32.249 | 257.6% | Yes |
| 9 | gq | GLibc Quick Sort | 32.645 | 262.0% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 28.965 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 30.612 | 5.7% | No |
| 3 | **fs** | Forsort Stable In-Place | 31.209 | 7.7% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 51.766 | 78.7% | No |
| 5 | wi | WikiSort | 56.621 | 95.5% | Yes |
| 6 | ti | TimSort | 58.151 | 100.8% | Yes |
| 7 | gs | Grail Sort In-Place | 61.136 | 111.1% | Yes |
| 8 | gq | GLibc Quick Sort | 68.779 | 137.5% | No |
| 9 | fb | Forsort Basic In-Place | 71.671 | 147.4% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 16.406 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 17.454 | 6.4% | No |
| 3 | **fs** | Forsort Stable In-Place | 17.504 | 6.7% | Yes |
| 4 | ti | TimSort | 22.154 | 35.0% | Yes |
| 5 | fb | Forsort Basic In-Place | 27.842 | 69.7% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 28.661 | 74.7% | No |
| 7 | wi | WikiSort | 32.538 | 98.3% | Yes |
| 8 | gq | GLibc Quick Sort | 40.941 | 149.5% | No |
| 9 | gs | Grail Sort In-Place | 42.734 | 160.5% | Yes |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | Forsort Basic In-Place | 0.789 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.803 | 1.8% | Yes |
| 3 | **fw** | Forsort With Workspace | 0.900 | 14.1% | Yes |
| 4 | fi | Forsort Unstable In-Place | 0.921 | 16.7% | No |
| 5 | fs | Forsort Stable In-Place | 1.075 | 36.2% | Yes |
| 6 | wi | WikiSort | 2.105 | 166.8% | Yes |
| 7 | gs | Grail Sort In-Place | 17.613 | 2132.3% | Yes |
| 8 | gq | GLibc Quick Sort | 19.976 | 2431.8% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 21.813 | 2664.6% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | Forsort Basic In-Place | 0.787 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.806 | 2.4% | Yes |
| 3 | **fw** | Forsort With Workspace | 0.897 | 14.0% | Yes |
| 4 | fi | Forsort Unstable In-Place | 0.933 | 18.6% | No |
| 5 | fs | Forsort Stable In-Place | 1.099 | 39.6% | Yes |
| 6 | wi | WikiSort | 2.046 | 160.0% | Yes |
| 7 | gs | Grail Sort In-Place | 16.457 | 1991.1% | Yes |
| 8 | gq | GLibc Quick Sort | 19.916 | 2430.6% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 20.789 | 2541.6% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 28.840 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 33.682 | 16.8% | No |
| 3 | **fs** | Forsort Stable In-Place | 34.628 | 20.1% | Yes |
| 4 | gs | Grail Sort In-Place | 77.192 | 167.7% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 84.060 | 191.5% | No |
| 6 | wi | WikiSort | 89.680 | 211.0% | Yes |
| 7 | ti | TimSort | 104.19 | 261.3% | Yes |
| 8 | gq | GLibc Quick Sort | 110.01 | 281.4% | No |
| 9 | fb | Forsort Basic In-Place | 123.90 | 329.6% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 29.297 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 32.896 | 12.3% | No |
| 3 | **fs** | Forsort Stable In-Place | 33.936 | 15.8% | Yes |
| 4 | gs | Grail Sort In-Place | 77.165 | 163.4% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 85.675 | 192.4% | No |
| 6 | wi | WikiSort | 89.836 | 206.6% | Yes |
| 7 | ti | TimSort | 104.09 | 255.3% | Yes |
| 8 | gq | GLibc Quick Sort | 108.99 | 272.0% | No |
| 9 | fb | Forsort Basic In-Place | 124.93 | 326.4% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 12.000 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 15.519 | 29.3% | Yes |
| 3 | **gs** | Grail Sort In-Place | 20.020 | 66.8% | Yes |
| 4 | fw | Forsort With Workspace | 22.648 | 88.7% | Yes |
| 5 | fs | Forsort Stable In-Place | 24.400 | 103.3% | Yes |
| 6 | fi | Forsort Unstable In-Place | 24.773 | 106.4% | No |
| 7 | nq | Bentley/McIlroy Quick Sort | 30.305 | 152.5% | No |
| 8 | fb | Forsort Basic In-Place | 32.389 | 169.9% | Yes |
| 9 | gq | GLibc Quick Sort | 42.728 | 256.1% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.926 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.079 | 16.5% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.259 | 36.0% | Yes |
| 4 | wi | WikiSort | 6.970 | 652.7% | Yes |
| 5 | gs | Grail Sort In-Place | 16.588 | 1691.4% | Yes |
| 6 | fw | Forsort With Workspace | 21.541 | 2226.2% | Yes |
| 7 | fi | Forsort Unstable In-Place | 23.824 | 2472.8% | No |
| 8 | gq | GLibc Quick Sort | 24.772 | 2575.2% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 30.854 | 3232.0% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Forsort Stable In-Place) - Average: 17.681 ns/item

### 100000000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 25.319 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 25.854 | 2.1% | No |
| 3 | **fs** | Forsort Stable In-Place | 26.271 | 3.8% | Yes |
| 4 | ti | TimSort | 35.888 | 41.7% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 39.049 | 54.2% | No |
| 6 | fb | Forsort Basic In-Place | 46.189 | 82.4% | Yes |
| 7 | wi | WikiSort | 47.361 | 87.1% | Yes |
| 8 | gq | GLibc Quick Sort | 57.548 | 127.3% | No |
| 9 | gs | Grail Sort In-Place | 59.085 | 133.4% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 10.619 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 12.368 | 16.5% | No |
| 3 | **fs** | Forsort Stable In-Place | 12.416 | 16.9% | Yes |
| 4 | fw | Forsort With Workspace | 12.841 | 20.9% | Yes |
| 5 | fb | Forsort Basic In-Place | 15.703 | 47.9% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 26.849 | 152.8% | No |
| 7 | wi | WikiSort | 30.225 | 184.6% | Yes |
| 8 | gq | GLibc Quick Sort | 40.236 | 278.9% | No |
| 9 | gs | Grail Sort In-Place | 42.673 | 301.9% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 34.709 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 34.723 | 0.0% | No |
| 3 | **fs** | Forsort Stable In-Place | 36.517 | 5.2% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 59.471 | 71.3% | No |
| 5 | wi | WikiSort | 66.835 | 92.6% | Yes |
| 6 | ti | TimSort | 67.678 | 95.0% | Yes |
| 7 | gs | Grail Sort In-Place | 72.284 | 108.3% | Yes |
| 8 | gq | GLibc Quick Sort | 81.293 | 134.2% | No |
| 9 | fb | Forsort Basic In-Place | 82.765 | 138.5% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 20.154 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 20.247 | 0.5% | No |
| 3 | **fs** | Forsort Stable In-Place | 20.454 | 1.5% | Yes |
| 4 | ti | TimSort | 25.171 | 24.9% | Yes |
| 5 | fb | Forsort Basic In-Place | 32.916 | 63.3% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 33.121 | 64.3% | No |
| 7 | wi | WikiSort | 40.751 | 102.2% | Yes |
| 8 | gq | GLibc Quick Sort | 50.214 | 149.2% | No |
| 9 | gs | Grail Sort In-Place | 53.703 | 166.5% | Yes |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | Forsort Basic In-Place | 0.779 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.786 | 0.9% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 0.979 | 25.7% | Yes |
| 4 | fi | Forsort Unstable In-Place | 1.449 | 86.0% | No |
| 5 | fw | Forsort With Workspace | 2.091 | 168.4% | Yes |
| 6 | wi | WikiSort | 2.408 | 209.1% | Yes |
| 7 | gs | Grail Sort In-Place | 23.439 | 2908.9% | Yes |
| 8 | gq | GLibc Quick Sort | 24.553 | 3051.9% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 25.899 | 3224.6% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.779 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.781 | 0.3% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 0.977 | 25.4% | Yes |
| 4 | fi | Forsort Unstable In-Place | 1.438 | 84.6% | No |
| 5 | fw | Forsort With Workspace | 2.089 | 168.2% | Yes |
| 6 | wi | WikiSort | 2.352 | 201.9% | Yes |
| 7 | gs | Grail Sort In-Place | 22.029 | 2727.9% | Yes |
| 8 | gq | GLibc Quick Sort | 24.302 | 3019.6% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 24.354 | 3026.3% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 36.371 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 39.539 | 8.7% | No |
| 3 | **fs** | Forsort Stable In-Place | 42.954 | 18.1% | Yes |
| 4 | gs | Grail Sort In-Place | 90.826 | 149.7% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 96.011 | 164.0% | No |
| 6 | wi | WikiSort | 105.96 | 191.3% | Yes |
| 7 | ti | TimSort | 120.80 | 232.1% | Yes |
| 8 | gq | GLibc Quick Sort | 126.48 | 247.8% | No |
| 9 | fb | Forsort Basic In-Place | 145.15 | 299.1% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 36.743 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 38.795 | 5.6% | No |
| 3 | **fs** | Forsort Stable In-Place | 42.881 | 16.7% | Yes |
| 4 | gs | Grail Sort In-Place | 91.126 | 148.0% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 97.539 | 165.5% | No |
| 6 | wi | WikiSort | 105.86 | 188.1% | Yes |
| 7 | ti | TimSort | 120.87 | 229.0% | Yes |
| 8 | gq | GLibc Quick Sort | 126.48 | 244.2% | No |
| 9 | fb | Forsort Basic In-Place | 144.44 | 293.1% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 15.239 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 20.715 | 35.9% | Yes |
| 3 | **gs** | Grail Sort In-Place | 27.015 | 77.3% | Yes |
| 4 | fw | Forsort With Workspace | 30.515 | 100.2% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 30.893 | 102.7% | No |
| 6 | fi | Forsort Unstable In-Place | 34.835 | 128.6% | No |
| 7 | fs | Forsort Stable In-Place | 35.722 | 134.4% | Yes |
| 8 | gq | GLibc Quick Sort | 51.063 | 235.1% | No |
| 9 | fb | Forsort Basic In-Place | 52.167 | 242.3% | Yes |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.049 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 1.243 | 18.5% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.563 | 49.0% | Yes |
| 4 | wi | WikiSort | 12.426 | 1084.6% | Yes |
| 5 | gs | Grail Sort In-Place | 23.075 | 2099.7% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 29.539 | 2715.9% | No |
| 7 | fw | Forsort With Workspace | 29.882 | 2748.6% | Yes |
| 8 | gq | GLibc Quick Sort | 31.527 | 2905.4% | No |
| 9 | fi | Forsort Unstable In-Place | 34.549 | 3193.5% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Forsort Stable In-Place) - Average: 22.073 ns/item


## Detailed Results by Dataset Size

### 100 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000000469** | 216 | **4.693** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000000514** | 220 | **5.135** | Yes | 2 |
| wi | WikiSort | **0.000000554** | 307 | **5.541** | Yes | 3 |
| fb | Forsort Basic In-Place | 0.000000572 | 278 | 5.722 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.000000653 | 307 | 6.525 | Yes | 5 |
| ti | TimSort | 0.000000687 | 302 | 6.869 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.000000843 | 537 | 8.425 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000000949 | 428 | 9.493 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000001042 | 341 | 10.415 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fi | Forsort Unstable In-Place | **0.000000205** | 127 | **2.050** | Yes | 1 |
| fw | Forsort With Workspace | **0.000000217** | 133 | **2.166** | Yes | 2 |
| fb | Forsort Basic In-Place | **0.000000224** | 184 | **2.242** | Yes | 3 |
| ti | TimSort | 0.000000231 | 151 | 2.315 | Yes | 4 |
| wi | WikiSort | 0.000000257 | 233 | 2.573 | Yes | 5 |
| fs | Forsort Stable In-Place | 0.000000261 | 205 | 2.607 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.000000621 | 523 | 6.209 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000000643 | 386 | 6.429 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000000716 | 317 | 7.165 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000000995** | 423 | **9.949** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000001093** | 441 | **10.926** | Yes | 2 |
| wi | WikiSort | **0.000001133** | 483 | **11.332** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000001316 | 568 | 13.156 | Yes | 4 |
| ti | TimSort | 0.000001388 | 399 | 13.880 | Yes | 5 |
| fs | Forsort Stable In-Place | 0.000001444 | 554 | 14.442 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.000001540 | 508 | 15.405 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000001626 | 538 | 16.261 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000001820 | 421 | 18.197 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000000310** | 163 | **3.100** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000000318** | 159 | **3.181** | Yes | 2 |
| fb | Forsort Basic In-Place | **0.000000345** | 217 | **3.447** | Yes | 3 |
| wi | WikiSort | 0.000000368 | 258 | 3.681 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.000000403 | 241 | 4.026 | Yes | 5 |
| ti | TimSort | 0.000000492 | 248 | 4.917 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.000000717 | 531 | 7.166 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000000761 | 400 | 7.611 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000000828 | 325 | 8.278 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000000096** | 99 | **0.956** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000000112** | 99 | **1.121** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000000115** | 99 | **1.145** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.000000185 | 121 | 1.846 | Yes | 4 |
| fw | Forsort With Workspace | 0.000000202 | 128 | 2.019 | Yes | 5 |
| wi | WikiSort | 0.000000229 | 228 | 2.289 | Yes | 6 |
| gq | GLibc Quick Sort | 0.000000684 | 316 | 6.839 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.000000737 | 487 | 7.368 | No | 8 |
| gs | Grail Sort In-Place | 0.000001167 | 495 | 11.666 | Yes | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000000097** | 99 | **0.968** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000000111** | 99 | **1.111** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000000114** | 99 | **1.140** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.000000184 | 121 | 1.842 | Yes | 4 |
| fw | Forsort With Workspace | 0.000000205 | 128 | 2.045 | Yes | 5 |
| wi | WikiSort | 0.000000229 | 228 | 2.294 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.000000596 | 521 | 5.956 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000000597 | 384 | 5.973 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000000676 | 316 | 6.756 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000001549** | 670 | **15.489** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000001784** | 701 | **17.836** | Yes | 2 |
| wi | WikiSort | **0.000002180** | 618 | **21.796** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000002322 | 581 | 23.218 | No | 4 |
| fs | Forsort Stable In-Place | 0.000002367 | 861 | 23.666 | Yes | 5 |
| ti | TimSort | 0.000002765 | 536 | 27.646 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.000002960 | 911 | 29.599 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000003273 | 540 | 32.727 | Yes | 8 |
| gs | Grail Sort In-Place | 0.000003273 | 762 | 32.730 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000001538** | 670 | **15.378** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000001809** | 704 | **18.095** | Yes | 2 |
| wi | WikiSort | **0.000002138** | 617 | **21.381** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000002320 | 868 | 23.197 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000002439 | 645 | 24.393 | Yes | 5 |
| ti | TimSort | 0.000002759 | 537 | 27.590 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.000002918 | 917 | 29.182 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000003062 | 737 | 30.619 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000003241 | 540 | 32.406 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| wi | WikiSort | **0.000000719** | 365 | **7.191** | Yes | 1 |
| fw | Forsort With Workspace | **0.000000736** | 431 | **7.357** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000000911** | 492 | **9.109** | No | 3 |
| ti | TimSort | 0.000000914 | 419 | 9.142 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000001159 | 780 | 11.588 | No | 5 |
| gs | Grail Sort In-Place | 0.000001490 | 520 | 14.900 | Yes | 6 |
| fs | Forsort Stable In-Place | 0.000001500 | 683 | 15.003 | Yes | 7 |
| fb | Forsort Basic In-Place | 0.000001745 | 786 | 17.450 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000002042 | 369 | 20.421 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000000109** | 99 | **1.091** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000000115** | 99 | **1.154** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000000127** | 100 | **1.275** | Yes | 3 |
| wi | WikiSort | 0.000000305 | 271 | 3.054 | Yes | 4 |
| fw | Forsort With Workspace | 0.000000601 | 421 | 6.006 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000000650 | 400 | 6.503 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.000000740 | 498 | 7.404 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000000944 | 356 | 9.440 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000001140 | 953 | 11.398 | Yes | 9 |

### 1000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000010864** | 4437 | **10.864** | Yes | 1 |
| wi | WikiSort | **0.000011451** | 7000 | **11.451** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000012106** | 5039 | **12.106** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.000012593 | 4835 | 12.593 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000012736 | 8522 | 12.736 | Yes | 5 |
| ti | TimSort | 0.000013164 | 4668 | 13.164 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000015230 | 6633 | 15.230 | Yes | 7 |
| fb | Forsort Basic In-Place | 0.000015316 | 5767 | 15.316 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000019215 | 6438 | 19.215 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000002018** | 1255 | **2.018** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000002295** | 1344 | **2.295** | Yes | 2 |
| fb | Forsort Basic In-Place | **0.000002969** | 2203 | **2.969** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000003027 | 2189 | 3.027 | Yes | 4 |
| wi | WikiSort | 0.000003286 | 2798 | 3.286 | Yes | 5 |
| ti | TimSort | 0.000003637 | 2045 | 3.637 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000008365 | 4877 | 8.365 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.000009394 | 8249 | 9.394 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000010882 | 4983 | 10.882 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000017021** | 7393 | **17.021** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000018793** | 7689 | **18.793** | Yes | 2 |
| wi | WikiSort | **0.000018970** | 8748 | **18.970** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000020753 | 9187 | 20.753 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.000021382 | 8173 | 21.382 | Yes | 5 |
| ti | TimSort | 0.000025013 | 7036 | 25.013 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000026170 | 9002 | 26.170 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000029905 | 7947 | 29.905 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000030225 | 9141 | 30.225 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000006433** | 2843 | **6.433** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.000007361** | 3431 | **7.361** | Yes | 2 |
| wi | WikiSort | **0.000007542** | 5002 | **7.542** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.000007653 | 3137 | 7.653 | Yes | 4 |
| ti | TimSort | 0.000008470 | 3567 | 8.470 | Yes | 5 |
| fb | Forsort Basic In-Place | 0.000008947 | 4094 | 8.947 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.000010844 | 8358 | 10.844 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000011291 | 5504 | 11.291 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000015275 | 5560 | 15.275 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000000811** | 999 | **0.811** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.000000989** | 999 | **0.989** | Yes | 2 |
| fb | Forsort Basic In-Place | **0.000000990** | 999 | **0.990** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.000001185 | 1052 | 1.185 | Yes | 4 |
| fw | Forsort With Workspace | 0.000001188 | 1028 | 1.188 | Yes | 5 |
| wi | WikiSort | 0.000002524 | 2530 | 2.524 | Yes | 6 |
| gq | GLibc Quick Sort | 0.000010001 | 4932 | 10.001 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.000010348 | 7953 | 10.348 | No | 8 |
| gs | Grail Sort In-Place | 0.000010368 | 5216 | 10.368 | Yes | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000000811** | 999 | **0.811** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000000985** | 999 | **0.985** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000000989** | 999 | **0.989** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.000001173 | 1052 | 1.173 | Yes | 4 |
| fw | Forsort With Workspace | 0.000001208 | 1028 | 1.208 | Yes | 5 |
| wi | WikiSort | 0.000002525 | 2530 | 2.525 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000007646 | 4790 | 7.646 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.000008835 | 8192 | 8.835 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000009774 | 4932 | 9.774 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000016631** | 9578 | **16.631** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000020888** | 10215 | **20.888** | No | 2 |
| fs | Forsort Stable In-Place | **0.000024025** | 10478 | **24.025** | Yes | 3 |
| wi | WikiSort | 0.000032643 | 9514 | 32.643 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000035583 | 9401 | 35.583 | No | 5 |
| gs | Grail Sort In-Place | 0.000038820 | 10536 | 38.820 | Yes | 6 |
| ti | TimSort | 0.000043660 | 8680 | 43.660 | Yes | 7 |
| fb | Forsort Basic In-Place | 0.000048257 | 15097 | 48.257 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000048904 | 8703 | 48.904 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000016602** | 9575 | **16.602** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000020562** | 10218 | **20.562** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000024163** | 10464 | **24.163** | Yes | 3 |
| wi | WikiSort | 0.000032367 | 9510 | 32.367 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000036978 | 10086 | 36.978 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000038577 | 10506 | 38.577 | Yes | 6 |
| ti | TimSort | 0.000043338 | 8680 | 43.338 | Yes | 7 |
| fb | Forsort Basic In-Place | 0.000048283 | 15120 | 48.283 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000049050 | 8703 | 49.050 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| wi | WikiSort | **0.000007691** | 4601 | **7.691** | Yes | 1 |
| fw | Forsort With Workspace | **0.000008402** | 6564 | **8.402** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000009371** | 6498 | **9.371** | No | 3 |
| ti | TimSort | 0.000009510 | 4456 | 9.510 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.000010409 | 5887 | 10.409 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000013423 | 5699 | 13.423 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.000016360 | 12038 | 16.360 | No | 7 |
| fb | Forsort Basic In-Place | 0.000019809 | 8563 | 19.809 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000024575 | 5237 | 24.575 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000000944** | 999 | **0.944** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000001010** | 999 | **1.010** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000001052** | 1000 | **1.052** | Yes | 3 |
| wi | WikiSort | 0.000003480 | 3287 | 3.480 | Yes | 4 |
| fw | Forsort With Workspace | 0.000007235 | 6614 | 7.235 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.000007527 | 6407 | 7.527 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000008050 | 5112 | 8.050 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000011696 | 5044 | 11.696 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000017208 | 14222 | 17.208 | Yes | 9 |

### 10000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000155857** | 65571 | **15.586** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.000172210** | 67719 | **17.221** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000172300** | 69598 | **17.230** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000183623 | 119573 | 18.362 | Yes | 4 |
| wi | WikiSort | 0.000195807 | 110229 | 19.581 | Yes | 5 |
| ti | TimSort | 0.000196535 | 56009 | 19.654 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.000233492 | 79243 | 23.349 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000235489 | 106235 | 23.549 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000272518 | 102550 | 27.252 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000041786** | 20648 | **4.179** | Yes | 1 |
| ti | TimSort | **0.000044965** | 20071 | **4.497** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000047455** | 22034 | **4.746** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000049743 | 24635 | 4.974 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.000058360 | 32458 | 5.836 | Yes | 5 |
| wi | WikiSort | 0.000066698 | 45926 | 6.670 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000110924 | 61178 | 11.092 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.000123198 | 112921 | 12.320 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000144149 | 69193 | 14.415 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000210256** | 100883 | **21.026** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000225111** | 104342 | **22.511** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000239130** | 105423 | **23.913** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000286002 | 127121 | 28.600 | Yes | 4 |
| wi | WikiSort | 0.000306541 | 131333 | 30.654 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000342901 | 126395 | 34.290 | Yes | 6 |
| ti | TimSort | 0.000354314 | 93937 | 35.431 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000405530 | 115311 | 40.553 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000424765 | 124783 | 42.476 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000114720** | 46482 | **11.472** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000129271** | 50062 | **12.927** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000130684** | 50986 | **13.068** | Yes | 3 |
| ti | TimSort | 0.000132035 | 41460 | 13.203 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000150647 | 116696 | 15.065 | Yes | 5 |
| wi | WikiSort | 0.000151362 | 95320 | 15.136 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.000160377 | 60799 | 16.038 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000183335 | 90191 | 18.334 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000225103 | 92078 | 22.510 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000007833** | 9999 | **0.783** | Yes | 1 |
| fw | Forsort With Workspace | **0.000008771** | 10049 | **0.877** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000009423** | 10091 | **0.942** | Yes | 3 |
| fb | Forsort Basic In-Place | 0.000009554 | 9999 | 0.955 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.000010222 | 9999 | 1.022 | Yes | 5 |
| wi | WikiSort | 0.000028763 | 23734 | 2.876 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000110422 | 55104 | 11.042 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000117867 | 64608 | 11.787 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000126602 | 109630 | 12.660 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000007841** | 9999 | **0.784** | Yes | 1 |
| fw | Forsort With Workspace | **0.000008867** | 10049 | **0.887** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000009221** | 10091 | **0.922** | Yes | 3 |
| fb | Forsort Basic In-Place | 0.000009577 | 9999 | 0.958 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.000010547 | 9999 | 1.055 | Yes | 5 |
| wi | WikiSort | 0.000025732 | 23662 | 2.573 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000090952 | 53332 | 9.095 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.000115123 | 111539 | 11.512 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000117304 | 64608 | 11.730 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000186116** | 126146 | **18.612** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000230656** | 133040 | **23.066** | No | 2 |
| fs | Forsort Stable In-Place | **0.000240303** | 133561 | **24.030** | Yes | 3 |
| gs | Grail Sort In-Place | 0.000475495 | 138673 | 47.549 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000480736 | 130139 | 48.074 | No | 5 |
| wi | WikiSort | 0.000496094 | 143379 | 49.609 | Yes | 6 |
| ti | TimSort | 0.000595574 | 120355 | 59.557 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000661818 | 120412 | 66.182 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000683405 | 208377 | 68.341 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000185369** | 126139 | **18.537** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000225210** | 133079 | **22.521** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000241629** | 133577 | **24.163** | Yes | 3 |
| gs | Grail Sort In-Place | 0.000473353 | 138631 | 47.335 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000495200 | 137010 | 49.520 | Yes | 5 |
| wi | WikiSort | 0.000504267 | 143338 | 50.427 | Yes | 6 |
| ti | TimSort | 0.000593937 | 120355 | 59.394 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000657852 | 120413 | 65.785 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000681193 | 208540 | 68.119 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000094551** | 39936 | **9.455** | Yes | 1 |
| wi | WikiSort | **0.000098558** | 44661 | **9.856** | Yes | 2 |
| fw | Forsort With Workspace | **0.000113904** | 97316 | **11.390** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.000120087 | 93307 | 12.009 | No | 4 |
| fs | Forsort Stable In-Place | 0.000120905 | 82496 | 12.090 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000141975 | 60795 | 14.197 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.000211757 | 166727 | 21.176 | No | 7 |
| fb | Forsort Basic In-Place | 0.000216803 | 86922 | 21.680 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000313743 | 70411 | 31.374 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000009124** | 9999 | **0.912** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000010049** | 9999 | **1.005** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000010504** | 10000 | **1.050** | Yes | 3 |
| wi | WikiSort | 0.000043720 | 25008 | 4.372 | Yes | 4 |
| gs | Grail Sort In-Place | 0.000095916 | 57076 | 9.592 | Yes | 5 |
| fw | Forsort With Workspace | 0.000103873 | 98010 | 10.387 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.000105582 | 93366 | 10.558 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000144546 | 69008 | 14.455 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000226897 | 192779 | 22.690 | Yes | 9 |

### 100000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.001816685** | 793749 | **18.167** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.001905474** | 837036 | **19.055** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.001944478** | 807831 | **19.445** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.002344976 | 1538403 | 23.450 | No | 4 |
| ti | TimSort | 0.002374684 | 678056 | 23.747 | Yes | 5 |
| wi | WikiSort | 0.002582320 | 1482384 | 25.823 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.002906200 | 949064 | 29.062 | Yes | 7 |
| gs | Grail Sort In-Place | 0.003089326 | 1432950 | 30.893 | Yes | 8 |
| gq | GLibc Quick Sort | 0.003286674 | 1388160 | 32.867 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000648461** | 255902 | **6.485** | Yes | 1 |
| fw | Forsort With Workspace | **0.000694861** | 295437 | **6.949** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000749001** | 311096 | **7.490** | No | 3 |
| fs | Forsort Stable In-Place | 0.000758637 | 321267 | 7.586 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.000931675 | 434213 | 9.317 | Yes | 5 |
| wi | WikiSort | 0.001301926 | 949669 | 13.019 | Yes | 6 |
| gs | Grail Sort In-Place | 0.001526948 | 912889 | 15.269 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.001649522 | 1515714 | 16.495 | No | 8 |
| gq | GLibc Quick Sort | 0.002057382 | 1052796 | 20.574 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.002404315** | 1237303 | **24.043** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.002515207** | 1269654 | **25.152** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.002657135** | 1267518 | **26.571** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.003575022 | 1622459 | 35.750 | No | 4 |
| wi | WikiSort | 0.003894915 | 1718062 | 38.949 | Yes | 5 |
| gs | Grail Sort In-Place | 0.004255528 | 1631693 | 42.555 | Yes | 6 |
| ti | TimSort | 0.004325407 | 1094094 | 43.254 | Yes | 7 |
| gq | GLibc Quick Sort | 0.004823010 | 1507230 | 48.230 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.005274987 | 1537065 | 52.750 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.001388979** | 611734 | **13.890** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.001484245** | 599707 | **14.842** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.001504298** | 643597 | **15.043** | Yes | 3 |
| ti | TimSort | 0.001676379 | 521641 | 16.764 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.001984526 | 1517041 | 19.845 | Yes | 5 |
| fb | Forsort Basic In-Place | 0.002045208 | 734993 | 20.452 | Yes | 6 |
| wi | WikiSort | 0.002049715 | 1317947 | 20.497 | Yes | 7 |
| gs | Grail Sort In-Place | 0.002545523 | 1279989 | 25.455 | Yes | 8 |
| gq | GLibc Quick Sort | 0.002767936 | 1297211 | 27.679 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000077953** | 99999 | **0.780** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000084699** | 99999 | **0.847** | Yes | 2 |
| fw | Forsort With Workspace | **0.000100856** | 100078 | **1.009** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000101232 | 99999 | 1.012 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.000103511 | 100167 | 1.035 | Yes | 5 |
| wi | WikiSort | 0.000261245 | 240807 | 2.612 | Yes | 6 |
| gs | Grail Sort In-Place | 0.001164776 | 616160 | 11.648 | Yes | 7 |
| gq | GLibc Quick Sort | 0.001411216 | 815024 | 14.112 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.001735836 | 1479362 | 17.358 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000077954** | 99999 | **0.780** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000084353** | 99999 | **0.844** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000100858** | 99999 | **1.009** | Yes | 3 |
| fw | Forsort With Workspace | 0.000101872 | 100078 | 1.019 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.000102724 | 100167 | 1.027 | Yes | 5 |
| wi | WikiSort | 0.000247753 | 240530 | 2.478 | Yes | 6 |
| gs | Grail Sort In-Place | 0.001049158 | 608786 | 10.492 | Yes | 7 |
| gq | GLibc Quick Sort | 0.001399810 | 815024 | 13.998 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.001572423 | 1524583 | 15.724 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.002275391** | 1621745 | **22.754** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.002686138** | 1649127 | **26.861** | No | 2 |
| fs | Forsort Stable In-Place | **0.002733936** | 1701468 | **27.339** | Yes | 3 |
| gs | Grail Sort In-Place | 0.005573111 | 1692386 | 55.731 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.006020293 | 1662949 | 60.203 | No | 5 |
| wi | WikiSort | 0.006169071 | 1828880 | 61.691 | Yes | 6 |
| ti | TimSort | 0.007389480 | 1531061 | 73.895 | Yes | 7 |
| gq | GLibc Quick Sort | 0.007764917 | 1536077 | 77.649 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.008675062 | 2641976 | 86.751 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.002263828** | 1621738 | **22.638** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.002635391** | 1649581 | **26.354** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.002749416** | 1701948 | **27.494** | Yes | 3 |
| gs | Grail Sort In-Place | 0.005602926 | 1692301 | 56.029 | Yes | 4 |
| wi | WikiSort | 0.006179556 | 1828538 | 61.796 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.006280172 | 1731551 | 62.802 | Yes | 6 |
| ti | TimSort | 0.007358736 | 1531056 | 73.587 | Yes | 7 |
| gq | GLibc Quick Sort | 0.007704821 | 1536078 | 77.048 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.008644037 | 2643487 | 86.440 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000984447** | 423415 | **9.844** | Yes | 1 |
| wi | WikiSort | **0.001112041** | 566101 | **11.120** | Yes | 2 |
| fw | Forsort With Workspace | **0.001433803** | 1228341 | **14.338** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.001441562 | 1049640 | 14.416 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.001488862 | 1195727 | 14.889 | No | 5 |
| gs | Grail Sort In-Place | 0.001493470 | 653668 | 14.935 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.002197593 | 1775188 | 21.976 | No | 7 |
| fb | Forsort Basic In-Place | 0.002406017 | 874231 | 24.060 | Yes | 8 |
| gq | GLibc Quick Sort | 0.003578501 | 866157 | 35.785 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000091168** | 99999 | **0.912** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000100395** | 99999 | **1.004** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000107982** | 100000 | **1.080** | Yes | 3 |
| wi | WikiSort | 0.000496285 | 284046 | 4.963 | Yes | 4 |
| gs | Grail Sort In-Place | 0.001083626 | 627299 | 10.836 | Yes | 5 |
| fw | Forsort With Workspace | 0.001333919 | 1235508 | 13.339 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.001401102 | 1201428 | 14.011 | Yes | 7 |
| gq | GLibc Quick Sort | 0.001688972 | 853904 | 16.890 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.002150543 | 1935567 | 21.505 | Yes | 9 |

### 1000000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.019698479** | 9378924 | **19.698** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.020578511** | 9541928 | **20.579** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.020716003** | 10065778 | **20.716** | No | 3 |
| ti | TimSort | 0.027191809 | 7732303 | 27.192 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.028810087 | 18775467 | 28.810 | No | 5 |
| wi | WikiSort | 0.031844838 | 18763260 | 31.845 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.034082155 | 10738576 | 34.082 | Yes | 7 |
| gq | GLibc Quick Sort | 0.039627400 | 17423146 | 39.627 | Yes | 8 |
| gs | Grail Sort In-Place | 0.040115133 | 18053251 | 40.115 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.008072682** | 3357950 | **8.073** | Yes | 1 |
| ti | TimSort | **0.008394720** | 3178195 | **8.395** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.008434815** | 3657414 | **8.435** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.008570963 | 3573302 | 8.571 | No | 4 |
| fb | Forsort Basic In-Place | 0.011408338 | 4900264 | 11.408 | Yes | 5 |
| wi | WikiSort | 0.017614399 | 13258878 | 17.614 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.019902833 | 18248831 | 19.903 | No | 7 |
| gs | Grail Sort In-Place | 0.023966636 | 13140021 | 23.967 | Yes | 8 |
| gq | GLibc Quick Sort | 0.026517172 | 14445922 | 26.517 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.026654705** | 14555244 | **26.655** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.027530218** | 15101046 | **27.530** | No | 2 |
| fs | Forsort Stable In-Place | **0.028617394** | 14974934 | **28.617** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.043490167 | 19736742 | 43.490 | No | 4 |
| wi | WikiSort | 0.046185754 | 21147526 | 46.186 | Yes | 5 |
| ti | TimSort | 0.049896078 | 12452404 | 49.896 | Yes | 6 |
| gs | Grail Sort In-Place | 0.051334339 | 19799007 | 51.334 | Yes | 7 |
| gq | GLibc Quick Sort | 0.057109877 | 18497076 | 57.110 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.062487535 | 17999029 | 62.488 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.015109975** | 7222086 | **15.110** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.016108292** | 7266949 | **16.108** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.016135962** | 7721818 | **16.136** | No | 3 |
| ti | TimSort | 0.019327118 | 6045830 | 19.327 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.024226217 | 8208369 | 24.226 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.024365094 | 18502647 | 24.365 | No | 6 |
| wi | WikiSort | 0.026085992 | 17098887 | 26.086 | Yes | 7 |
| gq | GLibc Quick Sort | 0.034020901 | 16566799 | 34.021 | Yes | 8 |
| gs | Grail Sort In-Place | 0.034217821 | 16616985 | 34.218 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | Forsort Basic In-Place | **0.000820374** | 999999 | **0.820** | Yes | 1 |
| ti | TimSort | **0.000858633** | 999999 | **0.859** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.001002224** | 1000212 | **1.002** | Yes | 3 |
| fw | Forsort With Workspace | 0.001150323 | 1000058 | 1.150 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.001280616 | 999999 | 1.281 | Yes | 5 |
| wi | WikiSort | 0.002597524 | 2596568 | 2.598 | Yes | 6 |
| gs | Grail Sort In-Place | 0.013587047 | 7043638 | 13.587 | Yes | 7 |
| gq | GLibc Quick Sort | 0.017024306 | 9884992 | 17.024 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.019964787 | 17946371 | 19.965 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | Forsort Basic In-Place | **0.000797911** | 999999 | **0.798** | Yes | 1 |
| ti | TimSort | **0.000871579** | 999999 | **0.872** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.001052572** | 1000212 | **1.053** | Yes | 3 |
| fw | Forsort With Workspace | 0.001207818 | 1000058 | 1.208 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.001223726 | 999999 | 1.224 | Yes | 5 |
| wi | WikiSort | 0.002522135 | 2595342 | 2.522 | Yes | 6 |
| gs | Grail Sort In-Place | 0.012655084 | 7019410 | 12.655 | Yes | 7 |
| gq | GLibc Quick Sort | 0.017071108 | 9884992 | 17.071 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.018342271 | 18196618 | 18.342 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.025572410** | 19344422 | **25.572** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.029679770** | 20001796 | **29.680** | No | 2 |
| fs | Forsort Stable In-Place | **0.030075844** | 20136371 | **30.076** | Yes | 3 |
| gs | Grail Sort In-Place | 0.064534789 | 20161896 | 64.535 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.072170096 | 20248052 | 72.170 | No | 5 |
| wi | WikiSort | 0.074019551 | 22373109 | 74.020 | Yes | 6 |
| ti | TimSort | 0.088416864 | 18299313 | 88.417 | Yes | 7 |
| gq | GLibc Quick Sort | 0.092033346 | 18672444 | 92.033 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.105606553 | 31919058 | 105.61 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.025573507** | 19344479 | **25.574** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.029638829** | 20006156 | **29.639** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.030369652** | 20144103 | **30.370** | Yes | 3 |
| gs | Grail Sort In-Place | 0.064750992 | 20161732 | 64.751 | Yes | 4 |
| wi | WikiSort | 0.073921943 | 22370329 | 73.922 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.075762827 | 20933577 | 75.763 | Yes | 6 |
| ti | TimSort | 0.088008684 | 18299330 | 88.009 | Yes | 7 |
| gq | GLibc Quick Sort | 0.092044251 | 18672447 | 92.044 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.106642240 | 31934009 | 106.64 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.010354397** | 4402855 | **10.354** | Yes | 1 |
| wi | WikiSort | **0.012177034** | 6209983 | **12.177** | Yes | 2 |
| gs | Grail Sort In-Place | **0.017216661** | 7770797 | **17.217** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.018389582 | 13911761 | 18.390 | Yes | 4 |
| fw | Forsort With Workspace | 0.018797374 | 16348376 | 18.797 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.019247726 | 15717539 | 19.248 | No | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.026113218 | 21892721 | 26.113 | No | 7 |
| fb | Forsort Basic In-Place | 0.027984389 | 8712709 | 27.984 | Yes | 8 |
| gq | GLibc Quick Sort | 0.036818671 | 10249883 | 36.819 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000974607** | 999999 | **0.975** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.001085835** | 999999 | **1.086** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.001190268** | 1000000 | **1.190** | Yes | 3 |
| wi | WikiSort | 0.006066638 | 3273489 | 6.067 | Yes | 4 |
| gs | Grail Sort In-Place | 0.013611928 | 7551070 | 13.612 | Yes | 5 |
| fw | Forsort With Workspace | 0.017741652 | 16420327 | 17.742 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.018267281 | 15784214 | 18.267 | Yes | 7 |
| gq | GLibc Quick Sort | 0.019753742 | 10066432 | 19.754 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.025923802 | 24025703 | 25.924 | Yes | 9 |

### 10000000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.211835240** | 108139592 | **21.184** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.222585310** | 111449499 | **22.259** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.226676040** | 115607902 | **22.668** | No | 3 |
| ti | TimSort | 0.315855427 | 80928004 | 31.586 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.337269127 | 221677473 | 33.727 | No | 5 |
| fb | Forsort Basic In-Place | 0.392704931 | 118999726 | 39.270 | Yes | 6 |
| wi | WikiSort | 0.397058089 | 222817587 | 39.706 | Yes | 7 |
| gq | GLibc Quick Sort | 0.476838092 | 207993459 | 47.684 | Yes | 8 |
| gs | Grail Sort In-Place | 0.491576969 | 215578040 | 49.158 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.090181121** | 29068713 | **9.018** | Yes | 1 |
| fw | Forsort With Workspace | **0.091574746** | 42843128 | **9.157** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.094448164** | 45667525 | **9.445** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.096046686 | 44731852 | 9.605 | No | 4 |
| fb | Forsort Basic In-Place | 0.132114694 | 52343121 | 13.211 | Yes | 5 |
| wi | WikiSort | 0.227603695 | 161705758 | 22.760 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.231958401 | 215103561 | 23.196 | No | 7 |
| gs | Grail Sort In-Place | 0.322492237 | 166968080 | 32.249 | Yes | 8 |
| gq | GLibc Quick Sort | 0.326449408 | 178599120 | 32.645 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.289650759** | 166154364 | **28.965** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.306115358** | 174377834 | **30.612** | No | 2 |
| fs | Forsort Stable In-Place | **0.312089405** | 171178816 | **31.209** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.517661822 | 232475000 | 51.766 | No | 4 |
| wi | WikiSort | 0.566206342 | 249329223 | 56.621 | Yes | 5 |
| ti | TimSort | 0.581513585 | 139292911 | 58.151 | Yes | 6 |
| gs | Grail Sort In-Place | 0.611361550 | 232273450 | 61.136 | Yes | 7 |
| gq | GLibc Quick Sort | 0.687791753 | 218009189 | 68.779 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.716713027 | 205431767 | 71.671 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.164058485** | 83680121 | **16.406** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.174537857** | 88578515 | **17.454** | No | 2 |
| fs | Forsort Stable In-Place | **0.175042948** | 86680228 | **17.504** | Yes | 3 |
| ti | TimSort | 0.221538150 | 59831650 | 22.154 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.278419105 | 89622464 | 27.842 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.286608880 | 218628214 | 28.661 | No | 6 |
| wi | WikiSort | 0.325380705 | 204422432 | 32.538 | Yes | 7 |
| gq | GLibc Quick Sort | 0.409406068 | 199431840 | 40.941 | Yes | 8 |
| gs | Grail Sort In-Place | 0.427336812 | 201520459 | 42.734 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | Forsort Basic In-Place | **0.007894617** | 9999999 | **0.789** | Yes | 1 |
| ti | TimSort | **0.008033618** | 9999999 | **0.803** | Yes | 2 |
| fw | Forsort With Workspace | **0.009001714** | 10000089 | **0.900** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.009207166 | 10000304 | 0.921 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.010749609 | 9999999 | 1.075 | Yes | 5 |
| wi | WikiSort | 0.021049049 | 20127951 | 2.105 | Yes | 6 |
| gs | Grail Sort In-Place | 0.176131196 | 79282122 | 17.613 | Yes | 7 |
| gq | GLibc Quick Sort | 0.199760619 | 114434624 | 19.976 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.218132983 | 209616775 | 21.813 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | Forsort Basic In-Place | **0.007868135** | 9999999 | **0.787** | Yes | 1 |
| ti | TimSort | **0.008063892** | 9999999 | **0.806** | Yes | 2 |
| fw | Forsort With Workspace | **0.008970023** | 10000089 | **0.897** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.009332893 | 10000304 | 0.933 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.010986445 | 9999999 | 1.099 | Yes | 5 |
| wi | WikiSort | 0.020458122 | 20122509 | 2.046 | Yes | 6 |
| gs | Grail Sort In-Place | 0.164569559 | 79189929 | 16.457 | Yes | 7 |
| gq | GLibc Quick Sort | 0.199162494 | 114434624 | 19.916 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.207891698 | 211572877 | 20.789 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.288398120** | 225429282 | **28.840** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.336820227** | 232277927 | **33.682** | No | 2 |
| fs | Forsort Stable In-Place | **0.346284278** | 235467153 | **34.628** | Yes | 3 |
| gs | Grail Sort In-Place | 0.771920506 | 236958729 | 77.192 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.840596393 | 238693529 | 84.060 | No | 5 |
| wi | WikiSort | 0.896799630 | 266876749 | 89.680 | Yes | 6 |
| ti | TimSort | 1.041898265 | 213810481 | 104.19 | Yes | 7 |
| gq | GLibc Quick Sort | 1.100080042 | 220067086 | 110.01 | Yes | 8 |
| fb | Forsort Basic In-Place | 1.238992225 | 373454731 | 123.90 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.292973793** | 225429372 | **29.297** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.328961965** | 232321285 | **32.896** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.339357691** | 235553287 | **33.936** | Yes | 3 |
| gs | Grail Sort In-Place | 0.771647522 | 236950641 | 77.165 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.856752420 | 245315299 | 85.675 | Yes | 5 |
| wi | WikiSort | 0.898357148 | 266850192 | 89.836 | Yes | 6 |
| ti | TimSort | 1.040929948 | 213810891 | 104.09 | Yes | 7 |
| gq | GLibc Quick Sort | 1.089863321 | 220067088 | 108.99 | Yes | 8 |
| fb | Forsort Basic In-Place | 1.249310631 | 373603375 | 124.93 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.119997190** | 39878073 | **12.000** | Yes | 1 |
| wi | WikiSort | **0.155193467** | 68335637 | **15.519** | Yes | 2 |
| gs | Grail Sort In-Place | **0.200201311** | 84028342 | **20.020** | Yes | 3 |
| fw | Forsort With Workspace | 0.226475340 | 197266387 | 22.648 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.243997157 | 177389805 | 24.400 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.247734907 | 190717940 | 24.773 | No | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.303046346 | 264937110 | 30.305 | No | 7 |
| fb | Forsort Basic In-Place | 0.323888187 | 87260864 | 32.389 | Yes | 8 |
| gq | GLibc Quick Sort | 0.427275000 | 120242804 | 42.728 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.009259713** | 9999999 | **0.926** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.010790373** | 9999999 | **1.079** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.012588707** | 10000000 | **1.259** | Yes | 3 |
| wi | WikiSort | 0.069698581 | 21498750 | 6.970 | Yes | 4 |
| gs | Grail Sort In-Place | 0.165875668 | 81979307 | 16.588 | Yes | 5 |
| fw | Forsort With Workspace | 0.215406247 | 197985849 | 21.541 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.238237926 | 191369358 | 23.824 | Yes | 7 |
| gq | GLibc Quick Sort | 0.247717121 | 118788160 | 24.772 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.308540456 | 290683459 | 30.854 | Yes | 9 |

### 100000000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **2.531935187** | 1190184624 | **25.319** | Yes | 1 |
| fi | Forsort Unstable In-Place | **2.585445550** | 1271725498 | **25.854** | No | 2 |
| fs | Forsort Stable In-Place | **2.627082525** | 1225568186 | **26.271** | Yes | 3 |
| ti | TimSort | 3.588771622 | 885291673 | 35.888 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 3.904855683 | 2556363738 | 39.049 | No | 5 |
| fb | Forsort Basic In-Place | 4.618859325 | 1303198586 | 46.189 | Yes | 6 |
| wi | WikiSort | 4.736079921 | 2589528798 | 47.361 | Yes | 7 |
| gq | GLibc Quick Sort | 5.754795770 | 2425087751 | 57.548 | Yes | 8 |
| gs | Grail Sort In-Place | 5.908475633 | 2494360434 | 59.085 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **1.061873514** | 324462522 | **10.619** | Yes | 1 |
| fi | Forsort Unstable In-Place | **1.236753990** | 550810957 | **12.368** | No | 2 |
| fs | Forsort Stable In-Place | **1.241641708** | 547281529 | **12.416** | Yes | 3 |
| fw | Forsort With Workspace | 1.284120934 | 515995914 | 12.841 | Yes | 4 |
| fb | Forsort Basic In-Place | 1.570276516 | 550843510 | 15.703 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 2.684890127 | 2503156427 | 26.849 | No | 6 |
| wi | WikiSort | 3.022518088 | 1989724997 | 30.225 | Yes | 7 |
| gq | GLibc Quick Sort | 4.023619051 | 2138224530 | 40.236 | Yes | 8 |
| gs | Grail Sort In-Place | 4.267317653 | 2022625207 | 42.673 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **3.470873062** | 1862655030 | **34.709** | Yes | 1 |
| fi | Forsort Unstable In-Place | **3.472264239** | 1935889512 | **34.723** | No | 2 |
| fs | Forsort Stable In-Place | **3.651749331** | 1924373356 | **36.517** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 5.947060581 | 2673076661 | 59.471 | No | 4 |
| wi | WikiSort | 6.683450755 | 2854508858 | 66.835 | Yes | 5 |
| ti | TimSort | 6.767810588 | 1534831256 | 67.678 | Yes | 6 |
| gs | Grail Sort In-Place | 7.228375593 | 2634592105 | 72.284 | Yes | 7 |
| gq | GLibc Quick Sort | 8.129268326 | 2514385833 | 81.293 | Yes | 8 |
| fb | Forsort Basic In-Place | 8.276504664 | 2304584977 | 82.765 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **2.015374169** | 925921638 | **20.154** | Yes | 1 |
| fi | Forsort Unstable In-Place | **2.024710767** | 982220304 | **20.247** | No | 2 |
| fs | Forsort Stable In-Place | **2.045359675** | 974526949 | **20.454** | Yes | 3 |
| ti | TimSort | 2.517123239 | 659636497 | 25.171 | Yes | 4 |
| fb | Forsort Basic In-Place | 3.291595306 | 967977143 | 32.916 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 3.312076567 | 2520956121 | 33.121 | No | 6 |
| wi | WikiSort | 4.075129133 | 2411276667 | 40.751 | Yes | 7 |
| gq | GLibc Quick Sort | 5.021389384 | 2341899008 | 50.214 | Yes | 8 |
| gs | Grail Sort In-Place | 5.370295094 | 2358494172 | 53.703 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | Forsort Basic In-Place | **0.077869679** | 99999999 | **0.779** | Yes | 1 |
| ti | TimSort | **0.078641650** | 99999999 | **0.786** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.097887432** | 99999999 | **0.979** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.144890388 | 100000429 | 1.449 | Yes | 4 |
| fw | Forsort With Workspace | 0.209108523 | 100000101 | 2.091 | Yes | 5 |
| wi | WikiSort | 0.240796517 | 223294351 | 2.408 | Yes | 6 |
| gs | Grail Sort In-Place | 2.343912596 | 840543505 | 23.439 | Yes | 7 |
| gq | GLibc Quick Sort | 2.455250146 | 1314447104 | 24.553 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 2.589856231 | 2472881797 | 25.899 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.077949925** | 99999999 | **0.779** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.078130504** | 99999999 | **0.781** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.097740164** | 99999999 | **0.977** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.143760811 | 100000429 | 1.438 | Yes | 4 |
| fw | Forsort With Workspace | 0.208876146 | 100000101 | 2.089 | Yes | 5 |
| wi | WikiSort | 0.235201034 | 223275953 | 2.352 | Yes | 6 |
| gs | Grail Sort In-Place | 2.202907273 | 840185031 | 22.029 | Yes | 7 |
| gq | GLibc Quick Sort | 2.430201390 | 1314447104 | 24.302 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 2.435381637 | 2525165841 | 24.354 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **3.637114604** | 2621029714 | **36.371** | Yes | 1 |
| fi | Forsort Unstable In-Place | **3.953861450** | 2634697879 | **39.539** | No | 2 |
| fs | Forsort Stable In-Place | **4.295422349** | 2742131801 | **42.954** | Yes | 3 |
| gs | Grail Sort In-Place | 9.082609428 | 2655245492 | 90.826 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 9.601068128 | 2749060430 | 96.011 | No | 5 |
| wi | WikiSort | 10.595747877 | 3064238700 | 105.96 | Yes | 6 |
| ti | TimSort | 12.079549531 | 2435412938 | 120.80 | Yes | 7 |
| gq | GLibc Quick Sort | 12.648123554 | 2532644916 | 126.48 | Yes | 8 |
| fb | Forsort Basic In-Place | 14.515427256 | 4273768630 | 145.15 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **3.674299737** | 2621029170 | **36.743** | Yes | 1 |
| fi | Forsort Unstable In-Place | **3.879495314** | 2635143637 | **38.795** | Yes | 2 |
| fs | Forsort Stable In-Place | **4.288078986** | 2743841495 | **42.881** | Yes | 3 |
| gs | Grail Sort In-Place | 9.112635047 | 2655129547 | 91.126 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 9.753945368 | 2820363361 | 97.539 | Yes | 5 |
| wi | WikiSort | 10.585954715 | 3063957721 | 105.86 | Yes | 6 |
| ti | TimSort | 12.086679265 | 2435415718 | 120.87 | Yes | 7 |
| gq | GLibc Quick Sort | 12.648337155 | 2532644915 | 126.48 | Yes | 8 |
| fb | Forsort Basic In-Place | 14.444329891 | 4275253950 | 144.44 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **1.523857955** | 418701661 | **15.239** | Yes | 1 |
| wi | WikiSort | **2.071486905** | 738440369 | **20.715** | Yes | 2 |
| gs | Grail Sort In-Place | **2.701481885** | 916687412 | **27.015** | Yes | 3 |
| fw | Forsort With Workspace | 3.051516912 | 2232942425 | 30.515 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 3.089348128 | 2805379387 | 30.893 | No | 5 |
| fi | Forsort Unstable In-Place | 3.483477483 | 2171341497 | 34.835 | No | 6 |
| fs | Forsort Stable In-Place | 3.572201262 | 2027888880 | 35.722 | Yes | 7 |
| gq | GLibc Quick Sort | 5.106265138 | 1363129113 | 51.063 | Yes | 8 |
| fb | Forsort Basic In-Place | 5.216741475 | 871236419 | 52.167 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.104931432** | 99999999 | **1.049** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.124284501** | 99999999 | **1.243** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.156267969** | 100000000 | **1.563** | Yes | 3 |
| wi | WikiSort | 1.242578455 | 266513829 | 12.426 | Yes | 4 |
| gs | Grail Sort In-Place | 2.307534393 | 896694624 | 23.075 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 2.953850667 | 2921036489 | 29.539 | Yes | 6 |
| fw | Forsort With Workspace | 2.988240643 | 2240136721 | 29.882 | Yes | 7 |
| gq | GLibc Quick Sort | 3.152732648 | 1351335168 | 31.527 | Yes | 8 |
| fi | Forsort Unstable In-Place | 3.454880084 | 2176935091 | 34.549 | Yes | 9 |


## Stability Verification

| Sort Type | Name | Expected | Verified (1M random) |
|-----------|------|----------|---------------------|
| fb | Forsort Basic In-Place | Stable | Yes |
| fi | Forsort Unstable In-Place | Unstable | No |
| fw | Forsort With Workspace | Stable | Yes |
| fs | Forsort Stable In-Place | Stable | Yes |
| gs | Grail Sort In-Place | Stable | Yes |
| gq | GLibc Quick Sort | Unstable | Yes |
| nq | Bentley/McIlroy Quick Sort | Unstable | No |
| ti | TimSort | Stable | Yes |
| wi | WikiSort | Stable | Yes |
| is | Insertion Sort | Stable | N/A |

---
*Generated automatically from benchmark_results.csv*
