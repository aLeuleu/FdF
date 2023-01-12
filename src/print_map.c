/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:25:45 by alevra            #+#    #+#             */
/*   Updated: 2023/01/12 16:35:53 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_map *map) //debug
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map)
		ft_printf("map : %p\n", map); //debug
	else
	{
		ft_printf("map->width : %d\n", map->column); //debug
		ft_printf("map->height : %d\n", map->line); //debug
		if (!map->map)
			ft_printf("map->map null\n");
		else
		{
			while (i < map->line)
			{
				while (j < map->column)
				{
					ft_printf("map->map[%d][%d] : (%d,%d,%d)\n", i, j, map->map[i][j].x, map->map[i][j].y, map->map[i][j].z); //debug
					j++;
				}
				j = 0;
				ft_printf("...\n");
				i++;
			}		
		}
	}
}