/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:13:24 by alevra            #+#    #+#             */
/*   Updated: 2023/01/13 17:42:26 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p	get_offset(t_p win_center, t_p map_iso_center)
{
	t_p	offset;

	ft_printf("\nwin_center(win).x : %d\n", win_center.x); //debug
	ft_printf("map_iso_center.x : %d\n", map_iso_center.x); //debug
	offset.x = win_center.x - map_iso_center.x;
	ft_printf("offset.x : %d\n", offset.x); //debug
	offset.y = win_center.y - map_iso_center.y;
	// offset.x = map_iso_center.x - win_center.x;
	// offset.x = map_iso_center.y - win_center.y;
	return (offset);
}
