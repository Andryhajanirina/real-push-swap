/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strategy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:44:42 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/02 15:25:30 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

void	print_strategy(int fd, float disorder, t_config cfg)
{
	if (cfg.mode == 1)
		ft_printf(fd, "[bench] strategy: Simple / O(n²)\n");
	else if (cfg.mode == 2)
		ft_printf(fd, "[bench] strategy: Medium / O(n√n)\n");
	else if (cfg.mode == 3)
		ft_printf(fd, "[bench] strategy: Complex / O(n log n)\n");
	else if (cfg.mode == 4)
	{
		if (disorder < 0.2)
			ft_printf(fd, "[bench] strategy: Adaptive / O(n²)\n");
		else if (disorder >= 0.2 && disorder < 0.5)
			ft_printf(fd, "[bench] strategy: Adaptive / O(n√n)\n");
		else
			ft_printf(fd, "[bench] strategy: Adaptive / O(n log n)\n");
	}
	else
	{
		if (disorder < 0.2)
			ft_printf(fd, "[bench] strategy: Adaptive / O(n²)\n");
		else if (disorder >= 0.2 && disorder < 0.5)
			ft_printf(fd, "[bench] strategy: Adaptive / O(n√n)\n");
		else
			ft_printf(fd, "[bench] strategy: Adaptive / O(n log n)\n");
	}
}
