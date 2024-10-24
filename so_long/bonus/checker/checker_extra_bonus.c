/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_extra_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:15:59 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/24 20:00:02 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "so_long_bonus.h"

int	line_length(char *line)
{
	int	i;
	int	sol;

	i = 0;
	sol = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
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

char	**duplicate(char **map)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map[i])
		i++;
	new_map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			while (i > 0)
				free(new_map[--i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
