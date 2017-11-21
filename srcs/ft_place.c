/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:09:29 by clonger           #+#    #+#             */
/*   Updated: 2017/11/21 14:34:50 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_where(char *tetriminos, int x, char *solution, int i)
{
	int		j;
	int		length;

	j = 0;
	length = 0;
	while (solution[length] != '\n')
		length++;
	length++;
	if (x >= 0 && x < 20 && i >= 0 && i < (length * (length - 1)))
	{
		if (ft_islower(tetriminos[x]) && solution[i] == '.')
		{
			tetriminos[x] -= 32;
			solution[i] = tetriminos[x];
			j++;
			j += ft_where(tetriminos, x + 1, solution, i + 1);
			j += ft_where(tetriminos, x + 5, solution, i + length);
			j += ft_where(tetriminos, x - 1, solution, i - 1);
		}
	}
	return (j);
}

int			ft_put_tetris(char **tetriminos, char *solution, int y, int i)
{
	int		j;
	char	alph;
	int		x;

	x = 0;
	j = 0;
	alph = 'A' + y;
	while (!ft_isalpha(tetriminos[y][x]))
		x++;
	if (ft_where(tetriminos[y], x, solution, i) == 4)
		return (1);
	reset_tetriminos(tetriminos[y]);
	while (solution[j])
	{
		if (solution[j] == alph)
			solution[j] = '.';
		j++;
	}
	return (0);
}
