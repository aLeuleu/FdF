/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_map_x_y_coords.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:55:23 by alevra            #+#    #+#             */
/*   Updated: 2023/01/17 21:10:25 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_map_x_y_coords(t_map *map, t_p spacing)
{
	int	line;
	int	column;

	line = 0;
	while (line < map->line)
	{
		column = 0;
		while (column < map->column)
		{
			map->map[line][column].x = (column * spacing.x);
			map->map[line][column].y = line * spacing.y ;
			map->map[line][column].z *= -10;
			column ++;
		}
		line ++;
	}
}
