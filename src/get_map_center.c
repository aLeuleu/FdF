/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:47:11 by alevra            #+#    #+#             */
/*   Updated: 2023/01/26 15:24:32 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p3d	get_map_center(t_map *map)
{
	t_p3d	center;
	int		map_width;
	int		map_height;
	t_p3d	**m;

	m = map->map;
	map_width = m[0][map->column -1].x;
	map_height = m[map->line - 1][0].y;
	center.x = map_width / 2;
	center.y = map_height / 2;
	center.z = 0;
	return (center);
}
