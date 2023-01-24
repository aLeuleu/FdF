/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:57:00 by alevra            #+#    #+#             */
/*   Updated: 2023/01/24 17:51:59 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	*win_init(int height, int width, char *window_title)
{
	t_win	*res;

	res = ft_calloc(sizeof(t_win), 1);
	if (!res)
		return (NULL);
	res->mlx = mlx_init();
	if (!res->mlx)
		return (free(res), NULL);
	res->win = mlx_new_window(res->mlx, width, height, window_title);
	if (!res->win)
		exit (0);
	res->img.img = mlx_new_image(res->mlx, width, height);
	if (!res->img.img)
		exit (0);
	res->img.addr = mlx_get_data_addr(res->img.img, &res->img.bits_per_pixel,
			&res->img.line_length, &res->img.endian);
	if (!res->img.addr)
		exit (0);
	res->img.bits_per_pixel /= 8;
	res->width = width;
	res->height = height;
	return (res);
}
