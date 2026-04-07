/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:16 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 10:04:29 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a, t_config *cfg)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	if (cfg && cfg->bench)
		cfg->ops[RRA]++;
	cfg->ops[TOTAL]++;
}

void	rrb(t_stack **b, t_config *cfg)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	if (cfg && cfg->bench)
		cfg->ops[RRB]++;
	cfg->ops[TOTAL]++;
}

void	rrr(t_stack **a, t_stack **b, t_config *cfg)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	if (cfg && cfg->bench)
		cfg->ops[RRR]++;
	cfg->ops[TOTAL]++;
}
