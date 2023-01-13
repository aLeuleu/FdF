/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:09:20 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/13 14:58:56 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		display_map_line(t_map *map, int line, t_win *win);
static void		display_map(t_map *map, t_win *win);
static t_win	*win_init(int height, int width, char *window_title);
static	void	put_pixel(int x, int y, t_win *win);
void			draw_line(int x1, int x2, int y1, int y2, t_win *win);
void			draw_line2(t_p start, t_p end, t_win *win);
static void		compute_map_x_y_coords(t_map *map, t_p spacing);
t_p3d			*next_tab_element(t_map *map, int column, int line);
t_p				projection_iso(t_p3d *p3d);
static void		compute_map_x_y_coords(t_map *map, t_p spacing);



int	main(int argc, char **argv)
{
	t_win	*win;
	t_map	*map;
	t_p	spacing;
	

	if (argc != 2)
		return (0);

	map = get_map(argv[1]);
	
	win = win_init(800, 1200, "fdf");
	if (!win)
		return (-1);//...
	// print_map(map);
	// draw_center(win);
	spacing.y =(win->height /(map->line)) * 0.5;
	spacing.x = win->width /(map->column) * 0.5;
	ft_printf("win->width : %d\n", win->width); //debug
	ft_printf("map->width : %d\n", map->column); //debug
	ft_printf("spacing_y : %d\n", spacing.y); //debug
	ft_printf("spacing_x : %d\n", spacing.x); //debug
	compute_map_x_y_coords(map, spacing);
	print_map(map);
	ft_printf("FLAG\n"); //debug
	display_map(map, win);
	
	mlx_loop(win->mlx);
	free(win); // a mettre dans une sous fonction qui libere tout a l'interieur
	return (0);
}

static t_win	*win_init(int height, int width, char *window_title)
{
	t_win	*res;
	void	*mlx;
	void	*win;
	t_data	img;

	res = malloc(sizeof(t_win));
	if (!res)
		return (NULL);

	mlx = mlx_init();
	if (!mlx)
		return (NULL); // il faut free des trucs en partant !
		
	img.img = mlx_new_image(mlx, width, height);
	win = mlx_new_window(mlx, width, height, window_title);

	res->mlx = mlx;
	res->win = win;
	res->width = width;
	res->height = height;
	return (res);
}

static void	display_map(t_map *map, t_win *win)
{
	int	i;
	i = 0;
	while (i < map->line)
	{
		display_map_line(map, i, win);
		i ++;
	}
}

static void		compute_map_x_y_coords(t_map *map, t_p spacing)
{
	int	line;
	int	column;
	t_p	offset;
	
	offset.x = spacing.x /2; 
	offset.y = spacing.y /2;
	line = 0;
	while (line < map->line )
	{
		column = 0;
		while (column < map->column )
		{
			
			map->map[line][column].x = (column * spacing.x) + offset.x;
			map->map[line][column].y = line * spacing.y + offset.y;
			map->map[line][column].z *= -3;
			column ++;
		}
		line ++;
	}
}

static void		display_map_line(t_map *map, int line, t_win *win)
{
	int	i;
	t_p	offset;
	t_p	p;
	t_p	next;

	i = 0;
	while (i < map->column)
	{
		p = projection_iso(&(map->map[line][i]));
		next = projection_iso(next_tab_element(map, i , line));
		ft_printf("line : %d\n", line); //debug
		
		if (i != map->column - 1)
		{
			ft_printf("colonne : %d\n", i); //debug
			ft_printf("drawing p(%d)->n(%d)\n", map->map[line][i].z, next_tab_element(map, i , line)->z ); //debug
			draw_line2(p , next, win);
		}
		if (line != map->line - 1)
		{
			next = projection_iso(&(map->map[line + 1][i]));
			draw_line2(p , next, win);
		}
		i++;	
	}
}

t_p3d	*next_tab_element(t_map *map, int column, int line)
{
	if (!(line < map->line && column < map->column))
		return (NULL);
	if (column != map->column -1)
		return (&(map->map[line][column +1]));
	else
		if (line != map->line -1)
			return (&(map->map[line +1][0]));
	return (NULL);
}

t_p	projection_iso(t_p3d *p3d)
{
	t_p res;
	
	res.x = 0;
	res.y = 0;
	if (!p3d)
		return (res);
	res.x = 0.7071 * (p3d->x - p3d->y);
	res.y = 0.8164 * p3d->z - ((-0.4082)*(p3d->x + p3d->y));
	return (res);
}

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
		put_pixel(p0.x +500, p0.y +200, win);
		if (p0.x==p1.x && p0.y==p1.y) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; p0.x += sx; }
		if (e2 < dy) { err += dx; p0.y += sy; }
	}
}

static	void	put_pixel(int x, int y, t_win *win)
{
	if (x < win->width && y < win->height )
		mlx_pixel_put(win->mlx, win->win, x, y, 0xFFFFFF);
	else
		ft_printf("OUTBOUND [x:%d][y:%d]\n", x, y); //debug

}
