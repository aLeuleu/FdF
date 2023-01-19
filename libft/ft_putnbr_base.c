/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:53:02 by alevra            #+#    #+#             */
/*   Updated: 2022/12/05 22:49:50 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		base_is_valid(char *base);
static int				char_is_plus_or_minus(char c);

int	ft_putnbr_base(long nbr, char *base)
{
	long	base_size;
	int		str_len;

	str_len = 0;
	if (!(base_is_valid(base)))
		return (0);
	base_size = (int)ft_strlen(base);
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr *= -1;
	}
	if (nbr > base_size -1)
	{
		str_len += ft_putnbr_base(nbr / base_size, base);
		str_len += ft_putnbr_base(nbr % base_size, base);
	}
	if (nbr < base_size)
	{
		ft_putchar(base[nbr]);
		str_len ++;
	}
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
			if (base[i] == base [j] && i != j)
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
