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

void	error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*solution;
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
	display(tetriminos);
	ft_putstr("\n\nOh yeah biatch !!!!\n\n");
	ft_parse(tetriminos);
	display(tetriminos);
	if (!(solution = (char *)malloc(sizeof(solution) * ft_strlen(tetriminos[0]))))
		return (0);
	ft_set_solution(solution, tetriminos, 0);
	ft_put_tetris(tetriminos, solution, 0, 0);
	ft_put_tetris(tetriminos, solution, 1, 1);
	ft_putstr("\nThat is the solution baby !!!!\n\n");
	ft_putstr(solution);
	ft_putstr("\nAnd now the solution has been parsed !!!!\n\n");
	return (0);
}