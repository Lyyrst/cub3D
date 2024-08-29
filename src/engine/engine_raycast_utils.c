/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_raycast_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:27:35 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 01:59:56 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/engine.h>

CUB_INLINE bool	angle_is_down(float angle)
{
	const float	fraction = floorf(rad2deg(angle) / 90.0f) + 1.0f;

	return (fraction >= 0.0f && fraction <= 2.0f);
}

CUB_INLINE bool	angle_is_left(float angle)
{
	const float	fraction = floorf(rad2deg(angle) / 90.0f) + 1.0f;

	return (fraction >= 2.0f && fraction < 4.0f);
}
