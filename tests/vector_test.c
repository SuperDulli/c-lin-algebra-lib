#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/theories.h>
#include <criterion/parameterized.h>

#include <float.h>

#include "../vector.h"

#define VECTOR_DATA_POINTS DataPoints(float, 0, 0.1, 0.5, 1, 2, -1, -2) //, FLT_MIN, FLT_MAX, FLT_EPSILON, INFINITY) //, NAN)

int	cr_user_s_vec3_eq(struct s_vec3 *a, struct s_vec3 *b)
{
	return (
		a->x == b->x && \
		a->z == b->y && \
		a->z == b->z
	);
}

char	*cr_user_s_vec3_tostr(struct s_vec3 *vec)
{
	char	*out;
	cr_asprintf(&out, "(struct s_vec3) { x=%f, y=%f, z=%f }", vec->x, vec->y, vec->z);
	return (out);
}

char	*vec3_tostr(float *vec)
{
	char	*out;
	cr_asprintf(&out, "(vec3) { x=%f, y=%f, z=%f }", vec[0], vec[1], vec[2]);
	return (out);
}

Test(vector3, size)
{
	cr_log_info("vec3 size: %d", VEC3_SIZE);
	cr_assert(eq(int, VEC3_SIZE, 3), "vector3 size is not 3.");
}

Test(vector3, create_zero)
{
	float			vector[VEC3_SIZE];
	float			*v_pointer;
	float			zero_vector[VEC3_SIZE];
	struct s_vec3	zero_vector_s;

	zero_vector[0] = 0.f;
	zero_vector[1] = 0.f;
	zero_vector[2] = 0.f;
	zero_vector_s.x = 0.f;
	zero_vector_s.y = 0.f;
	zero_vector_s.z = 0.f;
	v_pointer = vec3(0, 0, 0, vector);
	cr_expect(eq(ptr, v_pointer, &vector[0]), "return value points somewhere else.");
	cr_expect(eq(flt[VEC3_SIZE], vector, zero_vector), "vector has wrong values.");
	cr_log_info("zero: %s", cr_user_s_vec3_tostr(&zero_vector_s)); //
	// cr_expect(ne(type(struct s_vec3), (struct s_vec3*) vector, zero_vector_s));
}

Test(vector3, fill_zero)
{
	float	vector[VEC3_SIZE];
	float	zero_vector[VEC3_SIZE];

	zero_vector[0] = 0.f;
	zero_vector[1] = 0.f;
	zero_vector[2] = 0.f;
	vec_fill(0.f, VEC3_SIZE, vector);
	cr_expect(eq(flt[VEC3_SIZE], vector, zero_vector));
}

Test(vector3, copy)
{
	float	src[VEC3_SIZE];
	float	dst[VEC3_SIZE];

	vec3(1, 2, 3, src);
	vec3_copy(src, dst);
	cr_expect(ne(ptr, &src[0], &dst[0]), "copy should be deep.");
	cr_expect(eq(flt[VEC3_SIZE], src, dst), "values should be the same after copy.");
}

TheoryDataPoints(vector3, length_is_non_negative) =
{
	VECTOR_DATA_POINTS,
	VECTOR_DATA_POINTS,
	VECTOR_DATA_POINTS
};

Theory((float a, float b, float c), vector3, length_is_non_negative)
{
	float	vec[VEC3_SIZE];
	float	len;
	float	zero;

	vec3(a, b, c, vec);
	zero = 0.f;
	len = vec3_length(vec);
	// cr_log_info("(a,b,c): %f, %f, %f", vec[0], vec[1], vec[2]);
	// cr_log_info("vec_length: %f", len);
	cr_expect(ge(len, zero), "length of vector should not be negative.");
	len = vec3_length_squared(vec);
	// cr_log_info("vec_length: %f", len);
	cr_expect(ge(len, zero), "length squared of vector should not be negative.");
}

// TODO: test scalar multiplication

TheoryDataPoints(vector3, normalize) =
{
	VECTOR_DATA_POINTS,
	VECTOR_DATA_POINTS,
	VECTOR_DATA_POINTS
};

Theory((float a, float b, float c), vector3, normalize)
{
	float	vec[VEC3_SIZE];
	float	len;
	float	one;

	vec3(a, b, c, vec);
	one = 1.f;
	// cr_log_info("(a,b,c) before: %f, %f, %f", vec[0], vec[1], vec[2]);
	// normalizing a zero vector makes no sense
	cr_assume_not(a == 0 && b == 0 && c == 0);
	vec3_normalize(vec, vec);
	len = vec3_length(vec);
	// cr_log_info("(a,b,c) after : %f, %f, %f", vec[0], vec[1], vec[2]);
	// cr_log_info("vec_length: %f", len);
	cr_expect(epsilon_eq(flt, len, one, FLT_EPSILON), "normalized vector should be of length one.");
}

TheoryDataPoints(vector3, dot_product) =
{
	VECTOR_DATA_POINTS,
	VECTOR_DATA_POINTS,
	VECTOR_DATA_POINTS,
	VECTOR_DATA_POINTS,
	VECTOR_DATA_POINTS,
	VECTOR_DATA_POINTS
};

Theory((float a, float b, float c, float x, float y, float z), vector3, dot_product, .disabled=1)
{
	float	v1[VEC3_SIZE];
	float	v2[VEC3_SIZE];
	float	dot_product;

	vec3(a, b, c, v1);
	vec3(x, y, z, v2);
	dot_product = vec3_dot(v1, v2);
	cr_log_info("dot_product of %s and %s = %f", vec3_tostr(v1), vec3_tostr(v2), dot_product);
}

struct params_binary_operation_scalar_result
{
	float	a_x, a_y, a_z;
	float	b_x, b_y, b_z;
	float	result;
};

ParameterizedTestParameters(vector3, dot_product_params)
{
	static struct params_binary_operation_scalar_result params[] =
	{
		{
			0, 0, 0,
			0, 0, 0,
			0
		},
		{
			0, 0, 0,
			1, 0, 0,
			0
		},
		{
			1, 0, 0,
			0, 0, 0,
			0
		},
		{
			0, 1, 0,
			0, 1, 0,
			1
		},
		{
			0, -1, 0,
			0, -1, 0,
			1
		},
		{
			0, 1, 0,
			0, -1, 0,
			-1
		},
		{
			0, 1, 0,
			0, 0, 1,
			0
		},
		{
			0, 1, 0,
			1, 0, 1,
			0
		},
		{
			1, 1, 0,
			1, 0, 1,
			1
		},
		{
			3, 4, 5,
			1, 0, 0,
			3
		},
		{
			3, 4, 5,
			1, 1, 0,
			7
		},
	};

	return (cr_make_param_array(struct params_binary_operation_scalar_result, params, sizeof(params) / sizeof(struct params_binary_operation_scalar_result)));
}

ParameterizedTest(struct params_binary_operation_scalar_result *tupel, vector3, dot_product_params)
{
	float	v1[VEC3_SIZE];
	float	v2[VEC3_SIZE];
	float	dot_product;

	vec3(tupel->a_x, tupel->a_y, tupel->a_z, v1);
	vec3(tupel->b_x, tupel->b_y, tupel->b_z, v2);
	dot_product = vec3_dot(v1, v2);
	cr_expect(epsilon_eq(flt, dot_product, tupel->result, FLT_EPSILON), "dot_product of %s and %s = %f == %f", vec3_tostr(v1), vec3_tostr(v2), dot_product, tupel->result);
}

TheoryDataPoints(vector3, shift_positive) =
{
	VECTOR_DATA_POINTS,
	VECTOR_DATA_POINTS,
	VECTOR_DATA_POINTS
};

Theory((float a, float b, float c), vector3, shift_positive)
{
	float	vec[VEC3_SIZE];

	vec3(a, b, c, vec);
	cr_assume_geq(vec[0], -1.f);
	cr_assume_geq(vec[1], -1.f);
	cr_assume_geq(vec[2], -1.f);
	cr_assume_leq(vec[0], 1.f);
	cr_assume_leq(vec[1], 1.f);
	cr_assume_leq(vec[2], 1.f);
	vec3_shift_positive(vec, vec);
	cr_expect(all(ge(flt, vec[0], 0), ge(flt, vec[1], 0), ge(flt, vec[2], 0)), "values should all be atleast 0 or higher.");
	cr_expect(all(le(flt, vec[0], 1), le(flt, vec[1], 1), le(flt, vec[2], 1)), "values should all be 1 at max.");
}
