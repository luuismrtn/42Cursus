/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:06:30 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/11 20:10:08 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int *st, int size)
{
	int	i;
	int	max;

	i = 0;
	max = -2147483548;
	while (i < size)
	{
		if (st[i] > max)
			max = st[i];
		i++;
	}
	return (max);
}

int	find_min(int *st, int size)
{
	int	i;
	int	min;

	i = 0;
	min = 2147483547;
	while (i < size)
	{
		if (st[i] < min)
			min = st[i];
		i++;
	}
	return (min);
}

int	greater_than_pivot(int *stack, int size, int pivot)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] < pivot)
			return (1);
		i++;
	}
	return (0);
}

int	real_moves(char **str)
{
	int	moves_a;
	int	moves_b;

	moves_a = ft_atoi(str[1]);
	moves_b = ft_atoi(str[3]);
	if ((ft_strnstr(str[0], "up", 2) && ft_strnstr(str[2], "up", 2))
		|| (ft_strnstr(str[0], "down", 2) && ft_strnstr(str[2], "down", 2)))
	{
		if (moves_a > moves_b)
			return (moves_a);
		else
			return (moves_b);
	}
	return (moves_a + moves_b);
}
