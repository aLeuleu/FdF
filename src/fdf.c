/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:09:20 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/11 23:50:17 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	display_line(t_map *map, int line, t_win *win, int line_pos, t_p spacing);
static void	display_map(t_map *map, t_win *win);
static t_win	*win_init(int height, int width, char *window_title);
static	void	put_pixel(int x, int y, t_win *win);

/* TODO 
	OK - 1) s'adapter a l'ecran en largeur/hauteur
	2) tracer des lignes entres les points
	3) projeter de maniere isometrique
 */

int	main(int argc, char **argv)
{
	t_win	*win;
	t_map	*map;

	if (argc != 2)
		return (0);

	map = get_map(argv[1]);
	
	win = win_init(1000, 1500, "fdf");
	if (!win)
		return (-1);//...
	// print_map(map);
	draw_center(win);
	
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
	t_p	spacing;
	
	spacing.y =(win->height /(map->height));
	ft_printf("win->width : %d\n", win->width); //debug
	ft_printf("map->width : %d\n", map->width); //debug
	ft_printf("spacing_y : %d\n", spacing.y); //debug
	spacing.x = win->width /(map->width);
	ft_printf("spacing_x : %d\n", spacing.x); //debug
	i = 0;
	while (i < map->height)
	{
		display_line(map, i, win, (i)*spacing.y, spacing);
		i ++;
	}
}


static void		display_line(t_map *map, int line, t_win *win, int line_pos, t_p spacing)
{
	int	i;
	int	j;
	t_p	offset;
	t_p	p;
	
	
	offset.x = spacing.x /2; //(win->width)/2  - ((map->width - 1) * spacing_x)/2 ; //   
	offset.y = spacing.y /2;// (win->height)/2 - ((map->height - 1) * spacing_y)/2;//  
	j = line_pos;
	i = 0;
	while (i < map->width)
	{
		p.x = (i * spacing.x) + offset.x;
		p.y = j + offset.y;
		
		put_pixel(p.x, p.y, win);
		i++;	
	}
}

static	void	put_pixel(int x, int y, t_win *win)
{
	if (x < win->width && y < win->height )
		mlx_pixel_put(win->mlx, win->win, x, y, 0xFFFFFFF);
	else
		ft_printf("OUTBOUND [x:%d][y:%d]\n", x, y); //debug
}


/* stativ void	display_point(int x, int y)
{
	
}

static	void	display_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map)
		ft_printf("map : %p\n", map); //debug
	else
	{
		ft_printf("map->width : %d\n", map->width); //debug
		ft_printf("map->height : %d\n", map->height); //debug
		if (!map->map)
			ft_printf("map->map null\n");
		else
		{
			while (i < map->height)
			{
				while (j < map->width)
				{
					ft_printf("map->map[%d][%d] : %d\n", i, j, map->map[i][j]); //debug
					j++;
				}
				j = 0;
				ft_printf("...\n");
				i++;
			}		
		}
	}
} */