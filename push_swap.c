/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:24:54 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 15:50:52 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing/parsing.h"
#include "sorting/sorting.h"
#include "utils/utils.h"
#include "bench/bench.h"

static void	choose_strategy(t_stack **a, t_stack **b, t_config *cfg)
{
	int		size;
	float	dis;

	size = stack_size(*a);
	dis = compute_disorder(a);
	if (size < 2)
		return ;
	if (dis == 0.0)
		return ;
	if (cfg->mode == 1)
		return (simple_sort(a, b, cfg));
	if (cfg->mode == 2)
		return (medium_sort(a, b, cfg));
	if (cfg->mode == 3)
		return (complex_radix_sort(a, b, cfg));
	if (dis < 0.2 || (cfg->mode == 4 && dis < 0.2) || size <= 5)
		return (simple_sort(a, b, cfg));
	else if (dis <= 0.5 || (cfg->mode == 4 && dis <= 0.5) || size <= 100)
		return (medium_sort(a, b, cfg));
	else
		return (complex_radix_sort(a, b, cfg));
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	cfg;
	float		disorder;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (parse_flags(argc, argv, &cfg) == -1)
		return (write(2, "Error\n", 6), 1);
	if (!parse_numbers(argc, argv, &a))
		return (free_stack(&a), write(2, "Error\n", 6), 1);
	if (!a)
		return (0);
	index_stack(a);
	disorder = compute_disorder(&a);
	choose_strategy(&a, &b, &cfg);
	if (cfg.bench)
		print_bench_stats(2, disorder, cfg);
	return (free_stack(&a), 0);
}
