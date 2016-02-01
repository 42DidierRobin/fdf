/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:01:57 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/01 19:33:06 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

#include <stdio.h>

double 			give_angle_test(t_3Dpoint *u, t_3Dpoint *v)
{
	int 	scalaire;
	double	normeU;
	double 	normeV;

	scalaire = u->x * v->x + u->y * v->y ;
	normeU = sqrt(u->x * u->x + u->y * u->y );
	normeV = sqrt(v->x * v->x + v->y * v->y );
	if (normeU * normeV)
		return (acos((scalaire / (normeU * normeV))));
	return (0);
}

double 			give_angle(t_3Dpoint *u, t_3Dpoint *v)
{
	int 	scalaire;
	double	normeU;
	double 	normeV;

	scalaire = u->x * v->x + u->y * v->y + u->z * v->z;
	normeU = sqrt(u->x * u->x + u->y * u->y + u->z * u->z);
	normeV = sqrt(v->x * v->x + v->y * v->y + v->z *v->z);
	if (normeU * normeV)
		return (acos((scalaire / (normeU * normeV))));
	return (0);
}

t_3Dpoint		*vector_on_screen(t_3Dpoint *u, t_cam *cam)
{
	t_3Dpoint	*ret;
	double		temp;

	ret = new_3Dpoint(0, 0, 0);
	temp = - (cam->plan[0] * u->x + cam->plan[1] * u->y + cam->plan[2] *
			u->z + cam->plan[3]) / (cam->plan[0] * cam->plan[0] + cam->plan[1] *
				cam->plan[1] + cam->plan[2] * cam->plan[2]);
	ret->x = u->x + cam->plan[0] * temp + cam->plan[0];
	ret->y = u->y + cam->plan[1] * temp + cam->plan[1];
	ret->z = u->z + cam->plan[2] * temp + cam->plan[2];
	return (ret);
}
