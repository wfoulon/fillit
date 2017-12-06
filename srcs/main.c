/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:59:27 by clonger           #+#    #+#             */
/*   Updated: 2017/11/27 11:02:43 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**tetri;
	char	*feelit;

	if (argc != 2)
	{
		ft_putstr("usage :	./fillit <file_name>\n	one file_name needed to \
run fillit.\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error();
	if ((tetri = ft_read_file(fd)) == NULL)
		ft_error();
	ft_mapping(tetri);
	if ((feelit = ft_solver(tetri)) == NULL)
		ft_error();
	ft_putstr(feelit);
	close(fd);
	free(tetri);
	free(feelit);
	return (0);
}
