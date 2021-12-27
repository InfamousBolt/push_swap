/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:13:49 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 14:13:53 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* frees the void pointer */
static
void	ft_del(void *a)
{
	free(a);
}

/* pushes the value to the top of the other stack */
static
int	ft_push_it(t_list **a, t_list **b)
{
	int		*nbr;
	t_list	*hlp;

	nbr = malloc(sizeof(int));
	*nbr = *(int *)((*b)->content);
	ft_lstadd_front(a, ft_lstnew(nbr));
	hlp = (*b)-> next;
	ft_lstdelone(*b, &ft_del);
	*b = hlp;
	return (0);
}

/* executes pa or pb according to the value of ptr */
void	ft_push(t_list **head_a, t_list **head_b, char *ptr, int flag)
{
	int	err;

	err = 0;
	if (*head_b && !ft_strncmp(ptr, "pa", 2))
		err = ft_push_it(head_a, head_b);
	else if (*head_a && !ft_strncmp(ptr, "pb", 2))
		err = ft_push_it(head_b, head_a);
	if (flag && !err)
		write(1, ptr, 3);
}
