/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:46:42 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/24 20:12:02 by lumartin         ###   ########.fr       */
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

static int	init_struct(t_dfs_params *params, int height, int width, int target)
{
	if (target == 0)
	{
		params->visited = allocate_visited(height, width);
		if (!params->visited)
			return (0);
		params->height = height;
		params->width = width;
		params->c_count = 0;
		params->exit = 0;
	}
	params->steps = 0;
	params->perfect = -1;
	return (1);
}

static int	find_optimal_path(t_game *game, int height, int width, int all)
{
	int				total_steps;
	t_dfs_params	params_opt;
	char			**map;
	int				c_player[2];

	c_player[0] = game->player_x;
	c_player[1] = game->player_y;
	map = duplicate(game->map);
	init_struct(&params_opt, height, width, 0);
	if (all == 1)
	{
		total_steps = collect_all_coins(map, c_player, game->collectible_count,
				&params_opt);
		if (total_steps == -1)
			return (0);
		init_struct(&params_opt, height, width, 1);
		dfs_op_exit(map, params_opt.coin_x, params_opt.coin_y, &params_opt);
		if (params_opt.perfect == -1)
			return (0);
		return (total_steps + params_opt.perfect - 1);
	}
	dfs_c_e(map, c_player[0], c_player[1], &params_opt);
	if (params_opt.exit == 0 || params_opt.c_count != game->collectible_count)
		return (0);
	return (1);
}

int	check_connectivity(t_game *game, int height, int width)
{
	int				result;
	t_dfs_params	params;

	result = 1;
	if (!init_struct(&params, height, width, 0))
		return (0);
	if (height + width < 20)
	{
		game->perfect_moves = find_optimal_path(game, height, width, 1);
		if (game->perfect_moves == 0)
			return (0);
		ft_printf("Movimientos óptimos: %d\n", game->perfect_moves);
		free_visited(params.visited, height);
	}
	else
	{
		result = find_optimal_path(game, height, width, 0);
		if (result == 0)
			return (0);
		ft_printf("No hay movimientos óptimos, ¡hazlo lo mejor que puedas!\n");
		free_visited(params.visited, height);
	}
	return (result);
}
