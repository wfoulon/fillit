/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:05:39 by clonger           #+#    #+#             */
/*   Updated: 2017/11/09 18:05:39 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = ft_strnew(len);
	i = 0;
	if (!s || !str)
		return (NULL);
	else
	{
		while (s[start] && i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
	}
	return (str);
}
