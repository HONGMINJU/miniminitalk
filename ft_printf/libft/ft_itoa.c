/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:46:52 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 17:21:45 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	temp;
	char	*res;

	temp = n;
	len = get_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = 0;
	if (temp < 0)
	{
		res[0] = '-';
		temp = -temp;
	}
	if (temp == 0)
		res[0] = '0';
	while (temp)
	{
		res[len] = (temp % 10) + '0';
		temp /= 10;
		len--;
	}
	return (res);
}
