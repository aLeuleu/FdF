/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:09:20 by alevra          #+#    #+#             */
/*   Updated: 2023/01/21 17:12:31 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_win	win;

	if (BONUS)
		ft_printf("Bonus features enabled\n");
	if (argc != 2 || !get_map(argv[1], &win))
		return (-1);
	win_init(WIN_HEIGHT, WIN_WIDTH, "fdf", &win);
	draw_map(&win);
	mlx_put_image_to_window(win.mlx, win.win, win.img.img, 0, 0);
	mlx_hook(win.win, CLOSE_WINDOW_EVENT, 0, close_window, &win);
	mlx_hook(win.win, 2, 0, key_hook, &win);
	mlx_loop(win.mlx);
	return (0);
}
