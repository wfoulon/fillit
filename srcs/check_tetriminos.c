/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:17:23 by clonger           #+#    #+#             */
/*   Updated: 2017/11/20 16:14:19 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		ft_check_char(char *str)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (str[i] && result != 1)
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			result = 1;
		i++;
	}
	return (result);
}

size_t		ft_check_size(char *str, size_t i)
{
	size_t	j;
	size_t	k;
	size_t	l;

	j = 0;
	k = 0;
	l = 4;
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
		}
		i++;
	}
	if (((j / k) != 4))
		return (1);
	return (0);
}

size_t		ft_nb_tetriminos(char *str)
{
	size_t	i;
	size_t	count;

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

size_t		ft_enough_char(char *str)
{
	size_t	count;
	size_t	i;

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

size_t		ft_valid_form(char *str, size_t i, size_t first)
{
	size_t	last;
	size_t	mem_i;
	size_t	count;

	last = i + 16;
	mem_i = i;
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
