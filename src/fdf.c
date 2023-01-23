/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:09:20 by alevra          #+#    #+#             */
/*   Updated: 2023/01/21 17:12:31 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_hook(int keycode, t_win *win)
{
	if (keycode == ESC_KEY)
		close_window(win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	*win;
	t_map	map;

	if (argc != 2)
		return (-1);
	if (!get_map(argv[1], &map))
		return (-1);
	win = win_init(WIN_HEIGHT, WIN_WIDTH, "fdf");
	if (!win)
		return (freemap(&map), -1);
	display_map(&map, win);
	freemap(&map);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	mlx_hook(win->win, CLOSE_WINDOW_EVENT, 0, close_window, win);
	mlx_key_hook(win->win, key_hook, win);
	mlx_loop(win->mlx);
	return (0);
}
