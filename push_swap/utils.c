/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/11/23 23:00:48 by lumartin         ###   ########.fr       */
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
	int		moves;
	int		i;
	int		best_moves;
	char	**str;
	int		best_pos;
	int		temp_moves;
	char	*dir;
	char	*dirA;
	int		moves_a;
	int		moves_b;

	push("pb", s);
	moves = 0;
	dir = ft_strdup("aaaa");
	best_moves = 10000;
	best_pos = 0;
	while (s->a_size != 0)
	{
		i = 0;
		best_moves = 10000;
		best_pos = 0;
		temp_moves = 10000;
		while (i < 10 && i < s->a_size)
		{
			str = count_moves_to_b(s, i);
			temp_moves = ft_atoi(str[1]) + ft_atoi(str[3]);
			s->a[i], temp_moves, str[2], ft_atoi(str[3]);
			if (temp_moves < best_moves)
			{
				best_moves = temp_moves;
				best_pos = i;
				moves_b = ft_atoi(str[1]);
				dir = ft_strdup(str[0]);
				dirA = ft_strdup(str[2]);
				moves_a = ft_atoi(str[3]);
			}
			i++;
		}
		move_a(dirA, s, moves_a);
		moves_to_b(dir, moves_b, s);
	}
	order_stack_b(s);
	moves_to_a(s);
	return (moves);
}
void	move_a(char *dir, t_stacks *s, int moves)
{
	if (ft_strnstr(dir, "up", 2))
	{
		while (moves > 0)
		{
			rotate(s->a, s->a_size, "up", "a");
			moves--;
		}
	}
	else
	{
		while (moves > 0)
		{
			rotate(s->a, s->a_size, "down", "a");
			moves--;
		}
	}
}

void	moves_to_b(char *dir, int moves, t_stacks *s)
{
	if (ft_strnstr(dir, "up", 2))
	{
		while (moves > 0)
		{
			rotate(s->b, s->b_size, "up", "b");
			moves--;
		}
	}
	else
	{
		while (moves > 0)
		{
			rotate(s->b, s->b_size, "down", "b");
			moves--;
		}
	}
	push("pb", s);
}

void	order_stack_b(t_stacks *s)
{
	int	i;
	int	moves_up;
	int	moves_down;
	int	max;
	int	min;

	if (check_stack(s))
		return ;
	moves_up = 0;
	moves_down = 0;
	max = find_max(s->b, s->b_size);
	min = find_min(s->b, s->b_size);
	i = 0;
	while (max != s->b[i] && i < s->b_size - 1)
	{
		moves_up++;
		i++;
	}
	i = s->b_size - 1;
	while (min != s->b[i] && i > 0)
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

int	check_stack(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->b_size - 1)
	{
		if (s->b[i] < s->b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

char	**count_moves_to_b(t_stacks *s, int pos)
{
	int	num;
	int	moves_up;
	int	moves_down;

	char **str; // [0] = dirB, [1] = movesB, [2] = dirA, [3] = movesA
	str = malloc(4 * sizeof(char *));
	if (pos > s->a_size)
		error_message(s, "Error (No existe número en el stack A)\n");
	num = s->a[pos];
	if (pos < s->a_size - pos)
	{
		str[3] = ft_itoa(pos);
		str[2] = ft_strdup("up");
	}
	else
	{
		str[3] = ft_itoa(s->a_size - pos);
		str[2] = ft_strdup("down");
	}
	moves_up = count_moves_dir(s->b, num, "up", s->b_size);
	moves_down = count_moves_dir(s->b, num, "down", s->b_size);
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
	int	max;
	int	min;
	int	moves;
	int	i;

	max = find_max(stack, size);
	min = find_min(stack, size);
	moves = 0;
	if (ft_strnstr(dir, "up", 2))
	{
		i = 0;
		if (num > max || num < min)
		{
			while (i < size && stack[i] != max)
			{
				moves++;
				i++;
			}
			return (moves);
		}
		if (i == 0 && num > stack[i] && num < stack[size - 1])
			return (moves);
		else
		{
			moves++;
			while (i < size - 1)
			{
				if (num > stack[i + 1] && num < stack[i])
					return (moves);
				moves++;
				i++;
			}
		}
	}
	else
	{
		i = size - 1;
		if (num > max || num < min)
		{
			while (i > 0 && stack[i] != min)
			{
				moves++;
				i--;
			}
			return (moves);
		}
		if (i == size - 1 && num < stack[i] && num > stack[0])
			return (moves);
		else
		{
			moves++;
			while (i > 0)
			{
				if (num < stack[i - 1] && num > stack[i])
					return (moves);
				moves++;
				i--;
			}
		}
	}
	return (moves);
}

void	moves_to_a(t_stacks *s)
{
	int	i;
	int	size;

	i = 0;
	size = s->b_size;
	while (i < size)
	{
		push("pa", s);
		i++;
	}
}
