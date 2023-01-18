/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:22:38 by alevra            #+#    #+#             */
/*   Updated: 2023/01/18 18:54:57 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_p p, t_win *win, t_data *data, int color)
{
	if (p.x < win->width && p.y < win->height)
		my_mlx_pixel_put(data, p.x, p.y, color);
}
