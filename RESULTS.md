# ForSort Benchmark Results

## Overview

This document contains comprehensive benchmark results for all sorting algorithms implemented in the ForSort library. Results are organized by dataset size and test variant.

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
| gq | GLibc Quick Sort | Not guaranteed |
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


## Summary by Dataset Size

### Random Data Performance (ns per item, lower is better)

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------|-----------|-----------|-----------|-----------|-----------|
| fb | 62.2 | 74.0 | 91.2 | 104.5 | 124.4 | 145.9 |
| fi | 56.0 | 24.7 | 26.1 | 29.5 | 35.6 | 40.9 |
| fiw | 45.6 | 34.2 | 23.2 | 26.4 | 31.3 | 37.8 |
| fs | 41.3 | 27.0 | 27.3 | 30.6 | 36.4 | 44.7 |
| gq | 55.3 | 68.2 | 83.4 | 93.9 | 106.6 | 121.5 |
| gs | 82.3 | 47.3 | 60.7 | 64.4 | 79.6 | 89.7 |
| is | 53.3 | 136.8 | 1019.4 | -  | -  | -  |
| nq | 47.5 | 49.4 | 83.0 | 82.8 | 84.3 | 95.6 |
| ti | 53.3 | 63.2 | 77.4 | 90.5 | 106.6 | 120.8 |
| wi | 72.5 | 58.5 | 72.1 | 73.4 | 93.7 | 106.4 |

### Average Comparisons (Random Data)

| Sort Type | 1000 items | 10000 items | 100000 items | 1000000 items | 10000000 items | 100000000 items |
|-----------|-----------|-----------|-----------|-----------|-----------|-----------|
| fb | 15138 | 207075 | 2645090 | 31940226 | 373634427 | 4275266654 |
| fi | 10128 | 133036 | 1649240 | 20005479 | 232335444 | 2635150566 |
| fiw | 9543 | 126191 | 1622478 | 19344337 | 225441807 | 2621030115 |
| fs | 10446 | 133652 | 1702919 | 20144873 | 235565948 | 2743518385 |
| gq | 8699 | 120381 | 1536166 | 18671395 | 220067428 | 2532637467 |
| gs | 10421 | 138659 | 1692347 | 20158022 | 237013434 | 2654863274 |
| is | 10897 | 143533 | 1768738 | SKIPPED | SKIPPED | SKIPPED |
| nq | 10449 | 137009 | 1717333 | 20868796 | 244041390 | 2820562427 |
| ti | 8667 | 120349 | 1531408 | 18290497 | 213808938 | 2435380641 |
| wi | 9528 | 143420 | 1828495 | 22371807 | 266846348 | 3063971016 |

## Detailed Results by Dataset Size

### 1000 Items

| Sort Type | Variant | Time (s) | Comparisons | ns/item | Sorted | Stable |
|-----------|---------|----------|-------------|---------|--------|--------|
| fb | 1_percent_disorder | 0.000012059 | 2212 | 12.059 | TRUE | TRUE |
| fb | 25_percent_disorder | 0.000073898 | 9126 | 73.898 | TRUE | TRUE |
| fb | 5_percent_disorder | 0.000028509 | 4435 | 28.509 | TRUE | TRUE |
| fb | limited_range | 0.000107436 | 15144 | 107.436 | TRUE | TRUE |
| fb | ordered | 0.000002100 | 999 | 2.100 | TRUE | TRUE |
| fb | ordered_unique | 0.000002410 | 999 | 2.410 | TRUE | TRUE |
| fb | reversed | 0.000005060 | 1998 | 5.060 | TRUE | TRUE |
| fb | reversed_unique | 0.000004960 | 1998 | 4.960 | TRUE | TRUE |
| fb | unique | 0.000068188 | 15138 | 68.188 | TRUE | TRUE |
| fi | 1_percent_disorder | 0.000017370 | 1496 | 17.370 | TRUE | TRUE |
| fi | 25_percent_disorder | 0.000036388 | 7835 | 36.388 | TRUE | TRUE |
| fi | 5_percent_disorder | 0.000021559 | 3455 | 21.559 | TRUE | TRUE |
| fi | limited_range | 0.000057058 | 10166 | 57.058 | TRUE | FALSE |
| fi | ordered | 0.000007839 | 1052 | 7.839 | TRUE | TRUE |
| fi | ordered_unique | 0.000007740 | 1052 | 7.740 | TRUE | TRUE |
| fi | random | 0.000055958 | 10128 | 55.958 | TRUE | TRUE |
| fi | reversed | 0.000031499 | 6407 | 31.499 | TRUE | TRUE |
| fi | reversed_unique | 0.000031309 | 6407 | 31.309 | TRUE | TRUE |
| fi | unique | 0.000056438 | 10128 | 56.438 | TRUE | TRUE |
| fiw | 1_percent_disorder | 0.000008649 | 1355 | 8.649 | TRUE | TRUE |
| fiw | 25_percent_disorder | 0.000049028 | 7428 | 49.028 | TRUE | TRUE |
| fiw | 5_percent_disorder | 0.000024579 | 3122 | 24.579 | TRUE | TRUE |
| fiw | limited_range | 0.000030449 | 9545 | 30.449 | TRUE | TRUE |
| fiw | ordered | 0.000007520 | 1028 | 7.520 | TRUE | TRUE |
| fiw | ordered_unique | 0.000005440 | 1028 | 5.440 | TRUE | TRUE |
| fiw | random | 0.000045638 | 9543 | 45.638 | TRUE | TRUE |
| fiw | reversed | 0.000024159 | 6614 | 24.159 | TRUE | TRUE |
| fiw | reversed_unique | 0.000025030 | 6614 | 25.030 | TRUE | TRUE |
| fiw | unique | 0.000045668 | 9543 | 45.668 | TRUE | TRUE |
| fs | 1_percent_disorder | 0.000014210 | 2744 | 14.210 | TRUE | TRUE |
| fs | 25_percent_disorder | 0.000071718 | 8302 | 71.718 | TRUE | TRUE |
| fs | 5_percent_disorder | 0.000030349 | 3521 | 30.349 | TRUE | TRUE |
| fs | limited_range | 0.000064068 | 10564 | 64.068 | TRUE | TRUE |
| fs | ordered | 0.000002170 | 999 | 2.170 | TRUE | TRUE |
| fs | ordered_unique | 0.000002450 | 999 | 2.450 | TRUE | TRUE |
| fs | random | 0.000041308 | 10446 | 41.308 | TRUE | TRUE |
| fs | reversed | 0.000009800 | 2551 | 9.800 | TRUE | TRUE |
| fs | reversed_unique | 0.000013420 | 2551 | 13.420 | TRUE | TRUE |
| fs | unique | 0.000062757 | 10446 | 62.757 | TRUE | TRUE |
| gq | 1_percent_disorder | 0.000024669 | 5016 | 24.669 | TRUE | TRUE |
| gq | 25_percent_disorder | 0.000055608 | 8064 | 55.608 | TRUE | TRUE |
| gq | 5_percent_disorder | 0.000031479 | 5673 | 31.479 | TRUE | TRUE |
| gq | limited_range | 0.000050078 | 8702 | 50.078 | TRUE | TRUE |
| gq | ordered | 0.000013949 | 4932 | 13.949 | TRUE | TRUE |
| gq | ordered_unique | 0.000013290 | 4932 | 13.290 | TRUE | TRUE |
| gq | random | 0.000055308 | 8699 | 55.308 | TRUE | TRUE |
| gq | reversed | 0.000015370 | 5044 | 15.370 | TRUE | TRUE |
| gq | reversed_unique | 0.000023950 | 5044 | 23.950 | TRUE | TRUE |
| gq | unique | 0.000086397 | 8699 | 86.397 | TRUE | TRUE |
| gs | 1_percent_disorder | 0.000025879 | 4933 | 25.879 | TRUE | TRUE |
| gs | 25_percent_disorder | 0.000061358 | 9042 | 61.358 | TRUE | TRUE |
| gs | 5_percent_disorder | 0.000033699 | 5713 | 33.699 | TRUE | TRUE |
| gs | limited_range | 0.000048369 | 10486 | 48.369 | TRUE | TRUE |
| gs | ordered | 0.000022299 | 4790 | 22.299 | TRUE | TRUE |
| gs | ordered_unique | 0.000016840 | 4790 | 16.840 | TRUE | TRUE |
| gs | random | 0.000082317 | 10421 | 82.317 | TRUE | TRUE |
| gs | reversed | 0.000027459 | 5112 | 27.459 | TRUE | TRUE |
| gs | reversed_unique | 0.000026959 | 5112 | 26.959 | TRUE | TRUE |
| gs | unique | 0.000083937 | 10421 | 83.937 | TRUE | TRUE |
| is | 1_percent_disorder | 0.000003850 | 1926 | 3.850 | TRUE | TRUE |
| is | 25_percent_disorder | 0.000031149 | 10569 | 31.149 | TRUE | TRUE |
| is | 5_percent_disorder | 0.000012759 | 7002 | 12.759 | TRUE | TRUE |
| is | limited_range | 0.000051568 | 10897 | 51.568 | TRUE | TRUE |
| is | ordered | 0.000001260 | 999 | 1.260 | TRUE | TRUE |
| is | ordered_unique | 0.000001279 | 999 | 1.279 | TRUE | TRUE |
| is | random | 0.000053268 | 10897 | 53.268 | TRUE | TRUE |
| is | reversed | 0.000025629 | 10980 | 25.629 | TRUE | TRUE |
| is | reversed_unique | 0.000025659 | 10980 | 25.659 | TRUE | TRUE |
| is | unique | 0.000051778 | 10897 | 51.778 | TRUE | TRUE |
| nq | 1_percent_disorder | 0.000013350 | 8304 | 13.350 | TRUE | TRUE |
| nq | 25_percent_disorder | 0.000040659 | 9211 | 40.659 | TRUE | TRUE |
| nq | 5_percent_disorder | 0.000015160 | 8389 | 15.160 | TRUE | TRUE |
| nq | limited_range | 0.000070337 | 9551 | 70.337 | TRUE | FALSE |
| nq | ordered | 0.000017710 | 8192 | 17.710 | TRUE | TRUE |
| nq | ordered_unique | 0.000017989 | 8192 | 17.989 | TRUE | TRUE |
| nq | random | 0.000047519 | 10449 | 47.519 | TRUE | TRUE |
| nq | reversed | 0.000033209 | 14222 | 33.209 | TRUE | TRUE |
| nq | reversed_unique | 0.000033059 | 14222 | 33.059 | TRUE | TRUE |
| nq | unique | 0.000069058 | 10449 | 69.058 | TRUE | TRUE |
| ti | 1_percent_disorder | 0.000014589 | 2235 | 14.589 | TRUE | TRUE |
| ti | 25_percent_disorder | 0.000060768 | 7010 | 60.768 | TRUE | TRUE |
| ti | 5_percent_disorder | 0.000028589 | 3759 | 28.589 | TRUE | TRUE |
| ti | limited_range | 0.000056558 | 8670 | 56.558 | TRUE | TRUE |
| ti | ordered | 0.000002610 | 999 | 2.610 | TRUE | TRUE |
| ti | ordered_unique | 0.000003809 | 999 | 3.809 | TRUE | TRUE |
| ti | random | 0.000053308 | 8667 | 53.308 | TRUE | TRUE |
| ti | reversed | 0.000004399 | 999 | 4.399 | TRUE | TRUE |
| ti | reversed_unique | 0.000003990 | 999 | 3.990 | TRUE | TRUE |
| ti | unique | 0.000086737 | 8667 | 86.737 | TRUE | TRUE |
| wi | 1_percent_disorder | 0.000011609 | 2792 | 11.609 | TRUE | TRUE |
| wi | 25_percent_disorder | 0.000055068 | 8846 | 55.068 | TRUE | TRUE |
| wi | 5_percent_disorder | 0.000027469 | 5635 | 27.469 | TRUE | TRUE |
| wi | limited_range | 0.000067888 | 9532 | 67.888 | TRUE | TRUE |
| wi | ordered | 0.000008560 | 2530 | 8.560 | TRUE | TRUE |
| wi | ordered_unique | 0.000011300 | 2530 | 11.300 | TRUE | TRUE |
| wi | random | 0.000072487 | 9528 | 72.487 | TRUE | TRUE |
| wi | reversed | 0.000015249 | 3287 | 15.249 | TRUE | TRUE |
| wi | reversed_unique | 0.000015349 | 3287 | 15.349 | TRUE | TRUE |
| wi | unique | 0.000048768 | 9528 | 48.768 | TRUE | TRUE |

### 10000 Items

| Sort Type | Variant | Time (s) | Comparisons | ns/item | Sorted | Stable |
|-----------|---------|----------|-------------|---------|--------|--------|
| fb | 1_percent_disorder | 0.000077597 | 32359 | 7.760 | TRUE | TRUE |
| fb | 25_percent_disorder | 0.000487503 | 126347 | 48.750 | TRUE | TRUE |
| fb | 5_percent_disorder | 0.000313618 | 60447 | 31.362 | TRUE | TRUE |
| fb | limited_range | 0.000783252 | 207099 | 78.325 | TRUE | TRUE |
| fb | ordered | 0.000010229 | 9999 | 1.023 | TRUE | TRUE |
| fb | ordered_unique | 0.000017179 | 9999 | 1.718 | TRUE | TRUE |
| fb | reversed | 0.000037109 | 19998 | 3.711 | TRUE | TRUE |
| fb | reversed_unique | 0.000021659 | 19998 | 2.166 | TRUE | TRUE |
| fb | unique | 0.000811241 | 207075 | 81.124 | TRUE | TRUE |
| fi | 1_percent_disorder | 0.000066588 | 22792 | 6.659 | TRUE | TRUE |
| fi | 25_percent_disorder | 0.000435074 | 104888 | 43.507 | TRUE | TRUE |
| fi | 5_percent_disorder | 0.000154314 | 49717 | 15.431 | TRUE | TRUE |
| fi | limited_range | 0.000246871 | 133040 | 24.687 | TRUE | FALSE |
| fi | ordered | 0.000082937 | 10091 | 8.294 | TRUE | TRUE |
| fi | ordered_unique | 0.000011629 | 10091 | 1.163 | TRUE | TRUE |
| fi | random | 0.000246761 | 133036 | 24.676 | TRUE | TRUE |
| fi | reversed | 0.000125235 | 93366 | 12.523 | TRUE | TRUE |
| fi | reversed_unique | 0.000122856 | 93366 | 12.286 | TRUE | TRUE |
| fi | unique | 0.000415716 | 133036 | 41.572 | TRUE | TRUE |
| fiw | 1_percent_disorder | 0.000057558 | 21323 | 5.756 | TRUE | TRUE |
| fiw | 25_percent_disorder | 0.000238232 | 101352 | 23.823 | TRUE | TRUE |
| fiw | 5_percent_disorder | 0.000137015 | 46217 | 13.701 | TRUE | TRUE |
| fiw | limited_range | 0.000205113 | 126206 | 20.511 | TRUE | TRUE |
| fiw | ordered | 0.000011960 | 10049 | 1.196 | TRUE | TRUE |
| fiw | ordered_unique | 0.000011659 | 10049 | 1.166 | TRUE | TRUE |
| fiw | random | 0.000342488 | 126191 | 34.249 | TRUE | TRUE |
| fiw | reversed | 0.000116335 | 98010 | 11.633 | TRUE | TRUE |
| fiw | reversed_unique | 0.000116276 | 98010 | 11.628 | TRUE | TRUE |
| fiw | unique | 0.000219742 | 126191 | 21.974 | TRUE | TRUE |
| fs | 1_percent_disorder | 0.000068208 | 24197 | 6.821 | TRUE | TRUE |
| fs | 25_percent_disorder | 0.000406956 | 106432 | 40.696 | TRUE | TRUE |
| fs | 5_percent_disorder | 0.000178373 | 50742 | 17.837 | TRUE | TRUE |
| fs | limited_range | 0.000264490 | 133710 | 26.449 | TRUE | TRUE |
| fs | ordered | 0.000008490 | 9999 | 0.849 | TRUE | TRUE |
| fs | ordered_unique | 0.000008470 | 9999 | 0.847 | TRUE | TRUE |
| fs | random | 0.000270210 | 133652 | 27.021 | TRUE | TRUE |
| fs | reversed | 0.000031939 | 21910 | 3.194 | TRUE | TRUE |
| fs | reversed_unique | 0.000047128 | 21910 | 4.713 | TRUE | TRUE |
| fs | unique | 0.000266910 | 133652 | 26.691 | TRUE | TRUE |
| gq | 1_percent_disorder | 0.000149764 | 69350 | 14.976 | TRUE | TRUE |
| gq | 25_percent_disorder | 0.000453104 | 115721 | 45.310 | TRUE | TRUE |
| gq | 5_percent_disorder | 0.000420024 | 91579 | 42.002 | TRUE | TRUE |
| gq | limited_range | 0.000675136 | 120379 | 67.514 | TRUE | TRUE |
| gq | ordered | 0.000213533 | 64608 | 21.353 | TRUE | TRUE |
| gq | ordered_unique | 0.000138975 | 64608 | 13.898 | TRUE | TRUE |
| gq | random | 0.000682356 | 120381 | 68.236 | TRUE | TRUE |
| gq | reversed | 0.000166114 | 69008 | 16.611 | TRUE | TRUE |
| gq | reversed_unique | 0.000268730 | 69008 | 26.873 | TRUE | TRUE |
| gq | unique | 0.002087236 | 120381 | 208.724 | TRUE | TRUE |
| gs | 1_percent_disorder | 0.000141555 | 60937 | 14.155 | TRUE | TRUE |
| gs | 25_percent_disorder | 0.000383186 | 127531 | 38.319 | TRUE | TRUE |
| gs | 5_percent_disorder | 0.000189983 | 89970 | 18.998 | TRUE | TRUE |
| gs | limited_range | 0.000479623 | 138958 | 47.962 | TRUE | TRUE |
| gs | ordered | 0.000100207 | 53332 | 10.021 | TRUE | TRUE |
| gs | ordered_unique | 0.000108546 | 53332 | 10.855 | TRUE | TRUE |
| gs | random | 0.000472893 | 138659 | 47.289 | TRUE | TRUE |
| gs | reversed | 0.000101377 | 57076 | 10.138 | TRUE | TRUE |
| gs | reversed_unique | 0.000173013 | 57076 | 17.301 | TRUE | TRUE |
| gs | unique | 0.000476833 | 138659 | 47.683 | TRUE | TRUE |
| is | 1_percent_disorder | 0.000091416 | 66299 | 9.142 | TRUE | TRUE |
| is | 25_percent_disorder | 0.000486912 | 143007 | 48.691 | TRUE | TRUE |
| is | 5_percent_disorder | 0.000226402 | 141517 | 22.640 | TRUE | TRUE |
| is | limited_range | 0.001200917 | 143533 | 120.092 | TRUE | TRUE |
| is | ordered | 0.000011120 | 9999 | 1.112 | TRUE | TRUE |
| is | ordered_unique | 0.000011200 | 9999 | 1.120 | TRUE | TRUE |
| is | random | 0.001368470 | 143533 | 136.847 | TRUE | TRUE |
| is | reversed | 0.002442652 | 143612 | 244.265 | TRUE | TRUE |
| is | reversed_unique | 0.002122203 | 143612 | 212.220 | TRUE | TRUE |
| is | unique | 0.001214906 | 143533 | 121.491 | TRUE | TRUE |
| nq | 1_percent_disorder | 0.000135725 | 112554 | 13.572 | TRUE | TRUE |
| nq | 25_percent_disorder | 0.000384946 | 126774 | 38.495 | TRUE | TRUE |
| nq | 5_percent_disorder | 0.000167744 | 116444 | 16.774 | TRUE | TRUE |
| nq | limited_range | 0.000513931 | 130174 | 51.393 | TRUE | FALSE |
| nq | ordered | 0.000132115 | 111539 | 13.211 | TRUE | TRUE |
| nq | ordered_unique | 0.000209872 | 111539 | 20.987 | TRUE | TRUE |
| nq | random | 0.000493912 | 137009 | 49.391 | TRUE | TRUE |
| nq | reversed | 0.000242651 | 192779 | 24.265 | TRUE | TRUE |
| nq | reversed_unique | 0.000258140 | 192779 | 25.814 | TRUE | TRUE |
| nq | unique | 0.000495582 | 137009 | 49.558 | TRUE | TRUE |
| ti | 1_percent_disorder | 0.000060907 | 20318 | 6.091 | TRUE | TRUE |
| ti | 25_percent_disorder | 0.000418275 | 96274 | 41.828 | TRUE | TRUE |
| ti | 5_percent_disorder | 0.000174824 | 41101 | 17.482 | TRUE | TRUE |
| ti | limited_range | 0.000662056 | 120348 | 66.206 | TRUE | TRUE |
| ti | ordered | 0.000009619 | 9999 | 0.962 | TRUE | TRUE |
| ti | ordered_unique | 0.000009209 | 9999 | 0.921 | TRUE | TRUE |
| ti | random | 0.000631537 | 120349 | 63.154 | TRUE | TRUE |
| ti | reversed | 0.000010050 | 9999 | 1.005 | TRUE | TRUE |
| ti | reversed_unique | 0.000010960 | 9999 | 1.096 | TRUE | TRUE |
| ti | unique | 0.000647357 | 120349 | 64.736 | TRUE | TRUE |
| wi | 1_percent_disorder | 0.000086466 | 47827 | 8.647 | TRUE | TRUE |
| wi | 25_percent_disorder | 0.000326858 | 132042 | 32.686 | TRUE | TRUE |
| wi | 5_percent_disorder | 0.000182703 | 94710 | 18.270 | TRUE | TRUE |
| wi | limited_range | 0.000508322 | 143437 | 50.832 | TRUE | TRUE |
| wi | ordered | 0.000035369 | 23662 | 3.537 | TRUE | TRUE |
| wi | ordered_unique | 0.000034679 | 23662 | 3.468 | TRUE | TRUE |
| wi | random | 0.000585399 | 143420 | 58.540 | TRUE | TRUE |
| wi | reversed | 0.000056848 | 25008 | 5.685 | TRUE | TRUE |
| wi | reversed_unique | 0.000056168 | 25008 | 5.617 | TRUE | TRUE |
| wi | unique | 0.000758702 | 143420 | 75.870 | TRUE | TRUE |

### 100000 Items

| Sort Type | Variant | Time (s) | Comparisons | ns/item | Sorted | Stable |
|-----------|---------|----------|-------------|---------|--------|--------|
| fb | 1_percent_disorder | 0.000968676 | 431804 | 9.687 | TRUE | TRUE |
| fb | 25_percent_disorder | 0.005596500 | 1535002 | 55.965 | TRUE | TRUE |
| fb | 5_percent_disorder | 0.002131864 | 735032 | 21.319 | TRUE | TRUE |
| fb | limited_range | 0.009448831 | 2642972 | 94.488 | TRUE | TRUE |
| fb | ordered | 0.000097477 | 99999 | 0.975 | TRUE | TRUE |
| fb | ordered_unique | 0.000100676 | 99999 | 1.007 | TRUE | TRUE |
| fb | reversed | 0.000401525 | 203803 | 4.015 | TRUE | TRUE |
| fb | reversed_unique | 0.000200623 | 199998 | 2.006 | TRUE | TRUE |
| fb | unique | 0.009644445 | 2645089 | 96.444 | TRUE | TRUE |
| fi | 1_percent_disorder | 0.000756763 | 308065 | 7.568 | TRUE | TRUE |
| fi | 25_percent_disorder | 0.002576188 | 1268232 | 25.762 | TRUE | TRUE |
| fi | 5_percent_disorder | 0.001512006 | 656475 | 15.120 | TRUE | TRUE |
| fi | limited_range | 0.002625766 | 1648605 | 26.258 | TRUE | FALSE |
| fi | ordered | 0.000111316 | 100167 | 1.113 | TRUE | TRUE |
| fi | ordered_unique | 0.000108686 | 100167 | 1.087 | TRUE | TRUE |
| fi | random | 0.002610436 | 1649240 | 26.104 | TRUE | TRUE |
| fi | reversed | 0.001433769 | 1201403 | 14.338 | TRUE | TRUE |
| fi | reversed_unique | 0.001436638 | 1201428 | 14.366 | TRUE | TRUE |
| fi | unique | 0.002607227 | 1649183 | 26.072 | TRUE | TRUE |
| fiw | 1_percent_disorder | 0.001021274 | 293036 | 10.213 | TRUE | TRUE |
| fiw | 25_percent_disorder | 0.002389155 | 1236866 | 23.892 | TRUE | TRUE |
| fiw | 5_percent_disorder | 0.001463818 | 625323 | 14.638 | TRUE | TRUE |
| fiw | limited_range | 0.002336887 | 1622428 | 23.369 | TRUE | TRUE |
| fiw | ordered | 0.000139315 | 100078 | 1.393 | TRUE | TRUE |
| fiw | ordered_unique | 0.000128615 | 100078 | 1.286 | TRUE | TRUE |
| fiw | random | 0.002317147 | 1622478 | 23.171 | TRUE | TRUE |
| fiw | reversed | 0.001499586 | 1235508 | 14.996 | TRUE | TRUE |
| fiw | reversed_unique | 0.001397330 | 1235508 | 13.973 | TRUE | TRUE |
| fiw | unique | 0.002313057 | 1622478 | 23.131 | TRUE | TRUE |
| fs | 1_percent_disorder | 0.000779772 | 318465 | 7.798 | TRUE | TRUE |
| fs | 25_percent_disorder | 0.002668225 | 1266212 | 26.682 | TRUE | TRUE |
| fs | 5_percent_disorder | 0.001520906 | 599475 | 15.209 | TRUE | TRUE |
| fs | limited_range | 0.002869547 | 1702536 | 28.695 | TRUE | TRUE |
| fs | ordered | 0.000078317 | 99999 | 0.783 | TRUE | TRUE |
| fs | ordered_unique | 0.000078238 | 99999 | 0.782 | TRUE | TRUE |
| fs | random | 0.002734562 | 1702919 | 27.346 | TRUE | TRUE |
| fs | reversed | 0.000431305 | 219263 | 4.313 | TRUE | TRUE |
| fs | reversed_unique | 0.000285490 | 210306 | 2.855 | TRUE | TRUE |
| fs | unique | 0.002828629 | 1703019 | 28.286 | TRUE | TRUE |
| gq | 1_percent_disorder | 0.003628970 | 1046328 | 36.290 | TRUE | TRUE |
| gq | 25_percent_disorder | 0.005049109 | 1511072 | 50.491 | TRUE | TRUE |
| gq | 5_percent_disorder | 0.003068760 | 1299870 | 30.688 | TRUE | TRUE |
| gq | limited_range | 0.008257931 | 1536166 | 82.579 | TRUE | TRUE |
| gq | ordered | 0.001638112 | 815024 | 16.381 | TRUE | TRUE |
| gq | ordered_unique | 0.001594133 | 815024 | 15.941 | TRUE | TRUE |
| gq | random | 0.008340102 | 1536166 | 83.401 | TRUE | TRUE |
| gq | reversed | 0.001980549 | 853905 | 19.805 | TRUE | TRUE |
| gq | reversed_unique | 0.001942371 | 853904 | 19.424 | TRUE | TRUE |
| gq | unique | 0.012036289 | 1536166 | 120.363 | TRUE | TRUE |
| gs | 1_percent_disorder | 0.001823925 | 904672 | 18.239 | TRUE | TRUE |
| gs | 25_percent_disorder | 0.004328875 | 1633206 | 43.289 | TRUE | TRUE |
| gs | 5_percent_disorder | 0.002522779 | 1280038 | 25.228 | TRUE | TRUE |
| gs | limited_range | 0.005787683 | 1691595 | 57.877 | TRUE | TRUE |
| gs | ordered | 0.001100611 | 608786 | 11.006 | TRUE | TRUE |
| gs | ordered_unique | 0.001056092 | 608786 | 10.561 | TRUE | TRUE |
| gs | random | 0.006068133 | 1692347 | 60.681 | TRUE | TRUE |
| gs | reversed | 0.001108910 | 627302 | 11.089 | TRUE | TRUE |
| gs | reversed_unique | 0.001059772 | 627299 | 10.598 | TRUE | TRUE |
| gs | unique | 0.005745774 | 1692166 | 57.458 | TRUE | TRUE |
| is | 1_percent_disorder | 0.002281058 | 1743774 | 22.811 | TRUE | TRUE |
| is | 25_percent_disorder | 0.012885684 | 1768284 | 128.857 | TRUE | TRUE |
| is | 5_percent_disorder | 0.003005802 | 1764569 | 30.058 | TRUE | TRUE |
| is | limited_range | 0.099659918 | 1768738 | 996.599 | TRUE | TRUE |
| is | ordered | 0.000109846 | 99999 | 1.098 | TRUE | TRUE |
| is | ordered_unique | 0.000100356 | 99999 | 1.004 | TRUE | TRUE |
| is | random | 0.101941096 | 1768738 | 1019.411 | TRUE | TRUE |
| is | reversed | 0.239175287 | 1768918 | 2391.753 | TRUE | TRUE |
| is | reversed_unique | 0.249064310 | 1768918 | 2490.643 | TRUE | TRUE |
| is | unique | 0.101343737 | 1768738 | 1013.437 | TRUE | TRUE |
| nq | 1_percent_disorder | 0.001797805 | 1516043 | 17.978 | TRUE | TRUE |
| nq | 25_percent_disorder | 0.003644438 | 1625332 | 36.444 | TRUE | FALSE |
| nq | 5_percent_disorder | 0.002155542 | 1515354 | 21.555 | TRUE | FALSE |
| nq | limited_range | 0.006602751 | 1640156 | 66.028 | TRUE | FALSE |
| nq | ordered | 0.001796505 | 1524581 | 17.965 | TRUE | TRUE |
| nq | ordered_unique | 0.002000238 | 1524583 | 20.002 | TRUE | TRUE |
| nq | random | 0.008301290 | 1717333 | 83.013 | TRUE | FALSE |
| nq | reversed | 0.002390784 | 1935554 | 23.908 | TRUE | FALSE |
| nq | reversed_unique | 0.002271958 | 1935567 | 22.720 | TRUE | TRUE |
| nq | unique | 0.006790375 | 1717336 | 67.904 | TRUE | TRUE |
| ti | 1_percent_disorder | 0.000732853 | 254708 | 7.329 | TRUE | TRUE |
| ti | 25_percent_disorder | 0.004758128 | 1092617 | 47.581 | TRUE | TRUE |
| ti | 5_percent_disorder | 0.001956529 | 522910 | 19.565 | TRUE | TRUE |
| ti | limited_range | 0.008076078 | 1531448 | 80.761 | TRUE | TRUE |
| ti | ordered | 0.000082567 | 99999 | 0.826 | TRUE | TRUE |
| ti | ordered_unique | 0.000083177 | 99999 | 0.832 | TRUE | TRUE |
| ti | random | 0.007742790 | 1531408 | 77.428 | TRUE | TRUE |
| ti | reversed | 0.000239812 | 100112 | 2.398 | TRUE | TRUE |
| ti | reversed_unique | 0.000099466 | 99999 | 0.995 | TRUE | TRUE |
| ti | unique | 0.007951243 | 1531408 | 79.512 | TRUE | TRUE |
| wi | 1_percent_disorder | 0.001292963 | 936287 | 12.930 | TRUE | TRUE |
| wi | 25_percent_disorder | 0.004045363 | 1724079 | 40.454 | TRUE | TRUE |
| wi | 5_percent_disorder | 0.002203040 | 1321121 | 22.030 | TRUE | TRUE |
| wi | limited_range | 0.006188756 | 1828864 | 61.888 | TRUE | TRUE |
| wi | ordered | 0.000271350 | 240530 | 2.713 | TRUE | TRUE |
| wi | ordered_unique | 0.000273750 | 240530 | 2.737 | TRUE | TRUE |
| wi | random | 0.007214729 | 1828495 | 72.147 | TRUE | TRUE |
| wi | reversed | 0.000696945 | 284049 | 6.969 | TRUE | TRUE |
| wi | reversed_unique | 0.000554540 | 284046 | 5.545 | TRUE | TRUE |
| wi | unique | 0.006839023 | 1828495 | 68.390 | TRUE | TRUE |

### 1000000 Items

| Sort Type | Variant | Time (s) | Comparisons | ns/item | Sorted | Stable |
|-----------|---------|----------|-------------|---------|--------|--------|
| fb | 1_percent_disorder | 0.011824706 | 4912080 | 11.825 | TRUE | TRUE |
| fb | 25_percent_disorder | 0.062090296 | 17971590 | 62.090 | TRUE | TRUE |
| fb | 5_percent_disorder | 0.024228102 | 8177254 | 24.228 | TRUE | TRUE |
| fb | limited_range | 0.105384465 | 31924599 | 105.384 | TRUE | TRUE |
| fb | ordered | 0.000974725 | 999999 | 0.975 | TRUE | TRUE |
| fb | ordered_unique | 0.001213817 | 999999 | 1.214 | TRUE | TRUE |
| fb | reversed | 0.008925540 | 2216282 | 8.926 | TRUE | TRUE |
| fb | reversed_unique | 0.002021358 | 1999998 | 2.021 | TRUE | TRUE |
| fb | unique | 0.106708507 | 31940258 | 106.709 | TRUE | TRUE |
| fi | 1_percent_disorder | 0.009121633 | 3524638 | 9.122 | TRUE | FALSE |
| fi | 25_percent_disorder | 0.027340441 | 15090266 | 27.340 | TRUE | FALSE |
| fi | 5_percent_disorder | 0.016007866 | 7699280 | 16.008 | TRUE | FALSE |
| fi | limited_range | 0.029958947 | 20000785 | 29.959 | TRUE | FALSE |
| fi | ordered | 0.001045892 | 1000212 | 1.046 | TRUE | TRUE |
| fi | ordered_unique | 0.001013073 | 1000212 | 1.013 | TRUE | TRUE |
| fi | random | 0.029531732 | 20005479 | 29.532 | TRUE | FALSE |
| fi | reversed | 0.018529626 | 15784291 | 18.530 | TRUE | TRUE |
| fi | reversed_unique | 0.019235321 | 15784214 | 19.235 | TRUE | TRUE |
| fi | unique | 0.031279100 | 20003927 | 31.279 | TRUE | TRUE |
| fiw | 1_percent_disorder | 0.008638140 | 3374464 | 8.638 | TRUE | TRUE |
| fiw | 25_percent_disorder | 0.026923826 | 14553714 | 26.924 | TRUE | TRUE |
| fiw | 5_percent_disorder | 0.015577082 | 7201084 | 15.577 | TRUE | TRUE |
| fiw | limited_range | 0.026396514 | 19344227 | 26.397 | TRUE | TRUE |
| fiw | ordered | 0.001382830 | 1000058 | 1.383 | TRUE | TRUE |
| fiw | ordered_unique | 0.001376600 | 1000058 | 1.377 | TRUE | TRUE |
| fiw | random | 0.026373855 | 19344337 | 26.374 | TRUE | TRUE |
| fiw | reversed | 0.018613263 | 16420327 | 18.613 | TRUE | TRUE |
| fiw | reversed_unique | 0.019861359 | 16420327 | 19.861 | TRUE | TRUE |
| fiw | unique | 0.026218071 | 19344337 | 26.218 | TRUE | TRUE |
| fs | 1_percent_disorder | 0.008619961 | 3612221 | 8.620 | TRUE | TRUE |
| fs | 25_percent_disorder | 0.029259242 | 14945609 | 29.259 | TRUE | TRUE |
| fs | 5_percent_disorder | 0.015943179 | 7242401 | 15.943 | TRUE | TRUE |
| fs | limited_range | 0.030791037 | 20136481 | 30.791 | TRUE | TRUE |
| fs | ordered | 0.000807591 | 999999 | 0.808 | TRUE | TRUE |
| fs | ordered_unique | 0.001193887 | 999999 | 1.194 | TRUE | TRUE |
| fs | random | 0.030647622 | 20144873 | 30.648 | TRUE | TRUE |
| fs | reversed | 0.005621908 | 2336292 | 5.622 | TRUE | TRUE |
| fs | reversed_unique | 0.002955334 | 2088913 | 2.955 | TRUE | TRUE |
| fs | unique | 0.030142410 | 20144554 | 30.142 | TRUE | TRUE |
| gq | 1_percent_disorder | 0.027088189 | 14447185 | 27.088 | TRUE | TRUE |
| gq | 25_percent_disorder | 0.055857279 | 18502661 | 55.857 | TRUE | TRUE |
| gq | 5_percent_disorder | 0.034837262 | 16530918 | 34.837 | TRUE | TRUE |
| gq | limited_range | 0.093026268 | 18671395 | 93.026 | TRUE | TRUE |
| gq | ordered | 0.017775313 | 9884992 | 17.775 | TRUE | TRUE |
| gq | ordered_unique | 0.018029434 | 9884992 | 18.029 | TRUE | TRUE |
| gq | random | 0.093861727 | 18671395 | 93.862 | TRUE | TRUE |
| gq | reversed | 0.083921983 | 10066547 | 83.922 | TRUE | TRUE |
| gq | reversed_unique | 0.021209240 | 10066432 | 21.209 | TRUE | TRUE |
| gq | unique | 0.091828160 | 18671395 | 91.828 | TRUE | TRUE |
| gs | 1_percent_disorder | 0.028079364 | 13144367 | 28.079 | TRUE | TRUE |
| gs | 25_percent_disorder | 0.053379807 | 19780452 | 53.380 | TRUE | TRUE |
| gs | 5_percent_disorder | 0.035399901 | 16672002 | 35.400 | TRUE | TRUE |
| gs | limited_range | 0.066407921 | 20156763 | 66.408 | TRUE | TRUE |
| gs | ordered | 0.014602857 | 7019441 | 14.603 | TRUE | TRUE |
| gs | ordered_unique | 0.014657705 | 7019410 | 14.658 | TRUE | TRUE |
| gs | random | 0.064381093 | 20158022 | 64.381 | TRUE | TRUE |
| gs | reversed | 0.015426737 | 7552170 | 15.427 | TRUE | TRUE |
| gs | reversed_unique | 0.017415426 | 7551070 | 17.415 | TRUE | TRUE |
| gs | unique | 0.065401727 | 20154575 | 65.402 | TRUE | TRUE |
| is | 1_percent_disorder | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | 25_percent_disorder | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | 5_percent_disorder | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | limited_range | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | ordered | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | ordered_unique | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | random | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | reversed | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | reversed_unique | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | unique | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| nq | 1_percent_disorder | 0.021077138 | 18248470 | 21.077 | TRUE | FALSE |
| nq | 25_percent_disorder | 0.043419721 | 19802661 | 43.420 | TRUE | FALSE |
| nq | 5_percent_disorder | 0.024955768 | 18492866 | 24.956 | TRUE | FALSE |
| nq | limited_range | 0.073671518 | 20553611 | 73.672 | TRUE | FALSE |
| nq | ordered | 0.021479554 | 18196494 | 21.480 | TRUE | FALSE |
| nq | ordered_unique | 0.019261524 | 18196618 | 19.262 | TRUE | TRUE |
| nq | random | 0.082824257 | 20868796 | 82.824 | TRUE | FALSE |
| nq | reversed | 0.029923208 | 24024292 | 29.923 | TRUE | FALSE |
| nq | reversed_unique | 0.026941536 | 24025703 | 26.942 | TRUE | TRUE |
| nq | unique | 0.075438724 | 20868688 | 75.439 | TRUE | TRUE |
| ti | 1_percent_disorder | 0.008639678 | 3191636 | 8.640 | TRUE | TRUE |
| ti | 25_percent_disorder | 0.054443752 | 12434342 | 54.444 | TRUE | TRUE |
| ti | 5_percent_disorder | 0.021276141 | 6025478 | 21.276 | TRUE | TRUE |
| ti | limited_range | 0.097309013 | 18290244 | 97.309 | TRUE | TRUE |
| ti | ordered | 0.000846679 | 999999 | 0.847 | TRUE | TRUE |
| ti | ordered_unique | 0.000785101 | 999999 | 0.785 | TRUE | TRUE |
| ti | random | 0.090494780 | 18290497 | 90.495 | TRUE | TRUE |
| ti | reversed | 0.002881666 | 1006818 | 2.882 | TRUE | TRUE |
| ti | reversed_unique | 0.001852113 | 999999 | 1.852 | TRUE | TRUE |
| ti | unique | 0.090165851 | 18290499 | 90.166 | TRUE | TRUE |
| wi | 1_percent_disorder | 0.017710970 | 13269948 | 17.711 | TRUE | TRUE |
| wi | 25_percent_disorder | 0.046348185 | 21143567 | 46.348 | TRUE | TRUE |
| wi | 5_percent_disorder | 0.026060848 | 17053388 | 26.061 | TRUE | TRUE |
| wi | limited_range | 0.072898575 | 22375013 | 72.899 | TRUE | TRUE |
| wi | ordered | 0.002614235 | 2595343 | 2.614 | TRUE | TRUE |
| wi | ordered_unique | 0.002749331 | 2595342 | 2.749 | TRUE | TRUE |
| wi | random | 0.073413037 | 22371807 | 73.413 | TRUE | TRUE |
| wi | reversed | 0.006799134 | 3273957 | 6.799 | TRUE | TRUE |
| wi | reversed_unique | 0.006269893 | 3273489 | 6.270 | TRUE | TRUE |
| wi | unique | 0.072492020 | 22370399 | 72.492 | TRUE | TRUE |

### 10000000 Items

| Sort Type | Variant | Time (s) | Comparisons | ns/item | Sorted | Stable |
|-----------|---------|----------|-------------|---------|--------|--------|
| fb | 1_percent_disorder | 0.133542775 | 52321148 | 13.354 | TRUE | TRUE |
| fb | 25_percent_disorder | 0.722744736 | 205423876 | 72.274 | TRUE | TRUE |
| fb | 5_percent_disorder | 0.281450946 | 89509650 | 28.145 | TRUE | TRUE |
| fb | limited_range | 1.241151502 | 373483234 | 124.115 | TRUE | TRUE |
| fb | ordered | 0.011954761 | 9999999 | 1.195 | TRUE | TRUE |
| fb | ordered_unique | 0.009846187 | 9999999 | 0.985 | TRUE | TRUE |
| fb | reversed | 0.216579820 | 29498302 | 21.658 | TRUE | TRUE |
| fb | reversed_unique | 0.022052420 | 19999998 | 2.205 | TRUE | TRUE |
| fb | unique | 1.252925400 | 373634696 | 125.293 | TRUE | TRUE |
| fi | 1_percent_disorder | 0.105946624 | 44268314 | 10.595 | TRUE | FALSE |
| fi | 25_percent_disorder | 0.319833781 | 173895640 | 31.983 | TRUE | FALSE |
| fi | 5_percent_disorder | 0.184160002 | 87825094 | 18.416 | TRUE | FALSE |
| fi | limited_range | 0.352018148 | 232288484 | 35.202 | TRUE | FALSE |
| fi | ordered | 0.012409105 | 10000304 | 1.241 | TRUE | TRUE |
| fi | ordered_unique | 0.010427096 | 10000304 | 1.043 | TRUE | TRUE |
| fi | random | 0.356327314 | 232335444 | 35.633 | TRUE | FALSE |
| fi | reversed | 0.286056981 | 191373297 | 28.606 | TRUE | FALSE |
| fi | reversed_unique | 0.292515119 | 191369358 | 29.252 | TRUE | TRUE |
| fi | unique | 0.351251015 | 232334009 | 35.125 | TRUE | TRUE |
| fiw | 1_percent_disorder | 0.109809866 | 42894715 | 10.981 | TRUE | TRUE |
| fiw | 25_percent_disorder | 0.309032698 | 165645932 | 30.903 | TRUE | TRUE |
| fiw | 5_percent_disorder | 0.174827596 | 83058524 | 17.483 | TRUE | TRUE |
| fiw | limited_range | 0.327662330 | 225441758 | 32.766 | TRUE | TRUE |
| fiw | ordered | 0.011867405 | 10000089 | 1.187 | TRUE | TRUE |
| fiw | ordered_unique | 0.010319201 | 10000089 | 1.032 | TRUE | TRUE |
| fiw | random | 0.312695917 | 225441807 | 31.270 | TRUE | TRUE |
| fiw | reversed | 0.250806725 | 197985831 | 25.081 | TRUE | TRUE |
| fiw | reversed_unique | 0.277810097 | 197985849 | 27.781 | TRUE | TRUE |
| fiw | unique | 0.313926253 | 225441805 | 31.393 | TRUE | TRUE |
| fs | 1_percent_disorder | 0.104278234 | 45723521 | 10.428 | TRUE | TRUE |
| fs | 25_percent_disorder | 0.339036813 | 171498604 | 33.904 | TRUE | TRUE |
| fs | 5_percent_disorder | 0.186436130 | 86531834 | 18.644 | TRUE | TRUE |
| fs | limited_range | 0.362196813 | 235476695 | 36.220 | TRUE | TRUE |
| fs | ordered | 0.012233992 | 9999999 | 1.223 | TRUE | TRUE |
| fs | ordered_unique | 0.010820382 | 9999999 | 1.082 | TRUE | TRUE |
| fs | random | 0.363724289 | 235565948 | 36.372 | TRUE | TRUE |
| fs | reversed | 0.183295153 | 89901786 | 18.330 | TRUE | TRUE |
| fs | reversed_unique | 0.043888438 | 20867892 | 4.389 | TRUE | TRUE |
| fs | unique | 0.361805147 | 235566350 | 36.181 | TRUE | TRUE |
| gq | 1_percent_disorder | 0.754412151 | 178719900 | 75.441 | TRUE | TRUE |
| gq | 25_percent_disorder | 0.674921838 | 218019265 | 67.492 | TRUE | TRUE |
| gq | 5_percent_disorder | 0.403824442 | 199491157 | 40.382 | TRUE | TRUE |
| gq | limited_range | 1.065839362 | 220067417 | 106.584 | TRUE | TRUE |
| gq | ordered | 0.201249140 | 114434624 | 20.125 | TRUE | TRUE |
| gq | ordered_unique | 0.201330947 | 114434624 | 20.133 | TRUE | TRUE |
| gq | random | 1.065643550 | 220067428 | 106.564 | TRUE | TRUE |
| gq | reversed | 0.996863604 | 118797985 | 99.686 | TRUE | TRUE |
| gq | reversed_unique | 0.258755630 | 118788160 | 25.876 | TRUE | TRUE |
| gq | unique | 1.065750966 | 220067428 | 106.575 | TRUE | TRUE |
| gs | 1_percent_disorder | 0.360293911 | 167107953 | 36.029 | TRUE | TRUE |
| gs | 25_percent_disorder | 0.652314759 | 232407212 | 65.231 | TRUE | TRUE |
| gs | 5_percent_disorder | 0.462979892 | 201569842 | 46.298 | TRUE | TRUE |
| gs | limited_range | 0.805128464 | 236936715 | 80.513 | TRUE | TRUE |
| gs | ordered | 0.202819623 | 79190549 | 20.282 | TRUE | TRUE |
| gs | ordered_unique | 0.204964897 | 79189929 | 20.496 | TRUE | TRUE |
| gs | random | 0.796109246 | 237013434 | 79.611 | TRUE | TRUE |
| gs | reversed | 0.207177538 | 82000284 | 20.718 | TRUE | TRUE |
| gs | reversed_unique | 0.204170745 | 81979307 | 20.417 | TRUE | TRUE |
| gs | unique | 0.811842233 | 236874687 | 81.184 | TRUE | TRUE |
| is | 1_percent_disorder | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | 25_percent_disorder | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | 5_percent_disorder | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | limited_range | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | ordered | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | ordered_unique | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | random | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | reversed | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | reversed_unique | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | unique | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| nq | 1_percent_disorder | 0.243733512 | 214985800 | 24.373 | TRUE | FALSE |
| nq | 25_percent_disorder | 0.510389905 | 233347510 | 51.039 | TRUE | FALSE |
| nq | 5_percent_disorder | 0.294442819 | 218696014 | 29.444 | TRUE | FALSE |
| nq | limited_range | 0.829631958 | 237131562 | 82.963 | TRUE | FALSE |
| nq | ordered | 0.220787251 | 211563126 | 22.079 | TRUE | FALSE |
| nq | ordered_unique | 0.220262870 | 211572877 | 22.026 | TRUE | TRUE |
| nq | random | 0.842739955 | 244041390 | 84.274 | TRUE | FALSE |
| nq | reversed | 0.338847115 | 290526331 | 33.885 | TRUE | FALSE |
| nq | reversed_unique | 0.341999190 | 290683459 | 34.200 | TRUE | TRUE |
| nq | unique | 0.840565203 | 244066204 | 84.057 | TRUE | TRUE |
| ti | 1_percent_disorder | 0.092006015 | 29034572 | 9.201 | TRUE | TRUE |
| ti | 25_percent_disorder | 0.595522379 | 139122422 | 59.552 | TRUE | TRUE |
| ti | 5_percent_disorder | 0.217200811 | 59750966 | 21.720 | TRUE | TRUE |
| ti | limited_range | 1.062038550 | 213811853 | 106.204 | TRUE | TRUE |
| ti | ordered | 0.008037509 | 9999999 | 0.804 | TRUE | TRUE |
| ti | ordered_unique | 0.007893785 | 9999999 | 0.789 | TRUE | TRUE |
| ti | random | 1.066423291 | 213808938 | 106.642 | TRUE | TRUE |
| ti | reversed | 0.050777985 | 10548612 | 5.078 | TRUE | TRUE |
| ti | reversed_unique | 0.014549474 | 9999999 | 1.455 | TRUE | TRUE |
| ti | unique | 1.061669183 | 213807264 | 106.167 | TRUE | TRUE |
| wi | 1_percent_disorder | 0.260154539 | 161674690 | 26.015 | TRUE | TRUE |
| wi | 25_percent_disorder | 0.596774883 | 249353467 | 59.677 | TRUE | TRUE |
| wi | 5_percent_disorder | 0.365352297 | 204484322 | 36.535 | TRUE | TRUE |
| wi | limited_range | 0.932857678 | 266882917 | 93.286 | TRUE | TRUE |
| wi | ordered | 0.024406158 | 20122534 | 2.441 | TRUE | TRUE |
| wi | ordered_unique | 0.024163397 | 20122509 | 2.416 | TRUE | TRUE |
| wi | random | 0.937377845 | 266846348 | 93.738 | TRUE | TRUE |
| wi | reversed | 0.115167118 | 21887324 | 11.517 | TRUE | TRUE |
| wi | reversed_unique | 0.109767654 | 21498750 | 10.977 | TRUE | TRUE |
| wi | unique | 0.931048354 | 266816725 | 93.105 | TRUE | TRUE |

### 100000000 Items

| Sort Type | Variant | Time (s) | Comparisons | ns/item | Sorted | Stable |
|-----------|---------|----------|-------------|---------|--------|--------|
| fb | 1_percent_disorder | 1.603461611 | 550738763 | 16.035 | TRUE | TRUE |
| fb | 25_percent_disorder | 8.413078525 | 2304678923 | 84.131 | TRUE | TRUE |
| fb | 5_percent_disorder | 3.341289528 | 967795739 | 33.413 | TRUE | TRUE |
| fb | limited_range | 14.769281204 | 4273799920 | 147.693 | TRUE | TRUE |
| fb | ordered | 0.100024797 | 99999999 | 1.000 | TRUE | TRUE |
| fb | ordered_unique | 0.099996017 | 99999999 | 1.000 | TRUE | TRUE |
| fb | reversed | 4.679310739 | 514026322 | 46.793 | TRUE | TRUE |
| fb | reversed_unique | 0.230721283 | 199999998 | 2.307 | TRUE | TRUE |
| fb | unique | 14.665510673 | 4275274046 | 146.655 | TRUE | TRUE |
| fi | 1_percent_disorder | 1.347344817 | 551691891 | 13.473 | TRUE | FALSE |
| fi | 25_percent_disorder | 3.598834731 | 1935642234 | 35.988 | TRUE | FALSE |
| fi | 5_percent_disorder | 2.181575168 | 982528612 | 21.816 | TRUE | FALSE |
| fi | limited_range | 4.104836701 | 2634705082 | 41.048 | TRUE | FALSE |
| fi | ordered | 0.152007804 | 100000429 | 1.520 | TRUE | TRUE |
| fi | ordered_unique | 0.149685117 | 100000429 | 1.497 | TRUE | TRUE |
| fi | random | 4.093604774 | 2635150566 | 40.936 | TRUE | FALSE |
| fi | reversed | 3.792768403 | 2176942046 | 37.928 | TRUE | FALSE |
| fi | reversed_unique | 3.744238391 | 2176935091 | 37.442 | TRUE | TRUE |
| fi | unique | 4.100107391 | 2635150334 | 41.001 | TRUE | TRUE |
| fiw | 1_percent_disorder | 1.365463398 | 515849323 | 13.655 | TRUE | TRUE |
| fiw | 25_percent_disorder | 3.511762901 | 1862975057 | 35.118 | TRUE | TRUE |
| fiw | 5_percent_disorder | 2.096323422 | 925802654 | 20.963 | TRUE | TRUE |
| fiw | limited_range | 3.789653883 | 2621030913 | 37.897 | TRUE | TRUE |
| fiw | ordered | 0.189853098 | 100000101 | 1.899 | TRUE | TRUE |
| fiw | ordered_unique | 0.189882687 | 100000101 | 1.899 | TRUE | TRUE |
| fiw | random | 3.783181915 | 2621030115 | 37.832 | TRUE | TRUE |
| fiw | reversed | 3.347335521 | 2240116647 | 33.473 | TRUE | TRUE |
| fiw | reversed_unique | 3.303443774 | 2240136721 | 33.034 | TRUE | TRUE |
| fiw | unique | 3.785120686 | 2621030119 | 37.851 | TRUE | TRUE |
| fs | 1_percent_disorder | 1.360549944 | 547120878 | 13.605 | TRUE | TRUE |
| fs | 25_percent_disorder | 3.792471113 | 1929483884 | 37.925 | TRUE | TRUE |
| fs | 5_percent_disorder | 2.201798954 | 974324209 | 22.018 | TRUE | TRUE |
| fs | limited_range | 4.512989878 | 2741648021 | 45.130 | TRUE | TRUE |
| fs | ordered | 0.080633001 | 99999999 | 0.806 | TRUE | TRUE |
| fs | ordered_unique | 0.080541794 | 99999999 | 0.805 | TRUE | TRUE |
| fs | random | 4.469974409 | 2743518385 | 44.700 | TRUE | TRUE |
| fs | reversed | 3.229902829 | 1615892295 | 32.299 | TRUE | TRUE |
| fs | reversed_unique | 0.534906515 | 208655473 | 5.349 | TRUE | TRUE |
| fs | unique | 4.466211554 | 2743657248 | 44.662 | TRUE | TRUE |
| gq | 1_percent_disorder | 3.963380990 | 2138049958 | 39.634 | TRUE | TRUE |
| gq | 25_percent_disorder | 7.717038229 | 2514395611 | 77.170 | TRUE | TRUE |
| gq | 5_percent_disorder | 4.844100525 | 2344049524 | 48.441 | TRUE | TRUE |
| gq | limited_range | 12.215258690 | 2532637470 | 122.153 | TRUE | TRUE |
| gq | ordered | 2.303235210 | 1314447104 | 23.032 | TRUE | TRUE |
| gq | ordered_unique | 2.304506974 | 1314447104 | 23.045 | TRUE | TRUE |
| gq | random | 12.148851770 | 2532637467 | 121.489 | TRUE | TRUE |
| gq | reversed | 11.588362201 | 1352082027 | 115.884 | TRUE | TRUE |
| gq | reversed_unique | 2.972058287 | 1351335168 | 29.721 | TRUE | TRUE |
| gq | unique | 12.285641719 | 2532637467 | 122.856 | TRUE | TRUE |
| gs | 1_percent_disorder | 4.357375093 | 2022464193 | 43.574 | TRUE | TRUE |
| gs | 25_percent_disorder | 7.354206503 | 2634084984 | 73.542 | TRUE | TRUE |
| gs | 5_percent_disorder | 5.459977430 | 2358159772 | 54.600 | TRUE | TRUE |
| gs | limited_range | 9.030153927 | 2655479879 | 90.302 | TRUE | TRUE |
| gs | ordered | 2.214857506 | 840204682 | 22.149 | TRUE | TRUE |
| gs | ordered_unique | 2.202765819 | 840185031 | 22.028 | TRUE | TRUE |
| gs | random | 8.974453162 | 2654863274 | 89.745 | TRUE | TRUE |
| gs | reversed | 2.422775527 | 897888729 | 24.228 | TRUE | TRUE |
| gs | reversed_unique | 2.348047344 | 896694624 | 23.480 | TRUE | TRUE |
| gs | unique | 8.963878761 | 2654376960 | 89.639 | TRUE | TRUE |
| is | 1_percent_disorder | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | 25_percent_disorder | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | 5_percent_disorder | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | limited_range | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | ordered | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | ordered_unique | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | random | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | reversed | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | reversed_unique | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| is | unique | SKIPPED | SKIPPED | SKIPPED | SKIPPED | SKIPPED |
| nq | 1_percent_disorder | 2.842066572 | 2503500147 | 28.421 | TRUE | FALSE |
| nq | 25_percent_disorder | 5.840111748 | 2671105437 | 58.401 | TRUE | FALSE |
| nq | 5_percent_disorder | 3.400287669 | 2520521324 | 34.003 | TRUE | FALSE |
| nq | limited_range | 9.402445441 | 2751538913 | 94.024 | TRUE | FALSE |
| nq | ordered | 2.652865079 | 2523417040 | 26.529 | TRUE | FALSE |
| nq | ordered_unique | 2.658523015 | 2525165841 | 26.585 | TRUE | TRUE |
| nq | random | 9.559972339 | 2820562427 | 95.600 | TRUE | FALSE |
| nq | reversed | 3.372368268 | 2911814440 | 33.724 | TRUE | FALSE |
| nq | reversed_unique | 3.380134247 | 2921036489 | 33.801 | TRUE | TRUE |
| nq | unique | 9.559498106 | 2823779910 | 95.595 | TRUE | TRUE |
| ti | 1_percent_disorder | 1.103701214 | 324426897 | 11.037 | TRUE | TRUE |
| ti | 25_percent_disorder | 6.668467093 | 1534313421 | 66.685 | TRUE | TRUE |
| ti | 5_percent_disorder | 2.597649195 | 659692736 | 25.976 | TRUE | TRUE |
| ti | limited_range | 12.095854445 | 2435364282 | 120.959 | TRUE | TRUE |
| ti | ordered | 0.079081842 | 99999999 | 0.791 | TRUE | TRUE |
| ti | ordered_unique | 0.079217187 | 99999999 | 0.792 | TRUE | TRUE |
| ti | random | 12.077294437 | 2435380641 | 120.773 | TRUE | TRUE |
| ti | reversed | 0.868121567 | 167379151 | 8.681 | TRUE | TRUE |
| ti | reversed_unique | 0.102825764 | 99999999 | 1.028 | TRUE | TRUE |
| ti | unique | 12.077272987 | 2435393106 | 120.773 | TRUE | TRUE |
| wi | 1_percent_disorder | 3.140806636 | 1991250628 | 31.408 | TRUE | TRUE |
| wi | 25_percent_disorder | 6.784342945 | 2854467621 | 67.843 | TRUE | TRUE |
| wi | 5_percent_disorder | 4.232403037 | 2413299341 | 42.324 | TRUE | TRUE |
| wi | limited_range | 10.672435346 | 3064122058 | 106.724 | TRUE | TRUE |
| wi | ordered | 0.243714682 | 223276957 | 2.437 | TRUE | TRUE |
| wi | ordered_unique | 0.243325277 | 223275953 | 2.433 | TRUE | TRUE |
| wi | random | 10.635332917 | 3063971016 | 106.353 | TRUE | TRUE |
| wi | reversed | 1.350548953 | 295191469 | 13.505 | TRUE | TRUE |
| wi | reversed_unique | 1.264963927 | 266513829 | 12.650 | TRUE | TRUE |
| wi | unique | 10.656137295 | 3063949880 | 106.561 | TRUE | TRUE |


## Performance Rankings (Random Data)

### 1000 Items - Ranked by Time (Fastest First)

- **fs** (Stable Forsort In-Place (Stable)): 41.308 ns/item
- **fiw** (Adaptive Forsort In-Place Stable (with workspace)): 45.638 ns/item
- **nq** (Bentley/McIlroy Quick Sort In-Place (Unstable)): 47.519 ns/item
- **is** (Insertion Sort (Stable)): 53.268 ns/item
- **ti** (TimSort (Stable)): 53.308 ns/item
- **gq** (GLibc Quick Sort In-Place (Stability Not Guaranteed)): 55.308 ns/item
- **fi** (Adaptive Forsort In-Place (Unstable)): 55.958 ns/item
- **wi** (WikiSort (Stable)): 72.487 ns/item
- **gs** (Grail Sort In-Place (Stable)): 82.317 ns/item

### 10000 Items - Ranked by Time (Fastest First)

- **fi** (Adaptive Forsort In-Place (Unstable)): 24.676 ns/item
- **fs** (Stable Forsort In-Place (Stable)): 27.021 ns/item
- **fiw** (Adaptive Forsort In-Place Stable (with workspace)): 34.249 ns/item
- **gs** (Grail Sort In-Place (Stable)): 47.289 ns/item
- **nq** (Bentley/McIlroy Quick Sort In-Place (Unstable)): 49.391 ns/item
- **wi** (WikiSort (Stable)): 58.540 ns/item
- **ti** (TimSort (Stable)): 63.154 ns/item
- **gq** (GLibc Quick Sort In-Place (Stability Not Guaranteed)): 68.236 ns/item
- **is** (Insertion Sort (Stable)): 136.847 ns/item

### 100000 Items - Ranked by Time (Fastest First)

- **fiw** (Adaptive Forsort In-Place Stable (with workspace)): 23.171 ns/item
- **fi** (Adaptive Forsort In-Place (Unstable)): 26.104 ns/item
- **fs** (Stable Forsort In-Place (Stable)): 27.346 ns/item
- **gs** (Grail Sort In-Place (Stable)): 60.681 ns/item
- **wi** (WikiSort (Stable)): 72.147 ns/item
- **ti** (TimSort (Stable)): 77.428 ns/item
- **nq** (Bentley/McIlroy Quick Sort In-Place (Unstable)): 83.013 ns/item
- **gq** (GLibc Quick Sort In-Place (Stability Not Guaranteed)): 83.401 ns/item
- **is** (Insertion Sort (Stable)): 1019.411 ns/item

### 1000000 Items - Ranked by Time (Fastest First)

- **is** (Insertion Sort (Stable)): SKIPPED ns/item
- **fiw** (Adaptive Forsort In-Place Stable (with workspace)): 26.374 ns/item
- **fi** (Adaptive Forsort In-Place (Unstable)): 29.532 ns/item
- **fs** (Stable Forsort In-Place (Stable)): 30.648 ns/item
- **gs** (Grail Sort In-Place (Stable)): 64.381 ns/item
- **wi** (WikiSort (Stable)): 73.413 ns/item
- **nq** (Bentley/McIlroy Quick Sort In-Place (Unstable)): 82.824 ns/item
- **ti** (TimSort (Stable)): 90.495 ns/item
- **gq** (GLibc Quick Sort In-Place (Stability Not Guaranteed)): 93.862 ns/item

### 10000000 Items - Ranked by Time (Fastest First)

- **is** (Insertion Sort (Stable)): SKIPPED ns/item
- **fiw** (Adaptive Forsort In-Place Stable (with workspace)): 31.270 ns/item
- **fi** (Adaptive Forsort In-Place (Unstable)): 35.633 ns/item
- **fs** (Stable Forsort In-Place (Stable)): 36.372 ns/item
- **gs** (Grail Sort In-Place (Stable)): 79.611 ns/item
- **nq** (Bentley/McIlroy Quick Sort In-Place (Unstable)): 84.274 ns/item
- **wi** (WikiSort (Stable)): 93.738 ns/item
- **gq** (GLibc Quick Sort In-Place (Stability Not Guaranteed)): 106.564 ns/item
- **ti** (TimSort (Stable)): 106.642 ns/item

### 100000000 Items - Ranked by Time (Fastest First)

- **is** (Insertion Sort (Stable)): SKIPPED ns/item
- **fiw** (Adaptive Forsort In-Place Stable (with workspace)): 37.832 ns/item
- **fi** (Adaptive Forsort In-Place (Unstable)): 40.936 ns/item
- **fs** (Stable Forsort In-Place (Stable)): 44.700 ns/item
- **gs** (Grail Sort In-Place (Stable)): 89.745 ns/item
- **nq** (Bentley/McIlroy Quick Sort In-Place (Unstable)): 95.600 ns/item
- **wi** (WikiSort (Stable)): 106.353 ns/item
- **ti** (TimSort (Stable)): 120.773 ns/item
- **gq** (GLibc Quick Sort In-Place (Stability Not Guaranteed)): 121.489 ns/item


## Stability Verification

| Sort Type | Expected Stability | Verified Stable |
|-----------|-------------------|------------------|
| fb | Stable | TRUE |
| fi | Unstable | FALSE |
| fiw | Stable | TRUE |
| fs | Stable | TRUE |
| gq | Stable | TRUE |
| gs | Stable | TRUE |
| is | Stable | SKIPPED |
| nq | Unstable | FALSE |
| ti | Stable | TRUE |
| wi | Stable | TRUE |

---
*Generated automatically from benchmark_results.csv*
