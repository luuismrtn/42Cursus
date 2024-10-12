/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:51:35 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/12 13:14:38 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->img_player[0] = mlx_xpm_file_to_image(game->mlx,
			"./tiles/player_00.xpm", &width, &height);
	game->img_player[1] = mlx_xpm_file_to_image(game->mlx,
			"./tiles/player_01.xpm", &width, &height);
	game->img_player[2] = mlx_xpm_file_to_image(game->mlx,
			"./tiles/player_02.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./tiles/wall.xpm",
			&width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./tiles/collectible.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./tiles/exit.xpm",
			&width, &height);
	game->img_empty = mlx_xpm_file_to_image(game->mlx, "./tiles/empty.xpm",
			&width, &height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./tiles/enemy.xpm",
			&width, &height);
	if (!game->img_player[0] || !game->img_wall || !game->img_collectible
		|| !game->img_exit || !game->img_empty || !game->img_enemy)
		exit(error("Failed to load images"));
}

void	draw_enemy(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, x * 64, y
		* 64);
}

static void draw_move_counter(t_game *game)
{
    char move_str[20];
    sprintf(move_str, "Movimientos: %d", game->moves);

    mlx_string_put(game->mlx, game->win, 30, 30, 0xFFFFFF, move_str);
}

static void animate_sprites(t_game *game)
{
    int y;
    int x;
	int fps;

	fps = 144 * 50;
    if (game->current_frame++ % fps == 0)
    {
        mlx_put_image_to_window(game->mlx, game->win,
            game->img_player[(game->current_frame / fps) % 3],
            game->player_x * 64, game->player_y * 64);
        y = 0;
        while (game->map[y] != NULL)
        {
            x = 0;
            while (game->map[y][x] != '\0')
            {
                if (game->map[y][x] == 'M')
                    draw_enemy(game, x, y);
                x++;
            }
            y++;
        }
    }
    if (game->current_frame >= fps * 3)
        game->current_frame = 0;
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
