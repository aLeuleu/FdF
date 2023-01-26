/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:40:33 by alevra            #+#    #+#             */
/*   Updated: 2023/01/26 23:02:45 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_cross(t_p p, int l, t_win *win)
{
	t_p	n;
	t_p	s;
	t_p	e;
	t_p	w;

	ft_printf("cross[%d][%d]\n", p.x, p.y);
	n = add_points(p, (t_p){0, -l, 0xFFffFF});
	s = add_points(p, (t_p){0, +l, 0xFFffFF});
	e = add_points(p, (t_p){+l, 0, 0xFFffFF});
	w = add_points(p, (t_p){-l, 0, 0xFFffFF});
	draw_line(n, s, win);
	draw_line(w, e, win);
}
