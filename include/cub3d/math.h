/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:30:44 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/03 00:51:09 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

t_vec3		vec3_new(double x, double y, double z);

t_vec2		vec2_new(double x, double y);
t_vec2		vec2_add(t_vec2 lhs, t_vec2 rhs);
t_vec2		vec2_sub(t_vec2 lhs, t_vec2 rhs);
t_vec2		vec2_mul(t_vec2 lhs, t_vec2 rhs);
double		vec2_abs(t_vec2 v);

float		deg2rad(float d);
float		rad2deg(float r);

#endif