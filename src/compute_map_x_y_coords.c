/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_map_x_y_coords.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:55:23 by alevra            #+#    #+#             */
/*   Updated: 2023/01/20 00:20:58 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_map_x_y_coords(t_map *map, int spacing)
{
	int	line;
	int	column;

	line = 0;
	while (line < map->line)
	{
		column = 0;
		while (column < map->column)
		{
			map->map[line][column].x = (column * spacing);
			map->map[line][column].y = line * spacing;
			map->map[line][column].z *= -spacing;
			column ++;
		}
		line ++;
	}
}
