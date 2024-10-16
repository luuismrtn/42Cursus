/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:23:39 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/16 22:07:55 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_env(char **environ)
{
	int	i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strnstr(environ[i], "PATH=",
				ft_strlen(environ[i])) == environ[i])
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*get_path(char *cmd, char **env)
{
	char	*exec;
	char	**all_path;
	char	**s_cmd;
	char	*path_part;
	int		i;

	i = 0;
	all_path = ft_split(get_env(env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (all_path[i])
	{
		path_part = ft_strjoin(all_path[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(s_cmd);
			return (exec);
		}
		free(exec);
		i++;
	}
	ft_free_tab(all_path);
	ft_free_tab(s_cmd);
	return (cmd);
}

void	execute_command(char *cmd, char **environ)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], environ);
	if (execve(path, s_cmd, environ) == -1)
	{
		ft_putstr_fd("PIPEX: command not found: ", 2);
		ft_putstr_fd(s_cmd[0], 2);
		ft_putstr_fd("\n", 2);
		ft_free_tab(s_cmd);
		exit(0);
	}
}

static void	pipex(char **argv, char **environ)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		first_command(argv[1], argv[2], fd, environ);
	second_command(argv[4], argv[3], fd, environ);
}

int	main(int argc, char **argv, char **environ)
{
	if (argc != 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	pipex(argv, environ);
	return (0);
}
