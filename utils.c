/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:31:04 by gostroum          #+#    #+#             */
/*   Updated: 2025/10/17 19:58:39 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(int err_num)
{
	write(1, "Error\n", 6);
	exit (err_num);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && i < 20)
		i++;
	return (i);
}

long	ft_atoi(char *str)
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
		ans = 10 * ans + (str[i] - '0');
		if ('0' > str[i] || str[i] > '9' || sign * ans > INT_MAX
			|| sign * ans < INT_MIN)
			error_exit(ATOI_ERROR);
		i++;
	}
	return (ans * sign);
}
