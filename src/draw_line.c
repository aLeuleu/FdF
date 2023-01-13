/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:20:56 by alevra            #+#    #+#             */
/*   Updated: 2023/01/13 16:21:19 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_line(int x1, int x2, int y1, int y2, t_win *win);
void			draw_line2(t_p start, t_p end, t_win *win);

void	draw_line(int x0, int y0, int x1, int y1, t_win *win)
{
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;

 	for(;;){
		put_pixel(x0,y0, win);
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void	draw_line2(t_p p0, t_p p1, t_win *win)
{
/* 	ft_printf("p0.x : %d\n", p0.x); //debug
	ft_printf("p0.y : %d\n", p0.y); //debug
	ft_printf("p1.x : %d\n", p1.x); //debug
	ft_printf("p1.y : %d\n", p1.y); //debug */
	int dx = abs(p1.x-p0.x), sx = p0.x < p1.x ? 1 : -1;
	int dy = abs(p1.y-p0.y), sy = p0.y < p1.y ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;

 	for(;;){
		put_pixel(p0.x, p0.y , win);
		if (p0.x==p1.x && p0.y==p1.y) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; p0.x += sx; }
		if (e2 < dy) { err += dx; p0.y += sy; }
	}
}