/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:03:08 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/11 12:02:28 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *file_path)
{
	int		fd;
	char	*line;
	int		line_count;
	int		len;

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

int	*load_map(t_game *game, char *file_path)
{
	int		*map_size;
	int		fd;
	char	*line;
	int		line_count;

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
