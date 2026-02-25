#!/bin/bash

N=${1:-100}
VERBOSE=${2:-""}

if ! [[ "$N" =~ ^[0-9]+$ ]] || [ "$N" -lt 1 ]; then
    echo "Usage: $0 <n> [verbose]"
    exit 1
fi


NUMS=$(shuf -i -2147483648-2147483647 -n "$N" 2>/dev/null || \
       python3 -c "import random; nums=random.sample(range(-2147483648, 2147483648), $N); print(' '.join(map(str, nums)))")


MOVES=$(./push_swap $NUMS)


OPS=$(echo "$MOVES" | wc -l)


RESULT=$(echo "$MOVES" | ./checker $NUMS | tail -n 1)

# Output
echo "Numbers : $N"
echo "Operations: $OPS"
if [ "$RESULT" = "OK" ]; then
    echo -e "Result  : $(tput setaf 2)[OK]\033[0m"
else
    echo -e "Result  : $(tput setaf 1)[$RESULT]\033[0m"
fi
echo "--------------------Valgrind for push_swap---------------------------------------------"
valgrind --leak-check=full ./push_swap $NUMS > /dev/null
echo "--------------------------------valgrind for checker--------------------------------"
echo "$MOVES" | valgrind --leak-check=full --show-leak-kinds=all ./checker $NUMS | tail -n 1
echo $MOVES > stdout.txt

if [ "$VERBOSE" = "verbose" ]; then
    echo ""
    echo "Input   : $NUMS"
fi
