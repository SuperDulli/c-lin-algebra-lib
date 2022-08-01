# c-lin-algebra-lib

A library for doing linear algebra in C for doing computer graphics.

## Contents

All functions "should" work for two, three and 4 Dimensions.

In general Functions will
 - return the result (either a scalar or address of the result object)
 - take input parameters
 - take output parameters (address which values should be changed).

### Vector

| function prototype | Description | Notes |
| :---               |    :----    | :---  |
| `float *vecN(float x, float y, ..., float *result)` | fills the vector with the params | N is the Dimension (2, 3 or 4) |
| `float *vecN_copy(float vec, float *result)` | copies the values |  |
| `float vecN_length(float *vec)` | calculate the length | len = &#124;vec&#124; |
| `float *vecN_scalar_mult(float *vec, float s, float *result)` | multiplies each element with parameter s | result = s * vec |
| `float *vecN_normalize(float *vec, float *result)` | changes the components of the vector to make it a unit vector | unit_vector_len = &#124;vec&#124; = 1 |
| `float *vecN_add(float *v1, float *v2, float *result)` | adds the two vector together (component-wise) | result = v1 + v2 |
| `float vecN_dot(float *v1, float *v2)` | dot product | result (scalar) = v1 * v2 |
| `bool vecN_is_zero(float *vec)` | test if the vector is zero length / all components are zero | &#124;vec&#124; == 0 |
| `bool vecN_is_equal(float *v1, float *v2)` | test if the two vectors are the same | v1 == v2 |
| `float *vec3_cross(float *v1, float *v2, float *result)` | cross product | result = v1 x v2 |

### Matrix

all:
- create (zero, identity)
- copy
- add
- determinant
- inverse
- transpose

exclusive for 4D:
- scale
- translate
- rotate (X, Y, Z)
- scalar multiplication
- matrix multiplication

## usage

1. `make`
- all (build the static library ending in .a)
- v (test vector - optional)
- m (test matrix - optional)
- clean (remove intermediate files)
- fclean (fully clean the dir - removes the library and all intermediates)

2. include the relevant header(s):
```
#include "vector.h"
#include "matrix.h"
```

3. profit 
