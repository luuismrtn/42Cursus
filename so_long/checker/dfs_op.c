/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:29:52 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/14 02:04:22 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "so_long.h"

void	dfs_op(char **map, int x, int y, t_dfs_params *params)
{
	if (map[y][x] == 'E' || map[y][x] == 'M' || map[y][x] == '1')
		return ;
	if (x < 0 || x >= params->width || y < 0 || y >= params->height || params->visited[y][x])
		return ;
	params->steps++;
    params->visited[y][x] = 1;
	if (map[y][x] == 'C')
	{
		params->c_count++;
		if (params->perfect == -1 || params->steps < params->perfect)
        {
            params->coin_x = x;
            params->coin_y = y;
            params->perfect = params->steps;
        }	
	}
	dfs_op(map, x - 1, y, params);
	dfs_op(map, x, y - 1, params);
    dfs_op(map, x + 1, y, params);
	dfs_op(map, x, y + 1, params);
	params->steps--;
    params->visited[y][x] = 0;
	if (map[y][x] == 'C')
		params->c_count--;
}

void	dfs_op_exit(char **map, int x, int y, t_dfs_params *params)
{
	if (map[y][x] == 'M' || map[y][x] == '1')
		return ;
	if (x < 0 || x >= params->width || y < 0 || y >= params->height || params->visited[y][x])
		return ;
	params->steps++;
    params->visited[y][x] = 1;
	if (map[y][x] == 'E')
	{
		if (params->perfect == -1 || params->steps < params->perfect)
            params->perfect = params->steps;
	}
	dfs_op_exit(map, x - 1, y, params);
	dfs_op_exit(map, x, y - 1, params);
    dfs_op_exit(map, x + 1, y, params);
	dfs_op_exit(map, x, y + 1, params);
	params->steps--;
    params->visited[y][x] = 0;
}

static int find_closest_coin(char **map, int *player_x, int *player_y, t_dfs_params *params)
{
	params->perfect = -1;
	params->steps = 0;

	dfs_op(map, *player_x, *player_y, params);
	if (params->perfect == -1)
		return (0);
    *player_x = params->coin_x;
    *player_y = params->coin_y;
    map[params->coin_y][params->coin_x] = '0';
	return (params->perfect - 1);
}

int collect_all_coins(char **map, int *player_x, int *player_y, int coins, t_dfs_params *params_opt)
{
    int total_steps = 0;
    int steps;

    while (coins > 0)
    {
        allocate_visited(params_opt->height, params_opt->width);
        steps = find_closest_coin(map, player_x, player_y, params_opt);
        if (steps == 0)
            return (-1);
        total_steps += steps;
        coins--;
    }
    return (total_steps);
}

int find_optimal_path(t_game *game, int height, int width)
{
    int total_steps;
    t_dfs_params params_opt;
    char **map;
    int player_x;
    int player_y;
    int coins;

    coins = game->collectible_count;
    player_x = game->player_x;
    player_y = game->player_y;
    map = duplicate(game->map);
    if (!init_struct(&params_opt, height, width))
        return (0);
    total_steps = collect_all_coins(map, &player_x, &player_y, coins, &params_opt);
    if (total_steps == -1)
        return (0);
    params_opt.perfect = -1;
    params_opt.steps = 0;
    dfs_op_exit(map, params_opt.coin_x, params_opt.coin_y, &params_opt);
    if (params_opt.perfect == -1)
        return (0);
    return (total_steps + params_opt.perfect - 1);
}


