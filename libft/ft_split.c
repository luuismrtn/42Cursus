/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 02:35:34 by lumartin          #+#    #+#             */
/*   Updated: 2024/09/19 17:56:04 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_str(const char *str, char c, char **sol)
{
	int	s;
	int	i;
	int	j;
	int	start;

	s = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && c == str[i])
			i++;
		start = i;
		while (str[i] != '\0' && c != str[i])
			i++;
		if (start < i)
		{
			sol[s] = malloc(sizeof(char) * (i - start + 2));
			j = 0;
			while (start < i)
				sol[s][j++] = str[start++];
			sol[s][j] = '\0';
			s++;
		}
		sol[s] = 0;
	}
}

char	**ft_split(char const *str, char c)
{
	char	**sol;
	int		i;
	int		s;

	if (!str || !c)
		return (NULL);
	i = 0;
	s = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			s++;
		i++;
	}
	sol = malloc(sizeof(char *) * (s + 2));
	if (!sol)
		return (NULL);
	fill_str(str, c, sol);
	return (sol);
}
