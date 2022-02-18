/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:50:17 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 17:24:13 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
