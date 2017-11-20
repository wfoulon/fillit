/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:49:27 by clonger           #+#    #+#             */
/*   Updated: 2017/11/20 12:55:35 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_fill_solution(char **tetriminos, char *solution, size_t y)
{
	size_t	i;

	i = 0;
	if (!tetriminos[y])
		return (1);
	while (solution[i])
	{
		if (ft_put_tetris(tetriminos, solution, y, i))
		{
			i++;
			continue ;
		}
		if (ft_fill_solution(tetriminos, solution, y + 1))
			return (1);
	}
	return (0);
}

static char	*bigger(char *solution, size_t i)
{
	free(solution);
	if (!(solution = ft_strnew((i + 2) * (i + 1))))
		return (NULL);
	ft_init_solution(solution, i + 1);
	return (solution);
}

void	ft_init_solution(char *solution, size_t i)
{
	size_t	j;

	j = 0;
	while (j < (i + 1) * i)
	{
		if ((j + 1) % (i + 1) == 0)
			solution[j] = '\n';
		else
			solution[j] = '.';
		j++;
	}
	solution[j] = '\0';
}

void		ft_solve(char **tetriminos, char *solution)
{
	size_t	x;
	size_t	i;

	x = 0;
	i = 0;
	while (tetriminos[x])
		x++;
	x *= 4;
	while (i * i < x)
		i++;
	while (ft_fill_solution(tetriminos, solution, 0) == 0)
	{
		if (!(solution = bigger(solution, i)))
			return ;
		i++;
	}
}
