/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:01:22 by alevra            #+#    #+#             */
/*   Updated: 2023/01/16 16:38:32 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		display_map_line(t_map *map, int line, t_win *win, t_p offset);

void	display_map(t_map *map, t_win *win,t_p offset)
{
	int	i;
	i = 0;
	while (i < map->line)
	{
		display_map_line(map, i, win, offset);
		i ++;
	}
}

static void		display_map_line(t_map *map, int line, t_win *win, t_p offset)
{
	int	i;
	t_p	p;
	t_p	p_next_col;
	t_p	p_next_line;
	t_p	p_next_line_next_col;

	i = 0;
	while (i < map->column)
	{
		p = iso_projection(&(map->map[line][i]));
		p_next_col = iso_projection(next_tab_element(map, i , line));
		p = add_points(p, offset);
		p_next_col = add_points(p_next_col, offset); //record p0 p1 p2 p3 in order to draw a tile 
		if (i != map->column - 1)
			draw_line2(p, p_next_col, win);
		if (line != map->line - 1)
		{
			p_next_line = iso_projection(&(map->map[line + 1][i]));
			p_next_line = add_points(p_next_line, offset);
			draw_line2(p , p_next_line, win);
			p_next_line_next_col = iso_projection(next_tab_element(map, i , line + 1));
		}
		int z;
		z = map->map[line][i].z;
/* 		if (
			((i % 2 == 0) && (line %2 == 0) )
			||( (i % 2 == 1) && (line %2 == 1) )
			)
			if (i < map->column - 1 && line < map->line - 1)
				if (map->map[line][i].z == z && map->map[line][i+ 1].z ==z && map->map[line + 1][i].z == z && map->map[line + 1][i + 1].z == z)
					draw_tile(p, p_next_line, p_next_col, p_next_line_next_col, win);
				// if (map->map[line][i].z == 0 && map->map[line][i+ 1].z == 0 && map->map[line + 1][i].z == 0 && map->map[line + 1][i + 1].z == 0)
		 */
		i++;	
	}
}
