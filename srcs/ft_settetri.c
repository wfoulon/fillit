/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:52:14 by clonger           #+#    #+#             */
/*   Updated: 2017/11/27 10:57:05 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_mapping(char **tetri)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 'a';
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
				tetri[i][j] = c;
			++j;
		}
		++i;
		++c;
	}
}

void	reset_all(char **tetriminos)
{
	int		i;

	i = 0;
	while (tetriminos[i])
	{
		ft_reset(tetriminos[i]);
		++i;
	}
}

void	ft_reset(char *tetri)
{
	int		i;

	i = 0;
	while (tetri[i])
	{
		if (tetri[i] >= 'A' && tetri[i] <= 'Z')
			tetri[i] += 32;
		++i;
	}
}

char	*ft_bigger_square(char **tetri, char *feelit, int j)
{
	free(feelit);
	if ((feelit = ft_strnew((j + 2) * (j + 1))) == NULL)
		return (NULL);
	ft_start_sol(feelit, j + 1);
	reset_all(tetri);
	return (feelit);
}

int		ft_set(char *tetri, int i, char *feelit, int index)
{
	int		hashtag;
	int		len;

	hashtag = 0;
	len = 0;
	while (feelit[len] != '\n')
		++len;
	++len;
	if (i >= 0 && i < 20 && index >= 0 && index < (len * (len - 1)) &&
		feelit[index] == '.' && tetri[i] >= 'a' && tetri[i] <= 'z')
	{
		tetri[i] -= 32;
		feelit[index] = tetri[i];
		++hashtag;
		hashtag += ft_set(tetri, i + 1, feelit, index + 1);
		hashtag += ft_set(tetri, i + 5, feelit, index + len);
		hashtag += ft_set(tetri, i - 1, feelit, index - 1);
	}
	return (hashtag);
}
