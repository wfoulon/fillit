/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:03:18 by clonger           #+#    #+#             */
/*   Updated: 2017/11/16 18:03:18 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_parse(char **tetriminos)
{
	size_t	i;
	size_t	j;
	char	alpha;

	i = 0;
	j = 0;
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