/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:33:16 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/16 00:04:50 by gostroum         ###   ########.fr       */
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

static int	sortedb(t_bufs *b)
{
	size_t	i;

	if (b->len != b->b.top)
		return (1);
	i = 0;
	while (i < b->b.top)
	{
		if (b->a.data[i] != i)
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
		if ((b->data[b->top - 1] / pow) % 10 == dig)
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
	while (i < 10)
	{
//		if (!count_digit(&(b->a), i, pow))
//		{	
//			i++;
//			continue ;
//		}
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
	int		i;
	size_t	j;
	size_t	size;

	i = 9;
	while (i >= 0)
	{
		//if (!count_digit(&(b->b), i, pow))
		//{	
	//		i--;
	//		continue ;
	//	}
		j = 0;
		size = b->b.top;
		while (b->b.top > 0 && j < size)
		{
			if ((b->b.data[b->b.top - 1] / pow) % 10 == i)
				pa(b);
			else
			{
				if (b->b.top - 1 > 0)
					rb(b);
			}
			j++;
		}
		i--;
	}
}

static void	pa_all(t_bufs *b)
{
	while (b->b.top)
		pa(b);
}

void	solver(t_bufs *b)
{
	long	i;

	i = 1;
	while (!sorteda(b) && b->a.top != 0 && i < (long)INT_MAX * 10)
	{
		radixa(b, i);
		i *= 10;
		if (b->len > 100)
			pa_all(b);
		else
		{
			radixb(b, i);
			i *= 10;
		}
	}
	pa_all(b);
}
