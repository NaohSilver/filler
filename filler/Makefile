# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 01:33:55 by niludwig          #+#    #+#              #
#    Updated: 2017/03/10 17:04:38 by niludwig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = niludwig.filler

SRC = main.c get_map_piece.c creat_map.c

OBJ = main.o get_map_piece.c creat_map.o

LIB = print/libft/libft.a

LIBFTPRINTF = print/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(OBJ) $(LIB) $(LIBFTPRINTF)

all: $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
