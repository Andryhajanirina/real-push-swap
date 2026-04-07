/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:19:36 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 15:49:37 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	assign_index(t_stack *stack, int *arr, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == arr[i])
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void	index_stack(t_stack *stack)
{
	int	*arr;
	int	size;

	if (!stack)
		return ;
	size = stack_size(stack);
	arr = stack_to_array(stack, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	assign_index(stack, arr, size);
	free(arr);
}
