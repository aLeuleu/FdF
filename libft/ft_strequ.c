/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:11:19 by alevra            #+#    #+#             */
/*   Updated: 2022/12/23 17:11:29 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char *str1, char *str2)
{
	size_t	str1len;
	size_t	str2len;

	str1len = ft_strlen(str1);
	str2len = ft_strlen(str2);
	if (str1len != str2len || ft_strncmp(str1, str2, ft_max(str1len, str2len)))
		return (0);
	return (1);
}
