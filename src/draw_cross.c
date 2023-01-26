/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:40:33 by alevra            #+#    #+#             */
/*   Updated: 2023/01/26 22:32:39 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_cross(t_p p, int l, t_win *win)
{
	t_p	n;
	t_p	s;
	t_p	e;
	t_p	w;

	n = add_points(p, (t_p){0, -l});
	s = add_points(p, (t_p){0, +l});
	e = add_points(p, (t_p){+l, 0});
	w = add_points(p, (t_p){-l, 0});
	draw_line(n, s, win);
	draw_line(w, e, win);
}
