/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:09:12 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 15:03:58 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* rotate up if flag==0, rotate down if flag==1 */
static
int	ft_rotate_it(t_list **lst, int flag)
{
	t_list	*hlp;

	if (ft_lstsize(*lst) < 2)
		return (1);
	if (!flag)
	{
		hlp = *lst;
		*lst = (*lst)->next;
		ft_lstadd_back(lst, hlp);
		hlp->next = NULL;
	}
	else
	{
		hlp = *lst;
		while (hlp->next->next)
			hlp = hlp->next;
		ft_lstadd_front(lst, ft_lstlast(*lst));
		hlp->next = NULL;
	}
	return (0);
}

/* rotate the stack up according to given stack */
static
void	ft_rot_up(t_list **head_a, t_list **head_b, char *ptr, int flag)
{
	int	err;

	err = 0;
	if (!ft_strncmp(ptr, "ra", 2))
		err = ft_rotate_it(head_a, 0);
	else if (!ft_strncmp(ptr, "rb", 2))
		err = ft_rotate_it(head_b, 0);
	else if (!ft_strncmp(ptr, "rr", 2))
	{
		err = ft_rotate_it(head_a, 0);
		if (err == 0)
			err = ft_rotate_it(head_b, 0);
	}
	if (flag && !err)
		write(1, ptr, 3);
}

/* rotate the stack down according to given stack */
static
void	ft_rot_down(t_list **head_a, t_list **head_b, char *ptr, int flag)
{
	int	err;

	err = 0;
	if (!ft_strncmp(ptr, "rra", 3))
		err = ft_rotate_it(head_a, 1);
	else if (!ft_strncmp(ptr, "rrb", 3))
		err = ft_rotate_it(head_b, 1);
	else if (!ft_strncmp(ptr, "rrr", 3))
	{
		err = ft_rotate_it(head_a, 1);
		if (err == 0)
			err = ft_rotate_it(head_b, 1);
	}
	if (flag && !err)
		write(1, ptr, 4);
}

/* rotate up if len = 3 or else rotate down */
void	ft_rotate(t_list **head_a, t_list **head_b, char *ptr, int flag)
{
	int	len;

	len = ft_strlen(ptr);
	if (!len)
		return ;
	if (len == 3)
		ft_rot_up(head_a, head_b, ptr, flag);
	if (len == 4)
		ft_rot_down(head_a, head_b, ptr, flag);
}
