/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:41:02 by clonger           #+#    #+#             */
/*   Updated: 2017/11/07 16:41:04 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	str;
	size_t			i;

	str = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		((char*)b)[i] = str;
		i++;
	}
	return (b);
}
