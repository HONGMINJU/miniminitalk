/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 01:23:40 by minju             #+#    #+#             */
/*   Updated: 2022/02/06 17:33:40 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	cnt;

	cnt = 0;
	if (!dst || !src)
		return (0);
	if (size)
	{
		while (--size && src[cnt])
		{
			dst[cnt] = src[cnt];
			cnt++;
		}
		dst[cnt] = '\0';
	}
	while (src[cnt])
		cnt++;
	return (cnt);
}
