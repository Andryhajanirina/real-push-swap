/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:57:10 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/17 16:47:42 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_precision(int fd, const char *str, int *i, va_list args)
{
	int		precision;
	double	val;

	precision = 0;
	(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		precision = precision * 10 + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == 'f')
	{
		val = va_arg(args, double);
		return (ft_print_float(fd, val, precision));
	}
	return (write(fd, &str[*i], 1));
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (0);
	va_start(args, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == '.')
				count += handle_precision(fd, str, &i, args);
			else
				count += handle_format(fd, str[i], args);
		}
		else
			count += write(fd, &str[i], 1);
	}
	va_end(args);
	return (count);
}
