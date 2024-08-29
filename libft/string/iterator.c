/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:34:16 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/01 14:56:01 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/string.h>

t_iterator_scalar	iterator_scalar_new(t_string string, char scalar)
{
	return ((t_iterator_scalar){
		.scalar = scalar,
		.offset = 0,
		.string = string,
	});
}

static t_string	create_slice(t_iterator_scalar *iter, size_t i, bool dupe)
{
	t_string	str;

	if (dupe)
		str = string_slice(&iter->string, iter->offset, iter->offset + i);
	else
		str = (t_string){&iter->string.ptr[iter->offset], i, i};
	iter->offset += i;
	return (str);
}

t_string	iterator_scalar_next(t_iterator_scalar *iterator, bool dupe)
{
	size_t		i;
	t_string	result;

	if (!iterator || !iterator->string.ptr
		|| iterator->offset > iterator->string.len)
		return ((t_string){0});
	i = 0;
	result = (t_string){0};
	while (i + iterator->offset < iterator->string.len)
	{
		if (iterator->string.ptr[i + iterator->offset] == iterator->scalar)
		{
			i++;
			result = create_slice(iterator, i, dupe);
			break ;
		}
		i++;
	}
	if (!result.ptr && i != 0)
		return (create_slice(iterator, i, dupe));
	return (result);
}
