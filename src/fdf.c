/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:09:20 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/10 18:24:09 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> //debug

static void		cpy_splits_into_map_line(char **splits, int *map_line);

int				how_many_lines(int fd);
static void		print_map(t_map *map);
static int		malloc_map(t_map **map, int width, int height);
static t_map	*parse_map(int fd);
static void		str_to_map(char *str, int fd, char **splits, t_map *map);

static char	*file_to_str(int fd);

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_data	img;
	int		fd;
	t_map	*map;

	// if (argc != 2)
	// 	return (0);
	fd = open(argv[1], O_RDONLY);
	map = parse_map(fd);
	close(fd);
	ft_printf("f1\n"); //debug
	mlx = mlx_init();
	ft_printf("f1\n"); //debug
	img.img = mlx_new_image(mlx, 400, 400);
	win = mlx_new_window(mlx, 400, 400, "Carré noir");
	// mlx_pixel_put();
	mlx_loop(mlx);
	return (0);
}

static void	error(void)
{
	ft_printf("Error\n");
}

static t_map	*parse_map(int fd)
{
	char	**splits;
	t_map	*map;
	char	*str;
	int		height;

	str = file_to_str(fd);
	map = NULL;
	height = how_many_splits(str, '\n', NULL);
	splits = ft_split(str, '\n');
	if (!malloc_map(&map, 0, height))
		return (0);
	map->height = height;
	str_to_map(str, fd, splits, map);
	ft_printf("exiting parse_map\n");
	return (map);
}

static void	str_to_map(char *str, int fd, char **splits, t_map *map)
{
	int		width;
	int		height;

	height = 0;
	while (height < map->height)
	{
		if (map->width == 0)
			map->width = how_many_splits(splits[height], ' ', NULL);
		else
			if (map->width != how_many_splits(splits[height], ' ', NULL))
				error();
		cpy_splits_into_map_line(ft_split(splits[height], ' '), map->map[height]);
		height++;
	}
}

static void	cpy_splits_into_map_line(char **splits, int *map_line)
{
	while (*splits)
	{
		*map_line = ft_atoi(*splits);
		map_line++;
		splits++;
	}
}
static char	*file_to_str(int fd)
{
	char	*str;
	char	*new_str;
	char	*next_line;

	new_str = NULL;
	str = NULL;
	next_line = get_next_line(fd);
	while (next_line)
	{
		new_str = ft_strjoin(str, next_line);
		if (!new_str)
		{
			if (str)
				free(str);
			if (next_line)
				free(next_line);
			return (NULL);
		}
		free(str);
		str = new_str;
		free(next_line);
		next_line = get_next_line(fd);
	}
	return (str);
}

static int	malloc_map(t_map **map, int width, int height)
{
	int	i;

	i = 0;
	(*map) = malloc(sizeof(t_map));
	if (!(*map))
		return (0);
	(*map)->map = malloc(sizeof(int *) * height);
	if (!(*map)->map)
		return (0);
	while (i < height)
	{
		(*map)->map[i] = malloc(sizeof(int) * width);
		if (!(*map)->map[i])
			return (ft_freetab((void **)((*map)->map), i), 0);
		i++;
	}
	(*map)->height = height;
	(*map)->width = width;
	return (1);
}
static	void	print_map(t_map *map)
{
	return ;
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
}