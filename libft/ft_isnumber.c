/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:09:07 by alevra            #+#    #+#             */
/*   Updated: 2022/12/23 17:09:25 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(const char *str)
{
	int		i;

	if (!(str[0] == '-' || str[0] == '+' || ft_isdigit((int)str[0])))
		return (0);
	i = 1;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
