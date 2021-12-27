/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fasthelp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:20:45 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 14:22:08 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putinpos(t_list **lst)
{
	int	max;

	max = ft_getmaxval(lst);
	while (ft_getval(lst) != max)
	{
		if (!ft_upordown(lst, max))
			ft_rotate(NULL, lst, "rb\n", 1);
		else
			ft_rotate(NULL, lst, "rrb\n", 1);
	}
}

void	ft_push_back(t_list **a, t_list **b)
{
	while (*b)
	{
		ft_putinpos(b);
		ft_push(a, b, "pa\n", 1);
	}
}

void	ft_push2b(t_list **a, t_list **b, int *max, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (ft_getval(a) >= max[0] && ft_getval(a) <= max[1])
		{
			ft_push(a, b, "pb\n", 1);
			i++;
		}
		else
		{
			if (ft_getshortest(a, max[0], max[1]))
				ft_rotate(a, b, "rra\n", 1);
			else
				ft_rotate(a, b, "ra\n", 1);
		}
	}
}

void	ft_shift_back(t_list **lst, int max)
{
	while (ft_getval(lst) != max)
	{
		if (!ft_upordown(lst, max))
			ft_rotate(lst, NULL, "ra\n", 1);
		else
			ft_rotate(lst, NULL, "rra\n", 1);
	}
}
