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

## For the Random Numbers and a better way of using the checker you can copy paste this skript in a test.sh
#!/bin/bash

# Usage: ./test.sh <n> [verbose]
# Example: ./test.sh 100
#          ./test.sh 500 verbose

N=${1:-100}
VERBOSE=${2:-""}

if ! [[ "$N" =~ ^[0-9]+$ ]] || [ "$N" -lt 1 ]; then
    echo "Usage: $0 <n> [verbose]"
    exit 1
fi

# Generate n unique random numbers
NUMS=$(shuf -i -2147483648-2147483647 -n "$N" 2>/dev/null || \
       python3 -c "import random; nums=random.sample(range(-2147483648, 2147483648), $N); print(' '.join(map(str, nums)))")

# Get all moves
MOVES=$(./push_swap $NUMS)

# Count operations
OPS=$(echo "$MOVES" | wc -l)

# Check result
RESULT=$(echo "$MOVES" | ./checker $NUMS | tail -n 1)

# Output
echo "Numbers : $N"
echo "Operations: $OPS"
echo "Result  : $RESULT"
echo ""
#echo "Commands:"
#echo "$MOVES"

if [ "$VERBOSE" = "verbose" ]; then
    echo ""
    echo "Input   : $NUMS"
fi

##
## Note

AI was used for research and also to find errors
