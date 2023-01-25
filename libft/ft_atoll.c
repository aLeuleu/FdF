/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:52:37 by alevra            #+#    #+#             */
/*   Updated: 2023/01/25 19:29:59 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *a)
{
	long long	res;
	size_t		i;
	int			sign;

	res = 0;
	i = skip_whitespace(a);
	sign = 1;
	if (is_plus_or_minus(a[i]) && is_plus_or_minus(a[i + 1]))
		return (0);
	if (a[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (a[i] == '+')
		i++;
	while ((int)ft_isdigit(a[i]))
	{
		res = (res * 10) + a[i] - '0';
		i++;
	}
	res *= sign;
	return (res);
}
