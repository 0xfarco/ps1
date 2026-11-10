/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by login             #+#    #+#             */
/*   Updated: 2026/11/10 12:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_stack *s)
{
	int	i;
	int	min_i;

	min_i = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->data[i] < s->data[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

int	max_index(t_stack *s)
{
	int	i;
	int	max_i;

	max_i = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->data[i] > s->data[max_i])
			max_i = i;
		i++;
	}
	return (max_i);
}

float	compute_disorder(t_stack *s)
{
	int	i;
	int	j;
	int	mistakes;
	int	pairs;

	mistakes = 0;
	pairs = 0;
	i = 0;
	while (i < s->size)
	{
		j = i + 1;
		while (j < s->size)
		{
			pairs++;
			if (s->data[i] < s->data[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (pairs == 0)
		return (0);
	return ((float)mistakes / pairs);
}
