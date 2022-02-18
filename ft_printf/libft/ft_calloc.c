/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:55:00 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 17:18:08 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size * count);
	if (!new_ptr)
		return (0);
	ft_memset(new_ptr, 0, size * count);
	return (new_ptr);
}
