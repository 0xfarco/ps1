#include "push_swap.h"
#include <limits.h>

static int get_min_idx(t_ctx *c) {
    int i = 0;
    int idx = -1;
    int val = INT_MAX;
    while (i < c->a.size) {
        if (c->a.data[i] < val) {
            idx = i;
            val = c->a.data[i];
        }
        i++;
    }

    return (idx);
}

static void sort_three(t_ctx *c) {
    int x = c->a.data[c->a.size - 1];
    int y = c->a.data[c->a.size - 2];
    int z = c->a.data[c->a.size - 3];

    if (x > y && x > z && y < z) {
        op_ra(c);
    } else if (x > y && x > z && y > z) {
        op_ra(c);
        op_sa(c);
    } else if (x < y && x > z)
        op_rra(c);
    else if (x < y && x < z && y > z) {
        op_ra(c);
        op_sa(c);
        op_rra(c);
    } else if (x > y && x < z && y < z)
        op_sa(c);
}

static void sort_four(t_ctx *c) {
    int idx = get_min_idx(c);
    a_to_top(c, idx);
    op_pb(c);
    sort_three(c);
    op_pa(c);
}

static void sort_five(t_ctx *c) {
    int idx = get_min_idx(c);

    a_to_top(c, idx);
    op_pb(c);

    idx = get_min_idx(c);

    a_to_top(c, idx);
    op_pb(c);

    sort_three(c);
    op_pa(c);
    op_pa(c);
}

void sort_small(t_ctx *c) {
    if (c->a.size == 2) {
        op_sa(c);
    } else if (c->a.size == 3)
        sort_three(c);
    else if (c->a.size == 4)
        sort_four(c);
    else if (c->a.size == 5)
        sort_five(c);
}