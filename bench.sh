#!/bin/bash

for i in $(seq 1 700); do
    ARG=$(shuf -i 1-100000 -n 500 | tr '\n' ' ')

    MEDIUM=$(./push_swap --medium $ARG | wc -l)
    ADAPTIVE=$(./push_swap --adaptive $ARG | wc -l)

    printf "%3d | Medium: %5d | Adaptive: %5d | Difference: %+5d\n" \
        "$i" "$MEDIUM" "$ADAPTIVE" "$((ADAPTIVE - MEDIUM))"
done
