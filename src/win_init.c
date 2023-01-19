/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:57:00 by alevra            #+#    #+#             */
/*   Updated: 2023/01/19 15:18:42 by alevra           ###   ########lyon.fr   */
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
	res->img.img = mlx_new_image(res->mlx, width, height);
	if (!res->img.img)
		return (free(res), NULL);
	res->img.addr = mlx_get_data_addr(res->img.img, &res->img.bits_per_pixel,
			&res->img.line_length, &res->img.endian);
	res->win = mlx_new_window(res->mlx, width, height, window_title);
	if (!res->win)
		return (mlx_destroy_image(res->mlx, res->img.img), free(res), NULL);
	res->width = width;
	res->height = height;
	return (res);
}
