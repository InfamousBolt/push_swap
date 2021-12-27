/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:02:22 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 14:02:27 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* find the position of the smallest value in the list */
static
int	ft_find_min(t_list *lst, int n)
{
	int	min;
	int	i;
	int	poi;

	poi = 0;
	i = 1;
	min = *(int *)(lst->content);
	while (i < n)
	{
		lst = lst->next;
		if (*(int *)(lst->content) < min)
		{
			min = *(int *)(lst->content);
			poi = i;
		}
		i++;
	}
	return (poi);
}

/* executes ra and pb n number of times */
static
void	ft_shiftup(t_list **a, t_list **b, int n)
{
	int	i;

	i = 1;
	while (i <= n)
	{
		ft_rotate(a, b, "ra\n", 1);
		i++;
	}
	ft_push(a, b, "pb\n", 1);
}

/* executes rra and pb n number of times */
static
void	ft_shiftdown(t_list **a, t_list **b, int n)
{
	int	i;

	i = 1;
	while (i <= n)
	{
		ft_rotate(a, b, "rra\n", 1);
		i++;
	}
	ft_push(a, b, "pb\n", 1);
}

/* pushes values back to stack a */
static
void	ft_switch_back(t_list **a, t_list **b)
{
	if (*(int *)((*a)->content) > *(int *)((*a)->next->content))
		ft_swap(a, b, "sa\n", 1);
	while (*b)
		ft_push(a, b, "pa\n", 1);
}

/* insertion sort */
void	ft_sort(t_list **a, t_list **b)
{
	int	min;
	int	n;

	n = ft_lstsize(*a);
	while (n > 1)
	{
		n = ft_lstsize(*a);
		if (n == 2)
			break ;
		min = ft_find_min(*a, n);
		if (min == 0)
			ft_push(a, b, "pb\n", 1);
		else if (min < (n / 2))
			ft_shiftup(a, b, min);
		else
			ft_shiftdown(a, b, n - min);
	}
	ft_switch_back(a, b);
	return ;
}
