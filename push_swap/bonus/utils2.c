/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:06:30 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/19 16:34:50 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (i < 4)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
