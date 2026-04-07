/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 15:07:26 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	sort_3(t_stack **a, t_config *cfg)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && first < third && second < third)
		sa(a, cfg);
	else if (first > second && second > third && first > third)
	{
		sa(a, cfg);
		rra(a, cfg);
	}
	else if (first > second && second < third && first > third)
		ra(a, cfg);
	else if (first < second && first > third && second > third)
		rra(a, cfg);
	else if (first < second && second > third)
	{
		sa(a, cfg);
		ra(a, cfg);
	}
}
