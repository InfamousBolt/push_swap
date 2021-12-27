/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:22:00 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 14:22:03 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static
int	ft_space(char c)
{
	if (((c >= 8) && (c <= 13)) || (c == 32))
		return (1);
	else
		return (0);
}

long	ft_atol(const char *nptr)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while (ft_space(*nptr))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res *= 10;
		res += (*nptr - 48);
		nptr++;
	}
	res *= sign;
	return (res);
}
