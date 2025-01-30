/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:42:58 by lumartin          #+#    #+#             */
/*   Updated: 2025/01/30 15:43:09 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

static int	valid_instruction_a(t_stacks *s, char *line)
{
	if (!line || !s || s->a_size <= 0)
		return (0);
	if (ft_strncmp(line, "pb\n", 3) == 0)
		return (push("pb", s), 1);
	if (ft_strncmp(line, "ra\n", 3) == 0)
		return (rotate(s->a, s->a_size, "up"), 1);
	if (ft_strncmp(line, "rra\n", 4) == 0)
		return (rotate(s->a, s->a_size, "down"), 1);
	if (s->a_size > 1 && ft_strncmp(line, "sa\n", 3) == 0)
		return (swap(s->a, s->a_size), 1);
	return (2);
}

static int	valid_instruction_b(t_stacks *s, char *line)
{
	if (!line || !s || s->b_size <= 0)
		return (0);
	if (ft_strncmp(line, "pa\n", 3) == 0)
		return (push("pa", s), 1);
	if (ft_strncmp(line, "rb\n", 3) == 0)
		return (rotate(s->b, s->b_size, "up"), 1);
	if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (rotate(s->b, s->b_size, "down"), 1);
	if (s->b_size > 1 && ft_strncmp(line, "sb\n", 3) == 0)
		return (swap(s->b, s->b_size), 1);
	return (2);
}

static int	valid_instruction_both(t_stacks *s, char *line)
{
	if (!line || !s || s->a_size <= 1 || s->b_size <= 1)
		return (0);
	if (ft_strncmp(line, "ss\n", 3) == 0)
		return (swap(s->a, s->a_size), swap(s->b, s->b_size), 1);
	if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (rotate_both_down(s), 1);
	if (ft_strncmp(line, "rr\n", 3) == 0)
		return (rotate_both_up(s), 1);
	return (2);
}

static void	execute_instructions(t_stacks *s, char **instructions)
{
	int	i;
	int	valid_a;
	int	valid_b;
	int	valid_both;

	i = 0;
	while (instructions[i])
	{
		valid_a = valid_instruction_a(s, instructions[i]);
		valid_b = valid_instruction_b(s, instructions[i]);
		valid_both = valid_instruction_both(s, instructions[i]);
		if (!valid_a && !valid_b && !valid_both)
		{
			free_str(instructions);
			ft_putstr_fd("KO\n", 1);
			exit(0);
		}
		i++;
	}
}

void	read_instructions(t_stacks *s)
{
	char	*line;
	char	**instructions;
	int		i;

	i = 0;
	instructions = ft_calloc(10000, sizeof(char *));
	if (!instructions || !s)
		error_message(s, "Error\n");
	line = get_next_line(0);
	while (line)
	{
		if (i >= 9999 || valid_instruction(line) == 0)
		{
			free_str(instructions);
			free(line);
			error_message(s, "Error\n");
		}
		instructions[i++] = line;
		line = get_next_line(0);
	}
	instructions[i] = NULL;
	execute_instructions(s, instructions);
	free_str(instructions);
}
