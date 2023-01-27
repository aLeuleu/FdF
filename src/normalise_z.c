/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:27:55 by alevra            #+#    #+#             */
/*   Updated: 2023/01/27 16:34:07 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_min_z(t_map *map)
{
	int	i;
	int	j;
	int	min_z;

	i = 0;
	min_z = map->map[0][0].z;
	while (i < map->line)
	{
		j = 0;
		while (j < map->column)
		{
			if (min_z > map->map[i][j].z)
				min_z = map->map[i][j].z;
			j++;
		}
		i++;
	}
	return (min_z);
}

static int	get_max_z(t_map *map)
{
	int	i;
	int	j;
	int	max_z;

	i = 0;
	max_z = map->map[0][0].z;
	while (i < map->line)
	{
		j = 0;
		while (j < map->column)
		{
			if (max_z < map->map[i][j].z)
				max_z = map->map[i][j].z;
			j++;
		}
		i++;
	}
	return (max_z);
}
