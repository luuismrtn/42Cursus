/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:29:25 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/12 12:09:37 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int line_length(char *line)
{
	int i;
	int sol;

	i = 0;
	sol = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'E' || line[i] == 'P' || line[i] == 'C')
			sol++;
		i++;
	}
		
	return (sol);
}

static int	has_walls(t_game *game, int height, int width)
{
	int	j;
	int	i;

	j = 0;
	while (j < height)
	{
		if (game->map[j][0] != '1' || game->map[j][width - 1] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i < width)
	{
		if (game->map[0][i] != '1' || game->map[height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_rectangular(t_game *game, int width)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (line_length(game->map[i]) != width)
			exit(error("No rectangular"));
		i++;
	}
	return (1);
}

static void	check_number(t_game *game)
{
	int	i;
	int	j;
	int	*counts;

	counts = (int *)malloc(sizeof(int) * 3);
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				counts[0]++;
			}
			else if (game->map[i][j] == 'C')
				counts[1]++;
			else if (game->map[i][j] == 'E')
				counts[2]++;
			j++;
		}
		i++;
	}
	if (counts[0] < 1)
		exit(error("No player"));
	if (counts[0] > 1)
		exit(error("Duplicate player"));
	if (counts[1] == 0)
		exit(error("No object"));
	if (counts[2] < 1)
		exit(error("No exit"));
	if (counts[2] > 1)
		exit(error("Duplicate exit"));
	game->collectible_count = counts[1];
}

void	check_map(t_game *game, char *file_path)
{
	int		fd;
	char	*line;
	int		i;
	char	*ext;
	char	*file_name;

	file_name = ft_strrchr(file_path, '/');
	if (file_name)
		file_name++;
	else
		file_name = file_path;
	ext = ft_strrchr(file_name, '.');
	if (ext == NULL || ft_strncmp(ext, ".ber", 4) != 0 || ext == file_name)
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


int	checker(t_game *game, int height, int width)
{
	if (!check_rectangular(game, width))
		exit(error("Not rectangular"));
	if (!has_walls(game, height, width))
		exit(error("Not surrounded by walls"));
	if (!check_connectivity(game, height, width))
		exit(error("Not connected"));
}

int	error(char *message)
{
	ft_putstr_fd("Error\n", 1);
	if (message)
	{
		ft_putstr_fd(message, 1);
		ft_putstr_fd("\n", 1);
	}
	return (1);
}
