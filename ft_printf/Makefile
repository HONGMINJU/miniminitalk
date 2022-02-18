# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhong <mhong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 16:51:52 by mhong             #+#    #+#              #
#    Updated: 2022/02/07 16:51:59 by mhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGES		= -Wall -Werror -Wextra

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_NAME	= libft.a

SRCS		= ft_printf.c ft_print_util.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
		gcc $(CFLAGES) -c $< -o $@ -I ./

$(NAME): $(OBJS)
		make all -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_NAME) $(NAME)
		ar rc $@ $^
	
clean:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re: fclean all
