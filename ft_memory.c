/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:14:45 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 14:14:48 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* clean up functions */
static void	ft_del(void *nbr)
{
	free(nbr);
}

void	ft_cleanup(t_list **a, t_list **b)
{
	ft_lstclear(a, &ft_del);
	ft_lstclear(b, &ft_del);
	free(a);
	free(b);
}
