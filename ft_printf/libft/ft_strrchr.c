/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:03:50 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 17:34:22 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			find_char;
	int				i;
	unsigned char	*str_ptr;

	find_char = (char)c;
	i = ft_strlen(s);
	str_ptr = (unsigned char *)s;
	while (i > 0)
	{
		if (str_ptr[i] == find_char)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == find_char)
		return ((char *)s);
	return (0);
}
