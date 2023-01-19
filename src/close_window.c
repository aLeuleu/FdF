/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:34:07 by alevra            #+#    #+#             */
/*   Updated: 2023/01/19 15:50:53 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_if_exist(void *ptr);

int	close_window(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img.img);
	mlx_destroy_window(win->mlx, win->win);
	free_if_exist(win);
	exit(0);
	return (0);
}

static void	free_if_exist(void *ptr)
{
	if (ptr)
		free(ptr);
	else
		ft_printf("(close window)WARNING : tried to freed a null ptr\n");
}
