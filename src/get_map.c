/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:45:25 by alevra            #+#    #+#             */
/*   Updated: 2023/01/11 18:12:05 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	cpy_splits_into_map_line(char **splits, t_map *map, int height);
int				how_many_lines(int fd);
static int		malloc_map(t_map **map, int width, int height);
static t_map	*parse_map(int fd);
static void		str_to_map(char *str, int fd, char **splits, t_map *map);
static char		*file_to_str(int fd);
static void		error(void);
static t_map	*get_sample_map();	//debug

t_map	*get_map(char *map_file)
{
	t_map	*map;
	int		fd;

	fd = open(map_file, O_RDONLY);
	map = parse_map(fd);
	close(fd);
	return (map);
}

static t_map	*get_sample_map() //debug
{
	t_map	*res;

	res = malloc(sizeof(t_map));
	res->height = 4;
	res->width = 4;
	res->map = malloc(sizeof(int *) * res->height);
	for (int i = 0 ; i < 4; i++)
	{
		res->map[i] = malloc(sizeof(int) * res->width);
		for (int j = 0; j < 4; j ++)
			res->map[i][j] = j*i;
	}
	print_map(res);
	return (res);
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
	if (!malloc_map(&map, how_many_splits(splits[0], ' ', NULL), height))
		return (0);
	map->height = height;
	str_to_map(str, fd, splits, map);
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
		// ft_printf("splits[%d] : %s\n", height, splits[height]); //debug
		cpy_splits_into_map_line(ft_split(splits[height], ' '), map, height);

		// ft_printf("(control) height : %d\n", height);  //debug
		// for (int i_w = 0; i_w < map->width; i_w++)
		// 	ft_printf("map->map[0][%d] : %d (%p)\n", i_w, map->map[0][i_w], &(map->map[0][i_w]) - &(map->map[0][0])); //debug

		height++;
	}

}

static void	cpy_splits_into_map_line(char **splits, t_map *map, int height)
{
	int	i;

	i = 0;
	// ft_printf("(cpying .. )height : %d\n", height); //debug
	while (i < map->width)						// SIG_ABORT if width < 5 && fsan is off !???!...
	{
		map->map[height][i] = ft_atoi(splits[i]);
		// ft_printf("\tmap->map[%d][%d] : %d (%p)\n", height, i, (map->map[height][i]), &(map->map[height][i]) - &(map->map[0][0])); //debug
		i ++;
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
		return (error(),0);
	(*map)->map = malloc(sizeof(int *) * height);
	if (!(*map)->map)
		return (error(),0);

	while (i < height)
	{
		(*map)->map[i] = malloc(sizeof(int) * width);
		if (!(*map)->map[i])
			return (error(),ft_freetab((void **)((*map)->map), i), 0);
		i++;
	}
	(*map)->height = height;
	(*map)->width = width;
	// ft_printf("height : %d\n", height); //debug	
	// ft_printf("width : %d\n", width); //debug
	// for (size_t i = 0; i < (*map)->height; i++)
	// {
	// 	for (size_t j = 0; j < (*map)->width; j++)
	// 	{
	// 		ft_printf("[%d][%d] : (%p)\n", i, j, &((*map)->map[i][j]) - &((*map)->map[0][0]));
	// 	}
	// }
	return (1);
}
