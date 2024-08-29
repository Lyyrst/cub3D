/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:54:09 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 00:22:24 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/engine.h>

static const float	g_fov = FOV * M_PI / 180.0f;

static CUB_INLINE void	wall_set_height(
	t_player *player,
	t_engine_wall *wall,
	float angle
) {
	const float		plane_distance = (WINDOW_WIDTH / 2.0f) / tanf(g_fov / 2.0f);

	wall->height = (float)TILE_SIZE
		/ (wall->ray.vec.z * cosf(player->view_angle - angle))
		* plane_distance;
	wall->start = ((float)WINDOW_HEIGHT / 2.0f) - (wall->height * 0.5f);
}

CUB_INLINE t_engine_wall	wall_new(
		t_player *player,
		t_ray horizontal,
		t_ray vertical,
		float angle
) {
	t_engine_wall	wall;

	if (horizontal.vec.z < vertical.vec.z)
	{
		wall.ray = horizontal;
		if (player->pos.y < wall.ray.vec.y)
			wall.orientation = NO;
		else
			wall.orientation = SO;
		wall.texture_offset = (int)wall.ray.vec.x % TILE_SIZE;
	}
	else
	{
		wall.ray = vertical;
		if (player->pos.x < wall.ray.vec.x)
			wall.orientation = EA;
		else
			wall.orientation = WE;
		wall.texture_offset = (int)wall.ray.vec.y % TILE_SIZE;
	}
	wall_set_height(player, &wall, angle);
	return (wall);
}
