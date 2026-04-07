/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:31:13 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/02 15:29:59 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(int fd, int c)
{
	ft_putchar_fd(c, fd);
	return (1);
}

static int	ft_print_str(int fd, char *str)
{
	if (!str)
		return (write(2, "(null)", 6));
	return (write(fd, str, ft_strlen(str)));
}

static int	ft_print_unsigned(int fd, unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(fd, (n / 10));
	count += write(fd, &"0123456789"[n % 10], 1);
	return (count);
}

int	handle_format(int fd, const char format, va_list args)
{
	if (format == 'c')
		return (ft_print_char(fd, va_arg(args, int)));
	else if (format == 's')
		return (ft_print_str(fd, va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(fd, va_arg(args, int)));
	else if (format == 'f')
		return (ft_print_float(fd, va_arg(args, double), 6));
	else if (format == 'u')
		return (ft_print_unsigned(fd, va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_print_hex(fd, va_arg(args, unsigned int), 'x'));
	else if (format == 'X')
		return (ft_print_hex(fd, va_arg(args, unsigned int), 'X'));
	else if (format == 'p')
		return (ft_print_ptr(fd, va_arg(args, void *)));
	else if (format == '%')
		return (write(fd, "%", 1));
	else
		return (ft_print_char(fd, '%') + ft_print_char(fd, format));
	return (0);
}
