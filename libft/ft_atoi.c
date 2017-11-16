/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:04:39 by clonger           #+#    #+#             */
/*   Updated: 2017/11/08 15:04:39 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strverif(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else if (c == '\v' || c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_strverif(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
		else
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}
