/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:22:05 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/19 17:49:27 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(int fd, unsigned int n, char *base)
{
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_put_hex(fd, (n / 16), base);
	count += write(fd, &base[n % 16], 1);
	return (count);
}

int	ft_print_hex(int fd, unsigned int n, char base)
{
	if (base == 'X')
		return (ft_put_hex(fd, n, "0123456789ABCDEF"));
	return (ft_put_hex(fd, n, "0123456789abcdef"));
}

int	ft_print_nbr(int fd, int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = (long)n;
	if (nb < 0)
	{
		count += write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_print_nbr(fd, (nb / 10));
	count += write(fd, &"0123456789"[nb % 10], 1);
	return (count);
}

static int	ft_put_ptr(int fd, unsigned long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_put_ptr(fd, (n / 16));
	count += write(fd, &base[n % 16], 1);
	return (count);
}

int	ft_print_ptr(int fd, void *ptr)
{
	int	count;

	if (!ptr)
		return (write(fd, "(nil)", 5));
	count = 0;
	count += write(fd, "0x", 2);
	count += ft_put_ptr(fd, (unsigned long)ptr);
	return (count);
}
