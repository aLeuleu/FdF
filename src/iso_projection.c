/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:08:56 by alevra            #+#    #+#             */
/*   Updated: 2023/01/26 22:02:06 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec	p3d_to_vect(t_p3d *p);

t_p	iso_projection(t_p3d *p3d, double α, double ß, double  Γ)
{
	t_p		res;
	t_vec	v_p;
	t_vec	v_res;
	t_mat	mat_iso;
	t_mat	mat_rotx;
	t_mat	mat_roty;
	t_mat	mat_rotz;


	res.x = 0;
	res.y = 0;
	if (!p3d)
		return (res);
	mat_rotx = (t_mat){\
		(t_vec){1, 0, 0}, \
		(t_vec){0, cos(α), -sin(α)}, \
		(t_vec){0, sin(α), cos(α)} \
					};
	mat_roty = (t_mat){\
		(t_vec){cos(ß), 0, sin(ß)}, \
		(t_vec){0, 1, 0}, \
		(t_vec){-sin(ß), 0, cos(ß)} \
					};
	mat_rotz = (t_mat){\
		(t_vec){cos(Γ), -sin(Γ), 0}, \
		(t_vec){sin(Γ), cos(Γ), 0}, \
		(t_vec){0, 0, 1} \
					};
	mat_iso = (t_mat){\
		(t_vec){SQRT2_DIV_2, -SQRT2_DIV_2, 0}, \
		(t_vec){ONE_DIV_SQRT6, ONE_DIV_SQRT6, SQRT_2DIV3}, \
		(t_vec){0, 0, 0} \
					};
	v_p = p3d_to_vect(p3d);
	v_p = mult_mat(mat_rotx, v_p);
	v_p = mult_mat(mat_roty, v_p);
	v_p = mult_mat(mat_rotz, v_p);
	v_res = mult_mat(mat_iso, v_p);
	res.x = v_res.la;
	res.y = v_res.lb;
	res.color = p3d->color;
	return (res);
}

static t_vec	p3d_to_vect(t_p3d *p)
{
	t_vec	res;

	res.la = (double)p->x;
	res.lb = (double)p->y;
	res.lc = (double)p->z;
	return (res);
}
