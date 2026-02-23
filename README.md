# push_swap

This project has been created as part of the 42 curriculum by dsisli

## Description

Two stacks are used: **A** (input) and **B** (helper).
Each integer gets assigned an index (0 = smallest, N-1 = largest) before sorting.

**Small sort (≤ 5 elements):** hardcoded logic with minimal operations.
**Big sort (> 5 elements):** chunk-based algorithm:
1. Split indices into chunks and push them from A to B
2. Elements below the chunk median get rotated to the bottom of B — so larger indices naturally end up on top
3. Push everything back from B to A by always rotating the maximum to the top first

Chunk sizes are tuned for the best operation count: **20** for ≤ 100 elements, **45** for ≤ 500.

## Operations

| Op | Effect |
|----|--------|
| `sa` / `sb` | swap top two elements of A / B |
| `ss` | sa and sb simultaneously |
| `pa` / `pb` | push top of B to A / top of A to B |
| `ra` / `rb` | rotate A / B (top → bottom) |
| `rr` | ra and rb simultaneously |
| `rra` / `rrb` | reverse rotate A / B (bottom → top) |
| `rrr` | rra and rrb simultaneously |

## Instructions

```bash
make
./push_swap 3 1 4 1 5 9 2 6
./push_swap "3 1 4 1 5 9 2 6"
```
##
## Note

AI was used for research and also to find errors
