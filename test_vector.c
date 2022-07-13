/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:24:03 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/13 17:05:38 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

void	print_info(float *vec, size_t vec_size)
{
	float	len;
	float	len2;
	bool	is_zero;
	size_t	i;

	if (vec_size == 2)
	{
		len = vec2_length(vec);
		len2 = vec2_length_squared(vec);
		is_zero = vec2_is_zero(vec);
	}
	else if (vec_size == 3)
	{
		len = vec3_length(vec);
		len2 = vec3_length_squared(vec);
		is_zero = vec3_is_zero(vec);
	}
	else if (vec_size == 4)
	{
		len = vec4_length(vec);
		len2 = vec4_length_squared(vec);
		is_zero = vec4_is_zero(vec);
	}
	i = 0;
	while (i < vec_size)
	{
		printf("%.2f, ", vec[i]);
		i++;
	}
	printf("len=%.2f, len^2=%.2f, is_zero=%i\n", len, len2, is_zero);
}

int	main(void)
{
	const float		v4[4] = {1.f, 1.f, 1.f, 1.f};
	struct s_vec2	vec;
	float			vec_a[2];
	float			vec_b[2];
	float			*a;
	float			*b;
	float			position[VEC2_SIZE];
	float			homo[VEC4_SIZE];

	float			tmp[VEC2_SIZE];
	float			tmp4[VEC4_SIZE];
	vec.x = 1;
	vec.y = 2;
	print_vec2(&vec);
	a = &vec_a[0];
	b = &vec_b[0];
	a = vec2(0.f, 0.f, a);
	b = vec2(1.f, 1.f, b);
	vec2(2.5f, -0.25f, position);
	print_info(a, VEC2_SIZE);
	print_info(b, VEC2_SIZE);
	print_info(position, VEC2_SIZE);

	vec2_scalar_mult(b, 7.f, tmp);
	print_info(tmp, VEC2_SIZE);
	vec2_normalize(tmp, tmp);
	print_info(tmp, VEC2_SIZE);
	vec2_add(a, b, tmp);
	printf("a + b == (1,1)?: %i\n", vec2_is_equal(tmp, b));
	vec2_sub(b, a, tmp);
	printf("b - a == (1,1)?: %i\n", vec2_is_equal(tmp, b));
	printf("b * position = %f\n", vec2_dot(b, position));

	vec2(1.f, 0.f, a);
	vec2(0.f, 1.f, b);
	printf("(1, 0) * (0, 1) = %f\n", vec2_dot(a, b));
	printf("(0, 1) * (1, 0) = %f\n", vec2_dot(b, a));
	printf("(1, 0) * (1, 0) = %f\n", vec2_dot(a, a));
	printf("pos * pos = %f\n", vec2_dot(position, position));

	vec4(v4, homo);
	print_info(homo, VEC4_SIZE);
	vec4_normalize(homo, tmp4);
	print_info(tmp4, VEC4_SIZE);

	return (0);
}
