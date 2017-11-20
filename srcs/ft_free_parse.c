/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:03:18 by clonger           #+#    #+#             */
/*   Updated: 2017/11/20 12:30:23 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_parse(char **tetriminos)
{
	size_t	i;
	size_t	j;
	char	alpha;

	i = 0;
	alpha = 'A';
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

void		reset_solution(char *solution, char alph)
{
	size_t	i;

	i = 0;
	while (solution[i])
	{
		if (solution[i] == alph)
			solution[i] = '.';
		i++;
	}
}

char	*ft_set_solution(char **tetriminos)
{
	size_t	i;
	size_t	y;
	char	*solution;

	i = 0;
	y = 0;
	while (tetriminos[y])
		y++;
	y *= 4;
	while ((i * i) < y)
		i++;
	if (!(solution = (char *)malloc(sizeof(solution) * ((i + 1) * i))))
		return (NULL);
	ft_init_solution(solution, i);
	return (solution);
}
