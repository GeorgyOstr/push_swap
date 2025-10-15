/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:33:16 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/15 12:16:53 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	not_sorted(t_bufs *b)
{
	size_t	i;

	i = 0;
	if (b->len != b->a.top)
		return (1);
	while (i < b->a.top)
	{
		if (b->a.data[i] != b->a.top - i - 1)
			return (1);
		i++;
	}
	return (0);
}

static int	move_to_min(t_bufs *b)
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

void	solver(t_bufs *b)
{
	int	i;

	while (not_sorted(b) && b->a.top != 0)
	{
		move_to_min(b);
	}
	while (b->b.top)
	{
		pa(b);
	}
}
