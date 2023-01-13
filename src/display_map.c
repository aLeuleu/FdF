/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:01:22 by alevra            #+#    #+#             */
/*   Updated: 2023/01/13 17:23:00 by alevra           ###   ########lyon.fr   */
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
	t_p	next;

	i = 0;
	while (i < map->column)
	{
		p = iso_projection(&(map->map[line][i]));
		next = iso_projection(next_tab_element(map, i , line));
		p = add_points(p, offset);
		next = add_points(next, offset);
		if (i != map->column - 1)
			draw_line2(p, next, win);
		if (line != map->line - 1)
		{
			next = iso_projection(&(map->map[line + 1][i]));
			next = add_points(next, offset);
			draw_line2(p , next, win);
		}
		i++;	
	}
}