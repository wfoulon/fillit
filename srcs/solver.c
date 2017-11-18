/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:49:27 by clonger           #+#    #+#             */
/*   Updated: 2017/11/18 13:49:28 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		reset_tetriminos(char *solution, char alph)
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