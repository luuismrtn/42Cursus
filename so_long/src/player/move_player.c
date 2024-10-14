/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:46:08 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/14 03:12:37 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines_game(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y] != NULL)
		y++;
	return (y);
}

static void	update_map(t_game *game, int y, int x)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);
}

void	move_player(t_game *game, int y_offset, int x_offset)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + x_offset;
	new_y = game->player_y + y_offset;
	if (new_y < 0 || new_y >= count_lines_game(game) || new_x < 0
		|| new_x >= (int)ft_strlen(game->map[0]))
		return ;
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collectible_count--;
		if (game->map[new_y][new_x] == 'E' && game->collectible_count == 0)
		{
			if (game->moves <= game->perfect_moves)
				ft_putstr_fd("¡Has ganado!\n", 1);
			else
				ft_putstr_fd("¡Has perdido! Intenta buscar un camino mejor\n",
					1);
			close_game(game);
		}
		update_map(game, new_y, new_x);
		draw_map(game);
	}
}
