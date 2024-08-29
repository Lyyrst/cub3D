/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:30:01 by mrouault          #+#    #+#             */
/*   Updated: 2024/01/13 13:30:01 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/collections.h>

void	ft_list_add_front(t_list **list, t_list *new)
{
	t_list	*tmp;

	tmp = *list;
	*list = new;
	new->next = tmp;
}

void	ft_list_add_back(t_list **list, t_list *new)
{
	t_list	*tmp;

	if (!list)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	tmp = ft_list_last(*list);
	tmp->next = new;
}
