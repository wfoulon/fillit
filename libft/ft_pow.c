/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:56:17 by clonger           #+#    #+#             */
/*   Updated: 2017/11/13 18:56:17 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_pow(double nb, double power)
{
	double	result;
	double	test;
	int		even;

	result = 1;
	even = 1;
	test = 2;
	if (nb < 0)
	{
		if ((int)power % 2 != 0)
			even = -1;
		nb *= (-1);
	}
	if (power > 0)
	{
		result = nb * ft_pow(nb, power - 1);
		return (result * even);
	}
	if (power == 0 || power == 1)
		return (1);
	else
		return (0);
}
