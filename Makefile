# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhong  <mhong@student.42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 20:56:26 by mhong             #+#    #+#              #
#    Updated: 2022/02/18 20:56:26 by mhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLIENT = client
SERVER = server
FT_PRINTF_LIB = ./ft_printf/libftprintf.a

SRC_M_PATH = ./src/
# SRC_B_PATH = ./bonus/
INC_M_PATH = ./include/
INC_B_PATH = $(SRC_B_PATH)

SRC_M = client.c\
		server.c
# SRC_B = client_bonus.c\
# 		server_bonus.c

SRCS_M = $(addprefix $(SRC_M_PATH), $(SRC_M))
# SRCS_B = $(addprefix $(SRC_B_PATH), $(SRC_B))

OBJS_M = $(SRCS_M:.c=.o)
# OBJS_B = $(SRCS_B:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(CLIENT) $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# bonus:
# 	make HAS_BONUS=1 all

# ifdef HAS_BONUS
# $(CLIENT): ./bonus/client_bonus.o
# 	make -s -C ft_printf
# 	$(CC) $(CFLAGS) -o $@ $^ $(FT_PRINTF_LIB)

# $(SERVER): ./bonus/server_bonus.o
# 	$(CC) $(CFLAGS) -o $@ $^ $(FT_PRINTF_LIB)

else
$(CLIENT): ./src/client.o
	make -s -C ft_printf
	$(CC) $(CFLAGS) -o $@ $^ $(FT_PRINTF_LIB)

$(SERVER): ./src/server.o
	$(CC) $(CFLAGS) -o $@ $^ $(FT_PRINTF_LIB)
endif

clean:
	$(RM) $(OBJS_M) $(OBJS_B)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	make -s $@ -C ft_printf
	echo deleted all files

re: fclean all

.SILENT: $(OBJS)

.PHONY: all clean fclean re bonus $(SERVER) $(CLIENT)