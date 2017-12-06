/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:14:30 by amuller           #+#    #+#             */
/*   Updated: 2017/11/27 10:56:22 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_formchecker(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != '\n' && str[i])
		{
			count++;
			i++;
		}
		if (str[i + 1] == '\n' || str[i + 1] == '\0' || !str[i])
		{
			if (ft_links(str, i + 1) == 0)
				return (0);
			if (count != 16)
				return (0);
			count = 0;
		}
		i++;
	}
	return (1);
}

int		ft_links(char *str, int piece)
{
	int		i;
	int		links;

	i = piece - 20;
	links = 0;
	while (str[i] && i <= piece)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#' && i + 1 <= piece)
				links++;
			if (str[i + 5] == '#' && i + 5 <= piece)
				links++;
			if (str[i - 1] == '#' && i - 1 <= piece)
				links++;
			if (str[i - 5] == '#' && i - 5 >= piece - 20)
				links++;
		}
		i++;
	}
	if (links == 6 || links == 8)
		return (1);
	return (0);
}
