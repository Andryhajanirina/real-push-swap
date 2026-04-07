/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:01:40 by andry-ha          #+#    #+#             */
/*   Updated: 2026/02/15 08:19:30 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_of_int(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len_int;
	long	nb;

	result = 0;
	nb = n;
	len_int = len_of_int(n);
	result = malloc(sizeof(char) * (len_int + 1));
	if (!result)
		return (NULL);
	result[len_int] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		result[0] = '0';
	while (nb > 0)
	{
		result[--len_int] = (nb % 10) + '0';
		nb /= 10;
	}
	return (result);
}
