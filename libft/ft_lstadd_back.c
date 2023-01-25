/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:16:18 by alevra            #+#    #+#             */
/*   Updated: 2023/01/25 15:55:08 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*ptr;

	if (!list || !new)
		return ;
	ptr = ft_lstlast(*list);
	if (list && !(*list))
		*list = new;
	else
	{
		if (!ptr)
			ptr = ft_lstnew(NULL);
		if (!ptr)
			return ;
		ptr->next = new;
	}
}
