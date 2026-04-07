/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:57:10 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/19 17:46:47 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_printf(int fd, const char *str, ...);
int		ft_print_nbr(int fd, int n);
int		ft_print_hex(int fd, unsigned int n, char base);
int		ft_print_ptr(int fd, void *ptr);
int		handle_format(int fd, const char format, va_list args);
int		ft_print_float(int fd, double n, int precision);
#endif