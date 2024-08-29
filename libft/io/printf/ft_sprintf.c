/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:04:25 by mrouault          #+#    #+#             */
/*   Updated: 2024/03/18 15:22:24 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft/string.h>

t_string	ft_sprintf(const char *format, ...)
{
	va_list	args;
	int		ret;
	char	*buffer;

	if (!format)
		return ((t_string){0});
	va_start(args, format);
	ret = ft_vsprintf(&buffer, format, args);
	va_end(args);
	if (ret == -1)
		return ((t_string){0});
	return (string_new_owned(buffer));
}
