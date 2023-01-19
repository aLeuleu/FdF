/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:34:32 by alevra            #+#    #+#             */
/*   Updated: 2023/01/19 16:20:34 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	long	res;

	if (nb < 1)
		return (0);
	res = 1;
	while (res * res < nb)
		res++;
	if (res * res == nb)
		return (res);
	return (0);
}
