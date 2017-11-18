/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:17:23 by clonger           #+#    #+#             */
/*   Updated: 2017/11/15 16:17:26 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		ft_check_char(char *str)
{
	size_t	i;
	size_t		result;

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

size_t		ft_check_size(char *str)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
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
	if ((j / k) != 4)
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
	size_t	result;
	size_t	i;

	result = 0;
	i = 0;
	while (str[i] && result != 1)
	{
		count = 0;
		while (str[i] != '\n' || (str[i + 1] != '\n' && str[i + 1] != '\0'))
		{
			if (str[i] == '#')
				count++;

			i++;
		}
		if (count != 4)
			result = 1;
		i++;
	}
	return (result);
}

size_t		ft_valid_form(char *str, size_t i)
{
	size_t	last;
	size_t	first;
	size_t	count;

	last = i + 16;
	first = 0;
	while (str[i])
	{
		count = 0;
		while (str[i] != '\n' || (str[i + 1] != '\n' && str[i + 1] != '\0'))
		{
			if (str[i] == '#')
			{
				if (str[i - 1] == '#')
					count++;
				if (str[i + 1] == '#')
					count++;
				if (str[i - 5] == '#' && first < i)
					count++;
				if (str[i + 5] == '#' && last > i)
					count++;
			}
			i++;
		}
		if (count != 6 && count != 8)
			return (1);
		i++;
		first = i + 4;
		last = i + 16;
	}
	return (0);
}















