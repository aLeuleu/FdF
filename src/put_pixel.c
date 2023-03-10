/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:22:38 by alevra            #+#    #+#             */
/*   Updated: 2023/01/24 00:15:05 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_p p, t_win *win, t_data *data, int color)
{
	char	*dst;

	if (p.x >= 0 && p.y >= 0 && p.x < win->width && p.y < win->height)
	{
		dst = data->addr + \
		(p.y * data->line_length + p.x * data->bits_per_pixel);
		*(unsigned int *)dst = color;
	}
}
