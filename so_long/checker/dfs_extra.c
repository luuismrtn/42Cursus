/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:46:42 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/14 02:41:17 by lumartin         ###   ########.fr       */
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

int	**allocate_visited(int height, int width)
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

int	init_struct(t_dfs_params *params, int height, int width)
{
	params->visited = allocate_visited(height, width);
	if (!params->visited)
		return (0);
	params->height = height;
	params->width = width;
	params->c_count = 0;
	params->exit = 0;
	params->steps = 0;
	params->perfect = -1;
	return (1);
}

int	check_connectivity(t_game *game, int height, int width)
{
	int				result;
	t_dfs_params	params;

	result = 1;
	if (!init_struct(&params, height, width))
		return (0);
	game->perfect_moves = find_optimal_path(game, height, width);
	if (game->perfect_moves == 0)
		return (0);
	ft_printf("Movimientos óptimos: %d\n", game->perfect_moves);
	free_visited(params.visited, height);
	return (result);
}
