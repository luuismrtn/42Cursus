/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:45:58 by lumartin          #+#    #+#             */
/*   Updated: 2024/09/20 16:50:17 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return;

    if (*lst == NULL)
    {
        *lst = new;
    }
    else
    {
        t_list *last = ft_lstlast(*lst);
        last->next = new;
    }
    new->next = NULL;
}
