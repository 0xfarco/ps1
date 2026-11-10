/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by login             #+#    #+#             */
/*   Updated: 2026/11/10 12:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_ctx *c)
{
	stack_swap(&c->a);
	emit_op(c, OP_SA);
}

void	op_sb(t_ctx *c)
{
	stack_swap(&c->b);
	emit_op(c, OP_SB);
}

void	op_ss(t_ctx *c)
{
	stack_swap(&c->a);
	stack_swap(&c->b);
	emit_op(c, OP_SS);
}
