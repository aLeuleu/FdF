/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:15:40 by alevra            #+#    #+#             */
/*   Updated: 2023/01/27 00:37:11 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //debug
#ifndef FDF_H
# define FDF_H
# ifndef BONUS_FLAG
#  define BONUS 0
# else
#  define BONUS 1
# endif
# ifndef WIN_WIDTH
#  define WIN_WIDTH 1280
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 750
# endif
# ifndef MATH_MACRO
#  define SQRT2_DIV_2 0.7071
#  define ONE_DIV_SQRT6 0.4082
#  define SQRT_2DIV3 0.8164
# endif
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_ESC 53
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_NUMPAD_SEVEN 89
# define KEY_NUMPAD_EIGHT 91
# define KEY_NUMPAD_FOUR 86
# define KEY_NUMPAD_FIVE 87
# define KEY_NUMPAD_ONE 83
# define KEY_NUMPAD_TWO 84
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

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

typedef struct s_map {
	t_p3d	**map;
	int		column;
	int		line;
	float	scale;
	float	height_factor;
	t_p		translation;
	t_p		offset_center;
	double	alpha;
	double	beta;
	double	gamma;
	int		need_to_compute;
}				t_map;

typedef struct s_win {
	t_data	img;
	void	*mlx;
	void	*win;
	t_map	map;
	int		width;
	int		height;
}				t_win;

t_p			add_points(t_p p1, t_p p2);
int			close_window(t_win *win);
void		compute_map_coords(t_map *map, int spacing, float height_factor);
void		blackscreen(t_win *win);
void		draw_line(t_p a, t_p b, t_win *win);
void		draw_map(t_win *win);
int			get_map(const char *map_file, t_win *win);
void		iso_projection(t_p3d *p3d, t_map *map, t_p offset_center, t_p *res);
t_p3d		*next_map_element(t_map *map, int column, int line);
void		put_pixel(t_p p, t_win *win, t_data *data, int color);
t_p			get_win_center(t_win *win);
t_p			get_offset(t_p win_center, t_p map_iso_center);
void		freemap(t_map *map);
t_p3d		get_map_center(t_map *map);
void		win_init(int height, int width, char *window_title, t_win *win);
int			malloc_map(t_map *map, int line, int width);
int			key_hook(int keycode, t_win *win);
void		draw_cross(t_p p, int l, t_win *win); //debug


#endif