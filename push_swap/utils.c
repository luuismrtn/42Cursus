/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/10 00:34:39 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_if_sorted_or_has_duplicate(t_stacks *s, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < s->a_size)
		{
			j = i + 1;
			while (j < s->a_size)
			{
				if (s->a[i] == s->a[j])
					error_message(s, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(s))
		error_message(s, NULL);
}

void	parse_numbers(t_stacks *s)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	tmp = ft_split(s->join_args, ' ');
	i = 0;
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		s->a[z++] = ft_atoi(tmp[i++]);
		free(tmp[i - 1]);
	}
	free(tmp);
	exit_if_sorted_or_has_duplicate(s, 0);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

void	initialize_stacks(int argc, char **argv, t_stacks *s)
{
	int	i;

	i = 0;
	s->a_size = 0;
	s->b_size = 0;
	while (--argc)
	{
		if (count_words(argv[i + 1], ' '))
			s->a_size += count_words(argv[i + 1], ' ');
		else
			s->a_size++;
		i++;
	}
	s->a = malloc(s->a_size * sizeof *s->a);
	if (s->a == NULL)
		error_message(s, "Error\n");
	s->b = malloc(s->a_size * sizeof *s->b);
	if (s->b == NULL)
		error_message(s, "Error\n");
}

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

/* TURCO */

int	turkish_sort(t_stacks *s)
{
	int		best_moves;
	int		temp_moves;
	int		i;
	int		moves_a;
	int		moves_b;
	char	*dir;
	char	*dirA;
	char	**str;

	push("pb", s);
	while (s->a_size > 3)
	{
		best_moves = 10000;
		i = 0;
		while (i < s->a_size)
		{
			str = count_moves_to_stack(s, i, 'b');
			temp_moves = real_moves(str);
			if (temp_moves < best_moves)
			{
				best_moves = temp_moves;
				moves_a = ft_atoi(str[3]);
				moves_b = ft_atoi(str[1]);
				dirA = ft_strdup(str[2]);
				dir = ft_strdup(str[0]);
			}
			i++;
		}
		moves_b = move_stack(s, dirA, moves_a, dir, moves_b, 'a');
		move_to_stack(dir, moves_b, s, 'b');
	}
	order_stack(s, s->b, s->b_size, "b");
	go_a(s);
	return (0);
}

void	go_a(t_stacks *s)
{
	int	i;
	int	moves_up;
	int	moves_down;

	sort_three_elements(s);
	while (s->b_size != 0)
	{
		moves_up = count_moves_dir_to_a(s->a, s->b[0], "up", s->a_size);
		moves_down = count_moves_dir_to_a(s->a, s->b[0], "down", s->a_size);
		if (moves_up <= moves_down)
			move_to_stack("up", moves_up, s, 'a');
		else
			move_to_stack("down", moves_down, s, 'a');
	}
	order_stack(s, s->a, s->a_size, "a");
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

int	move_stack(t_stacks *s, char *dirA, int moves_a, char *dirB, int moves_b,
		char stack)
{
	while (moves_a > 0 && moves_b > 0)
	{
		if (ft_strnstr(dirA, "up", 2) && ft_strnstr(dirB, "up", 2))
			rotate_both_up(s);
		else if (ft_strnstr(dirA, "down", 2) && ft_strnstr(dirB, "down", 2))
			rotate_both_down(s);
		else
			break ;
		moves_a--;
		moves_b--;
	}
	if (stack == 'a')
		return (move_stack_letter(dirA, s, moves_a, 'a'), moves_b);
	else
		return (move_stack_letter(dirB, s, moves_b, 'b'), moves_a);
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

void	order_stack(t_stacks *s, int *st, int size, char *stack)
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

char	**count_moves_to_stack(t_stacks *s, int pos, char stack)
{
	char	**str;
	int		num;
	int		moves_up;
	int		moves_down;
	int		size;

	if (stack == 'b')
	{
		num = s->a[pos];
		moves_up = count_moves_dir(s->b, num, "up", s->b_size);
		moves_down = count_moves_dir(s->b, num, "down", s->b_size);
		size = s->a_size;
	}
	else
	{
		num = s->b[pos];
		moves_up = count_moves_dir_to_a(s->a, num, "up", s->a_size);
		moves_down = count_moves_dir_to_a(s->a, num, "down", s->a_size);
		size = s->b_size;
	}
	str = malloc(4 * sizeof(char *));
	if (pos < size - pos)
	{
		str[3] = ft_itoa(pos);
		str[2] = ft_strdup("up");
	}
	else
	{
		str[3] = ft_itoa(size - pos);
		str[2] = ft_strdup("down");
	}
	if (moves_up < moves_down)
	{
		str[0] = ft_strdup("up");
		str[1] = ft_itoa(moves_up);
	}
	else
	{
		str[0] = ft_strdup("down");
		str[1] = ft_itoa(moves_down);
	}
	return (str);
}

int	count_moves_dir(int *stack, int num, char *dir, int size)
{
	int	moves;
	int	i;

	moves = 0;
	i = 0;
	if (ft_strnstr(dir, "up", 2))
	{
		if (num > find_max(stack, size) || num < find_min(stack, size))
		{
			while (i < size && stack[i] != find_max(stack, size))
			{
				moves++;
				i++;
			}
			return (moves);
		}
		if (num > stack[i] && num < stack[size - 1])
			return (moves);
		moves++;
		while (i < size - 1)
		{
			if (num > stack[i + 1] && num < stack[i])
				return (moves);
			moves++;
			i++;
		}
	}
	else
	{
		i = size - 1;
		if (num > find_max(stack, size) || num < find_min(stack, size))
		{
			while (i > 0 && stack[i] != find_min(stack, size))
			{
				moves++;
				i--;
			}
			return (moves);
		}
		if (num < stack[i] && num > stack[0])
			return (moves);
		moves++;
		while (i > 0)
		{
			if (num < stack[i - 1] && num > stack[i])
				return (moves);
			moves++;
			i--;
		}
	}
	return (moves);
}

int	count_moves_dir_to_a(int *stack, int num, char *dir, int size)
{
	int	moves;
	int	i;

	moves = 0;
	i = 0;
	if (ft_strnstr(dir, "up", 2))
	{
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
	}
	else
	{
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
	}
	return (moves);
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
