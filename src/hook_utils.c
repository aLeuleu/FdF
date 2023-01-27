/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:11:50 by alevra            #+#    #+#             */
/*   Updated: 2023/01/27 16:21:21 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_arrow_key(int keycode)
{
	return (keycode == KEY_UP \
	|| keycode == KEY_DOWN \
	|| keycode == KEY_RIGHT \
	|| keycode == KEY_LEFT);
}

int	is_rot_key(int keycode)
{
	return (keycode == KEY_NUMPAD_SEVEN \
	|| keycode == KEY_NUMPAD_EIGHT \
	|| keycode == KEY_NUMPAD_FOUR \
	|| keycode == KEY_NUMPAD_FIVE \
	|| keycode == KEY_NUMPAD_ONE \
	|| keycode == KEY_NUMPAD_TWO);
}

int	is_altitude_key(int keycode)
{
	return (keycode == KEY_Z || keycode == KEY_X);
}

int	is_zoom_key(int keycode)
{
	return (keycode == KEY_PLUS || keycode == KEY_MINUS);
}

int	is_zoom_allowed(t_win *win)
{
	return (win->map.scale < 10 && win->map.scale > 0.1);
}
