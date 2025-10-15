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

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && i < 20)
		i++;
	return (i);
}

static long	ft_atoi(char *str)
{
	int			i;
	long		ans;
	int			sign;
	const int	len = ft_strlen(str);

	sign = 1;
	i = 0;
	ans = 0;
	if (len == 20 || len == 0)
		error_exit(ATOI_ERROR);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && i < 20)
	{
		if ('0' > str[i] || str[i] > '9')
			error_exit(ATOI_ERROR);
		ans = 10 * ans + (str[i] - '0');
		i++;
	}
	return (ans * sign);
}

t_bufs	validate(int argc, char**argv)
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
	return (bufs);
}

void	check_repeat(t_bufs *b)
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

void	enumerate(t_bufs *b)
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
	int		i;
	t_bufs	bufs;

	bufs = validate(argc, argv);
	check_repeat(&bufs);
	enumerate(&bufs);
	i = 0;
	while (i < bufs.a.top)
	{
		//printf("%ld\n", bufs.a.data[bufs.a.top - i - 1]);
		i++;
	}
	solver(&bufs);
	i = 0;
	while (i < bufs.a.top)
	{
		//printf("%ld\n", bufs.a.data[bufs.a.top - i - 1]);
		i++;
	}
	free(bufs.a.data);
	return (0);
}
