/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:06:53 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/02 03:55:56 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io.h>
#include <cub3d/parsing.h>

static const char	*g_error_table[] = {
[MissingColor] = "Missing colors",
[MissingTextures] = "Missing textures",
[MissingMap] = "Missing map",
[DuplicatedTexture] = "Duplicated texture",
[InvalidAssetsLine] = "Invalid assets line",
[InvalidMapLine] = "Invalid map line",
[InvalidMap] = "Invalid map",
[InvalidTexture] = "Invalid texture",
[FileError] = "File error",
};

void	state_print_error(t_parsing_state state)
{
	char	*error;

	if (!state.error)
		return ;
	if (state.error_type < 0 || state.error_type > FileError)
		error = "Invalid Error";
	else
		error = (char *)g_error_table[state.error_type];
	ft_fprintf(STDERR_FILENO, "Error\ncub3d: %s\n", error);
}

void	state_set_error(t_parsing_state *state, enum e_parse_error error)
{
	if (!state->error)
		state->error_type = error;
	state->error = true;
}
