/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:33:09 by mrouault          #+#    #+#             */
/*   Updated: 2024/01/13 13:33:49 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/collections.h>
#include <stdlib.h>

void	ft_list_del_one(t_list *list, void (*del)(void *))
{
	if (!list || !del)
		return ;
	del(list->data);
	free(list);
}
