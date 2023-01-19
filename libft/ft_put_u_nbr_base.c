/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_nbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:53:02 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 15:21:06 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	base_is_valid(char *base);
static int			char_is_plus_or_minus(char c);

int	ft_put_u_nbr_base(unsigned long nbr, char *base, int padding)
{
	unsigned int	base_size;
	int				str_len;
	int				res;

	str_len = 0;
	res = 0;
	if (!(base_is_valid(base)))
		return (-1);
	base_size = ft_strlen(base);
	if (nbr >= base_size || padding > 0)
	{
		res = ft_put_u_nbr_base(nbr / base_size, base, padding - 1);
		if (res < 0)
			return (-1);
		str_len += res;
	}
	res = ft_putchar(base[nbr % base_size]);
	if (res < 0)
		return (-1);
	str_len += res;
	return (str_len);
}

static unsigned int	base_is_valid(char *base)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (base[i])
		if (char_is_plus_or_minus(base[i++]))
			return (0);
	if (i < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	char_is_plus_or_minus(char c)
{
	return (c == '-' || c == '+');
}
