/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:49:30 by alevra            #+#    #+#             */
/*   Updated: 2023/01/17 21:09:18 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freemap(t_map *map)
{
	int	line;

	line = map->line - 1;
	while (line >= 0)
	{
		if (map->map[line])
			free(map->map[line--]);
		else
			ft_printf("WARNING : trying to free a null pointer\n");
	}
	free(map->map);
	free(map);
}
