/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:17:41 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/12 13:33:55 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "so_long.h"

typedef struct s_dfs_params
{
	int	**visited;
	int	width;
	int	*c_count;
	int	*exit;
}		t_dfs_params;

int		line_length(char *line);
int		error(char *message);
int		*counts_items(t_game *game, int *counts);

#endif