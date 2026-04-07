/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:50:30 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 12:00:14 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../utils/libft/libft.h"

static void	init_config(t_config *cfg)
{
	int	i;

	cfg->mode = 4;
	cfg->bench = 0;
	i = 0;
	while (i < 12)
		cfg->ops[i++] = 0;
}

static int	set_flag(char *arg, t_config *cfg)
{
	if (!ft_strncmp(arg, "--simple", 8) && arg[8] == '\0')
		return (cfg->mode = 1);
	if (!ft_strncmp(arg, "--medium", 8) && arg[8] == '\0')
		return (cfg->mode = 2);
	if (!ft_strncmp(arg, "--complex", 9) && arg[9] == '\0')
		return (cfg->mode = 3);
	if (!ft_strncmp(arg, "--adaptive", 10) && arg[10] == '\0')
		return (cfg->mode = 4);
	if (!ft_strncmp(arg, "--bench", 7) && arg[7] == '\0')
		return (cfg->bench = 1);
	return (0);
}

int	parse_flags(int argc, char **argv, t_config *cfg)
{
	int	i;

	i = 1;
	init_config(cfg);
	while (i < argc)
	{
		if (argv[i][0] == '-' && (!ft_isdigit(argv[i][1])))
		{
			if (!set_flag(argv[i], cfg))
				return (-1);
		}
		i++;
	}
	return (1);
}
