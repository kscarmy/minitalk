# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guderram <guderram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 07:36:00 by guderram          #+#    #+#              #
#    Updated: 2021/10/13 07:36:01 by guderram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_minitalk.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_C = srcs/server.c\
			srcs/client.c\
			srcs/ft_utils.c\


OBJS =  server.o\
			client.o\
			ft_utils.o\

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(SRC_C) -c
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(CC) $(CFLAGS) srcs/server.c $(NAME) -o server
	@$(CC) $(CFLAGS) srcs/client.c $(NAME) -o client

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf server
	@rm -rf client
	@rm -rf $(NAME)

re : fclean all
	@rm -rf $(OBJS)
