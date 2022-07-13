/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:16:47 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/13 16:18:38 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	vec2_dot(float *v1, float *v2)
{
	return (v1[0] * v2[0] + v1[1] * v2[1]);
}

float	vec3_dot(float *v1, float *v2)
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

float	vec4_dot(float *v1, float *v2)
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2] + v1[3] * v2[3]);
}