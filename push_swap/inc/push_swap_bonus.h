/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2025/01/30 15:43:22 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

// MOVE
void		rotate(int *array, int size, char *direction);
void		swap(int *array, int size);
void		push(char *str, t_stacks *s);
void		rotate_both_up(t_stacks *s);
void		rotate_both_down(t_stacks *s);

// UTILS
int			is_array_sorted(t_stacks *s);
void		parse_numbers(t_stacks *s);
void		initialize_stacks(int argc, char **argv, t_stacks *s);
void		free_str(char **str);

// ERROR
void		error_message(t_stacks *s, char *msg);
int			valid_number(char *str);
int			is_integer(char *str);

void		read_instructions(t_stacks *s);
int			valid_instruction(char *line);

#endif