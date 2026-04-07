/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:17:36 by andry-ha          #+#    #+#             */
/*   Updated: 2026/02/15 09:22:16 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	free_all(char **tab, int i)
{
	while (i > 0)
		free(tab[--i]);
	free(tab);
}

static int	fill_split(char **array_result, char const *s, char c)
{
	size_t	word_len;
	char	*next_sep;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			next_sep = ft_strchr(s, c);
			if (!next_sep)
				word_len = ft_strlen(s);
			else
				word_len = next_sep - s;
			array_result[i] = ft_substr(s, 0, word_len);
			if (!array_result[i])
				return (free_all(array_result, i), 0);
			i++;
			s += word_len;
		}
	}
	array_result[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array_result;

	if (!s)
		return (NULL);
	array_result = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!array_result)
		return (NULL);
	if (!fill_split(array_result, s, c))
		return (NULL);
	return (array_result);
}
