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
    "fb": {"name": "Forsort Basic In-Place", "stable": True},
    "fi": {"name": "Forsort Unstable In-Place", "stable": False},
    "fw": {"name": "Forsort With Workspace", "stable": True},
    "fs": {"name": "Forsort Stable In-Place", "stable": True},
    "gs": {"name": "Grail Sort In-Place", "stable": True},
    "gq": {"name": "GLibc Quick Sort", "stable": False},
    "nq": {"name": "Bentley/McIlroy Quick Sort", "stable": False},
    "ti": {"name": "TimSort", "stable": True},
    "wi": {"name": "WikiSort", "stable": True},
    "is": {"name": "Insertion Sort", "stable": True},
}


# Test variant descriptions
VARIANT_INFO = {
    "random_duplicates": "Random Data Duplicate Values",
    "random_unique": "Random Data Unique Values",
    "25_percent_disordered": "75% Ordered, 25% disorder",
    "10_percent_disordered": "90% Ordered, 10% disorder",
    "5_percent_disordered": "95% Ordered, 5% disorder",
    "1_percent_disordered": "99% Ordered, 1% disorder",
    "ordered_duplicates": "Fully Ordered Duplicate Values",
    "ordered_unique": "Fully Ordered Unique Values",
    "reversed_duplicates": "Reverse Ordered with duplicate values",
    "reversed_unique": "Reverse Ordered with unique values",
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
                else:
                    row["_valid"] = True
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

    # Get unique sizes and variants
    sizes = get_unique_values(data, "num_items")
    variants = get_unique_values(data, "test_variant")

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
    variants = get_unique_values(data, "test_variant")

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

        # Summary winner for this size (across all variants - average)
        lines.append("#### Overall Winner (Average Across All Variants)")
        lines.append("")

        avg_times = {}
        for st in SORT_TYPE_INFO.keys():
            st_rows = [r for r in size_rows if r["sort_type"] == st]
            if st_rows:
                valid_ns = [
                    r["_ns_per_item"] for r in st_rows if r.get("_valid", False)
                ]
                if valid_ns:
                    avg_times[st] = sum(valid_ns) / len(valid_ns)

        if avg_times:
            best_st = min(avg_times.keys(), key=lambda x: avg_times[x])
            lines.append(
                f"**Winner:** {best_st} ({SORT_TYPE_INFO[best_st]['name']}) - Average: {format_ns(avg_times[best_st])} ns/item"
            )

        lines.append("")

    return "\n".join(lines) + "\n"


def generate_cross_category_analysis(data: List[Dict]) -> str:
    """Generate cross-category winner analysis showing which algorithm wins most often."""
    lines = ["## Cross-Category Analysis", ""]

    sizes = get_unique_values(data, "num_items")
    variants = get_unique_values(data, "test_variant")

    # Count wins for each sort type
    win_counts = defaultdict(int)
    top3_counts = defaultdict(int)

    for size in sizes:
        for variant in variants:
            size_rows = [
                r
                for r in data
                if r.get("_valid", False)
                and r["num_items"] == size
                and r["test_variant"] == variant
            ]
            rankings = rank_by_time(size_rows)
            if rankings:
                win_counts[rankings[0][0]] += 1
                for st, _, _ in rankings[:3]:
                    top3_counts[st] += 1

    total_categories = len(sizes) * len(variants)

    lines.append("### Win Count by Algorithm")
    lines.append("")
    lines.append("| Rank | Sort Type | Name | Wins | Top 3 | Win Rate |")
    lines.append("|------|-----------|------|------|-------|----------|")

    # Sort by win count
    sorted_wins = sorted(win_counts.items(), key=lambda x: x[1], reverse=True)

    for rank, (st, wins) in enumerate(sorted_wins, 1):
        name = SORT_TYPE_INFO.get(st, {"name": st})["name"]
        top3 = top3_counts[st]
        win_rate = (
            f"{(wins / total_categories) * 100:.1f}%" if total_categories > 0 else "0%"
        )
        lines.append(f"| {rank} | **{st}** | {name} | {wins} | {top3} | {win_rate} |")

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
    nearly_sorted_variants = ["ordered", "1_percent_disordered", "5_percent_disordered"]
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
        r for r in data if r.get("_valid", False) and r["test_variant"] == "random"
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

        # Group by variant
        variants = get_unique_values(size_rows, "test_variant")

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
    lines.append("| Sort Type | Name | Expected | Verified (1M random) |")
    lines.append("|-----------|------|----------|---------------------|")

    for st, info in SORT_TYPE_INFO.items():
        expected = "Stable" if info["stable"] else "Unstable"

        # Check actual stability from data - look for either random variant
        rows = [
            r
            for r in data
            if r["sort_type"] == st
            and r["num_items"] == "1000000"
            and r["test_variant"] in ("random_duplicates", "random_unique")
        ]

        if rows and rows[0].get("_valid", False):
            verified = "Yes" if rows[0].get("_stable", False) else "No"
        else:
            verified = "N/A"

        lines.append(f"| {st} | {info['name']} | {expected} | {verified} |")

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

    variants = get_unique_values(data, "test_variant")
    print(f"Found {len(variants)} unique test variants")

    # Build the markdown content
    sections = []

    # Always include overview and reference sections
    sections.append(generate_overview_section())
    sections.append(generate_sort_types_section())
    sections.append(generate_variant_section())

    # Summary section (always included)
    sections.append(generate_summary_by_size(data, include_skipped))

    # Cross-category analysis (new feature)
    sections.append(generate_cross_category_analysis(data))

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
