/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 00:47:03 by minju             #+#    #+#             */
/*   Updated: 2022/02/06 17:24:37 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_ptr;
	unsigned char	find;

	find = c;
	s_ptr = (unsigned char *)s;
	while (n--)
	{
		if (*s_ptr == find)
			return (s_ptr);
		s_ptr++;
	}
	return (0);
}
