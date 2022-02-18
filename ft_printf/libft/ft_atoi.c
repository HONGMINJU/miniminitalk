/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:45:51 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 17:17:28 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	is_number(char c)
{
	return ('0' <= c && c <= '9');
}

int	is_min_int(const char *str)
{
	int		i;
	char	*min_int;

	i = 0;
	min_int = "-2147483648";
	while (str[i])
	{
		if (str[i] != min_int[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		number;
	int		is_minus;
	char	*str_ptr;

	number = 0;
	is_minus = 0;
	str_ptr = (char *)str;
	if (*str && is_min_int(str))
		return (-2147483648);
	while (*str_ptr && is_space(*str_ptr))
		str_ptr++;
	if (*str_ptr && (*str_ptr == '-' || *str_ptr == '+'))
	{
		if (*str_ptr == '-')
			is_minus = 1;
		str_ptr++;
	}
	while (*str_ptr && is_number(*str_ptr))
	{
		number = (number * 10) + (*str_ptr - '0');
		str_ptr++;
	}
	if (is_minus)
		number *= -1;
	return (number);
}
