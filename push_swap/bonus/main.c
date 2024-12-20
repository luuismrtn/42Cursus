/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/20 14:59:26 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (i < 4)
	{
		free(str[i]);
		i++;
	}
	free(str);
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

static void	join_args(int argc, char **argv, t_stacks *s)
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

int	main(int argc, char **argv)
{
	t_stacks	*s;

	check_arguments(argc, argv);
	s = malloc(sizeof(*s));
	if (s == NULL)
		exit(1);
	initialize_stacks(argc, argv, s);
	join_args(argc, argv, s);
	read_instructions(s);
	if (is_array_sorted(s))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
