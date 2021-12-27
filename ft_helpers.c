/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:17:32 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 14:17:36 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* checks if the list is sorted in increasing order when rev == 0
 * in case rev != 0 checks in decreasing order
 * returns 0 for false and 1 for true
*/
int	ft_issorted(t_list **lst, int rev)
{
	int		lval;
	t_list	*tmp;

	if (!*lst)
		return (0);
	tmp = *lst;
	lval = *(int *)tmp->content;
	tmp = tmp->next;
	while (tmp)
	{
		if (!rev && (lval > *(int *)tmp->content))
			return (0);
		if (rev && (lval < *(int *)tmp->content))
			return (0);
		lval = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (1);
}

/* check if all values in the list are either all positive or
 * all negative.
*/
int	ft_isposonly(t_list *lst)
{
	t_list	*tmp;
	int		flg;

	if (!lst)
		return (1);
	tmp = lst;
	if (*(int *)tmp->content >= 0)
		flg = 0;
	else
		flg = 1;
	while (tmp)
	{
		if (!flg && *(int *)tmp->content < 0)
			return (0);
		if (flg && *(int *)tmp->content >= 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/* find the next highest value to MAX and show the shortest path to it
 * return 0 if it is found in the upper half of the stack or 1 if in the
 * lower half of it */
int	ft_upordown(t_list **lst, int max)
{
	int		n;
	int		i;
	int		last;
	t_list	*hlp;

	last = ft_getminval(lst);
	n = 1;
	i = 1;
	hlp = *lst;
	while (hlp)
	{
		if ((ft_getval(&hlp) <= max) && (ft_getval(&hlp) > last))
		{
			last = ft_getval(&hlp);
			n = i;
		}
		i++;
		hlp = hlp->next;
	}
	if (n < (ft_lstsize(*lst) / 2))
		return (0);
	else
		return (1);
}

/* find what is nearer, shifting up or down the list to find the next
 * number between MIN and MAX. 0 shift down, 1 shift up
*/
int	ft_getshortest(t_list **lst, int min, int max)
{
	t_list	*run;
	int		i;
	int		val;
	int		n;

	i = 1;
	val = ft_lstsize(*lst);
	n = val;
	run = *lst;
	while (run)
	{
		if (ft_getval(&run) > min && ft_getval(&run) <= max)
		{
			if ((i < n / 2) && (i < val))
				val = i;
			else if ((i > n / 2) && (n - i < val))
				return (1);
		}
		i++;
		run = run->next;
	}
	return (0);
}

/* correction for rounding bug when dividing integers */
void	ft_chunk_corr(t_list **a, t_list **b)
{
	while (ft_getlastval(a) != ft_getmaxval(a))
	{
		ft_rotate(a, b, "rra\n", 1);
		ft_push(a, b, "pb\n", 1);
	}
}
