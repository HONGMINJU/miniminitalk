/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:31:52 by mhong             #+#    #+#             */
/*   Updated: 2022/02/07 17:06:34 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	print_p(long long ptr);
int	print_di(int num);
int	print_u(unsigned int num);
int	print_xX(unsigned long long num, int isUpper);
int	print_s(char *str);

#endif
