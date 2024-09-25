/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:03:15 by lumartin          #+#    #+#             */
/*   Updated: 2024/09/25 19:30:09 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *line;
    char c;
    int i;

    line = malloc(1000);
    if (!line)
        return (NULL);
    i = 0;
    if (!read(fd, &c, 1))
    {
        free(line);
        return (NULL);
    }
    else
    {
        line[i] = c;
        i++;
    }
    while (read(fd, &c, 1) && c != '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return (line);
}

//cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.
/*
#include <fcntl.h>
int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
            return (1);
        line = get_next_line(fd);
        printf("%s\n", line);
        free(line);
        close(fd);
    }
    return (0);
}
*/