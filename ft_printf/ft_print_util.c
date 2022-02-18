/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:50:02 by mhong             #+#    #+#             */
/*   Updated: 2022/02/07 17:06:31 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(long long ptr)
{
	int					cnt;
	unsigned long long	temp;

	temp = ptr;
	if (ptr < 0)
		temp = 0llu + ptr;
	ft_putstr_fd("0x", 1);
	cnt = 2;
	cnt += print_xX(temp, 0);
	return (cnt);
}

int	print_di(int nb)
{
	int		cnt;
	char	*temp;

	temp = ft_itoa(nb);
	cnt = print_s(temp);
	free(temp);
	return (cnt);
}

int	print_u(unsigned int num)
{
	int	cnt;

	cnt = 0;
	if (num >= 10)
		cnt += print_u(num / 10);
	cnt++;
	ft_putchar_fd("0123456789"[num % 10], 1);
	return (cnt);
}

int	print_xX(unsigned long long num, int isUpper)
{
	int	cnt;

	cnt = 0;
	if (num >= 16)
		cnt += print_xX(num / 16, isUpper);
	if (isUpper)
		ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
	else
		ft_putchar_fd("0123456789abcdef"[num % 16], 1);
	cnt++;
	return (cnt);
}

int	print_s(char *str)
{
	int	cnt;

	cnt = 0;
	if (str == 0)
		return (print_s("(null)"));
	while (*str != '\0')
	{
		ft_putchar_fd(*str, 1);
		cnt++;
		str++;
	}
	return (cnt);
}
