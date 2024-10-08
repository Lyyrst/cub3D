/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:46:40 by mrouault          #+#    #+#             */
/*   Updated: 2024/01/22 20:06:07 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

double	ft_mapf(const double in[2], const double out[2], double val)
{
	return ((val - in[0]) * (out[1] - out[0]) / (in[1] - in[0]) + out[0]);
}
