/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:11:50 by alevra            #+#    #+#             */
/*   Updated: 2023/01/30 12:01:29 by alevra           ###   ########lyon.fr   */
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
	return (keycode >= KEY_NUMPAD_1 \
	&& keycode <= KEY_NUMPAD_9);
}

int	is_altitude_key(int keycode)
{
	return (keycode == KEY_Z || keycode == KEY_X);
}

int	is_zoom_key(int keycode, t_win *win)
{
	return ((keycode == KEY_PLUS && win->map.scale < 10) || \
	(keycode == KEY_MINUS && win->map.scale > 0.1));
}
