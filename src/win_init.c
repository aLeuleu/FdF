/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:57:00 by alevra            #+#    #+#             */
/*   Updated: 2023/01/18 19:07:03 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	*win_init(int height, int width, char *window_title)
{
	t_win	*res;
	void	*mlx;
	void	*win;
	t_data	*img;

	res = malloc(sizeof(t_win));
	if (!res)
		return (NULL);
	mlx = mlx_init();
	if (!mlx)
		return (free(res), NULL);
	img = malloc(sizeof(t_data));
	if (!img)
		return (free(mlx), free(res), NULL);
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	win = mlx_new_window(mlx, width, height, window_title);
	res->mlx = mlx;
	res->win = win;
	res->width = width;
	res->height = height;
	res->img = img;
	return (res);
}
