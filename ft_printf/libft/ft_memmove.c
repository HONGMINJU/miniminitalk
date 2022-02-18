/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 00:15:14 by minju             #+#    #+#             */
/*   Updated: 2022/02/06 17:24:45 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	dst_ptr = dst;
	src_ptr = (unsigned char *)src;
	if (dst < src)
	{
		while (i++ < n)
			*dst_ptr++ = *src_ptr++;
	}
	else
	{
		while (i < n)
		{
			dst_ptr[n - i - 1] = src_ptr[n - i - 1];
			i++;
		}
	}
	return (dst);
}
