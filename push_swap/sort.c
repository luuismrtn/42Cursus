/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/11/23 22:46:45 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_stacks *s)
{
	if (s->a[2] != 2)
	{
		if (s->a[0] == 2)
			rotate(s->a, s->a_size, "up", "a");
		else
			rotate(s->a, s->a_size, "down", "a");
	}
	if (s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
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

