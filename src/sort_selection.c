/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:48:50 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/13 11:24:26 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_ctx *c)
{
	if (c->a.size < 2)
		return ;
	while (c->a.size > 0)
	{
		a_to_top(c, min_index(&c->a));
		op_pb(c);
	}
	while (c->b.size > 0)
		op_pa(c);
}
