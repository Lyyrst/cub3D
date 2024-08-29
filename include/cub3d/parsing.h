/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:33:59 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 05:18:36 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <libft/string.h>
# include <stdbool.h>
# include <stdint.h>

typedef enum e_state
{
	Assets,
	Map,
}						t_state_type;

typedef enum e_parse_error
{
	MissingColor,
	MissingTextures,
	MissingMap,
	DuplicatedTexture,
	InvalidAssetsLine,
	InvalidMapLine,
	InvalidMap,
	InvalidTexture,
	FileError,
}						t_parse_error;

typedef struct s_parsing_state
{
	bool				seen_textures;
	bool				seen_map;
	enum e_state		type;
	bool				error;
	enum e_parse_error	error_type;
}						t_parsing_state;

/*!
 * @brief Print to STDERR the current error state.
 * @param state The current parsing state.
 */
void					state_print_error(t_parsing_state state);

/*!
 * @brief Set the parsing state in a error state, if the parsing state
 * is already in an error the error won't be set.
 * @param state A pointer to the parsing state.
 * @param error The error to set.
 */
void					state_set_error(t_parsing_state *state,
							enum e_parse_error error);

typedef struct s_cfg
{
	t_string			tmp_map;
	char				**raw;
	char				*north_texture;
	char				*south_texture;
	char				*east_texture;
	char				*west_texture;
	uint32_t			floor_color;
	uint32_t			ceiling_color;
	int					width;
	int					height;
}						t_parsed_cfg;

void					cfg_parse_lines(t_parsed_cfg *cfg,
							t_parsing_state *state,
							t_iterator_scalar *iterator);

int						cfg_fill_color(uint32_t *color, t_string *line,
							t_string start);

void					cfg_map_translate(t_parsed_cfg *map);

bool					cfg_map_is_valid(t_parsed_cfg *cfg);
bool					map_is_valid_line(t_string line);
bool					map_player_tile(char c);

#endif // PARSING_H
