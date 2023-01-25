/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:33:49 by alevra            #+#    #+#             */
/*   Updated: 2023/01/25 14:33:55 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	how_many_splits(const char *str, char c, int *res)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	if (res)
		*res = i;
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	init_var(size_t *i, size_t *j, int *index_start)
{
	*i = 0;
	*j = 0;
	*index_start = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index_start;
	char	**splits;
	size_t	strlen;

	splits = malloc((how_many_splits(s, c, NULL) + 1) * sizeof(char *));
	if (!(splits))
		return (NULL);
	init_var(&i, &j, &index_start);
	strlen = ft_strlen(s);
	while (i <= strlen)
	{
		if (s[i] != c && index_start < 0)
			index_start = i++;
		else if ((s[i++] == c || (i - 1) == strlen) && index_start >= 0)
		{
			splits[j++] = word_dup(s, index_start, (i - 1));
			if (splits[j - 1] == NULL)
				return (ft_freetab((void **)splits, j - 2), NULL);
			index_start = -1;
		}
	}
	splits[j] = 0;
	return (splits);
}
