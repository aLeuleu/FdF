/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:05:19 by alevra            #+#    #+#             */
/*   Updated: 2023/01/25 17:01:41 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*ptr;

	if (lst == NULL)
		return (0);
	size = 1;
	ptr = lst;
	while (ptr->next != NULL)
	{
		size ++;
		ptr = ptr->next;
	}
	return (size);
}
