# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clonger <clonger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 11:09:30 by clonger           #+#    #+#              #
#    Updated: 2017/11/20 12:54:58 by clonger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit
SRC			=	srcs/main.c \
				srcs/check_tetriminos.c \
				srcs/ft_free_parse.c \
				srcs/ft_place.c \
				srcs/tools.c \
				srcs/solver.c
OBJ			=	$(SRC:.c=.o)
INCLUDES	=	-I libft -I includes
LIBS		=	-L libft/ -lft
FLAGS		=	-Wall -Werror -Wextra

all : $(NAME)

$(NAME):	$(OBJ)
	@make -C libft/ re
	@gcc -o $(NAME) $(OBJ) $(LIBS)
	@echo "\t\t\033[32;1;3;4mfillit is ready\033[0m"
	@echo "\t\033[36;1;4;3;44mLet's go baby !\033[0m"

$(OBJ):	%.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "\033[35;4;3mall files.o are removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\t\t\033[31;1;3;4mfillit and libft.a is deleted\033[0m"

re: fclean all