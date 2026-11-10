/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by login             #+#    #+#             */
/*   Updated: 2026/11/10 12:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(t_stack *s, int cap)
{
	s->size = 0;
	s->data = malloc(sizeof(int) * cap);
	return (s->data != NULL);
}

void	stack_push(t_stack *s, int v)
{
	s->data[s->size] = v;
	s->size++;
}

int	stack_pop(t_stack *s)
{
	s->size--;
	return (s->data[s->size]);
}

int	stack_top(t_stack *s)
{
	return (s->data[s->size - 1]);
}
