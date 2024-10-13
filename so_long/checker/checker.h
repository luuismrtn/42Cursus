/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:17:41 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/13 20:22:13 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "so_long.h"

typedef struct s_dfs_params
{
	int	**visited;
	int	*exit;
	int	*c_count;
	int	width;
	int	height;
	int	steps;
	int	perfect;
}		t_dfs_params;

int		line_length(char *line);
int		error(char *message);
int		*counts_items(t_game *game, int *counts);
void	dfs(t_game *game, int x, int y, t_dfs_params *params);

#endif