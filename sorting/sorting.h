/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:54 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 15:36:55 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H
# include "../push_swap.h"
# include "../utils/utils.h"
# include "../operations/operations.h"

typedef struct s_sort_ctx
{
	t_stack		**a;
	t_stack		**b;
	t_config	*cfg;
	int			i;
	int			chunk;
}	t_sort_ctx;

void	index_stack(t_stack *a);
void	sort_3(t_stack **a, t_config *cfg);
void	sort_5(t_stack **a, t_stack **b, t_config *cfg);
void	complex_sort(t_stack **a, t_stack **b, t_config *cfg);
void	complex_radix_sort(t_stack **a, t_stack **b, t_config *cfg);
void	simple_sort(t_stack **a, t_stack **b, t_config *cfg);
void	medium_sort(t_stack **a, t_stack **b, t_config *cfg);
void	assign_index(t_stack *stack, int *arr, int size);

#endif
