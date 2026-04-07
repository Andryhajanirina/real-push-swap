/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 23:09:21 by andry-ha          #+#    #+#             */
/*   Updated: 2026/02/15 08:20:11 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lt_len;

	i = 0;
	lt_len = ft_strlen(little);
	if (lt_len == 0)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (i + lt_len <= len && ft_strncmp(big + i, little, lt_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
