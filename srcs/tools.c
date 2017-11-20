/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:38:56 by clonger           #+#    #+#             */
/*   Updated: 2017/11/20 16:14:51 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display(char **tetriminos)
{
	int i;

	i = 0;
	if (tetriminos && tetriminos != 0)
	{
		while (tetriminos && tetriminos[i])
		{
			ft_putstr(tetriminos[i]);
			i++;
		}
	}
}

int		is_valid(char *buf)
{
	if (ft_check_char(buf) || ft_check_size(buf, 0))
		error();
	if (ft_nb_tetriminos(buf) >= 27 || ft_enough_char(buf))
		error();
	if (ft_valid_form(buf, 0, 0))
		error();
	return (1);
}

char	**ft_read(int fd)
{
	char	**tetriminos;
	char	buf[547];
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((read(fd, buf, 546)) <= 0)
		return (NULL);
	if (!(is_valid(buf)))
		error();
	if (!(tetriminos = (char **)malloc(sizeof(char *) * 27)))
		return (NULL);
	while (buf[i])
	{
		if (ft_strlen(buf) >= 20)
			tetriminos[j] = ft_strsub(buf, 21 * j, 21);
		else
			return (NULL);
		i += ft_strlen(tetriminos[j]);
		tetriminos[j][ft_strlen(tetriminos[j])] = '\0';
		j++;
	}
	tetriminos[j] = NULL;
	return (tetriminos);
}
