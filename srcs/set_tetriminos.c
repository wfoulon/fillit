/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:27:23 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/16 11:27:25 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reset_tetriminos(char *tetriminos)
{
	int i;

	i = 0;
	while (tetriminos[i])
	{
		if (tetriminos[i] >= 'A' && tetriminos[i] <= 'Z')
			tetriminos[i] += 32;
		i++;
	}
}

void	reset_all_tetriminos (char **tetriminos)
{
	int i;

	i = 0;
	while (tetriminos[i])
	{
		reset_tetriminos(tetriminos[i]);
		i++;
	}
}

int		set_tetriminos(char *tetriminos, int i, char *solution, int j)
{
	int nb;
	int len;

	nb = 0;
	len = 0;
	while (solution[len] != '\n')
		len++;
	len++;
	if (i >= 0 && i < 20 && j >= 0 && j < (len * (len - 1))
		&& tetriminos[i] >= 'a' && tetriminos[i] <= 'z' &&
		solution[j] == '.')
	{
		tetriminos[i] -= 32;
		solution[j] = tetriminos[i];
		nb++;
		nb += set_tetriminos(tetriminos, i + 1, solution, j + 1);
		nb += set_tetriminos(teriminos, i + 5, solution, j + len);
		nb += set_tetriminos(tetriminos, i - 1, solution, j - 1);
	}
	return (nb);
}