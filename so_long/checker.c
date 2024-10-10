/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:29:25 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/11 00:07:10 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	dfs(t_game *game, int x, int y, int **visited, int width,
		int c_count)
{
	int	height;

	height = ft_strlen(game->map);
	if (x < 0 || x >= width || y < 0 || y >= height || visited[y][x] || game->map[y][x] == '1')
		return (c_count);
	visited[y][x] = 1;
	if (game->map[y][x] == 'C')
		c_count++;
	c_count = dfs(game, x, y - 1, visited, width, c_count);
	c_count = dfs(game, x, y + 1, visited, width, c_count);
	c_count = dfs(game, x - 1, y, visited, width, c_count);
	c_count = dfs(game, x + 1, y, visited, width, c_count);
	return (c_count);
}

static void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static int	**allocate_visited(int height, int width)
{
	int	**visited;
	int	i;
	int	j;

	visited = (int **)malloc(sizeof(int *) * height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = (int *)malloc(sizeof(int) * width);
		if (!visited[i])
		{
			free_visited(visited, i);
			return (NULL);
		}
		j = 0;
		while (j < width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}

static int	check_connectivity(t_game *game, int height, int width)
{
	int	**visited;
	int	c_count;
	int	result;

	visited = allocate_visited(height, width);
	if (!visited)
		return (0);
	c_count = dfs(game, game->player_x, game->player_y, visited, width, 0);
	result = (c_count == game->collectible_count);
	free_visited(visited, height);
	return (result);
}

int	checker(t_game *game, int height, int width)
{
	return (has_walls(game, height, width) && check_connectivity(game, height,
			width));
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
