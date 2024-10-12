/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:46:42 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/12 13:34:56 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "so_long.h"

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

static void	dfs(t_game *game, int x, int y, t_dfs_params *params)
{
	int	height;

	if (game->map[y][x] == 'E')
	{
		params->exit[0]++;
		params->visited[y][x] = 1;
	}
	else if (game->map[y][x] == 'M')
		params->visited[y][x] = 1;
	height = ft_strlen(game->map[0]) + 1;
	if (x < 0 || x >= params->width || y < 0 || y >= height
		|| params->visited[y][x] || game->map[y][x] == '1')
		return ;
	params->visited[y][x] = 1;
	if (game->map[y][x] == 'C')
		params->c_count[0]++;
	dfs(game, x, y - 1, params);
	dfs(game, x, y + 1, params);
	dfs(game, x - 1, y, params);
	dfs(game, x + 1, y, params);
}

int	check_connectivity(t_game *game, int height, int width)
{
	int				**visited;
	int				result;
	int				*exit;
	int				*c_count;
	t_dfs_params	params;

	exit = (int *)malloc(sizeof(int));
	c_count = (int *)malloc(sizeof(int));
	exit[0] = 0;
	c_count[0] = 0;
	visited = allocate_visited(height, width);
	if (!visited)
		return (0);
	params.visited = visited;
	params.width = width;
	params.c_count = c_count;
	params.exit = exit;
	dfs(game, game->player_x, game->player_y, &params);
	result = (c_count[0] == game->collectible_count && exit[0] > 0);
	free_visited(visited, height);
	free(exit);
	free(c_count);
	return (result);
}
