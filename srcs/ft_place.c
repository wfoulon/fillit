/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:09:29 by clonger           #+#    #+#             */
/*   Updated: 2017/11/17 12:09:29 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_placeable(char *tetriminos, char *solution, char alph, int i)
{
	int		result;
	int		start;
	size_t	x;
	int count;

	result = 1;
	x = 0;
	start = 0;
	count = 0;
	while (tetriminos[x] && result != 0)
	{
		if (tetriminos[x] == alph)
		{
			if (solution[i] != alph && solution[i] != '.')
				result = 0;
			if (solution[i] == '\n' || solution[i] == '\0')
				result = 0;
			start = 1;
			count++;
		}
		if (start == 1 && count != 4)
			i++;
		x++;
	}
	return (result);
}

char	ft_find_alph(char *tetriminos)
{
	int		x;

	x = 0;
	while (!ft_isalpha(tetriminos[x]))
		x++;
	return (tetriminos[x]);
}

void	ft_put_tetris(char **tetriminos, char *solution, int y, int i)
{
	int		x;
	int		go;
	char	alph;

	x = 0;
	go = 0;
	alph = ft_find_alph(tetriminos[y]);
	if (!ft_is_placeable(tetriminos[y], solution, alph, i))
		error();
	else
		printf("\nIs placeable\n");
	while (tetriminos[y][x])
	{
		if (tetriminos[y][x] == alph)
		{
			solution[i] = alph;
			go = 1;
		}
		if (go == 1)
			i++;
		x++;
	}
}
