/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:17:23 by clonger           #+#    #+#             */
/*   Updated: 2017/11/24 14:40:00 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' || str[i] == '.' || str[i] == '\n' || str[i] == '\0')
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_check_size(char *str, int i, int j)
{
	int	k;
	int	l;
	int	result;

	k = 0;
	l = 4;
	result = 0;
	while (str[i])
	{
		if (str[l] == '\n')
		{
			l += 5;
			j++;
		}
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			k++;
			l++;
			((j % k) != 0 || (j != 4 && k == 1)) ? result = 1 : result;
		}
		i++;
	}
	((j == 0) || (k == 0)) ? result = 1 : result;
	(((j / k) != 4) && (result != 1)) ? result = 1 : result;
	return (result);
}

int		ft_nb_tetriminos(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	if (count > 26)
		return (0);
	return (count);
}

int		ft_enough_char(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
			count++;
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			if (count != 4)
				return (1);
			count = 0;
		}
		i++;
	}
	return (0);
}

int		ft_valid_form(char *str, int i, int first)
{
	int	last;
	int	count;

	last = i + 16;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			(str[i - 1] == '#') ? count++ : count;
			(str[i + 1] == '#') ? count++ : count;
			(str[i - 5] == '#' && first < i) ? count++ : count;
			(str[i + 5] == '#' && last > i) ? count++ : count;
		}
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			if (count != 6 && count != 8)
				return (1);
			count = 0;
			first = i + 4;
			last = i + 16;
		}
		i++;
	}
	return (0);
}
