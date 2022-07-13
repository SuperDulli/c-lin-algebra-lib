/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:24:03 by chelmerd          #+#    #+#             */
/*   Updated: 2022/07/13 13:32:07 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "vector.h"

int	main(void)
{
	struct s_vec2	vec;

	vec.x = 1;
	vec.y = 2;
	print_vec2(&vec);
	return (0);
}
