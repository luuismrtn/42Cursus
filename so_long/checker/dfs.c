/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:46:42 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/13 21:04:22 by lumartin         ###   ########.fr       */
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
			visited[i][j++] = 0;
		i++;
	}
	return (visited);
}

static void	check_shortest_path(t_dfs_params *params, int c_count, int steps)
{
	if (c_count == params->c_count[0] && params->exit[0] > 0)
	{
		if (params->perfect == -1 || steps < params->perfect)
			params->perfect = steps;
	}
}

void	print_visited(int **visited, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("Visited:\n");
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_printf("%d", visited[i][j]);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

static void	choose_direction(t_game *game, int x, int y, t_dfs_params *params)
{
	ft_putstr_fd("Posible dirección IZQUIERDA: ", 1);
	ft_putchar_fd(game->map[y][x - 1], 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Posible dirección ARRIBA: ", 1);
	ft_putchar_fd(game->map[y - 1][x], 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Posible dirección DERECHA: ", 1);
	ft_putchar_fd(game->map[y][x + 1], 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Posible dirección ABAJO: ", 1);
	ft_putchar_fd(game->map[y + 1][x], 1);
	ft_putchar_fd('\n', 1);
	if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
	{
		ft_putstr_fd("Izquierda.\n", 1);
		dfs(game, x - 1, y, params);
	}
	if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
	{
		ft_putstr_fd("Arriba.\n", 1);
		dfs(game, x - 1, y, params);
	}
	if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
	{
		ft_putstr_fd("Derecha.\n", 1);
		dfs(game, x, y + 1, params);
	}
	if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
	{
		ft_putstr_fd("Abaj.\n", 1);
		dfs(game, x + 1, y, params);
	}
}

void	dfs(t_game *game, int x, int y, t_dfs_params *params)
{
	if (params->perfect != -1 && params->steps >= params->perfect)
		return ;
	if (game->map[y][x] == 'E')
	{
		params->exit[0]++;
		params->visited[y][x] = 1;
	}
	else if (game->map[y][x] == 'M')
		return ;
	ft_putstr_fd("X: ", 1);
	ft_putnbr_fd(x, 1);
	ft_putstr_fd(" Y: ", 1);
	ft_putnbr_fd(y, 1);
	ft_putchar_fd('\n', 1);
	print_visited(params->visited, params->height, params->width);
	if (x <= 0 || x >= params->width || y <= 0 || y >= params->height
		|| game->map[y][x] == '1')
		return ;
	params->visited[y][x] = 1;
	params->steps++;
	if (game->map[y][x] == 'C')
		params->c_count[0]++;
	if (game->map[y][x] == 'E')
	{
		ft_putstr_fd("Se ha encontrado un camino válido.\n", 1);
		check_shortest_path(params, params->c_count[0], params->steps);
	}
	choose_direction(game, x, y, params);
	params->visited[y][x] = 0;
	params->steps--;
	if (game->map[y][x] == 'C')
		params->c_count[0]--;
	if (game->map[y][x] == 'E')
		params->exit[0]--;
}

int	check_connectivity(t_game *game, int height, int width)
{
	int				**visited;
	int				result;
	int				*exit;
	int				*c_count;
	t_dfs_params	params;

	params.perfect = -1;
	params.steps = 0;
	exit = (int *)malloc(sizeof(int));
	c_count = (int *)malloc(sizeof(int));
	exit[0] = 0;
	c_count[0] = 0;
	visited = allocate_visited(height, width);
	if (!visited)
		return (0);
	params.visited = visited;
	params.width = width;
	params.height = height;
	params.c_count = c_count;
	params.exit = exit;
	dfs(game, game->player_x, game->player_y, &params);
	result = (c_count[0] == game->collectible_count && exit[0] > 0);
	if (params.perfect != -1)
		ft_printf("CAMINO CORTO %d pasos\n", params.perfect);
	else
		ft_printf("No se ha encontrado un camino válido.\n");
	free_visited(visited, height);
	free(exit);
	free(c_count);
	return (result);
}
