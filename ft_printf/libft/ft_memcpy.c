/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:27:09 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 17:24:42 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	i = 0;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst_ptr == NULL && src_ptr == NULL)
		return (NULL);
	while (i++ < n)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
