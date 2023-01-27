/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:01:22 by alevra            #+#    #+#             */
/*   Updated: 2023/01/27 16:11:21 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_map_line(t_map *map, int line, t_win *win, t_p offset);
static void		set_spacing(t_win *win, t_map *map, int *spacing, float scale);
void			apply_offset_center(t_map *map);

void	draw_map(t_win *win)
{
	int		i;
	int		spacing;
	t_p3d	map_center;
	t_p		iso_map_center;

	i = 0;
	set_spacing(win, &win->map, &spacing, win->map.scale);
	if (win->map.need_to_compute)
	{
		compute_map_coords(&win->map, spacing, win->map.height_factor);
		map_center = get_map_center(&win->map);
		iso_projection(&map_center, &win->map, (t_p){0, 0, 0}, &iso_map_center);
		win->map.offset_center = \
		get_offset(get_win_center(win), iso_map_center);
		apply_offset_center(&win->map);
	}
	win->map.need_to_compute = 0;
	while (i < win->map.line)
		draw_map_line(&win->map, i++, win, win->map.translation);
}

/* 
	p[0] : p;
	p[1] : p_next_col;
	p[2] : p_next_line;
 */
static void	draw_map_line(t_map *map, int line, t_win *win, t_p offset)
{
	int	i;
	t_p	p[3];
	t_p	win_center;

	win_center = get_win_center(win);
	i = 0;
	while (i < map->column)
	{
		iso_projection(&(map->map[line][i]), map, win_center, &p[0]);
		p[0] = add_points(p[0], offset);
		iso_projection(next_map_element(map, i, line), map, win_center, &p[1]);
		p[1] = add_points(p[1], offset);
		if (i != map->column - 1)
			draw_line(p[0], p[1], win);
		if (line != map->line - 1)
		{
			iso_projection(&(map->map[line + 1][i]), map, win_center, &p[2]);
			p[2] = add_points(p[2], offset);
			draw_line(p[0], p[2], win);
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

void	apply_offset_center(t_map *map)
{
	int		i;
	int		j;
	t_p3d	map_center;

	map_center = get_map_center(map);
	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->column)
		{
			map->map[i][j].x -= map_center.x;
			map->map[i][j].y -= map_center.y;
			j++;
		}
		i++;
	}
}
