/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:39:28 by clonger           #+#    #+#             */
/*   Updated: 2017/11/07 17:39:30 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[length] = s2[i];
		i++;
		length++;
	}
	s1[length] = '\0';
	return (s1);
}
