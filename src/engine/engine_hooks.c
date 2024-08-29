/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:18:42 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 13:55:21 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/engine.h>

void	game_setup_hooks(t_game *game)
{
	void *const	mlx = game->engine.renderer.mlx;
	void *const	window = game->engine.renderer.window;

	mlx_on_event(mlx, window, MLX_KEYDOWN, (t_mlx_hook)engine_key_hook, game);
	mlx_on_event(mlx, window, MLX_WINDOW_EVENT,
		(t_mlx_hook)engine_window_hook, game);
	if (CUB_BONUS)
		mlx_loop_hook(mlx, (int (*)(void *))engine_loop_hook, game);
}
