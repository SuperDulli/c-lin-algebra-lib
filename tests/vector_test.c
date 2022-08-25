#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../vector.h"

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
	// cr_assert(eq(int, VEC3_SIZE, 3), "vector3 size is not 3.");
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
