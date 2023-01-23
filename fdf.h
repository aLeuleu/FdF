/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:15:40 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/21 16:42:01 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef WIN_WIDTH
#  define WIN_WIDTH 1600
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 900
# endif
# ifndef ESC_KEY
#  define ESC_KEY 53
# endif
# ifndef CLOSE_WINDOW_EVENT
#  define CLOSE_WINDOW_EVENT 17
# endif
# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <errno.h>
# include <string.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_p3d {
	int		x;
	int		y;
	int		z;
	int		color;
}				t_p3d;

typedef struct s_map {
	t_p3d	**map;
	int		column;
	int		line;
}				t_map;

typedef struct s_win {
	t_data	img;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}				t_win;

typedef struct s_p {
	int		x;
	int		y;
	int		color;
}				t_p;

int			get_map(const char *map_file, t_map *map);
void		display_map(t_map *map, t_win *win);
t_p			iso_projection(t_p3d *p3d);
t_p3d		*next_tab_element(t_map *map, int column, int line);
void		draw_line(t_p a, t_p b, t_win *win);
void		put_pixel(t_p p, t_win *win, t_data *data, int color);
t_p			get_win_center(t_win *win);
t_p			get_offset(t_p win_center, t_p map_iso_center);
t_p			add_points(t_p p1, t_p p2);
int			close_window(t_win *win);
void		freemap(t_map *map);
t_p3d		get_map_center(t_map *map);
void		compute_map_coords(t_map *map, int spacing);
t_win		*win_init(int height, int width, char *window_title);
int			malloc_map(t_map *map, int width);

#endif