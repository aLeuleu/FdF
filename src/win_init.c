/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:57:00 by alevra            #+#    #+#             */
/*   Updated: 2023/01/25 18:51:41 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	win_init(int height, int width, char *window_title, t_win *win)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		return (freemap(&win->map), exit(EXIT_FAILURE));
	win->win = mlx_new_window(win->mlx, width, height, window_title);
	if (!win->win)
		return (freemap(&win->map), exit(EXIT_FAILURE));
	win->img.img = mlx_new_image(win->mlx, width, height);
	if (!win->img.img)
		return (freemap(&win->map), mlx_destroy_window(win->mlx, win->win), \
		exit(EXIT_FAILURE));
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bits_per_pixel,
			&win->img.line_length, &win->img.endian);
	win->img.bits_per_pixel /= 8;
	win->width = width;
	win->height = height;
}
