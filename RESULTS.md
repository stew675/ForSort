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
| fb | Basic Forsort In-Place | Stable |
| fi | Adaptive Forsort In-Place | Unstable |
| fiw | Adaptive Forsort Stable (with workspace) | Stable |
| fs | Stable Forsort In-Place | Stable |
| gs | Grail Sort In-Place | Stable |
| gq | GLibc Quick Sort | Unstable |
| nq | Bentley/McIlroy Quick Sort | Unstable |
| ti | TimSort | Stable |
| wi | WikiSort | Stable |
| is | Insertion Sort | Stable |


## Test Variants

| Variant | Description |
|---------|-------------|
| random | Random data |
| ordered | Fully ordered data |
| reversed | Fully reversed data |
| unique | All unique values |
| ordered_unique | Ordered unique values |
| reversed_unique | Reversed unique values |
| 1_percent_disorder | 99% ordered, 1% disorder |
| 5_percent_disorder | 95% ordered, 5% disorder |
| 25_percent_disorder | 75% ordered, 25% disorder |
| limited_range | Limited key range |


## Summary by Dataset Size and Test Variant

### 1 Percent Disorder

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------||-----------||-----------||-----------||-----------||-----------|
| ti | *****14.589** | *****6.091** | *****7.329** | *****8.640** | *****9.201** | *****11.037** |
| fiw | ****8.649** | ****5.756** | ****10.213** | ****8.638** | ****10.981** | ****13.655** |
| fs | ***14.210** | ***6.821** | ***7.798** | ***8.620** | ***10.428** | ***13.605** |
| fi | 17.370 | 6.659 | 7.568 | 9.122 | 10.595 | 13.473 |
| fb | 12.059 | 7.760 | 9.687 | 11.825 | 13.354 | 16.035 |
| is | 3.850 | 9.142 | 22.811 | - | - | - |
| wi | 11.609 | 8.647 | 12.930 | 17.711 | 26.015 | 31.408 |
| nq | 13.350 | 13.572 | 17.978 | 21.077 | 24.373 | 28.421 |
| gs | 25.879 | 14.155 | 18.239 | 28.079 | 36.029 | 43.574 |
| gq | 24.669 | 14.976 | 36.290 | 27.088 | 75.441 | 39.634 |

### 25 Percent Disorder

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------||-----------||-----------||-----------||-----------||-----------|
| fiw | *****49.028** | *****23.823** | *****23.892** | *****26.924** | *****30.903** | *****35.118** |
| fi | ****36.388** | ****43.507** | ****25.762** | ****27.340** | ****31.983** | ****35.988** |
| fs | ***71.718** | ***40.696** | ***26.682** | ***29.259** | ***33.904** | ***37.925** |
| nq | 40.659 | 38.495 | 36.444 | 43.420 | 51.039 | 58.401 |
| wi | 55.068 | 32.686 | 40.454 | 46.348 | 59.677 | 67.843 |
| ti | 60.768 | 41.828 | 47.581 | 54.444 | 59.552 | 66.685 |
| gs | 61.358 | 38.319 | 43.289 | 53.380 | 65.231 | 73.542 |
| gq | 55.608 | 45.310 | 50.491 | 55.857 | 67.492 | 77.170 |
| fb | 73.898 | 48.750 | 55.965 | 62.090 | 72.274 | 84.131 |
| is | 31.149 | 48.691 | 128.86 | - | - | - |

### 5 Percent Disorder

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------||-----------||-----------||-----------||-----------||-----------|
| fiw | *****24.579** | *****13.701** | *****14.638** | *****15.577** | *****17.483** | *****20.963** |
| fi | ****21.559** | ****15.431** | ****15.120** | ****16.008** | ****18.416** | ****21.816** |
| fs | ***30.349** | ***17.837** | ***15.209** | ***15.943** | ***18.644** | ***22.018** |
| is | 12.759 | 22.640 | 30.058 | - | - | - |
| ti | 28.589 | 17.482 | 19.565 | 21.276 | 21.720 | 25.976 |
| nq | 15.160 | 16.774 | 21.555 | 24.956 | 29.444 | 34.003 |
| fb | 28.509 | 31.362 | 21.319 | 24.228 | 28.145 | 33.413 |
| wi | 27.469 | 18.270 | 22.030 | 26.061 | 36.535 | 42.324 |
| gs | 33.699 | 18.998 | 25.228 | 35.400 | 46.298 | 54.600 |
| gq | 31.479 | 42.002 | 30.688 | 34.837 | 40.382 | 48.441 |

### Limited Range

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------||-----------||-----------||-----------||-----------||-----------|
| fiw | *****30.449** | *****20.511** | *****23.369** | *****26.397** | *****32.766** | *****37.897** |
| fi | ****57.058** | ****24.687** | ****26.258** | ****29.959** | ****35.202** | ****41.048** |
| fs | ***64.068** | ***26.449** | ***28.695** | ***30.791** | ***36.220** | ***45.130** |
| gs | 48.369 | 47.962 | 57.877 | 66.408 | 80.513 | 90.302 |
| nq | 70.337 | 51.393 | 66.028 | 73.672 | 82.963 | 94.024 |
| wi | 67.888 | 50.832 | 61.888 | 72.899 | 93.286 | 106.72 |
| gq | 50.078 | 67.514 | 82.579 | 93.026 | 106.58 | 122.15 |
| ti | 56.558 | 66.206 | 80.761 | 97.309 | 106.20 | 120.96 |
| fb | 107.44 | 78.325 | 94.488 | 105.38 | 124.11 | 147.69 |
| is | 51.568 | 120.09 | 996.60 | - | - | - |

### Ordered

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------||-----------||-----------||-----------||-----------||-----------|
| fs | *****2.170** | *****0.849** | *****0.783** | *****0.808** | *****1.223** | *****0.806** |
| ti | ****2.610** | ****0.962** | ****0.826** | ****0.847** | ****0.804** | ****0.791** |
| is | ***1.260** | ***1.112** | ***1.098** | - | - | - |
| fb | 2.100 | 1.023 | 0.975 | 0.975 | 1.195 | 1.000 |
| fiw | 7.520 | 1.196 | 1.393 | 1.383 | 1.187 | 1.899 |
| fi | 7.839 | 8.294 | 1.113 | 1.046 | 1.241 | 1.520 |
| wi | 8.560 | 3.537 | 2.713 | 2.614 | 2.441 | 2.437 |
| gs | 22.299 | 10.021 | 11.006 | 14.603 | 20.282 | 22.149 |
| gq | 13.949 | 21.353 | 16.381 | 17.775 | 20.125 | 23.032 |
| nq | 17.710 | 13.211 | 17.965 | 21.480 | 22.079 | 26.529 |

### Ordered Unique

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------||-----------||-----------||-----------||-----------||-----------|
| is | *****1.279** | *****1.120** | *****1.004** | - | - | - |
| fs | ****2.450** | ****0.847** | ****0.782** | ****1.194** | ****1.082** | ****0.805** |
| ti | ***3.809** | ***0.921** | ***0.832** | ***0.785** | ***0.789** | ***0.792** |
| fb | 2.410 | 1.718 | 1.007 | 1.214 | 0.985 | 1.000 |
| fiw | 5.440 | 1.166 | 1.286 | 1.377 | 1.032 | 1.899 |
| fi | 7.740 | 1.163 | 1.087 | 1.013 | 1.043 | 1.497 |
| wi | 11.300 | 3.468 | 2.737 | 2.749 | 2.416 | 2.433 |
| gs | 16.840 | 10.855 | 10.561 | 14.658 | 20.496 | 22.028 |
| gq | 13.290 | 13.898 | 15.941 | 18.029 | 20.133 | 23.045 |
| nq | 17.989 | 20.987 | 20.002 | 19.262 | 22.026 | 26.585 |

### Random

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------||-----------||-----------||-----------||-----------||-----------|
| fiw | *****45.638** | *****34.249** | *****23.171** | *****26.374** | *****31.270** | *****37.832** |
| fs | ****41.308** | ****27.021** | ****27.346** | ****30.648** | ****36.372** | ****44.700** |
| fi | ***55.958** | ***24.676** | ***26.104** | ***29.532** | ***35.633** | ***40.936** |
| gs | 82.317 | 47.289 | 60.681 | 64.381 | 79.611 | 89.745 |
| nq | 47.519 | 49.391 | 83.013 | 82.824 | 84.274 | 95.600 |
| wi | 72.487 | 58.540 | 72.147 | 73.413 | 93.738 | 106.35 |
| ti | 53.308 | 63.154 | 77.428 | 90.495 | 106.64 | 120.77 |
| gq | 55.308 | 68.236 | 83.401 | 93.862 | 106.56 | 121.49 |
| fb | 62.247 | 73.992 | 91.150 | 104.46 | 124.40 | 145.85 |
| is | 53.268 | 136.85 | 1019.4 | - | - | - |

### Reversed

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------||-----------||-----------||-----------||-----------||-----------|
| ti | *****4.399** | *****1.005** | *****2.398** | *****2.882** | *****5.078** | *****8.681** |
| wi | ****15.249** | ****5.685** | ****6.969** | ****6.799** | ****11.517** | ****13.505** |
| fs | ***9.800** | ***3.194** | ***4.313** | ***5.622** | ***18.330** | ***32.299** |
| fb | 5.060 | 3.711 | 4.015 | 8.926 | 21.658 | 46.793 |
| gs | 27.459 | 10.138 | 11.089 | 15.427 | 20.718 | 24.228 |
| fiw | 24.159 | 11.633 | 14.996 | 18.613 | 25.081 | 33.473 |
| fi | 31.499 | 12.523 | 14.338 | 18.530 | 28.606 | 37.928 |
| nq | 33.209 | 24.265 | 23.908 | 29.923 | 33.885 | 33.724 |
| gq | 15.370 | 16.611 | 19.805 | 83.922 | 99.686 | 115.88 |
| is | 25.629 | 244.26 | 2391.8 | - | - | - |

### Reversed Unique

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------||-----------||-----------||-----------||-----------||-----------|
| ti | *****3.990** | *****1.096** | *****0.995** | *****1.852** | *****1.455** | *****1.028** |
| fb | ****4.960** | ****2.166** | ****2.006** | ****2.021** | ****2.205** | ****2.307** |
| fs | ***13.420** | ***4.713** | ***2.855** | ***2.955** | ***4.389** | ***5.349** |
| wi | 15.349 | 5.617 | 5.545 | 6.270 | 10.977 | 12.650 |
| gs | 26.959 | 17.301 | 10.598 | 17.415 | 20.417 | 23.480 |
| fiw | 25.030 | 11.628 | 13.973 | 19.861 | 27.781 | 33.034 |
| fi | 31.309 | 12.286 | 14.366 | 19.235 | 29.252 | 37.442 |
| gq | 23.950 | 26.873 | 19.424 | 21.209 | 25.876 | 29.721 |
| nq | 33.059 | 25.814 | 22.720 | 26.942 | 34.200 | 33.801 |
| is | 25.659 | 212.22 | 2490.6 | - | - | - |

### Unique

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------||-----------||-----------||-----------||-----------||-----------|
| fiw | *****45.668** | *****21.974** | *****23.131** | *****26.218** | *****31.393** | *****37.851** |
| fs | ****62.757** | ****26.691** | ****28.286** | ****30.142** | ****36.181** | ****44.662** |
| fi | ***56.438** | ***41.572** | ***26.072** | ***31.279** | ***35.125** | ***41.001** |
| gs | 83.937 | 47.683 | 57.458 | 65.402 | 81.184 | 89.639 |
| nq | 69.058 | 49.558 | 67.904 | 75.439 | 84.057 | 95.595 |
| wi | 48.768 | 75.870 | 68.390 | 72.492 | 93.105 | 106.56 |
| ti | 86.737 | 64.736 | 79.512 | 90.166 | 106.17 | 120.77 |
| fb | 68.188 | 81.124 | 96.444 | 106.71 | 125.29 | 146.66 |
| gq | 86.397 | 208.72 | 120.36 | 91.828 | 106.58 | 122.86 |
| is | 51.778 | 121.49 | 1013.4 | - | - | - |


## Cross-Category Analysis

### Win Count by Algorithm

| Rank | Sort Type | Name | Wins | Top 3 | Win Rate |
|------|-----------|------|------|-------|----------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 27 | 33 | 45.0% |
| 2 | **ti** | TimSort | 20 | 27 | 33.3% |
| 3 | **fs** | Stable Forsort In-Place | 7 | 49 | 11.7% |
| 4 | **is** | Insertion Sort | 5 | 8 | 8.3% |
| 5 | **fi** | Adaptive Forsort In-Place | 1 | 31 | 1.7% |

### Recommendations by Use Case

- **Best Stable Sort:** fs (Stable Forsort In-Place) - Avg: 20.002 ns/item (1M-100M items)
- **Best Unstable Sort:** fi (Adaptive Forsort In-Place) - Avg: 22.760 ns/item (1M-100M items)
- **Best for Nearly-Sorted Data:** fiw (Adaptive Forsort Stable (with workspace)) - Avg: 9.967 ns/item
- **Best for Random Data:** fiw (Adaptive Forsort Stable (with workspace)) - Avg: 33.089 ns/item


## Performance Rankings

### 1000 Items

#### 1 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 3.850 | 0.0% | Yes |
| 2 | **fiw** | Adaptive Forsort Stable (with workspace) | 8.649 | 124.6% | Yes |
| 3 | **wi** | WikiSort | 11.609 | 201.5% | Yes |
| 4 | fb | Basic Forsort In-Place | 12.059 | 213.2% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 13.350 | 246.8% | No |
| 6 | fs | Stable Forsort In-Place | 14.210 | 269.1% | Yes |
| 7 | ti | TimSort | 14.589 | 278.9% | Yes |
| 8 | fi | Adaptive Forsort In-Place | 17.370 | 351.2% | No |
| 9 | gq | GLibc Quick Sort | 24.669 | 540.8% | No |
| 10 | gs | Grail Sort In-Place | 25.879 | 572.2% | Yes |

#### 25 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 31.149 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 36.388 | 16.8% | No |
| 3 | **nq** | Bentley/McIlroy Quick Sort | 40.659 | 30.5% | No |
| 4 | fiw | Adaptive Forsort Stable (with workspace) | 49.028 | 57.4% | Yes |
| 5 | wi | WikiSort | 55.068 | 76.8% | Yes |
| 6 | gq | GLibc Quick Sort | 55.608 | 78.5% | No |
| 7 | ti | TimSort | 60.768 | 95.1% | Yes |
| 8 | gs | Grail Sort In-Place | 61.358 | 97.0% | Yes |
| 9 | fs | Stable Forsort In-Place | 71.718 | 130.2% | Yes |
| 10 | fb | Basic Forsort In-Place | 73.898 | 137.2% | Yes |

#### 5 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 12.759 | 0.0% | Yes |
| 2 | **nq** | Bentley/McIlroy Quick Sort | 15.160 | 18.8% | No |
| 3 | **fi** | Adaptive Forsort In-Place | 21.559 | 69.0% | No |
| 4 | fiw | Adaptive Forsort Stable (with workspace) | 24.579 | 92.6% | Yes |
| 5 | wi | WikiSort | 27.469 | 115.3% | Yes |
| 6 | fb | Basic Forsort In-Place | 28.509 | 123.4% | Yes |
| 7 | ti | TimSort | 28.589 | 124.1% | Yes |
| 8 | fs | Stable Forsort In-Place | 30.349 | 137.9% | Yes |
| 9 | gq | GLibc Quick Sort | 31.479 | 146.7% | No |
| 10 | gs | Grail Sort In-Place | 33.699 | 164.1% | Yes |

#### Limited Range

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 30.449 | 0.0% | Yes |
| 2 | **gs** | Grail Sort In-Place | 48.369 | 58.9% | Yes |
| 3 | **gq** | GLibc Quick Sort | 50.078 | 64.5% | No |
| 4 | is | Insertion Sort | 51.568 | 69.4% | Yes |
| 5 | ti | TimSort | 56.558 | 85.7% | Yes |
| 6 | fi | Adaptive Forsort In-Place | 57.058 | 87.4% | No |
| 7 | fs | Stable Forsort In-Place | 64.068 | 110.4% | Yes |
| 8 | wi | WikiSort | 67.888 | 123.0% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort | 70.337 | 131.0% | No |
| 10 | fb | Basic Forsort In-Place | 107.44 | 252.8% | Yes |

#### Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 1.260 | 0.0% | Yes |
| 2 | **fb** | Basic Forsort In-Place | 2.100 | 66.7% | Yes |
| 3 | **fs** | Stable Forsort In-Place | 2.170 | 72.2% | Yes |
| 4 | ti | TimSort | 2.610 | 107.1% | Yes |
| 5 | fiw | Adaptive Forsort Stable (with workspace) | 7.520 | 496.8% | Yes |
| 6 | fi | Adaptive Forsort In-Place | 7.839 | 522.1% | No |
| 7 | wi | WikiSort | 8.560 | 579.4% | Yes |
| 8 | gq | GLibc Quick Sort | 13.949 | 1007.1% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 17.710 | 1305.6% | No |
| 10 | gs | Grail Sort In-Place | 22.299 | 1669.8% | Yes |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **is** | Insertion Sort | 1.279 | 0.0% | Yes |
| 2 | **fb** | Basic Forsort In-Place | 2.410 | 88.4% | Yes |
| 3 | **fs** | Stable Forsort In-Place | 2.450 | 91.6% | Yes |
| 4 | ti | TimSort | 3.809 | 197.8% | Yes |
| 5 | fiw | Adaptive Forsort Stable (with workspace) | 5.440 | 325.3% | Yes |
| 6 | fi | Adaptive Forsort In-Place | 7.740 | 505.2% | No |
| 7 | wi | WikiSort | 11.300 | 783.5% | Yes |
| 8 | gq | GLibc Quick Sort | 13.290 | 939.1% | No |
| 9 | gs | Grail Sort In-Place | 16.840 | 1216.7% | Yes |
| 10 | nq | Bentley/McIlroy Quick Sort | 17.989 | 1306.5% | No |

#### Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fs** | Stable Forsort In-Place | 41.308 | 0.0% | Yes |
| 2 | **fiw** | Adaptive Forsort Stable (with workspace) | 45.638 | 10.5% | Yes |
| 3 | **nq** | Bentley/McIlroy Quick Sort | 47.519 | 15.0% | No |
| 4 | is | Insertion Sort | 53.268 | 29.0% | Yes |
| 5 | ti | TimSort | 53.308 | 29.1% | Yes |
| 6 | gq | GLibc Quick Sort | 55.308 | 33.9% | No |
| 7 | fi | Adaptive Forsort In-Place | 55.958 | 35.5% | No |
| 8 | fb | Basic Forsort In-Place | 62.247 | 50.7% | Yes |
| 9 | wi | WikiSort | 72.487 | 75.5% | Yes |
| 10 | gs | Grail Sort In-Place | 82.317 | 99.3% | Yes |

#### Reversed

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 4.399 | 0.0% | Yes |
| 2 | **fb** | Basic Forsort In-Place | 5.060 | 15.0% | Yes |
| 3 | **fs** | Stable Forsort In-Place | 9.800 | 122.8% | Yes |
| 4 | wi | WikiSort | 15.249 | 246.6% | Yes |
| 5 | gq | GLibc Quick Sort | 15.370 | 249.4% | No |
| 6 | fiw | Adaptive Forsort Stable (with workspace) | 24.159 | 449.2% | Yes |
| 7 | is | Insertion Sort | 25.629 | 482.6% | Yes |
| 8 | gs | Grail Sort In-Place | 27.459 | 524.2% | Yes |
| 9 | fi | Adaptive Forsort In-Place | 31.499 | 616.0% | No |
| 10 | nq | Bentley/McIlroy Quick Sort | 33.209 | 654.9% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 3.990 | 0.0% | Yes |
| 2 | **fb** | Basic Forsort In-Place | 4.960 | 24.3% | Yes |
| 3 | **fs** | Stable Forsort In-Place | 13.420 | 236.3% | Yes |
| 4 | wi | WikiSort | 15.349 | 284.7% | Yes |
| 5 | gq | GLibc Quick Sort | 23.950 | 500.3% | No |
| 6 | fiw | Adaptive Forsort Stable (with workspace) | 25.030 | 527.3% | Yes |
| 7 | is | Insertion Sort | 25.659 | 543.1% | Yes |
| 8 | gs | Grail Sort In-Place | 26.959 | 575.7% | Yes |
| 9 | fi | Adaptive Forsort In-Place | 31.309 | 684.7% | No |
| 10 | nq | Bentley/McIlroy Quick Sort | 33.059 | 728.5% | No |

#### Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 45.668 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 48.768 | 6.8% | Yes |
| 3 | **is** | Insertion Sort | 51.778 | 13.4% | Yes |
| 4 | fi | Adaptive Forsort In-Place | 56.438 | 23.6% | No |
| 5 | fs | Stable Forsort In-Place | 62.757 | 37.4% | Yes |
| 6 | fb | Basic Forsort In-Place | 68.188 | 49.3% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 69.058 | 51.2% | No |
| 8 | gs | Grail Sort In-Place | 83.937 | 83.8% | Yes |
| 9 | gq | GLibc Quick Sort | 86.397 | 89.2% | No |
| 10 | ti | TimSort | 86.737 | 89.9% | Yes |

#### Overall Winner (Average Across All Variants)

**Winner:** is (Insertion Sort) - Average: 25.820 ns/item

### 10000 Items

#### 1 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 5.756 | 0.0% | Yes |
| 2 | **ti** | TimSort | 6.091 | 5.8% | Yes |
| 3 | **fi** | Adaptive Forsort In-Place | 6.659 | 15.7% | No |
| 4 | fs | Stable Forsort In-Place | 6.821 | 18.5% | Yes |
| 5 | fb | Basic Forsort In-Place | 7.760 | 34.8% | Yes |
| 6 | wi | WikiSort | 8.647 | 50.2% | Yes |
| 7 | is | Insertion Sort | 9.142 | 58.8% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 13.572 | 135.8% | No |
| 9 | gs | Grail Sort In-Place | 14.155 | 145.9% | Yes |
| 10 | gq | GLibc Quick Sort | 14.976 | 160.2% | No |

#### 25 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 23.823 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 32.686 | 37.2% | Yes |
| 3 | **gs** | Grail Sort In-Place | 38.319 | 60.8% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 38.495 | 61.6% | No |
| 5 | fs | Stable Forsort In-Place | 40.696 | 70.8% | Yes |
| 6 | ti | TimSort | 41.828 | 75.6% | Yes |
| 7 | fi | Adaptive Forsort In-Place | 43.507 | 82.6% | No |
| 8 | gq | GLibc Quick Sort | 45.310 | 90.2% | No |
| 9 | is | Insertion Sort | 48.691 | 104.4% | Yes |
| 10 | fb | Basic Forsort In-Place | 48.750 | 104.6% | Yes |

#### 5 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 13.701 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 15.431 | 12.6% | No |
| 3 | **nq** | Bentley/McIlroy Quick Sort | 16.774 | 22.4% | No |
| 4 | ti | TimSort | 17.482 | 27.6% | Yes |
| 5 | fs | Stable Forsort In-Place | 17.837 | 30.2% | Yes |
| 6 | wi | WikiSort | 18.270 | 33.3% | Yes |
| 7 | gs | Grail Sort In-Place | 18.998 | 38.7% | Yes |
| 8 | is | Insertion Sort | 22.640 | 65.2% | Yes |
| 9 | fb | Basic Forsort In-Place | 31.362 | 128.9% | Yes |
| 10 | gq | GLibc Quick Sort | 42.002 | 206.6% | No |

#### Limited Range

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 20.511 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 24.687 | 20.4% | No |
| 3 | **fs** | Stable Forsort In-Place | 26.449 | 29.0% | Yes |
| 4 | gs | Grail Sort In-Place | 47.962 | 133.8% | Yes |
| 5 | wi | WikiSort | 50.832 | 147.8% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 51.393 | 150.6% | No |
| 7 | ti | TimSort | 66.206 | 222.8% | Yes |
| 8 | gq | GLibc Quick Sort | 67.514 | 229.2% | No |
| 9 | fb | Basic Forsort In-Place | 78.325 | 281.9% | Yes |
| 10 | is | Insertion Sort | 120.09 | 485.5% | Yes |

#### Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fs** | Stable Forsort In-Place | 0.849 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.962 | 13.3% | Yes |
| 3 | **fb** | Basic Forsort In-Place | 1.023 | 20.5% | Yes |
| 4 | is | Insertion Sort | 1.112 | 31.0% | Yes |
| 5 | fiw | Adaptive Forsort Stable (with workspace) | 1.196 | 40.9% | Yes |
| 6 | wi | WikiSort | 3.537 | 316.6% | Yes |
| 7 | fi | Adaptive Forsort In-Place | 8.294 | 876.9% | No |
| 8 | gs | Grail Sort In-Place | 10.021 | 1080.3% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort | 13.211 | 1456.1% | No |
| 10 | gq | GLibc Quick Sort | 21.353 | 2415.1% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fs** | Stable Forsort In-Place | 0.847 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.921 | 8.7% | Yes |
| 3 | **is** | Insertion Sort | 1.120 | 32.2% | Yes |
| 4 | fi | Adaptive Forsort In-Place | 1.163 | 37.3% | No |
| 5 | fiw | Adaptive Forsort Stable (with workspace) | 1.166 | 37.7% | Yes |
| 6 | fb | Basic Forsort In-Place | 1.718 | 102.8% | Yes |
| 7 | wi | WikiSort | 3.468 | 309.4% | Yes |
| 8 | gs | Grail Sort In-Place | 10.855 | 1181.6% | Yes |
| 9 | gq | GLibc Quick Sort | 13.898 | 1540.9% | No |
| 10 | nq | Bentley/McIlroy Quick Sort | 20.987 | 2377.8% | No |

#### Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fi** | Adaptive Forsort In-Place | 24.676 | 0.0% | No |
| 2 | **fs** | Stable Forsort In-Place | 27.021 | 9.5% | Yes |
| 3 | **fiw** | Adaptive Forsort Stable (with workspace) | 34.249 | 38.8% | Yes |
| 4 | gs | Grail Sort In-Place | 47.289 | 91.6% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 49.391 | 100.2% | No |
| 6 | wi | WikiSort | 58.540 | 137.2% | Yes |
| 7 | ti | TimSort | 63.154 | 155.9% | Yes |
| 8 | gq | GLibc Quick Sort | 68.236 | 176.5% | No |
| 9 | fb | Basic Forsort In-Place | 73.992 | 199.9% | Yes |
| 10 | is | Insertion Sort | 136.85 | 454.6% | Yes |

#### Reversed

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.005 | 0.0% | Yes |
| 2 | **fs** | Stable Forsort In-Place | 3.194 | 217.8% | Yes |
| 3 | **fb** | Basic Forsort In-Place | 3.711 | 269.3% | Yes |
| 4 | wi | WikiSort | 5.685 | 465.7% | Yes |
| 5 | gs | Grail Sort In-Place | 10.138 | 908.8% | Yes |
| 6 | fiw | Adaptive Forsort Stable (with workspace) | 11.633 | 1057.5% | Yes |
| 7 | fi | Adaptive Forsort In-Place | 12.523 | 1146.1% | No |
| 8 | gq | GLibc Quick Sort | 16.611 | 1552.8% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 24.265 | 2314.4% | No |
| 10 | is | Insertion Sort | 244.26 | 24205.0% | Yes |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.096 | 0.0% | Yes |
| 2 | **fb** | Basic Forsort In-Place | 2.166 | 97.6% | Yes |
| 3 | **fs** | Stable Forsort In-Place | 4.713 | 330.0% | Yes |
| 4 | wi | WikiSort | 5.617 | 412.5% | Yes |
| 5 | fiw | Adaptive Forsort Stable (with workspace) | 11.628 | 960.9% | Yes |
| 6 | fi | Adaptive Forsort In-Place | 12.286 | 1021.0% | No |
| 7 | gs | Grail Sort In-Place | 17.301 | 1478.6% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 25.814 | 2255.3% | No |
| 9 | gq | GLibc Quick Sort | 26.873 | 2351.9% | No |
| 10 | is | Insertion Sort | 212.22 | 19263.1% | Yes |

#### Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 21.974 | 0.0% | Yes |
| 2 | **fs** | Stable Forsort In-Place | 26.691 | 21.5% | Yes |
| 3 | **fi** | Adaptive Forsort In-Place | 41.572 | 89.2% | No |
| 4 | gs | Grail Sort In-Place | 47.683 | 117.0% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 49.558 | 125.5% | No |
| 6 | ti | TimSort | 64.736 | 194.6% | Yes |
| 7 | wi | WikiSort | 75.870 | 245.3% | Yes |
| 8 | fb | Basic Forsort In-Place | 81.124 | 269.2% | Yes |
| 9 | is | Insertion Sort | 121.49 | 452.9% | Yes |
| 10 | gq | GLibc Quick Sort | 208.72 | 849.9% | No |

#### Overall Winner (Average Across All Variants)

**Winner:** fiw (Adaptive Forsort Stable (with workspace)) - Average: 14.564 ns/item

### 100000 Items

#### 1 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 7.329 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 7.568 | 3.3% | No |
| 3 | **fs** | Stable Forsort In-Place | 7.798 | 6.4% | Yes |
| 4 | fb | Basic Forsort In-Place | 9.687 | 32.2% | Yes |
| 5 | fiw | Adaptive Forsort Stable (with workspace) | 10.213 | 39.4% | Yes |
| 6 | wi | WikiSort | 12.930 | 76.4% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 17.978 | 145.3% | No |
| 8 | gs | Grail Sort In-Place | 18.239 | 148.9% | Yes |
| 9 | is | Insertion Sort | 22.811 | 211.2% | Yes |
| 10 | gq | GLibc Quick Sort | 36.290 | 395.2% | No |

#### 25 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 23.892 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 25.762 | 7.8% | No |
| 3 | **fs** | Stable Forsort In-Place | 26.682 | 11.7% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 36.444 | 52.5% | No |
| 5 | wi | WikiSort | 40.454 | 69.3% | Yes |
| 6 | gs | Grail Sort In-Place | 43.289 | 81.2% | Yes |
| 7 | ti | TimSort | 47.581 | 99.2% | Yes |
| 8 | gq | GLibc Quick Sort | 50.491 | 111.3% | No |
| 9 | fb | Basic Forsort In-Place | 55.965 | 134.2% | Yes |
| 10 | is | Insertion Sort | 128.86 | 439.3% | Yes |

#### 5 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 14.638 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 15.120 | 3.3% | No |
| 3 | **fs** | Stable Forsort In-Place | 15.209 | 3.9% | Yes |
| 4 | ti | TimSort | 19.565 | 33.7% | Yes |
| 5 | fb | Basic Forsort In-Place | 21.319 | 45.6% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 21.555 | 47.3% | No |
| 7 | wi | WikiSort | 22.030 | 50.5% | Yes |
| 8 | gs | Grail Sort In-Place | 25.228 | 72.3% | Yes |
| 9 | is | Insertion Sort | 30.058 | 105.3% | Yes |
| 10 | gq | GLibc Quick Sort | 30.688 | 109.6% | No |

#### Limited Range

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 23.369 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 26.258 | 12.4% | No |
| 3 | **fs** | Stable Forsort In-Place | 28.695 | 22.8% | Yes |
| 4 | gs | Grail Sort In-Place | 57.877 | 147.7% | Yes |
| 5 | wi | WikiSort | 61.888 | 164.8% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 66.028 | 182.5% | No |
| 7 | ti | TimSort | 80.761 | 245.6% | Yes |
| 8 | gq | GLibc Quick Sort | 82.579 | 253.4% | No |
| 9 | fb | Basic Forsort In-Place | 94.488 | 304.3% | Yes |
| 10 | is | Insertion Sort | 996.60 | 4164.6% | Yes |

#### Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fs** | Stable Forsort In-Place | 0.783 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.826 | 5.5% | Yes |
| 3 | **fb** | Basic Forsort In-Place | 0.975 | 24.5% | Yes |
| 4 | is | Insertion Sort | 1.098 | 40.2% | Yes |
| 5 | fi | Adaptive Forsort In-Place | 1.113 | 42.1% | No |
| 6 | fiw | Adaptive Forsort Stable (with workspace) | 1.393 | 77.9% | Yes |
| 7 | wi | WikiSort | 2.713 | 246.5% | Yes |
| 8 | gs | Grail Sort In-Place | 11.006 | 1305.6% | Yes |
| 9 | gq | GLibc Quick Sort | 16.381 | 1992.1% | No |
| 10 | nq | Bentley/McIlroy Quick Sort | 17.965 | 2194.4% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fs** | Stable Forsort In-Place | 0.782 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.832 | 6.4% | Yes |
| 3 | **is** | Insertion Sort | 1.004 | 28.4% | Yes |
| 4 | fb | Basic Forsort In-Place | 1.007 | 28.8% | Yes |
| 5 | fi | Adaptive Forsort In-Place | 1.087 | 39.0% | No |
| 6 | fiw | Adaptive Forsort Stable (with workspace) | 1.286 | 64.5% | Yes |
| 7 | wi | WikiSort | 2.737 | 250.0% | Yes |
| 8 | gs | Grail Sort In-Place | 10.561 | 1250.5% | Yes |
| 9 | gq | GLibc Quick Sort | 15.941 | 1938.5% | No |
| 10 | nq | Bentley/McIlroy Quick Sort | 20.002 | 2457.8% | No |

#### Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 23.171 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 26.104 | 12.7% | No |
| 3 | **fs** | Stable Forsort In-Place | 27.346 | 18.0% | Yes |
| 4 | gs | Grail Sort In-Place | 60.681 | 161.9% | Yes |
| 5 | wi | WikiSort | 72.147 | 211.4% | Yes |
| 6 | ti | TimSort | 77.428 | 234.2% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 83.013 | 258.3% | No |
| 8 | gq | GLibc Quick Sort | 83.401 | 259.9% | No |
| 9 | fb | Basic Forsort In-Place | 91.150 | 293.4% | Yes |
| 10 | is | Insertion Sort | 1019.4 | 4299.5% | Yes |

#### Reversed

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 2.398 | 0.0% | Yes |
| 2 | **fb** | Basic Forsort In-Place | 4.015 | 67.4% | Yes |
| 3 | **fs** | Stable Forsort In-Place | 4.313 | 79.9% | Yes |
| 4 | wi | WikiSort | 6.969 | 190.6% | Yes |
| 5 | gs | Grail Sort In-Place | 11.089 | 362.4% | Yes |
| 6 | fi | Adaptive Forsort In-Place | 14.338 | 497.9% | No |
| 7 | fiw | Adaptive Forsort Stable (with workspace) | 14.996 | 525.4% | Yes |
| 8 | gq | GLibc Quick Sort | 19.805 | 725.9% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 23.908 | 897.0% | No |
| 10 | is | Insertion Sort | 2391.8 | 99639.5% | Yes |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.995 | 0.0% | Yes |
| 2 | **fb** | Basic Forsort In-Place | 2.006 | 101.6% | Yes |
| 3 | **fs** | Stable Forsort In-Place | 2.855 | 186.9% | Yes |
| 4 | wi | WikiSort | 5.545 | 457.3% | Yes |
| 5 | gs | Grail Sort In-Place | 10.598 | 965.1% | Yes |
| 6 | fiw | Adaptive Forsort Stable (with workspace) | 13.973 | 1304.3% | Yes |
| 7 | fi | Adaptive Forsort In-Place | 14.366 | 1343.8% | No |
| 8 | gq | GLibc Quick Sort | 19.424 | 1852.2% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 22.720 | 2183.4% | No |
| 10 | is | Insertion Sort | 2490.6 | 250215.9% | Yes |

#### Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 23.131 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 26.072 | 12.7% | No |
| 3 | **fs** | Stable Forsort In-Place | 28.286 | 22.3% | Yes |
| 4 | gs | Grail Sort In-Place | 57.458 | 148.4% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 67.904 | 193.6% | No |
| 6 | wi | WikiSort | 68.390 | 195.7% | Yes |
| 7 | ti | TimSort | 79.512 | 243.7% | Yes |
| 8 | fb | Basic Forsort In-Place | 96.444 | 316.9% | Yes |
| 9 | gq | GLibc Quick Sort | 120.36 | 420.4% | No |
| 10 | is | Insertion Sort | 1013.4 | 4281.3% | Yes |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Stable Forsort In-Place) - Average: 14.275 ns/item

### 1000000 Items

#### 1 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fs** | Stable Forsort In-Place | 8.620 | 0.0% | Yes |
| 2 | **fiw** | Adaptive Forsort Stable (with workspace) | 8.638 | 0.2% | Yes |
| 3 | **ti** | TimSort | 8.640 | 0.2% | Yes |
| 4 | fi | Adaptive Forsort In-Place | 9.122 | 5.8% | No |
| 5 | fb | Basic Forsort In-Place | 11.825 | 37.2% | Yes |
| 6 | wi | WikiSort | 17.711 | 105.5% | Yes |
| 7 | nq | Bentley/McIlroy Quick Sort | 21.077 | 144.5% | No |
| 8 | gq | GLibc Quick Sort | 27.088 | 214.2% | No |
| 9 | gs | Grail Sort In-Place | 28.079 | 225.7% | Yes |

#### 25 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 26.924 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 27.340 | 1.5% | No |
| 3 | **fs** | Stable Forsort In-Place | 29.259 | 8.7% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 43.420 | 61.3% | No |
| 5 | wi | WikiSort | 46.348 | 72.1% | Yes |
| 6 | gs | Grail Sort In-Place | 53.380 | 98.3% | Yes |
| 7 | ti | TimSort | 54.444 | 102.2% | Yes |
| 8 | gq | GLibc Quick Sort | 55.857 | 107.5% | No |
| 9 | fb | Basic Forsort In-Place | 62.090 | 130.6% | Yes |

#### 5 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 15.577 | 0.0% | Yes |
| 2 | **fs** | Stable Forsort In-Place | 15.943 | 2.3% | Yes |
| 3 | **fi** | Adaptive Forsort In-Place | 16.008 | 2.8% | No |
| 4 | ti | TimSort | 21.276 | 36.6% | Yes |
| 5 | fb | Basic Forsort In-Place | 24.228 | 55.5% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 24.956 | 60.2% | No |
| 7 | wi | WikiSort | 26.061 | 67.3% | Yes |
| 8 | gq | GLibc Quick Sort | 34.837 | 123.6% | No |
| 9 | gs | Grail Sort In-Place | 35.400 | 127.3% | Yes |

#### Limited Range

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 26.397 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 29.959 | 13.5% | No |
| 3 | **fs** | Stable Forsort In-Place | 30.791 | 16.6% | Yes |
| 4 | gs | Grail Sort In-Place | 66.408 | 151.6% | Yes |
| 5 | wi | WikiSort | 72.899 | 176.2% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 73.672 | 179.1% | No |
| 7 | gq | GLibc Quick Sort | 93.026 | 252.4% | No |
| 8 | ti | TimSort | 97.309 | 268.6% | Yes |
| 9 | fb | Basic Forsort In-Place | 105.38 | 299.2% | Yes |

#### Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fs** | Stable Forsort In-Place | 0.808 | 0.0% | Yes |
| 2 | **ti** | TimSort | 0.847 | 4.8% | Yes |
| 3 | **fb** | Basic Forsort In-Place | 0.975 | 20.7% | Yes |
| 4 | fi | Adaptive Forsort In-Place | 1.046 | 29.5% | No |
| 5 | fiw | Adaptive Forsort Stable (with workspace) | 1.383 | 71.2% | Yes |
| 6 | wi | WikiSort | 2.614 | 223.5% | Yes |
| 7 | gs | Grail Sort In-Place | 14.603 | 1707.3% | Yes |
| 8 | gq | GLibc Quick Sort | 17.775 | 2099.9% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 21.480 | 2558.4% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.785 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 1.013 | 29.0% | No |
| 3 | **fs** | Stable Forsort In-Place | 1.194 | 52.1% | Yes |
| 4 | fb | Basic Forsort In-Place | 1.214 | 54.6% | Yes |
| 5 | fiw | Adaptive Forsort Stable (with workspace) | 1.377 | 75.4% | Yes |
| 6 | wi | WikiSort | 2.749 | 250.2% | Yes |
| 7 | gs | Grail Sort In-Place | 14.658 | 1767.3% | Yes |
| 8 | gq | GLibc Quick Sort | 18.029 | 2196.7% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 19.262 | 2353.8% | No |

#### Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 26.374 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 29.532 | 12.0% | No |
| 3 | **fs** | Stable Forsort In-Place | 30.648 | 16.2% | Yes |
| 4 | gs | Grail Sort In-Place | 64.381 | 144.1% | Yes |
| 5 | wi | WikiSort | 73.413 | 178.4% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 82.824 | 214.0% | No |
| 7 | ti | TimSort | 90.495 | 243.1% | Yes |
| 8 | gq | GLibc Quick Sort | 93.862 | 255.9% | No |
| 9 | fb | Basic Forsort In-Place | 104.46 | 296.1% | Yes |

#### Reversed

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 2.882 | 0.0% | Yes |
| 2 | **fs** | Stable Forsort In-Place | 5.622 | 95.1% | Yes |
| 3 | **wi** | WikiSort | 6.799 | 135.9% | Yes |
| 4 | fb | Basic Forsort In-Place | 8.926 | 209.7% | Yes |
| 5 | gs | Grail Sort In-Place | 15.427 | 435.3% | Yes |
| 6 | fi | Adaptive Forsort In-Place | 18.530 | 543.0% | No |
| 7 | fiw | Adaptive Forsort Stable (with workspace) | 18.613 | 545.8% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 29.923 | 938.3% | No |
| 9 | gq | GLibc Quick Sort | 83.922 | 2811.9% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.852 | 0.0% | Yes |
| 2 | **fb** | Basic Forsort In-Place | 2.021 | 9.1% | Yes |
| 3 | **fs** | Stable Forsort In-Place | 2.955 | 59.6% | Yes |
| 4 | wi | WikiSort | 6.270 | 238.6% | Yes |
| 5 | gs | Grail Sort In-Place | 17.415 | 840.3% | Yes |
| 6 | fi | Adaptive Forsort In-Place | 19.235 | 938.6% | No |
| 7 | fiw | Adaptive Forsort Stable (with workspace) | 19.861 | 972.4% | Yes |
| 8 | gq | GLibc Quick Sort | 21.209 | 1045.2% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 26.942 | 1354.8% | No |

#### Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 26.218 | 0.0% | Yes |
| 2 | **fs** | Stable Forsort In-Place | 30.142 | 15.0% | Yes |
| 3 | **fi** | Adaptive Forsort In-Place | 31.279 | 19.3% | No |
| 4 | gs | Grail Sort In-Place | 65.402 | 149.5% | Yes |
| 5 | wi | WikiSort | 72.492 | 176.5% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 75.439 | 187.7% | No |
| 7 | ti | TimSort | 90.166 | 243.9% | Yes |
| 8 | gq | GLibc Quick Sort | 91.828 | 250.2% | No |
| 9 | fb | Basic Forsort In-Place | 106.71 | 307.0% | Yes |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Stable Forsort In-Place) - Average: 15.598 ns/item

### 10000000 Items

#### 1 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 9.201 | 0.0% | Yes |
| 2 | **fs** | Stable Forsort In-Place | 10.428 | 13.3% | Yes |
| 3 | **fi** | Adaptive Forsort In-Place | 10.595 | 15.2% | No |
| 4 | fiw | Adaptive Forsort Stable (with workspace) | 10.981 | 19.3% | Yes |
| 5 | fb | Basic Forsort In-Place | 13.354 | 45.1% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 24.373 | 164.9% | No |
| 7 | wi | WikiSort | 26.015 | 182.7% | Yes |
| 8 | gs | Grail Sort In-Place | 36.029 | 291.6% | Yes |
| 9 | gq | GLibc Quick Sort | 75.441 | 719.9% | No |

#### 25 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 30.903 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 31.983 | 3.5% | No |
| 3 | **fs** | Stable Forsort In-Place | 33.904 | 9.7% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 51.039 | 65.2% | No |
| 5 | ti | TimSort | 59.552 | 92.7% | Yes |
| 6 | wi | WikiSort | 59.677 | 93.1% | Yes |
| 7 | gs | Grail Sort In-Place | 65.231 | 111.1% | Yes |
| 8 | gq | GLibc Quick Sort | 67.492 | 118.4% | No |
| 9 | fb | Basic Forsort In-Place | 72.274 | 133.9% | Yes |

#### 5 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 17.483 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 18.416 | 5.3% | No |
| 3 | **fs** | Stable Forsort In-Place | 18.644 | 6.6% | Yes |
| 4 | ti | TimSort | 21.720 | 24.2% | Yes |
| 5 | fb | Basic Forsort In-Place | 28.145 | 61.0% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 29.444 | 68.4% | No |
| 7 | wi | WikiSort | 36.535 | 109.0% | Yes |
| 8 | gq | GLibc Quick Sort | 40.382 | 131.0% | No |
| 9 | gs | Grail Sort In-Place | 46.298 | 164.8% | Yes |

#### Limited Range

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 32.766 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 35.202 | 7.4% | No |
| 3 | **fs** | Stable Forsort In-Place | 36.220 | 10.5% | Yes |
| 4 | gs | Grail Sort In-Place | 80.513 | 145.7% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 82.963 | 153.2% | No |
| 6 | wi | WikiSort | 93.286 | 184.7% | Yes |
| 7 | ti | TimSort | 106.20 | 224.1% | Yes |
| 8 | gq | GLibc Quick Sort | 106.58 | 225.3% | No |
| 9 | fb | Basic Forsort In-Place | 124.11 | 278.8% | Yes |

#### Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.804 | 0.0% | Yes |
| 2 | **fiw** | Adaptive Forsort Stable (with workspace) | 1.187 | 47.6% | Yes |
| 3 | **fb** | Basic Forsort In-Place | 1.195 | 48.6% | Yes |
| 4 | fs | Stable Forsort In-Place | 1.223 | 52.1% | Yes |
| 5 | fi | Adaptive Forsort In-Place | 1.241 | 54.4% | No |
| 6 | wi | WikiSort | 2.441 | 203.6% | Yes |
| 7 | gq | GLibc Quick Sort | 20.125 | 2403.1% | No |
| 8 | gs | Grail Sort In-Place | 20.282 | 2422.6% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort | 22.079 | 2646.1% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.789 | 0.0% | Yes |
| 2 | **fb** | Basic Forsort In-Place | 0.985 | 24.8% | Yes |
| 3 | **fiw** | Adaptive Forsort Stable (with workspace) | 1.032 | 30.8% | Yes |
| 4 | fi | Adaptive Forsort In-Place | 1.043 | 32.2% | No |
| 5 | fs | Stable Forsort In-Place | 1.082 | 37.1% | Yes |
| 6 | wi | WikiSort | 2.416 | 206.2% | Yes |
| 7 | gq | GLibc Quick Sort | 20.133 | 2451.7% | No |
| 8 | gs | Grail Sort In-Place | 20.496 | 2497.7% | Yes |
| 9 | nq | Bentley/McIlroy Quick Sort | 22.026 | 2691.6% | No |

#### Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 31.270 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 35.633 | 14.0% | No |
| 3 | **fs** | Stable Forsort In-Place | 36.372 | 16.3% | Yes |
| 4 | gs | Grail Sort In-Place | 79.611 | 154.6% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 84.274 | 169.5% | No |
| 6 | wi | WikiSort | 93.738 | 199.8% | Yes |
| 7 | gq | GLibc Quick Sort | 106.56 | 240.8% | No |
| 8 | ti | TimSort | 106.64 | 241.0% | Yes |
| 9 | fb | Basic Forsort In-Place | 124.40 | 297.8% | Yes |

#### Reversed

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 5.078 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 11.517 | 126.8% | Yes |
| 3 | **fs** | Stable Forsort In-Place | 18.330 | 261.0% | Yes |
| 4 | gs | Grail Sort In-Place | 20.718 | 308.0% | Yes |
| 5 | fb | Basic Forsort In-Place | 21.658 | 326.5% | Yes |
| 6 | fiw | Adaptive Forsort Stable (with workspace) | 25.081 | 393.9% | Yes |
| 7 | fi | Adaptive Forsort In-Place | 28.606 | 463.3% | No |
| 8 | nq | Bentley/McIlroy Quick Sort | 33.885 | 567.3% | No |
| 9 | gq | GLibc Quick Sort | 99.686 | 1863.1% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.455 | 0.0% | Yes |
| 2 | **fb** | Basic Forsort In-Place | 2.205 | 51.5% | Yes |
| 3 | **fs** | Stable Forsort In-Place | 4.389 | 201.6% | Yes |
| 4 | wi | WikiSort | 10.977 | 654.4% | Yes |
| 5 | gs | Grail Sort In-Place | 20.417 | 1303.2% | Yes |
| 6 | gq | GLibc Quick Sort | 25.876 | 1678.4% | No |
| 7 | fiw | Adaptive Forsort Stable (with workspace) | 27.781 | 1809.3% | Yes |
| 8 | fi | Adaptive Forsort In-Place | 29.252 | 1910.4% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 34.200 | 2250.5% | No |

#### Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 31.393 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 35.125 | 11.9% | No |
| 3 | **fs** | Stable Forsort In-Place | 36.181 | 15.3% | Yes |
| 4 | gs | Grail Sort In-Place | 81.184 | 158.6% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 84.057 | 167.8% | No |
| 6 | wi | WikiSort | 93.105 | 196.6% | Yes |
| 7 | ti | TimSort | 106.17 | 238.2% | Yes |
| 8 | gq | GLibc Quick Sort | 106.58 | 239.5% | No |
| 9 | fb | Basic Forsort In-Place | 125.29 | 299.1% | Yes |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Stable Forsort In-Place) - Average: 19.677 ns/item

### 100000000 Items

#### 1 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 11.037 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 13.473 | 22.1% | No |
| 3 | **fs** | Stable Forsort In-Place | 13.605 | 23.3% | Yes |
| 4 | fiw | Adaptive Forsort Stable (with workspace) | 13.655 | 23.7% | Yes |
| 5 | fb | Basic Forsort In-Place | 16.035 | 45.3% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 28.421 | 157.5% | No |
| 7 | wi | WikiSort | 31.408 | 184.6% | Yes |
| 8 | gq | GLibc Quick Sort | 39.634 | 259.1% | No |
| 9 | gs | Grail Sort In-Place | 43.574 | 294.8% | Yes |

#### 25 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 35.118 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 35.988 | 2.5% | No |
| 3 | **fs** | Stable Forsort In-Place | 37.925 | 8.0% | Yes |
| 4 | nq | Bentley/McIlroy Quick Sort | 58.401 | 66.3% | No |
| 5 | ti | TimSort | 66.685 | 89.9% | Yes |
| 6 | wi | WikiSort | 67.843 | 93.2% | Yes |
| 7 | gs | Grail Sort In-Place | 73.542 | 109.4% | Yes |
| 8 | gq | GLibc Quick Sort | 77.170 | 119.7% | No |
| 9 | fb | Basic Forsort In-Place | 84.131 | 139.6% | Yes |

#### 5 Percent Disorder

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 20.963 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 21.816 | 4.1% | No |
| 3 | **fs** | Stable Forsort In-Place | 22.018 | 5.0% | Yes |
| 4 | ti | TimSort | 25.976 | 23.9% | Yes |
| 5 | fb | Basic Forsort In-Place | 33.413 | 59.4% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 34.003 | 62.2% | No |
| 7 | wi | WikiSort | 42.324 | 101.9% | Yes |
| 8 | gq | GLibc Quick Sort | 48.441 | 131.1% | No |
| 9 | gs | Grail Sort In-Place | 54.600 | 160.5% | Yes |

#### Limited Range

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 37.897 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 41.048 | 8.3% | No |
| 3 | **fs** | Stable Forsort In-Place | 45.130 | 19.1% | Yes |
| 4 | gs | Grail Sort In-Place | 90.302 | 138.3% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 94.024 | 148.1% | No |
| 6 | wi | WikiSort | 106.72 | 181.6% | Yes |
| 7 | ti | TimSort | 120.96 | 219.2% | Yes |
| 8 | gq | GLibc Quick Sort | 122.15 | 222.3% | No |
| 9 | fb | Basic Forsort In-Place | 147.69 | 289.7% | Yes |

#### Ordered

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.791 | 0.0% | Yes |
| 2 | **fs** | Stable Forsort In-Place | 0.806 | 1.9% | Yes |
| 3 | **fb** | Basic Forsort In-Place | 1.000 | 26.4% | Yes |
| 4 | fi | Adaptive Forsort In-Place | 1.520 | 92.2% | No |
| 5 | fiw | Adaptive Forsort Stable (with workspace) | 1.899 | 140.1% | Yes |
| 6 | wi | WikiSort | 2.437 | 208.1% | Yes |
| 7 | gs | Grail Sort In-Place | 22.149 | 2700.1% | Yes |
| 8 | gq | GLibc Quick Sort | 23.032 | 2811.8% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 26.529 | 3253.9% | No |

#### Ordered Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 0.792 | 0.0% | Yes |
| 2 | **fs** | Stable Forsort In-Place | 0.805 | 1.6% | Yes |
| 3 | **fb** | Basic Forsort In-Place | 1.000 | 26.3% | Yes |
| 4 | fi | Adaptive Forsort In-Place | 1.497 | 89.0% | No |
| 5 | fiw | Adaptive Forsort Stable (with workspace) | 1.899 | 139.8% | Yes |
| 6 | wi | WikiSort | 2.433 | 207.2% | Yes |
| 7 | gs | Grail Sort In-Place | 22.028 | 2681.3% | Yes |
| 8 | gq | GLibc Quick Sort | 23.045 | 2809.7% | No |
| 9 | nq | Bentley/McIlroy Quick Sort | 26.585 | 3256.7% | No |

#### Random

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 37.832 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 40.936 | 8.2% | No |
| 3 | **fs** | Stable Forsort In-Place | 44.700 | 18.2% | Yes |
| 4 | gs | Grail Sort In-Place | 89.745 | 137.2% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 95.600 | 152.7% | No |
| 6 | wi | WikiSort | 106.35 | 181.1% | Yes |
| 7 | ti | TimSort | 120.77 | 219.2% | Yes |
| 8 | gq | GLibc Quick Sort | 121.49 | 221.1% | No |
| 9 | fb | Basic Forsort In-Place | 145.85 | 285.5% | Yes |

#### Reversed

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 8.681 | 0.0% | Yes |
| 2 | **wi** | WikiSort | 13.505 | 55.6% | Yes |
| 3 | **gs** | Grail Sort In-Place | 24.228 | 179.1% | Yes |
| 4 | fs | Stable Forsort In-Place | 32.299 | 272.1% | Yes |
| 5 | fiw | Adaptive Forsort Stable (with workspace) | 33.473 | 285.6% | Yes |
| 6 | nq | Bentley/McIlroy Quick Sort | 33.724 | 288.5% | No |
| 7 | fi | Adaptive Forsort In-Place | 37.928 | 336.9% | No |
| 8 | fb | Basic Forsort In-Place | 46.793 | 439.0% | Yes |
| 9 | gq | GLibc Quick Sort | 115.88 | 1234.9% | No |

#### Reversed Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **ti** | TimSort | 1.028 | 0.0% | Yes |
| 2 | **fb** | Basic Forsort In-Place | 2.307 | 124.4% | Yes |
| 3 | **fs** | Stable Forsort In-Place | 5.349 | 420.3% | Yes |
| 4 | wi | WikiSort | 12.650 | 1130.5% | Yes |
| 5 | gs | Grail Sort In-Place | 23.480 | 2184.0% | Yes |
| 6 | gq | GLibc Quick Sort | 29.721 | 2791.1% | No |
| 7 | fiw | Adaptive Forsort Stable (with workspace) | 33.034 | 3113.4% | Yes |
| 8 | nq | Bentley/McIlroy Quick Sort | 33.801 | 3188.0% | No |
| 9 | fi | Adaptive Forsort In-Place | 37.442 | 3542.2% | No |

#### Unique

| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |
|------|-----------|------|---------|-------------|---------|
| 1 | **fiw** | Adaptive Forsort Stable (with workspace) | 37.851 | 0.0% | Yes |
| 2 | **fi** | Adaptive Forsort In-Place | 41.001 | 8.3% | No |
| 3 | **fs** | Stable Forsort In-Place | 44.662 | 18.0% | Yes |
| 4 | gs | Grail Sort In-Place | 89.639 | 136.8% | Yes |
| 5 | nq | Bentley/McIlroy Quick Sort | 95.595 | 152.6% | No |
| 6 | wi | WikiSort | 106.56 | 181.5% | Yes |
| 7 | ti | TimSort | 120.77 | 219.1% | Yes |
| 8 | gq | GLibc Quick Sort | 122.86 | 224.6% | No |
| 9 | fb | Basic Forsort In-Place | 146.66 | 287.5% | Yes |

#### Overall Winner (Average Across All Variants)

**Winner:** fs (Stable Forsort In-Place) - Average: 24.730 ns/item


## Detailed Results by Dataset Size

### 1000 Items

#### 1 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000003850** | 1926 | **3.850** | Yes | 1 |
| fiw | Adaptive Forsort Stable (with workspace) | **0.000008649** | 1355 | **8.649** | Yes | 2 |
| wi | WikiSort | **0.000011609** | 2792 | **11.609** | Yes | 3 |
| fb | Basic Forsort In-Place | 0.000012059 | 2212 | 12.059 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000013350 | 8304 | 13.350 | Yes | 5 |
| fs | Stable Forsort In-Place | 0.000014210 | 2744 | 14.210 | Yes | 6 |
| ti | TimSort | 0.000014589 | 2235 | 14.589 | Yes | 7 |
| fi | Adaptive Forsort In-Place | 0.000017370 | 1496 | 17.370 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000024669 | 5016 | 24.669 | Yes | 9 |
| gs | Grail Sort In-Place | 0.000025879 | 4933 | 25.879 | Yes | 10 |

#### 25 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000031149** | 10569 | **31.149** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.000036388** | 7835 | **36.388** | Yes | 2 |
| nq | Bentley/McIlroy Quick Sort | **0.000040659** | 9211 | **40.659** | Yes | 3 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000049028 | 7428 | 49.028 | Yes | 4 |
| wi | WikiSort | 0.000055068 | 8846 | 55.068 | Yes | 5 |
| gq | GLibc Quick Sort | 0.000055608 | 8064 | 55.608 | Yes | 6 |
| ti | TimSort | 0.000060768 | 7010 | 60.768 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000061358 | 9042 | 61.358 | Yes | 8 |
| fs | Stable Forsort In-Place | 0.000071718 | 8302 | 71.718 | Yes | 9 |
| fb | Basic Forsort In-Place | 0.000073898 | 9126 | 73.898 | Yes | 10 |

#### 5 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000012759** | 7002 | **12.759** | Yes | 1 |
| nq | Bentley/McIlroy Quick Sort | **0.000015160** | 8389 | **15.160** | Yes | 2 |
| fi | Adaptive Forsort In-Place | **0.000021559** | 3455 | **21.559** | Yes | 3 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000024579 | 3122 | 24.579 | Yes | 4 |
| wi | WikiSort | 0.000027469 | 5635 | 27.469 | Yes | 5 |
| fb | Basic Forsort In-Place | 0.000028509 | 4435 | 28.509 | Yes | 6 |
| ti | TimSort | 0.000028589 | 3759 | 28.589 | Yes | 7 |
| fs | Stable Forsort In-Place | 0.000030349 | 3521 | 30.349 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000031479 | 5673 | 31.479 | Yes | 9 |
| gs | Grail Sort In-Place | 0.000033699 | 5713 | 33.699 | Yes | 10 |

#### Limited Range

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.000030449** | 9545 | **30.449** | Yes | 1 |
| gs | Grail Sort In-Place | **0.000048369** | 10486 | **48.369** | Yes | 2 |
| gq | GLibc Quick Sort | **0.000050078** | 8702 | **50.078** | Yes | 3 |
| is | Insertion Sort | 0.000051568 | 10897 | 51.568 | Yes | 4 |
| ti | TimSort | 0.000056558 | 8670 | 56.558 | Yes | 5 |
| fi | Adaptive Forsort In-Place | 0.000057058 | 10166 | 57.058 | No | 6 |
| fs | Stable Forsort In-Place | 0.000064068 | 10564 | 64.068 | Yes | 7 |
| wi | WikiSort | 0.000067888 | 9532 | 67.888 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000070337 | 9551 | 70.337 | No | 9 |
| fb | Basic Forsort In-Place | 0.000107436 | 15144 | 107.44 | Yes | 10 |

#### Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000001260** | 999 | **1.260** | Yes | 1 |
| fb | Basic Forsort In-Place | **0.000002100** | 999 | **2.100** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.000002170** | 999 | **2.170** | Yes | 3 |
| ti | TimSort | 0.000002610 | 999 | 2.610 | Yes | 4 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000007520 | 1028 | 7.520 | Yes | 5 |
| fi | Adaptive Forsort In-Place | 0.000007839 | 1052 | 7.839 | Yes | 6 |
| wi | WikiSort | 0.000008560 | 2530 | 8.560 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000013949 | 4932 | 13.949 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000017710 | 8192 | 17.710 | Yes | 9 |
| gs | Grail Sort In-Place | 0.000022299 | 4790 | 22.299 | Yes | 10 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| is | Insertion Sort | **0.000001279** | 999 | **1.279** | Yes | 1 |
| fb | Basic Forsort In-Place | **0.000002410** | 999 | **2.410** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.000002450** | 999 | **2.450** | Yes | 3 |
| ti | TimSort | 0.000003809 | 999 | 3.809 | Yes | 4 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000005440 | 1028 | 5.440 | Yes | 5 |
| fi | Adaptive Forsort In-Place | 0.000007740 | 1052 | 7.740 | Yes | 6 |
| wi | WikiSort | 0.000011300 | 2530 | 11.300 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000013290 | 4932 | 13.290 | Yes | 8 |
| gs | Grail Sort In-Place | 0.000016840 | 4790 | 16.840 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.000017989 | 8192 | 17.989 | Yes | 10 |

#### Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fs | Stable Forsort In-Place | **0.000041308** | 10446 | **41.308** | Yes | 1 |
| fiw | Adaptive Forsort Stable (with workspace) | **0.000045638** | 9543 | **45.638** | Yes | 2 |
| nq | Bentley/McIlroy Quick Sort | **0.000047519** | 10449 | **47.519** | Yes | 3 |
| is | Insertion Sort | 0.000053268 | 10897 | 53.268 | Yes | 4 |
| ti | TimSort | 0.000053308 | 8667 | 53.308 | Yes | 5 |
| gq | GLibc Quick Sort | 0.000055308 | 8699 | 55.308 | Yes | 6 |
| fi | Adaptive Forsort In-Place | 0.000055958 | 10128 | 55.958 | Yes | 7 |
| fb | Basic Forsort In-Place | 0.000062247 | 15138 | 62.247 | Yes | 8 |
| wi | WikiSort | 0.000072487 | 9528 | 72.487 | Yes | 9 |
| gs | Grail Sort In-Place | 0.000082317 | 10421 | 82.317 | Yes | 10 |

#### Reversed

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000004399** | 999 | **4.399** | Yes | 1 |
| fb | Basic Forsort In-Place | **0.000005060** | 1998 | **5.060** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.000009800** | 2551 | **9.800** | Yes | 3 |
| wi | WikiSort | 0.000015249 | 3287 | 15.249 | Yes | 4 |
| gq | GLibc Quick Sort | 0.000015370 | 5044 | 15.370 | Yes | 5 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000024159 | 6614 | 24.159 | Yes | 6 |
| is | Insertion Sort | 0.000025629 | 10980 | 25.629 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000027459 | 5112 | 27.459 | Yes | 8 |
| fi | Adaptive Forsort In-Place | 0.000031499 | 6407 | 31.499 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.000033209 | 14222 | 33.209 | Yes | 10 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000003990** | 999 | **3.990** | Yes | 1 |
| fb | Basic Forsort In-Place | **0.000004960** | 1998 | **4.960** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.000013420** | 2551 | **13.420** | Yes | 3 |
| wi | WikiSort | 0.000015349 | 3287 | 15.349 | Yes | 4 |
| gq | GLibc Quick Sort | 0.000023950 | 5044 | 23.950 | Yes | 5 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000025030 | 6614 | 25.030 | Yes | 6 |
| is | Insertion Sort | 0.000025659 | 10980 | 25.659 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000026959 | 5112 | 26.959 | Yes | 8 |
| fi | Adaptive Forsort In-Place | 0.000031309 | 6407 | 31.309 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.000033059 | 14222 | 33.059 | Yes | 10 |

#### Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.000045668** | 9543 | **45.668** | Yes | 1 |
| wi | WikiSort | **0.000048768** | 9528 | **48.768** | Yes | 2 |
| is | Insertion Sort | **0.000051778** | 10897 | **51.778** | Yes | 3 |
| fi | Adaptive Forsort In-Place | 0.000056438 | 10128 | 56.438 | Yes | 4 |
| fs | Stable Forsort In-Place | 0.000062757 | 10446 | 62.757 | Yes | 5 |
| fb | Basic Forsort In-Place | 0.000068188 | 15138 | 68.188 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.000069058 | 10449 | 69.058 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000083937 | 10421 | 83.937 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000086397 | 8699 | 86.397 | Yes | 9 |
| ti | TimSort | 0.000086737 | 8667 | 86.737 | Yes | 10 |

### 10000 Items

#### 1 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.000057558** | 21323 | **5.756** | Yes | 1 |
| ti | TimSort | **0.000060907** | 20318 | **6.091** | Yes | 2 |
| fi | Adaptive Forsort In-Place | **0.000066588** | 22792 | **6.659** | Yes | 3 |
| fs | Stable Forsort In-Place | 0.000068208 | 24197 | 6.821 | Yes | 4 |
| fb | Basic Forsort In-Place | 0.000077597 | 32359 | 7.760 | Yes | 5 |
| wi | WikiSort | 0.000086466 | 47827 | 8.647 | Yes | 6 |
| is | Insertion Sort | 0.000091416 | 66299 | 9.142 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.000135725 | 112554 | 13.572 | Yes | 8 |
| gs | Grail Sort In-Place | 0.000141555 | 60937 | 14.155 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000149764 | 69350 | 14.976 | Yes | 10 |

#### 25 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.000238232** | 101352 | **23.823** | Yes | 1 |
| wi | WikiSort | **0.000326858** | 132042 | **32.686** | Yes | 2 |
| gs | Grail Sort In-Place | **0.000383186** | 127531 | **38.319** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.000384946 | 126774 | 38.495 | Yes | 4 |
| fs | Stable Forsort In-Place | 0.000406956 | 106432 | 40.696 | Yes | 5 |
| ti | TimSort | 0.000418275 | 96274 | 41.828 | Yes | 6 |
| fi | Adaptive Forsort In-Place | 0.000435074 | 104888 | 43.507 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000453104 | 115721 | 45.310 | Yes | 8 |
| is | Insertion Sort | 0.000486912 | 143007 | 48.691 | Yes | 9 |
| fb | Basic Forsort In-Place | 0.000487503 | 126347 | 48.750 | Yes | 10 |

#### 5 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.000137015** | 46217 | **13.701** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.000154314** | 49717 | **15.431** | Yes | 2 |
| nq | Bentley/McIlroy Quick Sort | **0.000167744** | 116444 | **16.774** | Yes | 3 |
| ti | TimSort | 0.000174824 | 41101 | 17.482 | Yes | 4 |
| fs | Stable Forsort In-Place | 0.000178373 | 50742 | 17.837 | Yes | 5 |
| wi | WikiSort | 0.000182703 | 94710 | 18.270 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000189983 | 89970 | 18.998 | Yes | 7 |
| is | Insertion Sort | 0.000226402 | 141517 | 22.640 | Yes | 8 |
| fb | Basic Forsort In-Place | 0.000313618 | 60447 | 31.362 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000420024 | 91579 | 42.002 | Yes | 10 |

#### Limited Range

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.000205113** | 126206 | **20.511** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.000246871** | 133040 | **24.687** | No | 2 |
| fs | Stable Forsort In-Place | **0.000264490** | 133710 | **26.449** | Yes | 3 |
| gs | Grail Sort In-Place | 0.000479623 | 138958 | 47.962 | Yes | 4 |
| wi | WikiSort | 0.000508322 | 143437 | 50.832 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.000513931 | 130174 | 51.393 | No | 6 |
| ti | TimSort | 0.000662056 | 120348 | 66.206 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000675136 | 120379 | 67.514 | Yes | 8 |
| fb | Basic Forsort In-Place | 0.000783252 | 207099 | 78.325 | Yes | 9 |
| is | Insertion Sort | 0.001200917 | 143533 | 120.09 | Yes | 10 |

#### Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fs | Stable Forsort In-Place | **0.000008490** | 9999 | **0.849** | Yes | 1 |
| ti | TimSort | **0.000009619** | 9999 | **0.962** | Yes | 2 |
| fb | Basic Forsort In-Place | **0.000010229** | 9999 | **1.023** | Yes | 3 |
| is | Insertion Sort | 0.000011120 | 9999 | 1.112 | Yes | 4 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000011960 | 10049 | 1.196 | Yes | 5 |
| wi | WikiSort | 0.000035369 | 23662 | 3.537 | Yes | 6 |
| fi | Adaptive Forsort In-Place | 0.000082937 | 10091 | 8.294 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000100207 | 53332 | 10.021 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000132115 | 111539 | 13.211 | Yes | 9 |
| gq | GLibc Quick Sort | 0.000213533 | 64608 | 21.353 | Yes | 10 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fs | Stable Forsort In-Place | **0.000008470** | 9999 | **0.847** | Yes | 1 |
| ti | TimSort | **0.000009209** | 9999 | **0.921** | Yes | 2 |
| is | Insertion Sort | **0.000011200** | 9999 | **1.120** | Yes | 3 |
| fi | Adaptive Forsort In-Place | 0.000011629 | 10091 | 1.163 | Yes | 4 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000011659 | 10049 | 1.166 | Yes | 5 |
| fb | Basic Forsort In-Place | 0.000017179 | 9999 | 1.718 | Yes | 6 |
| wi | WikiSort | 0.000034679 | 23662 | 3.468 | Yes | 7 |
| gs | Grail Sort In-Place | 0.000108546 | 53332 | 10.855 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000138975 | 64608 | 13.898 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.000209872 | 111539 | 20.987 | Yes | 10 |

#### Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fi | Adaptive Forsort In-Place | **0.000246761** | 133036 | **24.676** | Yes | 1 |
| fs | Stable Forsort In-Place | **0.000270210** | 133652 | **27.021** | Yes | 2 |
| fiw | Adaptive Forsort Stable (with workspace) | **0.000342488** | 126191 | **34.249** | Yes | 3 |
| gs | Grail Sort In-Place | 0.000472893 | 138659 | 47.289 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000493912 | 137009 | 49.391 | Yes | 5 |
| wi | WikiSort | 0.000585399 | 143420 | 58.540 | Yes | 6 |
| ti | TimSort | 0.000631537 | 120349 | 63.154 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000682356 | 120381 | 68.236 | Yes | 8 |
| fb | Basic Forsort In-Place | 0.000739923 | 207075 | 73.992 | Yes | 9 |
| is | Insertion Sort | 0.001368470 | 143533 | 136.85 | Yes | 10 |

#### Reversed

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000010050** | 9999 | **1.005** | Yes | 1 |
| fs | Stable Forsort In-Place | **0.000031939** | 21910 | **3.194** | Yes | 2 |
| fb | Basic Forsort In-Place | **0.000037109** | 19998 | **3.711** | Yes | 3 |
| wi | WikiSort | 0.000056848 | 25008 | 5.685 | Yes | 4 |
| gs | Grail Sort In-Place | 0.000101377 | 57076 | 10.138 | Yes | 5 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000116335 | 98010 | 11.633 | Yes | 6 |
| fi | Adaptive Forsort In-Place | 0.000125235 | 93366 | 12.523 | Yes | 7 |
| gq | GLibc Quick Sort | 0.000166114 | 69008 | 16.611 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.000242651 | 192779 | 24.265 | Yes | 9 |
| is | Insertion Sort | 0.002442652 | 143612 | 244.26 | Yes | 10 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000010960** | 9999 | **1.096** | Yes | 1 |
| fb | Basic Forsort In-Place | **0.000021659** | 19998 | **2.166** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.000047128** | 21910 | **4.713** | Yes | 3 |
| wi | WikiSort | 0.000056168 | 25008 | 5.617 | Yes | 4 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000116276 | 98010 | 11.628 | Yes | 5 |
| fi | Adaptive Forsort In-Place | 0.000122856 | 93366 | 12.286 | Yes | 6 |
| gs | Grail Sort In-Place | 0.000173013 | 57076 | 17.301 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.000258140 | 192779 | 25.814 | Yes | 8 |
| gq | GLibc Quick Sort | 0.000268730 | 69008 | 26.873 | Yes | 9 |
| is | Insertion Sort | 0.002122203 | 143612 | 212.22 | Yes | 10 |

#### Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.000219742** | 126191 | **21.974** | Yes | 1 |
| fs | Stable Forsort In-Place | **0.000266910** | 133652 | **26.691** | Yes | 2 |
| fi | Adaptive Forsort In-Place | **0.000415716** | 133036 | **41.572** | Yes | 3 |
| gs | Grail Sort In-Place | 0.000476833 | 138659 | 47.683 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.000495582 | 137009 | 49.558 | Yes | 5 |
| ti | TimSort | 0.000647357 | 120349 | 64.736 | Yes | 6 |
| wi | WikiSort | 0.000758702 | 143420 | 75.870 | Yes | 7 |
| fb | Basic Forsort In-Place | 0.000811241 | 207075 | 81.124 | Yes | 8 |
| is | Insertion Sort | 0.001214906 | 143533 | 121.49 | Yes | 9 |
| gq | GLibc Quick Sort | 0.002087236 | 120381 | 208.72 | Yes | 10 |

### 100000 Items

#### 1 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000732853** | 254708 | **7.329** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.000756763** | 308065 | **7.568** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.000779772** | 318465 | **7.798** | Yes | 3 |
| fb | Basic Forsort In-Place | 0.000968676 | 431804 | 9.687 | Yes | 4 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.001021274 | 293036 | 10.213 | Yes | 5 |
| wi | WikiSort | 0.001292963 | 936287 | 12.930 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.001797805 | 1516043 | 17.978 | Yes | 7 |
| gs | Grail Sort In-Place | 0.001823925 | 904672 | 18.239 | Yes | 8 |
| is | Insertion Sort | 0.002281058 | 1743774 | 22.811 | Yes | 9 |
| gq | GLibc Quick Sort | 0.003628970 | 1046328 | 36.290 | Yes | 10 |

#### 25 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.002389155** | 1236866 | **23.892** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.002576188** | 1268232 | **25.762** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.002668225** | 1266212 | **26.682** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.003644438 | 1625332 | 36.444 | No | 4 |
| wi | WikiSort | 0.004045363 | 1724079 | 40.454 | Yes | 5 |
| gs | Grail Sort In-Place | 0.004328875 | 1633206 | 43.289 | Yes | 6 |
| ti | TimSort | 0.004758128 | 1092617 | 47.581 | Yes | 7 |
| gq | GLibc Quick Sort | 0.005049109 | 1511072 | 50.491 | Yes | 8 |
| fb | Basic Forsort In-Place | 0.005596500 | 1535002 | 55.965 | Yes | 9 |
| is | Insertion Sort | 0.012885684 | 1768284 | 128.86 | Yes | 10 |

#### 5 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.001463818** | 625323 | **14.638** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.001512006** | 656475 | **15.120** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.001520906** | 599475 | **15.209** | Yes | 3 |
| ti | TimSort | 0.001956529 | 522910 | 19.565 | Yes | 4 |
| fb | Basic Forsort In-Place | 0.002131864 | 735032 | 21.319 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.002155542 | 1515354 | 21.555 | No | 6 |
| wi | WikiSort | 0.002203040 | 1321121 | 22.030 | Yes | 7 |
| gs | Grail Sort In-Place | 0.002522779 | 1280038 | 25.228 | Yes | 8 |
| is | Insertion Sort | 0.003005802 | 1764569 | 30.058 | Yes | 9 |
| gq | GLibc Quick Sort | 0.003068760 | 1299870 | 30.688 | Yes | 10 |

#### Limited Range

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.002336887** | 1622428 | **23.369** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.002625766** | 1648605 | **26.258** | No | 2 |
| fs | Stable Forsort In-Place | **0.002869547** | 1702536 | **28.695** | Yes | 3 |
| gs | Grail Sort In-Place | 0.005787683 | 1691595 | 57.877 | Yes | 4 |
| wi | WikiSort | 0.006188756 | 1828864 | 61.888 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.006602751 | 1640156 | 66.028 | No | 6 |
| ti | TimSort | 0.008076078 | 1531448 | 80.761 | Yes | 7 |
| gq | GLibc Quick Sort | 0.008257931 | 1536166 | 82.579 | Yes | 8 |
| fb | Basic Forsort In-Place | 0.009448831 | 2642972 | 94.488 | Yes | 9 |
| is | Insertion Sort | 0.099659918 | 1768738 | 996.60 | Yes | 10 |

#### Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fs | Stable Forsort In-Place | **0.000078317** | 99999 | **0.783** | Yes | 1 |
| ti | TimSort | **0.000082567** | 99999 | **0.826** | Yes | 2 |
| fb | Basic Forsort In-Place | **0.000097477** | 99999 | **0.975** | Yes | 3 |
| is | Insertion Sort | 0.000109846 | 99999 | 1.098 | Yes | 4 |
| fi | Adaptive Forsort In-Place | 0.000111316 | 100167 | 1.113 | Yes | 5 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000139315 | 100078 | 1.393 | Yes | 6 |
| wi | WikiSort | 0.000271350 | 240530 | 2.713 | Yes | 7 |
| gs | Grail Sort In-Place | 0.001100611 | 608786 | 11.006 | Yes | 8 |
| gq | GLibc Quick Sort | 0.001638112 | 815024 | 16.381 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.001796505 | 1524581 | 17.965 | Yes | 10 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fs | Stable Forsort In-Place | **0.000078238** | 99999 | **0.782** | Yes | 1 |
| ti | TimSort | **0.000083177** | 99999 | **0.832** | Yes | 2 |
| is | Insertion Sort | **0.000100356** | 99999 | **1.004** | Yes | 3 |
| fb | Basic Forsort In-Place | 0.000100676 | 99999 | 1.007 | Yes | 4 |
| fi | Adaptive Forsort In-Place | 0.000108686 | 100167 | 1.087 | Yes | 5 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.000128615 | 100078 | 1.286 | Yes | 6 |
| wi | WikiSort | 0.000273750 | 240530 | 2.737 | Yes | 7 |
| gs | Grail Sort In-Place | 0.001056092 | 608786 | 10.561 | Yes | 8 |
| gq | GLibc Quick Sort | 0.001594133 | 815024 | 15.941 | Yes | 9 |
| nq | Bentley/McIlroy Quick Sort | 0.002000238 | 1524583 | 20.002 | Yes | 10 |

#### Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.002317147** | 1622478 | **23.171** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.002610436** | 1649240 | **26.104** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.002734562** | 1702919 | **27.346** | Yes | 3 |
| gs | Grail Sort In-Place | 0.006068133 | 1692347 | 60.681 | Yes | 4 |
| wi | WikiSort | 0.007214729 | 1828495 | 72.147 | Yes | 5 |
| ti | TimSort | 0.007742790 | 1531408 | 77.428 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.008301290 | 1717333 | 83.013 | No | 7 |
| gq | GLibc Quick Sort | 0.008340102 | 1536166 | 83.401 | Yes | 8 |
| fb | Basic Forsort In-Place | 0.009115023 | 2645090 | 91.150 | Yes | 9 |
| is | Insertion Sort | 0.101941096 | 1768738 | 1019.4 | Yes | 10 |

#### Reversed

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000239812** | 100112 | **2.398** | Yes | 1 |
| fb | Basic Forsort In-Place | **0.000401525** | 203803 | **4.015** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.000431305** | 219263 | **4.313** | Yes | 3 |
| wi | WikiSort | 0.000696945 | 284049 | 6.969 | Yes | 4 |
| gs | Grail Sort In-Place | 0.001108910 | 627302 | 11.089 | Yes | 5 |
| fi | Adaptive Forsort In-Place | 0.001433769 | 1201403 | 14.338 | Yes | 6 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.001499586 | 1235508 | 14.996 | Yes | 7 |
| gq | GLibc Quick Sort | 0.001980549 | 853905 | 19.805 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.002390784 | 1935554 | 23.908 | No | 9 |
| is | Insertion Sort | 0.239175287 | 1768918 | 2391.8 | Yes | 10 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000099466** | 99999 | **0.995** | Yes | 1 |
| fb | Basic Forsort In-Place | **0.000200623** | 199998 | **2.006** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.000285490** | 210306 | **2.855** | Yes | 3 |
| wi | WikiSort | 0.000554540 | 284046 | 5.545 | Yes | 4 |
| gs | Grail Sort In-Place | 0.001059772 | 627299 | 10.598 | Yes | 5 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.001397330 | 1235508 | 13.973 | Yes | 6 |
| fi | Adaptive Forsort In-Place | 0.001436638 | 1201428 | 14.366 | Yes | 7 |
| gq | GLibc Quick Sort | 0.001942371 | 853904 | 19.424 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.002271958 | 1935567 | 22.720 | Yes | 9 |
| is | Insertion Sort | 0.249064310 | 1768918 | 2490.6 | Yes | 10 |

#### Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.002313057** | 1622478 | **23.131** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.002607227** | 1649183 | **26.072** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.002828629** | 1703019 | **28.286** | Yes | 3 |
| gs | Grail Sort In-Place | 0.005745774 | 1692166 | 57.458 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.006790375 | 1717336 | 67.904 | Yes | 5 |
| wi | WikiSort | 0.006839023 | 1828495 | 68.390 | Yes | 6 |
| ti | TimSort | 0.007951243 | 1531408 | 79.512 | Yes | 7 |
| fb | Basic Forsort In-Place | 0.009644445 | 2645089 | 96.444 | Yes | 8 |
| gq | GLibc Quick Sort | 0.012036289 | 1536166 | 120.36 | Yes | 9 |
| is | Insertion Sort | 0.101343737 | 1768738 | 1013.4 | Yes | 10 |

### 1000000 Items

#### 1 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fs | Stable Forsort In-Place | **0.008619961** | 3612221 | **8.620** | Yes | 1 |
| fiw | Adaptive Forsort Stable (with workspace) | **0.008638140** | 3374464 | **8.638** | Yes | 2 |
| ti | TimSort | **0.008639678** | 3191636 | **8.640** | Yes | 3 |
| fi | Adaptive Forsort In-Place | 0.009121633 | 3524638 | 9.122 | No | 4 |
| fb | Basic Forsort In-Place | 0.011824706 | 4912080 | 11.825 | Yes | 5 |
| wi | WikiSort | 0.017710970 | 13269948 | 17.711 | Yes | 6 |
| nq | Bentley/McIlroy Quick Sort | 0.021077138 | 18248470 | 21.077 | No | 7 |
| gq | GLibc Quick Sort | 0.027088189 | 14447185 | 27.088 | Yes | 8 |
| gs | Grail Sort In-Place | 0.028079364 | 13144367 | 28.079 | Yes | 9 |

#### 25 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.026923826** | 14553714 | **26.924** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.027340441** | 15090266 | **27.340** | No | 2 |
| fs | Stable Forsort In-Place | **0.029259242** | 14945609 | **29.259** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.043419721 | 19802661 | 43.420 | No | 4 |
| wi | WikiSort | 0.046348185 | 21143567 | 46.348 | Yes | 5 |
| gs | Grail Sort In-Place | 0.053379807 | 19780452 | 53.380 | Yes | 6 |
| ti | TimSort | 0.054443752 | 12434342 | 54.444 | Yes | 7 |
| gq | GLibc Quick Sort | 0.055857279 | 18502661 | 55.857 | Yes | 8 |
| fb | Basic Forsort In-Place | 0.062090296 | 17971590 | 62.090 | Yes | 9 |

#### 5 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.015577082** | 7201084 | **15.577** | Yes | 1 |
| fs | Stable Forsort In-Place | **0.015943179** | 7242401 | **15.943** | Yes | 2 |
| fi | Adaptive Forsort In-Place | **0.016007866** | 7699280 | **16.008** | No | 3 |
| ti | TimSort | 0.021276141 | 6025478 | 21.276 | Yes | 4 |
| fb | Basic Forsort In-Place | 0.024228102 | 8177254 | 24.228 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.024955768 | 18492866 | 24.956 | No | 6 |
| wi | WikiSort | 0.026060848 | 17053388 | 26.061 | Yes | 7 |
| gq | GLibc Quick Sort | 0.034837262 | 16530918 | 34.837 | Yes | 8 |
| gs | Grail Sort In-Place | 0.035399901 | 16672002 | 35.400 | Yes | 9 |

#### Limited Range

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.026396514** | 19344227 | **26.397** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.029958947** | 20000785 | **29.959** | No | 2 |
| fs | Stable Forsort In-Place | **0.030791037** | 20136481 | **30.791** | Yes | 3 |
| gs | Grail Sort In-Place | 0.066407921 | 20156763 | 66.408 | Yes | 4 |
| wi | WikiSort | 0.072898575 | 22375013 | 72.899 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.073671518 | 20553611 | 73.672 | No | 6 |
| gq | GLibc Quick Sort | 0.093026268 | 18671395 | 93.026 | Yes | 7 |
| ti | TimSort | 0.097309013 | 18290244 | 97.309 | Yes | 8 |
| fb | Basic Forsort In-Place | 0.105384465 | 31924599 | 105.38 | Yes | 9 |

#### Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fs | Stable Forsort In-Place | **0.000807591** | 999999 | **0.808** | Yes | 1 |
| ti | TimSort | **0.000846679** | 999999 | **0.847** | Yes | 2 |
| fb | Basic Forsort In-Place | **0.000974725** | 999999 | **0.975** | Yes | 3 |
| fi | Adaptive Forsort In-Place | 0.001045892 | 1000212 | 1.046 | Yes | 4 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.001382830 | 1000058 | 1.383 | Yes | 5 |
| wi | WikiSort | 0.002614235 | 2595343 | 2.614 | Yes | 6 |
| gs | Grail Sort In-Place | 0.014602857 | 7019441 | 14.603 | Yes | 7 |
| gq | GLibc Quick Sort | 0.017775313 | 9884992 | 17.775 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.021479554 | 18196494 | 21.480 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.000785101** | 999999 | **0.785** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.001013073** | 1000212 | **1.013** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.001193887** | 999999 | **1.194** | Yes | 3 |
| fb | Basic Forsort In-Place | 0.001213817 | 999999 | 1.214 | Yes | 4 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.001376600 | 1000058 | 1.377 | Yes | 5 |
| wi | WikiSort | 0.002749331 | 2595342 | 2.749 | Yes | 6 |
| gs | Grail Sort In-Place | 0.014657705 | 7019410 | 14.658 | Yes | 7 |
| gq | GLibc Quick Sort | 0.018029434 | 9884992 | 18.029 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.019261524 | 18196618 | 19.262 | Yes | 9 |

#### Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.026373855** | 19344337 | **26.374** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.029531732** | 20005479 | **29.532** | No | 2 |
| fs | Stable Forsort In-Place | **0.030647622** | 20144873 | **30.648** | Yes | 3 |
| gs | Grail Sort In-Place | 0.064381093 | 20158022 | 64.381 | Yes | 4 |
| wi | WikiSort | 0.073413037 | 22371807 | 73.413 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.082824257 | 20868796 | 82.824 | No | 6 |
| ti | TimSort | 0.090494780 | 18290497 | 90.495 | Yes | 7 |
| gq | GLibc Quick Sort | 0.093861727 | 18671395 | 93.862 | Yes | 8 |
| fb | Basic Forsort In-Place | 0.104459748 | 31940226 | 104.46 | Yes | 9 |

#### Reversed

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.002881666** | 1006818 | **2.882** | Yes | 1 |
| fs | Stable Forsort In-Place | **0.005621908** | 2336292 | **5.622** | Yes | 2 |
| wi | WikiSort | **0.006799134** | 3273957 | **6.799** | Yes | 3 |
| fb | Basic Forsort In-Place | 0.008925540 | 2216282 | 8.926 | Yes | 4 |
| gs | Grail Sort In-Place | 0.015426737 | 7552170 | 15.427 | Yes | 5 |
| fi | Adaptive Forsort In-Place | 0.018529626 | 15784291 | 18.530 | Yes | 6 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.018613263 | 16420327 | 18.613 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.029923208 | 24024292 | 29.923 | No | 8 |
| gq | GLibc Quick Sort | 0.083921983 | 10066547 | 83.922 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.001852113** | 999999 | **1.852** | Yes | 1 |
| fb | Basic Forsort In-Place | **0.002021358** | 1999998 | **2.021** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.002955334** | 2088913 | **2.955** | Yes | 3 |
| wi | WikiSort | 0.006269893 | 3273489 | 6.270 | Yes | 4 |
| gs | Grail Sort In-Place | 0.017415426 | 7551070 | 17.415 | Yes | 5 |
| fi | Adaptive Forsort In-Place | 0.019235321 | 15784214 | 19.235 | Yes | 6 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.019861359 | 16420327 | 19.861 | Yes | 7 |
| gq | GLibc Quick Sort | 0.021209240 | 10066432 | 21.209 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.026941536 | 24025703 | 26.942 | Yes | 9 |

#### Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.026218071** | 19344337 | **26.218** | Yes | 1 |
| fs | Stable Forsort In-Place | **0.030142410** | 20144554 | **30.142** | Yes | 2 |
| fi | Adaptive Forsort In-Place | **0.031279100** | 20003927 | **31.279** | Yes | 3 |
| gs | Grail Sort In-Place | 0.065401727 | 20154575 | 65.402 | Yes | 4 |
| wi | WikiSort | 0.072492020 | 22370399 | 72.492 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.075438724 | 20868688 | 75.439 | Yes | 6 |
| ti | TimSort | 0.090165851 | 18290499 | 90.166 | Yes | 7 |
| gq | GLibc Quick Sort | 0.091828160 | 18671395 | 91.828 | Yes | 8 |
| fb | Basic Forsort In-Place | 0.106708507 | 31940258 | 106.71 | Yes | 9 |

### 10000000 Items

#### 1 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.092006015** | 29034572 | **9.201** | Yes | 1 |
| fs | Stable Forsort In-Place | **0.104278234** | 45723521 | **10.428** | Yes | 2 |
| fi | Adaptive Forsort In-Place | **0.105946624** | 44268314 | **10.595** | No | 3 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.109809866 | 42894715 | 10.981 | Yes | 4 |
| fb | Basic Forsort In-Place | 0.133542775 | 52321148 | 13.354 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.243733512 | 214985800 | 24.373 | No | 6 |
| wi | WikiSort | 0.260154539 | 161674690 | 26.015 | Yes | 7 |
| gs | Grail Sort In-Place | 0.360293911 | 167107953 | 36.029 | Yes | 8 |
| gq | GLibc Quick Sort | 0.754412151 | 178719900 | 75.441 | Yes | 9 |

#### 25 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.309032698** | 165645932 | **30.903** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.319833781** | 173895640 | **31.983** | No | 2 |
| fs | Stable Forsort In-Place | **0.339036813** | 171498604 | **33.904** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 0.510389905 | 233347510 | 51.039 | No | 4 |
| ti | TimSort | 0.595522379 | 139122422 | 59.552 | Yes | 5 |
| wi | WikiSort | 0.596774883 | 249353467 | 59.677 | Yes | 6 |
| gs | Grail Sort In-Place | 0.652314759 | 232407212 | 65.231 | Yes | 7 |
| gq | GLibc Quick Sort | 0.674921838 | 218019265 | 67.492 | Yes | 8 |
| fb | Basic Forsort In-Place | 0.722744736 | 205423876 | 72.274 | Yes | 9 |

#### 5 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.174827596** | 83058524 | **17.483** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.184160002** | 87825094 | **18.416** | No | 2 |
| fs | Stable Forsort In-Place | **0.186436130** | 86531834 | **18.644** | Yes | 3 |
| ti | TimSort | 0.217200811 | 59750966 | 21.720 | Yes | 4 |
| fb | Basic Forsort In-Place | 0.281450946 | 89509650 | 28.145 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 0.294442819 | 218696014 | 29.444 | No | 6 |
| wi | WikiSort | 0.365352297 | 204484322 | 36.535 | Yes | 7 |
| gq | GLibc Quick Sort | 0.403824442 | 199491157 | 40.382 | Yes | 8 |
| gs | Grail Sort In-Place | 0.462979892 | 201569842 | 46.298 | Yes | 9 |

#### Limited Range

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.327662330** | 225441758 | **32.766** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.352018148** | 232288484 | **35.202** | No | 2 |
| fs | Stable Forsort In-Place | **0.362196813** | 235476695 | **36.220** | Yes | 3 |
| gs | Grail Sort In-Place | 0.805128464 | 236936715 | 80.513 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.829631958 | 237131562 | 82.963 | No | 5 |
| wi | WikiSort | 0.932857678 | 266882917 | 93.286 | Yes | 6 |
| ti | TimSort | 1.062038550 | 213811853 | 106.20 | Yes | 7 |
| gq | GLibc Quick Sort | 1.065839362 | 220067417 | 106.58 | Yes | 8 |
| fb | Basic Forsort In-Place | 1.241151502 | 373483234 | 124.11 | Yes | 9 |

#### Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.008037509** | 9999999 | **0.804** | Yes | 1 |
| fiw | Adaptive Forsort Stable (with workspace) | **0.011867405** | 10000089 | **1.187** | Yes | 2 |
| fb | Basic Forsort In-Place | **0.011954761** | 9999999 | **1.195** | Yes | 3 |
| fs | Stable Forsort In-Place | 0.012233992 | 9999999 | 1.223 | Yes | 4 |
| fi | Adaptive Forsort In-Place | 0.012409105 | 10000304 | 1.241 | Yes | 5 |
| wi | WikiSort | 0.024406158 | 20122534 | 2.441 | Yes | 6 |
| gq | GLibc Quick Sort | 0.201249140 | 114434624 | 20.125 | Yes | 7 |
| gs | Grail Sort In-Place | 0.202819623 | 79190549 | 20.282 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.220787251 | 211563126 | 22.079 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.007893785** | 9999999 | **0.789** | Yes | 1 |
| fb | Basic Forsort In-Place | **0.009846187** | 9999999 | **0.985** | Yes | 2 |
| fiw | Adaptive Forsort Stable (with workspace) | **0.010319201** | 10000089 | **1.032** | Yes | 3 |
| fi | Adaptive Forsort In-Place | 0.010427096 | 10000304 | 1.043 | Yes | 4 |
| fs | Stable Forsort In-Place | 0.010820382 | 9999999 | 1.082 | Yes | 5 |
| wi | WikiSort | 0.024163397 | 20122509 | 2.416 | Yes | 6 |
| gq | GLibc Quick Sort | 0.201330947 | 114434624 | 20.133 | Yes | 7 |
| gs | Grail Sort In-Place | 0.204964897 | 79189929 | 20.496 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.220262870 | 211572877 | 22.026 | Yes | 9 |

#### Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.312695917** | 225441807 | **31.270** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.356327314** | 232335444 | **35.633** | No | 2 |
| fs | Stable Forsort In-Place | **0.363724289** | 235565948 | **36.372** | Yes | 3 |
| gs | Grail Sort In-Place | 0.796109246 | 237013434 | 79.611 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.842739955 | 244041390 | 84.274 | No | 5 |
| wi | WikiSort | 0.937377845 | 266846348 | 93.738 | Yes | 6 |
| gq | GLibc Quick Sort | 1.065643550 | 220067428 | 106.56 | Yes | 7 |
| ti | TimSort | 1.066423291 | 213808938 | 106.64 | Yes | 8 |
| fb | Basic Forsort In-Place | 1.243969631 | 373634427 | 124.40 | Yes | 9 |

#### Reversed

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.050777985** | 10548612 | **5.078** | Yes | 1 |
| wi | WikiSort | **0.115167118** | 21887324 | **11.517** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.183295153** | 89901786 | **18.330** | Yes | 3 |
| gs | Grail Sort In-Place | 0.207177538 | 82000284 | 20.718 | Yes | 4 |
| fb | Basic Forsort In-Place | 0.216579820 | 29498302 | 21.658 | Yes | 5 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.250806725 | 197985831 | 25.081 | Yes | 6 |
| fi | Adaptive Forsort In-Place | 0.286056981 | 191373297 | 28.606 | No | 7 |
| nq | Bentley/McIlroy Quick Sort | 0.338847115 | 290526331 | 33.885 | No | 8 |
| gq | GLibc Quick Sort | 0.996863604 | 118797985 | 99.686 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.014549474** | 9999999 | **1.455** | Yes | 1 |
| fb | Basic Forsort In-Place | **0.022052420** | 19999998 | **2.205** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.043888438** | 20867892 | **4.389** | Yes | 3 |
| wi | WikiSort | 0.109767654 | 21498750 | 10.977 | Yes | 4 |
| gs | Grail Sort In-Place | 0.204170745 | 81979307 | 20.417 | Yes | 5 |
| gq | GLibc Quick Sort | 0.258755630 | 118788160 | 25.876 | Yes | 6 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.277810097 | 197985849 | 27.781 | Yes | 7 |
| fi | Adaptive Forsort In-Place | 0.292515119 | 191369358 | 29.252 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 0.341999190 | 290683459 | 34.200 | Yes | 9 |

#### Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **0.313926253** | 225441805 | **31.393** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **0.351251015** | 232334009 | **35.125** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.361805147** | 235566350 | **36.181** | Yes | 3 |
| gs | Grail Sort In-Place | 0.811842233 | 236874687 | 81.184 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 0.840565203 | 244066204 | 84.057 | Yes | 5 |
| wi | WikiSort | 0.931048354 | 266816725 | 93.105 | Yes | 6 |
| ti | TimSort | 1.061669183 | 213807264 | 106.17 | Yes | 7 |
| gq | GLibc Quick Sort | 1.065750966 | 220067428 | 106.58 | Yes | 8 |
| fb | Basic Forsort In-Place | 1.252925400 | 373634696 | 125.29 | Yes | 9 |

### 100000000 Items

#### 1 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **1.103701214** | 324426897 | **11.037** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **1.347344817** | 551691891 | **13.473** | No | 2 |
| fs | Stable Forsort In-Place | **1.360549944** | 547120878 | **13.605** | Yes | 3 |
| fiw | Adaptive Forsort Stable (with workspace) | 1.365463398 | 515849323 | 13.655 | Yes | 4 |
| fb | Basic Forsort In-Place | 1.603461611 | 550738763 | 16.035 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 2.842066572 | 2503500147 | 28.421 | No | 6 |
| wi | WikiSort | 3.140806636 | 1991250628 | 31.408 | Yes | 7 |
| gq | GLibc Quick Sort | 3.963380990 | 2138049958 | 39.634 | Yes | 8 |
| gs | Grail Sort In-Place | 4.357375093 | 2022464193 | 43.574 | Yes | 9 |

#### 25 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **3.511762901** | 1862975057 | **35.118** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **3.598834731** | 1935642234 | **35.988** | No | 2 |
| fs | Stable Forsort In-Place | **3.792471113** | 1929483884 | **37.925** | Yes | 3 |
| nq | Bentley/McIlroy Quick Sort | 5.840111748 | 2671105437 | 58.401 | No | 4 |
| ti | TimSort | 6.668467093 | 1534313421 | 66.685 | Yes | 5 |
| wi | WikiSort | 6.784342945 | 2854467621 | 67.843 | Yes | 6 |
| gs | Grail Sort In-Place | 7.354206503 | 2634084984 | 73.542 | Yes | 7 |
| gq | GLibc Quick Sort | 7.717038229 | 2514395611 | 77.170 | Yes | 8 |
| fb | Basic Forsort In-Place | 8.413078525 | 2304678923 | 84.131 | Yes | 9 |

#### 5 Percent Disorder

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **2.096323422** | 925802654 | **20.963** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **2.181575168** | 982528612 | **21.816** | No | 2 |
| fs | Stable Forsort In-Place | **2.201798954** | 974324209 | **22.018** | Yes | 3 |
| ti | TimSort | 2.597649195 | 659692736 | 25.976 | Yes | 4 |
| fb | Basic Forsort In-Place | 3.341289528 | 967795739 | 33.413 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 3.400287669 | 2520521324 | 34.003 | No | 6 |
| wi | WikiSort | 4.232403037 | 2413299341 | 42.324 | Yes | 7 |
| gq | GLibc Quick Sort | 4.844100525 | 2344049524 | 48.441 | Yes | 8 |
| gs | Grail Sort In-Place | 5.459977430 | 2358159772 | 54.600 | Yes | 9 |

#### Limited Range

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **3.789653883** | 2621030913 | **37.897** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **4.104836701** | 2634705082 | **41.048** | No | 2 |
| fs | Stable Forsort In-Place | **4.512989878** | 2741648021 | **45.130** | Yes | 3 |
| gs | Grail Sort In-Place | 9.030153927 | 2655479879 | 90.302 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 9.402445441 | 2751538913 | 94.024 | No | 5 |
| wi | WikiSort | 10.672435346 | 3064122058 | 106.72 | Yes | 6 |
| ti | TimSort | 12.095854445 | 2435364282 | 120.96 | Yes | 7 |
| gq | GLibc Quick Sort | 12.215258690 | 2532637470 | 122.15 | Yes | 8 |
| fb | Basic Forsort In-Place | 14.769281204 | 4273799920 | 147.69 | Yes | 9 |

#### Ordered

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.079081842** | 99999999 | **0.791** | Yes | 1 |
| fs | Stable Forsort In-Place | **0.080633001** | 99999999 | **0.806** | Yes | 2 |
| fb | Basic Forsort In-Place | **0.100024797** | 99999999 | **1.000** | Yes | 3 |
| fi | Adaptive Forsort In-Place | 0.152007804 | 100000429 | 1.520 | Yes | 4 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.189853098 | 100000101 | 1.899 | Yes | 5 |
| wi | WikiSort | 0.243714682 | 223276957 | 2.437 | Yes | 6 |
| gs | Grail Sort In-Place | 2.214857506 | 840204682 | 22.149 | Yes | 7 |
| gq | GLibc Quick Sort | 2.303235210 | 1314447104 | 23.032 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 2.652865079 | 2523417040 | 26.529 | No | 9 |

#### Ordered Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.079217187** | 99999999 | **0.792** | Yes | 1 |
| fs | Stable Forsort In-Place | **0.080541794** | 99999999 | **0.805** | Yes | 2 |
| fb | Basic Forsort In-Place | **0.099996017** | 99999999 | **1.000** | Yes | 3 |
| fi | Adaptive Forsort In-Place | 0.149685117 | 100000429 | 1.497 | Yes | 4 |
| fiw | Adaptive Forsort Stable (with workspace) | 0.189882687 | 100000101 | 1.899 | Yes | 5 |
| wi | WikiSort | 0.243325277 | 223275953 | 2.433 | Yes | 6 |
| gs | Grail Sort In-Place | 2.202765819 | 840185031 | 22.028 | Yes | 7 |
| gq | GLibc Quick Sort | 2.304506974 | 1314447104 | 23.045 | Yes | 8 |
| nq | Bentley/McIlroy Quick Sort | 2.658523015 | 2525165841 | 26.585 | Yes | 9 |

#### Random

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **3.783181915** | 2621030115 | **37.832** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **4.093604774** | 2635150566 | **40.936** | No | 2 |
| fs | Stable Forsort In-Place | **4.469974409** | 2743518385 | **44.700** | Yes | 3 |
| gs | Grail Sort In-Place | 8.974453162 | 2654863274 | 89.745 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 9.559972339 | 2820562427 | 95.600 | No | 5 |
| wi | WikiSort | 10.635332917 | 3063971016 | 106.35 | Yes | 6 |
| ti | TimSort | 12.077294437 | 2435380641 | 120.77 | Yes | 7 |
| gq | GLibc Quick Sort | 12.148851770 | 2532637467 | 121.49 | Yes | 8 |
| fb | Basic Forsort In-Place | 14.585178561 | 4275266654 | 145.85 | Yes | 9 |

#### Reversed

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.868121567** | 167379151 | **8.681** | Yes | 1 |
| wi | WikiSort | **1.350548953** | 295191469 | **13.505** | Yes | 2 |
| gs | Grail Sort In-Place | **2.422775527** | 897888729 | **24.228** | Yes | 3 |
| fs | Stable Forsort In-Place | 3.229902829 | 1615892295 | 32.299 | Yes | 4 |
| fiw | Adaptive Forsort Stable (with workspace) | 3.347335521 | 2240116647 | 33.473 | Yes | 5 |
| nq | Bentley/McIlroy Quick Sort | 3.372368268 | 2911814440 | 33.724 | No | 6 |
| fi | Adaptive Forsort In-Place | 3.792768403 | 2176942046 | 37.928 | No | 7 |
| fb | Basic Forsort In-Place | 4.679310739 | 514026322 | 46.793 | Yes | 8 |
| gq | GLibc Quick Sort | 11.588362201 | 1352082027 | 115.88 | Yes | 9 |

#### Reversed Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| ti | TimSort | **0.102825764** | 99999999 | **1.028** | Yes | 1 |
| fb | Basic Forsort In-Place | **0.230721283** | 199999998 | **2.307** | Yes | 2 |
| fs | Stable Forsort In-Place | **0.534906515** | 208655473 | **5.349** | Yes | 3 |
| wi | WikiSort | 1.264963927 | 266513829 | 12.650 | Yes | 4 |
| gs | Grail Sort In-Place | 2.348047344 | 896694624 | 23.480 | Yes | 5 |
| gq | GLibc Quick Sort | 2.972058287 | 1351335168 | 29.721 | Yes | 6 |
| fiw | Adaptive Forsort Stable (with workspace) | 3.303443774 | 2240136721 | 33.034 | Yes | 7 |
| nq | Bentley/McIlroy Quick Sort | 3.380134247 | 2921036489 | 33.801 | Yes | 8 |
| fi | Adaptive Forsort In-Place | 3.744238391 | 2176935091 | 37.442 | Yes | 9 |

#### Unique

| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |
|-----------|------|----------|-------------|---------|---------|------|
| fiw | Adaptive Forsort Stable (with workspace) | **3.785120686** | 2621030119 | **37.851** | Yes | 1 |
| fi | Adaptive Forsort In-Place | **4.100107391** | 2635150334 | **41.001** | Yes | 2 |
| fs | Stable Forsort In-Place | **4.466211554** | 2743657248 | **44.662** | Yes | 3 |
| gs | Grail Sort In-Place | 8.963878761 | 2654376960 | 89.639 | Yes | 4 |
| nq | Bentley/McIlroy Quick Sort | 9.559498106 | 2823779910 | 95.595 | Yes | 5 |
| wi | WikiSort | 10.656137295 | 3063949880 | 106.56 | Yes | 6 |
| ti | TimSort | 12.077272987 | 2435393106 | 120.77 | Yes | 7 |
| gq | GLibc Quick Sort | 12.285641719 | 2532637467 | 122.86 | Yes | 8 |
| fb | Basic Forsort In-Place | 14.665510673 | 4275274046 | 146.66 | Yes | 9 |


## Stability Verification

| Sort Type | Name | Expected | Verified (1M random) |
|-----------|------|----------|---------------------|
| fb | Basic Forsort In-Place | Stable | Yes |
| fi | Adaptive Forsort In-Place | Unstable | No |
| fiw | Adaptive Forsort Stable (with workspace) | Stable | Yes |
| fs | Stable Forsort In-Place | Stable | Yes |
| gs | Grail Sort In-Place | Stable | Yes |
| gq | GLibc Quick Sort | Unstable | Yes |
| nq | Bentley/McIlroy Quick Sort | Unstable | No |
| ti | TimSort | Stable | Yes |
| wi | WikiSort | Stable | Yes |
| is | Insertion Sort | Stable | N/A |

---
*Generated automatically from benchmark_results.csv*
