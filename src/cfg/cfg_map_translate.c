/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg_map_translate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:00:25 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/01 17:57:38 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/defines.h>
#include <cub3d/parsing.h>
#include <libft/memory.h>

static void	map_fill_raw(t_parsed_cfg *map, t_split *lines, size_t max_width)
{
	size_t	i;
	size_t	j;

	i = 0;
	map->width = (int)max_width;
	map->height = (int)lines->size;
	map->raw = ft_calloc(lines->size + 1, sizeof(char *));
	if (!map->raw)
		return ;
	while (i < lines->size)
	{
		map->raw[i] = ft_calloc(max_width + 1, sizeof(char));
		j = 0;
		while (j < max_width)
		{
			map->raw[i][j] = lines->strs[i].ptr[j];
			++j;
		}
		++i;
	}
}

void	cfg_map_translate(t_parsed_cfg *map)
{
	t_split	lines;
	size_t	max_width;
	size_t	i;

	i = 0;
	max_width = 0;
	string_replace_char(&map->tmp_map, VOID_CHAR, UNDEFINED_CHAR);
	lines = string_split(&map->tmp_map, '\n');
	if (!lines.strs)
		return ;
	while (i < lines.size)
	{
		if (lines.strs[i].len > max_width)
			max_width = lines.strs[i].len;
		i++;
	}
	i = 0;
	while (i < lines.size)
	{
		string_pad(&lines.strs[i], max_width, UNDEFINED_CHAR);
		i++;
	}
	map_fill_raw(map, &lines, max_width);
	split_destroy(&lines);
}
