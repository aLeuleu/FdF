/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:15:40 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/12 15:30:21 by alevra           ###   ########lyon.fr   */
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





t_map			*get_map(char *map_file);
void			print_map(t_map *map); //debug
void			draw_center(t_win *win);
#endif
