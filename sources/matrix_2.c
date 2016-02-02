/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:41:08 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/02 18:20:37 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

double			**give_rotation_matrix(t_3Dpoint *u, double a)
{
	double			**ret;
	double			c;
	double			s;

	c = cos(a);
	s = sin(a);
	ret = give_null_matrix(4);
	ret[3][3] = 1;
	ret[0][0] = u->x * u->x * (1 - c) + c;
	ret[0][1] = u->x * u->y * (1 - c) - s * u->z;
	ret[0][2] = u->x * u->z * (1 - c) + s * u->y;
	ret[1][0] = u->x * u->y * (1 - c) + s * u->z;
	ret[1][1] = u->y * u->y * (1 - c) + c;
	ret[1][2] = u->y * u->z * (1 - c) - s * u->x;
	ret[2][0] = u->x * u->z * (1 - c) - s * u->y;
	ret[2][1] = u->y * u->z * (1 - c) + s * u->x;
	ret[2][2] = u->z * u->z * (1 - c) + c;
	return (ret);
}

void		matrix_on_point(t_3Dpoint *point, double **m)
{
	point->x = m[0][0] * point->x + m[0][1] * point->y + m[0][2] * point->z + m[0][3] * point->z;
	point->y = m[1][0] * point->x + m[1][1] * point->y + m[1][2] * point->z + m[1][3] * point->z;
	point->z = m[2][0] * point->x + m[2][1] * point->y + m[2][2] * point->z + m[2][3] * point->z;
	point->t = m[3][0] * point->x + m[3][1] * point->y + m[3][2] * point->z + m[3][3] * point->z;
}
