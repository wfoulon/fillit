#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clonger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:02:45 by clonger           #+#    #+#              #
#    Updated: 2017/11/07 18:02:46 by clonger          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit
SRC			=	srcs/fillit.c \
				srcs/check_tetriminos.c
OBJ			=	$(SRC:.c=.o)
INCLUDES	=	-I libft -I includes
LIBS		=	-L libft/ -lft
FLAGS		=	-Wall -Werror -Wextra

all : $(NAME)

$(NAME):	$(OBJ)
	@make -C libft/ re
	@gcc -o $(NAME) $(OBJ) $(LIBS)
	@echo "\033[32;1mfillit is ready\033[0m"

$(OBJ):	%.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "\033[37mall files.o are removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[31m.a is deleted\033[0m"

re: fclean all