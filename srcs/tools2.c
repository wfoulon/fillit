/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:03:18 by clonger           #+#    #+#             */
/*   Updated: 2017/11/24 14:36:35 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_parse(char **tetriminos)
{
	int		i;
	int		j;
	char	alpha;

	i = 0;
	alpha = 'a';
	while (tetriminos[i])
	{
		j = 0;
		while (tetriminos[i][j])
		{
			if (tetriminos[i][j] == '#')
				tetriminos[i][j] = alpha;
			j++;
		}
		i++;
		alpha++;
	}
}

void		ft_free(char **tetriminos)
{
	int		y;

	y = 0;
	while (tetriminos[y])
	{
		free(tetriminos[y]);
		y++;
	}
	free(tetriminos);
}

void		reset_tetriminos(char *tetriminos)
{
	int		x;

	x = 0;
	while (tetriminos[x])
	{
		if (tetriminos[x] >= 'A' && tetriminos[x] <= 'Z')
			tetriminos[x] += 32;
		x++;
	}
}

void		reset_all_tetriminos(char **tetriminos)
{
	int		y;

	y = 0;
	while (tetriminos[y])
	{
		reset_tetriminos(tetriminos[y]);
		y++;
	}
}

char		*ft_set_solution(char **tetriminos)
{
	int		i;
	int		y;
	char	*solution;

	i = 0;
	y = 0;
	while (tetriminos[y])
		y++;
	y *= 4;
	while ((i * i) < y)
		i++;
	if (!(solution = (char *)malloc(sizeof(char) * ((i + 1) * i))))
		return (NULL);
	ft_init_solution(solution, i);
	return (solution);
}
