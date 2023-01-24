/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:08:16 by alevra            #+#    #+#             */
/*   Updated: 2023/01/24 13:12:25 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_bg(t_win *win, int color)
{
	int	i;
	int	j;
	t_p	a;
	t_p	b;

	i = 0;
	a.x = 0;
	a.y = 0;
	a.color = color;
	b.color = color;
	b.x = win->width - 1;
	b.y = 0;
	j = 0;
	while (j < win->height)
	{
		draw_line(a, b, win);
		a.y = j;
		b.y = j;
		j++;
	}
}
