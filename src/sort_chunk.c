/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by login             #+#    #+#             */
/*   Updated: 2026/11/10 12:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_below(t_stack *a, int limit)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < a->size)
	{
		if (a->data[i] < limit)
			cnt++;
		i++;
	}
	return (cnt);
}

static int	up_steps(t_stack *a, int limit)
{
	int	up;

	up = 0;
	while (a->data[a->size - 1 - up] >= limit)
		up++;
	return (up);
}

static int	down_steps(t_stack *a, int limit)
{
	int	down;

	down = 0;
	while (a->data[down] >= limit)
		down++;
	return (down + 1);
}

static void	push_chunk(t_ctx *c, int limit, int chunk)
{
	int	left;
	int	up;
	int	down;
	int	v;
	int	rbed;

	rbed = 0;
	left = count_below(&c->a, limit);
	while (left-- > 0)
	{
		up = up_steps(&c->a, limit);
		down = down_steps(&c->a, limit);
		if (up - rbed <= down)
			ra_n(c, up);
		else
			rra_n(c, down);
		v = stack_top(&c->a);
		op_pb(c);
		rbed = (v < limit - chunk / 2 && c->b.size > 1);
		if (rbed)
			op_rb(c);
	}
}

void	chunk_based_sort(t_ctx *c)
{
	int	*sorted;
	int	chunk;
	int	limit;

	if (c->a.size < 2)
		return ;
	sorted = ranks_in(c);
	chunk = (int)ft_sqrt(c->a.size) * CHUNK_MUL / 10;
	if (chunk < 1)
		chunk = 1;
	limit = chunk;
	while (c->a.size > 0)
	{
		push_chunk(c, limit, chunk);
		limit += chunk;
	}
	pull_back(c);
	ranks_out(&c->a, sorted);
}
