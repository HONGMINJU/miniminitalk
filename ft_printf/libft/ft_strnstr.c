/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:22:58 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 17:34:20 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!str2[0])
		return ((char *)str1);
	i = 0;
	while (str1[i])
	{
		j = 0;
		while (str1[i + j] == str2[j] && i + j < len)
		{
			if (!str2[j + 1])
				return ((char *)&str1[i]);
			j++;
		}
		i++;
	}
	return (0);
}
