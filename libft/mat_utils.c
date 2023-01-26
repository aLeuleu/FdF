/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:55:25 by alevra            #+#    #+#             */
/*   Updated: 2023/01/26 21:03:47 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

//multiply matrix[2][3] by vect[3]
t_vec	mult_mat(t_mat mat, t_vec vec)
{
	t_vec	res;
	res.la = (mat.ca.la * vec.la) + (mat.ca.lb * vec.lb) + (mat.ca.lc * vec.lc);
	res.lb = (mat.cb.la * vec.la) + (mat.cb.lb * vec.lb) + (mat.cb.lc * vec.lc);
	res.lc = (mat.cc.la * vec.la) + (mat.cc.lb * vec.lb) + (mat.cc.lc * vec.lc);
	return (res);
}

void	show_vect(t_vec vec)
{
	ft_printf("|%d|\n", vec.la);
	ft_printf("|%d|\n", vec.lb);
	ft_printf("|%d|\n", vec.lc);
}
