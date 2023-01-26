/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:01:22 by alevra            #+#    #+#             */
/*   Updated: 2023/01/26 21:54:04 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_map_line(t_map *map, int line, t_win *win, t_p offset);
static void		set_spacing(t_win *win, t_map *map, int *spacing, float scale);

void	draw_map(t_win *win)
{
	int		i;
	int		spacing;
	t_p3d	map_center;
	t_p		offset;

	i = 0;
	set_spacing(win, &win->map, &spacing, win->map.scale);
	offset = (t_p){0, 0, 0};
	if (win->map.need_to_compute)
	{
		compute_map_coords(&win->map, spacing, win->map.height_factor);
		map_center = get_map_center(&win->map);
		win->map.offset_center = \
		get_offset(get_win_center(win), iso_projection(&map_center, 0, 0, 0));
	}
	win->map.need_to_compute = 0;
	offset = add_points(win->map.offset_center, win->map.translation);
	while (i < win->map.line)
		draw_map_line(&win->map, i++, win, offset);
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
		p = iso_projection(&(map->map[line][i]), map->α, map->ß, map->Γ);
		p_next_col = iso_projection(next_map_element(map, i, line), map->α, map->ß, map->Γ);
		p = add_points(p, offset);
		p_next_col = add_points(p_next_col, offset);
		if (i != map->column - 1)
			draw_line(p, p_next_col, win);
		if (line != map->line - 1)
		{
			p_next_line = iso_projection(&(map->map[line + 1][i]), map->α, map->ß, map->Γ);
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
