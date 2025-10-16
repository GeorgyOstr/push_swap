/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:33:16 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/16 19:19:55 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sorteda(t_bufs *b)
{
	size_t	i;

	if (b->len != b->a.top)
		return (1);
	i = 0;
	while (i < b->a.top)
	{
		if (b->a.data[i] != b->a.top - i - 1)
			return (0);
		i++;
	}
	return (1);
}

static size_t	count_digit(t_ringbuffer *b, int dig, int pow)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (i < b->top)
	{
		if ((b->data[i] / pow) % RADIX_BASE == dig)
		{
			c++;
		}
		i++;
	}
	return (c);
}

static void	radixa(t_bufs *b, int pow)
{
	int		i;
	size_t	j;
	size_t	size;

	i = 0;
	while (i < RADIX_BASE)
	{
		if (count_digit(&(b->a), i, pow))
		{
			j = 0;
			size = b->a.top;
			while (b->a.top > 0 && j < size)
			{
				if ((b->a.data[b->a.top - 1] / pow) % RADIX_BASE == i)
					pb(b);
				else
				{
					if (b->a.top - 1 > 0)
						ra(b);
				}
				j++;
			}
		}
		i++;
	}
}

static void	radixb(t_bufs *b, int pow)
{
	int		i;
	size_t	j;
	size_t	size;

	i = RADIX_BASE - 1;
	while (i >= 0)
	{
		if (count_digit(&(b->b), i, pow))
		{
			j = 0;
			size = b->b.top;
			while (b->b.top > 0 && j < size)
			{
				if ((b->b.data[b->b.top - 1] / pow) % RADIX_BASE == i)
					pa(b);
				else
				{
					if (b->b.top - 1 > 0)
						rb(b);
				}
				j++;
			}
		}
		i--;
	}
}

void	solver(t_bufs *b)
{
	long	i;

	if (b->len == 1)
		return ;
	if (b->len == 2)
		two(b);
	else if (b->len == 3)
		three(b);
	else if (b->len <= 30)
		lessthen(b);
	else
	{
		i = 1;
		while (!sorteda(b) && b->a.top != 0 && i < (long)INT_MAX * 10)
		{
			radixa(b, i);
			i *= RADIX_BASE;
			radixb(b, i);
			i *= RADIX_BASE;
		}
	}
}
