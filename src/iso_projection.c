/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:08:56 by alevra            #+#    #+#             */
/*   Updated: 2023/01/24 18:09:06 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p	iso_projection(t_p3d *p3d)
{
	t_p	res;

	res.x = 0;
	res.y = 0;
	if (!p3d)
		return (res);
	res.x = 0.7071 * (p3d->x - p3d->y);
	res.y = 0.8164 * p3d->z - ((-0.4082) * (p3d->x + p3d->y));
	res.color = p3d->color;
	return (res);
}
