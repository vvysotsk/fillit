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

NAME = fillit

FLAGS = -Wall -Wextra -Werror -I.

SRC = check.c \
coordinates.c \
map.c \
read.c \
solver.c 

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(FLAGS) -o $(NAME) main.c $(OBJ)

%.o: %.c
	@gcc $(FLAGS) -c $<

clean:
	@rm -rf $(OBJ) main.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
