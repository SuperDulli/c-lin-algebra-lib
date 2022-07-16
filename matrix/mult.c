/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:30:26 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/16 14:43:43 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix.h"

float	*mat4_mult(float *m1, float *m2, float *result)
{
	size_t			i;
	size_t			j;
	size_t			r;
	const size_t	dim = 4;
	float			tmp[MAT4_SIZE];

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			r = 0;
			tmp[j * dim + i] = 0;
			while (r < dim)
			{
				tmp[j * dim + i] += m1[r * dim + i] * m2[j * dim + r];
				r++;
			}
			j++;
		}
		i++;
	}
	return (mat_copy(tmp, MAT4_SIZE, result));
}
