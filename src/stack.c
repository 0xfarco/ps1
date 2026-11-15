/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:37 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:42:38 by fcholakk         ###   ########.fr       */
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

void stack_print(t_ctx *c) {
    int i = c->a.size - 1;
    ft_putstr_fd("A : [", 1);
    while (i >= 0) {
        ft_putstr_fd(" ", 1);
        ft_putnbr_fd(c->a.data[i], 1);
        i--;
    }
    ft_putstr_fd(" ]\t", 1);

    i = c->b.size - 1;
    ft_putstr_fd("B : [", 1);
    while (i >= 0) {
        ft_putstr_fd(" ", 1);
        ft_putnbr_fd(c->b.data[i], 1);
        i--;
    }
    ft_putstr_fd(" ]\n", 1);
}
