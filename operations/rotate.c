/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:16 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 10:00:02 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stack **a, t_config *cfg)
{
	rotate(a);
	write(1, "ra\n", 3);
	if (cfg && cfg->bench)
		cfg->ops[RA]++;
	cfg->ops[TOTAL]++;
}

void	rb(t_stack **b, t_config *cfg)
{
	rotate(b);
	write(1, "rb\n", 3);
	if (cfg && cfg->bench)
		cfg->ops[RB]++;
	cfg->ops[TOTAL]++;
}

void	rr(t_stack **a, t_stack **b, t_config *cfg)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	if (cfg && cfg->bench)
		cfg->ops[RR]++;
	cfg->ops[TOTAL]++;
}
