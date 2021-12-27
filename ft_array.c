/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:21:47 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 14:21:50 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* Bubblesort the array*/
void	ft_bubblesort(int *ptr, int n)
{
	int	i;
	int	swapped;
	int	help;

	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < (n - 1))
		{
			if (ptr[i] > ptr[i + 1])
			{
				help = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = help;
				swapped = 1;
			}
			i++;
		}
	}
}

/* init the array and fill with numbers in the list */
int	*ft_init(t_list **lst)
{
	int		*ptr;
	int		i;
	t_list	*run;

	ptr = malloc(ft_lstsize(*lst) * sizeof(int));
	if (!ptr)
		return (NULL);
	i = 0;
	run = *lst;
	while (run)
	{
		ptr[i] = ft_getval(&run);
		i++;
		run = run->next;
	}
	ft_bubblesort(ptr, ft_lstsize(*lst));
	return (ptr);
}
