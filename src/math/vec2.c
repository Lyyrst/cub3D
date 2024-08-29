/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:37:06 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 00:51:24 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/defines.h>
#include <cub3d/math.h>
#include <math.h>

CUB_INLINE t_vec2	vec2_new(double x, double y)
{
	return ((t_vec2){x, y});
}

CUB_INLINE t_vec2	vec2_add(t_vec2 lhs, t_vec2 rhs)
{
	return (vec2_new(lhs.x + rhs.x, lhs.y + rhs.y));
}

CUB_INLINE t_vec2	vec2_sub(t_vec2 lhs, t_vec2 rhs)
{
	return (vec2_new(lhs.x - rhs.x, lhs.y - rhs.y));
}

CUB_INLINE double	vec2_abs(t_vec2 v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y)));
}
