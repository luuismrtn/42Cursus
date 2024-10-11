/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:18:53 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/11 12:12:00 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		player_x;
	int		player_y;
	int		collectible_count;
	int		moves;
	void	*img_player;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	void	*img_empty;
}			t_game;

void		init_game(t_game *game, int height, int width);
void		draw_map(t_game *game);
int			handle_input(int keycode, t_game *game);
int			close_game(t_game *game);
void		move_player(t_game *game, int x, int y);
int			*load_map(t_game *game, char *file_path);
int			error(char *message);
void		draw_map(t_game *game);
void		check_map(t_game *game, char *file_path);
void		move_player(t_game *game, int y_offset, int x_offset);
int			check_connectivity(t_game *game, int height, int width);

#endif
