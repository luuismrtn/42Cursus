/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/11/24 16:30:19 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
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

void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		sort_three_elements(t_stacks *s);
void		parse_numbers(t_stacks *s);
void		initialize_stacks(int argc, char **argv, t_stacks *s);
void		error_message(t_stacks *s, char *msg);
void		exit_if_sorted_or_has_duplicate(t_stacks *s, int i);
int			is_array_sorted(t_stacks *s);
int			find_max(int *st, int size);
int			find_min(int *st, int size);
int			count_moves_dir(int *stack, int num, char *dir, int size);
void		print_stack(t_stacks *stack, char letter);
char		**count_moves_to_b(t_stacks *s, int pos);
void		moves_to_a(t_stacks *s);
void		rotate_both_up(t_stacks *s, int size, char *list);
void		rotate_both_down(t_stacks *s, int size, char *list);

#endif