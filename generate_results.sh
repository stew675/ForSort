#!/bin/bash

# Script to generate RESULTS.md from benchmark_results.csv
# Organizes benchmark data into organized Markdown tables

INPUT_FILE="benchmark_results.csv"
OUTPUT_FILE="RESULTS.md"

if [[ ! -f "$INPUT_FILE" ]]; then
    echo "Error: $INPUT_FILE not found. Run benchmark.sh first."
    exit 1
fi

echo "Generating $OUTPUT_FILE from $INPUT_FILE..."

# Start writing the markdown file
cat > "$OUTPUT_FILE" << 'HEADER'
# ForSort Benchmark Results

## Overview

This document contains comprehensive benchmark results for all sorting algorithms implemented in the ForSort library. Results are organized by dataset size and test variant.

**Test Configuration:**
- Random seed: 42
- All tests run with `-a 42` flag for reproducibility
- Workspace-enabled variants use `-w 1`

HEADER

# Get unique sort types (excluding header)
SORT_TYPES=$(tail -n +2 "$INPUT_FILE" | cut -d',' -f1 | sort -u)

# Get unique item counts
ITEM_COUNTS=$(tail -n +2 "$INPUT_FILE" | cut -d',' -f3 | sort -n -u)

# Get unique test variants
VARIANTS=$(tail -n +2 "$INPUT_FILE" | cut -d',' -f4 | sort -u)

# Add sort type descriptions
echo "## Sort Types" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"
cat >> "$OUTPUT_FILE" << 'SORT_TYPES_DESC'
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

SORT_TYPES_DESC

# Add test variant descriptions
echo "" >> "$OUTPUT_FILE"
echo "## Test Variants" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"
cat >> "$OUTPUT_FILE" << 'VARIANTS_DESC'
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

VARIANTS_DESC

# Add summary tables
echo "" >> "$OUTPUT_FILE"
echo "## Summary by Dataset Size" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"
echo "### Random Data Performance (ns per item, lower is better)" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"

# Create header row
printf "| Sort Type |" >> "$OUTPUT_FILE"
for n in $ITEM_COUNTS; do
    printf " %d items |" "$n" >> "$OUTPUT_FILE"
done
echo "" >> "$OUTPUT_FILE"

# Create separator row
printf "|-----------|" >> "$OUTPUT_FILE"
for n in $ITEM_COUNTS; do
    printf "-----------|" >> "$OUTPUT_FILE"
done
echo "" >> "$OUTPUT_FILE"

# Create data rows for each sort type
for sort in $SORT_TYPES; do
    printf "| %s |" "$sort" >> "$OUTPUT_FILE"
    for n in $ITEM_COUNTS; do
        # Get ns_per_item for random variant
        value=$(grep "^$sort," "$INPUT_FILE" | grep ",random," | grep ",$n," | cut -d',' -f9)
        if [[ -n "$value" ]]; then
            printf " %.1f |" "$value" >> "$OUTPUT_FILE"
        else
            printf " - |" >> "$OUTPUT_FILE"
        fi
    done
    echo "" >> "$OUTPUT_FILE"
done

echo "" >> "$OUTPUT_FILE"
echo "### Average Comparisons (Random Data)" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"

# Create header row
printf "| Sort Type |" >> "$OUTPUT_FILE"
for n in $ITEM_COUNTS; do
    printf " %d items |" "$n" >> "$OUTPUT_FILE"
done
echo "" >> "$OUTPUT_FILE"

# Create separator row
printf "|-----------|" >> "$OUTPUT_FILE"
for n in $ITEM_COUNTS; do
    printf "-----------|" >> "$OUTPUT_FILE"
done
echo "" >> "$OUTPUT_FILE"

# Create data rows for each sort type
for sort in $SORT_TYPES; do
    printf "| %s |" "$sort" >> "$OUTPUT_FILE"
    for n in $ITEM_COUNTS; do
        # Get avg_comparisons for random variant
        value=$(grep "^$sort," "$INPUT_FILE" | grep ",random," | grep ",$n," | cut -d',' -f6)
        if [[ -n "$value" ]]; then
            printf " %s |" "$value" >> "$OUTPUT_FILE"
        else
            printf " - |" >> "$OUTPUT_FILE"
        fi
    done
    echo "" >> "$OUTPUT_FILE"
done

# Add detailed tables for each item count
echo "" >> "$OUTPUT_FILE"
echo "## Detailed Results by Dataset Size" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"

for n in $ITEM_COUNTS; do
    echo "### $n Items" >> "$OUTPUT_FILE"
    echo "" >> "$OUTPUT_FILE"
    
    # Table header
    printf "| Sort Type | Variant | Time (s) | Comparisons | ns/item | Sorted | Stable |\n" >> "$OUTPUT_FILE"
    printf "|-----------|---------|----------|-------------|---------|--------|--------|\n" >> "$OUTPUT_FILE"
    
    # Get all rows for this item count, sorted by sort_type and variant
    grep ",$n," "$INPUT_FILE" | tail -n +2 | sort -t',' -k1,1 -k4,4 | while IFS=',' read -r sort_type sort_name num_items variant_name avg_time avg_comparisons is_sorted is_stable ns_per_item; do
        printf "| %s | %s | %s | %s | %s | %s | %s |\n" "$sort_type" "$variant_name" "$avg_time" "$avg_comparisons" "$ns_per_item" "$is_sorted" "$is_stable" >> "$OUTPUT_FILE"
    done
    
    echo "" >> "$OUTPUT_FILE"
done

# Add ranking tables for each dataset size (random data only)
echo "" >> "$OUTPUT_FILE"
echo "## Performance Rankings (Random Data)" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"

for n in $ITEM_COUNTS; do
    echo "### $n Items - Ranked by Time (Fastest First)" >> "$OUTPUT_FILE"
    echo "" >> "$OUTPUT_FILE"
    
    # Get random data results sorted by time
    grep ",$n," "$INPUT_FILE" | grep ",random," | tail -n +2 | sort -t',' -k9 -n | head -10 | while IFS=',' read -r sort_type sort_name num_items variant_name avg_time avg_comparisons is_sorted is_stable ns_per_item; do
        echo "- **$sort_type** ($sort_name): ${ns_per_item} ns/item" >> "$OUTPUT_FILE"
    done
    
    echo "" >> "$OUTPUT_FILE"
done

# Add stability verification
echo "" >> "$OUTPUT_FILE"
echo "## Stability Verification" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"

printf "| Sort Type | Expected Stability | Verified Stable |\n" >> "$OUTPUT_FILE"
printf "|-----------|-------------------|------------------|\n" >> "$OUTPUT_FILE"

for sort in $SORT_TYPES; do
    # Get stability for random variant, 1M items
    is_stable=$(grep "^$sort," "$INPUT_FILE" | grep ",random," | grep ",1000000," | cut -d',' -f8)
    
    if [[ "$sort" == "fi" ]]; then
        expected="Unstable"
    elif [[ "$sort" == "nq" ]]; then
        expected="Unstable"
    else
        expected="Stable"
    fi
    
    if [[ -z "$is_stable" ]]; then
        is_stable="N/A"
    fi
    
    printf "| %s | %s | %s |\n" "$sort" "$expected" "$is_stable" >> "$OUTPUT_FILE"
done

echo "" >> "$OUTPUT_FILE"
echo "---" >> "$OUTPUT_FILE"
echo "*Generated automatically from benchmark_results.csv*" >> "$OUTPUT_FILE"

echo ""
echo "Results generated successfully!"
echo "View with: cat $OUTPUT_FILE"
echo ""
echo "Markdown preview with: cat $OUTPUT_FILE | pandoc -t html"
