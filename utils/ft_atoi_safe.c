/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:52:06 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 15:41:08 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi_safe(const char *str, int *out)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	*out = (int)(result * sign);
	return (1);
}
