/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:26:31 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/14 18:26:09 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
