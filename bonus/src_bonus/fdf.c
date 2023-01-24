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

static void	draw_bg(t_win *win, int color);

static int	key_hook(int keycode, t_win *win)
{
	if (keycode == KEY_ESC)
		close_window(win);
	if (!BONUS)
		return (0);
	if (keycode == KEY_PLUS && win->map->scale < 5)
		win->map->scale *= 1.2;
	if (keycode == KEY_MINUS && win->map->scale > 0.4)
		win->map->scale *= 0.8;
	if (keycode == KEY_Z)
		win->map->height_factor = 1.2;
	if (keycode == KEY_X)
		win->map->height_factor = 0.8;;
	draw_bg(win, 0);
	display_map(win->map, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	win->map->height_factor = 1;
	win->map->height_factor = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	*win;
	t_map	map;

	if (BONUS)
		ft_printf("Bonus features enabled\n");
	if (argc != 2)
		return (-1);
	if (!get_map(argv[1], &map))
		return (-1);
	win = win_init(WIN_HEIGHT, WIN_WIDTH, "fdf");
	if (!win)
		return (freemap(&map), -1);
	win->map = &map;
	map.height_factor = -1;
	display_map(&map, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	mlx_hook(win->win, CLOSE_WINDOW_EVENT, 0, close_window, win);
	mlx_key_hook(win->win, key_hook, win);
	mlx_loop(win->mlx);
	close_window(win);
	return (0);
}

static void	draw_bg(t_win *win, int color)
{
	int	i;
	int	j;
	t_p	a;
	t_p	b;

	i = 0;
	a.x = 0;
	a.y = 0;
	a.color = color;
	b.color = color;
	b.x = win->width - 1;
	b.y = 0;
	j = 0;
	while (j < win->height)
	{
		draw_line(a, b, win);
		a.y = j;
		b.y = j;
		j++;
	}
}
