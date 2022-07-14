/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:26:36 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/14 18:58:04 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>

void	print_matrix(float *m, size_t size)
{
	size_t			edge_len;
	struct s_mat4	*matrix;
	size_t			index;

	size_t i, j;
	matrix = NULL;
	matrix = (struct s_mat4 *)m;
	printf("%f, %f, %f, %f\n", matrix->m11, matrix->m12, matrix->m13,
		matrix->m14);
	printf("%f, %f, %f, %f\n", matrix->m21, matrix->m22, matrix->m23,
		matrix->m24);
	printf("%f, %f, %f, %f\n", matrix->m31, matrix->m32, matrix->m33,
		matrix->m34);
	printf("%f, %f, %f, %f\n", matrix->m41, matrix->m42, matrix->m43,
		matrix->m44);
	edge_len = sqrt(size);
	i = 0;
	while (i < edge_len)
	{
		j = 0;
		while (j < edge_len)
		{
			index = i * edge_len + j;
			printf("%.2zu=%zu%zu=%.2f, ", index, i + 1, j + 1, m[index]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(void)
{
	float	identity[MAT4_SIZE];

	mat4_identity(identity);
	print_matrix(identity, MAT4_SIZE);
}
