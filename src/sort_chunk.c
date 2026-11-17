/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:16 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/17 13:45:31 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunk(t_ctx *c, int min_r, int max_r)
{
	int	mid_r;
	int	target_count;
	int	pushed;
	int	r;

	mid_r = min_r + (max_r - min_r) / 2;
	target_count = max_r - min_r + 1;
	pushed = 0;
	while (pushed < target_count && c->a.size > 0)
	{
		r = stack_top(&c->a);
		if (r >= min_r && r <= max_r)
		{
			op_pb(c);
			if (r <= mid_r && c->b.size > 1)
				op_rb(c);
			pushed++;
		}
		else
			op_ra(c);
	}
}

void	chunk_sort(t_ctx *c)
{
	int	*sorted;
	int	sz;
	int	chunk_size;
	int	min_r;
	int	max_r;

	if (c->a.size < 2)
		return ;
	sz = c->a.size;
	sorted = ranks_in(c);
	chunk_size = ft_sqrt(sz);
	min_r = 0;
	while (min_r < sz)
	{
		max_r = min_r + chunk_size - 1;
		if (max_r >= sz)
			max_r = sz - 1;
		push_chunk(c, min_r, max_r);
		min_r += chunk_size;
	}
	pull_back(c);
	ranks_out(&c->a, sorted);
}
