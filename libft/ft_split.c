/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-linux <luis-linux@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:24:37 by irrevuel          #+#    #+#             */
/*   Updated: 2024/09/20 15:45:54 by luis-linux       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordsize(int n, char const *s, char c)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	len = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
			{
				if (n + 1 == count)
					len++;
				i++;
			}
		}
	}
	return (len);
}

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	**ft_savespace(char const *s, char c)
{
	int		i;
	int		size;
	char	**esplit;

	i = 0;
	size = ft_wordcount(s, c);
	esplit = malloc(sizeof(char *) * (size + 1));
	if (!esplit)
		return (NULL);
	while (i <= size)
	{
		esplit[i] = malloc(sizeof(char) * (ft_wordsize(i, s, c) + 1));
		if (!esplit[i])
			return (NULL);
		i++;
	}
	return (esplit);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	split = ft_savespace(s, c);
	if (!split)
		return (NULL);
	while (s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		if (s[k] != c && s[k] != '\0')
		{
			j = 0;
			while (s[k] != c && s[k] != '\0')
				split[i][j++] = s[k++];
			split[i][j] = '\0';
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}
