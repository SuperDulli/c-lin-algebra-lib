/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:22:40 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/20 10:55:40 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix.h"

float	*mat2_inverse(float *m, float *result)
{
	const float	determinant = mat2_determinant(m);
	float		tmp[MAT2_SIZE];

	if (!determinant)
		return (m);
	tmp[0] = (1 / determinant) * m[3];
	tmp[1] = (1 / determinant) * -m[2];
	tmp[2] = (1 / determinant) * -m[1];
	tmp[3] = (1 / determinant) * m[0];
	result[0] = tmp[0];
	result[1] = tmp[1];
	result[2] = tmp[2];
	result[3] = tmp[3];
	return (result);
}

float	*mat3_inverse(float *m, float *result)
{
	const float	determinant = mat3_determinant(m);
	float		tmp[MAT3_SIZE];

	if (!determinant)
		return (m);
	tmp[0] = (1 / determinant) * (m[4] * m[8] - m[7] * m[5]);
	tmp[1] = (1 / determinant) * (m[7] * m[2] - m[1] * m[8]);
	tmp[2] = (1 / determinant) * (m[1] * m[5] - m[4] * m[2]);
	tmp[3] = (1 / determinant) * (m[6] * m[5] - m[3] * m[8]);
	tmp[4] = (1 / determinant) * (m[0] * m[8] - m[6] * m[2]);
	tmp[5] = (1 / determinant) * (m[3] * m[2] - m[0] * m[5]);
	tmp[6] = (1 / determinant) * (m[3] * m[7] - m[6] * m[4]);
	tmp[7] = (1 / determinant) * (m[6] * m[1] - m[0] * m[7]);
	tmp[8] = (1 / determinant) * (m[0] * m[4] - m[3] * m[1]);
	return (mat_copy(tmp, MAT4_SIZE, result));
}
