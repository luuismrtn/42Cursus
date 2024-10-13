/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:15:59 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/13 17:43:40 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "so_long.h"

int	line_length(char *line)
{
	int	i;
	int	sol;

	i = 0;
	sol = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'E' || line[i] == 'P'
			|| line[i] == 'C' || line[i] == 'M')
			sol++;
		i++;
	}
	return (sol);
}

int	*counts_items(t_game *game, int *counts)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				counts[0]++;
			}
			else if (game->map[i][j] == 'C')
				counts[1]++;
			else if (game->map[i][j] == 'E')
				counts[2]++;
			j++;
		}
		i++;
	}
	return (counts);
}

int	error(char *message)
{
	ft_putstr_fd("Error\n", 1);
	if (message)
	{
		ft_putstr_fd(message, 1);
		ft_putstr_fd("\n", 1);
	}
	return (1);
}
