/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:46:08 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/11 19:32:04 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int count_lines(t_game *game)
{
	int count;
	
	count = 0;
	while (game->map[count])
	{
		count++;
	}
	return (count);
}

void	move_player(t_game *game, int y_offset, int x_offset)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + x_offset;
	new_y = game->player_y + y_offset;
	if (new_y < 0 || new_y >= count_lines(game) || new_x < 0
		|| new_x >= ft_strlen(game->map[0]))
		return ;
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collectible_count--;
		if (game->map[new_y][new_x] == 'E' && game->collectible_count == 0)
		{
			ft_putstr_fd("¡Has ganado!\n", 1);
			close_game(game);
		}
		game->map[game->player_y][game->player_x] = '0';
		game->map[new_y][new_x] = 'P';
		game->player_x = new_x;
		game->player_y = new_y;
		game->moves++;
		printf("Movimientos: %d\n", game->moves);
		draw_map(game);
	}
}
