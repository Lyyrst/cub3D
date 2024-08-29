/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:20:03 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/02 04:03:49 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/engine.h>

void	renderer_draw_surroundings(t_renderer *r, t_engine_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_set_image_pixel(r->mlx, r->image, j, i, map->ceiling_color.hex);
			++j;
		}
		i++;
	}
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_set_image_pixel(r->mlx, r->image, j, i, map->floor_color.hex);
			++j;
		}
		i++;
	}
}

static CUB_INLINE uint32_t	**wall_get_texture(
		t_engine_map *map, t_engine_wall *wall
) {
	uint32_t **const	textures[] = {
	[SO] = map->south,
	[NO] = map->north,
	[EA] = map->east,
	[WE] = map->west,
	};

	return (textures[wall->orientation]);
}

CUB_INLINE void	renderer_draw_wall(
		t_renderer *renderer,
		t_engine_map *map,
		t_engine_wall wall
) {
	const float			ratio = wall.height / (float)WALL_PIXEL_HEIGHT;
	uint32_t **const	texture = wall_get_texture(map, &wall);
	uint32_t			color;
	int					i;
	int					y_offset;

	y_offset = -1;
	i = 0;
	if (wall.start < 0)
		i = -wall.start;
	while (i < (int)wall.height)
	{
		if (y_offset != (int)((float)i / ratio))
		{
			y_offset = (int)((float)i / ratio);
			color = texture[y_offset][wall.texture_offset];
		}
		if (wall.column < 0 || (wall.start + i) < 0
			|| wall.column >= WINDOW_WIDTH || (wall.start + i) >= WINDOW_HEIGHT)
			break ;
		mlx_set_image_pixel(renderer->mlx, renderer->image, \
		wall.column, wall.start + i, color);
		i++;
	}
}
