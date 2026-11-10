/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by login             #+#    #+#             */
/*   Updated: 2026/11/10 12:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	c;
	t_opts	o;
	float	disorder;
	int		status;

	status = parse_args(argc, argv, &c, &o);
	if (status < 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (status == 0)
		return (0);
	disorder = compute_disorder(&c.a);
	if (c.a.size >= 2 && disorder != 0)
	{
		run_strategy(&c, o.strategy, disorder);
		flush_ops(&c);
		if (o.bench)
			bench_print(disorder, strategy_name(o.strategy, disorder), &c);
	}
	ctx_free(&c);
	return (0);
}
