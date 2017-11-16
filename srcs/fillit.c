/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:14:37 by clonger           #+#    #+#             */
/*   Updated: 2017/11/15 11:14:37 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
void	display(int **tetriminos)
{
	int i;

	if (tetriminos && tetriminos != 0)
	{
		int i = 0;
		while (tetriminos && tetriminos[i])
		{
			ft_putstr(tetriminos[i]);
			i++;
			ft_putchar('\n');
		}
		tetriminos++;
	}
}*/

int		isValid(char *buf)
{
	printf("buf: \n%s\n", buf);
	printf("ft_check_char: %lu\n", ft_check_char(buf));
	printf("ft_check_size: %lu\n", ft_check_size(buf));
	printf("ft_nb_tetriminos: %lu\n", ft_nb_tetriminos(buf));
	printf("ft_enough_char: %lu\n", ft_enough_char(buf));
	printf("ft_valid_form: %lu\n", ft_valid_form(buf, 0));
	printf("ft_count: %lu\n", ft_count(buf, ft_valid_form));
	// printf("ft_count%d\n", ft_count(buf, ft_valid_form));
	// if (ft_check_char(buf) || ft_check_size(buf))
	// 	error();
	// if (ft_nb_tetriminos(buf) >= 27 || ft_enough_char(buf))
	// 	error();
	// if (ft_nb_tetriminos(buf) != ft_count(buf, ft_valid_form))
		error();
	return (1);
}

char	**ft_read(int fd)
{
	char	**tetriminos;
	char	buf[547];

	if (!(tetriminos = (char **)malloc(sizeof(char *) * 27)))
		return (NULL);
	if ((read(fd, buf, 546)) <= 0)
		return (NULL);
	if (!(isValid(buf)))
		error();




	return (tetriminos);
}

void	error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	int		fd;
	// char	*str;
	char	**tetriminos;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit <file name>");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	tetriminos = ft_read(fd);
	close(fd);
	if (!tetriminos)
		error();
	// ft_display(tetriminos);
	return (0);
}