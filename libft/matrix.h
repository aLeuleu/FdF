/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:51 by alevra            #+#    #+#             */
/*   Updated: 2023/01/30 11:54:06 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "libft.h"

typedef struct s_vector
{
	double	la;
	double	lb;
	double	lc;
}	t_vec;

typedef struct s_matrix
{
	t_vec	ca;
	t_vec	cb;
	t_vec	cc;
}	t_mat;

typedef struct s_p {
	int		x;
	int		y;
	int		color;
}				t_p;

typedef struct s_p3d {
	int		x;
	int		y;
	int		z;
	int		color;
}				t_p3d;

t_vec	mult_mat(t_mat mat, t_vec vec);
void	show_vect(t_vec vec);

#endif