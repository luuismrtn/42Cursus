/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:34:28 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/11 20:38:06 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_moves_up(int *stack, int num, int size)
{
	int	moves;
	int	i;

	moves = 0;
	i = 0;
	if (num > find_max(stack, size) || num < find_min(stack, size))
	{
		while (i < size && stack[i] != find_min(stack, size))
		{
			moves++;
			i++;
		}
		return (moves);
	}
	if (num < stack[i] && num > stack[size - 1])
		return (moves);
	moves++;
	while (i < size - 1)
	{
		if (num < stack[i + 1] && num > stack[i])
			return (moves);
		moves++;
		i++;
	}
	return (moves);
}

static int	count_moves_down(int *stack, int num, int size)
{
	int	moves;
	int	i;

	moves = 0;
	i = size - 1;
	if (num > find_max(stack, size) || num < find_min(stack, size))
	{
		while (i > 0 && stack[i] != find_max(stack, size))
		{
			moves++;
			i--;
		}
		return (moves);
	}
	if (num > stack[i] && num < stack[0])
		return (moves);
	moves++;
	while (i > 0)
	{
		if (num > stack[i - 1] && num < stack[i])
			return (moves);
		moves++;
		i--;
	}
	return (moves);
}

int	count_moves_dir(int *stack, int num, char *dir, int size)
{
	if (ft_strnstr(dir, "up", 2))
		return (count_moves_up(stack, num, size));
	return (count_moves_down(stack, num, size));
}
