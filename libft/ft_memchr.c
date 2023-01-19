/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:53:20 by alevra            #+#    #+#             */
/*   Updated: 2022/11/23 10:09:08 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*uc_s;
	unsigned char	uc_c;

	uc_c = (unsigned char) c;
	uc_s = (unsigned char *) s;
	i = 0;
	while (uc_s[i] != uc_c && n > 1)
	{
		i ++;
		n --;
	}
	if (uc_s[i] == uc_c && n > 0)
		return ((void *)(s + i));
	else
		return (NULL);
}
