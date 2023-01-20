/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:45:25 by alevra            #+#    #+#             */
/*   Updated: 2023/01/20 15:21:20 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		cpy_splits_into_map_line(char **splits, t_map *map, int height);
static void		parse_map(int fd, t_map *map);
static int		str_to_map(char **splits, t_map *map);
static char		*file_to_str(int fd);

int	get_map(const char *map_file, t_map *map)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Could not open file %s : %s\n", map_file, strerror(errno));
		return (0);
	}
	parse_map(fd, map);
	close(fd);
	return (1);
}

static void	parse_map(int fd, t_map *map)
{
	char	**splits_by_lines;
	char	*str;
	int		columns;

	str = file_to_str(fd);
	if (!str)
		return ;
	splits_by_lines = ft_split(str, '\n');
	if (!splits_by_lines)
		return (free(str));
	map->line = ft_tablen((void **)splits_by_lines);
	columns = how_many_splits(splits_by_lines[0], ' ', NULL);
	if (!malloc_map(map, columns))
		return (ft_freetab((void **)splits_by_lines, map->line - 1),
			free(str));
	if (!str_to_map(splits_by_lines, map))
		return (ft_freetab((void **)splits_by_lines, map->line - 1),
			free(str));
	ft_freetab((void **)splits_by_lines, map->line - 1);
	free(str);
}

static int	str_to_map(char **splits_by_lines, t_map *map)
{
	int		height;
	char	**splits_by_spaces;

	height = 0;
	while (height < map->line)
	{
		splits_by_spaces = ft_split(splits_by_lines[height], ' ');
		if (!splits_by_spaces)
			return (freemap(map), 0);
		if (map->column != ft_tablen((void **)splits_by_spaces))
			return (freemap(map), ft_freetab((void **)splits_by_spaces, \
			ft_tablen((void **)splits_by_spaces)), 0);
		cpy_splits_into_map_line(splits_by_spaces, map, height);
		ft_freetab((void **)splits_by_spaces, map->column - 1);
		height++;
	}
	return (1);
}

static void	cpy_splits_into_map_line(char **splits, t_map *map, int height)
{
	int		i;
	char	*coma;

	i = 0;
	while (i < map->column)
	{
		map->map[height][i].z = ft_atoi(splits[i]);
		coma = ft_strchr(splits[i], ',');
		if (coma)
			ft_printf("coma : %s\n", coma+3);
		else
			map->map[height][i].color = 0xFFFFFF;
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
