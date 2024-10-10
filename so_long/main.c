/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:51:35 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/11 00:12:04 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, int height, int width)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 64 * width, 64 * height, "so_long");
	game->moves = 0;
	load_images(game);
	draw_map(game);
}

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->img_player = mlx_xpm_file_to_image(game->mlx, "./tiles/player.xpm",
			&width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./tiles/wall.xpm",
			&width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./tiles/collectible.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./tiles/exit.xpm",
			&width, &height);
	game->img_empty = mlx_xpm_file_to_image(game->mlx, "./tiles/empty.xpm",
			&width, &height);
	if (!game->img_player || !game->img_wall || !game->img_collectible
		|| !game->img_exit || !game->img_empty)
		exit(error("Failed to load images"));
}

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
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		*map_size;

	if (argc != 2)
		return (error("Wrong number of arguments"));
	map_size = load_map(&game, argv[1]);
    if (map_size[0] == map_size[1])
        return (error("No rectangular"));
    if (!checker(&game, map_size[0], map_size[1]))
        return (error("Invalid map"));
	init_game(&game, map_size[0], map_size[1]);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
