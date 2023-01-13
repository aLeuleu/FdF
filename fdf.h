/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:15:40 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/13 17:21:15 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_p3d {
	int		x;
	int		y;
	int		z;
}				t_p3d;

typedef struct	s_map {
	t_p3d	**map;
	int		column;
	int		line;
}				t_map;

typedef struct	s_win {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}				t_win;

typedef struct	s_p {
	int		x;
	int		y;
}				t_p;

t_map		*get_map(char *map_file);
void		print_map(t_map *map); //debug
void		draw_center(t_win *win);
void	display_map(t_map *map, t_win *win,t_p offset);
t_p			iso_projection(t_p3d *p3d);
t_p3d		*next_tab_element(t_map *map, int column, int line);
void		draw_line(int x1, int x2, int y1, int y2, t_win *win);
void		draw_line2(t_p start, t_p end, t_win *win);
void		put_pixel(int x, int y, t_win *win);
void		draw_cross(t_p p, int l, t_win *win);
t_p			get_win_center(t_win	*win);
t_p			get_offset(t_p win_center, t_p map_iso_center);
t_p			add_points(t_p p1, t_p p2);

#endif
