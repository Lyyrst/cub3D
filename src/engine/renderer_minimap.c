/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:20:02 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/05/03 04:51:55 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/engine.h>

static const int	g_compass_offset = ((int)WINDOW_WIDTH / 2 - 97) + 8;

static void	compass_pointer(t_engine *engine, t_player *player)
{
	const float	angle = rad2deg(player->view_angle);
	void *const	mlx = engine->renderer.mlx;
	void *const	image = engine->renderer.image;
	float		compass_index;
	int			y;

	compass_index = 0.0f;
	y = 24;
	while (angle > 0
		&& compass_index != ceilf(angle)
		&& compass_index <= 360.0f)
		compass_index++;
	compass_index /= 10;
	while (y < 30)
	{
		mlx_set_image_pixel(mlx, image,
			g_compass_offset + (int)compass_index * 5, y, 0xffffffff);
		y++;
	}
}

static unsigned int	pick_wall_color(int x, int y)
{
	if (x % 24 == 0 || y % 24 == 0)
		return (0xff3f9beb);
	if (x % 12)
		return (0xff346a99);
	if (y % 12)
		return (0xff346a99);
	return (0xff83b7e6);
}

static unsigned int	pick_floor_color(int x, int y)
{
	if (x % 4 == 0 || y % 4 == 0)
		return (0x7f2cbf42);
	if (x % 10 == 0 || y % 10 == 0)
		return (0x7f19a62e);
	return (0x7f09991f);
}

static void	draw_minimap(t_engine *engine, float original_x, float y)
{
	float	xi;
	float	x;
	float	yi;

	yi = 1.0f;
	x = original_x;
	while (++yi < 200.0f)
	{
		xi = 1.0f;
		while (++xi < 200.0f)
		{
			if (engine_map_is_wall(&engine->map, vec2_new(x, y)))
				mlx_set_image_pixel(engine->renderer.mlx, \
				engine->renderer.minimap, \
				(int)xi, (int)yi, pick_wall_color((int)xi, (int)yi));
			else
				mlx_set_image_pixel(engine->renderer.mlx, \
				engine->renderer.minimap, \
				(int)xi, (int)yi, pick_floor_color((int)xi, (int)yi));
			x += 5.0f;
		}
		x = original_x;
		y += 5.0f;
	}
}

void	engine_render_minimap(t_engine *engine, t_player *player)
{
	double	start_x;
	double	start_y;

	start_x = player->pos.x - 500.0f;
	start_y = player->pos.y - 500.0f;
	draw_minimap(engine, start_x, start_y);
	compass_pointer(engine, player);
}
