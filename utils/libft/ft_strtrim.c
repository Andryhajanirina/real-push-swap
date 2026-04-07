/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:06:24 by andry-ha          #+#    #+#             */
/*   Updated: 2026/02/15 08:20:13 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strimmed;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start += 1;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end -= 1;
	strimmed = malloc((end - start) + 1);
	if (!strimmed)
		return (NULL);
	ft_strlcpy(strimmed, (s1 + start), (end - start) + 1);
	return (strimmed);
}
