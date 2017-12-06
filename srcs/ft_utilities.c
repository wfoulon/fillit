/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:48:57 by clonger           #+#    #+#             */
/*   Updated: 2017/11/27 10:57:04 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_isalpha2(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

static void	bzero_tetriminos(char **tetri)
{
	int		i;

	i = 0;
	while (i < 26)
	{
		*tetri = NULL;
		++tetri;
		++i;
	}
}

char		**ft_read_file(int fd)
{
	char	**tetri;
	char	buff[BUFFSIZE + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((tetri = (char **)malloc(sizeof(char *) * MSIZE + 1)) == NULL)
		return (NULL);
	bzero_tetriminos(tetri);
	if (read(fd, buff, BUFFSIZE) <= 0)
		return (NULL);
	if (!ft_errors(buff))
		return (NULL);
	while (buff[j])
	{
		tetri[i] = ft_strsub(buff, i * 21, 21);
		j += 21;
		i++;
	}
	return (tetri);
}
