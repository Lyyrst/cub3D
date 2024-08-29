/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:22:45 by mrouault          #+#    #+#             */
/*   Updated: 2024/03/27 23:17:03 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/strconv.h>
#include <limits.h>

static bool	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\v'
		|| c == '\t' || c == '\r' || c == '\f');
}

int64_t	ft_safe_atol(const char *str, bool *error, int64_t min, int64_t max)
{
	int			i;
	int			sign;
	__int128_t	n;

	i = 0;
	n = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == 0)
		*error = true;
	while (str[i] && !*error)
	{
		if ((str[i] < '0' || str[i] > '9'))
			*error = true;
		n = (n * 10) + str[i] - '0';
		if ((sign == 1 && n > max) || (sign != 1 && n * sign < min))
			*error = true;
		i++;
	}
	return (n * sign);
}
