/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:31:24 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 00:45:23 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <cub3d/defines.h>
#include <libft/memory.h>
#include <stdbool.h>

static const bool	g_valid_map_chars[256] = {
[' '] = true,
['1'] = true,
['0'] = true,
['N'] = true,
['S'] = true,
['W'] = true,
['E'] = true,
[0xff] = false,
};

bool	map_player_tile(char c)
{
	return (c == 'S' || c == 'N' || c == 'E' || c == 'W');
}

static bool	map_check_player_pos(t_parsed_cfg *map, double *x, double *y)
{
	int	i;
	int	j;
	int	ctr;

	ctr = 0;
	i = 0;
	if (!map->raw)
		return (false);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map_player_tile(map->raw[i][j]))
			{
				*x = (float)j;
				*y = (float)i;
				++ctr;
			}
			++j;
		}
		++i;
	}
	return (ctr == 1);
}

static bool	map_flood_fill(t_parsed_cfg *map, int x, int y, bool *visited)
{
	if (!map->raw || map->width <= x || map->height <= y || y < 0 || x < 0)
		return (false);
	if (map->raw[y][x] == WALL_CHAR)
		return (true);
	if (visited[map->width * y + x])
		return (true);
	if (!map_player_tile(map->raw[y][x]) && map->raw[y][x] != WALL_CHAR)
		map->raw[y][x] = FLOOR_CHAR;
	visited[map->width * y + x] = true;
	if (!map_flood_fill(map, x, y + 1, visited))
		return (false);
	if (!map_flood_fill(map, x, y - 1, visited))
		return (false);
	if (!map_flood_fill(map, x + 1, y, visited))
		return (false);
	if (!map_flood_fill(map, x - 1, y, visited))
		return (false);
	return (true);
}

bool	map_is_valid_line(t_string line)
{
	size_t	i;

	i = 0;
	if (line.len == 0)
		return (false);
	while (i < line.len)
	{
		if (!g_valid_map_chars[(uint8_t)line.ptr[i]])
			return (false);
		i++;
	}
	return (true);
}

bool	cfg_map_is_valid(t_parsed_cfg *cfg)
{
	t_vec2	pos;
	bool	*visited;
	bool	valid;

	if (!cfg->raw)
		return (false);
	if (!map_check_player_pos(cfg, &pos.x, &pos.y))
		return (false);
	visited = ft_calloc(cfg->width * cfg->height, sizeof(bool));
	if (!visited)
		return (false);
	valid = map_flood_fill(cfg, (int)pos.x, (int)pos.y, visited);
	free(visited);
	return (valid);
}
