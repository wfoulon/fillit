/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:38:56 by clonger           #+#    #+#             */
/*   Updated: 2017/11/18 13:38:56 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display(char **tetriminos)
{
	int i;

	i = 0;
	if (tetriminos && tetriminos != 0)
	{
		while (tetriminos && tetriminos[i])
		{
			ft_putstr(tetriminos[i]);
			i++;
		}
	}
}

size_t		ft_count(char *str, size_t (f)(char *, size_t i))
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (f(str, i) == 0)
			count++;
		while (str[i] != '\n' || (str[i + 1] != '\n' && str[i + 1] != '\0'))
			i++;
		i += 2;
	}
	return (count);
}

void	ft_set_solution(char *solution, char **tetriminos, int y)
{
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (tetriminos[y][x])
	{
		if (tetriminos[y][x] != '\n')
		{
			solution[i] = '.';
			i++;
			x++;
		}
		else
		{
			solution[i] = tetriminos[y][x];
			i++;
			x++;
		}
	}
}

int		isValid(char *buf)
{	/*
	printf("buf: \n%s\n", buf);
	printf("ft_check_char: %lu\n", ft_check_char(buf));
	printf("ft_check_size: %lu\n", ft_check_size(buf));
	printf("ft_nb_tetriminos: %lu\n", ft_nb_tetriminos(buf));
	printf("ft_enough_char: %lu\n", ft_enough_char(buf));
	printf("ft_valid_form: %lu\n", ft_valid_form(buf, 0));
	printf("ft_count: %lu\n", ft_count(buf, ft_valid_form));*/
	if (ft_check_char(buf) || ft_check_size(buf))
		error();
	if (ft_nb_tetriminos(buf) >= 27 || ft_enough_char(buf))
		error();
	if (ft_nb_tetriminos(buf) != ft_count(buf, ft_valid_form))
		error();
	return (1);
}

char	**ft_read(int fd)
{
	char	**tetriminos;
	char	buf[547];
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((read(fd, buf, 546)) <= 0)
		return (NULL);
	if (!(isValid(buf)))
		error();
	// printf("It's all good\n");
	if (!(tetriminos = (char **)malloc(sizeof(char *) * 27)))
		return (NULL);
	while (buf[i])
	{
		if (ft_strlen(buf) >= 20)
			tetriminos[j] = ft_strsub(buf, 21 * j, 21);
		else
			return (NULL);
		i += ft_strlen(tetriminos[j]);
		tetriminos[j][ft_strlen(tetriminos[j])] = '\0';
		j++;
	}
	tetriminos[j] = NULL;
	return (tetriminos);
}
