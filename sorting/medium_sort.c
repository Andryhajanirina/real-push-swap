/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:51:31 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/20 15:51:47 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static int	find_max_pos(t_stack *b)
{
	int	max;
	int	pos;
	int	i;

	if (!b)
		return (-1);
	max = b->index;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return (pos);
}

static void	move_max_top(t_stack **b, t_config *cfg)
{
	int	pos;
	int	b_size;

	pos = find_max_pos(*b);
	b_size = stack_size(*b);
	if (pos <= b_size / 2)
	{
		while (pos--)
			rb(b, cfg);
	}
	else
	{
		pos = b_size - pos;
		while (pos--)
			rrb(b, cfg);
	}
}

static int	ft_sqrt_ceil(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

static void	push_to_b(t_sort_ctx *ctx)
{
	int	index;

	index = (*ctx->a)->index;
	if (index <= ctx->i)
	{
		pb(ctx->a, ctx->b, ctx->cfg);
		rb(ctx->b, ctx->cfg);
		ctx->i++;
	}
	else if (index <= ctx->i + ctx->chunk)
	{
		pb(ctx->a, ctx->b, ctx->cfg);
		ctx->i++;
	}
	else
		ra(ctx->a, ctx->cfg);
}

void	medium_sort(t_stack **a, t_stack **b, t_config *cfg)
{
	t_sort_ctx	ctx;

	ctx.a = a;
	ctx.b = b;
	ctx.cfg = cfg;
	ctx.i = 0;
	ctx.chunk = ft_sqrt_ceil(stack_size(*a));
	while (*a)
		push_to_b(&ctx);
	while (*ctx.b)
	{
		move_max_top(ctx.b, ctx.cfg);
		pa(ctx.a, ctx.b, ctx.cfg);
	}
}
