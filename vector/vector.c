/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:27:06 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/13 16:59:00 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.h"
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

float	*vec3(float x, float y, float z, float *result)
{
	result[0] = x;
	result[1] = y;
	result[2] = z;
	return (result);
}

// norm only allows function that take a maximum of 4 parameters

float	*vec4(const float values[4], float *result)
{
	result[0] = values[0];
	result[1] = values[1];
	result[2] = values[2];
	result[3] = values[3];
	return (result);
}
