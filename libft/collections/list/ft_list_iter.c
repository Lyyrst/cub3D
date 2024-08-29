/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:31:01 by mrouault          #+#    #+#             */
/*   Updated: 2024/01/13 13:31:26 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/collections.h>

void	ft_list_iter(t_list *list, void (*f)(void *))
{
	if (!list || !f)
		return ;
	f(list->data);
	list = list->next;
	while (list != NULL)
	{
		f(list->data);
		list = list->next;
	}
}
