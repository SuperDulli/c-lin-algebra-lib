/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:27:06 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/13 13:30:46 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "vector.h"

void	print_vec2(struct s_vec2 *vec)
{
	printf("vector2(%f,%f,[%f,%f])\n", vec->x, vec->y, vec->v[0], vec->v[1]);
}
