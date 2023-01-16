/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:09:20 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/16 17:35:06 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_win		*win_init(int height, int width, char *window_title);
static void			compute_map_x_y_coords(t_map *map, t_p spacing);
t_p3d				get_map_center(t_map *map);

t_p3d				get_map_center(t_map *map)
{
	t_p3d	center;
	int		map_width;
	int		map_height;
	t_p3d	**m;
	
	m = map->map;		
	map_width = m[0][map->column -1].x;
	map_height = m[map->line - 1][0].y;

	center.x = map_width / 2;
	center.y = map_height / 2;
	center.z = 0;
	ft_printf("center.x : %d\n", center.x); //debug
	ft_printf("center.y : %d\n", center.y); //debug
	return (center);
}

t_p	point(int x, int y)
{
	t_p res;

	res.x = x;
	res.y = y;

	return (res);
}

int	main(int argc, char **argv)
{
	t_win	*win;
	t_map	*map;
	t_p3d	map_center;
	t_p	map_center_iso;
	t_p	map_center_iso_offseted;
	t_p	spacing;
	t_p	offset;
	

	if (argc != 2)
		return (0);

	map = get_map(argv[1]);
	
	win = win_init(1500, 1500, "fdf");
	if (!win)
		return (-1);//...
	spacing.y =(win->height /(map->line)) *0.7 ;
	spacing.x = win->width /(map->column) *0.7 ;
	
	spacing.y = spacing.x + spacing.y;
	spacing.y /= 2;
	spacing.x = spacing.y;

	
	compute_map_x_y_coords(map, spacing);
	map_center = get_map_center(map);
	
	map_center_iso = iso_projection(&map_center); 
	offset = get_offset(get_win_center(win), map_center_iso);
	
	// draw_cross(map_center_iso, 50, win);
	map_center_iso_offseted = add_points(map_center_iso, offset);

	
	// draw_center(win);
	// draw_cross(map_center_iso_offseted, 50, win);
	display_map(map, win, offset);

	mlx_hook(win->win, 17, 0, close_window, win);
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

static void		compute_map_x_y_coords(t_map *map, t_p spacing)
{
	int	line;
	int	column;
	
	line = 0;
	while (line < map->line )
	{
		column = 0;
		while (column < map->column )
		{
			map->map[line][column].x = (column * spacing.x) ;
			map->map[line][column].y = line * spacing.y ;
			map->map[line][column].z *= -10;
			column ++;
		}
		line ++;
	}
}
