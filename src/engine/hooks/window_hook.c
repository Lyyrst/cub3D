/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:20:43 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/02 02:21:10 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/engine.h>

int	engine_window_hook(int event, t_game *game)
{
	if (event == 0)
		mlx_loop_end(game->engine.renderer.mlx);
	return (0);
}
