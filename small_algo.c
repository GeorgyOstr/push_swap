/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:42:01 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/16 19:22:44 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_pb(t_bufs *b)
{
	size_t	i;
	size_t	imin;
	long	min;

	i = 0;
	min = (long)INT_MAX + 1;
	imin = 0;
	while (i < b->a.top)
	{
		if (b->a.data[i] < min)
		{
			imin = i;
			min = b->a.data[i];
		}
		i++;
	}
	if (imin + 1 < b->a.top - imin - 1)
	{
		while (b->a.data[b->a.top - 1] != min)
			rra(b);
	}
	else
	{
		while (b->a.data[b->a.top - 1] != min)
			ra(b);
	}
	pb(b);
}

void	lessthen(t_bufs *b)
{
	int	i;

	i = 0;
	while (i < b->len - 3)
	{
		min_pb(b);
		i++;
	}
	three(b);
	i = 0;
	while (i < b->len - 3)
	{
		pa(b);
		i++;
	}
}

void	three(t_bufs *b)
{
	if (b->a.data[b->a.top - 3] > b->a.data[b->a.top - 1]
		&& b->a.data[b->a.top - 3] > b->a.data[b->a.top - 2])
		two(b);
	else if (b->a.data[b->a.top - 1] > b->a.data[b->a.top - 2]
		&& b->a.data[b->a.top - 1] > b->a.data[b->a.top - 3])
	{
		ra(b);
		two(b);
	}
	else if (b->a.data[b->a.top - 2] > b->a.data[b->a.top - 1]
		&& b->a.data[b->a.top - 2] > b->a.data[b->a.top - 3])
	{
		rra(b);
		two(b);
	}
}

void	two(t_bufs *b)
{
	if (b->a.data[b->a.top - 1] > b->a.data[b->a.top - 2])
		sa(b);
}
