/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg_parse_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:50:01 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/01 17:56:20 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/parsing.h>
#include <libft/io.h>

static const t_string	g_north_start = {"NO ", 3, 4};
static const t_string	g_south_start = {"SO ", 3, 4};
static const t_string	g_east_start = {"EA ", 3, 4};
static const t_string	g_west_start = {"WE ", 3, 4};
static const t_string	g_floor_start = {"F ", 2, 3};
static const t_string	g_ceiling_start = {"C ", 2, 3};

static int	cfg_fill_texture(char **field, t_parsing_state *state,
		t_string *line, t_string start)
{
	size_t	i;

	i = start.len;
	while (i < line->len && line->ptr[i] == ' ')
		i++;
	if (*field)
	{
		state_set_error(state, DuplicatedTexture);
		return (0);
	}
	*field = string_slice(line, i, line->len).ptr;
	return (1);
}

static int	cfg_handle_texture_line(t_parsed_cfg *map, t_parsing_state *state,
		t_string *line)
{
	string_trim(line, " \n\t", true);
	if (string_starts_with(*line, g_north_start))
		return (cfg_fill_texture(&map->north_texture, state, line,
				g_north_start));
	if (string_starts_with(*line, g_south_start))
		return (cfg_fill_texture(&map->south_texture, state, line,
				g_south_start));
	if (string_starts_with(*line, g_east_start))
		return (cfg_fill_texture(&map->east_texture, state, line,
				g_east_start));
	if (string_starts_with(*line, g_west_start))
		return (cfg_fill_texture(&map->west_texture, state, line,
				g_west_start));
	if (string_starts_with(*line, g_ceiling_start))
		return (cfg_fill_color(&map->ceiling_color, line, g_ceiling_start));
	if (string_starts_with(*line, g_floor_start))
		return (cfg_fill_color(&map->floor_color, line, g_floor_start));
	return (line->len == 0);
}

static int	cfg_handle_map_line(
	t_parsed_cfg *map,
	t_parsing_state *state,
	t_string *line,
	bool prev_is_nl
) {
	if (prev_is_nl && line->len != 0)
	{
		state_set_error(state, InvalidMapLine);
		return (0);
	}
	if (map_is_valid_line(*line))
	{
		string_append_string(&map->tmp_map, line, false);
		string_append_char(&map->tmp_map, '\n');
		state->seen_map = true;
		return (1);
	}
	if (line->len != 0)
		state_set_error(state, InvalidMapLine);
	return (0);
}

static int	cfg_process_line(
	t_parsed_cfg *map,
	t_parsing_state *state,
	t_string *line
) {
	static bool	prev_is_nl;

	if (state->type == Assets)
	{
		if (map_is_valid_line(*line))
		{
			state->type = Map;
			state->seen_map = true;
			return (1);
		}
		if (!cfg_handle_texture_line(map, state, line))
			state_set_error(state, InvalidAssetsLine);
		if (!state->error)
			state->seen_textures = true;
		return (0);
	}
	cfg_handle_map_line(map, state, line, prev_is_nl);
	prev_is_nl = (line->len == 0);
	return (0);
}

void	cfg_parse_lines(
	t_parsed_cfg *cfg,
	t_parsing_state *state,
	t_iterator_scalar *iterator
) {
	t_string	line;
	size_t		backtrack;

	state->type = Assets;
	while (!state->error)
	{
		backtrack = iterator->offset;
		line = iterator_scalar_next(iterator, true);
		if (!line.ptr)
			return ;
		string_trim(&line, "\n", true);
		if (cfg_process_line(cfg, state, &line))
			iterator->offset = backtrack;
		string_destroy(&line);
	}
}
