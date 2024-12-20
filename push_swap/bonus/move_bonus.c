/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/19 17:23:35 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	swap(int *array, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
}

void	push(char *str, t_stacks *s)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (s->b_size <= 0)
			return ;
		tmp = s->b[0];
		ft_memmove(s->a + 1, s->a, sizeof(int) * s->a_size);
		s->a[0] = tmp;
		s->b_size--;
		ft_memmove(s->b, s->b + 1, sizeof(int) * s->b_size);
		s->a_size++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (s->a_size <= 0)
			return ;
		tmp = s->a[0];
		ft_memmove(s->b + 1, s->b, sizeof(int) * s->b_size);
		s->b[0] = tmp;
		s->a_size--;
		ft_memmove(s->a, s->a + 1, sizeof(int) * s->a_size);
		s->b_size++;
	}
}

void	rotate(int *array, int size, char *direction)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
	}
}

void	rotate_both_up(t_stacks *s)
{
	int	tmp;
	int	*array_a;
	int	*array_b;

	array_a = s->a;
	array_b = s->b;
	if (s->a_size < 0 || s->b_size < 0)
		return ;
	tmp = array_a[0];
	ft_memmove(array_a, array_a + 1, sizeof(int) * (s->a_size - 1));
	array_a[s->a_size - 1] = tmp;
	tmp = array_b[0];
	ft_memmove(array_b, array_b + 1, sizeof(int) * (s->b_size - 1));
	array_b[s->b_size - 1] = tmp;
}

void	rotate_both_down(t_stacks *s)
{
	int	tmp;
	int	*array_a;
	int	*array_b;

	array_a = s->a;
	array_b = s->b;
	if (s->a_size < 0 || s->b_size < 0)
		return ;
	tmp = array_a[s->a_size - 1];
	ft_memmove(array_a + 1, array_a, sizeof(int) * (s->a_size - 1));
	array_a[0] = tmp;
	tmp = array_b[s->b_size - 1];
	ft_memmove(array_b + 1, array_b, sizeof(int) * (s->b_size - 1));
	array_b[0] = tmp;
}
