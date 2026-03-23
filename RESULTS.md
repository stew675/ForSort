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

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|
| fw | *****10.669** | *****15.275** | *****17.789** | *****19.163** | *****20.743** | *****25.309** |
| fi | ****12.366** | ****16.756** | ****18.850** | ****20.489** | ****22.129** | ****25.467** |
| fs | ***12.203** | ***17.389** | ***19.493** | ***20.828** | ***22.513** | ***26.565** |
| ti | 13.116 | 19.481 | 23.579 | 26.932 | 30.935 | 35.490 |
| is | 14.551 | 23.621 | 37.933 | - | - | - |
| nq | 12.846 | 18.363 | 23.747 | 29.122 | 34.336 | 39.698 |
| wi | 11.494 | 19.674 | 26.000 | 31.813 | 39.379 | 48.545 |
| fb | 15.372 | 23.464 | 29.457 | 34.386 | 39.676 | 46.670 |
| gs | 15.313 | 23.818 | 31.291 | 40.059 | 49.331 | 60.151 |
| gq | 19.315 | 27.392 | 32.894 | 39.627 | 47.899 | 57.895 |

### 1 Percent Disordered

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|
| ti | *****3.621** | *****4.456** | *****6.566** | *****8.473** | *****9.097** | *****10.726** |
| fw | ****2.052** | ****4.154** | ****6.927** | ****8.107** | ****9.174** | ****12.911** |
| fi | ***2.301** | ***4.733** | ***7.452** | ***8.498** | ***9.543** | ***12.262** |
| fs | 3.039 | 4.971 | 7.626 | 8.434 | 9.495 | 12.463 |
| fb | 3.006 | 5.786 | 9.157 | 11.258 | 13.115 | 15.519 |
| is | 2.007 | 7.312 | 19.687 | - | - | - |
| wi | 3.296 | 6.701 | 13.247 | 17.679 | 22.784 | 30.463 |
| nq | 9.466 | 12.382 | 16.551 | 20.032 | 23.383 | 27.142 |
| gs | 8.536 | 11.444 | 15.925 | 24.661 | 33.200 | 43.269 |
| gq | 10.467 | 14.361 | 20.609 | 26.639 | 32.742 | 39.832 |

### 25 Percent Disordered

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|
| fw | *****16.768** | *****20.685** | *****23.699** | *****25.973** | *****28.664** | *****34.257** |
| fi | ****18.543** | ****22.251** | ****25.100** | ****27.203** | ****30.076** | ****34.205** |
| fs | ***21.510** | ***24.004** | ***26.669** | ***28.831** | ***31.495** | ***36.598** |
| nq | 20.656 | 28.534 | 36.399 | 44.335 | 52.103 | 59.904 |
| wi | 19.029 | 30.822 | 39.009 | 46.474 | 56.882 | 67.871 |
| ti | 24.827 | 35.408 | 43.181 | 49.751 | 58.422 | 67.243 |
| gs | 26.104 | 34.559 | 43.049 | 52.071 | 62.085 | 73.497 |
| gq | 30.044 | 40.446 | 48.016 | 57.118 | 69.050 | 81.428 |
| fb | 30.659 | 42.721 | 52.840 | 62.222 | 71.858 | 83.430 |
| is | 26.560 | 40.355 | 125.12 | - | - | - |

### 5 Percent Disordered

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|
| fw | *****6.403** | *****11.388** | *****13.830** | *****15.052** | *****16.360** | *****20.020** |
| fi | ****7.580** | ****12.654** | ****14.802** | ****16.023** | ****17.340** | ****20.207** |
| fs | ***7.412** | ***13.050** | ***14.991** | ***16.236** | ***17.451** | ***20.647** |
| ti | 8.408 | 12.929 | 16.467 | 19.033 | 21.332 | 24.426 |
| is | 8.483 | 19.266 | 26.999 | - | - | - |
| fb | 9.034 | 15.951 | 20.539 | 24.258 | 28.043 | 32.984 |
| nq | 10.946 | 15.249 | 20.091 | 24.672 | 29.036 | 33.598 |
| wi | 7.685 | 15.315 | 20.809 | 26.357 | 33.136 | 41.380 |
| gs | 11.314 | 18.499 | 25.791 | 34.509 | 43.137 | 54.354 |
| gq | 14.660 | 22.428 | 27.723 | 33.982 | 40.935 | 49.686 |

### Ordered Duplicates

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|
| ti | *****0.827** | *****0.795** | *****0.793** | *****0.823** | *****0.808** | *****0.786** |
| fb | ****0.987** | ****0.963** | ****0.883** | ****0.835** | ****0.801** | ****0.792** |
| is | ***0.983** | ***0.962** | ***0.886** | - | - | - |
| fs | 0.989 | 0.975 | 0.973 | 1.040 | 0.984 | 0.978 |
| fi | 1.194 | 0.959 | 1.062 | 1.032 | 0.932 | 1.473 |
| fw | 1.227 | 0.926 | 1.060 | 1.151 | 0.916 | 2.082 |
| wi | 2.525 | 2.856 | 2.629 | 2.602 | 2.093 | 2.414 |
| gs | 10.008 | 10.785 | 11.628 | 13.555 | 17.028 | 23.056 |
| gq | 9.840 | 11.784 | 14.051 | 17.082 | 20.038 | 23.966 |
| nq | 10.431 | 12.740 | 17.470 | 20.062 | 21.931 | 25.976 |

### Ordered Unique

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|
| ti | *****0.816** | *****0.786** | *****0.782** | *****0.842** | *****0.803** | *****0.786** |
| fb | ****1.001** | ****0.973** | ****0.857** | ****0.883** | ****0.804** | ****0.792** |
| is | ***0.983** | ***0.958** | ***0.850** | - | - | - |
| fs | 0.989 | 0.975 | 0.974 | 1.001 | 0.994 | 0.981 |
| fi | 1.196 | 0.961 | 1.062 | 1.046 | 0.935 | 1.481 |
| fw | 1.239 | 0.924 | 1.059 | 1.148 | 0.908 | 2.116 |
| wi | 2.526 | 2.576 | 2.501 | 2.534 | 2.040 | 2.375 |
| gs | 7.579 | 9.239 | 10.340 | 12.646 | 16.497 | 22.325 |
| gq | 9.826 | 11.773 | 13.989 | 17.094 | 20.083 | 24.322 |
| nq | 8.885 | 11.573 | 15.770 | 18.470 | 20.889 | 24.455 |

### Random Duplicates

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|
| fw | *****16.563** | *****18.540** | *****22.777** | *****25.646** | *****29.059** | *****36.295** |
| fi | ****20.354** | ****22.537** | ****26.187** | ****29.348** | ****33.275** | ****38.793** |
| fs | ***23.847** | ***23.822** | ***27.360** | ***30.156** | ***33.678** | ***42.454** |
| gs | 38.502 | 47.561 | 56.133 | 65.399 | 77.983 | 91.618 |
| nq | 36.351 | 49.007 | 61.328 | 73.490 | 85.651 | 97.703 |
| wi | 32.695 | 50.614 | 62.446 | 74.782 | 91.588 | 108.10 |
| ti | 43.824 | 59.711 | 74.164 | 88.695 | 104.91 | 121.29 |
| gq | 48.985 | 65.245 | 77.091 | 92.146 | 109.66 | 126.81 |
| fb | 48.660 | 68.078 | 87.104 | 106.27 | 124.30 | 146.11 |
| is | 48.942 | 117.43 | 976.59 | - | - | - |

### Random Unique

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|
| fw | *****16.543** | *****18.509** | *****22.825** | *****25.602** | *****29.311** | *****36.396** |
| fi | ****20.401** | ****22.616** | ****26.020** | ****29.467** | ****33.000** | ****38.656** |
| fs | ***23.645** | ***23.638** | ***27.274** | ***30.167** | ***33.944** | ***43.581** |
| gs | 38.142 | 47.471 | 56.091 | 65.177 | 77.906 | 91.645 |
| nq | 37.560 | 50.275 | 62.617 | 74.916 | 87.093 | 99.441 |
| wi | 32.977 | 50.234 | 61.962 | 74.390 | 91.938 | 108.09 |
| ti | 43.832 | 60.083 | 74.291 | 88.721 | 105.05 | 121.26 |
| gq | 49.021 | 65.734 | 77.112 | 92.131 | 109.24 | 126.72 |
| fb | 48.408 | 68.210 | 87.692 | 105.96 | 124.86 | 146.13 |
| is | 48.529 | 116.34 | 981.14 | - | - | - |

### Reversed Duplicates

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|
| ti | *****9.586** | *****9.437** | *****9.856** | *****10.315** | *****11.983** | *****16.041** |
| wi | ****7.726** | ****9.949** | ****11.241** | ****12.300** | ****15.496** | ****20.924** |
| fw | ***8.236** | ***11.495** | ***14.344** | ***18.784** | ***22.482** | ***30.663** |
| gs | 13.487 | 14.311 | 15.028 | 17.386 | 20.196 | 27.421 |
| fi | 9.428 | 12.106 | 15.279 | 19.543 | 24.037 | 35.531 |
| fs | 10.407 | 12.096 | 14.451 | 18.580 | 24.450 | 36.415 |
| nq | 16.413 | 21.302 | 22.057 | 26.173 | 30.469 | 31.010 |
| fb | 19.726 | 21.645 | 24.070 | 28.013 | 32.275 | 53.640 |
| gq | 23.947 | 31.383 | 36.155 | 36.316 | 43.205 | 50.597 |
| is | 22.556 | 211.69 | 2433.2 | - | - | - |

### Reversed Unique

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|----------|----------|----------|----------|----------|----------|
| ti | *****0.959** | *****0.921** | *****0.925** | *****1.059** | *****0.979** | *****1.064** |
| fb | ****2.156** | ****2.148** | ****2.052** | ****2.096** | ****2.051** | ****2.227** |
| fs | ***2.939** | ***2.275** | ***2.390** | ***2.508** | ***2.775** | ***5.630** |
| wi | 3.530 | 4.454 | 5.135 | 6.065 | 6.951 | 12.789 |
| gs | 7.808 | 9.513 | 10.553 | 13.231 | 16.104 | 22.968 |
| fw | 7.158 | 10.296 | 13.378 | 18.072 | 21.955 | 30.722 |
| fi | 7.632 | 10.691 | 14.004 | 19.020 | 24.310 | 33.838 |
| gq | 11.723 | 14.470 | 17.022 | 19.797 | 24.978 | 31.609 |
| nq | 17.114 | 22.596 | 21.634 | 26.055 | 31.002 | 29.687 |
| is | 21.973 | 210.72 | 2458.9 | - | - | - |


## Cross-Category Analysis

### Win Count by Algorithm

| Rank | Sort Type | Name | Wins | Top 3 | Win Rate |
|------|-----------|------|------|-------|----------|
| 1 | **fw** | Forsort With Workspace | 31 | 42 | 51.7% |
| 2 | **ti** | TimSort | 25 | 29 | 41.7% |
| 3 | **is** | Insertion Sort | 1 | 6 | 1.7% |
| 4 | **wi** | WikiSort | 1 | 8 | 1.7% |
| 5 | **fb** | Forsort Basic In-Place | 1 | 15 | 1.7% |
| 6 | **fi** | Forsort Unstable In-Place | 1 | 36 | 1.7% |

### Recommendations by Use Case

- **Best Stable Sort:** fs (Forsort Stable In-Place) - Avg: 18.729 ns/item (1M-100M items)
- **Best Unstable Sort:** fi (Forsort Unstable In-Place) - Avg: 20.305 ns/item (1M-100M items)
- **Best for Nearly-Sorted Data:** fw (Forsort With Workspace) - Avg: 10.531 ns/item


## Performance Rankings

### 1000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 10.669 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 11.494 | 7.7% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 12.203 | 14.4% | Yes |
| 4 | fi | Forsort Unstable In-Place | 12.366 | 15.9% | No |
| 5 | nq | Bentley/McIlroy Quick Sort | 12.846 | 20.4% | No |
| 6 | ti | TimSort | 13.116 | 22.9% | Yes |
| 7 | is | Insertion Sort | 14.551 | 36.4% | Yes |
| 8 | gs | Grail Sort In-Place | 15.313 | 43.5% | Yes |
| 9 | fb | Forsort Basic In-Place | 15.372 | 44.1% | Yes |
| 10 | gq | GLibc Quick Sort | 19.315 | 81.0% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 2.007 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 2.052 | 2.2% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 2.301 | 14.6% | No |
| 4 | fb | Forsort Basic In-Place | 3.006 | 49.8% | Yes |
| 5 | fs | Forsort Stable In-Place | 3.039 | 51.4% | Yes |
| 6 | wi | WikiSort | 3.296 | 64.2% | Yes |
| 7 | ti | TimSort | 3.621 | 80.4% | Yes |
| 8 | gs | Grail Sort In-Place | 8.536 | 325.3% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort | 9.466 | 371.6% | No |
| 10 | gq | GLibc Quick Sort | 10.467 | 421.5% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 16.768 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 18.543 | 10.6% | No |
| 3 | **wi** | WikiSort | 19.029 | 13.5% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 20.656 | 23.2% | No |
| 5 | fs | Forsort Stable In-Place | 21.510 | 28.3% | Yes |
| 6 | ti | TimSort | 24.827 | 48.1% | Yes |
| 7 | gs | Grail Sort In-Place | 26.104 | 55.7% | Yes |
| 8 | is | Insertion Sort | 26.560 | 58.4% | Yes |
| 9 | gq | GLibc Quick Sort | 30.044 | 79.2% | No |
| 10 | fb | Forsort Basic In-Place | 30.659 | 82.8% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 6.403 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 7.412 | 15.8% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 7.580 | 18.4% | No |
| 4 | wi | WikiSort | 7.685 | 20.0% | Yes |
| 5 | ti | TimSort | 8.408 | 31.3% | Yes |
| 6 | is | Insertion Sort | 8.483 | 32.5% | Yes |
| 7 | fb | Forsort Basic In-Place | 9.034 | 41.1% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 10.946 | 71.0% | No |
| 9 | gs | Grail Sort In-Place | 11.314 | 76.7% | Yes |
| 10 | gq | GLibc Quick Sort | 14.660 | 129.0% | No |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.827 | 0.0% | Yes |
| 2 | **is** | Insertion Sort | 0.983 | 18.9% | Yes |
| 3 | **fb** | Forsort Basic In-Place | 0.987 | 19.3% | Yes |
| 4 | fs | Forsort Stable In-Place | 0.989 | 19.6% | Yes |
| 5 | fi | Forsort Unstable In-Place | 1.194 | 44.4% | No |
| 6 | fw | Forsort With Workspace | 1.227 | 48.4% | Yes |
| 7 | wi | WikiSort | 2.525 | 205.3% | Yes |
| 8 | gq | GLibc Quick Sort | 9.840 | 1089.8% | No |
| 9 | gs | Grail Sort In-Place | 10.008 | 1110.2% | Yes |
| 10 | nq | Bentley/McIlroy Quick Sort | 10.431 | 1161.3% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.816 | 0.0% | Yes |
| 2 | **is** | Insertion Sort | 0.983 | 20.5% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 0.989 | 21.2% | Yes |
| 4 | fb | Forsort Basic In-Place | 1.001 | 22.7% | Yes |
| 5 | fi | Forsort Unstable In-Place | 1.196 | 46.6% | No |
| 6 | fw | Forsort With Workspace | 1.239 | 51.8% | Yes |
| 7 | wi | WikiSort | 2.526 | 209.6% | Yes |
| 8 | gs | Grail Sort In-Place | 7.579 | 828.8% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort | 8.885 | 988.8% | No |
| 10 | gq | GLibc Quick Sort | 9.826 | 1104.2% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 16.563 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 20.354 | 22.9% | No |
| 3 | **fs** | Forsort Stable In-Place | 23.847 | 44.0% | Yes |
| 4 | wi | WikiSort | 32.695 | 97.4% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 36.351 | 119.5% | No |
| 6 | gs | Grail Sort In-Place | 38.502 | 132.5% | Yes |
| 7 | ti | TimSort | 43.824 | 164.6% | Yes |
| 8 | fb | Forsort Basic In-Place | 48.660 | 193.8% | Yes |
| 9 | is | Insertion Sort | 48.942 | 195.5% | Yes |
| 10 | gq | GLibc Quick Sort | 48.985 | 195.7% | No |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 16.543 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 20.401 | 23.3% | No |
| 3 | **fs** | Forsort Stable In-Place | 23.645 | 42.9% | Yes |
| 4 | wi | WikiSort | 32.977 | 99.3% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 37.560 | 127.0% | No |
| 6 | gs | Grail Sort In-Place | 38.142 | 130.6% | Yes |
| 7 | ti | TimSort | 43.832 | 165.0% | Yes |
| 8 | fb | Forsort Basic In-Place | 48.408 | 192.6% | Yes |
| 9 | is | Insertion Sort | 48.529 | 193.4% | Yes |
| 10 | gq | GLibc Quick Sort | 49.021 | 196.3% | No |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **wi** | WikiSort | 7.726 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 8.236 | 6.6% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 9.428 | 22.0% | No |
| 4 | ti | TimSort | 9.586 | 24.1% | Yes |
| 5 | fs | Forsort Stable In-Place | 10.407 | 34.7% | Yes |
| 6 | gs | Grail Sort In-Place | 13.487 | 74.6% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 16.413 | 112.4% | No |
| 8 | fb | Forsort Basic In-Place | 19.726 | 155.3% | Yes |
| 9 | is | Insertion Sort | 22.556 | 191.9% | Yes |
| 10 | gq | GLibc Quick Sort | 23.947 | 210.0% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.959 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 2.156 | 124.8% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 2.939 | 206.5% | Yes |
| 4 | wi | WikiSort | 3.530 | 268.1% | Yes |
| 5 | fw | Forsort With Workspace | 7.158 | 646.4% | Yes |
| 6 | fi | Forsort Unstable In-Place | 7.632 | 695.8% | No |
| 7 | gs | Grail Sort In-Place | 7.808 | 714.2% | Yes |
| 8 | gq | GLibc Quick Sort | 11.723 | 1122.4% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 17.114 | 1684.6% | No |
| 10 | is | Insertion Sort | 21.973 | 2191.2% | Yes |

#### Overall Winner (Average Across All Variants)

**Winner:** fw (Forsort With Workspace) - Average: 8.686 ns/item

### 10000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 15.275 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 16.756 | 9.7% | No |
| 3 | **fs** | Forsort Stable In-Place | 17.389 | 13.8% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 18.363 | 20.2% | No |
| 5 | ti | TimSort | 19.481 | 27.5% | Yes |
| 6 | wi | WikiSort | 19.674 | 28.8% | Yes |
| 7 | fb | Forsort Basic In-Place | 23.464 | 53.6% | Yes |
| 8 | is | Insertion Sort | 23.621 | 54.6% | Yes |
| 9 | gs | Grail Sort In-Place | 23.818 | 55.9% | Yes |
| 10 | gq | GLibc Quick Sort | 27.392 | 79.3% | No |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 4.154 | 0.0% | Yes |
| 2 | **ti** | TimSort | 4.456 | 7.3% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 4.733 | 13.9% | No |
| 4 | fs | Forsort Stable In-Place | 4.971 | 19.7% | Yes |
| 5 | fb | Forsort Basic In-Place | 5.786 | 39.3% | Yes |
| 6 | wi | WikiSort | 6.701 | 61.3% | Yes |
| 7 | is | Insertion Sort | 7.312 | 76.0% | Yes |
| 8 | gs | Grail Sort In-Place | 11.444 | 175.5% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort | 12.382 | 198.1% | No |
| 10 | gq | GLibc Quick Sort | 14.361 | 245.7% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 20.685 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 22.251 | 7.6% | No |
| 3 | **fs** | Forsort Stable In-Place | 24.004 | 16.0% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 28.534 | 37.9% | No |
| 5 | wi | WikiSort | 30.822 | 49.0% | Yes |
| 6 | gs | Grail Sort In-Place | 34.559 | 67.1% | Yes |
| 7 | ti | TimSort | 35.408 | 71.2% | Yes |
| 8 | is | Insertion Sort | 40.355 | 95.1% | Yes |
| 9 | gq | GLibc Quick Sort | 40.446 | 95.5% | No |
| 10 | fb | Forsort Basic In-Place | 42.721 | 106.5% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 11.388 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 12.654 | 11.1% | No |
| 3 | **ti** | TimSort | 12.929 | 13.5% | Yes |
| 4 | fs | Forsort Stable In-Place | 13.050 | 14.6% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 15.249 | 33.9% | No |
| 6 | wi | WikiSort | 15.315 | 34.5% | Yes |
| 7 | fb | Forsort Basic In-Place | 15.951 | 40.1% | Yes |
| 8 | gs | Grail Sort In-Place | 18.499 | 62.4% | Yes |
| 9 | is | Insertion Sort | 19.266 | 69.2% | Yes |
| 10 | gq | GLibc Quick Sort | 22.428 | 96.9% | No |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.795 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 0.926 | 16.5% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 0.959 | 20.6% | No |
| 4 | is | Insertion Sort | 0.962 | 21.0% | Yes |
| 5 | fb | Forsort Basic In-Place | 0.963 | 21.1% | Yes |
| 6 | fs | Forsort Stable In-Place | 0.975 | 22.6% | Yes |
| 7 | wi | WikiSort | 2.856 | 259.2% | Yes |
| 8 | gs | Grail Sort In-Place | 10.785 | 1256.6% | Yes |
| 9 | gq | GLibc Quick Sort | 11.784 | 1382.3% | No |
| 10 | nq | Bentley/McIlroy Quick Sort | 12.740 | 1502.5% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.786 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 0.924 | 17.6% | Yes |
| 3 | **is** | Insertion Sort | 0.958 | 21.9% | Yes |
| 4 | fi | Forsort Unstable In-Place | 0.961 | 22.3% | No |
| 5 | fb | Forsort Basic In-Place | 0.973 | 23.8% | Yes |
| 6 | fs | Forsort Stable In-Place | 0.975 | 24.0% | Yes |
| 7 | wi | WikiSort | 2.576 | 227.7% | Yes |
| 8 | gs | Grail Sort In-Place | 9.239 | 1075.4% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort | 11.573 | 1372.4% | No |
| 10 | gq | GLibc Quick Sort | 11.773 | 1397.8% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 18.540 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 22.537 | 21.6% | No |
| 3 | **fs** | Forsort Stable In-Place | 23.822 | 28.5% | Yes |
| 4 | gs | Grail Sort In-Place | 47.561 | 156.5% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 49.007 | 164.3% | No |
| 6 | wi | WikiSort | 50.614 | 173.0% | Yes |
| 7 | ti | TimSort | 59.711 | 222.1% | Yes |
| 8 | gq | GLibc Quick Sort | 65.245 | 251.9% | No |
| 9 | fb | Forsort Basic In-Place | 68.078 | 267.2% | Yes |
| 10 | is | Insertion Sort | 117.43 | 533.4% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 18.509 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 22.616 | 22.2% | No |
| 3 | **fs** | Forsort Stable In-Place | 23.638 | 27.7% | Yes |
| 4 | gs | Grail Sort In-Place | 47.471 | 156.5% | Yes |
| 5 | wi | WikiSort | 50.234 | 171.4% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 50.275 | 171.6% | No |
| 7 | ti | TimSort | 60.083 | 224.6% | Yes |
| 8 | gq | GLibc Quick Sort | 65.734 | 255.1% | No |
| 9 | fb | Forsort Basic In-Place | 68.210 | 268.5% | Yes |
| 10 | is | Insertion Sort | 116.34 | 528.6% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 9.437 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 9.949 | 5.4% | Yes |
| 3 | **fw** | Forsort With Workspace | 11.495 | 21.8% | Yes |
| 4 | fs | Forsort Stable In-Place | 12.096 | 28.2% | Yes |
| 5 | fi | Forsort Unstable In-Place | 12.106 | 28.3% | No |
| 6 | gs | Grail Sort In-Place | 14.311 | 51.6% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 21.302 | 125.7% | No |
| 8 | fb | Forsort Basic In-Place | 21.645 | 129.4% | Yes |
| 9 | gq | GLibc Quick Sort | 31.383 | 232.6% | No |
| 10 | is | Insertion Sort | 211.69 | 2143.2% | Yes |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.921 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 2.148 | 133.2% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 2.275 | 147.0% | Yes |
| 4 | wi | WikiSort | 4.454 | 383.6% | Yes |
| 5 | gs | Grail Sort In-Place | 9.513 | 932.9% | Yes |
| 6 | fw | Forsort With Workspace | 10.296 | 1017.9% | Yes |
| 7 | fi | Forsort Unstable In-Place | 10.691 | 1060.8% | No |
| 8 | gq | GLibc Quick Sort | 14.470 | 1471.1% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 22.596 | 2353.4% | No |
| 10 | is | Insertion Sort | 210.72 | 22779.2% | Yes |

#### Overall Winner (Average Across All Variants)

**Winner:** fw (Forsort With Workspace) - Average: 11.219 ns/item

### 100000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 17.789 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 18.850 | 6.0% | No |
| 3 | **fs** | Forsort Stable In-Place | 19.493 | 9.6% | Yes |
| 4 | ti | TimSort | 23.579 | 32.5% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 23.747 | 33.5% | No |
| 6 | wi | WikiSort | 26.000 | 46.2% | Yes |
| 7 | fb | Forsort Basic In-Place | 29.457 | 65.6% | Yes |
| 8 | gs | Grail Sort In-Place | 31.291 | 75.9% | Yes |
| 9 | gq | GLibc Quick Sort | 32.894 | 84.9% | No |
| 10 | is | Insertion Sort | 37.933 | 113.2% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 6.566 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 6.927 | 5.5% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 7.452 | 13.5% | No |
| 4 | fs | Forsort Stable In-Place | 7.626 | 16.1% | Yes |
| 5 | fb | Forsort Basic In-Place | 9.157 | 39.5% | Yes |
| 6 | wi | WikiSort | 13.247 | 101.8% | Yes |
| 7 | gs | Grail Sort In-Place | 15.925 | 142.5% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 16.551 | 152.1% | No |
| 9 | is | Insertion Sort | 19.687 | 199.8% | Yes |
| 10 | gq | GLibc Quick Sort | 20.609 | 213.9% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 23.699 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 25.100 | 5.9% | No |
| 3 | **fs** | Forsort Stable In-Place | 26.669 | 12.5% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 36.399 | 53.6% | No |
| 5 | wi | WikiSort | 39.009 | 64.6% | Yes |
| 6 | gs | Grail Sort In-Place | 43.049 | 81.6% | Yes |
| 7 | ti | TimSort | 43.181 | 82.2% | Yes |
| 8 | gq | GLibc Quick Sort | 48.016 | 102.6% | No |
| 9 | fb | Forsort Basic In-Place | 52.840 | 123.0% | Yes |
| 10 | is | Insertion Sort | 125.12 | 428.0% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 13.830 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 14.802 | 7.0% | No |
| 3 | **fs** | Forsort Stable In-Place | 14.991 | 8.4% | Yes |
| 4 | ti | TimSort | 16.467 | 19.1% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 20.091 | 45.3% | No |
| 6 | fb | Forsort Basic In-Place | 20.539 | 48.5% | Yes |
| 7 | wi | WikiSort | 20.809 | 50.5% | Yes |
| 8 | gs | Grail Sort In-Place | 25.791 | 86.5% | Yes |
| 9 | is | Insertion Sort | 26.999 | 95.2% | Yes |
| 10 | gq | GLibc Quick Sort | 27.723 | 100.5% | No |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.793 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.883 | 11.3% | Yes |
| 3 | **is** | Insertion Sort | 0.886 | 11.7% | Yes |
| 4 | fs | Forsort Stable In-Place | 0.973 | 22.7% | Yes |
| 5 | fw | Forsort With Workspace | 1.060 | 33.7% | Yes |
| 6 | fi | Forsort Unstable In-Place | 1.062 | 33.9% | No |
| 7 | wi | WikiSort | 2.629 | 231.5% | Yes |
| 8 | gs | Grail Sort In-Place | 11.628 | 1366.3% | Yes |
| 9 | gq | GLibc Quick Sort | 14.051 | 1671.9% | No |
| 10 | nq | Bentley/McIlroy Quick Sort | 17.470 | 2103.0% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.782 | 0.0% | Yes |
| 2 | **is** | Insertion Sort | 0.850 | 8.7% | Yes |
| 3 | **fb** | Forsort Basic In-Place | 0.857 | 9.6% | Yes |
| 4 | fs | Forsort Stable In-Place | 0.974 | 24.6% | Yes |
| 5 | fw | Forsort With Workspace | 1.059 | 35.4% | Yes |
| 6 | fi | Forsort Unstable In-Place | 1.062 | 35.8% | No |
| 7 | wi | WikiSort | 2.501 | 219.8% | Yes |
| 8 | gs | Grail Sort In-Place | 10.340 | 1222.3% | Yes |
| 9 | gq | GLibc Quick Sort | 13.989 | 1688.9% | No |
| 10 | nq | Bentley/McIlroy Quick Sort | 15.770 | 1916.6% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 22.777 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 26.187 | 15.0% | No |
| 3 | **fs** | Forsort Stable In-Place | 27.360 | 20.1% | Yes |
| 4 | gs | Grail Sort In-Place | 56.133 | 146.4% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 61.328 | 169.3% | No |
| 6 | wi | WikiSort | 62.446 | 174.2% | Yes |
| 7 | ti | TimSort | 74.164 | 225.6% | Yes |
| 8 | gq | GLibc Quick Sort | 77.091 | 238.5% | No |
| 9 | fb | Forsort Basic In-Place | 87.104 | 282.4% | Yes |
| 10 | is | Insertion Sort | 976.59 | 4187.6% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 22.825 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 26.020 | 14.0% | No |
| 3 | **fs** | Forsort Stable In-Place | 27.274 | 19.5% | Yes |
| 4 | gs | Grail Sort In-Place | 56.091 | 145.7% | Yes |
| 5 | wi | WikiSort | 61.962 | 171.5% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 62.617 | 174.3% | No |
| 7 | ti | TimSort | 74.291 | 225.5% | Yes |
| 8 | gq | GLibc Quick Sort | 77.112 | 237.8% | No |
| 9 | fb | Forsort Basic In-Place | 87.692 | 284.2% | Yes |
| 10 | is | Insertion Sort | 981.14 | 4198.5% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 9.856 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 11.241 | 14.1% | Yes |
| 3 | **fw** | Forsort With Workspace | 14.344 | 45.5% | Yes |
| 4 | fs | Forsort Stable In-Place | 14.451 | 46.6% | Yes |
| 5 | gs | Grail Sort In-Place | 15.028 | 52.5% | Yes |
| 6 | fi | Forsort Unstable In-Place | 15.279 | 55.0% | No |
| 7 | nq | Bentley/McIlroy Quick Sort | 22.057 | 123.8% | No |
| 8 | fb | Forsort Basic In-Place | 24.070 | 144.2% | Yes |
| 9 | gq | GLibc Quick Sort | 36.155 | 266.8% | No |
| 10 | is | Insertion Sort | 2433.2 | 24587.5% | Yes |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.925 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 2.052 | 121.8% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 2.390 | 158.4% | Yes |
| 4 | wi | WikiSort | 5.135 | 455.1% | Yes |
| 5 | gs | Grail Sort In-Place | 10.553 | 1040.9% | Yes |
| 6 | fw | Forsort With Workspace | 13.378 | 1346.3% | Yes |
| 7 | fi | Forsort Unstable In-Place | 14.004 | 1413.9% | No |
| 8 | gq | GLibc Quick Sort | 17.022 | 1740.2% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 21.634 | 2238.8% | No |
| 10 | is | Insertion Sort | 2458.9 | 265723.7% | Yes |

#### Overall Winner (Average Across All Variants)

**Winner:** fw (Forsort With Workspace) - Average: 13.769 ns/item

### 1000000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 19.163 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 20.489 | 6.9% | No |
| 3 | **fs** | Forsort Stable In-Place | 20.828 | 8.7% | Yes |
| 4 | ti | TimSort | 26.932 | 40.5% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 29.122 | 52.0% | No |
| 6 | wi | WikiSort | 31.813 | 66.0% | Yes |
| 7 | fb | Forsort Basic In-Place | 34.386 | 79.4% | Yes |
| 8 | gq | GLibc Quick Sort | 39.627 | 106.8% | No |
| 9 | gs | Grail Sort In-Place | 40.059 | 109.0% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 8.107 | 0.0% | Yes |
| 2 | **fs** | Forsort Stable In-Place | 8.434 | 4.0% | Yes |
| 3 | **ti** | TimSort | 8.473 | 4.5% | Yes |
| 4 | fi | Forsort Unstable In-Place | 8.498 | 4.8% | No |
| 5 | fb | Forsort Basic In-Place | 11.258 | 38.9% | Yes |
| 6 | wi | WikiSort | 17.679 | 118.1% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 20.032 | 147.1% | No |
| 8 | gs | Grail Sort In-Place | 24.661 | 204.2% | Yes |
| 9 | gq | GLibc Quick Sort | 26.639 | 228.6% | No |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 25.973 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 27.203 | 4.7% | No |
| 3 | **fs** | Forsort Stable In-Place | 28.831 | 11.0% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 44.335 | 70.7% | No |
| 5 | wi | WikiSort | 46.474 | 78.9% | Yes |
| 6 | ti | TimSort | 49.751 | 91.5% | Yes |
| 7 | gs | Grail Sort In-Place | 52.071 | 100.5% | Yes |
| 8 | gq | GLibc Quick Sort | 57.118 | 119.9% | No |
| 9 | fb | Forsort Basic In-Place | 62.222 | 139.6% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 15.052 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 16.023 | 6.5% | No |
| 3 | **fs** | Forsort Stable In-Place | 16.236 | 7.9% | Yes |
| 4 | ti | TimSort | 19.033 | 26.4% | Yes |
| 5 | fb | Forsort Basic In-Place | 24.258 | 61.2% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 24.672 | 63.9% | No |
| 7 | wi | WikiSort | 26.357 | 75.1% | Yes |
| 8 | gq | GLibc Quick Sort | 33.982 | 125.8% | No |
| 9 | gs | Grail Sort In-Place | 34.509 | 129.3% | Yes |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.823 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.835 | 1.5% | Yes |
| 3 | **fi** | Forsort Unstable In-Place | 1.032 | 25.4% | No |
| 4 | fs | Forsort Stable In-Place | 1.040 | 26.4% | Yes |
| 5 | fw | Forsort With Workspace | 1.151 | 39.9% | Yes |
| 6 | wi | WikiSort | 2.602 | 216.2% | Yes |
| 7 | gs | Grail Sort In-Place | 13.555 | 1547.0% | Yes |
| 8 | gq | GLibc Quick Sort | 17.082 | 1975.6% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 20.062 | 2337.7% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.842 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.883 | 4.9% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 1.001 | 18.9% | Yes |
| 4 | fi | Forsort Unstable In-Place | 1.046 | 24.2% | No |
| 5 | fw | Forsort With Workspace | 1.148 | 36.3% | Yes |
| 6 | wi | WikiSort | 2.534 | 201.0% | Yes |
| 7 | gs | Grail Sort In-Place | 12.646 | 1401.9% | Yes |
| 8 | gq | GLibc Quick Sort | 17.094 | 1930.2% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 18.470 | 2093.6% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 25.646 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 29.348 | 14.4% | No |
| 3 | **fs** | Forsort Stable In-Place | 30.156 | 17.6% | Yes |
| 4 | gs | Grail Sort In-Place | 65.399 | 155.0% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 73.490 | 186.6% | No |
| 6 | wi | WikiSort | 74.782 | 191.6% | Yes |
| 7 | ti | TimSort | 88.695 | 245.8% | Yes |
| 8 | gq | GLibc Quick Sort | 92.146 | 259.3% | No |
| 9 | fb | Forsort Basic In-Place | 106.27 | 314.4% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 25.602 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 29.467 | 15.1% | No |
| 3 | **fs** | Forsort Stable In-Place | 30.167 | 17.8% | Yes |
| 4 | gs | Grail Sort In-Place | 65.177 | 154.6% | Yes |
| 5 | wi | WikiSort | 74.390 | 190.6% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 74.916 | 192.6% | No |
| 7 | ti | TimSort | 88.721 | 246.5% | Yes |
| 8 | gq | GLibc Quick Sort | 92.131 | 259.9% | No |
| 9 | fb | Forsort Basic In-Place | 105.96 | 313.9% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 10.315 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 12.300 | 19.2% | Yes |
| 3 | **gs** | Grail Sort In-Place | 17.386 | 68.6% | Yes |
| 4 | fs | Forsort Stable In-Place | 18.580 | 80.1% | Yes |
| 5 | fw | Forsort With Workspace | 18.784 | 82.1% | Yes |
| 6 | fi | Forsort Unstable In-Place | 19.543 | 89.5% | No |
| 7 | nq | Bentley/McIlroy Quick Sort | 26.173 | 153.7% | No |
| 8 | fb | Forsort Basic In-Place | 28.013 | 171.6% | Yes |
| 9 | gq | GLibc Quick Sort | 36.316 | 252.1% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.059 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 2.096 | 97.9% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 2.508 | 136.8% | Yes |
| 4 | wi | WikiSort | 6.065 | 472.7% | Yes |
| 5 | gs | Grail Sort In-Place | 13.231 | 1149.4% | Yes |
| 6 | fw | Forsort With Workspace | 18.072 | 1606.5% | Yes |
| 7 | fi | Forsort Unstable In-Place | 19.020 | 1696.0% | No |
| 8 | gq | GLibc Quick Sort | 19.797 | 1769.4% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 26.055 | 2360.3% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Forsort Stable In-Place) - Average: 15.778 ns/item

### 10000000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 20.743 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 22.129 | 6.7% | No |
| 3 | **fs** | Forsort Stable In-Place | 22.513 | 8.5% | Yes |
| 4 | ti | TimSort | 30.935 | 49.1% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 34.336 | 65.5% | No |
| 6 | wi | WikiSort | 39.379 | 89.8% | Yes |
| 7 | fb | Forsort Basic In-Place | 39.676 | 91.3% | Yes |
| 8 | gq | GLibc Quick Sort | 47.899 | 130.9% | No |
| 9 | gs | Grail Sort In-Place | 49.331 | 137.8% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 9.097 | 0.0% | Yes |
| 2 | **fw** | Forsort With Workspace | 9.174 | 0.8% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 9.495 | 4.4% | Yes |
| 4 | fi | Forsort Unstable In-Place | 9.543 | 4.9% | No |
| 5 | fb | Forsort Basic In-Place | 13.115 | 44.2% | Yes |
| 6 | wi | WikiSort | 22.784 | 150.5% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 23.383 | 157.0% | No |
| 8 | gq | GLibc Quick Sort | 32.742 | 259.9% | No |
| 9 | gs | Grail Sort In-Place | 33.200 | 265.0% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 28.664 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 30.076 | 4.9% | No |
| 3 | **fs** | Forsort Stable In-Place | 31.495 | 9.9% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 52.103 | 81.8% | No |
| 5 | wi | WikiSort | 56.882 | 98.4% | Yes |
| 6 | ti | TimSort | 58.422 | 103.8% | Yes |
| 7 | gs | Grail Sort In-Place | 62.085 | 116.6% | Yes |
| 8 | gq | GLibc Quick Sort | 69.050 | 140.9% | No |
| 9 | fb | Forsort Basic In-Place | 71.858 | 150.7% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 16.360 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 17.340 | 6.0% | No |
| 3 | **fs** | Forsort Stable In-Place | 17.451 | 6.7% | Yes |
| 4 | ti | TimSort | 21.332 | 30.4% | Yes |
| 5 | fb | Forsort Basic In-Place | 28.043 | 71.4% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 29.036 | 77.5% | No |
| 7 | wi | WikiSort | 33.136 | 102.5% | Yes |
| 8 | gq | GLibc Quick Sort | 40.935 | 150.2% | No |
| 9 | gs | Grail Sort In-Place | 43.137 | 163.7% | Yes |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fb** | Forsort Basic In-Place | 0.801 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.808 | 0.9% | Yes |
| 3 | **fw** | Forsort With Workspace | 0.916 | 14.4% | Yes |
| 4 | fi | Forsort Unstable In-Place | 0.932 | 16.4% | No |
| 5 | fs | Forsort Stable In-Place | 0.984 | 22.8% | Yes |
| 6 | wi | WikiSort | 2.093 | 161.3% | Yes |
| 7 | gs | Grail Sort In-Place | 17.028 | 2025.8% | Yes |
| 8 | gq | GLibc Quick Sort | 20.038 | 2401.6% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 21.931 | 2638.0% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.803 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.804 | 0.1% | Yes |
| 3 | **fw** | Forsort With Workspace | 0.908 | 13.1% | Yes |
| 4 | fi | Forsort Unstable In-Place | 0.935 | 16.4% | No |
| 5 | fs | Forsort Stable In-Place | 0.994 | 23.8% | Yes |
| 6 | wi | WikiSort | 2.040 | 154.0% | Yes |
| 7 | gs | Grail Sort In-Place | 16.497 | 1954.4% | Yes |
| 8 | gq | GLibc Quick Sort | 20.083 | 2401.0% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 20.889 | 2501.4% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 29.059 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 33.275 | 14.5% | No |
| 3 | **fs** | Forsort Stable In-Place | 33.678 | 15.9% | Yes |
| 4 | gs | Grail Sort In-Place | 77.983 | 168.4% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 85.651 | 194.7% | No |
| 6 | wi | WikiSort | 91.588 | 215.2% | Yes |
| 7 | ti | TimSort | 104.91 | 261.0% | Yes |
| 8 | gq | GLibc Quick Sort | 109.66 | 277.4% | No |
| 9 | fb | Forsort Basic In-Place | 124.30 | 327.8% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 29.311 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 33.000 | 12.6% | No |
| 3 | **fs** | Forsort Stable In-Place | 33.944 | 15.8% | Yes |
| 4 | gs | Grail Sort In-Place | 77.906 | 165.8% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 87.093 | 197.1% | No |
| 6 | wi | WikiSort | 91.938 | 213.7% | Yes |
| 7 | ti | TimSort | 105.05 | 258.4% | Yes |
| 8 | gq | GLibc Quick Sort | 109.24 | 272.7% | No |
| 9 | fb | Forsort Basic In-Place | 124.86 | 326.0% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 11.983 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 15.496 | 29.3% | Yes |
| 3 | **gs** | Grail Sort In-Place | 20.196 | 68.5% | Yes |
| 4 | fw | Forsort With Workspace | 22.482 | 87.6% | Yes |
| 5 | fi | Forsort Unstable In-Place | 24.037 | 100.6% | No |
| 6 | fs | Forsort Stable In-Place | 24.450 | 104.0% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 30.469 | 154.3% | No |
| 8 | fb | Forsort Basic In-Place | 32.275 | 169.3% | Yes |
| 9 | gq | GLibc Quick Sort | 43.205 | 260.6% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.979 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 2.051 | 109.5% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 2.775 | 183.5% | Yes |
| 4 | wi | WikiSort | 6.951 | 610.0% | Yes |
| 5 | gs | Grail Sort In-Place | 16.104 | 1544.9% | Yes |
| 6 | fw | Forsort With Workspace | 21.955 | 2142.6% | Yes |
| 7 | fi | Forsort Unstable In-Place | 24.310 | 2383.1% | No |
| 8 | gq | GLibc Quick Sort | 24.978 | 2451.4% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 31.002 | 3066.7% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Forsort Stable In-Place) - Average: 17.778 ns/item

### 100000000 Items

#### 10 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 25.309 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 25.467 | 0.6% | No |
| 3 | **fs** | Forsort Stable In-Place | 26.565 | 5.0% | Yes |
| 4 | ti | TimSort | 35.490 | 40.2% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 39.698 | 56.9% | No |
| 6 | fb | Forsort Basic In-Place | 46.670 | 84.4% | Yes |
| 7 | wi | WikiSort | 48.545 | 91.8% | Yes |
| 8 | gq | GLibc Quick Sort | 57.895 | 128.8% | No |
| 9 | gs | Grail Sort In-Place | 60.151 | 137.7% | Yes |

#### 1 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 10.726 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 12.262 | 14.3% | No |
| 3 | **fs** | Forsort Stable In-Place | 12.463 | 16.2% | Yes |
| 4 | fw | Forsort With Workspace | 12.911 | 20.4% | Yes |
| 5 | fb | Forsort Basic In-Place | 15.519 | 44.7% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 27.142 | 153.0% | No |
| 7 | wi | WikiSort | 30.463 | 184.0% | Yes |
| 8 | gq | GLibc Quick Sort | 39.832 | 271.4% | No |
| 9 | gs | Grail Sort In-Place | 43.269 | 303.4% | Yes |

#### 25 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fi** | Forsort Unstable In-Place | 34.205 | 0.0% | No |
| 2 | **fw** | Forsort With Workspace | 34.257 | 0.2% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 36.598 | 7.0% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 59.904 | 75.1% | No |
| 5 | ti | TimSort | 67.243 | 96.6% | Yes |
| 6 | wi | WikiSort | 67.871 | 98.4% | Yes |
| 7 | gs | Grail Sort In-Place | 73.497 | 114.9% | Yes |
| 8 | gq | GLibc Quick Sort | 81.428 | 138.1% | No |
| 9 | fb | Forsort Basic In-Place | 83.430 | 143.9% | Yes |

#### 5 Percent Disordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 20.020 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 20.207 | 0.9% | No |
| 3 | **fs** | Forsort Stable In-Place | 20.647 | 3.1% | Yes |
| 4 | ti | TimSort | 24.426 | 22.0% | Yes |
| 5 | fb | Forsort Basic In-Place | 32.984 | 64.8% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 33.598 | 67.8% | No |
| 7 | wi | WikiSort | 41.380 | 106.7% | Yes |
| 8 | gq | GLibc Quick Sort | 49.686 | 148.2% | No |
| 9 | gs | Grail Sort In-Place | 54.354 | 171.5% | Yes |

#### Ordered Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.786 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.792 | 0.8% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 0.978 | 24.4% | Yes |
| 4 | fi | Forsort Unstable In-Place | 1.473 | 87.4% | No |
| 5 | fw | Forsort With Workspace | 2.082 | 164.9% | Yes |
| 6 | wi | WikiSort | 2.414 | 207.1% | Yes |
| 7 | gs | Grail Sort In-Place | 23.056 | 2833.3% | Yes |
| 8 | gq | GLibc Quick Sort | 23.966 | 2949.1% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 25.976 | 3204.8% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.786 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 0.792 | 0.8% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 0.981 | 24.8% | Yes |
| 4 | fi | Forsort Unstable In-Place | 1.481 | 88.4% | No |
| 5 | fw | Forsort With Workspace | 2.116 | 169.2% | Yes |
| 6 | wi | WikiSort | 2.375 | 202.2% | Yes |
| 7 | gs | Grail Sort In-Place | 22.325 | 2740.3% | Yes |
| 8 | gq | GLibc Quick Sort | 24.322 | 2994.4% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 24.455 | 3011.3% | No |

#### Random Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 36.295 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 38.793 | 6.9% | No |
| 3 | **fs** | Forsort Stable In-Place | 42.454 | 17.0% | Yes |
| 4 | gs | Grail Sort In-Place | 91.618 | 152.4% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 97.703 | 169.2% | No |
| 6 | wi | WikiSort | 108.10 | 197.8% | Yes |
| 7 | ti | TimSort | 121.29 | 234.2% | Yes |
| 8 | gq | GLibc Quick Sort | 126.81 | 249.4% | No |
| 9 | fb | Forsort Basic In-Place | 146.11 | 302.6% | Yes |

#### Random Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fw** | Forsort With Workspace | 36.396 | 0.0% | Yes |
| 2 | **fi** | Forsort Unstable In-Place | 38.656 | 6.2% | No |
| 3 | **fs** | Forsort Stable In-Place | 43.581 | 19.7% | Yes |
| 4 | gs | Grail Sort In-Place | 91.645 | 151.8% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 99.441 | 173.2% | No |
| 6 | wi | WikiSort | 108.09 | 197.0% | Yes |
| 7 | ti | TimSort | 121.26 | 233.2% | Yes |
| 8 | gq | GLibc Quick Sort | 126.72 | 248.2% | No |
| 9 | fb | Forsort Basic In-Place | 146.13 | 301.5% | Yes |

#### Reversed Duplicates

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 16.041 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 20.924 | 30.4% | Yes |
| 3 | **gs** | Grail Sort In-Place | 27.421 | 70.9% | Yes |
| 4 | fw | Forsort With Workspace | 30.663 | 91.2% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 31.010 | 93.3% | No |
| 6 | fi | Forsort Unstable In-Place | 35.531 | 121.5% | No |
| 7 | fs | Forsort Stable In-Place | 36.415 | 127.0% | Yes |
| 8 | gq | GLibc Quick Sort | 50.597 | 215.4% | No |
| 9 | fb | Forsort Basic In-Place | 53.640 | 234.4% | Yes |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.064 | 0.0% | Yes |
| 2 | **fb** | Forsort Basic In-Place | 2.227 | 109.3% | Yes |
| 3 | **fs** | Forsort Stable In-Place | 5.630 | 429.1% | Yes |
| 4 | wi | WikiSort | 12.789 | 1102.0% | Yes |
| 5 | gs | Grail Sort In-Place | 22.968 | 2058.6% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 29.687 | 2690.1% | No |
| 7 | fw | Forsort With Workspace | 30.722 | 2787.4% | Yes |
| 8 | gq | GLibc Quick Sort | 31.609 | 2870.8% | No |
| 9 | fi | Forsort Unstable In-Place | 33.838 | 3080.3% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Forsort Stable In-Place) - Average: 22.631 ns/item


## Detailed Results by Dataset Size

### 1000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000010669** | 4437 | **10.669** | Yes | 1 |
| wi | WikiSort | **0.000011494** | 7000 | **11.494** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000012203** | 5039 | **12.203** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.000012366 | 4835 | 12.366 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000012846 | 8522 | 12.846 | Yes | 5 |
| ti | TimSort | 0.000013116 | 4668 | 13.116 | Yes | 6 |
| is | Insertion Sort | 0.000014551 | 9778 | 14.551 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000015313 | 6633 | 15.313 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000015372 | 5767 | 15.372 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000019315 | 6438 | 19.315 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000002007** | 1619 | **2.007** | Yes | 1 |
| fw | Forsort With Workspace | **0.000002052** | 1255 | **2.052** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000002301** | 1344 | **2.301** | Yes | 3 |
| fb | Forsort Basic In-Place | 0.000003006 | 2203 | 3.006 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.000003039 | 2189 | 3.039 | Yes | 5 |
| wi | WikiSort | 0.000003296 | 2798 | 3.296 | Yes | 6 |
| ti | TimSort | 0.000003621 | 2045 | 3.621 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000008536 | 4877 | 8.536 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000009466 | 8249 | 9.466 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000010467 | 4983 | 10.467 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000016768** | 7393 | **16.768** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000018543** | 7689 | **18.543** | Yes | 2 |
| wi | WikiSort | **0.000019029** | 8748 | **19.029** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000020656 | 9187 | 20.656 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.000021510 | 8173 | 21.510 | Yes | 5 |
| ti | TimSort | 0.000024827 | 7036 | 24.827 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000026104 | 9002 | 26.104 | Yes | 7 |
| is | Insertion Sort | 0.000026560 | 10649 | 26.560 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000030044 | 7947 | 30.044 | Yes | 9 |
| fb | Forsort Basic In-Place | 0.000030659 | 9141 | 30.659 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000006403** | 2843 | **6.403** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.000007412** | 3431 | **7.412** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000007580** | 3137 | **7.580** | Yes | 3 |
| wi | WikiSort | 0.000007685 | 5001 | 7.685 | Yes | 4 |
| ti | TimSort | 0.000008408 | 3567 | 8.408 | Yes | 5 |
| is | Insertion Sort | 0.000008483 | 6333 | 8.483 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.000009034 | 4094 | 9.034 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.000010946 | 8358 | 10.946 | Yes | 8 |
| gs | Grail Sort In-Place | 0.000011314 | 5504 | 11.314 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000014660 | 5560 | 14.660 | Yes | 10 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000000827** | 999 | **0.827** | Yes | 1 |
| is | Insertion Sort | **0.000000983** | 999 | **0.983** | Yes | 2 |
| fb | Forsort Basic In-Place | **0.000000987** | 999 | **0.987** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000000989 | 999 | 0.989 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.000001194 | 1052 | 1.194 | Yes | 5 |
| fw | Forsort With Workspace | 0.000001227 | 1028 | 1.227 | Yes | 6 |
| wi | WikiSort | 0.000002525 | 2530 | 2.525 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000009840 | 4932 | 9.840 | Yes | 8 |
| gs | Grail Sort In-Place | 0.000010008 | 5216 | 10.008 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.000010431 | 7953 | 10.431 | No | 10 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000000816** | 999 | **0.816** | Yes | 1 |
| is | Insertion Sort | **0.000000983** | 999 | **0.983** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000000989** | 999 | **0.989** | Yes | 3 |
| fb | Forsort Basic In-Place | 0.000001001 | 999 | 1.001 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.000001196 | 1052 | 1.196 | Yes | 5 |
| fw | Forsort With Workspace | 0.000001239 | 1028 | 1.239 | Yes | 6 |
| wi | WikiSort | 0.000002526 | 2530 | 2.526 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000007579 | 4790 | 7.579 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000008885 | 8192 | 8.885 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000009826 | 4932 | 9.826 | Yes | 10 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000016563** | 9578 | **16.563** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000020354** | 10215 | **20.354** | No | 2 |
| fs | Forsort Stable In-Place | **0.000023847** | 10478 | **23.847** | Yes | 3 |
| wi | WikiSort | 0.000032695 | 9514 | 32.695 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000036351 | 9401 | 36.351 | No | 5 |
| gs | Grail Sort In-Place | 0.000038502 | 10536 | 38.502 | Yes | 6 |
| ti | TimSort | 0.000043824 | 8680 | 43.824 | Yes | 7 |
| fb | Forsort Basic In-Place | 0.000048660 | 15097 | 48.660 | Yes | 8 |
| is | Insertion Sort | 0.000048942 | 10907 | 48.942 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000048985 | 8703 | 48.985 | Yes | 10 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000016543** | 9575 | **16.543** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000020401** | 10218 | **20.401** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000023645** | 10464 | **23.645** | Yes | 3 |
| wi | WikiSort | 0.000032977 | 9510 | 32.977 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000037560 | 10086 | 37.560 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000038142 | 10506 | 38.142 | Yes | 6 |
| ti | TimSort | 0.000043832 | 8680 | 43.832 | Yes | 7 |
| fb | Forsort Basic In-Place | 0.000048408 | 15120 | 48.408 | Yes | 8 |
| is | Insertion Sort | 0.000048529 | 10912 | 48.529 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000049021 | 8703 | 49.021 | Yes | 10 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| wi | WikiSort | **0.000007726** | 4601 | **7.726** | Yes | 1 |
| fw | Forsort With Workspace | **0.000008236** | 6564 | **8.236** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000009428** | 6498 | **9.428** | No | 3 |
| ti | TimSort | 0.000009586 | 4456 | 9.586 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.000010407 | 5887 | 10.407 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000013487 | 5699 | 13.487 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.000016413 | 12038 | 16.413 | No | 7 |
| fb | Forsort Basic In-Place | 0.000019726 | 8563 | 19.726 | Yes | 8 |
| is | Insertion Sort | 0.000022556 | 10978 | 22.556 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000023947 | 5237 | 23.947 | Yes | 10 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000000959** | 999 | **0.959** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000002156** | 1998 | **2.156** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000002939** | 2551 | **2.939** | Yes | 3 |
| wi | WikiSort | 0.000003530 | 3287 | 3.530 | Yes | 4 |
| fw | Forsort With Workspace | 0.000007158 | 6614 | 7.158 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.000007632 | 6407 | 7.632 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000007808 | 5112 | 7.808 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000011723 | 5044 | 11.723 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000017114 | 14222 | 17.114 | Yes | 9 |
| is | Insertion Sort | 0.000021973 | 10980 | 21.973 | Yes | 10 |

### 10000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000152752** | 65570 | **15.275** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000167564** | 69599 | **16.756** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000173895** | 67719 | **17.389** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000183627 | 119573 | 18.363 | Yes | 4 |
| ti | TimSort | 0.000194810 | 56009 | 19.481 | Yes | 5 |
| wi | WikiSort | 0.000196741 | 110229 | 19.674 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.000234643 | 79242 | 23.464 | Yes | 7 |
| is | Insertion Sort | 0.000236211 | 142148 | 23.621 | Yes | 8 |
| gs | Grail Sort In-Place | 0.000238182 | 106234 | 23.818 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000273921 | 102551 | 27.392 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000041538** | 20647 | **4.154** | Yes | 1 |
| ti | TimSort | **0.000044559** | 20070 | **4.456** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000047333** | 22033 | **4.733** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000049710 | 24636 | 4.971 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.000057857 | 32456 | 5.786 | Yes | 5 |
| wi | WikiSort | 0.000067006 | 45926 | 6.701 | Yes | 6 |
| is | Insertion Sort | 0.000073115 | 63416 | 7.312 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000114445 | 61178 | 11.444 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000123817 | 112921 | 12.382 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000143611 | 69193 | 14.361 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000206849** | 100883 | **20.685** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000222509** | 104343 | **22.251** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000240037** | 105425 | **24.004** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000285343 | 127121 | 28.534 | Yes | 4 |
| wi | WikiSort | 0.000308217 | 131331 | 30.822 | Yes | 5 |
| gs | Grail Sort In-Place | 0.000345587 | 126395 | 34.559 | Yes | 6 |
| ti | TimSort | 0.000354083 | 93930 | 35.408 | Yes | 7 |
| is | Insertion Sort | 0.000403552 | 143045 | 40.355 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000404457 | 115309 | 40.446 | Yes | 9 |
| fb | Forsort Basic In-Place | 0.000427209 | 124782 | 42.721 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000113875** | 46482 | **11.388** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000126536** | 50062 | **12.654** | Yes | 2 |
| ti | TimSort | **0.000129288** | 41460 | **12.929** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000130504 | 50985 | 13.050 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000152488 | 116696 | 15.249 | Yes | 5 |
| wi | WikiSort | 0.000153154 | 95321 | 15.315 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.000159515 | 60799 | 15.951 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000184987 | 90191 | 18.499 | Yes | 8 |
| is | Insertion Sort | 0.000192663 | 141271 | 19.266 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000224280 | 92078 | 22.428 | Yes | 10 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000007950** | 9999 | **0.795** | Yes | 1 |
| fw | Forsort With Workspace | **0.000009257** | 10049 | **0.926** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000009593** | 10091 | **0.959** | Yes | 3 |
| is | Insertion Sort | 0.000009618 | 9999 | 0.962 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.000009632 | 9999 | 0.963 | Yes | 5 |
| fs | Forsort Stable In-Place | 0.000009751 | 9999 | 0.975 | Yes | 6 |
| wi | WikiSort | 0.000028564 | 23734 | 2.856 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000107847 | 55104 | 10.785 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000117840 | 64608 | 11.784 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.000127397 | 109630 | 12.740 | No | 10 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000007855** | 9999 | **0.786** | Yes | 1 |
| fw | Forsort With Workspace | **0.000009238** | 10049 | **0.924** | Yes | 2 |
| is | Insertion Sort | **0.000009583** | 9999 | **0.958** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.000009614 | 10091 | 0.961 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.000009732 | 9999 | 0.973 | Yes | 5 |
| fs | Forsort Stable In-Place | 0.000009755 | 9999 | 0.975 | Yes | 6 |
| wi | WikiSort | 0.000025764 | 23662 | 2.576 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000092392 | 53332 | 9.239 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000115730 | 111539 | 11.573 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000117727 | 64608 | 11.773 | Yes | 10 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000185404** | 126146 | **18.540** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000225370** | 133040 | **22.537** | No | 2 |
| fs | Forsort Stable In-Place | **0.000238217** | 133561 | **23.822** | Yes | 3 |
| gs | Grail Sort In-Place | 0.000475614 | 138673 | 47.561 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000490068 | 130137 | 49.007 | No | 5 |
| wi | WikiSort | 0.000506137 | 143380 | 50.614 | Yes | 6 |
| ti | TimSort | 0.000597111 | 120355 | 59.711 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000652450 | 120413 | 65.245 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000680777 | 208374 | 68.078 | Yes | 9 |
| is | Insertion Sort | 0.001174321 | 143506 | 117.43 | Yes | 10 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.000185095** | 126139 | **18.509** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.000226158** | 133079 | **22.616** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000236383** | 133577 | **23.638** | Yes | 3 |
| gs | Grail Sort In-Place | 0.000474713 | 138630 | 47.471 | Yes | 4 |
| wi | WikiSort | 0.000502342 | 143339 | 50.234 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.000502751 | 137009 | 50.275 | Yes | 6 |
| ti | TimSort | 0.000600834 | 120355 | 60.083 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000657336 | 120413 | 65.734 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.000682100 | 208537 | 68.210 | Yes | 9 |
| is | Insertion Sort | 0.001163445 | 143513 | 116.34 | Yes | 10 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000094371** | 39936 | **9.437** | Yes | 1 |
| wi | WikiSort | **0.000099491** | 44661 | **9.949** | Yes | 2 |
| fw | Forsort With Workspace | **0.000114954** | 97316 | **11.495** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000120959 | 82496 | 12.096 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.000121062 | 93307 | 12.106 | No | 5 |
| gs | Grail Sort In-Place | 0.000143115 | 60796 | 14.311 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.000213023 | 166725 | 21.302 | No | 7 |
| fb | Forsort Basic In-Place | 0.000216448 | 86922 | 21.645 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000313827 | 70411 | 31.383 | Yes | 9 |
| is | Insertion Sort | 0.002116910 | 143610 | 211.69 | Yes | 10 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000009206** | 9999 | **0.921** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000021475** | 19998 | **2.148** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000022749** | 21910 | **2.275** | Yes | 3 |
| wi | WikiSort | 0.000044537 | 25008 | 4.454 | Yes | 4 |
| gs | Grail Sort In-Place | 0.000095130 | 57076 | 9.513 | Yes | 5 |
| fw | Forsort With Workspace | 0.000102956 | 98010 | 10.296 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.000106906 | 93366 | 10.691 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000144699 | 69008 | 14.470 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000225963 | 192779 | 22.596 | Yes | 9 |
| is | Insertion Sort | 0.002107173 | 143612 | 210.72 | Yes | 10 |

### 100000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.001778930** | 793764 | **17.789** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.001885012** | 837033 | **18.850** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.001949305** | 807830 | **19.493** | Yes | 3 |
| ti | TimSort | 0.002357887 | 678052 | 23.579 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.002374697 | 1538407 | 23.747 | Yes | 5 |
| wi | WikiSort | 0.002600019 | 1482357 | 26.000 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.002945675 | 949054 | 29.457 | Yes | 7 |
| gs | Grail Sort In-Place | 0.003129099 | 1432892 | 31.291 | Yes | 8 |
| gq | GLibc Quick Sort | 0.003289419 | 1388167 | 32.894 | Yes | 9 |
| is | Insertion Sort | 0.003793312 | 1766495 | 37.933 | Yes | 10 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000656595** | 255911 | **6.566** | Yes | 1 |
| fw | Forsort With Workspace | **0.000692749** | 295456 | **6.927** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.000745210** | 311115 | **7.452** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000762608 | 321287 | 7.626 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.000915719 | 434229 | 9.157 | Yes | 5 |
| wi | WikiSort | 0.001324750 | 949667 | 13.247 | Yes | 6 |
| gs | Grail Sort In-Place | 0.001592541 | 912868 | 15.925 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.001655133 | 1515721 | 16.551 | Yes | 8 |
| is | Insertion Sort | 0.001968696 | 1746861 | 19.687 | Yes | 9 |
| gq | GLibc Quick Sort | 0.002060893 | 1052791 | 20.609 | Yes | 10 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.002369943** | 1237300 | **23.699** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.002509973** | 1269646 | **25.100** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.002666944** | 1267521 | **26.669** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.003639950 | 1622471 | 36.399 | Yes | 4 |
| wi | WikiSort | 0.003900897 | 1718054 | 39.009 | Yes | 5 |
| gs | Grail Sort In-Place | 0.004304851 | 1631763 | 43.049 | Yes | 6 |
| ti | TimSort | 0.004318139 | 1094067 | 43.181 | Yes | 7 |
| gq | GLibc Quick Sort | 0.004801646 | 1507255 | 48.016 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.005283970 | 1537056 | 52.840 | Yes | 9 |
| is | Insertion Sort | 0.012512258 | 1768034 | 125.12 | Yes | 10 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.001382960** | 611739 | **13.830** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.001480247** | 643591 | **14.802** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.001499149** | 599708 | **14.991** | Yes | 3 |
| ti | TimSort | 0.001646669 | 521645 | 16.467 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.002009068 | 1517055 | 20.091 | Yes | 5 |
| fb | Forsort Basic In-Place | 0.002053931 | 735010 | 20.539 | Yes | 6 |
| wi | WikiSort | 0.002080903 | 1317946 | 20.809 | Yes | 7 |
| gs | Grail Sort In-Place | 0.002579098 | 1279975 | 25.791 | Yes | 8 |
| is | Insertion Sort | 0.002699944 | 1764018 | 26.999 | Yes | 9 |
| gq | GLibc Quick Sort | 0.002772315 | 1297217 | 27.723 | Yes | 10 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000079289** | 99999 | **0.793** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000088269** | 99999 | **0.883** | Yes | 2 |
| is | Insertion Sort | **0.000088573** | 99999 | **0.886** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000097324 | 99999 | 0.973 | Yes | 4 |
| fw | Forsort With Workspace | 0.000106027 | 100078 | 1.060 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.000106170 | 100167 | 1.062 | Yes | 6 |
| wi | WikiSort | 0.000262902 | 240807 | 2.629 | Yes | 7 |
| gs | Grail Sort In-Place | 0.001162827 | 616161 | 11.628 | Yes | 8 |
| gq | GLibc Quick Sort | 0.001405061 | 815024 | 14.051 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.001747035 | 1479358 | 17.470 | No | 10 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000078191** | 99999 | **0.782** | Yes | 1 |
| is | Insertion Sort | **0.000084994** | 99999 | **0.850** | Yes | 2 |
| fb | Forsort Basic In-Place | **0.000085710** | 99999 | **0.857** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.000097400 | 99999 | 0.974 | Yes | 4 |
| fw | Forsort With Workspace | 0.000105909 | 100078 | 1.059 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.000106152 | 100167 | 1.062 | Yes | 6 |
| wi | WikiSort | 0.000250058 | 240530 | 2.501 | Yes | 7 |
| gs | Grail Sort In-Place | 0.001034039 | 608786 | 10.340 | Yes | 8 |
| gq | GLibc Quick Sort | 0.001398905 | 815024 | 13.989 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.001576996 | 1524583 | 15.770 | Yes | 10 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.002277720** | 1621744 | **22.777** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.002618686** | 1649126 | **26.187** | No | 2 |
| fs | Forsort Stable In-Place | **0.002736018** | 1701468 | **27.360** | Yes | 3 |
| gs | Grail Sort In-Place | 0.005613263 | 1692380 | 56.133 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.006132836 | 1663179 | 61.328 | No | 5 |
| wi | WikiSort | 0.006244588 | 1828877 | 62.446 | Yes | 6 |
| ti | TimSort | 0.007416420 | 1531076 | 74.164 | Yes | 7 |
| gq | GLibc Quick Sort | 0.007709124 | 1536077 | 77.091 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.008710394 | 2642006 | 87.104 | Yes | 9 |
| is | Insertion Sort | 0.097658717 | 1768772 | 976.59 | Yes | 10 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.002282541** | 1621737 | **22.825** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.002602045** | 1649581 | **26.020** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.002727420** | 1701948 | **27.274** | Yes | 3 |
| gs | Grail Sort In-Place | 0.005609075 | 1692299 | 56.091 | Yes | 4 |
| wi | WikiSort | 0.006196196 | 1828536 | 61.962 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.006261659 | 1731512 | 62.617 | Yes | 6 |
| ti | TimSort | 0.007429093 | 1531074 | 74.291 | Yes | 7 |
| gq | GLibc Quick Sort | 0.007711163 | 1536078 | 77.112 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.008769205 | 2643502 | 87.692 | Yes | 9 |
| is | Insertion Sort | 0.098113846 | 1768780 | 981.14 | Yes | 10 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000985618** | 423415 | **9.856** | Yes | 1 |
| wi | WikiSort | **0.001124081** | 566125 | **11.241** | Yes | 2 |
| fw | Forsort With Workspace | **0.001434386** | 1228341 | **14.344** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.001445057 | 1049640 | 14.451 | Yes | 4 |
| gs | Grail Sort In-Place | 0.001502752 | 653665 | 15.028 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.001527859 | 1195728 | 15.279 | No | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.002205730 | 1775198 | 22.057 | No | 7 |
| fb | Forsort Basic In-Place | 0.002407025 | 874234 | 24.070 | Yes | 8 |
| gq | GLibc Quick Sort | 0.003615501 | 866156 | 36.155 | Yes | 9 |
| is | Insertion Sort | 0.243320378 | 1768916 | 2433.2 | Yes | 10 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000092458** | 99999 | **0.925** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000205189** | 199998 | **2.052** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.000239048** | 210306 | **2.390** | Yes | 3 |
| wi | WikiSort | 0.000513483 | 284046 | 5.135 | Yes | 4 |
| gs | Grail Sort In-Place | 0.001055258 | 627299 | 10.553 | Yes | 5 |
| fw | Forsort With Workspace | 0.001337821 | 1235508 | 13.378 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.001400427 | 1201428 | 14.004 | Yes | 7 |
| gq | GLibc Quick Sort | 0.001702158 | 853904 | 17.022 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.002163364 | 1935567 | 21.634 | Yes | 9 |
| is | Insertion Sort | 0.245886933 | 1768918 | 2458.9 | Yes | 10 |

### 1000000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.019163416** | 9378919 | **19.163** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.020488689** | 10065646 | **20.489** | No | 2 |
| fs | Forsort Stable In-Place | **0.020828117** | 9541829 | **20.828** | Yes | 3 |
| ti | TimSort | 0.026931705 | 7732409 | 26.932 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.029121617 | 18775482 | 29.122 | No | 5 |
| wi | WikiSort | 0.031813414 | 18763332 | 31.813 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.034386446 | 10738391 | 34.386 | Yes | 7 |
| gq | GLibc Quick Sort | 0.039627085 | 17422395 | 39.627 | Yes | 8 |
| gs | Grail Sort In-Place | 0.040058520 | 18052628 | 40.059 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.008107045** | 3357826 | **8.107** | Yes | 1 |
| fs | Forsort Stable In-Place | **0.008434186** | 3657630 | **8.434** | Yes | 2 |
| ti | TimSort | **0.008472522** | 3178270 | **8.473** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.008497932 | 3573466 | 8.498 | No | 4 |
| fb | Forsort Basic In-Place | 0.011257612 | 4900221 | 11.258 | Yes | 5 |
| wi | WikiSort | 0.017679174 | 13258987 | 17.679 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.020031550 | 18248981 | 20.032 | No | 7 |
| gs | Grail Sort In-Place | 0.024661259 | 13140131 | 24.661 | Yes | 8 |
| gq | GLibc Quick Sort | 0.026639107 | 14446341 | 26.639 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.025973321** | 14555100 | **25.973** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.027202919** | 15100948 | **27.203** | No | 2 |
| fs | Forsort Stable In-Place | **0.028830623** | 14974558 | **28.831** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.044335403 | 19738342 | 44.335 | No | 4 |
| wi | WikiSort | 0.046473560 | 21147516 | 46.474 | Yes | 5 |
| ti | TimSort | 0.049750762 | 12452072 | 49.751 | Yes | 6 |
| gs | Grail Sort In-Place | 0.052070848 | 19798612 | 52.071 | Yes | 7 |
| gq | GLibc Quick Sort | 0.057117962 | 18497245 | 57.118 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.062222154 | 17999085 | 62.222 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.015051820** | 7222003 | **15.052** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.016023132** | 7721762 | **16.023** | No | 2 |
| fs | Forsort Stable In-Place | **0.016236009** | 7266918 | **16.236** | Yes | 3 |
| ti | TimSort | 0.019032607 | 6045702 | 19.033 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.024257738 | 8208435 | 24.258 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.024672363 | 18502531 | 24.672 | No | 6 |
| wi | WikiSort | 0.026356784 | 17098338 | 26.357 | Yes | 7 |
| gq | GLibc Quick Sort | 0.033981658 | 16566537 | 33.982 | Yes | 8 |
| gs | Grail Sort In-Place | 0.034508873 | 16617516 | 34.509 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000823320** | 999999 | **0.823** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000835467** | 999999 | **0.835** | Yes | 2 |
| fi | Forsort Unstable In-Place | **0.001032374** | 1000212 | **1.032** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.001039642 | 999999 | 1.040 | Yes | 4 |
| fw | Forsort With Workspace | 0.001151456 | 1000058 | 1.151 | Yes | 5 |
| wi | WikiSort | 0.002602327 | 2596569 | 2.602 | Yes | 6 |
| gs | Grail Sort In-Place | 0.013554668 | 7043630 | 13.555 | Yes | 7 |
| gq | GLibc Quick Sort | 0.017082282 | 9884992 | 17.082 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.020062442 | 17946378 | 20.062 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000842035** | 999999 | **0.842** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.000882807** | 999999 | **0.883** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.001000915** | 999999 | **1.001** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.001045806 | 1000212 | 1.046 | Yes | 4 |
| fw | Forsort With Workspace | 0.001147869 | 1000058 | 1.148 | Yes | 5 |
| wi | WikiSort | 0.002533910 | 2595342 | 2.534 | Yes | 6 |
| gs | Grail Sort In-Place | 0.012645737 | 7019410 | 12.646 | Yes | 7 |
| gq | GLibc Quick Sort | 0.017093656 | 9884992 | 17.094 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.018470486 | 18196618 | 18.470 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.025646217** | 19344423 | **25.646** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.029347805** | 20001793 | **29.348** | No | 2 |
| fs | Forsort Stable In-Place | **0.030155750** | 20136370 | **30.156** | Yes | 3 |
| gs | Grail Sort In-Place | 0.065398538 | 20162205 | 65.399 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.073489670 | 20262071 | 73.490 | No | 5 |
| wi | WikiSort | 0.074782356 | 22373179 | 74.782 | Yes | 6 |
| ti | TimSort | 0.088694587 | 18299291 | 88.695 | Yes | 7 |
| gq | GLibc Quick Sort | 0.092146498 | 18672439 | 92.146 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.106266426 | 31919011 | 106.27 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.025601732** | 19344483 | **25.602** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.029466759** | 20006177 | **29.467** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.030167176** | 20144097 | **30.167** | Yes | 3 |
| gs | Grail Sort In-Place | 0.065176848 | 20161687 | 65.177 | Yes | 4 |
| wi | WikiSort | 0.074389976 | 22370389 | 74.390 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.074916287 | 20938662 | 74.916 | Yes | 6 |
| ti | TimSort | 0.088720540 | 18299314 | 88.721 | Yes | 7 |
| gq | GLibc Quick Sort | 0.092130698 | 18672439 | 92.131 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.105957559 | 31933798 | 105.96 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.010314809** | 4402853 | **10.315** | Yes | 1 |
| wi | WikiSort | **0.012299724** | 6207660 | **12.300** | Yes | 2 |
| gs | Grail Sort In-Place | **0.017386303** | 7770801 | **17.386** | Yes | 3 |
| fs | Forsort Stable In-Place | 0.018580167 | 13911789 | 18.580 | Yes | 4 |
| fw | Forsort With Workspace | 0.018784212 | 16348383 | 18.784 | Yes | 5 |
| fi | Forsort Unstable In-Place | 0.019543367 | 15717552 | 19.543 | No | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.026172660 | 21892802 | 26.173 | No | 7 |
| fb | Forsort Basic In-Place | 0.028012811 | 8712753 | 28.013 | Yes | 8 |
| gq | GLibc Quick Sort | 0.036315567 | 10249892 | 36.316 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.001058713** | 999999 | **1.059** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.002096470** | 1999998 | **2.096** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.002508083** | 2088913 | **2.508** | Yes | 3 |
| wi | WikiSort | 0.006065014 | 3273489 | 6.065 | Yes | 4 |
| gs | Grail Sort In-Place | 0.013230791 | 7551070 | 13.231 | Yes | 5 |
| fw | Forsort With Workspace | 0.018072363 | 16420327 | 18.072 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.019020390 | 15784214 | 19.020 | Yes | 7 |
| gq | GLibc Quick Sort | 0.019797313 | 10066432 | 19.797 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.026054586 | 24025703 | 26.055 | Yes | 9 |

### 10000000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.207427254** | 108136956 | **20.743** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.221293916** | 115617274 | **22.129** | No | 2 |
| fs | Forsort Stable In-Place | **0.225134624** | 111448176 | **22.513** | Yes | 3 |
| ti | TimSort | 0.309353580 | 80925243 | 30.935 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.343359787 | 221669671 | 34.336 | No | 5 |
| wi | WikiSort | 0.393791366 | 222839482 | 39.379 | Yes | 6 |
| fb | Forsort Basic In-Place | 0.396755191 | 119004161 | 39.676 | Yes | 7 |
| gq | GLibc Quick Sort | 0.478988276 | 208005685 | 47.899 | Yes | 8 |
| gs | Grail Sort In-Place | 0.493310994 | 215571686 | 49.331 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.090973151** | 29069681 | **9.097** | Yes | 1 |
| fw | Forsort With Workspace | **0.091738614** | 42850992 | **9.174** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.094945570** | 45672892 | **9.495** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.095427426 | 44731145 | 9.543 | No | 4 |
| fb | Forsort Basic In-Place | 0.131149290 | 52344010 | 13.115 | Yes | 5 |
| wi | WikiSort | 0.227842050 | 161734923 | 22.784 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.233829431 | 215110068 | 23.383 | No | 7 |
| gq | GLibc Quick Sort | 0.327420037 | 178609052 | 32.742 | Yes | 8 |
| gs | Grail Sort In-Place | 0.332001863 | 166962457 | 33.200 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.286638305** | 166155567 | **28.664** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.300758452** | 174363379 | **30.076** | No | 2 |
| fs | Forsort Stable In-Place | **0.314948811** | 171186457 | **31.495** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.521032147 | 232464629 | 52.103 | No | 4 |
| wi | WikiSort | 0.568817018 | 249329827 | 56.882 | Yes | 5 |
| ti | TimSort | 0.584222610 | 139283095 | 58.422 | Yes | 6 |
| gs | Grail Sort In-Place | 0.620847348 | 232215059 | 62.085 | Yes | 7 |
| gq | GLibc Quick Sort | 0.690500288 | 218008909 | 69.050 | Yes | 8 |
| fb | Forsort Basic In-Place | 0.718578560 | 205430665 | 71.858 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.163603943** | 83711153 | **16.360** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.173395372** | 88606072 | **17.340** | No | 2 |
| fs | Forsort Stable In-Place | **0.174509268** | 86683679 | **17.451** | Yes | 3 |
| ti | TimSort | 0.213320203 | 59828908 | 21.332 | Yes | 4 |
| fb | Forsort Basic In-Place | 0.280431050 | 89624605 | 28.043 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.290364632 | 218637153 | 29.036 | No | 6 |
| wi | WikiSort | 0.331360048 | 204435712 | 33.136 | Yes | 7 |
| gq | GLibc Quick Sort | 0.409348233 | 199438755 | 40.935 | Yes | 8 |
| gs | Grail Sort In-Place | 0.431371921 | 201499966 | 43.137 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fb | Forsort Basic In-Place | **0.008005439** | 9999999 | **0.801** | Yes | 1 |
| ti | TimSort | **0.008083803** | 9999999 | **0.808** | Yes | 2 |
| fw | Forsort With Workspace | **0.009158089** | 10000089 | **0.916** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.009316000 | 10000304 | 0.932 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.009841889 | 9999999 | 0.984 | Yes | 5 |
| wi | WikiSort | 0.020928711 | 20127952 | 2.093 | Yes | 6 |
| gs | Grail Sort In-Place | 0.170277717 | 79282160 | 17.028 | Yes | 7 |
| gq | GLibc Quick Sort | 0.200381412 | 114434624 | 20.038 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.219305391 | 209616775 | 21.931 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.008030856** | 9999999 | **0.803** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.008038721** | 9999999 | **0.804** | Yes | 2 |
| fw | Forsort With Workspace | **0.009082028** | 10000089 | **0.908** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.009353298 | 10000304 | 0.935 | Yes | 4 |
| fs | Forsort Stable In-Place | 0.009942179 | 9999999 | 0.994 | Yes | 5 |
| wi | WikiSort | 0.020395639 | 20122509 | 2.040 | Yes | 6 |
| gs | Grail Sort In-Place | 0.164972749 | 79189929 | 16.497 | Yes | 7 |
| gq | GLibc Quick Sort | 0.200827225 | 114434624 | 20.083 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.208888187 | 211572877 | 20.889 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.290592420** | 225429372 | **29.059** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.332753702** | 232277822 | **33.275** | No | 2 |
| fs | Forsort Stable In-Place | **0.336778259** | 235467084 | **33.678** | Yes | 3 |
| gs | Grail Sort In-Place | 0.779831996 | 236958802 | 77.983 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.856509726 | 238426327 | 85.651 | No | 5 |
| wi | WikiSort | 0.915883656 | 266877152 | 91.588 | Yes | 6 |
| ti | TimSort | 1.049124157 | 213810303 | 104.91 | Yes | 7 |
| gq | GLibc Quick Sort | 1.096587015 | 220066877 | 109.66 | Yes | 8 |
| fb | Forsort Basic In-Place | 1.243011421 | 373451538 | 124.30 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **0.293111952** | 225429382 | **29.311** | Yes | 1 |
| fi | Forsort Unstable In-Place | **0.330000697** | 232321330 | **33.000** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.339439458** | 235553320 | **33.944** | Yes | 3 |
| gs | Grail Sort In-Place | 0.779063544 | 236954845 | 77.906 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.870931728 | 245146777 | 87.093 | Yes | 5 |
| wi | WikiSort | 0.919381912 | 266849832 | 91.938 | Yes | 6 |
| ti | TimSort | 1.050459084 | 213810880 | 105.05 | Yes | 7 |
| gq | GLibc Quick Sort | 1.092386182 | 220066878 | 109.24 | Yes | 8 |
| fb | Forsort Basic In-Place | 1.248617548 | 373600354 | 124.86 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.119832743** | 39878005 | **11.983** | Yes | 1 |
| wi | WikiSort | **0.154961954** | 68281610 | **15.496** | Yes | 2 |
| gs | Grail Sort In-Place | **0.201964860** | 84028558 | **20.196** | Yes | 3 |
| fw | Forsort With Workspace | 0.224815546 | 197266392 | 22.482 | Yes | 4 |
| fi | Forsort Unstable In-Place | 0.240367175 | 190717993 | 24.037 | No | 5 |
| fs | Forsort Stable In-Place | 0.244501067 | 177389869 | 24.450 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.304685565 | 264938580 | 30.469 | No | 7 |
| fb | Forsort Basic In-Place | 0.322745722 | 87261055 | 32.275 | Yes | 8 |
| gq | GLibc Quick Sort | 0.432054839 | 120242863 | 43.205 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.009786140** | 9999999 | **0.979** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.020509149** | 19999998 | **2.051** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.027745473** | 20867892 | **2.775** | Yes | 3 |
| wi | WikiSort | 0.069511696 | 21498750 | 6.951 | Yes | 4 |
| gs | Grail Sort In-Place | 0.161042160 | 81979307 | 16.104 | Yes | 5 |
| fw | Forsort With Workspace | 0.219546673 | 197985849 | 21.955 | Yes | 6 |
| fi | Forsort Unstable In-Place | 0.243104683 | 191369358 | 24.310 | Yes | 7 |
| gq | GLibc Quick Sort | 0.249777290 | 118788160 | 24.978 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.310016405 | 290683459 | 31.002 | Yes | 9 |

### 100000000 Items

#### 10 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **2.530893564** | 1190163424 | **25.309** | Yes | 1 |
| fi | Forsort Unstable In-Place | **2.546713125** | 1271696181 | **25.467** | No | 2 |
| fs | Forsort Stable In-Place | **2.656512948** | 1225557917 | **26.565** | Yes | 3 |
| ti | TimSort | 3.548974833 | 885349200 | 35.490 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 3.969756048 | 2556114832 | 39.698 | No | 5 |
| fb | Forsort Basic In-Place | 4.667011102 | 1303198586 | 46.670 | Yes | 6 |
| wi | WikiSort | 4.854466001 | 2589528798 | 48.545 | Yes | 7 |
| gq | GLibc Quick Sort | 5.789545085 | 2425087751 | 57.895 | Yes | 8 |
| gs | Grail Sort In-Place | 6.015076110 | 2494360434 | 60.151 | Yes | 9 |

#### 1 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **1.072557498** | 324457797 | **10.726** | Yes | 1 |
| fi | Forsort Unstable In-Place | **1.226233482** | 550340981 | **12.262** | No | 2 |
| fs | Forsort Stable In-Place | **1.246258164** | 547276621 | **12.463** | Yes | 3 |
| fw | Forsort With Workspace | 1.291136746 | 515983732 | 12.911 | Yes | 4 |
| fb | Forsort Basic In-Place | 1.551855373 | 550843510 | 15.519 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 2.714225867 | 2503124446 | 27.142 | No | 6 |
| wi | WikiSort | 3.046304073 | 1990181595 | 30.463 | Yes | 7 |
| gq | GLibc Quick Sort | 3.983222307 | 2138192604 | 39.832 | Yes | 8 |
| gs | Grail Sort In-Place | 4.326902303 | 2022530075 | 43.269 | Yes | 9 |

#### 25 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fi | Forsort Unstable In-Place | **3.420504731** | 1935889512 | **34.205** | No | 1 |
| fw | Forsort With Workspace | **3.425709885** | 1862655030 | **34.257** | Yes | 2 |
| fs | Forsort Stable In-Place | **3.659809780** | 1924373356 | **36.598** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 5.990400107 | 2673076661 | 59.904 | No | 4 |
| ti | TimSort | 6.724278612 | 1534831256 | 67.243 | Yes | 5 |
| wi | WikiSort | 6.787143739 | 2854508858 | 67.871 | Yes | 6 |
| gs | Grail Sort In-Place | 7.349677664 | 2634592105 | 73.497 | Yes | 7 |
| gq | GLibc Quick Sort | 8.142842687 | 2514385833 | 81.428 | Yes | 8 |
| fb | Forsort Basic In-Place | 8.342982036 | 2304584977 | 83.430 | Yes | 9 |

#### 5 Percent Disordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **2.001956525** | 925918048 | **20.020** | Yes | 1 |
| fi | Forsort Unstable In-Place | **2.020743975** | 982170604 | **20.207** | No | 2 |
| fs | Forsort Stable In-Place | **2.064685960** | 974518742 | **20.647** | Yes | 3 |
| ti | TimSort | 2.442566222 | 659631595 | 24.426 | Yes | 4 |
| fb | Forsort Basic In-Place | 3.298381317 | 967963232 | 32.984 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 3.359759096 | 2520850711 | 33.598 | No | 6 |
| wi | WikiSort | 4.138039596 | 2411282096 | 41.380 | Yes | 7 |
| gq | GLibc Quick Sort | 4.968551217 | 2341899008 | 49.686 | Yes | 8 |
| gs | Grail Sort In-Place | 5.435377744 | 2358494172 | 54.354 | Yes | 9 |

#### Ordered Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.078552610** | 99999999 | **0.786** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.079188564** | 99999999 | **0.792** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.097827504** | 99999999 | **0.978** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.147268071 | 100000429 | 1.473 | Yes | 4 |
| fw | Forsort With Workspace | 0.208217315 | 100000101 | 2.082 | Yes | 5 |
| wi | WikiSort | 0.241426721 | 223294335 | 2.414 | Yes | 6 |
| gs | Grail Sort In-Place | 2.305556910 | 840542710 | 23.056 | Yes | 7 |
| gq | GLibc Quick Sort | 2.396573075 | 1314447104 | 23.966 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 2.597615824 | 2472882034 | 25.976 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.078627547** | 99999999 | **0.786** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.079182811** | 99999999 | **0.792** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.098091316** | 99999999 | **0.981** | Yes | 3 |
| fi | Forsort Unstable In-Place | 0.148088338 | 100000429 | 1.481 | Yes | 4 |
| fw | Forsort With Workspace | 0.211584476 | 100000101 | 2.116 | Yes | 5 |
| wi | WikiSort | 0.237512367 | 223275953 | 2.375 | Yes | 6 |
| gs | Grail Sort In-Place | 2.232538003 | 840185031 | 22.325 | Yes | 7 |
| gq | GLibc Quick Sort | 2.432246432 | 1314447104 | 24.322 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 2.445536555 | 2525165841 | 24.455 | Yes | 9 |

#### Random Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **3.629485644** | 2621029714 | **36.295** | Yes | 1 |
| fi | Forsort Unstable In-Place | **3.879304971** | 2634697879 | **38.793** | No | 2 |
| fs | Forsort Stable In-Place | **4.245442846** | 2742131801 | **42.454** | Yes | 3 |
| gs | Grail Sort In-Place | 9.161776953 | 2655245492 | 91.618 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 9.770257411 | 2749060430 | 97.703 | No | 5 |
| wi | WikiSort | 10.810110215 | 3064238700 | 108.10 | Yes | 6 |
| ti | TimSort | 12.128933030 | 2435412938 | 121.29 | Yes | 7 |
| gq | GLibc Quick Sort | 12.680917931 | 2532644916 | 126.81 | Yes | 8 |
| fb | Forsort Basic In-Place | 14.610756403 | 4273768630 | 146.11 | Yes | 9 |

#### Random Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fw | Forsort With Workspace | **3.639563970** | 2621029170 | **36.396** | Yes | 1 |
| fi | Forsort Unstable In-Place | **3.865571791** | 2635143637 | **38.656** | Yes | 2 |
| fs | Forsort Stable In-Place | **4.358097904** | 2743841495 | **43.581** | Yes | 3 |
| gs | Grail Sort In-Place | 9.164548158 | 2655129547 | 91.645 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 9.944102438 | 2820363361 | 99.441 | Yes | 5 |
| wi | WikiSort | 10.809300069 | 3063957721 | 108.09 | Yes | 6 |
| ti | TimSort | 12.125734075 | 2435415718 | 121.26 | Yes | 7 |
| gq | GLibc Quick Sort | 12.671754261 | 2532644915 | 126.72 | Yes | 8 |
| fb | Forsort Basic In-Place | 14.613546595 | 4275253950 | 146.13 | Yes | 9 |

#### Reversed Duplicates

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **1.604083224** | 418702981 | **16.041** | Yes | 1 |
| wi | WikiSort | **2.092436747** | 744007323 | **20.924** | Yes | 2 |
| gs | Grail Sort In-Place | **2.742132355** | 916681093 | **27.421** | Yes | 3 |
| fw | Forsort With Workspace | 3.066291528 | 2232942602 | 30.663 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 3.101003496 | 2805414470 | 31.010 | No | 5 |
| fi | Forsort Unstable In-Place | 3.553149719 | 2171397613 | 35.531 | No | 6 |
| fs | Forsort Stable In-Place | 3.641450785 | 2027882293 | 36.415 | Yes | 7 |
| gq | GLibc Quick Sort | 5.059735799 | 1363129113 | 50.597 | Yes | 8 |
| fb | Forsort Basic In-Place | 5.363953906 | 871236419 | 53.640 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.106418345** | 99999999 | **1.064** | Yes | 1 |
| fb | Forsort Basic In-Place | **0.222671659** | 199999998 | **2.227** | Yes | 2 |
| fs | Forsort Stable In-Place | **0.563042267** | 208655473 | **5.630** | Yes | 3 |
| wi | WikiSort | 1.278887250 | 266513829 | 12.789 | Yes | 4 |
| gs | Grail Sort In-Place | 2.296826958 | 896694624 | 22.968 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 2.968740131 | 2921036489 | 29.687 | Yes | 6 |
| fw | Forsort With Workspace | 3.072165532 | 2240136721 | 30.722 | Yes | 7 |
| gq | GLibc Quick Sort | 3.160901496 | 1351335168 | 31.609 | Yes | 8 |
| fi | Forsort Unstable In-Place | 3.383844351 | 2176935091 | 33.838 | Yes | 9 |


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
