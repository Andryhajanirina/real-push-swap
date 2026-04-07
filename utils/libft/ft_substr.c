/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:43:23 by andry-ha          #+#    #+#             */
/*   Updated: 2026/02/15 08:20:16 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy_s;
	size_t	s_len;
	size_t	copy_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		copy_s = malloc(1);
		if (!copy_s)
			return (NULL);
		copy_s[0] = '\0';
		return (copy_s);
	}
	copy_len = s_len - start;
	if (copy_len > len)
		copy_len = len;
	copy_s = malloc(copy_len + 1);
	if (!copy_s)
		return (NULL);
	copy_s = ft_memcpy(copy_s, s + start, copy_len);
	copy_s[copy_len] = '\0';
	return (copy_s);
}
