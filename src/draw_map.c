/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:01:22 by alevra            #+#    #+#             */
/*   Updated: 2023/01/27 00:19:06 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_map_line(t_map *map, int line, t_win *win, t_p offset);
static void		set_spacing(t_win *win, t_map *map, int *spacing, float scale);
void	apply_offset_center(t_map *map);

void	draw_map(t_win *win)
{
	int		i;
	int		spacing;
	t_p3d	map_center;


	i = 0;
	set_spacing(win, &win->map, &spacing, win->map.scale);
	if (win->map.need_to_compute)
	{
		compute_map_coords(&win->map, spacing, win->map.height_factor);
		map_center = get_map_center(&win->map);
		win->map.offset_center = \
		get_offset(get_win_center(win), iso_projection(&map_center, 0, 0, 0, (t_p){0, 0, 0}));
		apply_offset_center(&win->map);
	}
	win->map.need_to_compute = 0;
	while (i < win->map.line)
		draw_map_line(&win->map, i++, win, win->map.translation);
}

//apres, on veut que la map soit au centre de l'ecran

static void	draw_map_line(t_map *map, int line, t_win *win, t_p offset)
{
	int	i;
	t_p	p;
	t_p	p_next_col;
	t_p	p_next_line;
	t_p	win_center;

	win_center = get_win_center(win);
	i = 0;
	while (i < map->column)
	{
		p = iso_projection(&(map->map[line][i]), map, win_center);
		p_next_col = iso_projection(next_map_element(map, i, line), map, win_center);
		p = add_points(p, offset);
		p_next_col = add_points(p_next_col, offset);
		if (i != map->column - 1)
			draw_line(p, p_next_col, win);
		if (line != map->line - 1)
		{
			p_next_line = iso_projection(&(map->map[line + 1][i]), map, win_center);
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

void	apply_offset_center(t_map *map)
{
	int	i;
	int	j;
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