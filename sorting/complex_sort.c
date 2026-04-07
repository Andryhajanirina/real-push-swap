/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:11:17 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 15:57:34 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "../algo/algo.h"

static void	final_rotate(t_stack **a, t_config *cfg)
{
	int	pos;
	int	size;

	pos = find_min_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos--)
			ra(a, cfg);
	else
		while (pos++ < size)
			rra(a, cfg);
}

void	complex_sort(t_stack **a, t_stack **b, t_config *cfg)
{
	int	size;
	int	limit;

	size = stack_size(*a);
	limit = size - 3;
	while (stack_size(*a) > 3)
	{
		if ((*a)->index < limit)
			pb(a, b, cfg);
		else
			ra(a, cfg);
	}
	sort_3(a, cfg);
	while (*b)
		best_move(a, b, cfg);
	final_rotate(a, cfg);
}

int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_core(t_stack **a, t_stack **b, t_config *cfg, int size)
{
	int	i;
	int	j;
	int	max_bits;

	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b, cfg);
			else
				ra(a, cfg);
			j++;
		}
		while (*b)
			pa(a, b, cfg);
		i++;
	}
}

void	complex_radix_sort(t_stack **a, t_stack **b, t_config *cfg)
{
	int	size;

	size = stack_size(*a);
	if (size <= 3)
		return (sort_3(a, cfg));
	else if (size <= 5)
		return (sort_5(a, b, cfg));
	radix_core(a, b, cfg, size);
}
