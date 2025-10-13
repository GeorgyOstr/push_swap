/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:02:10 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/13 23:18:20 by gostroum         ###   ########.fr       */
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

t_ringbuffer	validate(int argc, char**argv)
{
	size_t			i;
	t_ringbuffer	ans;

	i = 0;
	if (argc <= 1)
		exit(0);
	ans.buf = malloc(2 * (argc - 1) * sizeof(long));
	if (!ans.buf)
		error_exit(MALLOC_ERROR);
	ans.writepos = 0;
	ans.readpos = 0;
	ans.len = argc - 1;
	while (i < argc - 1)
	{
		ans.buf[i] = ft_atoi(argv[i + 1]);
		ans.buf[i + ans.len] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (ans);
}

void	check_repeat(t_ringbuffer *b)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < b->len)
	{
		j = 0;
		while (j < b->len)
		{
			if (i != j && b->buf[j] == b->buf[i])
				error_exit(UNIQUE_ERROR);
			j++;
		}
		i++;
	}
}

void	enumerate(t_ringbuffer *b)
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
			if (b->buf[j] < min)
			{
				min = b->buf[j];
				jmin = j;
			}
			j++;
		}
		b->buf[jmin + b->len] = i;
		b->buf[jmin] = (long)INT_MAX + 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int				i;
	t_ringbuffer	data;

	data = validate(argc, argv);
	check_repeat(&data);
	enumerate(&data);
	i = 0;
	while (i < data.len)
	{
		printf("%ld\n", data.buf[data.len + i++]);
	}
	free(data.buf);
	return (0);
}
