/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by login             #+#    #+#             */
/*   Updated: 2026/11/10 09:01:42 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*strategy_name(int strategy, float disorder)
{
	if (strategy == S_SIMPLE)
		return ("Simple / O(n^2)");
	if (strategy == S_MEDIUM)
		return ("Medium / O(n√n)");
	if (strategy == S_COMPLEX)
		return ("Complex / O(nlogn)");
	if (disorder < LOW_DISORDER)
		return ("Adaptive / O(n^2)");
	if (disorder < MID_DISORDER)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(nlogn)");
}

void	run_strategy(t_ctx *c, int strategy, float disorder)
{
	if (strategy == S_SIMPLE)
		selection_sort(c);
	else if (strategy == S_MEDIUM)
		chunk_based_sort(c);
	else if (strategy == S_COMPLEX)
		lsd_radix_sort(c);
	else if (disorder < LOW_DISORDER)
		selection_sort(c);
	else if (disorder < MID_DISORDER)
		range_window_sort(c);
	else
		lsd_radix_sort(c);
}
