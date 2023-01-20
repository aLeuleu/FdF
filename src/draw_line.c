/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:20:56 by alevra            #+#    #+#             */
/*   Updated: 2023/01/20 00:50:36 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_p a, t_p b, t_win *win)
{
	int		i;
	int		steps;
	float	x;
	float	y;
	t_p		to_draw;

	steps = ft_max(abs(b.x - a.x), abs(b.y - a.y));
	x = a.x;
	y = a.y;
	i = 0;
	while (i <= steps)
	{
		to_draw.x = round(x);
		to_draw.y = round(y);
		put_pixel(to_draw, win, &win->img, 0xFFFFFF);
		x += (b.x - a.x) / (float)steps;
		y += (b.y - a.y) / (float)steps;
		i++;
	}
}
