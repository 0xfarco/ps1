/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:37:31 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/17 19:21:14 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	idx = min_index(&c->a);
	a_to_top(c, idx);
	op_pb(c);
	sort_three(c);
	op_pa(c);
}

static void	sort_five(t_ctx *c)
{
	int	idx;

	idx = min_index(&c->a);
	a_to_top(c, idx);
	op_pb(c);
	idx = min_index(&c->a);
	a_to_top(c, idx);
	op_pb(c);
	sort_three(c);
	op_pa(c);
	op_pa(c);
}

void	sort_small(t_ctx *c)
{
	if (quick_fix(c))
		return ;
	if (c->a.size == 2)
		op_sa(c);
	else if (c->a.size == 3)
		sort_three(c);
	else if (c->a.size == 4)
		sort_four(c);
	else if (c->a.size == 5)
		sort_five(c);
}
