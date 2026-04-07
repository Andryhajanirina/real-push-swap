/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:03:03 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/01 15:58:08 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	find_min_pos(t_stack *a)
{
	t_stack	*min;
	int		pos;

	min = find_min(a);
	pos = 0;
	while (a)
	{
		if (a == min)
			return (pos);
		pos++;
		a = a->next;
	}
	return (0);
}
