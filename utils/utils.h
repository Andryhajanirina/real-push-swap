/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:54 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/02 13:30:53 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../push_swap.h"

void	add_back(t_stack **stack, int value);
int		stack_size(t_stack *stack);
int		*stack_to_array(t_stack *stack, int size);
void	sort_array(int *arr, int size);
float	compute_disorder(t_stack **stack);
void	free_stack(t_stack **stack);
int		ft_atoi_safe(const char *str, int *out);
void	ft_free_split(char **split);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

#endif
