/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:53:33 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/14 18:21:37 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define VALIDATE_ERROR		1
# define ATOI_ERROR			2	
# define MALLOC_ERROR		3
# define UNIQUE_ERROR		4

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_ringbuffer
{
	long	*data;
	size_t	top;
}	t_ringbuffer;

typedef struct s_bufs
{
	t_ringbuffer	a;
	t_ringbuffer	b;
	size_t			len;	
}	t_bufs;

void	error_exit(int err_num);
void	pa(t_bufs *b);
void	pb(t_bufs *b);
void	sa(t_bufs *b);
void	sb(t_bufs *b);
void	ra(t_bufs *b);
void	rb(t_bufs *b);
void	rra(t_bufs *b);
void	rrb(t_bufs *b);

void	solver(t_bufs *b);
#endif 
