#!/usr/bin/env python3
"""
ForSort Benchmark Results Generator

Processes benchmark_results.csv and generates a comprehensive RESULTS.md file
with intelligent ranking, cross-category analysis, and enhanced formatting.

Usage:
    python generate_results.py [options]

Options:
    --input FILE      Input CSV file (default: benchmark_results.csv)
    --output FILE     Output Markdown file (default: RESULTS.md)
    --no-detailed     Skip detailed tables (summary only)
    --no-rankings     Skip ranking sections
    --include-skipped Include SKIPPED entries in rankings
"""

import csv
import argparse
from collections import defaultdict
from typing import Dict, List, Tuple, Optional


# Sort type metadata
SORT_TYPE_INFO = {
    "fb": {"name": "ForSort Basic Fully In-Place", "stable": True},
    "fi": {"name": "ForSort Unstable Fully In-Place", "stable": False},
    "fs": {"name": "ForSort Stable Fully In-Place", "stable": True},
    "fw": {"name": "ForSort With Allocated Workspace", "stable": True},
    "gs": {"name": "GrailSort Fully In-Place", "stable": True},
    "gq": {"name": "GLibc Quick Sort Fully In-Place", "stable": False},
    "nq": {"name": "Bentley/McIlroy Quick Sort In-Place", "stable": False},
    "ti": {"name": "TimSort with Allocated Workspace", "stable": True},
    "wi": {"name": "WikiSort Fully In-Place", "stable": True},
    "is": {"name": "Insertion Sort Fully In-Place", "stable": True},
}


# Test variant descriptions
VARIANT_INFO = {
    "fully_random": "Fully Random Data",
    "25_percent_disordered": "75% Ordered, 25% disorder",
    "10_percent_disordered": "90% Ordered, 10% disorder",
    "5_percent_disordered": "95% Ordered, 5% disorder",
    "1_percent_disordered": "99% Ordered, 1% disorder",
    "fully_ordered": "Fully Ordered",
    "reverse_ordered_duplicates": "Reverse Ordered with Duplicate Values",
    "reverse_ordered_uniques": "Reverse Ordered with Unique Values",
}


def load_csv_data(filepath: str) -> List[Dict]:
    """Load and validate CSV data."""
    data = []
    with open(filepath, "r") as f:
        reader = csv.DictReader(f)
        for row in reader:
            # Parse numeric fields, handle SKIPPED values
            try:
                if row["avg_time_sec"] == "SKIPPED":
                    row["_valid"] = False
                    row["_skipped"] = True
                else:
                    row["_valid"] = True
                    row["_skipped"] = False
                    row["_num_items"] = int(row["num_items"])
                    row["_time_sec"] = float(row["avg_time_sec"])
                    row["_comparisons"] = int(row["avg_comparisons"])
                    row["_ns_per_item"] = float(row["ns_per_item"])
                    row["_sorted"] = row["sorted"].upper() == "TRUE"
                    row["_stable"] = row["stable"].upper() == "TRUE"
                data.append(row)
            except (ValueError, KeyError) as e:
                print(f"Warning: Skipping invalid row: {row} ({e})")
    return data


def get_unique_values(data: List[Dict], field: str) -> List[str]:
    """Get sorted unique values from a field."""
    return sorted(set(row[field] for row in data if row.get("_valid", False)))


def rank_by_time(rows: List[Dict]) -> List[Tuple[str, float, int]]:
    """Rank rows by ns_per_item (lower is better). Returns list of (sort_type, ns_per_item, rank)."""
    valid_rows = [
        (r["sort_type"], r["_ns_per_item"]) for r in rows if r.get("_valid", False)
    ]
    sorted_rows = sorted(valid_rows, key=lambda x: x[1])
    return [(st, ns, i + 1) for i, (st, ns) in enumerate(sorted_rows)]


def calculate_relative_performance(ns_values: Dict[str, float]) -> Dict[str, float]:
    """Calculate % slower than best for each algorithm."""
    if not ns_values:
        return {}
    best = min(ns_values.values())
    if best == 0:
        return {k: 0.0 for k in ns_values}
    return {k: ((v / best) - 1) * 100 for k, v in ns_values.items()}


def format_ns(ns_value: float) -> str:
    """Format ns_per_item value."""
    if ns_value >= 1000:
        return f"{ns_value:.1f}"
    elif ns_value >= 100:
        return f"{ns_value:.2f}"
    else:
        return f"{ns_value:.3f}"


def generate_overview_section() -> str:
    """Generate the overview section."""
    return """# ForSort Benchmark Results

## Overview

This document contains comprehensive benchmark results for all sorting algorithms implemented in the ForSort library. Results are organized by dataset size and test variant with intelligent ranking and cross-category analysis.

**Test Configuration:**
- Random seed: 42
- All tests run with `-a 42` flag for reproducibility
- Workspace-enabled variants use `-w 1`

"""


def generate_sort_types_section() -> str:
    """Generate the sort types reference section."""
    lines = [
        "## Sort Types",
        "",
        "| Code | Name | Stability |",
        "|------|------|-----------|",
    ]
    for code, info in SORT_TYPE_INFO.items():
        stability = "Stable" if info["stable"] else "Unstable"
        lines.append(f"| {code} | {info['name']} | {stability} |")
    return "\n".join(lines) + "\n\n"


def generate_variant_section() -> str:
    """Generate the test variants reference section."""
    lines = [
        "## Test Variants",
        "",
        "| Variant | Description |",
        "|---------|-------------|",
    ]
    for variant, desc in VARIANT_INFO.items():
        lines.append(f"| {variant} | {desc} |")
    return "\n".join(lines) + "\n\n"


def generate_summary_by_size(data: List[Dict], include_skipped: bool = False) -> str:
    """Generate summary tables organized by dataset size and test variant."""
    lines = ["## Summary by Dataset Size and Test Variant", ""]

    # Get unique sizes and variants (maintain custom order from VARIANT_INFO)
    sizes = get_unique_values(data, "num_items")
    variants = list(VARIANT_INFO.keys())

    for variant in variants:
        lines.append(f"### {variant.replace('_', ' ').title()}")
        lines.append("")
        lines.append("| Sort Type | " + " | ".join(f"{n} items" for n in sizes) + " |")
        lines.append("|-----------|" + "".join("-" * 10 + "|" for _ in sizes))

        # Build ns_per_item matrix for this variant
        matrix = {}  # sort_type -> {size -> ns_value}
        for row in data:
            if not row.get("_valid", False):
                continue
            if row["test_variant"] != variant:
                continue
            st = row["sort_type"]
            size = row["num_items"]
            if st not in matrix:
                matrix[st] = {}
            matrix[st][size] = row["_ns_per_item"]

        # Rank within this variant (average across all sizes)
        avg_times = {}
        for st, size_dict in matrix.items():
            valid_values = [v for v in size_dict.values() if v is not None]
            if valid_values:
                avg_times[st] = sum(valid_values) / len(valid_values)

        ranked_types = sorted(avg_times.keys(), key=lambda x: avg_times[x])

        # Generate rows in rank order
        for st in ranked_types:
            row_parts = [f"| {st} |"]
            for size in sizes:
                if st in matrix and size in matrix[st]:
                    ns_val = format_ns(matrix[st][size])
                    # Highlight top 3 performers with asterisks
                    rank = ranked_types.index(st) + 1
                    if rank <= 3:
                        stars = "*" * (4 - rank)
                        row_parts.append(f" {stars}**{ns_val}** |")
                    else:
                        row_parts.append(f" {ns_val} |")
                else:
                    row_parts.append(" - |")
            lines.append("".join(row_parts))

        lines.append("")

    return "\n".join(lines) + "\n"


def generate_performance_rankings(
    data: List[Dict], include_skipped: bool = False
) -> str:
    """Generate detailed performance ranking tables for each size and variant."""
    lines = ["## Performance Rankings", ""]

    sizes = get_unique_values(data, "num_items")
    variants = list(VARIANT_INFO.keys())

    for size in sizes:
        lines.append(f"### {size} Items")
        lines.append("")

        # Get all valid rows for this size
        size_rows = [
            r for r in data if r.get("_valid", False) and r["num_items"] == size
        ]

        for variant in variants:
            variant_rows = [r for r in size_rows if r["test_variant"] == variant]

            # Rank by ns_per_item
            rankings = rank_by_time(variant_rows)

            lines.append(f"#### {variant.replace('_', ' ').title()}")
            lines.append("")
            lines.append(
                "| Rank | Sort Type | Name | ns/item | vs Best (%) | Stable? |"
            )
            lines.append(
                "|------|-----------|------|---------|-------------|---------|"
            )

            # Calculate relative performance
            ns_values = {st: ns for st, ns, _ in rankings}
            rel_perf = calculate_relative_performance(ns_values)

            best_ns = rankings[0][1] if rankings else 0

            for rank, (st, ns, _) in enumerate(rankings, 1):
                name = SORT_TYPE_INFO.get(st, {"name": st})["name"]
                stable_mark = (
                    "Yes" if SORT_TYPE_INFO.get(st, {}).get("stable", False) else "No"
                )

                # Highlight top 3
                prefix = "**" if rank <= 3 else ""
                suffix = "**" if rank <= 3 else ""

                rel_pct = f"{rel_perf.get(st, 0):.1f}%" if st in rel_perf else "-"

                lines.append(
                    f"| {rank} | {prefix}{st}{suffix} | {name} | {format_ns(ns)} | {rel_pct} | {stable_mark} |"
                )

            lines.append("")

    return "\n".join(lines) + "\n"


def generate_size_winners_summary(data: List[Dict]) -> str:
    """Generate summary table of winners for each dataset size."""
    lines = ["## Size Winners Summary", ""]

    sizes = get_unique_values(data, "num_items")
    variants = list(VARIANT_INFO.keys())

    lines.append(
        "| Dataset Size | 1st Place | Avg (ns/item) | 2nd Place | Avg (ns/item) | 3rd Place | Avg (ns/item) |"
    )
    lines.append(
        "|--------------|-----------|---------------|-----------|---------------|-----------|---------------|"
    )

    for size in sizes:
        size_rows = [
            r for r in data if r.get("_valid", False) and r["num_items"] == size
        ]

        # Calculate average time across all variants for each sort type
        avg_times = {}
        for st in SORT_TYPE_INFO.keys():
            st_rows = [r for r in size_rows if r["sort_type"] == st]
            if st_rows:
                valid_ns = [
                    r["_ns_per_item"] for r in st_rows if r.get("_valid", False)
                ]
                if valid_ns:
                    avg_times[st] = sum(valid_ns) / len(valid_ns)

        # Sort by average time (lower is better)
        sorted_by_time = sorted(avg_times.items(), key=lambda x: x[1])

        if len(sorted_by_time) >= 3:
            first_st, first_avg = sorted_by_time[0]
            second_st, second_avg = sorted_by_time[1]
            third_st, third_avg = sorted_by_time[2]

            first_name = SORT_TYPE_INFO[first_st]["name"]
            second_name = SORT_TYPE_INFO[second_st]["name"]
            third_name = SORT_TYPE_INFO[third_st]["name"]

            lines.append(
                f"| {size} | **{first_st}**<br>{first_name} | {format_ns(first_avg)} | **{second_st}**<br>{second_name} | {format_ns(second_avg)} | **{third_st}**<br>{third_name} | {format_ns(third_avg)} |"
            )
        else:
            lines.append(f"| {size} | - | - | - | - | - | - |")

    lines.append("")
    return "\n".join(lines) + "\n"


def generate_worst_case_analysis(
    data: List[Dict], exclude_reversed: bool = True
) -> str:
    """Generate worst-case performance analysis - find algorithm with best worst results."""
    lines = ["## Worst-Case Performance", ""]

    if exclude_reversed:
        lines.append(
            "This section identifies which algorithm has the best *worst-case* performance across all test variants "
            "except reverse-ordered scenarios (statistical outliers rarely seen in practice). "
            "Lower rank indicates better performance in the worst scenario encountered.\n"
        )
    else:
        lines.append(
            "This section identifies which algorithm has the best *worst-case* performance across all test variants and dataset sizes. "
            "Lower rank indicates better performance in the worst scenario encountered.\n"
        )

    sizes = get_unique_values(data, "num_items")

    # Filter out reverse-ordered variants if requested
    if exclude_reversed:
        variants = [v for v in VARIANT_INFO.keys() if not v.startswith("reverse_")]
    else:
        variants = list(VARIANT_INFO.keys())

    # Build data structure: sort_type -> list of (size, variant, rank)
    worst_case_data = defaultdict(list)

    for size in sizes:
        for variant in variants:
            # Get all rows for this category
            category_rows = [
                r
                for r in data
                if r["num_items"] == size and r["test_variant"] == variant
            ]

            # Get only valid rows for ranking
            valid_rows = [r for r in category_rows if r.get("_valid", False)]
            rankings = rank_by_time(valid_rows)

            if not rankings:
                continue

            # Build rank dict for this category
            rank_dict = {st: rank for st, _, rank in rankings}

            # For each sort type with an entry in this category
            sort_types_in_category = set(r["sort_type"] for r in category_rows)

            for st in sort_types_in_category:
                if st in rank_dict:
                    rank = rank_dict[st]
                else:
                    rank = len(rankings)  # Last place for skipped

                worst_case_data[st].append((size, variant, rank))

    # For each algorithm, find its worst rank (highest number = worst performance)
    worst_ranks = {}
    for st, cases in worst_case_data.items():
        worst_rank = max(rank for _, _, rank in cases)
        worst_ranks[st] = worst_rank

    # Sort by worst rank (lower = better), then by scenarios with that rank (lower = better)
    sorted_by_worst = sorted(
        worst_ranks.items(),
        key=lambda x: (x[1], sum(1 for _, _, r in worst_case_data[x[0]] if r == x[1])),
    )

    lines.append("| Rank | Sort Type | Name | Worst Rank | Scenarios |")
    lines.append("|------|-----------|------|------------|-----------|")

    for rank, (st, worst_rank) in enumerate(sorted_by_worst, 1):
        name = SORT_TYPE_INFO.get(st, {"name": st})["name"]
        # Count how many scenarios had this worst rank
        scenarios = [
            f"{size}/{variant}"
            for size, variant, r in worst_case_data[st]
            if r == worst_rank
        ]
        scenario_count = len(scenarios)

        # Highlight top 3
        prefix = "**" if rank <= 3 else ""
        suffix = "**" if rank <= 3 else ""

        lines.append(
            f"| {rank} | {prefix}{st}{suffix} | {name} | {worst_rank} | {scenario_count} |"
        )

    lines.append("")
    lines.append(
        "*Worst rank indicates the highest (poorest) position achieved across all test categories. "
        "Lower worst rank = better worst-case performance.*"
    )
    lines.append("")

    return "\n".join(lines) + "\n"


def generate_cross_category_analysis(data: List[Dict]) -> str:
    """Generate cross-category analysis using weighted average rank positions."""
    lines = ["## Cross-Category Analysis", ""]

    sizes = get_unique_values(data, "num_items")
    variants = list(VARIANT_INFO.keys())

    num_sort_types = len(SORT_TYPE_INFO)

    def is_reversed_variant(variant: str) -> bool:
        """Check if variant is a reversed scenario (lower weight)."""
        return variant.startswith("reverse_")

    def get_variant_weight(variant: str) -> float:
        """Get weight for a variant (0.05 for reversed, 1.0 for others)."""
        return 0.05 if is_reversed_variant(variant) else 1.0

    # Build set of all size/variant combinations that exist in the data
    all_categories = set()
    for row in data:
        all_categories.add((row["num_items"], row["test_variant"]))

    # Calculate weighted average rank for each sort type
    weighted_rank_sums = defaultdict(float)
    total_weight = defaultdict(float)
    top3_counts = defaultdict(int)
    win_counts = defaultdict(int)

    for size in sizes:
        for variant in variants:
            if (size, variant) not in all_categories:
                continue

            # Get all rows for this category (including skipped ones)
            category_rows = [
                r
                for r in data
                if r["num_items"] == size and r["test_variant"] == variant
            ]

            # Get only valid (non-skipped) rows for ranking
            valid_rows = [r for r in category_rows if r.get("_valid", False)]
            rankings = rank_by_time(valid_rows)
            weight = get_variant_weight(variant)

            # Build ranking dict for this category (only valid entries get ranked)
            rank_dict = {st: rank for st, _, rank in rankings} if rankings else {}

            if rankings:
                # Count wins and top 3
                win_counts[rankings[0][0]] += 1
                for st, _, _ in rankings[:3]:
                    top3_counts[st] += 1

            # For each sort type that has an entry in this category (valid or skipped)
            sort_types_in_category = set(r["sort_type"] for r in category_rows)

            for st in SORT_TYPE_INFO.keys():
                if st in sort_types_in_category:
                    # Algorithm has an entry - check if it's valid or skipped
                    if st in rank_dict:
                        rank = rank_dict[st]
                    else:
                        # Algorithm was skipped for this category - assign last place
                        rank = num_sort_types

                    weighted_rank_sums[st] += rank * weight
                    total_weight[st] += weight

    # Calculate weighted average rank for each sort type
    weighted_avg_ranks = {}
    for st in SORT_TYPE_INFO.keys():
        if total_weight[st] > 0:
            weighted_avg_ranks[st] = weighted_rank_sums[st] / total_weight[st]

    # Sort by weighted average rank (lower is better)
    sorted_by_rank = sorted(weighted_avg_ranks.items(), key=lambda x: x[1])

    total_categories = len(sizes) * len(variants)

    lines.append("### Overall Performance Ranking (Weighted Average)")
    lines.append("")
    lines.append("| Rank | Sort Type | Name | Weighted Rank | Wins | Top 3 |")
    lines.append("|------|-----------|------|---------------|------|-------|")

    for rank, (st, avg_rank) in enumerate(sorted_by_rank, 1):
        name = SORT_TYPE_INFO.get(st, {"name": st})["name"]
        wins = win_counts.get(st, 0)
        top3 = top3_counts.get(st, 0)

        # Highlight top 3
        prefix = "**" if rank <= 3 else ""
        suffix = "**" if rank <= 3 else ""

        lines.append(
            f"| {rank} | {prefix}{st}{suffix} | {name} | {avg_rank:.2f} | {wins} | {top3} |"
        )

    lines.append("")
    lines.append(
        "*Rankings based on weighted average finish position across all test categories. "
        "Reversed test scenarios weighted at 0.05x, all others at 1.0x. "
        "Skipped results (e.g., Insertion Sort for large datasets) counted as last place.*"
    )
    lines.append("")

    # Best for each use case
    lines.append("### Recommendations by Use Case")
    lines.append("")

    # For stable sorting requirement
    stable_algos = [st for st, info in SORT_TYPE_INFO.items() if info["stable"]]
    unstable_algos = [st for st, info in SORT_TYPE_INFO.items() if not info["stable"]]

    # Calculate best average for stable algorithms (across large sizes)
    large_sizes = ["1000000", "10000000", "100000000"]

    def calc_avg_for_sizes(algos, target_sizes):
        avgs = {}
        for st in algos:
            rows = [
                r
                for r in data
                if r.get("_valid", False)
                and r["sort_type"] == st
                and r["num_items"] in target_sizes
            ]
            if rows:
                avgs[st] = sum(r["_ns_per_item"] for r in rows) / len(rows)
        return avgs

    stable_avg = calc_avg_for_sizes(stable_algos, large_sizes)
    unstable_avg = calc_avg_for_sizes(unstable_algos, large_sizes)

    if stable_avg:
        best_stable = min(stable_avg.keys(), key=lambda x: stable_avg[x])
        lines.append(
            f"- **Best Stable Sort:** {best_stable} ({SORT_TYPE_INFO[best_stable]['name']}) - Avg: {format_ns(stable_avg[best_stable])} ns/item (1M-100M items)"
        )

    if unstable_avg:
        best_unstable = min(unstable_avg.keys(), key=lambda x: unstable_avg[x])
        lines.append(
            f"- **Best Unstable Sort:** {best_unstable} ({SORT_TYPE_INFO[best_unstable]['name']}) - Avg: {format_ns(unstable_avg[best_unstable])} ns/item (1M-100M items)"
        )

    # Best for nearly-sorted data
    nearly_sorted_variants = [
        "fully_ordered",
        "1_percent_disordered",
        "5_percent_disordered",
    ]
    nearly_sorted_rows = [
        r
        for r in data
        if r.get("_valid", False) and r["test_variant"] in nearly_sorted_variants
    ]
    ns_avg = {}
    for st in SORT_TYPE_INFO.keys():
        st_rows = [r for r in nearly_sorted_rows if r["sort_type"] == st]
        if st_rows:
            ns_avg[st] = sum(r["_ns_per_item"] for r in st_rows) / len(st_rows)

    if ns_avg:
        best_nearly = min(ns_avg.keys(), key=lambda x: ns_avg[x])
        lines.append(
            f"- **Best for Nearly-Sorted Data:** {best_nearly} ({SORT_TYPE_INFO[best_nearly]['name']}) - Avg: {format_ns(ns_avg[best_nearly])} ns/item"
        )

    # Best for random data
    random_rows = [
        r
        for r in data
        if r.get("_valid", False) and r["test_variant"] == "fully_random"
    ]
    rand_avg = {}
    for st in SORT_TYPE_INFO.keys():
        st_rows = [r for r in random_rows if r["sort_type"] == st]
        if st_rows:
            rand_avg[st] = sum(r["_ns_per_item"] for r in st_rows) / len(st_rows)

    if rand_avg:
        best_random = min(rand_avg.keys(), key=lambda x: rand_avg[x])
        lines.append(
            f"- **Best for Random Data:** {best_random} ({SORT_TYPE_INFO[best_random]['name']}) - Avg: {format_ns(rand_avg[best_random])} ns/item"
        )

    lines.append("")
    return "\n".join(lines) + "\n"


def generate_detailed_tables(data: List[Dict], sizes: List[str]) -> str:
    """Generate detailed result tables for each size."""
    lines = ["## Detailed Results by Dataset Size", ""]

    for size in sizes:
        lines.append(f"### {size} Items")
        lines.append("")

        # Get all valid rows for this size, sorted by variant then rank
        size_rows = [
            r for r in data if r.get("_valid", False) and r["num_items"] == size
        ]

        # Group by variant (maintain custom order from VARIANT_INFO)
        variants = list(VARIANT_INFO.keys())

        for variant in variants:
            variant_rows = [r for r in size_rows if r["test_variant"] == variant]

            # Rank within this variant
            rankings = rank_by_time(variant_rows)
            ranking_dict = {st: rank for st, _, rank in rankings}

            lines.append(f"#### {variant.replace('_', ' ').title()}")
            lines.append("")
            lines.append(
                "| Sort Type | Name | Time (s) | Comparisons | ns/item | Stable? | Rank |"
            )
            lines.append(
                "|-----------|------|----------|-------------|---------|---------|------|"
            )

            # Sort by rank for display
            sorted_rows = sorted(
                variant_rows, key=lambda r: ranking_dict.get(r["sort_type"], 999)
            )

            for row in sorted_rows:
                st = row["sort_type"]
                name = SORT_TYPE_INFO.get(st, {"name": st})["name"]
                stable_mark = "Yes" if row["_stable"] else "No"
                rank = ranking_dict[st]

                # Highlight top 3
                time_str = (
                    f"**{row['avg_time_sec']}**" if rank <= 3 else row["avg_time_sec"]
                )
                ns_str = (
                    f"**{format_ns(row['_ns_per_item'])}**"
                    if rank <= 3
                    else format_ns(row["_ns_per_item"])
                )

                lines.append(
                    f"| {st} | {name} | {time_str} | {row['avg_comparisons']} | {ns_str} | {stable_mark} | {rank} |"
                )

            lines.append("")

    return "\n".join(lines) + "\n"


def generate_stability_section(data: List[Dict]) -> str:
    """Generate stability verification section."""
    lines = ["## Stability Verification", ""]
    lines.append("| Sort Type | Name | Stable |")
    lines.append("|-----------|------|--------|")

    for st, info in SORT_TYPE_INFO.items():
        expected = "Stable" if info["stable"] else "Unstable"

        # Check actual stability from data - look for fully_random variant
        rows = [
            r
            for r in data
            if r["sort_type"] == st
            and r["num_items"] == "1000000"
            and r["test_variant"] == "fully_random"
        ]

        if rows and rows[0].get("_valid", False):
            verified = "Yes" if rows[0].get("_stable", False) else "No"
        else:
            verified = "N/A"

        lines.append(f"| {st} | {info['name']} | {verified} |")

    return (
        "\n".join(lines)
        + "\n\n---\n*Generated automatically from benchmark_results.csv*\n"
    )


def generate_results(
    input_file: str,
    output_file: str,
    include_detailed: bool = True,
    include_rankings: bool = True,
    include_skipped: bool = False,
):
    """Main function to generate the results markdown file."""

    print(f"Loading data from {input_file}...")
    data = load_csv_data(input_file)

    valid_count = sum(1 for r in data if r.get("_valid", False))
    print(f"Loaded {len(data)} rows, {valid_count} valid entries")

    sizes = get_unique_values(data, "num_items")
    print(f"Found {len(sizes)} unique dataset sizes: {sizes}")

    variants = list(VARIANT_INFO.keys())
    print(f"Found {len(variants)} unique test variants")

    # Build the markdown content
    sections = []

    # Always include overview and reference sections
    sections.append(generate_overview_section())
    sections.append(generate_sort_types_section())
    sections.append(generate_variant_section())

    # Cross-category Analysis Summary
    sections.append(generate_cross_category_analysis(data))

    # Size winners summary
    sections.append(generate_size_winners_summary(data))

    # Worst-case performance (exclude reversed by default)
    sections.append(generate_worst_case_analysis(data, exclude_reversed=True))

    # Summary section (always included)
    sections.append(generate_summary_by_size(data, include_skipped))

    # Rankings section
    if include_rankings:
        sections.append(generate_performance_rankings(data, include_skipped))

    # Detailed tables (optional)
    if include_detailed:
        sections.append(generate_detailed_tables(data, sizes))

    # Stability verification
    sections.append(generate_stability_section(data))

    # Write output
    output_content = "\n".join(sections)
    with open(output_file, "w") as f:
        f.write(output_content)

    print(f"\nResults written to {output_file}")
    print("Generation complete!")


def main():
    parser = argparse.ArgumentParser(
        description="Generate benchmark results markdown from CSV"
    )
    parser.add_argument(
        "--input", default="benchmark_results.csv", help="Input CSV file"
    )
    parser.add_argument("--output", default="RESULTS.md", help="Output Markdown file")
    parser.add_argument(
        "--no-detailed", action="store_true", help="Skip detailed tables"
    )
    parser.add_argument(
        "--no-rankings", action="store_true", help="Skip ranking sections"
    )
    parser.add_argument(
        "--include-skipped",
        action="store_true",
        help="Include SKIPPED entries in rankings",
    )

    args = parser.parse_args()

    generate_results(
        input_file=args.input,
        output_file=args.output,
        include_detailed=not args.no_detailed,
        include_rankings=not args.no_rankings,
        include_skipped=args.include_skipped,
    )


if __name__ == "__main__":
    main()
