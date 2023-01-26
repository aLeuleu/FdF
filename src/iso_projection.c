/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:08:56 by alevra            #+#    #+#             */
/*   Updated: 2023/01/27 00:35:35 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec	p3d_to_vect(t_p3d *p);

/* 
mat[0] : iso projection matrix
mat[1] : alpha rotation matrix
mat[2] : beta rotation matrix
mat[3] : gamma rotation matrix
 */
void	iso_projection(t_p3d *p3d, t_map *map, t_p offset_center, t_p *res)
{
	t_vec		v_p;
	t_vec		v_res;
	t_mat		mat[4];
	double		cos_sin[6];

	if (!p3d)
		return (ft_bzero((void *)res, sizeof(t_p)), (void)0);
	get_cos_sin(&cos_sin, map);
	mat[1] = (t_mat){\
		(t_vec){1, 0, 0}, \
		(t_vec){0, cos_sin[0], -cos_sin[1]}, \
		(t_vec){0, cos_sin[1], cos_sin[0]} \
					};
	mat[2] = (t_mat){\
		(t_vec){cos_sin[2], 0, cos_sin[3]}, \
		(t_vec){0, 1, 0}, \
		(t_vec){-cos_sin[3], 0, cos_sin[2]} \
					};
	mat[3] = (t_mat){\
		(t_vec){cos_sin[4], -cos_sin[5], 0}, \
		(t_vec){cos_sin[5], cos_sin[4], 0}, \
		(t_vec){0, 0, 1} \
					};
	mat[0] = (t_mat){\
		(t_vec){SQRT2_DIV_2, -SQRT2_DIV_2, 0}, \
		(t_vec){ONE_DIV_SQRT6, ONE_DIV_SQRT6, SQRT_2DIV3}, \
		(t_vec){0, 0, 0} \
					};
	v_p = p3d_to_vect(p3d);
	v_p = mult_mat(mat[1], v_p);
	v_p = mult_mat(mat[2], v_p);
	v_p = mult_mat(mat[3], v_p);
	v_res = mult_mat(mat[0], v_p);
	res->x = v_res.la;
	res->y = v_res.lb;
	res->x = v_res.la + offset_center.x;
	res->y = v_res.lb + offset_center.y;
	res->color = p3d->color;
	return ;
}

/* 
	[0] : cos(alpha)
	[1] : sin(alpha)
	[2] : cos(beta)
	[3] : sin(beta)
	[4] : cos(gamma)
	[5] : sin(gamma)
 */
static void	get_cos_sin(double *cos_sin[6], t_map *map)
{
	*cos_sin[0] = cos(map->alpha);
	*cos_sin[1] = sin(map->alpha);
	*cos_sin[2] = cos(map->beta);
	*cos_sin[3] = sin(map->beta);
	*cos_sin[4] = cos(map->gamma);
	*cos_sin[5] = sin(map->gamma);
}

static t_vec	p3d_to_vect(t_p3d *p)
{
	t_vec	res;

	res.la = (double)p->x;
	res.lb = (double)p->y;
	res.lc = (double)p->z;
	return (res);
}
