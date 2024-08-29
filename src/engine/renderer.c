/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:29:01 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 14:01:33 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/engine.h>

static bool	renderer_init_images(
	t_renderer *renderer,
	int w_width,
	int w_height
) {
	void *const	mlx = renderer->mlx;
	int			w;
	int			h;

	renderer->image = mlx_new_image(mlx, w_width, w_height);
	if (!renderer->image)
		return (false);
	renderer->minimap = mlx_new_image(mlx, MINIMAP_SIZE, MINIMAP_SIZE);
	if (!renderer->minimap)
		return (false);
	renderer->slime = mlx_png_file_to_image(mlx, "textures/slime.png", &w, &h);
	if (!renderer->slime)
		return (false);
	renderer->compass = mlx_png_file_to_image(mlx,
			"textures/compass.png", &w, &h);
	if (!renderer->compass)
		return (false);
	return (true);
}

static void	renderer_put_image(t_renderer *renderer, void *image, int x, int y)
{
	void *const	mlx = renderer->mlx;
	void *const	window = renderer->window;

	mlx_put_image_to_window(mlx, window, image, x, y);
}

static void	renderer_put_all(t_renderer *renderer, int width)
{
	renderer_put_image(renderer, renderer->image, 0, 0);
	if (CUB_BONUS)
	{
		renderer_put_image(renderer, renderer->minimap, width - 200, 0);
		renderer_put_image(renderer, renderer->slime, width - 104, 96);
		renderer_put_image(renderer, renderer->compass, (width / 2) - 97, 10);
	}
}

t_renderer	renderer_new(uint32_t w_width, uint32_t w_height)
{
	t_renderer	render;

	render = (t_renderer){0};
	render.mlx = mlx_init();
	if (!render.mlx)
		return ((t_renderer){0});
	render.window = mlx_new_window(render.mlx,
			(int)w_width, (int)w_height, "Cub3D");
	if (!render.window)
	{
		renderer_destroy(&render);
		return ((t_renderer){0});
	}
	if (!renderer_init_images(&render, (int)w_width, (int)w_height))
	{
		renderer_destroy(&render);
		return ((t_renderer){0});
	}
	renderer_put_all(&render, (int)w_width);
	return (render);
}

void	renderer_destroy(t_renderer	*renderer)
{
	if (!renderer->mlx)
		return ;
	if (renderer->image)
		mlx_destroy_image(renderer->mlx, renderer->image);
	if (renderer->minimap)
		mlx_destroy_image(renderer->mlx, renderer->minimap);
	if (renderer->compass)
		mlx_destroy_image(renderer->mlx, renderer->compass);
	if (renderer->slime)
		mlx_destroy_image(renderer->mlx, renderer->slime);
	if (renderer->window)
		mlx_destroy_window(renderer->mlx, renderer->window);
	mlx_destroy_display(renderer->mlx);
	renderer->mlx = NULL;
	renderer->window = NULL;
	renderer->image = NULL;
}
