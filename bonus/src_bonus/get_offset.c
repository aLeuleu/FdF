/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:13:24 by alevra            #+#    #+#             */
/*   Updated: 2023/01/17 21:09:48 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p	get_offset(t_p win_center, t_p map_iso_center)
{
	t_p	offset;

	offset.x = win_center.x - map_iso_center.x;
	offset.y = win_center.y - map_iso_center.y;
	return (offset);
}
