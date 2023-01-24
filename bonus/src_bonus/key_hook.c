/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:09:37 by alevra            #+#    #+#             */
/*   Updated: 2023/01/24 13:23:40 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_win *win)
{
	if (keycode == KEY_ESC)
		close_window(win);
	if (!BONUS)
		return (0);
	if (keycode == KEY_PLUS && win->map->scale < 5)
		win->map->scale *= 1.2;
	if (keycode == KEY_MINUS && win->map->scale > 0.4)
		win->map->scale *= 0.8;
	if (keycode == KEY_Z)
		win->map->height_factor = 1.2;
	if (keycode == KEY_X)
		win->map->height_factor = 0.8;
	draw_bg(win, 0);
	draw_map(win->map, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	win->map->height_factor = 1;
	win->map->height_factor = 1;
	return (0);
}
