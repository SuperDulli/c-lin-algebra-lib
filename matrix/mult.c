/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:30:26 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/14 20:01:46 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix.h"

float	*mat4_mult(float *m1, float *m2, float *result)
{
	size_t	i;
	size_t	j;
	const size_t	rows = 4;
	const size_t	columns = 4;
	float	tmp[MAT4_SIZE];

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			tmp[j * rows + i]
				= m1[i] * m2[i * rows]
				+ m1[(i + 1) * rows + 1] * m2[1]
				+ m1[(i + 2) * rows + 1] * m2[2]
				+ m1[(i + 3) * rows + 1] * m2[3];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < MAT4_SIZE)
	{
		result[i] = tmp[i];
		i++;
	}
	return (result);
}
