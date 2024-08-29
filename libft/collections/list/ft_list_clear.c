/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:34:25 by mrouault          #+#    #+#             */
/*   Updated: 2024/01/13 13:34:27 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/collections.h>
#include <stdlib.h>

void	ft_list_clear(t_list **list, void (*del)(void *))
{
	t_list	*n;

	if (!del)
		return ;
	while (list && *list)
	{
		del((*list)->data);
		n = (*list)->next;
		free(*list);
		*list = n;
	}
}
