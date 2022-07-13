/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:48:26 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/13 14:27:27 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include <math.h>

# define VEC2_SIZE 2
# define VEC3_SIZE 3
# define VEC4_SIZE 4

struct s_vec2
{
	union
	{
		struct
		{
			float	x;
			float	y;
		};
		float	v[VEC2_SIZE];
	};
};

struct s_vec3
{
	union
	{
		struct
		{
			float	x;
			float	y;
			float	z;
		};
		float	v[VEC3_SIZE];
	};
};

struct s_vec4
{
	union
	{
		struct
		{
			float	x;
			float	y;
			float	z;
			float	w;
		};
		float	v[VEC4_SIZE];
	};
};

// vec2 functions

float	*vec2(float x, float y, float *result);
float	vec2_length(float *vec);
float	vec2_length_squared(float *vec);
float	*vec2_scalar_mult(float *vec, float s, float *result);
float	*vec2_normalize(float *vec, float *result);
float	*vec2_add(float *v1, float *v2, float *result);
float	*vec2_sub(float *v1, float *v2, float *result);
float	vec2_dot(float *v1, float *v2);
bool	vec2_is_zero(float *vec);
bool	vec2_is_equal(float *v1, float *v2);

void	print_vec2(struct s_vec2 *vec);

#endif
