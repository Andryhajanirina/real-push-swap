/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:00:57 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 09:55:55 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H
# include "../sorting/sorting.h"
# define COST_A 0
# define COST_B 1
# define COST_TOTAL 2
# define BEST_A 0
# define BEST_B 1
# define BEST_TOTAL 2

int		find_min_pos(t_stack *a);
int		target_pos(t_stack *a, int idx, int pos, int best_pos);
int		calc_cost(int size, int pos);
void	best_move(t_stack **a, t_stack **b, t_config *cfg);
#endif
