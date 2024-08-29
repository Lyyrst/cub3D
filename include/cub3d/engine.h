/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:28:31 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 14:23:37 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <cub3d/defines.h>
# include <cub3d/math.h>
# include <cub3d/parsing.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

typedef union u_color
{
	uint32_t			hex;
	struct
	{
		uint8_t			r;
		uint8_t			g;
		uint8_t			b;
		uint8_t			a;
	};
}						t_color;

typedef struct s_ray
{
	t_vec3				vec;
	bool				hit;
}						t_ray;

typedef enum e_orientation
{
	SO,
	NO,
	WE,
	EA,
}						t_orientation;

typedef struct s_engine_wall
{
	t_ray				ray;
	enum e_orientation	orientation;
	int					start;
	int					column;
	int					texture_offset;
	float				height;
}						t_engine_wall;

typedef struct s_renderer
{
	void				*mlx;
	void				*window;
	void				*image;
	void				*minimap;
	void				*slime;
	void				*compass;
	int					width;
	int					height;
}						t_renderer;

typedef struct s_engine_map
{
	t_parsed_cfg		*cfg;
	char				**ptr;
	t_color				ceiling_color;
	t_color				floor_color;
	uint32_t			**south;
	uint32_t			**north;
	uint32_t			**east;
	uint32_t			**west;
	int					width;
	int					height;
}						t_engine_map;

typedef struct s_engine
{
	t_engine_map		map;
	t_renderer			renderer;
}						t_engine;

typedef struct s_player
{
	t_vec2				pos;
	float				view_angle;
}						t_player;

/*!
 * @brief Create a new renderer instance with the provided window size.
 * It's resources must be freed using `renderer_destroy`.
 * @param w_width The window width.
 * @param w_height The window height
 * @return A renderer object with all it's fields set to 0 in case of an error.
 */
t_renderer				renderer_new(uint32_t w_width, uint32_t w_height);

/*!
 * @brief Release all the memory associated to the renderer,
 * and also free all the resources of the mlx.
 * @param renderer A pointer the renderer instance.
 */
void					renderer_destroy(t_renderer *renderer);

/*!
 * @brief Draw the floor and ceiling.
 * @param renderer A pointer to the renderer instance
 * @param map A pointer to the map instance.
 * @param wall The wall to draw on the screen.
 */
void					renderer_draw_surroundings(t_renderer *r,
							t_engine_map *map);

/*!
 * @brief Draw an engine wall on the screen, it will draw the texture
 * slice accordingly to the wall orientation.
 * @param renderer A pointer to the renderer instance
 * @param map A pointer to the map instance.
 * @param wall The wall to draw on the screen.
 */
void					renderer_draw_wall(t_renderer *renderer,
							t_engine_map *map, t_engine_wall wall);

/*!
 * @brief Create a new engine instance, will initialize the internal renderer
 * and engine map based on the parsed config.
 * It must be freed by calling \a `engine_destroy`
 * @param cfg A pointer to the parsed config
 * @return A `t_engine` object with all fields set to 0 in case of failure.
 */
t_engine				engine_new(t_parsed_cfg *cfg);

/*!
 * @brief Release all memory associated with the engine instance.
 * @param engine A pointer to the engine instance.
 */
void					engine_destroy(t_engine *engine);

/*!
 * @brief Check if the angle is down bad or not
 * @param angle The angle to check
 * @return Whether the angle is facing down or not.
 */
bool					angle_is_down(float angle);

/*!
 * @brief Check if the angle is facing left
 * @param angle The angle to check
 * @return Whether the angle is facing left or not.
 */
bool					angle_is_left(float angle);

/*!
 * @brief Cast a ray based on the given angle and checks all the horizontal
 * intersections on the grid.
 * Step 1.
 * 	We need to compute the distance to the first intersection point on the
 * 	grid, to do so we round up or down our `player.y` depending on
 * 	which direction we're facing, `intersect.x` is the Adjacent so we can
 * 	find it in a trivial way `tan(angle) = intersect.y / intersect.x` ->
 *  `intersect.x = intersect.y / tan(angle)`
 *
 * Step 2.
 * 	We now need to calculate the delta which we'll add to the last intersection
 *	in each iteration of the loop, since we're looking for horizontal
 *	intersections we know `delta.y` will be 1 unit of the grid.
 *	`delta.x = delta.y / tan(angle)`
 *
 * Step 3.
 *	Shoot the ray.
 * @param engine A pointer to the engine, used to check the map.
 * @param p The player position.
 * @param angle The angle to cast the ray from.
 * @return A `t_ray` containing the position of where the
 * ray hit and whether the ray hit at all.
 */
t_ray					engine_intersect_horizontal(t_engine *engine,
							t_player *p, float angle);

/*!
 * @brief Cast a ray based on the given angle and checks all the vertical
 * intersections on the grid.
 * Step 1.
 * 	We need to compute the distance to the first intersection point on
 * 	the grid, to do so we round up or down our `player.x`
 * 	depending on which direction we're facing, `intersect.y`
 * 	is the Opposite so we can find it in a trivial way
 * 	`tan(angle) = intersect.y / intersect.x` ->
 *  `intersect.y = intersect.x * tan(angle)`
 *
 *
 * Step 2.
 * 	We now need to calculate the delta which we'll add to the last intersection
 *	in each iteration of the loop, since we're looking for
 *	vertical intersections we know `delta.x` will be 1 unit of the grid.
 *	`delta.y = delta.x * tan(angle)`
 *
 * Step 3.
 *	Shoot the ray.
 * @param engine A pointer to the engine, used to check the map.
 * @param p The player position.
 * @param angle The angle to cast the ray from.
 * @return A `t_ray` containing the position of where
 * the ray hit and whether the ray hit at all.
 */
t_ray					engine_intersect_vertical(t_engine *engine, t_player *p,
							float angle);

/*!
 * @brief Render the whole scene, including all the walls and HUD
 * @param engine A pointer to the engine instance
 * @param player A pointer to the player object
 */
void					engine_render_scene(t_engine *engine, t_player *player);

/*!
 * @brief Render the minimap on the window.
 * @param engine A pointer to the engine instance.
 * @param player A pointer to the player instance.
 */
void					engine_render_minimap(t_engine *engine,
							t_player *player);

/*!
 * @brief Create and allocate a new engine map, it converts the texture to
 * \a `uint32_t` 2D array internally, and copy all the fields from the
 * passed \a `cfg` object.
 * The returned object MUST be freed using \a `engine_map_destroy`.
 * @param cfg A pointer to a parsed config object.
 * @param mlx A pointer to the mlx.
 * @return Returns an object with all it's fields set to 0 on error.
 */
t_engine_map			engine_map_new(t_parsed_cfg *cfg, void *mlx);

/*!
 * @brief Release all the memory associated with the given engine map,
 * it also destroys the underlying \a `t_parsed_cfg`.
 * @param map A pointer to the engine map.
 */
void					engine_map_destroy(t_engine_map *map);

/*!
 * @brief Create a new engine wall, what it does is choose between
 * the provided horizontal and vertical based on the distance of both,
 * it also calculates the height and the start of the wall on the screen.
 * @param player A pointer to the player object,
 * required to compute the orientation of the wall.
 * @param horizontal The horizontal ray.
 * @param vertical The vertical ray.
 * @param angle The angle in which the ray was cast.
 * @return A engine wall instance containing all necessary variables
 * to draw the wall on the screen.
 */
t_engine_wall			wall_new(t_player *player, t_ray horizontal,
							t_ray vertical, float angle);

/*!
 * @brief Check if the given position is within the boundaries of the map.
 * @param map A pointer to the current engine map.
 * @param position The position to check.
 * @return Whether or not the \a `position` is within the boundaries of the map.
 */
bool					engine_map_in_bounds(t_engine_map *map,
							t_vec2 position);

/*!
 * @brief Check if the given position is a wall.
 * @param map A pointer to the current engine map.
 * @param vec The position to check.
 * @return Whether or not the \a `vec` is a wall.
 */
bool					engine_map_is_wall(t_engine_map *map, t_vec2 vec);

void					player_angle_retarget(t_player *player);

uint32_t				**engine_convert_texture(char *path, void *mlx);

typedef struct s_game
{
	t_engine			engine;
	t_player			player;
}						t_game;

typedef int				(*t_mlx_hook)(int, void *);

void					game_setup_hooks(t_game *game);
int						engine_key_hook(int key, t_game *g);
int						engine_window_hook(int event, t_game *game);
int						engine_loop_hook(t_game *game);

#endif
