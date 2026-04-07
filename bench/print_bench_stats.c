/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench_stats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:49:01 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 11:52:10 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "../sorting/sorting.h"

void	print_bench_stats(int fd, float disorder, t_config cfg)
{
	if (cfg.bench)
	{
		ft_printf(fd, "[bench] disorder: %.2f%%\n", disorder * 100);
		print_strategy(fd, disorder, cfg);
		ft_printf(fd, "[bench] total_ops: %d\n", cfg.ops[TOTAL]);
		ft_printf(fd, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
			cfg.ops[SA], cfg.ops[SB], cfg.ops[SS], cfg.ops[PA], cfg.ops[PB]);
		ft_printf(fd, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
			cfg.ops[RA], cfg.ops[RB], cfg.ops[RR],
			cfg.ops[RRA], cfg.ops[RRB], cfg.ops[RRR]);
	}
}
