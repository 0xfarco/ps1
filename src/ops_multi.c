/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_multi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by login             #+#    #+#             */
/*   Updated: 2026/11/10 12:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_n(t_ctx *c, int n)
{
	while (n-- > 0)
		op_ra(c);
}

void	rra_n(t_ctx *c, int n)
{
	while (n-- > 0)
		op_rra(c);
}

void	rb_n(t_ctx *c, int n)
{
	while (n-- > 0)
		op_rb(c);
}

void	rrb_n(t_ctx *c, int n)
{
	while (n-- > 0)
		op_rrb(c);
}
