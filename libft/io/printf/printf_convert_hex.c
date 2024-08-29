/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convert_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:20:27 by mrouault          #+#    #+#             */
/*   Updated: 2024/01/31 08:56:31 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_convert_hex(t_string *buffer, unsigned int n)
{
	t_string	tmp;

	tmp = ft_utoa_base(n, HEX_BASE, 16);
	if (tmp.ptr == NULL)
		return (STRING_ALLOC_FAILURE);
	return (string_append_string(buffer, &tmp, true));
}

int	printf_convert_hex_upper(t_string *buffer, unsigned int n)
{
	t_string	tmp;

	tmp = ft_utoa_base(n, HEX_BASE_UPPER, 16);
	if (tmp.ptr == NULL)
		return (STRING_ALLOC_FAILURE);
	return (string_append_string(buffer, &tmp, true));
}
