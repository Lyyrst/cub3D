/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:40:06 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 13:08:29 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <cub3d/engine.h>
#include <cub3d/parsing.h>
#include <libft/memory.h>
#include <stdlib.h>

static bool	engine_map_init_textures(
	t_engine_map *map,
	t_parsed_cfg *cfg,
	void *mlx
) {
	map->north = engine_convert_texture(cfg->north_texture, mlx);
	if (!map->north)
		return (false);
	map->south = engine_convert_texture(cfg->south_texture, mlx);
	if (!map->south)
		return (false);
	map->west = engine_convert_texture(cfg->west_texture, mlx);
	if (!map->west)
		return (false);
	map->east = engine_convert_texture(cfg->east_texture, mlx);
	if (!map->east)
		return (false);
	return (true);
}

t_engine_map	engine_map_new(t_parsed_cfg *cfg, void *mlx)
{
	t_engine_map	new;

	new = (t_engine_map){0};
	new.cfg = cfg;
	if (!engine_map_init_textures(&new, cfg, mlx))
	{
		engine_map_destroy(&new);
		state_print_error((t_parsing_state){ 
			.error_type = InvalidTexture,
			.error = true
		});
		return ((t_engine_map){0});
	}
	new.floor_color.hex = cfg->floor_color;
	new.ceiling_color.hex = cfg->ceiling_color;
	new.width = cfg->width;
	new.height = cfg->height;
	new.ptr = cfg->raw;
	return (new);
}

void	engine_map_destroy(t_engine_map *map)
{
	ft_free_tab_n((void **)map->north, TEXTURE_SIZE);
	ft_free_tab_n((void **)map->south, TEXTURE_SIZE);
	ft_free_tab_n((void **)map->east, TEXTURE_SIZE);
	ft_free_tab_n((void **)map->west, TEXTURE_SIZE);
	cfg_destroy(map->cfg);
}

CUB_INLINE bool	engine_map_in_bounds(t_engine_map *map, t_vec2 position)
{
	if ((int)position.x < 0 || (int)position.y < 0)
		return (false);
	if ((int)(position.x / TILE_SIZE) >= map->width
			|| (int)(position.y / TILE_SIZE) >= map->height)
		return (false);
	return (true);
}

CUB_INLINE bool	engine_map_is_wall(t_engine_map *map, t_vec2 vec)
{
	if (!engine_map_in_bounds(map, vec))
		return (false);
	return (map->ptr[(int)(vec.y / TILE_SIZE)] \
	[(int)(vec.x / TILE_SIZE)] == WALL_CHAR);
}
