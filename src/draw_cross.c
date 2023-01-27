/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:40:33 by alevra            #+#    #+#             */
/*   Updated: 2023/01/27 01:07:20 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_cross(t_p p, int l, t_win *win)
{
	const t_p	n = add_points(p, (t_p){0, -l, 0xFFffFF});
	const t_p	s = add_points(p, (t_p){0, +l, 0xFFffFF});
	const t_p	e = add_points(p, (t_p){+l, 0, 0xFFffFF});
	const t_p	w = add_points(p, (t_p){-l, 0, 0xFFffFF});

	ft_printf("cross[%d][%d]\n", p.x, p.y); //debug
	draw_line(n, s, win);
	draw_line(w, e, win);
}
