/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:26:10 by clonger           #+#    #+#             */
/*   Updated: 2017/11/09 16:26:11 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * size);
	if (!str || size == 0)
		return (NULL);
	while (size > 0)
	{
		str[size] = 0;
		size--;
	}
	str[size] = 0;
	return ((void *)str);
}
