/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:05:42 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/11 22:12:27 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	go_a(t_stacks *s)
{
	int		*count_moves;
	int		i;
	char	**str;
	char	**dirs;
	int		*moves;

	init_pointers(&moves, &dirs, &count_moves);
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
			free_str(str);
		}
		moves[0] = move_stack(s, dirs, moves, 'b');
		move_to_stack(dirs[0], moves[0], s, 'a');
	}
	order_stack(s->a, s->a_size, "a");
	free_pointers(moves, dirs, count_moves);
}

void	init_pointers(int **moves, char ***dirs, int **count_moves)
{
	*moves = malloc(2 * sizeof(int));
	*dirs = malloc(2 * sizeof(char *));
	*count_moves = malloc(2 * sizeof(int));
	if (!*moves || !*dirs || !*count_moves)
	{
		free(*moves);
		free(*dirs);
		free(*count_moves);
		error_message(NULL, "Error en memoria\n");
	}
	(*dirs)[0] = NULL;
	(*dirs)[1] = NULL;
}

void	free_pointers(int *moves, char **dirs, int *count_moves)
{
	free(moves);
	if (dirs)
	{
		free(dirs[0]);
		free(dirs[1]);
		free(dirs);
	}
	free(count_moves);
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
