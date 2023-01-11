/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:28:31 by alevra            #+#    #+#             */
/*   Updated: 2023/01/11 23:26:05 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_center(t_win *win)		//debug
{

	for (size_t i = 0; i < win->width; i++)
		mlx_pixel_put(win->mlx, win->win, i, (win->height)/2 , 0x606060);

	for (size_t i = 0; i < win->height; i++)
		mlx_pixel_put(win->mlx, win->win, win->width /2, i , 0x606060);

}