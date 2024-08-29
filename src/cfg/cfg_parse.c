/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:18:46 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/02 02:17:23 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft/io.h>
#include <libft/string.h>
#include <fcntl.h>

static bool	texture_valid(char *path)
{
	int			fd;
	t_string	str;

	str = string_new_owned(path);
	if (str.len < 4)
		return (false);
	if (ft_strcmp(&str.ptr[str.len - 4], ".png") != 0)
		return (false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

static bool	map_name_valid(char *path)
{
	t_string	str;

	str = string_new_owned(path);
	if (str.len < 4)
		return (false);
	return (ft_strcmp(&str.ptr[str.len - 4], ".cub") == 0);
}

static bool	cfg_set_errors(t_parsed_cfg *cfg, t_parsing_state *state)
{
	if (cfg->ceiling_color == 0 || cfg->floor_color == 0)
		state_set_error(state, MissingColor);
	if (!cfg->west_texture || !cfg->north_texture || !cfg->south_texture
		|| !cfg->east_texture)
		state_set_error(state, MissingTextures);
	if (!cfg->raw)
		state_set_error(state, InvalidMap);
	if (!state->seen_textures)
		state_set_error(state, MissingTextures);
	if (!state->seen_map)
		state_set_error(state, MissingMap);
	if (!texture_valid(cfg->north_texture)
		|| !texture_valid(cfg->south_texture)
		|| !texture_valid(cfg->east_texture)
		|| !texture_valid(cfg->west_texture))
		state_set_error(state, InvalidTexture);
	return (state->error);
}

t_parsed_cfg	cfg_parse(const char *path, t_parsing_state *state)
{
	t_parsed_cfg		cfg;
	t_iterator_scalar	iterator;
	t_string			file;

	file = ft_read_file(string_new_owned((char *)path));
	if (!file.ptr || !map_name_valid((char *)path))
	{
		string_destroy(&file);
		state_set_error(state, FileError);
		return ((t_parsed_cfg){0});
	}
	iterator = iterator_scalar_new(file, '\n');
	cfg = (t_parsed_cfg){.tmp_map = string_new_capacity(128)};
	cfg_parse_lines(&cfg, state, &iterator);
	string_destroy(&file);
	if (!state->error)
		cfg_map_translate(&cfg);
	if (cfg_set_errors(&cfg, state))
		cfg_destroy(&cfg);
	if (!cfg_map_is_valid(&cfg))
	{
		state_set_error(state, InvalidMap);
		cfg_destroy(&cfg);
	}
	return (cfg);
}
