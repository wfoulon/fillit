/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:05:39 by clonger           #+#    #+#             */
/*   Updated: 2017/11/13 17:26:53 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int			i;

	i = 0;
	if (n < 0)
	{
		n *= (-1);
		i++;
	}
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void		ft_change(char *str, int n, int len)
{
	int			mod;

	if (n < 0)
	{
		n *= (-1);
		str[0] = '-';
	}
	while (n > 0)
	{
		mod = n % 10;
		n = n / 10;
		str[len--] = mod + 48;
	}
}

char			*ft_itoa(int n)
{
	int			length;
	char		*str;

	length = ft_count(n) - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = ft_strnew(length + 1);
	if (!str)
		return (NULL);
	ft_change(str, n, length);
	return (str);
}
