/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/17 13:02:13 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	sort_5(t_stack **a, t_stack **b, t_config *cfg)
{
	while (stack_size(*a) > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b, cfg);
		else
			ra(a, cfg);
	}
	sort_3(a, cfg);
	if (stack_size(*b) > 1 && (*b)->index < (*b)->next->index)
		sb(b, cfg);
	while (*b)
		pa(a, b, cfg);
}
