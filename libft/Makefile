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

NAME		=	libft.a
HEADER		=	.libft.h
SRC			=	ft_memset.c \
				ft_bzero.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_memccpy.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_putstr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_putchar_fd.c \
				ft_putchar.c \
				ft_putstr_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putnbr.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_isspace.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_print_params_fd.c \
				ft_sort_params_fd.c \
				ft_pow.c \
				ft_find_prime.c
OBJ			= 	$(SRC:.c=.o)

all : $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32;1mlibft is ready\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[37mall files.o are removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) is deleted\033[0m"

re: fclean all