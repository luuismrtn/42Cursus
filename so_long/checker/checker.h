/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:17:41 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/14 02:26:22 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "so_long.h"

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

void	dfs_op(char **map, int x, int y, t_dfs_params *params);
int		line_length(char *line);
int		error(char *message);
int		*counts_items(t_game *game, int *counts);
int		init_struct(t_dfs_params *params, int height, int width);
int		find_optimal_path(t_game *game, int height, int width);
int		**allocate_visited(int height, int width);
char	**duplicate(char **map);

#endif