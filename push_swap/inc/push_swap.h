/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/11 22:14:41 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		rotate_both_up(t_stacks *s);
void		rotate_both_down(t_stacks *s);

// UTILS
int			greater_than_pivot(int *stack, int size, int pivot);
void		error_message(t_stacks *s, char *msg);
int			is_array_sorted(t_stacks *s);
int			find_max(int *st, int size);
int			find_min(int *st, int size);
void		exit_if_sorted_or_has_duplicate(t_stacks *s, int i);
int			real_moves(char **str);
int			set_moves(char **str, char **dirs, int *moves, int temp_moves);
void		parse_numbers(t_stacks *s);
void		initialize_stacks(int argc, char **argv, t_stacks *s);
void		set_moves_dir(char **str, char *dir, int moves);
void		free_str(char **str);
void		init_pointers(int **moves, char ***dirs, int **count_moves);
void		free_pointers(int *moves, char **dirs, int *count_moves);

// SORT
void		turkish_sort(t_stacks *s);
void		sort_three_elements(t_stacks *s);
int			count_moves_dir(int *stack, int num, char *dir, int size);
void		go_a(t_stacks *s);
void		move_to_stack(char *dir, int moves, t_stacks *s, char stack);
int			move_stack(t_stacks *s, char **dirs, int *moves, char stack);
char		**count_moves_to_stack(t_stacks *s, int pos);
void		order_stack(int *st, int size, char *stack);

// ERROR
int			valid_number(char *str);
int			is_integer(char *str);

#endif