/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:14:37 by clonger           #+#    #+#             */
/*   Updated: 2017/11/20 15:39:53 by clonger          ###   ########.fr       */
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
		ft_putstr("usage :	./fillit <file_name>\n	one file_name needed to \
run fillit.\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	tetriminos = ft_read(fd);
	close(fd);
	if (!tetriminos)
		error();
	ft_parse(tetriminos);
	solution = ft_set_solution(tetriminos);
	ft_solve(tetriminos, solution);
	ft_putstr(solution);
	return (0);
}
