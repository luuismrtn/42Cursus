/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:51:35 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/12 14:11:11 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keycode, t_game *game)
{
	if (keycode == 119)
		move_player(game, -1, 0);
	else if (keycode == 97)
		move_player(game, 0, -1);
	else if (keycode == 115)
		move_player(game, 1, 0);
	else if (keycode == 100)
		move_player(game, 0, 1);
	else if (keycode == 65307)
		close_game(game);
	draw_move_counter(game);
	return (0);
}

static int	update_frame(t_game *game)
{
	animate_sprites(game);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	exit(0);
}

void	init_game(t_game *game, int height, int width)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 64 * width, 64 * height, "so_long");
	game->moves = 0;
	game->current_frame = 0;
	load_images(game);
	draw_map(game);
	draw_move_counter(game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		*map_size;

	if (argc != 2)
		return (error("Wrong number of arguments"));
	map_size = load_map(&game, argv[1]);
	if (!checker(&game, map_size[0], map_size[1]))
		return (1);
	init_game(&game, map_size[0], map_size[1]);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, update_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
