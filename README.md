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

### 3. Simple — Minimum Extraction (`sort_simple.c`)

1. Find the smallest value in A.
2. Bring it to the top with `ra` if it is in the upper half, or `rra` otherwise (the shorter way).
3. Push it to B.
4. Repeat until A is empty, then push everything back to A.

**Why:** very easy to understand, and works well for small or almost sorted inputs. Finding the minimum each time costs a full scan, so it is O(n²).

### 4. Medium — Range Window (`sort_window.c`)

1. Convert values to ranks.
2. Use a window of size about `√n × WINDOW_MUL / 10`, starting at rank 0.
3. Look at the top of A:
   - If its rank is above the window, rotate A (`ra`).
   - Otherwise push it to B. If its rank is in the lower part of the window (smaller than the number already pushed), also rotate B (`rb`) so small values sink to the bottom of B.
4. Each push moves the window forward by one.
5. When A is empty, repeatedly bring the largest value of B to the top and push it back to A.

**Why:** B ends up roughly sorted, so pulling the values back is cheap. This is much faster than Simple on larger inputs. O(n√n).

### 5. Complex — Binary LSD Radix Sort (`sort_radix.c`)

1. Convert values to ranks.
2. Compute how many bits the largest rank needs.
3. For each bit, from the lowest to the highest:
   - Go through every value in A: if the bit is `0`, push to B (`pb`); if it is `1`, rotate A (`ra`).
   - Push everything from B back to A.

**Why:** no searching for minimum or maximum, the same simple pass for every bit, and predictable cost on large or very disordered inputs. O(n log n).

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

### AI Usage

AI tools (ChatGPT and Claude) were used as learning assistants throughout this project.

They helped with:

- Understanding sorting algorithms and their complexity.
- Learning range-window sorting and Radix Sort.
- Understanding disorder calculation and adaptive algorithm selection.
- Merging the two team members' versions into one codebase.
- Reviewing code logic and debugging.
- Improving code structure and meeting Norminette requirements.
- Preparing test cases and understanding test results.

AI was used for explanations, guidance, and code review. The implementation was developed and tested by the project members.
