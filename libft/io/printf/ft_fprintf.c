/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:52:28 by mrouault          #+#    #+#             */
/*   Updated: 2024/01/31 08:55:57 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		ret;
	char	*buffer;

	if (!format)
		return (-1);
	va_start(args, format);
	ret = ft_vsprintf(&buffer, format, args);
	if (ret != -1)
	{
		write(fd, buffer, ret);
		free(buffer);
	}
	va_end(args);
	return (ret);
}
