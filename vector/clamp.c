/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:52:13 by chelmerd          #+#    #+#             */
/*   Updated: 2022/08/10 11:59:02 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static
float	ft_maxf(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static
float	ft_minf(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	*vec3_clamp(float *vec, float lower, float upper, float *result)
{
	result[0] = ft_maxf(lower, ft_minf(vec[0], upper));
	result[1] = ft_maxf(lower, ft_minf(vec[1], upper));
	result[2] = ft_maxf(lower, ft_minf(vec[2], upper));
	return (result);
}
