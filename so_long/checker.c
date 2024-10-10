/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:29:25 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/10 20:27:38 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_walls(t_game *game, int height, int width)
{
	int	i;
	int	j;

	j = 0;
	while (j < height)
	{
		if (game->map[j][0] != '1' || game->map[j][width - 1] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i < width)
	{
		if (game->map[0][i] != '1' || game->map[height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	checker(t_game *game, int height, int width)
{
	return (has_walls(game, height, width));
}

int	error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}