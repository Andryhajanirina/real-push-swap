/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:16 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 10:00:24 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, t_config *cfg)
{
	swap(a);
	write(1, "sa\n", 3);
	if (cfg && cfg->bench)
		cfg->ops[SA]++;
	cfg->ops[TOTAL]++;
}

void	sb(t_stack **b, t_config *cfg)
{
	swap(b);
	write(1, "sb\n", 3);
	if (cfg && cfg->bench)
		cfg->ops[SB]++;
	cfg->ops[TOTAL]++;
}

void	ss(t_stack **a, t_stack **b, t_config *cfg)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	if (cfg && cfg->bench)
		cfg->ops[SS]++;
	cfg->ops[TOTAL]++;
}
