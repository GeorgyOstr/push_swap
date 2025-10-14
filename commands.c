/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:26:31 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/14 18:26:09 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_bufs *b)
{
	b->a.top -= 1;
	b->b.data[b->b.top] = b->a.data[b->a.top];
	b->b.top += 1;
	write(1, "pb\n", 3);
}

void	pa(t_bufs *b)
{
	b->b.top -= 1;
	b->a.data[b->a.top] = b->b.data[b->b.top];
	b->a.top += 1;
	write(1, "pa\n", 3);
}

void	sa(t_bufs *b)
{
	long	tmp;

	tmp = b->a.data[b->a.top - 1];
	b->a.data[b->a.top - 1] = b->a.data[b->a.top - 2];
	b->a.data[b->a.top - 2] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_bufs *b)
{
	long	tmp;

	tmp = b->b.data[b->b.top - 1];
	b->b.data[b->b.top - 1] = b->b.data[b->b.top - 2];
	b->b.data[b->b.top - 2] = tmp;
	write(1, "sb\n", 3);
}

static void	r(t_ringbuffer *b)
{
	long	tmp;
	size_t	i;

	tmp = b->data[b->top - 1];
	i = b->top - 2;
	while (i >= 0)
	{
		b->data[i + 1] = b->data[i];
		if (i == 0)
			break ;
		i--;
	}
	b->data[0] = tmp;
}

void	ra(t_bufs *b)
{
	r(&(b->a));
	write(1, "ra\n", 3);
}

void	rb(t_bufs *b)
{
	r(&(b->b));
	write(1, "rb\n", 3);
}

static void	rr(t_ringbuffer *b)
{
	long	tmp;
	size_t	i;

	tmp = b->data[0];
	i = 0;
	while (i < b->top - 1)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->data[b->top - 1] = tmp;
}

void	rra(t_bufs *b)
{
	rr(&(b->a));
	write(1, "rra\n", 4);
}

void	rrb(t_bufs *b)
{
	rr(&(b->b));
	write(1, "rrb\n", 4);
}
