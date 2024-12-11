/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:05:42 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/11 20:39:03 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_a(t_stacks *s)
{
	int		*count_moves;
	int		i;
	char	**str;
	char	**dirs;
	int		*moves;

	moves = malloc(2 * sizeof(int));
	count_moves = malloc(2 * sizeof(int));
	dirs = malloc(2 * sizeof(char *));
	while (s->b_size != 0)
	{
		count_moves[0] = 10000;
		i = 0;
		while (i < s->b_size)
		{
			str = count_moves_to_stack(s, i);
			count_moves[1] = real_moves(str);
			if (count_moves[1] < count_moves[0])
				count_moves[0] = set_moves(str, dirs, moves, count_moves[1]);
			i++;
		}
		moves[0] = move_stack(s, dirs, moves, 'b');
		move_to_stack(dirs[0], moves[0], s, 'a');
	}
	order_stack(s, s->a, s->a_size, "a");
}

char	**count_moves_to_stack(t_stacks *s, int pos)
{
	char	**str;
	int		num;
	int		moves_up;
	int		moves_down;

	num = s->b[pos];
	moves_up = count_moves_dir(s->a, num, "up", s->a_size);
	moves_down = count_moves_dir(s->a, num, "down", s->a_size);
	str = malloc(4 * sizeof(char *));
	if (pos < s->b_size - pos)
	{
		str[3] = ft_itoa(pos);
		str[2] = ft_strdup("up");
	}
	else
	{
		str[3] = ft_itoa(s->b_size - pos);
		str[2] = ft_strdup("down");
	}
	if (moves_up < moves_down)
		set_moves_dir(str, "up", moves_up);
	else
		set_moves_dir(str, "down", moves_down);
	return (str);
}

void	set_moves_dir(char **str, char *dir, int moves)
{
	str[0] = ft_strdup(dir);
	str[1] = ft_itoa(moves);
}
