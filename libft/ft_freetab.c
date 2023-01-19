/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:42:46 by alevra            #+#    #+#             */
/*   Updated: 2023/01/19 16:20:26 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(void **tab, int position)
{
	if (position >= 0)
	{
		while (position >= 0)
		{
			if (!tab[position])
				ft_printf("\n\nWARNING : trying to free a null pointer\n\n");
			else
				free(tab[position]);
			position--;
		}
	}
	free(tab);
}
