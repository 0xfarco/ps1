/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by login             #+#    #+#             */
/*   Updated: 2026/11/10 12:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_top(t_ctx *c, int idx)
{
	int	up;
	int	down;

	up = c->a.size - 1 - idx;
	down = idx + 1;
	if (up <= down)
		ra_n(c, up);
	else
		rra_n(c, down);
}

void	b_to_top(t_ctx *c, int idx)
{
	int	up;
	int	down;

	up = c->b.size - 1 - idx;
	down = idx + 1;
	if (up <= down)
		rb_n(c, up);
	else
		rrb_n(c, down);
}

void	pull_back(t_ctx *c)
{
	while (c->b.size > 0)
	{
		b_to_top(c, max_index(&c->b));
		op_pa(c);
	}
}
