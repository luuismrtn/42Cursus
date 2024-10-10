/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:03:08 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/10 23:34:48 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *file_path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo del mapa");
		exit(1);
	}
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

static void	check_players(t_game *game, int i, int j)
{
	if (game->player_x != -1 || game->player_y != -1)
		exit(error());
	game->player_x = j;
	game->player_y = i;
}

static void	check(char *line, t_game *game, int i)
{
	int	j;

	j = 0;
	j = 0;
	while (line[j++])
	{
		if (line[j] == 'P')
			check_players(game, i, j);
		else if (line[j] == 'C')
			game->collectible_count = game->collectible_count + 1;
			
	}
}

static void	check_map(t_game *game, char *file_path)
{
	int		fd;
	char	*line;
	int		i;
	int		line_count;

	i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		exit(error());
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = line;
		check(line, game, i);
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}

int	*load_map(t_game *game, char *file_path)
{
	int		*map_size;
	int		fd;
	char	*line;
	int		line_count;

	game->collectible_count = 0;
	map_size = (int *)malloc(sizeof(int) * 2);
	if (!map_size)
		exit(error());
	line_count = count_lines(file_path);
	game->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!game->map)
		exit(error());
	game->player_x = -1;
	game->player_y = -1;
	check_map(game, file_path);
	map_size[0] = line_count;
	map_size[1] = ft_strlen(game->map[0]) - 1;

	return (map_size);
}
