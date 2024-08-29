/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:30:48 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/02 03:56:37 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/engine.h>

int	engine_loop_hook(t_game *game)
{
	static int		old[2] = {0, 0};
	int				current[2];

	mlx_mouse_get_pos(game->engine.renderer.mlx, &current[0], &current[1]);
	if (current[0] == old[0])
		return (0);
	if (current[0] < old[0])
		game->player.view_angle += STEP_SIZE * 0.5f;
	else
		game->player.view_angle -= STEP_SIZE * 0.5f;
	player_angle_retarget(&game->player);
	old[0] = WINDOW_WIDTH / 2;
	old[1] = WINDOW_HEIGHT / 2;
	mlx_mouse_move(game->engine.renderer.mlx,
		game->engine.renderer.window,
		WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	engine_render_scene(&game->engine, &game->player);
	return (0);
}
