/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_tab_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:10:20 by alevra            #+#    #+#             */
/*   Updated: 2023/01/13 16:10:31 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p3d	*next_tab_element(t_map *map, int column, int line)
{
	if (!(line < map->line && column < map->column))
		return (NULL);
	if (column != map->column -1)
		return (&(map->map[line][column +1]));
	else
		if (line != map->line -1)
			return (&(map->map[line +1][0]));
	return (NULL);
}