# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 01:33:55 by niludwig          #+#    #+#              #
#    Updated: 2017/03/12 05:06:35 by niludwig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = niludwig.filler
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = main.c get_piece.c get_map.c creat_map.c useless.c
OBJ = $(SRC:.c=.o)
LIBFT_PATH = ./print/libft/
PRINTF_PATH = ./print/
PRINTF = ./print/libftprintf.a
LIBFT = ./print/libft/libft.a
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(PRINTF_PATH)
	@$(MAKE) -C $(LIBFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -L. $(LIBFT) $(PRINTF)

%.o: %.c
	@$(CC) $(CFLAG) -o $@ -c $<

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all
