/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:15:52 by alevra            #+#    #+#             */
/*   Updated: 2023/01/27 16:21:52 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	refresh(t_win *win)
{
	blackscreen(win);
	draw_map(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	win->map.height_factor = 1;
}

int	key_hook(int keycode, t_win *win)
{
	if (!keycode_is_valid(keycode, win))
		return (0);
	if (keycode == KEY_ESC)
		close_window(win);
	if (keycode == (KEY_F5))
	{
		win->map.translation = (t_p){0, 0, 0};
		win->map.alpha = 0;
		win->map.beta = 0;
		win->map.gamma = 0;
	}
	if (!BONUS)
		return (0);
	if (is_zoom_key(keycode) && is_zoom_allowed(win))
		execute_zoom(keycode, win);
	if (is_altitude_key(keycode))
		execute_altitude(keycode, win);
	if (is_arrow_key(keycode))
		execute_translation(keycode, win);
	if (is_rot_key(keycode))
		execute_rotation(keycode, win);
	refresh(win);
	return (0);
}
