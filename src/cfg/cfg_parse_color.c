/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:38:13 by mrouault          #+#    #+#             */
/*   Updated: 2024/04/30 16:43:21 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft/io.h>
#include <libft/memory.h>
#include <libft/strconv.h>

static int	cfg_color_parse(t_split *color, uint8_t *rgb)
{
	size_t	i;
	bool	error;

	error = false;
	i = 0;
	if (color->size < 3)
		error = true;
	while (i < color->size && i < 3)
	{
		rgb[i] = ft_safe_atol(color->strs[i].ptr, &error, 0, 255);
		i++;
	}
	split_destroy(color);
	return (error == false);
}

int	cfg_fill_color(uint32_t *color, t_string *line, t_string start)
{
	size_t	i;
	t_split	colors;
	uint8_t	rgb[3];

	ft_bzero(rgb, sizeof(uint8_t) * 3);
	i = start.len;
	while (i < line->len && line->ptr[i] == ' ')
		i++;
	if (string_char_count(line, ',') != 2)
		return (0);
	colors = string_split(&((t_string){.ptr = &line->ptr[i], .len = line->len
				- i, .cap = line->len - i + 1}), ',');
	if (!colors.strs)
		return (0);
	if (!cfg_color_parse(&colors, rgb))
		return (0);
	*color = 0xff << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	return (1);
}
