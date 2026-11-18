*This project has been created as part of the 42 curriculum by gelgasim, fcholakk.*

# Push_swap

## Description

**Push_swap** is a 42 School algorithm project: sort a list of integers using two stacks (A and B) and a small set of operations, with as few operations as possible.

Stack A starts with the numbers. Stack B starts empty and is used as temporary storage. At the end, A must be sorted in ascending order and B must be empty.

The project includes four strategies and an adaptive mode that picks one based on how disordered the input is.

### Main Features

- All 11 push_swap operations (`sa sb ss pa pb ra rb rr rra rrb rrr`).
- Four strategies: Simple, Medium, Complex and Adaptive.
- Rank-based sorting for Medium and Complex (works with negative and large numbers).
- Disorder measurement used by the Adaptive strategy.
- Automatic merging of paired moves (`ra`+`rb` → `rr`, `rra`+`rrb` → `rrr`, `sa`+`sb` → `ss`).
- Benchmark mode (`--bench`) with per-operation statistics.
- Bonus: our own `checker` program.

## Instructions

### Compilation

```bash
make          # builds push_swap
make bonus    # builds checker
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # rebuilds everything
```

### Execution

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"     # numbers inside one argument also work
```

The program prints one operation per line. It prints nothing if the input is already sorted, and `Error` (on stderr) for invalid input: non-numbers, values outside the `int` range, or duplicates.

### Strategies

| Flag | Algorithm | Complexity |
|---|---|---|
| `--simple` | Minimum extraction | O(n²) |
| `--medium` | Range window | O(n√n) |
| `--complex` | Binary LSD Radix Sort | O(n log n) |
| `--adaptive` (default) | Chosen by disorder | depends on input |

```bash
./push_swap --simple   4 67 3 87 23
./push_swap --medium   4 67 3 87 23
./push_swap --complex  4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
```

If no strategy flag is given, Adaptive is used.

Adaptive thresholds (`LOW_DISORDER` and `MID_DISORDER` in `push_swap.h`):

| Disorder | Selected strategy |
|---|---|
| Below 20% | Simple |
| 20% to below 50% | Medium |
| 50% or higher | Complex |

### Benchmark Mode

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

Benchmark output is written to **stderr**, so it does not interfere with the operations on stdout. Example:

```text
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 15
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 0 rb: 4 rr: 0 rra: 0 rrb: 1 rrr: 0
```

### Testing with a Checker

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG          # our bonus checker
./push_swap $ARG | ./checker_linux $ARG    # 42's checker
```

Expected output: `OK` (A is sorted and B is empty), otherwise `KO`.

## Algorithm Explanation and Justification

### Stack representation

Each stack is an `int` array with a `size`. The **top** of the stack is the last element (`data[size - 1]`), so push and pop are O(1).

All moves go through `emit_op()`, which counts each operation for the benchmark and merges paired moves (for example `ra` followed by `rb` becomes `rr`) to save operations.

### 1. Disorder

Disorder measures how far the input is from sorted:

`Disorder = Inversions / Total Pairs`

An inversion is a pair of numbers in the wrong order. The result is between 0 (already sorted) and 1 (fully reversed). The Adaptive strategy uses this value to choose an algorithm.

### 2. Ranks

Medium and Complex first replace each value with its **rank**, meaning its position in sorted order (0 to n-1):

```text
Original:  40  10  30  20
Ranks:      3   0   2   1
```

This makes every value small and non-negative, which radix sort and the window logic need. The original values are restored after sorting (`ranks_in` / `ranks_out` in `rank.c`).

### 3. Simple — Selection Sort (`sort_selection.c`)

1. Find the smallest value in A.
2. Bring it to the top with `ra` if it is in the upper half, or `rra` otherwise (the shorter way).
3. Push it to B.
4. Repeat until A is empty, then push everything back to A.

**Why:** Very easy to understand, and works well for small or almost sorted inputs. Finding the minimum each time costs a full scan, so it is O(n²).

### 4. Medium — Chunk Based Sort (`sort_chunk.c`)

1. Normalize numbers: Convert all values into ranks from 0 to size - 1 using ranks_in(). This makes sorting independent of the original values.
2. Calculate chunk size: Use the square root of the stack size (ft_sqrt(sz)) to determine how many elements each chunk should contain. This balances the number of sorting passes and stack operations.
3. Divide into chunks: Split the ranked values into smaller ranges, defined by min_r and max_r.
4. Push chunks to stack B: Check the top element of stack A:
    - If its rank belongs to the current chunk, push it to stack B (pb).
    - If its rank is in the lower half of the chunk, rotate stack B (rb) to keep smaller values closer to the bottom.
    - Otherwise, rotate stack A (ra) to find the next element.
5. Repeat: Move to the next rank range and continue until all elements have been transferred to stack B.
6. Sort back to stack A: Use pull_back() to retrieve elements from stack B in descending order, placing them into stack A in ascending order.
7. Restore original values: Use ranks_out() to replace ranks with their original numbers.

**why:** Dividing numbers into smaller chunks reduces unnecessary rotations and helps organize elements before rebuilding the sorted stack, improving the efficiency of stack operations.

### 5. Complex — Binary LSD Radix Sort (`sort_radix.c`)

1. Convert values to ranks.
2. Compute how many bits the largest rank needs.
3. For each bit, from the lowest to the highest:
   - Go through every value in A: if the bit is `0`, push to B (`pb`); if it is `1`, rotate A (`ra`).
   - Push everything from B back to A.

**Why:** No searching for minimum or maximum, the same simple pass for every bit, and predictable cost on large or very disordered inputs. O(n log n).

### 6. Adaptive (`strategy.c`)

Calculates the disorder and picks Simple, Medium or Complex using the thresholds above. Nearly sorted inputs get the cheap simple method, and very mixed inputs get radix sort.

## Project Structure

```text
include/push_swap.h   types, constants, prototypes
src/
  main.c              program entry
  parse_*.c           argument and flag parsing, validation
  stack*.c            stack data structure and helpers
  ctx.c               context (both stacks + counters), errors
  ops_*.c             the 11 operations, output and move merging
  moves.c             bring an element to the top of A or B
  rank.c              rank conversion
  sort_simple.c       Simple strategy
  sort_window.c       Medium strategy
  sort_radix.c        Complex strategy
  strategy.c          strategy selection
  bench.c             benchmark output
bonus/                checker program
```

## Resources

- [Sorting Algorithms - Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Selection Sort](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)
- [Radix Sort](https://www.geeksforgeeks.org/dsa/radix-sort/)
- [Chunk-Based Sorting](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81)