/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:58:16 by clonger           #+#    #+#             */
/*   Updated: 2017/11/08 12:58:17 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		length;
	int		i;

	a = (char)c;
	length = ft_strlen(s);
	i = 0;
	while (length > 0)
	{
		if (s[length] == a)
			return ((char*)s + length);
		else
			length--;
	}
	if (s[length] == a)
		return ((char*)s + length);
	return (NULL);
}
