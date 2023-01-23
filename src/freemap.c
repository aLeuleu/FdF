/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:49:30 by alevra            #+#    #+#             */
/*   Updated: 2023/01/21 17:36:51 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freemap(t_map *map)
{
	if (map->map)
		ft_freetab((void **)map->map, map->line -1);
	if (map->map)
	{
		ft_printf("map->map still exist\n");
		free(map->map);
	}
}
