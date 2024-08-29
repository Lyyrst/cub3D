/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convert_other.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:18:19 by mrouault          #+#    #+#             */
/*   Updated: 2024/02/21 16:56:25 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_convert_string(t_string *buffer, char *str)
{
	if (!str)
		return (string_append(buffer, "(null)"));
	else
		return (string_append(buffer, str));
}

int	printf_convert_pointer(t_string *buffer, void *ptr)
{
	t_string	tmp;

	if (ptr == NULL)
		return (string_append(buffer, "(nil)"));
	tmp = ft_utoa_base((uint64_t)ptr, HEX_BASE, 16);
	if (tmp.ptr == NULL)
		return (STRING_ALLOC_FAILURE);
	if (string_append(buffer, "0x") != STRING_ALLOC_SUCCESS)
		return (STRING_ALLOC_FAILURE);
	return (string_append_string(buffer, &tmp, true));
}

int	printf_convert_float(t_string *buffer, double f)
{
	t_string	tmp;

	tmp = ft_ftoa(f);
	if (!tmp.ptr)
		return (STRING_ALLOC_FAILURE);
	return (string_append_string(buffer, &tmp, true));
}

int	printf_convert_float_hex(t_string *buffer, double f)
{
	const uint64_t	cast = *(uint64_t*)&f;
	t_string		tmp;

	tmp = ft_utoa_base(cast, HEX_BASE, 16);
	if (!tmp.ptr)
		return (STRING_ALLOC_FAILURE);
	return (string_append_string(buffer, &tmp, true));
}
