# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 13:55:23 by egaliber          #+#    #+#              #
#    Updated: 2022/03/14 14:00:56 by egaliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./*.c
OBJ = $(SRC:.c=.o)
HEADER = fillit.h
LIBFT = libft/
FLAGS -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
		make -C $(LIBFT)
		gcc $(FLAGS) -c $(SRC)
		gcc $(OBJ) libft/libft.a $(FLAGS) -o $(NAME)

clean:
			rm -f $(OBJ)
			make clean -C libft/

fclean: clean
			rm -f $(NAME)
			make fclean -C libft/
			
re: fclean all