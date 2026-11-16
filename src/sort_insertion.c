#include "push_swap.h"
#include <limits.h>

static int	find_target_idx_in_b(t_stack *b, int val)
{
	int	i;
	int	best_idx;
	int	max_idx;

	i = 0;
	best_idx = -1;
	max_idx = 0;
	while (i < b->size)
	{
		if (b->data[i] > b->data[max_idx])
			max_idx = i;
		if (b->data[i] < val && (best_idx == -1 || b->data[i] > b->data[best_idx]))
			best_idx = i;
		i++;
	}
	if (best_idx == -1)
		return (max_idx);
	return (best_idx);
}

void	insertion_sort(t_ctx *c)
{
	int	target_idx;

	if (c->a.size < 2)
		return ;
	op_pb(c);
	op_pb(c);
	if (c->b.data[c->b.size - 1] < c->b.data[c->b.size - 2])
		op_sb(c);
    stack_print(c);
	while (c->a.size > 0)
	{
		target_idx = find_target_idx_in_b(&c->b, c->a.data[c->a.size - 1]);
		b_to_top(c, target_idx);
		op_pb(c);
        stack_print(c);
	}
	target_idx = find_target_idx_in_b(&c->b, INT_MAX);
	b_to_top(c, target_idx);
	pull_back(c);
    stack_print(c);
}
