/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overflow_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:14:22 by alevra            #+#    #+#             */
/*   Updated: 2022/12/23 17:15:50 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_overflow_int(long long nb)
{
	if (nb > INT_MAX)
		return (1);
	if (nb < INT_MIN)
		return (-1);
	return (0);
}
