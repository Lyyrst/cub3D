/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:27:09 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/01 14:55:50 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/string.h>

void	string_pad(t_string *str, size_t max, char c)
{
	size_t	i;

	if (str->len >= max)
		return ;
	if (str->cap < max)
		string_grow(str, max + 1);
	i = str->len;
	while (i < max)
	{
		string_append_char(str, c);
		i++;
	}
}
