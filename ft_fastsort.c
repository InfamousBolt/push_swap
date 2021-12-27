/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fastsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:20:30 by keshav            #+#    #+#             */
/*   Updated: 2021/12/24 14:36:07 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* returns chunk size according to the number of elements */
static int	ft_getchunk(int n)
{
	if (n < 200)
		return (4);
	else
		return (9);
}

/* executes after sorting is done */
static void	ft_finish(t_list **a, t_list **b, int *arr, int *max)
{
	ft_chunk_corr(a, b);
	ft_push_back(a, b);
	if (arr)
		free(arr);
	if (max)
		free(max);
}

/* fast sort algorithm by dividing input to chunks 
 * and findng min element in each chunk 
*/
void	ft_fastsort(t_list **a, t_list **b)
{
	int	n;
	int	chunk;
	int	*arr;
	int	i;
	int	*minmaxlast;

	i = 0;
	n = ft_lstsize(*a);
	chunk = ft_getchunk(n);
	minmaxlast = malloc(sizeof(int) * 3);
	arr = ft_init(a);
	while (arr && minmaxlast && i < chunk)
	{
		minmaxlast[0] = arr[n - (n / chunk) * (i + 1)];
		minmaxlast[1] = arr[(n - (n / chunk) * i) - 1];
		ft_push2b(a, b, minmaxlast, n / chunk);
		if (i)
			ft_shift_back(a, minmaxlast[2]);
		ft_push_back(a, b);
		minmaxlast[2] = ft_getval(a);
		i++;
	}
	ft_finish(a, b, arr, minmaxlast);
}
