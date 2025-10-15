/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:33:16 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/15 15:54:24 by gostroum         ###   ########.fr       */
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

static void	radixa(t_bufs *b, int pow)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	while (i < 10)
	{
		j = 0;
		size = b->a.top;
		while (b->a.top > 0 && j < size)
		{
			if ((b->a.data[b->a.top - 1] / pow) % 10 == i)
				pb(b);
			else
			{
				if (b->a.top - 1 > 0)
					ra(b);
			}
			j++;
		}
		i++;
	}
}

static void	radixb(t_bufs *b, int pow)
{
	while (b->b.top)
		pa(b);
}

void	solver(t_bufs *b)
{
	long	i;

	i = 1;
	while (not_sorted(b) && b->a.top != 0 && i < (long)INT_MAX * 10)
	{
		radixa(b, i);
		radixb(b, i);
		i *= 10;
	}
	while (b->b.top)
		pa(b);
}
