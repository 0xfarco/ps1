/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:37:31 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/16 12:48:09 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_idx(t_ctx *c)
{
	int	i;
	int	idx;
	int	val;

	i = 0;
	idx = -1;
	val = INT_MAX;
	while (i < c->a.size)
	{
		if (c->a.data[i] < val)
		{
			idx = i;
			val = c->a.data[i];
		}
		i++;
	}
	return (idx);
}

static void	sort_three(t_ctx *c)
{
	int	x;
	int	y;
	int	z;

	x = c->a.data[c->a.size - 1];
	y = c->a.data[c->a.size - 2];
	z = c->a.data[c->a.size - 3];
	if (x > y && x > z && y < z)
		op_ra(c);
	else if (x > y && x > z && y > z)
	{
		op_ra(c);
		op_sa(c);
	}
	else if (x < y && x > z)
		op_rra(c);
	else if (x < y && x < z && y > z)
	{
		op_ra(c);
		op_sa(c);
		op_rra(c);
	}
	else if (x > y && x < z && y < z)
		op_sa(c);
}

static void	sort_four(t_ctx *c)
{
	int	idx;

	idx = get_min_idx(c);
	a_to_top(c, idx);
	op_pb(c);
	sort_three(c);
	op_pa(c);
}

static void	sort_five(t_ctx *c)
{
	int	idx;

	idx = get_min_idx(c);
	a_to_top(c, idx);
	op_pb(c);
	idx = get_min_idx(c);
	a_to_top(c, idx);
	op_pb(c);
	sort_three(c);
	op_pa(c);
	op_pa(c);
}

void	sort_small(t_ctx *c)
{
	if (c->a.size == 2)
		op_sa(c);
	else if (c->a.size == 3)
		sort_three(c);
	else if (c->a.size == 4)
		sort_four(c);
	else if (c->a.size == 5)
		sort_five(c);
}
