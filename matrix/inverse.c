/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:22:40 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/19 15:00:30 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix.h"

float	*mat2_inverse(float *m, float *result)
{
	const float	determinant = mat2_determinant(m);

	if (!determinant)
		return (m);
	result[0] = (1 / determinant) * m[3];
	result[1] = (1 / determinant) * -m[2];
	result[2] = (1 / determinant) * -m[1];
	result[3] = (1 / determinant) * m[0];
	return (result);
}

float	*mat3_inverse(float *m, float *result)
{
	const float	determinant = mat3_determinant(m);
	const float	e = m[0] * m[8] - m[6] * m[2];
	const float	f = -(m[0] * m[5] - m[3] * m[8]);
	const float	g = m[3] * m[7] - m[6] * m[4];
	const float	h = -(m[0] * m[7] - m[6] * m[1]);
	const float	i = m[0] * m[4] - m[3] * m[2];

	if (!determinant)
		return (m);
	result[0] = (1 / determinant) * m[4] * m[8] - m[7] * m[5];;
	result[1] = (1 / determinant) * -(m[1] * m[8] - m[7] * m[2]);
	result[2] = (1 / determinant) * m[1] * m[5] - m[4] * m[2];
	result[3] = (1 / determinant) * -(m[4] * m[8] - m[6] * m[5]);
	result[4] = (1 / determinant) * e;
	result[5] = (1 / determinant) * f;
	result[6] = (1 / determinant) * g;
	result[7] = (1 / determinant) * h;
	result[8] = (1 / determinant) * i;
	return (result);
}
