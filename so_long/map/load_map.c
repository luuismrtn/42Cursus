/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:03:08 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/11 00:47:18 by lumartin         ###   ########.fr       */
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
	len = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line)
	{
		free(line);
		line_count++;
		line = get_next_line(fd);
		if (line)
		{
			if (len != ft_strlen(line))
				exit(error("No rectangular"));
		}
	}
	close(fd);
	return (line_count);
}


static void check_number(t_game *game)
{
	int	i;
	int	j;
	int	*counts;

	counts = (int *)malloc(sizeof(int) * 3);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				counts[0]++;
			else if (game->map[i][j] == 'C')
				counts[1]++;
			else if (game->map[i][j] == 'E')
				counts[2]++;
			j++;
		}
		i++;
	}
	if (counts[0] < 1)
		error("No player");
	if (counts[0] > 1)
		error("Duplicate player");
	if (counts[1] == 0)
		error("No object");
	if (counts[2] < 0)
		error("No exit");
	if (counts[2] > 1)
		error("Duplicate exit");

	game->collectible_count = counts[1];
	
}

static void	check_map(t_game *game, char *file_path)
{
	int		fd;
	char	*line;
	int		i;
	int		line_count;
	char	*ext;

	ext = ft_strrchr(file_path, '.');
	if (ext == NULL || ft_strncmp(ext, ".ber", 4) != 0)
		exit(error("Bad extension"));
	i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		exit(error("Error opening file"));
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
	check_number(game);
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
