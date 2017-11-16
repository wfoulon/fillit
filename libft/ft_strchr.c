/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:20:07 by clonger           #+#    #+#             */
/*   Updated: 2017/11/08 12:20:09 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	a = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return ((char*)s + i);
		else
			i++;
	}
	if (s[i] == a)
		return ((char*)s + i);
	return (NULL);
}
