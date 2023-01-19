/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:09:20 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/19 14:24:38 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p	point(int x, int y)
{
	t_p	res;

	res.x = x;
	res.y = y;
	return (res);
}

int	key_hook(int keycode, t_win *win)
{
	if (keycode == ESC_KEY)
		close_window(win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	*win;
	t_map	*map;
	t_p3d	map_center;
	t_p		spacing;
	t_p		offset;

	if (argc != 2)
		return (0);
	map = get_map(argv[1]);
	if (!map)
		return (-1);
	win = win_init(WIN_HEIGHT, WIN_WIDTH, "fdf");
	if (!win)
		return (freemap(map), -1);
	spacing.y = ft_min(win->height, win->width)
		/ ft_max(map->line, map->column);
	spacing.y *= 0.7;
	spacing.x = spacing.y;
	compute_map_x_y_coords(map, spacing);
	map_center = get_map_center(map);
	offset = get_offset(get_win_center(win), iso_projection(&map_center));
	display_map(map, win, offset);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	freemap(map);
	mlx_hook(win->win, 17, 0, close_window, win);
	mlx_key_hook(win->win, key_hook, win);
	mlx_loop(win->mlx);
	return (0);
}
