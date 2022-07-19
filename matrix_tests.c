/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:26:36 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/19 13:25:08 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>

void	print_matrix(float *m, size_t size)
{
	size_t	edge_len;
	size_t	index;
	size_t	i;
	size_t	j;

	// struct s_mat4	*matrix;
	// matrix = NULL;
	// matrix = (struct s_mat4 *)m;
	// printf("%f, %f, %f, %f\n", matrix->m11, matrix->m12, matrix->m13,
	// 		matrix->m14);
	// printf("%f, %f, %f, %f\n", matrix->m21, matrix->m22, matrix->m23,
	// 		matrix->m24);
	// printf("%f, %f, %f, %f\n", matrix->m31, matrix->m32, matrix->m33,
	// 		matrix->m34);
	// printf("%f, %f, %f, %f\n", matrix->m41, matrix->m42, matrix->m43,
	// 		matrix->m44);
	edge_len = sqrt(size);
	i = 0;
	while (i < edge_len)
	{
		j = 0;
		while (j < edge_len)
		{
			index = i * edge_len + j; // row-major order
			index = j * edge_len + i; // column-major order
			// printf("%2zu=%zu%zu=%5.0f, ", index, i + 1, j + 1, m[index]);
			printf("%5.0f, ", m[index]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

int	main(void)
{
	float	identity[MAT4_SIZE];
	float	a[MAT4_SIZE];
	float	b[MAT4_SIZE];
	float	tmp[MAT4_SIZE];
	float	tmp2[MAT4_SIZE];
	int		i;

	mat4_identity(identity);
	print_matrix(identity, MAT4_SIZE);
	mat4_identity(a);
	mat4_scalar_mult(identity, 7.f, tmp);
	print_matrix(tmp, MAT4_SIZE);
	mat4_mult(identity, tmp, tmp);
	print_matrix(tmp, MAT4_SIZE);
	i = 0;
	a[i] = 5;
	a[++i] = 2;
	a[++i] = 8;
	a[++i] = 3;
	a[++i] = 7;
	a[++i] = 3;
	a[++i] = 10;
	a[++i] = 3;
	a[++i] = 9;
	a[++i] = 3;
	a[++i] = 2;
	a[++i] = 4;
	a[++i] = 10;
	a[++i] = 8;
	a[++i] = 3;
	a[++i] = 8;
	i = 0;
	b[i] = 3;
	b[++i] = 12;
	b[++i] = 9;
	b[++i] = 3;
	b[++i] = 10;
	b[++i] = 1;
	b[++i] = 10;
	b[++i] = 12;
	b[++i] = 12;
	b[++i] = 4;
	b[++i] = 12;
	b[++i] = 4;
	b[++i] = 18;
	b[++i] = 9;
	b[++i] = 2;
	b[++i] = 10;
	mat4_mult(a, b, tmp);
	print_matrix(tmp, MAT4_SIZE);
	mat_transpose(tmp, 4, tmp2);
	print_matrix(tmp2, MAT4_SIZE);
	printf("det=%f\n", mat4_determinant(tmp2));
	printf("det=%f\n", mat4_determinant(a));
	printf("det=%f\n", mat4_determinant(b));
	printf("det=%f\n", mat4_determinant(identity));
}