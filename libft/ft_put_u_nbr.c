/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:58:35 by alevra            #+#    #+#             */
/*   Updated: 2022/12/05 17:18:24 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_u_nbr(unsigned int n)
{
	char	c;
	int		i;

	i = 0;
	if (n >= 10)
	{
		i += ft_put_u_nbr(n / 10);
		i += ft_put_u_nbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
		i++;
	}
	return (i);
}
