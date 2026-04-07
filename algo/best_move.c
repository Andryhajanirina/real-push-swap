/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:08:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 15:11:33 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	apply_rot(t_stack **a, t_stack **b, int cost[2], t_config *cfg)
{
	while (cost[COST_A] > 0 && cost[COST_B] > 0)
	{
		rr(a, b, cfg);
		cost[COST_A]--;
		cost[COST_B]--;
	}
	while (cost[COST_A] < 0 && cost[COST_B] < 0)
	{
		rrr(a, b, cfg);
		cost[COST_A]++;
		cost[COST_B]++;
	}
	while (cost[COST_A] > 0 && cost[COST_A]--)
		ra(a, cfg);
	while (cost[COST_A] < 0 && cost[COST_A]++)
		rra(a, cfg);
	while (cost[COST_B] > 0 && cost[COST_B]--)
		rb(b, cfg);
	while (cost[COST_B] < 0 && cost[COST_B]++)
		rrb(b, cfg);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	best_move(t_stack **a, t_stack **b, t_config *cfg)
{
	t_stack	*tmp;
	int		pos;
	int		cost[3];
	int		best[3];
	int		target;

	tmp = *b;
	pos = 0;
	best[BEST_TOTAL] = 2147483647;
	while (tmp)
	{
		target = target_pos(*a, tmp->index, pos, best[BEST_TOTAL]);
		cost[COST_A] = calc_cost(stack_size(*a), target);
		cost[COST_B] = calc_cost(stack_size(*b), pos++);
		cost[COST_TOTAL] = ft_abs(cost[COST_A]) + ft_abs(cost[COST_B]);
		if (cost[COST_TOTAL] < best[BEST_TOTAL])
		{
			best[BEST_A] = cost[COST_A];
			best[BEST_B] = cost[COST_B];
			best[BEST_TOTAL] = cost[COST_TOTAL];
		}
		tmp = tmp->next;
	}
	apply_rot(a, b, best, cfg);
	pa(a, b, cfg);
}
