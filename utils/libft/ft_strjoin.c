/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:32:35 by andry-ha          #+#    #+#             */
/*   Updated: 2026/02/15 08:19:58 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	sjoin = malloc(ft_strlen(s1) + ft_strlen(s2) +1);
	if (!sjoin)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		sjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		sjoin[i] = s2[j];
		i++;
		j++;
	}
	sjoin[i] = '\0';
	return (sjoin);
}
