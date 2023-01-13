/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:40:33 by alevra            #+#    #+#             */
/*   Updated: 2023/01/13 17:48:44 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_cross(t_p p, int l, t_win *win)
{
	int i;
	int j;

	i = p.x - l;
	j = p.y - l;
	ft_printf("(draw_cross : )\n");
	ft_printf("\tp.x : %d\n", p.x); //debug
	ft_printf("\tp.y : %d\n", p.y); //debug
	while (i < p.x + l)
		put_pixel(i++, p.y, win);
	while (j < p.y + l)
		put_pixel(p.x, j++, win);
}