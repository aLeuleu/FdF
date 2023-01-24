/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:01:22 by alevra            #+#    #+#             */
/*   Updated: 2023/01/24 18:09:59 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_map_line(t_map *map, int line, t_win *win, t_p offset);
static void		set_spacing(t_win *win, t_map *map, int *spacing, float scale);

void	draw_map(t_map *map, t_win *win)
{
	int		i;
	int		spacing;
	t_p3d	map_center;
	t_p		offset;

	i = 0;
	set_spacing(win, map, &spacing, map->scale);
	compute_map_coords(map, spacing, map->height_factor);
	map_center = get_map_center(map);
	offset = get_offset(get_win_center(win), iso_projection(&map_center));
	while (i < map->line)
		draw_map_line(map, i++, win, offset);
}

static void	draw_map_line(t_map *map, int line, t_win *win, t_p offset)
{
	int	i;
	t_p	p;
	t_p	p_next_col;
	t_p	p_next_line;

	i = 0;
	while (i < map->column)
	{
		p = iso_projection(&(map->map[line][i]));
		p_next_col = iso_projection(next_map_element(map, i, line));
		p = add_points(p, offset);
		p_next_col = add_points(p_next_col, offset);
		if (i != map->column - 1)
			draw_line(p, p_next_col, win);
		if (line != map->line - 1)
		{
			p_next_line = iso_projection(&(map->map[line + 1][i]));
			p_next_line = add_points(p_next_line, offset);
			draw_line(p, p_next_line, win);
		}
		i++;
	}
}

static void	set_spacing(t_win *win, t_map *map, int *spacing, float scale)
{
	*spacing = ft_min(win->height, win->width)
		/ ft_max(map->line, map->column);
	*spacing *= scale;
}
