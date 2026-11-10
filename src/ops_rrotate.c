/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by login             #+#    #+#             */
/*   Updated: 2026/11/10 12:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_ctx *c)
{
	stack_rrotate(&c->a);
	emit_op(c, OP_RRA);
}

void	op_rrb(t_ctx *c)
{
	stack_rrotate(&c->b);
	emit_op(c, OP_RRB);
}

void	op_rrr(t_ctx *c)
{
	stack_rrotate(&c->a);
	stack_rrotate(&c->b);
	emit_op(c, OP_RRR);
}
