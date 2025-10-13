/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:53:33 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/13 19:54:38 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define VALIDATE_ERROR		1
# define ATOI_ERROR			2	
# define MALLOC_ERROR		3

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_ringbuffer
{
	int		*buf;
	size_t	writepos;
	size_t	readpos;
}	t_ringbuffer;

void	error_exit(int err_num);

#endif 
