/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:00:55 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/13 11:20:05 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_num;
	int	bits;

	max_num = size - 1;
	bits = 0;
	while (max_num > 0)
	{
		max_num /= 2;
		bits++;
	}
	return (bits);
}

static void	sort_bit(t_ctx *c, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((stack_top(&c->a) >> bit) & 1) == 0)
			op_pb(c);
		else
			op_ra(c);
		i++;
	}
	while (c->b.size > 0)
		op_pa(c);
}

void	lsd_radix_sort(t_ctx *c)
{
	int	*sorted;
	int	max_bits;
	int	bit;

	if (c->a.size < 2)
		return ;
	sorted = ranks_in(c);
	max_bits = get_max_bits(c->a.size);
	bit = 0;
	while (bit < max_bits)
	{
		sort_bit(c, bit, c->a.size);
		bit++;
	}
	ranks_out(&c->a, sorted);
}
