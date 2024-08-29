/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:14:40 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 13:38:52 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/engine.h>
#include <libft/memory.h>
#include <libft/io.h>

static uint32_t	**alloc_texture(void)
{
	uint32_t	**texture;
	size_t		i;

	i = 0;
	texture = ft_calloc(sizeof(uint32_t *), TEXTURE_SIZE);
	if (!texture)
		return (NULL);
	while (i < TEXTURE_SIZE)
	{
		texture[i] = ft_calloc(sizeof(uint32_t), TEXTURE_SIZE);
		i++;
	}
	return (texture);
}

void	scale_and_fill_texture(
	uint32_t **texture,
	void *mlx,
	void *image,
	int size
) {
	const float	ratio = (float)size / (float)TEXTURE_SIZE;
	int			i;
	int			j;
	int			x;
	int			y;

	i = 0;
	while (i < TEXTURE_SIZE)
	{
		j = 0;
		while (j < TEXTURE_SIZE)
		{
			x = (int)((float)j * ratio);
			y = (int)((float)i * ratio);
			texture[i][j] = (uint32_t)mlx_get_image_pixel(mlx, image, x, y);
			++j;
		}
		++i;
	}
}

uint32_t	**engine_convert_texture(char *path, void *mlx)
{
	void		*image;
	uint32_t	**texture;
	int			width;
	int			height;

	image = mlx_png_file_to_image(mlx, path, &width, &height);
	if (width != height || !image || (width >= 256 || height >= 256))
	{
		if (image)
			mlx_destroy_image(mlx, image);
		return (NULL);
	}
	texture = alloc_texture();
	if (texture)
		scale_and_fill_texture(texture, mlx, image, width);
	mlx_destroy_image(mlx, image);
	return (texture);
}
