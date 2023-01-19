/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:29:49 by alevra            #+#    #+#             */
/*   Updated: 2022/11/23 10:37:43 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	char_c;
	int		res;

	char_c = (char)c;
	res = -1;
	i = 0;
	if (char_c == '\0')
	{
		while (s[i])
			i++;
		return ((char *)s + i);
	}
	while (s[i])
	{
		if (s[i] == char_c)
			res = i;
		i++;
	}
	if (res == -1)
		return (NULL);
	else
		return ((char *)s + res);
}
