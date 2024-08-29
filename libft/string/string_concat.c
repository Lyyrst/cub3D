/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:44:41 by mrouault          #+#    #+#             */
/*   Updated: 2024/03/18 15:19:07 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/string.h>

t_string	string_concat(t_string *s1, t_string *s2, char destroy)
{
	t_string	result;

	result = string_new_capacity(s1->len + s2->len + 1);
	string_append_string(&result, s1, destroy >> 1 & 0b01);
	string_append_string(&result, s2, destroy & 0b01);
	return (result);
}
