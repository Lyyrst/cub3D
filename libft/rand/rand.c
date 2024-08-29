/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 09:45:22 by mrouault          #+#    #+#             */
/*   Updated: 2024/01/31 09:07:49 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/rand.h>

double	xoshiro_double(t_xoshiro_256 *x)
{
	static uint64_t	constant = 0x3ca0000000000000;

	return ((xoshiro256_next(x) >> 11) * (*(double *)&constant));
}
