/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ps.c                                      :+:      :+:    :+:   */
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
