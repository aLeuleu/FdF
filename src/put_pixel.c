/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:22:38 by alevra            #+#    #+#             */
/*   Updated: 2023/01/13 17:24:32 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(int x, int y, t_win *win)
{
	if (x < win->width && y < win->height )
		mlx_pixel_put(win->mlx, win->win, x, y, 0xFFFFFF);
	else
		ft_printf("."); //debug
		// ft_printf("OUTBOUND [x:%d][y:%d]\n", x, y); //debug
}