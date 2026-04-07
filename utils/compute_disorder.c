/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:45:59 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 15:47:00 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

float	compute_disorder(t_stack **stack)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*current;
	t_stack	*next_node;

	mistakes = 0;
	total_pairs = 0;
	current = *stack;
	while (current && current->next)
	{
		next_node = current->next;
		while (next_node)
		{
			total_pairs++;
			if (current->value > next_node->value)
				mistakes++;
			next_node = next_node->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / (float)total_pairs);
}
