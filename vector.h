/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:48:26 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/13 13:44:06 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include <math.h>

# define VEC2_SIZE 2
# define VEC3_SIZE 3
# define VEC4_SIZE 4

struct s_vec2
{
	union
	{
		struct
		{
			float	x;
			float	y;
		};
		float	v[VEC2_SIZE];
	};
};

struct s_vec3
{
	union
	{
		struct
		{
			float	x;
			float	y;
			float	z;
		};
		float	v[VEC3_SIZE];
	};
};

struct s_vec4
{
	union
	{
		struct
		{
			float	x;
			float	y;
			float	z;
			float	w;
		};
		float	v[VEC4_SIZE];
	};
};

void	print_vec2(struct s_vec2 *vec);

#endif
