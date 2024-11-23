/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/11/23 22:59:59 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(t_stacks *s, char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	if (s != NULL)
	{
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s->join_args != NULL)
			free(s->join_args);
		if (s != NULL)
			free(s);
	}
	exit(1);
}

static void	check_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		error_message(NULL, "");
	while (i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
			error_message(NULL, "Error\n");
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
					&& (argv[i][j] != '-' && argv[i][j] != '+'
						&& argv[i][j] != ' ')) || (argv[i][j] == '-'
					&& argv[i][j + 1] == '\0') || (argv[i][j] == '+'
					&& argv[i][j + 1] == '\0') || (argv[i][j] == '-'
					&& argv[i][j + 1] == ' ') || (argv[i][j] == '+' && argv[i][j
					+ 1] == ' '))
				error_message(NULL, "Error\n");
			j++;
		}
		++i;
	}
}

void	join_args(int argc, char **argv, t_stacks *s)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	s->join_args = ft_strdup(tmp);
	if (s->join_args == NULL)
		error_message(s, "Error JOIN_ARGS = NULL\n");
	if (tmp)
		free(tmp);
	parse_numbers(s);
}

static void	choose_sort(t_stacks *s)
{
	if (s->a_size == 2)
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		sort_three_elements(s);
	else
		turkish_sort(s);
}

int	main(int argc, char **argv)
{
	t_stacks	*s;

	check_arguments(argc, argv);
	s = malloc(sizeof *s);
	if (s == NULL)
		exit(1);
	initialize_stacks(argc, argv, s);
	join_args(argc, argv, s);
	choose_sort(s);
	exit_if_sorted_or_has_duplicate(s, 1);
	error_message(s, "Error NO SORTED\n");
	return (0);
}
