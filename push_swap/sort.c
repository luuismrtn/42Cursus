/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/11/24 19:00:09 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_stacks *st)
{
	int f;
	int s;
	int t;
	
	f = st->a[0];
	s = st->a[1];
	t = st->a[2];
	
	if (f > s && f > t && s < t)
		rotate(st->a, st->a_size, "up", "a");
	else if (f > s && f > t && s > t)
	{
		rotate(st->a, st->a_size, "up", "a");
		swap("sa", st->a, st->a_size);
	}
	else if (f < s && f > t)
		rotate(st->a, st->a_size, "down", "a");
	else if (f > s && f < t)
		swap("sa", st->a, st->a_size);
	else if (f < s && f < t && s > t)
	{
		rotate(st->a, st->a_size, "down", "a");
		swap("sa", st->a, st->a_size);
	}
}

int	is_array_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(t_stacks *stack, char letter)
{
	size_t	i;

	i = 0;
	ft_printf("%c: ", letter);
	ft_printf("[");
	if (letter == 'a')
	{
		if (stack->a_size == 0)
		{
			ft_printf("]\n");
			return ;
		}
		while (i < stack->a_size - 1)
		{
			ft_printf("%i, ", stack->a[i]);
			i++;
		}
		ft_printf("%i", stack->a[i]);
	}
	else
	{
		if (stack->b_size == 0)
		{
			ft_printf("]\n");
			return ;
		}
		while (i < stack->b_size - 1)
		{
			ft_printf("%i, ", stack->b[i]);
			i++;
		}
		ft_printf("%i", stack->b[i]);
	}
	ft_printf("]\n");
}

