/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:04:33 by alevra            #+#    #+#             */
/*   Updated: 2023/01/25 18:47:38 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//example : log_condition( (a == b) , "a==b", __FUNCTION__, __LINE__);
void	log_condition(int condition_to_check, char *condition_msg, \
const char *function, int line)
{
	ft_printf("[🔎]%s()-l%d : %s : ", function, line, condition_msg);
	if (condition_to_check)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}
