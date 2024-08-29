/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:26:53 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 00:52:37 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/defines.h>
#include <cub3d/math.h>

CUB_INLINE t_vec3	vec3_new(double x, double y, double z)
{
	return ((t_vec3){x, y, z});
}
