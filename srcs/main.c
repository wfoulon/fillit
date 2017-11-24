/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:14:37 by clonger           #+#    #+#             */
/*   Updated: 2017/11/24 14:38:17 by clonger          ###   ########.fr       */
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
	if (((fd = open(argv[1], O_RDONLY)) <= 0))
		error();
	tetriminos = ft_read(fd, 0);
	close(fd);
	if (!tetriminos)
		error();
	ft_parse(tetriminos);
	if (!(solution = ft_solve(tetriminos)))
		error();
	ft_putstr(solution);
	free(solution);
	ft_free(tetriminos);
	return (0);
}
