/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:56:57 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 17:23:35 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (!l || !f)
		return (NULL);
	new_list = ft_lstnew((*f)(l->content));
	if (!new_list)
		return (NULL);
	tmp = new_list;
	l = l->next;
	while (l)
	{
		tmp->next = ft_lstnew((*f)(l->content));
		if (!tmp->next)
		{
			ft_lstclear(&new_list, d);
			return (NULL);
		}
		tmp = tmp->next;
		l = l->next;
	}
	return (new_list);
}
