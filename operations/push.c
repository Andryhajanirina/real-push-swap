/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:16 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 09:59:14 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_stack **a, t_stack **b, t_config *cfg)
{
	push(b, a);
	write(1, "pa\n", 3);
	if (cfg && cfg->bench)
		cfg->ops[PA]++;
	cfg->ops[TOTAL]++;
}

void	pb(t_stack **a, t_stack **b, t_config *cfg)
{
	push(a, b);
	write(1, "pb\n", 3);
	if (cfg && cfg->bench)
		cfg->ops[PB]++;
	cfg->ops[TOTAL]++;
}
