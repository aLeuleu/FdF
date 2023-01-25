/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:15:40 by alevra            #+#    #+#             */
/*   Updated: 2023/01/25 23:54:56 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef BONUS_FLAG
#  define BONUS 0
# else
#  define BONUS 1
# endif
# ifndef WIN_WIDTH
#  define WIN_WIDTH 2560
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1500
# endif
# define KEY_Z 6
# define KEY_X 7
# define KEY_ESC 53
# define KEY_PLUS 69
# define KEY_MINUS 78
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
	float	scale;
	float	height_factor;
}				t_map;

typedef struct s_win {
	t_data	img;
	void	*mlx;
	void	*win;
	t_map	map;
	int		width;
	int		height;
}				t_win;

typedef struct s_p {
	int		x;
	int		y;
	int		color;
}				t_p;

t_p			add_points(t_p p1, t_p p2);
int			close_window(t_win *win);
void		compute_map_coords(t_map *map, int spacing, float height_factor);
void		blackscreen(t_win *win);
void		draw_line(t_p a, t_p b, t_win *win);
void		draw_map(t_win *win);
int			get_map(const char *map_file, t_win *win);
t_p			iso_projection(t_p3d *p3d);
t_p3d		*next_map_element(t_map *map, int column, int line);
void		put_pixel(t_p p, t_win *win, t_data *data, int color);
t_p			get_win_center(t_win *win);
t_p			get_offset(t_p win_center, t_p map_iso_center);
void		freemap(t_map *map);
t_p3d		get_map_center(t_map *map);
void		win_init(int height, int width, char *window_title, t_win *win);
int			malloc_map(t_map *map, int line, int width);
int			key_hook(int keycode, t_win *win);

#endif