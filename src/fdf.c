/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:09:20 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/09 13:52:07 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_data	img;

	if (argc != 2)
		return (0);
	
	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 400, 400);
	win = mlx_new_window(mlx, 400, 400, "Carré noir");
	mlx_loop(mlx);
	return (0);
}