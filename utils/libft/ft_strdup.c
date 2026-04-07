/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:43:04 by andry-ha          #+#    #+#             */
/*   Updated: 2026/02/15 12:13:55 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy_s;
	size_t	len_s;

	len_s = ft_strlen(s) + 1;
	copy_s = malloc(len_s);
	if (!copy_s)
		return (NULL);
	ft_strlcpy(copy_s, s, ft_strlen(s) + 1);
	return (copy_s);
}
