/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:55:35 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/13 18:01:47 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix.h"

float	*mat4_zero(float *result)
{
	size_t	i;

	i = 0;
	while (i < MAT4_SIZE)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}

float	*mat4_identity(float *result)
{
	size_t	i;

	i = 0;
	while (i < MAT4_SIZE)
	{
		if (i % 5 == 0)
			result[i] = 1;
		else
			result[i] = 0;
		i++;
	}
	return (result);
}
