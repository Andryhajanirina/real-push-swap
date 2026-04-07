/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:05:20 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 15:18:17 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	target_pos(t_stack *a, int idx, int pos, int best_pos)
{
	t_stack	*tmp;
	int		best_diff;
	int		diff;

	tmp = a;
	pos = 0;
	best_pos = 0;
	best_diff = 2147483647;
	while (tmp)
	{
		diff = tmp->index - idx;
		if (diff > 0 && diff < best_diff)
		{
			best_diff = diff;
			best_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (best_diff == 2147483647)
		return (find_min_pos(a));
	return (best_pos);
}
