/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_values.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:57:03 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 13:57:09 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* get value saved in the linked list content */
int	ft_getval(t_list **lst)
{
	return (*(int *)(*lst)->content);
}

/* get value saved in the last element of the linked list content */
int	ft_getlastval(t_list **lst)
{
	t_list	*hlp;

	hlp = ft_lstlast(*lst);
	return (ft_getval(&hlp));
}

/* find highest value in the list */
int	ft_getmaxval(t_list **lst)
{
	int		max;
	t_list	*hlp;

	hlp = *lst;
	max = ft_getval(&hlp);
	while (hlp)
	{
		if (ft_getval(&hlp) > max)
			max = ft_getval(&hlp);
		hlp = hlp->next;
	}
	return (max);
}

/* find the smallest value in the list */
int	ft_getminval(t_list **lst)
{
	int		min;
	t_list	*hlp;

	hlp = *lst;
	min = ft_getval(lst);
	while (hlp)
	{
		if (ft_getval(&hlp) < min)
			min = ft_getval(&hlp);
		hlp = hlp->next;
	}
	return (min);
}
