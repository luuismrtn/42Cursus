/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:03:08 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/24 20:31:44 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_lines(char *file_path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		exit(error("Error opening file"));
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line_count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

void	draw_enemy(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, x * 64, y
		* 64);
}

void	draw_move_counter(t_game *game)
{
	char	move_str[20];

	sprintf(move_str, "Movimientos: %d", game->moves);
	mlx_string_put(game->mlx, game->win, 30, 30, 0xFFFFFF, move_str);
}

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->img_player[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_00.xpm", &width, &height);
	game->img_player[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_01.xpm", &width, &height);
	game->img_player[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_02.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectible.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&width, &height);
	game->img_empty = mlx_xpm_file_to_image(game->mlx, "./textures/empty.xpm",
			&width, &height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./textures/enemy.xpm",
			&width, &height);
	if (!game->img_player[0] || !game->img_wall || !game->img_collectible
		|| !game->img_exit || !game->img_empty || !game->img_enemy)
		exit(error("Failed to load images"));
}

int	*load_map(t_game *game, char *file_path)
{
	int	*map_size;
	int	line_count;

	game->collectible_count = 0;
	map_size = (int *)malloc(sizeof(int) * 2);
	if (!map_size)
		exit(error("Error allocating memory"));
	line_count = count_lines(file_path);
	game->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!game->map)
		exit(error("Error allocating memory"));
	game->player_x = -1;
	game->player_y = -1;
	check_map(game, file_path);
	map_size[0] = line_count;
	map_size[1] = ft_strlen(game->map[0]) - 1;
	return (map_size);
}
