/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:58:31 by alevra            #+#    #+#             */
/*   Updated: 2023/01/25 18:46:18 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	malloc_map(t_map *map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	map->map = ft_calloc(sizeof(t_p3d *), height);
	if (!map->map)
		return (0);
	while (i < height)
	{
		map->map[i] = ft_calloc(sizeof(t_p3d), width);
		if (!map->map[i])
			return (ft_freetab((void **)(map->map), i), 0);
		j = 0;
		while (j < width)
			map->map[i][j++].color = 0;
		i++;
	}
	map->column = width;
	map->line = height;
	return (1);
}
