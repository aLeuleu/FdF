/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_map_coords.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:55:23 by alevra            #+#    #+#             */
/*   Updated: 2023/01/26 03:07:15 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_map_coords(t_map *map, int spacing, float height_factor)
{
	int		line;
	int		column;

	line = 0;
	while (line < map->line)
	{
		column = 0;
		while (column < map->column)
		{
			map->map[line][column].x = (column * spacing);
			map->map[line][column].y = line * spacing;
			map->map[line][column].z *= height_factor;
			if (map->map[line][column].z > 0)
				map->map[line][column].z *= -1;
			column ++;
		}
		line ++;
	}
}
