/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:09:37 by alevra            #+#    #+#             */
/*   Updated: 2023/01/26 22:00:50 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	keycode_is_valid(int keycode, t_win *win);
static void	refresh(t_win *win);
static int	is_arrow_key(int keycode);
static int	is_rot_key(int keycode);

int	key_hook(int keycode, t_win *win)
{
	if (!keycode_is_valid(keycode, win))
		return (0);
	if (keycode == KEY_ESC)
		close_window(win);
	if (!BONUS)
		return (0);
	if (keycode == KEY_PLUS && win->map.scale < 5)
	{
		win->map.scale *= 1.2;
		win->map.height_factor = 1.2;
		win->map.need_to_compute = 1;
	}
	if (keycode == KEY_MINUS && win->map.scale > 0.4)
	{
		win->map.scale *= 0.8;
		win->map.height_factor = 0.8;
		win->map.need_to_compute = 1;
	}
	if (keycode == KEY_Z)
	{
		win->map.need_to_compute = 1;
		win->map.height_factor = 1.2;
	}
	if (keycode == KEY_X)
	{
		win->map.need_to_compute = 1;
		win->map.height_factor = 0.8;
	}
	if (keycode == KEY_UP)
	{
		win->map.height_factor = 1;
		win->map.translation = add_points(win->map.translation, (t_p){0, -10, 0});
	}
	if (keycode == KEY_DOWN)
	{
		win->map.height_factor = 1;
		win->map.translation = add_points(win->map.translation, (t_p){0, 10, 0});
	}
	if (keycode == KEY_RIGHT)
	{
		win->map.height_factor = 1;
		win->map.translation = add_points(win->map.translation, (t_p){10, 0, 0});
	}
	if (keycode == KEY_LEFT)
	{
		win->map.height_factor = 1;
		win->map.translation = add_points(win->map.translation, (t_p){-10, 0, 0});
	}
	if (keycode == KEY_NUMPAD_SEVEN)
		win->map.α += 0.05;
	if (keycode == KEY_NUMPAD_EIGHT)
		win->map.α -= 0.05;
	if (keycode == KEY_NUMPAD_FOUR) 
		win->map.ß += 0.05;
	if (keycode == KEY_NUMPAD_FIVE)
		win->map.ß -= 0.05;
	if (keycode == KEY_NUMPAD_ONE)
		win->map.Γ += 0.05;
	if (keycode == KEY_NUMPAD_TWO)
		win->map.Γ -= 0.05;
	refresh(win);
	return (0);
}	

static void	refresh(t_win *win)
{
	blackscreen(win);
	draw_map(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	win->map.height_factor = 1;
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
	if (keycode == KEY_NUMPAD_SEVEN || keycode == KEY_NUMPAD_EIGHT)
		return (1);
	if (is_arrow_key(keycode) || is_rot_key(keycode))
		return (1);
	return (0);
}

static int	is_arrow_key(int keycode)
{
	return (keycode == KEY_UP \
	|| keycode == KEY_DOWN \
	|| keycode == KEY_RIGHT \
	|| keycode == KEY_LEFT);
}

static int	is_rot_key(int keycode)
{
	return (keycode == KEY_NUMPAD_SEVEN \
	|| keycode == KEY_NUMPAD_EIGHT \
	|| keycode == KEY_NUMPAD_FOUR \
	|| keycode == KEY_NUMPAD_FIVE \
	|| keycode == KEY_NUMPAD_ONE \
	|| keycode == KEY_NUMPAD_TWO);
}