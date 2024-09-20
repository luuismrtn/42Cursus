/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:59:44 by lumartin          #+#    #+#             */
/*   Updated: 2024/09/20 21:07:23 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*sol;
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	sol = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&sol, del);
			return (NULL);
		}
		if (!sol)
			sol = new;
		else
			tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	return (sol);
}
