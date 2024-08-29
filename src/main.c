/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:15:59 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 14:02:03 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io.h>
#include <cub3d.h>
#include <cub3d/engine.h>

static void	cub_loop(t_parsed_cfg *cfg)
{
	t_game			game;

	game.engine = engine_new(cfg);
	if (!game.engine.renderer.mlx)
		return ;
	game.player = cfg_get_player(cfg);
	engine_render_scene(&game.engine, &game.player);
	game_setup_hooks(&game);
	if (CUB_BONUS)
		mlx_mouse_hide();
	mlx_set_fps_goal(game.engine.renderer.mlx, 60);
	mlx_loop(game.engine.renderer.mlx);
	engine_destroy(&game.engine);
}

int	main(int argc, char **argv)
{
	t_parsing_state	state;
	t_parsed_cfg	cfg;

	state = ((t_parsing_state){0});
	if (argc != 2)
	{
		ft_fprintf(STDERR_FILENO,
			"Error\ncub3d: Invalid number of arguments\n");
		return (1);
	}
	cfg = cfg_parse(argv[1], &state);
	if (!cfg.raw || state.error)
	{
		state_print_error(state);
		cfg_destroy(&cfg);
		return (1);
	}
	cub_loop(&cfg);
	return (0);
}
