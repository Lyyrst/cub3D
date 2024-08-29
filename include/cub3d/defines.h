/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:42:35 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 13:54:39 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <sys/cdefs.h>
# include <math.h>

# ifdef CUB_DEBUG
#  define CUB_INLINE
# else
#  define CUB_INLINE __always_inline
# endif

# ifdef CUB_BONUS
#  undef CUB_BONUS
#  define CUB_BONUS true
# else
#  define CUB_BONUS false
# endif

# define WALL_CHAR '1'
# define FLOOR_CHAR '0'
# define VOID_CHAR ' '
# define UNDEFINED_CHAR 'x'

# define TILE_SIZE 64
# define TEXTURE_SIZE 64
# define WALL_PIXEL_HEIGHT 64
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define MINIMAP_SIZE 200
# define STEP_SIZE 0.090f
# define FOV 60.f

#endif
