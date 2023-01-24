/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:34:07 by alevra            #+#    #+#             */
/*   Updated: 2023/01/24 17:36:44 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_if_exist(void *ptr);

void	close_window(t_win *win)
{
	if (win->img.img)
		mlx_destroy_image(win->mlx, win->img.img);
	if (win->mlx)
		mlx_destroy_window(win->mlx, win->win);
	freemap(win->map);
	free_if_exist(win);
	exit(0);
}

static void	free_if_exist(void *ptr)
{
	if (ptr)
		free(ptr);
	else
		ft_printf("(close window)WARNING : tried to freed a null ptr\n");
}
