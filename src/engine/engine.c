/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:45:13 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 13:57:33 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io.h>
#include <cub3d/engine.h>
#include <math.h>

static const float	g_fov = FOV * M_PI / 180.0f;
static const float	g_step = g_fov / (float)WINDOW_WIDTH;

t_engine	engine_new(t_parsed_cfg *cfg)
{
	t_engine	engine;

	engine = (t_engine){0};
	engine.renderer = renderer_new(WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!engine.renderer.mlx)
	{
		ft_fprintf(STDERR_FILENO,
			"Error\ncub3d: Issue during mlx initialization\n");
		return ((t_engine){0});
	}
	engine.map = engine_map_new(cfg, engine.renderer.mlx);
	if (!engine.map.cfg)
	{
		renderer_destroy(&engine.renderer);
		return ((t_engine){0});
	}
	return (engine);
}

void	engine_destroy(t_engine *engine)
{
	renderer_destroy(&engine->renderer);
	engine_map_destroy(&engine->map);
	*engine = (t_engine){0};
}

static CUB_INLINE void	render_engine_column(
	t_engine *engine,
	t_player *player,
	int column,
	float player_angle
) {
	t_ray			horizontal;
	t_ray			vertical;
	t_engine_wall	wall;
	float			angle;

	angle = player_angle - (float)column * g_step;
	if (angle > 2 * M_PI)
		angle -= 2.0f * M_PI;
	if (angle <= 0)
		angle += 2.0f * M_PI;
	horizontal = engine_intersect_horizontal(engine, player, angle);
	vertical = engine_intersect_vertical(engine, player, angle);
	if (!horizontal.hit && !vertical.hit)
		return ;
	wall = wall_new(player, horizontal, vertical, angle);
	wall.column = column;
	renderer_draw_wall(&engine->renderer, &engine->map, wall);
}

void	engine_render_scene(t_engine *engine, t_player *player)
{
	int			i;
	const float	player_angle = player->view_angle + g_fov * 0.5f;

	renderer_draw_surroundings(&engine->renderer, &engine->map);
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		render_engine_column(engine, player, i, player_angle);
		i++;
	}
	if (CUB_BONUS)
		engine_render_minimap(engine, player);
}
