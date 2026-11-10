/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by login             #+#    #+#             */
/*   Updated: 2026/11/10 12:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_ctx *c)
{
	if (c->b.size == 0)
		return ;
	stack_push(&c->a, stack_pop(&c->b));
	emit_op(c, OP_PA);
}

void	op_pb(t_ctx *c)
{
	if (c->a.size == 0)
		return ;
	stack_push(&c->b, stack_pop(&c->a));
	emit_op(c, OP_PB);
}
