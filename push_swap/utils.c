/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/09 01:49:15 by lumartin         ###   ########.fr       */
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
			temp_moves = ft_atoi(str[1]) + ft_atoi(str[3]);
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
	order_stack_b(s);
	go_a(s);
	return (0);
}

void	go_a(t_stacks *s)
{
	char	**str;
	int		i;
	int		best_moves;
	int		temp_moves;
	char	*dir;
	char	*dirB;
	int		moves_a;
	int		moves_b;

	sort_three_elements(s);
	while (s->b_size != 0)
	{
		i = 0;
		best_moves = 10000;
		temp_moves = 10000;
		while (i < 1000 && i < s->b_size)
		{
			str = count_moves_to_stack(s, i, 'a');
			temp_moves = ft_atoi(str[1]) + ft_atoi(str[3]);
			if (temp_moves < best_moves)
			{
				best_moves = temp_moves;
				moves_a = ft_atoi(str[1]);
				dir = ft_strdup(str[0]);
				dirB = ft_strdup(str[2]);
				moves_b = ft_atoi(str[3]);
			}
			i++;
		}
		moves_b = move_stack(s, dir, moves_a, dirB, moves_b, 'b');
		move_to_stack(dir, moves_a, s, 'a');
	}
	order_stack_a(s);
}

void move_stack_lett(char *dir, t_stacks *s, int moves, char letter)
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
		{
			rotate_both_up(s, s->a_size, "ab");
		}
		else if (ft_strnstr(dirA, "down", 2) && ft_strnstr(dirB, "down", 2))
		{
			rotate_both_down(s, s->a_size, "ab");
		}
		else
			break ;
		moves_a--;
		moves_b--;
	}
	if (stack == 'a')
	{
		move_stack_lett(dirA, s, moves_a, 'a');
		return (moves_b);
	}
	else
	{
		move_stack_lett(dirB, s, moves_b, 'b');
		return (moves_a);
	}
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

void	order_stack_b(t_stacks *s)
{
	int	i;
	int	moves_up;
	int	moves_down;

	if (check_stack(s, 'b'))
		return ;
	moves_up = 0;
	moves_down = 0;
	i = 0;
	while (find_max(s->b, s->b_size) != s->b[i] && i < s->b_size - 1)
	{
		moves_up++;
		i++;
	}
	i = s->b_size - 1;
	while (find_min(s->b, s->b_size) != s->b[i] && i > 0)
	{
		moves_down++;
		i--;
	}
	if (moves_up < moves_down)
	{
		while (moves_up > 0)
		{
			rotate(s->b, s->b_size, "up", "b");
			moves_up--;
		}
	}
	else
	{
		while (moves_down > 0)
		{
			rotate(s->b, s->b_size, "down", "b");
			moves_down--;
		}
	}
}

void	order_stack_a(t_stacks *s)
{
	int	moves_up;
	int	moves_down;
	int	i;

	moves_up = 0;
	moves_down = 0;
	if (check_stack(s, 'a'))
		return ;
	i = s->a_size - 1;
	while (i >= 0)
	{
		if (s->a[i] == find_max(s->a, s->a_size))
			break ;
		moves_down++;
		i--;
	}
	i = 0;
	while (i < s->a_size)
	{
		if (s->a[i] == find_min(s->a, s->a_size))
			break ;
		moves_up++;
		i++;
	}
	if (moves_up <= moves_down)
	{
		while (moves_up-- > 0)
			rotate(s->a, s->a_size, "up", "a");
	}
	else
	{
		while (moves_down-- > 0)
			rotate(s->a, s->a_size, "down", "a");
	}
}

int	check_stack(t_stacks *s, char stack)
{
	int	i;

	i = 0;
	if (stack == 'a')
	{
		while (i < s->a_size - 1)
		{
			if (s->a[i] < s->a[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		while (i < s->b_size - 1)
		{
			if (s->b[i] < s->b[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
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
