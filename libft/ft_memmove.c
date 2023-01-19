/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:56:05 by alevra            #+#    #+#             */
/*   Updated: 2022/11/10 13:56:23 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (src_cpy < dest_cpy)
	{
		while (len--)
			*(dest_cpy + len) = *(src_cpy + len);
		return (dest);
	}
	else
	{
		while (len--)
			*dest_cpy++ = *src_cpy++;
		return (dest);
	}
}
