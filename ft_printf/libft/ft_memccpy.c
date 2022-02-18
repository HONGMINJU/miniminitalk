/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 00:06:31 by minju             #+#    #+#             */
/*   Updated: 2022/02/06 17:24:28 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	unsigned char	find;

	i = 0;
	find = c;
	dst_ptr = dst;
	src_ptr = (unsigned char *)src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		if (src_ptr[i] == find)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
