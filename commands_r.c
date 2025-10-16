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

static void	r(t_ringbuffer *b)
{
	long	tmp;
	long	i;

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
