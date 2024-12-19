/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/19 16:24:06 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
		if (valid_number(tmp[i]) == 0)
			error_message(s, "Error\n");
		if (is_integer(tmp[i]) == 0)
			error_message(s, "Error\n");
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
	s->a = malloc(s->a_size * sizeof(int));
	if (s->a == NULL)
		error_message(s, "Error\n");
	s->b = malloc(s->a_size * sizeof(int));
	if (s->b == NULL)
		error_message(s, "Error\n");
}

int	set_moves(char **str, char **dirs, int *moves, int temp_moves)
{
	free(dirs[0]);
	free(dirs[1]);
	dirs[0] = ft_strdup(str[0]);
	dirs[1] = ft_strdup(str[2]);
	if (!dirs[0] || !dirs[1])
	{
		free(dirs[0]);
		free(dirs[1]);
		return (temp_moves);
	}
	moves[0] = ft_atoi(str[1]);
	moves[1] = ft_atoi(str[3]);
	return (temp_moves);
}
