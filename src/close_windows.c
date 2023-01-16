/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:34:07 by alevra            #+#    #+#             */
/*   Updated: 2023/01/16 17:34:44 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int    close_window(t_win *win)
{
    mlx_destroy_window(win->mlx, win->win);
    free(win);
    exit(0);
    return (0);
}