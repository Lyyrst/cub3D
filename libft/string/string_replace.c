/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:28:22 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/01 14:55:45 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/string.h>

void	string_replace_char(t_string *str, char to_find, char to_replace)
{
	size_t	i;

	i = 0;
	while (i < str->len)
	{
		if (str->ptr[i] == to_find)
			str->ptr[i] = to_replace;
		i++;
	}
}
