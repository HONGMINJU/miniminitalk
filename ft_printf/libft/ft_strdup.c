/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:04:16 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 17:32:17 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_ptr;
	char	*str_ptr;
	int		str_len;
	int		i;

	i = 0;
	str_len = ft_strlen(s1);
	str_ptr = (char *)s1;
	new_ptr = malloc(str_len + 1);
	if (!new_ptr)
		return (0);
	while (i < str_len)
	{
		new_ptr[i] = s1[i];
		i++;
	}
	new_ptr[i] = 0;
	return (new_ptr);
}
