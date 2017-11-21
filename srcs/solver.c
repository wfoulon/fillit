/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:49:27 by clonger           #+#    #+#             */
/*   Updated: 2017/11/21 14:55:00 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*bigger(char **tetriminos, char *solution, size_t i)
{
	free(solution);
	if (!(solution = ft_strnew((i + 2) * (i + 1))))
		return (NULL);
	ft_init_solution(solution, i + 1);
	reset_all_tetriminos(tetriminos);
	return (solution);
}

static int		ft_fill_solution(char **tetriminos, char **sol, size_t y)
{
	size_t		i;
	char		*sol_cpy;

	i = 0;
	if (!tetriminos[y])
		return (1);
	sol_cpy = ft_strdup(*sol);
	while ((*sol)[i])
	{
		if (!ft_put_tetris(tetriminos, *sol, y, i))
		{
			i++;
			continue ;
		}
		if (ft_fill_solution(tetriminos, sol, y + 1))
		{
			free(sol_cpy);
			return (1);
		}
		free(*sol);
		*sol = ft_strdup(sol_cpy);
	}
	free(sol_cpy);
	return (0);
}

void			ft_init_solution(char *solution, size_t i)
{
	size_t		j;

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

char			*ft_solve(char **tetriminos)
{
	size_t		y;
	size_t		i;
	char		*solution;

	y = 0;
	i = 0;
	while (tetriminos[y])
		y++;
	y *= 4;
	while (i * i < y)
		i++;
	solution = ft_set_solution(tetriminos);
	while (ft_fill_solution(tetriminos, &solution, 0) == 0)
	{
		if (!(solution = bigger(tetriminos, solution, i)))
			return (NULL);
		i++;
	}
	return (solution);
}
