/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:41:08 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/02 14:42:21 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

void		matrix_on_point(t_3Dpoint *point, int m[4][4])
{
	point->x = m[0][0] * point->x + m[0][1] * point->y + m[0][2] * point->z + m[0][3] * point->z;
	point->y = m[1][0] * point->x + m[1][1] * point->y + m[1][2] * point->z + m[1][3] * point->z;
	point->z = m[2][0] * point->x + m[2][1] * point->y + m[2][2] * point->z + m[2][3] * point->z;
	point->t = m[3][0] * point->x + m[3][1] * point->y + m[3][2] * point->z + m[3][3] * point->z;
}
