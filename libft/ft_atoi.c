/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:52:37 by alevra            #+#    #+#             */
/*   Updated: 2022/11/23 10:05:00 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_plus_or_minus(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static int	skip_whitespace(const char *a)
{
	int	offset;

	offset = 0;
	while (a[offset] == '\f' || a[offset] == '\n' || a[offset] == '\t'
		|| a[offset] == '\v' || a[offset] == '\r' || a[offset] == ' ')
	{
		offset++;
	}
	return (offset);
}

int	ft_atoi(const char *a)
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
	while (is_number(a[i]))
	{
		if (res != ((res * 10) + (a[i] - 48)) / 10)
			return ((sign + 1) / -2);
		res = (res * 10) + a[i] - '0';
		i++;
	}
	res *= sign;
	return ((int)res);
}
