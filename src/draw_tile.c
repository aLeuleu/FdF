/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:23:25 by alevra            #+#    #+#             */
/*   Updated: 2023/01/17 19:56:57 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/* draw a tile with :
p0 up left corner
p1 up right corner
p2 down left corner
p3 down right corner

Call repeatedly 'draw_lines'

[p0][p1]
[p2][p3]

 */
// void	draw_tile(t_p p0, t_p p1, t_p p2, t_p p3, t_win *win)
// {
// 	t_p	start;
// 	t_p	end;
// 	t_p	step_start;
// 	t_p	step_end;
// 	int	steps;

// 	start = p0;
// 	end = p1;
	
// 	steps = 10;
// 	step.x = abs(p0.x - p1.x);
// 	step.x /= steps;
	
// 	step.y = abs(p0.y - p2.y);
// 	step.y /= steps;

// 	log_point(p0, "p0");
// 	log_point(p1, "p1");
// 	log_point(p2, "p2");
// 	log_point(p3, "p3");

// 	log_point(step, "step");
	
// 	while (!(pts_equ(start, p2)))
// 	{
// 		ft_printf("draw line [%d][%d] -> [%d][%d]\n", start.x , start.y , end.x, end.y);
// /* 		if(steps == 10)
// 		{
// 			draw_cross(start, 15, win);
// 			draw_cross(end, 20, win);
// 		} */
// 		draw_line (start, end, win);
// 		start.y += step.y;
// 		end.y += step.y;
// 		steps--;
// 		if (steps < 0)
// 			break ;
// 	}

// 	if (steps < 0 )
// 	{
// 		ft_printf("draw_line : error\n");
// 		return (0);
// 	}
// 	return (1);
// }

void	draw_tile(t_p a, t_p p1, t_p b, t_p p3, t_win *win)
{
	int		i;
	int		steps;
	float	x;
	float	y;
	t_p		cross;
	t_p		vector;

	vector.x = (p1.x - a.x);
	vector.y = (p1.y - a.y);
	steps = max(abs(b.x - a.x), abs(b.x - a.x));
	x = a.x;
	y = a.y;
	i = 0;
	while (i <= steps)
	{
		cross.x = x;
		cross.y = y;
		// draw_cross(cross, 20, win);
		// draw_cross(add_points(cross, vector), 20, win);
		draw_line(cross, add_points(cross, vector), win);
		x += (b.x - a.x) / (float)steps;
		y += (b.y - a.y) / (float)steps;
		i++;
	}
}

void	log_point(t_p p, char *pt_name)
{
	ft_printf("%s : [%d][%d]\n", pt_name, p.x, p.y);
}