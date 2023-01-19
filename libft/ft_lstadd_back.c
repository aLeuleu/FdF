/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:16:18 by alevra            #+#    #+#             */
/*   Updated: 2022/11/10 22:38:36 by alevra           ###   ########lyon.fr   */
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
		ptr->next = new;
	}
}
