/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:03:39 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/11 21:17:50 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	turkish_sort(t_stacks *s)
{
	int	pivot;

	pivot = (find_min(s->a, s->a_size) + (find_max(s->a, s->a_size))) / 2;
	while (s->a_size != 3)
	{
		while (greater_than_pivot(s->a, s->a_size, pivot) && s->a_size != 4)
		{
			if (s->a[0] <= pivot)
				push("pb", s);
			else
				rotate(s->a, s->a_size, "up", "a");
		}
		push("pb", s);
	}
	sort_three_elements(s);
	go_a(s);
}

void	move_stack_letter(char *dir, t_stacks *s, int moves, char letter)
{
	if (letter == 'a')
	{
		if (ft_strnstr(dir, "up", 2))
			while (moves-- > 0)
				rotate(s->a, s->a_size, "up", "a");
		else
			while (moves-- > 0)
				rotate(s->a, s->a_size, "down", "a");
	}
	else
	{
		if (ft_strnstr(dir, "up", 2))
			while (moves-- > 0)
				rotate(s->b, s->b_size, "up", "b");
		else
			while (moves-- > 0)
				rotate(s->b, s->b_size, "down", "b");
	}
}

int	move_stack(t_stacks *s, char **dirs, int *moves, char stack)
{
	while (moves[0] > 0 && moves[1] > 0)
	{
		if (ft_strnstr(dirs[0], "up", 2) && ft_strnstr(dirs[1], "up", 2))
			rotate_both_up(s);
		else if (ft_strnstr(dirs[0], "down", 2) && ft_strnstr(dirs[1], "down",
				2))
			rotate_both_down(s);
		else
			break ;
		moves[0]--;
		moves[1]--;
	}
	if (stack == 'a')
		return (move_stack_letter(dirs[0], s, moves[0], 'a'), moves[1]);
	else
		return (move_stack_letter(dirs[1], s, moves[1], 'b'), moves[0]);
}

void	move_to_stack(char *dir, int moves, t_stacks *s, char stack)
{
	if (stack == 'a')
	{
		while (moves-- > 0)
			rotate(s->a, s->a_size, dir, "a");
		push("pa", s);
	}
	else
	{
		while (moves-- > 0)
			rotate(s->b, s->b_size, dir, "b");
		push("pb", s);
	}
}

void	order_stack(int *st, int size, char *stack)
{
	int	i;
	int	moves_up;
	int	moves_down;

	i = 0;
	while (st[i] != find_min(st, size))
		i++;
	if (ft_strncmp(stack, "a", 1))
	{
		moves_up = i + 1;
		moves_down = size - i - 1;
	}
	else
	{
		moves_up = i;
		moves_down = size - i;
	}
	if (moves_up < moves_down)
		while (moves_up-- > 0)
			rotate(st, size, "up", stack);
	else
		while (moves_down-- > 0)
			rotate(st, size, "down", stack);
}
