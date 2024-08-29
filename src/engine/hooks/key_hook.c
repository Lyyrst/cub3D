/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:20:35 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 04:56:15 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_scancode.h>
#include <cub3d/engine.h>

static CUB_INLINE bool	wall_collide(t_engine *e, t_player *player, t_vec2 old)
{
	t_engine_map *const	map = &e->map;
	bool				wall;

	wall = false;
	wall |= engine_map_is_wall(map,
			vec2_new(player->pos.x - 12.0f, player->pos.y - 12.0f));
	wall |= engine_map_is_wall(map,
			vec2_new(player->pos.x + 12.0f, player->pos.y + 12.0f));
	wall |= engine_map_is_wall(map,
			vec2_new(player->pos.x + 12.0f, player->pos.y - 12.0f));
	wall |= engine_map_is_wall(map,
			vec2_new(player->pos.x - 12.0f, player->pos.y + 12.0f));
	if (wall)
		player->pos = old;
	return (wall);
}

CUB_INLINE void	player_angle_retarget(t_player *player)
{
	if (player->view_angle < 0)
		player->view_angle += 2.0f * M_PI;
	if (player->view_angle > 2.0f * M_PI)
		player->view_angle -= 2.0f * M_PI;
}

static CUB_INLINE void	player_handle_movement(t_player *player, int key)
{
	const float	angle = player->view_angle;
	t_vec2		delta;

	if (key == SDL_SCANCODE_W || key == SDL_SCANCODE_S)
	{
		delta = vec2_new((cosf(angle) * STEP_SIZE) * TILE_SIZE,
				(-sinf(angle) * STEP_SIZE) * TILE_SIZE);
		if (key == SDL_SCANCODE_W)
			player->pos = vec2_add(player->pos, delta);
		else
			player->pos = vec2_sub(player->pos, delta);
	}
	if (key == SDL_SCANCODE_A || key == SDL_SCANCODE_D)
	{
		delta = vec2_new((cosf(angle + deg2rad(90.0f)) * STEP_SIZE) * TILE_SIZE,
				(-sinf(angle + deg2rad(90.0f)) * STEP_SIZE) * TILE_SIZE);
		if (key == SDL_SCANCODE_A)
			player->pos = vec2_add(player->pos, delta);
		else
			player->pos = vec2_sub(player->pos, delta);
	}
}

int	engine_key_hook(int key, t_game *g)
{
	t_vec2		old;

	old = g->player.pos;
	player_handle_movement(&g->player, key);
	if (key == SDL_SCANCODE_RIGHT)
		g->player.view_angle -= STEP_SIZE;
	if (key == SDL_SCANCODE_LEFT)
		g->player.view_angle += STEP_SIZE;
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(g->engine.renderer.mlx);
	player_angle_retarget(&g->player);
	if (!wall_collide(&g->engine, &g->player, old))
		engine_render_scene(&g->engine, &g->player);
	return (0);
}
