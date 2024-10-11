/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:40:54 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/11 13:03:24 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *game, char tile, int x, int y)
{
	int	tile_size;

	tile_size = 64;
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
			* tile_size, y * tile_size);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x
			* tile_size, y * tile_size);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x
			* tile_size, y * tile_size);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
			* tile_size, y * tile_size);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty, x
			* tile_size, y * tile_size);
	else
		exit(error("Invalid map"));
}

static void	draw_map_line(t_game *game, int y)
{
	int	x;

	x = 0;
	while (game->map[y][x] != '\0' && game->map[y][x] != '\n')
	{
		draw_tile(game, game->map[y][x], x, y);
		x++;
	}
}

void	draw_map(t_game *game)
{
	int	y;

	y = 0;
	if (!game || !game->map)
	{
		error("Invalid game");
		return ;
	}
	while (game->map[y] != NULL)
	{
		draw_map_line(game, y);
		y++;
	}
}
