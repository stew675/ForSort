#!/bin/bash

# Benchmarking script for all sort types in ts executable
# Runs each sort type with item counts: 1000, 10000, 100000, 1000000, 10000000

# Sort types to test
SORT_TYPES=(
    "fb:Basic Forsort In-Place (Stable)"
    "fi:Adaptive Forsort In-Place (Unstable)"
    "fiw:Adaptive Forsort In-Place Stable (with workspace)"
    "fs:Stable Forsort In-Place (Stable)"
    "gs:Grail Sort In-Place (Stable)"
    "gq:GLibc Quick Sort In-Place (Stability Not Guaranteed)"
    "nq:Bentley/McIlroy Quick Sort In-Place (Unstable)"
    "ti:TimSort (Stable)"
    "wi:WikiSort (Stable)"
    "is:Insertion Sort (Stable)"
)

# Test variants to run for each sort type
# Format: "variant_name:options"
TEST_VARIANTS=(
    "random:-a 42"
    "ordered:-a 42 -o"
    "reversed:-a 42 -o -r"
    "unique:-a 42 -u"
    "ordered_unique:-a 42 -o -u"
    "reversed_unique:-a 42 -o -u -r"
    "1_percent_disorder:-a 42 -d 1"
    "5_percent_disorder:-a 42 -d 5"
    "25_percent_disorder:-a 42 -d 25"
    "limited_range:-a 42 -l n"
)

NUM_ITEMS=(1000 10000 100000 1000000 10000000 100000000)

OUTPUT_FILE="benchmark_results.csv"

# Clear previous results
echo "sort_type,sort_name,num_items,test_variant,avg_time_sec,avg_comparisons,sorted,stable,ns_per_item" > "$OUTPUT_FILE"

echo "Starting benchmark..."
echo "========================================"

for sort_entry in "${SORT_TYPES[@]}"; do
    IFS=':' read -r sort_code sort_name <<< "$sort_entry"
    
    for variant_entry in "${TEST_VARIANTS[@]}"; do
        IFS=':' read -r variant_name variant_opts <<< "$variant_entry"
        
        echo ""
        echo "Testing: $sort_name ($sort_code) - $variant_name"
        echo "------------------------------------------------"
        
        for n in "${NUM_ITEMS[@]}"; do
            # Skip large item counts for insertion sort (O(n^2) algorithm)
            if [[ "$sort_code" == "is" && "$n" -gt 100000 ]]; then
                echo "  Skipping $n items (O(n^2) algorithm)"
                echo "$sort_code,$sort_name,$n,$variant_name,SKIPPED,SKIPPED,SKIPPED,SKIPPED,SKIPPED" >> "$OUTPUT_FILE"
                continue
            fi
            echo -n "  Running with $n items... "
            
            # Run the benchmark (fiw uses stable variant with auto workspace)
            if [[ "$sort_code" == "fiw" ]]; then
                output=$(./ts $variant_opts fi -w 1 "$n" 2>&1)
            else
                output=$(./ts $variant_opts "$sort_code" "$n" 2>&1)
            fi
            
            # Parse the output
            avg_time=$(echo "$output" | grep "Avg Time taken to sort" | sed 's/.*: *\([0-9.]*\)s.*/\1/')
            avg_comparisons=$(echo "$output" | grep "Avg Number of Compares" | sed 's/.*: *\([0-9]*\).*/\1/')
            is_sorted=$(echo "$output" | grep "Data Is Sorted" | awk '{print $NF}')
            is_stable=$(echo "$output" | grep "Sort is Stable" | awk '{print $NF}')
            ns_per_item=$(echo "$output" | grep "Avg ns per item" | sed 's/.*: *\([0-9.]*\)ns.*/\1/')
            
            echo "$sort_code,$sort_name,$n,$variant_name,$avg_time,$avg_comparisons,$is_sorted,$is_stable,$ns_per_item" >> "$OUTPUT_FILE"
            
            echo "Done (Time: $avg_time, Comparisons: $avg_comparisons)"
        done
    done
done

echo ""
echo "========================================"
echo "Benchmarking complete!"
echo "Results saved to: $OUTPUT_FILE"
echo ""
echo "CSV Format: sort_type,sort_name,num_items,test_variant,avg_time_sec,avg_comparisons,sorted,stable,ns_per_item"
echo ""
echo "You can view results with:"
echo "  cat $OUTPUT_FILE"
echo "  cat $OUTPUT_FILE | column -t -s','"
