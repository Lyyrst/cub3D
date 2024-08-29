/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:12:07 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 05:01:32 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <cub3d/engine.h>
#include <libft/memory.h>
#include <stdlib.h>

static void	destroy_ptr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	cfg_destroy(t_parsed_cfg *cfg)
{
	destroy_ptr((void **)&cfg->north_texture);
	destroy_ptr((void **)&cfg->south_texture);
	destroy_ptr((void **)&cfg->east_texture);
	destroy_ptr((void **)&cfg->west_texture);
	if (cfg->raw)
		ft_free_tab((void **)cfg->raw);
	string_destroy(&cfg->tmp_map);
	cfg->raw = NULL;
}

static float	cfg_get_player_angle(char c)
{
	if (c == 'W')
		return (deg2rad(180));
	if (c == 'E')
		return (0);
	if (c == 'N')
		return (deg2rad(90));
	if (c == 'S')
		return (deg2rad(270));
	return (0);
}

t_player	cfg_get_player(t_parsed_cfg *cfg)
{
	t_player	player;
	int			i;
	int			j;

	i = 0;
	player = (t_player){0};
	if (!cfg->raw)
		return (player);
	while (i < cfg->height)
	{
		j = 0;
		while (j < cfg->width)
		{
			if (map_player_tile(cfg->raw[i][j]))
			{
				player.pos = vec2_new(((float)j + 0.5f) * TILE_SIZE,
						((float)i + 0.5f) * TILE_SIZE);
				player.view_angle = cfg_get_player_angle(cfg->raw[i][j]);
				return (player);
			}
			++j;
		}
		++i;
	}
	return (player);
}
