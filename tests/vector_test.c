#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/theories.h>

#include <float.h>

#include "../vector.h"

#define VECTOR_DATA_POINTS DataPoints(float, 0, 1, 2, -1, -2, FLT_MIN, FLT_MAX, FLT_EPSILON, INFINITY) //, NAN)

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
}