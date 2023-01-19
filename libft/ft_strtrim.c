/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:38:16 by alevra            #+#    #+#             */
/*   Updated: 2022/11/23 14:47:13 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = -1;
	while (src[++i] && i < n)
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

static	char	*ft_strnew(int size)
{
	char	*res;

	if (size <= 0)
		size = 0;
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	while (size >= 0)
		res[size--] = 0;
	return (res);
}

static	int	contains_charset(char c, char const *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s, char const *charset)
{
	char			*res;
	int				start;
	int				end;
	unsigned int	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	start = 0;
	while (contains_charset(s[start], charset) && s[start])
		start ++;
	end = len_s;
	while (contains_charset(s[end - 1], charset) && end > start)
		end --;
	if (start > end)
		return (ft_strdup(""));
	res = ft_strnew(end - start);
	if (!res)
		return (NULL);
	else
		return (ft_strncpy(res, &(s[start]), end - start));
}
