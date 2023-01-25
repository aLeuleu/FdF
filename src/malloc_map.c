/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:58:31 by alevra            #+#    #+#             */
/*   Updated: 2023/01/25 13:15:44 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	malloc_map(t_map *map, int width)
{
	int	i;
	int	j;

	i = 0;
	map->map = ft_calloc(sizeof(t_p3d *), map->line);
	if (!map->map)
		return (0);
	while (i < map->line)
	{
		map->map[i] = ft_calloc(sizeof(t_p3d), width);
		if (!map->map[i])
			return (ft_freetab((void **)(map->map), i), 0);
		j = 0;
		while(j < width)
			map->map[i][j++].color = 0;
		i++;
	}
	map->column = width;
	return (1);
}
