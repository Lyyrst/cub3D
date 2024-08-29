/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:33:50 by mrouault          #+#    #+#             */
/*   Updated: 2024/01/31 09:12:33 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/strconv.h>

t_string	ft_itoa(int n)
{
	return (ft_itoa_base(n, DEC_BASE, 10));
}

t_string	ft_itoa_base(int n, const char *base, int radix)
{
	t_string	str;

	if (n < 0)
	{
		str = ft_utoa_base((uint64_t)(-n), base, radix);
		if (str.ptr)
			string_insert_char(&str, '-', 0);
	}
	else
		str = ft_utoa_base((uint64_t)n, base, radix);
	return (str);
}
