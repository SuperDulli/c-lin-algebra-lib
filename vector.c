/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:27:06 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/13 14:31:06 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

void	print_vec2(struct s_vec2 *vec)
{
	printf("vector2(%f,%f,[%f,%f])\n", vec->x, vec->y, vec->v[0], vec->v[1]);
}

float	*vec2(float x, float y, float *result)
{
	result[0] = x;
	result[1] = y;
	return (result);
}

float	vec2_length(float *vec)
{
	return (sqrtf(vec[0] * vec[0] + vec[1] * vec[1]));
}

float	vec2_length_squared(float *vec)
{
	return (vec[0] * vec[0] + vec[1] * vec[1]);
}

float	*vec2_scalar_mult(float *vec, float s, float *result)
{
	result[0] = vec[0] * s;
	result[1] = vec[1] * s;
	return (result);
}

float	*vec2_normalize(float *vec, float *result)
{
	const float	len = vec2_length(vec);

	result[0] = vec[0] / len;
	result[1] = vec[1] / len;
	return (result);
}

float	*vec2_add(float *v1, float *v2, float *result)
{
	result[0] = v1[0] + v2[0];
	result[1] = v1[1] + v2[1];
	return (result);
}

float	*vec2_sub(float *v1, float *v2, float *result)
{
	result[0] = v1[0] - v2[0];
	result[1] = v1[1] - v2[1];
	return (result);
}

float	vec2_dot(float *v1, float *v2)
{
	return (v1[0] * v2[0] + v1[1] * v2[1]);
}

bool	vec2_is_zero(float *vec)
{
	return (fabsf(vec[0]) < __FLT_EPSILON__ && fabsf(vec[1]) < __FLT_EPSILON__);
}

bool	vec2_is_equal(float *v1, float *v2)
{
	return (fabsf(v1[0] - v2[0]) < __FLT_EPSILON__
		&& fabsf(v1[1] - v2[1]) < __FLT_EPSILON__);
}
