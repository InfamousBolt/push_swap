/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:14:04 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 14:14:16 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_minisort(t_list **a, t_list **b)
{
	while (!ft_issorted(a, 0))
	{
		if (ft_getval(a) > ft_getval(&(*a)->next))
		{
			ft_swap(a, b, "sa\n", 1);
		}
		else
			ft_rotate(a, b, "rra\n", 1);
	}
}
