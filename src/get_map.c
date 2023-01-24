/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:45:25 by alevra            #+#    #+#             */
/*   Updated: 2023/01/24 02:00:46 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		cpy_splits_into_map_line(char **splits, t_map *map, int height);
static void		parse_map(int fd, t_map *map);
static void		file_to_str_list(int fd, t_list *list);
static int		lst_to_map(t_list *list, t_map *map);

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
	map->scale = 1;
	map->height_factor = -7;
	return ((map->map) != 0);
}

static void	parse_map(int fd, t_map *map)
{
	int		columns;
	t_list	list;

	list.content = 0;
	list.next = 0;
	file_to_str_list(fd, &list);
	map->line = ft_lstsize(&list);
	columns = how_many_splits((char *)list.content, ' ', NULL);
	if (!malloc_map(map, columns))
		return (ft_lstclear(&list.next, free), free(list.content));
	if (!lst_to_map(&list, map))
		freemap(map);
	ft_lstclear(&list.next, free);
	free(list.content);
}

static int	lst_to_map(t_list *list, t_map *map)
{
	int		height;
	char	**splits_by_spaces;
	t_list	*next;

	height = 0;
	next = list;
	while (height < map->line)
	{
		splits_by_spaces = ft_split((char *)next->content, ' ');
		if (!splits_by_spaces)
			return (0);
		if (map->column != ft_tablen((void **)splits_by_spaces))
		{
			ft_printf("line : %d, number of columns : %d\n", map->line - 1, map->column);
			ft_printf("line : %d, number of columns : %d\n", map->line, ft_tablen((void **)splits_by_spaces));
			return (ft_freetab((void **)splits_by_spaces, \
			ft_tablen((void **)splits_by_spaces) - 1), 0);
		}
		cpy_splits_into_map_line(splits_by_spaces, map, height);
		ft_freetab((void **)splits_by_spaces, map->column - 1);
		height++;
		next = next->next;
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
		if (coma && BONUS)
			map->map[height][i].color = ft_hextoi(coma + 3);
		else
			map->map[height][i].color = 0xFFFFFF;
		i ++;
	}
}

static void	file_to_str_list(int fd, t_list *list)
{
	char	*next_line;

	next_line = get_next_line(fd);
	list->content = next_line;
	next_line = get_next_line(fd);
	while (next_line)
	{
		ft_lstadd_back(&list, ft_lstnew((void *)next_line));
		next_line = get_next_line(fd);
	}
}
