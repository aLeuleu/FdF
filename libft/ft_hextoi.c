/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:53:43 by alevra            #+#    #+#             */
/*   Updated: 2023/01/25 18:54:14 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_hexa(char c)
{
	int	is_number;
	int	is_hex_letter_maj;
	int	is_hex_letter;

	is_number = (c >= '0' && c <= '9');
	is_hex_letter_maj = (c >= 'A' && c <= 'F');
	is_hex_letter = (c >= 'a' && c <= 'f');
	return (is_number || is_hex_letter || is_hex_letter_maj);
}

static int	hex_value(char c)
{
	int	is_number;
	int	is_hex_letter;
	int	is_hex_letter_maj;

	is_number = (c >= '0' && c <= '9');
	is_hex_letter_maj = (c >= 'A' && c <= 'F');
	is_hex_letter = (c >= 'a' && c <= 'f');
	if (is_number)
		return (c - '0');
	if (is_hex_letter_maj)
		return (c - 'A' + 10);
	if (is_hex_letter)
		return (c - 'a' + 10);
	return (0);
}

int	ft_hextoi(const char *a)
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
	while (is_hexa(a[i]))
	{
		res = (res * 16) + hex_value(a[i]);
		i++;
	}
	res *= sign;
	return ((int)res);
}
