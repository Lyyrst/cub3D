/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:57:16 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 00:25:27 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/engine.h>
#include <math.h>

static const t_ray	g_bogus_ray = {{9999999, 9999999, 9999999}, false};

static CUB_INLINE t_ray	trace_ray(
		t_engine *engine,
		t_player *player,
		t_vec2 intersect,
		t_vec2 delta
) {
	t_vec2	point;
	int		i;

	i = 256;
	while (i > 0)
	{
		point.x = intersect.x + player->pos.x;
		point.y = intersect.y + player->pos.y;
		if (!engine_map_in_bounds(&engine->map, point))
			break ;
		if (engine_map_is_wall(&engine->map, point))
			return ((t_ray){
				.vec = vec3_new(point.x, point.y, vec2_abs(intersect)),
				.hit = true,
			});
		intersect.x += delta.x;
		intersect.y += delta.y;
		i--;
	}
	return (g_bogus_ray);
}

CUB_INLINE t_ray	engine_intersect_horizontal(
		t_engine *engine,
		t_player *p,
		float angle
) {
	const float	tan_angle = tanf(angle);
	const bool	up = !angle_is_down(angle);
	t_vec2		intersect;
	t_vec2		delta;

	if (up)
		intersect.y = (ceil(p->pos.y / TILE_SIZE) * TILE_SIZE) - p->pos.y;
	else
		intersect.y = (floor(p->pos.y / TILE_SIZE) * TILE_SIZE) - p->pos.y
			- 0.0001f;
	intersect.x = -intersect.y / tan_angle;
	delta.y = -TILE_SIZE;
	if (up)
		delta.y = TILE_SIZE;
	delta.x = -delta.y / tan_angle;
	return (trace_ray(engine, p, intersect, delta));
}

CUB_INLINE t_ray	engine_intersect_vertical(
		t_engine *engine,
		t_player *p,
		float angle
) {
	const float	tan_angle = tanf(angle);
	const bool	right = !angle_is_left(angle);
	t_vec2		intersect;
	t_vec2		delta;

	if (right)
		intersect.x = (ceil(p->pos.x / TILE_SIZE) * TILE_SIZE) - p->pos.x;
	else
		intersect.x = (floor(p->pos.x / TILE_SIZE) * TILE_SIZE) - p->pos.x
			- 0.0001f;
	intersect.y = intersect.x * -tan_angle;
	delta.x = -TILE_SIZE;
	if (right)
		delta.x = TILE_SIZE;
	delta.y = delta.x * -tan_angle;
	return (trace_ray(engine, p, intersect, delta));
}
