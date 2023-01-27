/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:18:55 by alevra            #+#    #+#             */
/*   Updated: 2023/01/27 01:04:58 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p	add_points(t_p p1, t_p p2)
{
	t_p	res;

	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	res.color = p1.color;
	return (res);
}
