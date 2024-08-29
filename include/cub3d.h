/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:10:44 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/01 14:18:53 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <cub3d/engine.h>
# include <cub3d/parsing.h>
# include <stdint.h>

t_parsed_cfg	cfg_parse(const char *path, t_parsing_state *state);
t_player		cfg_get_player(t_parsed_cfg *cfg);
void			cfg_destroy(t_parsed_cfg *cfg);

#endif