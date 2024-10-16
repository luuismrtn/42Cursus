/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:25:48 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/16 21:44:55 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	execute_command(char *cmd, char **environ);
int		open_input_file(char *file1);
int		open_output_file(char *file2);
void	first_command(char *file1, char *cmd1, int *fd, char **environ);
void	second_command(char *file2, char *cmd2, int *fd, char **environ);
void	ft_free_tab(char **tab);

#endif
