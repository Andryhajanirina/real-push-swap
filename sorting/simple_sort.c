/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:35:56 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 09:32:39 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static void	move_min_top(t_stack **a, t_config *cfg)
{
	t_stack	*min;
	t_stack	*tmp;
	int		pos;
	int		size;

	min = find_min(*a);
	pos = 0;
	tmp = *a;
	while (tmp && tmp != min)
	{
		tmp = tmp->next;
		pos++;
	}
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, cfg);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a, cfg);
	}
}

void	simple_sort(t_stack **a, t_stack **b, t_config *cfg)
{
	int	size;

	while (stack_size(*a) > 3)
	{
		move_min_top(a, cfg);
		pb(a, b, cfg);
	}
	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, cfg);
	}
	else if (size == 3)
		sort_3(a, cfg);
	while (*b)
		pa(a, b, cfg);
}
