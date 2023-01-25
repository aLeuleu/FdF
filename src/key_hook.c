/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:09:37 by alevra            #+#    #+#             */
/*   Updated: 2023/01/25 23:55:10 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	keycode_is_valid(int keycode, t_win *win);

int	key_hook(int keycode, t_win *win)
{
	if (!keycode_is_valid(keycode, win))
		return (0);
	if (keycode == KEY_ESC)
		close_window(win);
	if (!BONUS)
		return (0);
	if (keycode == KEY_PLUS && win->map.scale < 5)
		win->map.scale *= 1.2;
	if (keycode == KEY_MINUS && win->map.scale > 0.4)
		win->map.scale *= 0.8;
	if (keycode == KEY_Z)
		win->map.height_factor = 1.2;
	if (keycode == KEY_X)
		win->map.height_factor = 0.8;
	blackscreen(win);
	draw_map(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	win->map.height_factor = 1;
	win->map.height_factor = 1;
	return (0);
}

static int	keycode_is_valid(int keycode, t_win *win)
{
	if (keycode == KEY_ESC)
		return (1);
	if (!BONUS)
		return (0);
	if (keycode == KEY_PLUS && win->map.scale < 5)
		return (1);
	if (keycode == KEY_MINUS && win->map.scale > 0.4)
		return (1);
	if (keycode == KEY_Z)
		return (1);
	if (keycode == KEY_X)
		return (1);
	return (0);
}
