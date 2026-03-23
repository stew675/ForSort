#!/bin/bash

# Benchmarking script for all sort types in ts executable
# Runs each sort type with item counts: 1000, 10000, 100000, 1000000, 10000000

# Sort types to test
SORT_TYPES=(
    "fb:ForSort Basic Fully In-Place        (Stable)"
    "fi:ForSort Unstable Fully In-Place     (Unstable)"
    "fs:ForSort Stable Fully In-Place       (Stable)"
    "fw:ForSort With Allocated Workspace    (Stable)"
    "gs:GrailSort Fully In-Place            (Stable)"
    "gq:GLibc Quick Sort Fully In-Place     (Stability Not Guaranteed)"
    "nq:Bentley/McIlroy Quick Sort In-Place (Unstable)"
    "ti:TimSort with Allocated Workspace    (Stable)"
    "wi:WikiSort Fully In-Place             (Stable)"
)

#    "is:Insertion Sort Fully In-Place       (Stable)"

# Test variants to run for each sort type
# Format: "variant_name:options"
TEST_VARIANTS=(
    "random_duplicates:-a 42 -l n"
    "random_unique:-a 42 -u"
    "25_percent_disordered:-a 42 -d 25"
    "10_percent_disordered:-a 42 -d 10"
    "5_percent_disordered:-a 42 -d 5"
    "1_percent_disordered:-a 42 -d 1"
    "ordered_duplicates:-a 42 -l n -o"
    "ordered_unique:-a 42 -o -u"
    "reversed_duplicates:-a 42 -l n -o -r"
    "reversed_unique:-a 42 -o -u -r"
)

NUM_ITEMS=(100 1000 10000 100000 1000000 10000000 100000000)

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
            
            # Run the benchmark
            output=$(./ts $variant_opts "$sort_code" -x "$n" 2>&1)
            
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
