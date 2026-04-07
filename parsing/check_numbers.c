/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:09:00 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/02 13:38:42 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	process_split(char **split, t_stack **a)
{
	int	j;
	int	num;

	j = 0;
	while (split[j])
	{
		if (!ft_atoi_safe(split[j], &num))
			return (ft_free_split(split), 0);
		add_back(a, num);
		j++;
	}
	return (ft_free_split(split), 1);
}

int	parse_numbers(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**split;

	i = 0;
	while (++i < argc)
	{
		if (!(argv[i][0] == '-' && !ft_isdigit(argv[i][1])))
		{
			split = ft_split(argv[i], ' ');
			if (!split || !process_split(split, a))
				return (free_stack(a), 0);
		}
	}
	if (check_duplicates(*a))
		return (free_stack(a), 0);
	return (1);
}
