/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:40 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/10 00:41:05 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_stacks *st)
{
	int	f;
	int	s;
	int	t;

	f = st->a[0];
	s = st->a[1];
	t = st->a[2];
	if (f > s && f > t && s < t)
		rotate(st->a, st->a_size, "up", "a");
	else if (f > s && f > t && s > t)
	{
		rotate(st->a, st->a_size, "up", "a");
		swap("sa", st->a, st->a_size);
	}
	else if (f < s && f > t)
		rotate(st->a, st->a_size, "down", "a");
	else if (f > s && f < t)
		swap("sa", st->a, st->a_size);
	else if (f < s && f < t && s > t)
	{
		rotate(st->a, st->a_size, "down", "a");
		swap("sa", st->a, st->a_size);
	}
}

int	is_array_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
