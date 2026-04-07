/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:45:08 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/02 15:24:48 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_H
# define BENCH_H

# include <stdlib.h>
# include "../push_swap.h"

void	print_strategy(int fd, float disorder, t_config cfg);
void	print_bench_stats(int fd, float disorder, t_config cfg);
#endif