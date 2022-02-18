/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:39:55 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 17:22:03 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	if (lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		head = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = head;
	}
	*lst = 0;
}
