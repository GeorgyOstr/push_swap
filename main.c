/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:02:10 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/15 12:13:24 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_repeat(t_bufs *b)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < b->len)
	{
		j = 0;
		while (j < b->len)
		{
			if (i != j && b->a.data[j] == b->a.data[i])
				error_exit(UNIQUE_ERROR);
			j++;
		}
		i++;
	}
}

static t_bufs	validate(int argc, char**argv)
{
	size_t	i;
	t_bufs	bufs;

	i = 0;
	if (argc <= 1)
		exit(0);
	bufs.a.data = malloc(2 * (argc - 1) * sizeof(long));
	if (!bufs.a.data)
		error_exit(MALLOC_ERROR);
	bufs.b.data = bufs.a.data + argc - 1;
	bufs.len = argc - 1;
	bufs.a.top = argc - 1;
	bufs.b.top = 0;
	while (i < argc - 1)
	{
		bufs.b.data[i] = ft_atoi(argv[argc - i - 1]);
		bufs.a.data[i] = ft_atoi(argv[argc - i - 1]);
		i++;
	}
	check_repeat(&bufs);
	return (bufs);
}

static void	enumerate(t_bufs *b)
{
	size_t	i;
	size_t	j;
	long	min;
	size_t	jmin;

	i = 0;
	while (i < b->len)
	{
		j = 0;
		min = (long)INT_MAX + 1;
		while (j < b->len)
		{
			if (b->b.data[j] < min)
			{
				min = b->b.data[j];
				jmin = j;
			}
			j++;
		}
		b->a.data[jmin] = i;
		b->b.data[jmin] = (long)INT_MAX + 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_bufs	bufs;

	bufs = validate(argc, argv);
	enumerate(&bufs);
	solver(&bufs);
	free(bufs.a.data);
	return (0);
}
