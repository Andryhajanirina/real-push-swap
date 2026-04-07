/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:44:18 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/17 16:44:35 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_power10(int n)
{
	long	result;

	result = 1;
	while (n-- > 0)
		result *= 10;
	return (result);
}

static int	print_decimals(int fd, double decimal, int precision)
{
	long	frac;
	long	div;
	int		count;
	char	digit;

	count = 0;
	frac = (long)(decimal * ft_power10(precision) + 0.5);
	div = ft_power10(precision - 1);
	while (precision-- > 0)
	{
		digit = (frac / div) % 10 + '0';
		count += write(fd, &digit, 1);
		div /= 10;
	}
	return (count);
}

int	ft_print_float(int fd, double n, int precision)
{
	int		count;
	long	integer;
	double	decimal;

	count = 0;
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	integer = (long)n;
	decimal = n - integer;
	count += ft_print_nbr(fd, integer);
	count += write(fd, ".", 1);
	count += print_decimals(fd, decimal, precision);
	return (count);
}
