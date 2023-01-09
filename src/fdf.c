/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:09:20 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/10 00:11:58 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		cpy_splits_into_map_line(char **splits, int *map_line);
static int		count_splits(char **splits);
int				how_many_lines(int fd);
static void		print_map(t_map *map);
static int		malloc_map(t_map *map, int width, int height);
static t_map	*parse_map(int fd);
static void		cpy_splits_into_map(char *str, int fd, char **splits, t_map *map);

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_data	img;
	int		fd;
	t_map	*map;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	ft_printf("bonjour\n"); //debug
	map = parse_map(fd);
	ft_printf("au revoir\n"); //debug

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 400, 400);
	win = mlx_new_window(mlx, 400, 400, "Carré noir");
	mlx_loop(mlx);
	return (0);
}

static t_map	*parse_map(int fd)
{
	char	*str;
	char	**splits;
	int		width;
	t_map	*map;
	int		height;

	map = NULL;
	height = how_many_lines(fd);
	ft_printf("flag0\n");
	str = get_next_line(fd);
	splits = ft_split(str, ' ');
	width = count_splits(splits);
	ft_printf("flag1\n");
	if (!malloc_map(map, width, height))
		return (0);
	cpy_splits_into_map(str, fd, splits, map);
	ft_printf("flag2\n");
	print_map(map);
	return (map);
}

static void	cpy_splits_into_map(char *str, int fd, char **splits, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str)
	{	
		cpy_splits_into_map_line(splits, map->map[i]);
		i++;
		free(str);
		str = get_next_line(fd);
		splits = ft_split(str, ' ');
	}
	free(str);
}

static void	print_map(t_map *map)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (height < map->height)
	{
		while (width < map->width)
			ft_printf("%d\t", map->map[height][width++]);
		ft_printf("\n");
		width = 0;
		height++;
	}
}

static int	count_splits(char **splits)
{
	int		count_splits;

	count_splits = 0;
	while (splits[count_splits])
		count_splits++;
	return (--count_splits);
}

static int	malloc_map(t_map *map, int width, int height)
{
	int	i;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->map = malloc(sizeof(int *) * height);
	if (!map->map)
		return (0);
	while (i < height)
	{
		map->map[i] = malloc(sizeof(int) * width);
		if (!map->map[i])
			return (ft_freetab((void **)(map->map), i), 0);
		i++;
	}
	return (1);
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

int	how_many_lines(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*pos;
	int		lines_count;
	int		read_value;

	pos = &buffer[0];
	lines_count = 0;
	read_value = read(fd, buffer, 2000); //debug
	while (read_value > 0)
	{
		pos = ft_strchr(pos, (int) '\n');
		while (pos)
		{
			lines_count++;
			pos = ft_strchr(pos + 1, (int) '\n');
		}
		read_value = read(fd, buffer, BUFFER_SIZE);
	}
	return (lines_count);
}