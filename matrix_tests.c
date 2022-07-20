/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:26:36 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/20 13:18:08 by chelmerd         ###   ########.fr       */
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
			printf("%5.2f, ", m[index]);
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
	float	d2_a[MAT2_SIZE];
	float	d2_tmp[MAT2_SIZE];

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
	d2_a[0] = 4;
	d2_a[1] = 5;
	d2_a[2] = -7;
	d2_a[3] = 3;
	print_matrix(d2_a, MAT2_SIZE);
	mat2_inverse(d2_a, d2_tmp);
	print_matrix(d2_tmp, MAT2_SIZE);

	float d3_a[MAT3_SIZE];
	float d3_tmp[MAT3_SIZE];
	d3_a[0] = 4;
	d3_a[1] = 5;
	d3_a[2] = -7;
	d3_a[3] = 3;
	d3_a[4] = -2;
	d3_a[5] = 0;
	d3_a[6] = 1;
	d3_a[7] = -42;
	d3_a[8] = 42;
	print_matrix(d3_a, MAT3_SIZE);
	mat3_inverse(d3_a, d3_tmp);
	print_matrix(d3_tmp, MAT3_SIZE);

	float d4_a[MAT4_SIZE];
	float d4_tmp[MAT4_SIZE];
	d4_a[0] = 4;
	d4_a[1] = 5;
	d4_a[2] = -7;
	d4_a[3] = 3;
	d4_a[4] = -2;
	d4_a[5] = 0;
	d4_a[6] = 1;
	d4_a[7] = -42;
	d4_a[8] = 42;
	d4_a[9] = 0;
	d4_a[10] = 10;
	d4_a[11] = 11;
	d4_a[12] = 12;
	d4_a[13] = 13;
	d4_a[14] = 14;
	d4_a[15] = 15;
	print_matrix(d4_a, MAT4_SIZE);
	mat4_inverse(d4_a, d4_tmp);
	print_matrix(d4_tmp, MAT4_SIZE);

	printf("Transformation matricies:\n");
	float scaling[MAT4_SIZE];
	float translating[MAT4_SIZE];
	float rotation_x[MAT4_SIZE];
	float rotation_y[MAT4_SIZE];
	float rotation_z[MAT4_SIZE];
	mat4_scale(1, 7, 49, scaling);
	mat4_translate(-1, -2, 3, translating);
	mat4_rotate_x(7, rotation_x);
	mat4_rotate_y(7, rotation_y);
	mat4_rotate_z(7, rotation_z);
	print_matrix(scaling, MAT4_SIZE);
	print_matrix(translating, MAT4_SIZE);
	print_matrix(rotation_x, MAT4_SIZE);
	print_matrix(rotation_y, MAT4_SIZE);
	print_matrix(rotation_z, MAT4_SIZE);

	printf("comibined transforms:\n");
	mat4_mult(translating, scaling, tmp);
	mat4_mult(tmp, rotation_x, tmp);
	mat4_mult(tmp, rotation_y, tmp);
	mat4_mult(tmp, rotation_z, tmp);
	print_matrix(tmp, MAT4_SIZE);
}
