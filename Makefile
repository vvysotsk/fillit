#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/02 16:43:15 by vvysotsk          #+#    #+#              #
#    Updated: 2018/02/02 16:43:21 by vvysotsk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all, clean, fclean, re

NAME = fillit

FLAGS = -Wall -Wextra -Werror -I.

SRC = check.c \
coordinates.c \
map.c \
read.c \
solver.c \

LIBFT = includes/libft.a 

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(FLAGS) -o $(NAME) main.c $(OBJ) $(LIBFT)

$(LIBFT):
	make -C ./includes

%.o: %.c
	@gcc $(FLAGS) -c $<

clean:
	@rm -rf $(OBJ) main.o
	@make clean -C ./includes

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./includes

re: fclean all
