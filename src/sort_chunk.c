/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:16 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:42:17 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int n)
{
	return (n / 15 + 11);
}

static void	chunk_step(t_ctx *c, int *pushed, int chunk)
{
	int	r;

	r = stack_top(&c->a);
	if (r > *pushed + chunk)
	{
		op_ra(c);
		return ;
	}
	op_pb(c);
	if (r <= *pushed && c->b.size > 1)
		op_rb(c);
	(*pushed)++;
}

void	chunk_sort(t_ctx *c)
{
	int	*sorted;
	int	chunk;
	int	pushed;

	if (c->a.size < 2)
		return ;
	sorted = ranks_in(c);
	chunk = get_chunk_size(c->a.size);
	pushed = 0;
	while (c->a.size > 0)
		chunk_step(c, &pushed, chunk);
	pull_back(c);
	ranks_out(&c->a, sorted);
}
