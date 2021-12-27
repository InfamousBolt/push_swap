/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:57:33 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 15:02:06 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* swap two values in the linked list */
static
int	ft_swap_it(t_list *head)
{
	int	*hlp;

	if (!head || (ft_lstsize(head) < 2))
		return (1);
	hlp = head->content;
	head->content = head->next->content;
	head->next->content = hlp;
	return (0);
}

/* swap two values in the linked list according to given stack */
void	ft_swap(t_list **head_a, t_list **head_b, char *ptr, int flag)
{
	int	err_a;

	err_a = 0;
	if (!ft_strncmp(ptr, "sa", 2))
		err_a = ft_swap_it(*head_a);
	else if (!ft_strncmp(ptr, "sb", 2))
		err_a = ft_swap_it(*head_b);
	else if (!ft_strncmp(ptr, "ss", 2))
	{
		err_a = ft_swap_it(*head_a);
		if (err_a == 0)
			err_a = ft_swap_it(*head_b);
	}
	if (flag && !err_a)
		write(1, ptr, 3);
}
