/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:17:41 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/24 20:14:25 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "so_long_bonus.h"

typedef struct s_dfs_params
{
	int	**visited;
	int	exit;
	int	c_count;
	int	width;
	int	height;
	int	steps;
	int	perfect;
	int	coin_x;
	int	coin_y;
}		t_dfs_params;

char	**duplicate(char **map);
int		line_length(char *line);
int		*counts_items(t_game *game, int *counts);
int		**allocate_visited(int height, int width);
void	dfs_c_e(char **map, int x, int y, t_dfs_params *params);
int		collect_all_coins(char **map, int *c_player, int coins,
			t_dfs_params *params_opt);
void	dfs_op_exit(char **map, int x, int y, t_dfs_params *params);

#endif