#include "push_swap.h"
#include <stdio.h>

int get_midpoint(int chunk_start, int chunk_size) {
    return chunk_start + (chunk_size / 2) - 1;
}

// void chunk_sort(t_ctx *c) {
//     int sz = c->a.size;
//     int chunk_size = ft_sqrt(sz);
//     int chunks = sz / chunk_size;
//
//     // stack_print(c);
//
//     int *sorted = ranks_in(c);
//
//     // for(int i = 0; i < sz; i++) {
//     //     printf("%d : %d\t", i, sorted[i]);
//     // }
//     //
//     // printf("\n");
//     // printf("\n");
//
//     int j = 0;
//     int mul = 0;
//     while (j < chunks) {
//         int chunk_start = *(c->a.data + mul);
//         // int first_rank = chunk_start;
//         int rank_ubound = rank_of(sorted, sz, *(c->a.data + mul + chunk_size - 1));
//
//         int midpoint = get_midpoint(chunk_start, chunk_size);
//
//         int in = 0;
//         while (in < chunk_size) {
//             if (rank_of(sorted, sz, stack_top(&c->a)) > rank_ubound) {
//                 op_ra(c);
//             } else {
//                 op_pb(c);
//                 if (stack_top(&c->a) <= midpoint)
//                     op_rb(c);
//                 in++;
//             }
//             // stack_print(c);
//         }
//         mul += chunk_size;
//         j++;
//
//     }
//
//     pull_back(c);
//     ranks_out(&c->a, sorted);
//     // stack_print(c);
// }

int get_chunk_size(int sz) {
    // Yields ~18 for n=100, and ~42 for n=500
    return (sz / 15 + 11);
}

// void chunk_sort(t_ctx *c) {
//     int sz = c->a.size;
//     // int chunk_size = ft_sqrt(sz);
//     int chunk_size = get_chunk_size(sz);
//     int *sorted = ranks_in(c);
//     int mul = 0;
//
//     while (c->a.size > 0) {
//         int rank_ubound = mul + chunk_size - 1;
//         if (rank_ubound >= sz)
//             rank_ubound = sz - 1;
//         int midpoint = get_midpoint(mul, chunk_size);
//
//         int in = 0;
//         while (in < chunk_size && c->a.size > 0) {
//             int top_rank = rank_of(sorted, sz, stack_top(&c->a));
//             if (top_rank > rank_ubound) {
//                 op_ra(c);
//             } else {
//                 op_pb(c);
//                 if (top_rank <= midpoint)
//                     op_rb(c);
//                 in++;
//             }
//         }
//         mul += chunk_size;
//     }
//     pull_back(c);
//     // ranks_out(&c->a, sorted);
//     // stack_print(c);
//     free(sorted);
// }

void chunk_sort(t_ctx *c)
{
    int sz = c->a.size;
    int chunk_size = get_chunk_size(sz); // e.g., 15 for n=100, 35 for n=500
    int *sorted = ranks_in(c);
    int i = 0;

    while (c->a.size > 0)
    {
        int top_rank = rank_of(sorted, sz, stack_top(&c->a));
        if (top_rank <= i)
        {
            op_pb(c);
            op_rb(c);
            i++;
        }
        else if (top_rank <= i + chunk_size)
        {
            op_pb(c);
            i++;
        }
        else
            op_ra(c);
    }
    pull_back(c);
    free(sorted);
}
