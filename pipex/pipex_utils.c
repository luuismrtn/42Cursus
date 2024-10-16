/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:55:43 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/16 21:48:05 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	open_input_file(char *file1)
{
	int	infile;

	infile = open(file1, O_RDONLY);
	if (infile < 0)
	{
		perror("Error opening file1");
		exit(EXIT_FAILURE);
	}
	return (infile);
}

int	open_output_file(char *file2)
{
	int	outfile;

	outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("Error opening file2");
		exit(EXIT_FAILURE);
	}
	return (outfile);
}

void	first_command(char *file1, char *cmd1, int *fd, char **environ)
{
	int	infile;

	infile = open_input_file(file1);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(infile);
	execute_command(cmd1, environ);
}

void	second_command(char *file2, char *cmd2, int *fd, char **environ)
{
	int	outfile;

	outfile = open_output_file(file2);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(outfile);
	execute_command(cmd2, environ);
}
