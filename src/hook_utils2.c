/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:17:48 by alevra            #+#    #+#             */
/*   Updated: 2023/01/27 16:21:37 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	execute_zoom(int keycode, t_win *win)
{
	if (keycode == KEY_PLUS)
	{
		win->map.scale *= 1.2;
		win->map.height_factor = 1.2;
	}
	if (keycode == KEY_MINUS)
	{
		win->map.scale *= 0.8;
		win->map.height_factor = 0.8;
	}
	win->map.need_to_compute = 1;
}

int	keycode_is_valid(int keycode, t_win *win)
{
	if (keycode == KEY_ESC || keycode == KEY_F5)
		return (1);
	if (!BONUS)
		return (0);
	if ((keycode == KEY_PLUS && win->map.scale < 10)
		|| (keycode == KEY_MINUS && win->map.scale > 0.1)
		|| keycode == KEY_Z || keycode == KEY_X
		|| keycode == KEY_NUMPAD_SEVEN || keycode == KEY_NUMPAD_EIGHT
		|| is_arrow_key(keycode) || is_rot_key(keycode))
		return (1);
	return (0);
}

void	execute_altitude(int keycode, t_win *win)
{
	win->map.need_to_compute = 1;
	if (keycode == KEY_Z)
		win->map.height_factor = 1.2;
	if (keycode == KEY_X)
		win->map.height_factor = 0.8;
}

void	execute_rotation(int keycode, t_win *win)
{
	if (keycode == KEY_NUMPAD_SEVEN)
		win->map.alpha += 0.005;
	if (keycode == KEY_NUMPAD_EIGHT)
		win->map.alpha -= 0.005;
	if (keycode == KEY_NUMPAD_FOUR)
		win->map.beta += 0.005;
	if (keycode == KEY_NUMPAD_FIVE)
		win->map.beta -= 0.005;
	if (keycode == KEY_NUMPAD_ONE)
		win->map.gamma += 0.005;
	if (keycode == KEY_NUMPAD_TWO)
		win->map.gamma -= 0.005;
}

void	execute_translation(int keycode, t_win *win)
{
	win->map.height_factor = 1;
	if (keycode == KEY_UP)
		win->map.translation = \
		add_points(win->map.translation, (t_p){0, -13, 0});
	if (keycode == KEY_DOWN)
		win->map.translation = \
		add_points(win->map.translation, (t_p){0, 13, 0});
	if (keycode == KEY_RIGHT)
		win->map.translation = \
		add_points(win->map.translation, (t_p){13, 0, 0});
	if (keycode == KEY_LEFT)
		win->map.translation = \
		add_points(win->map.translation, (t_p){-13, 0, 0});
}
