/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:30:10 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/01 19:28:07 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

t_3Dpoint			*new_3Dpoint(int x, int y, int z)
{
	t_3Dpoint		*ret;

	ret = (t_3Dpoint*)malloc(sizeof(t_3Dpoint));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

t_cam				*new_cam(t_3Dpoint *ori, t_3Dpoint *fuite,  double fov)
{
	t_cam		*ret;

	ret = (t_cam*)malloc(sizeof(t_cam));
	ret->to = fuite;
	ret->from = ori;
	ret->fov = fov;
	ret->plan[0] = ret->to->x - ret->from->x;
	ret->plan[1] = ret->to->y - ret->from->y;
	ret->plan[2] = ret->to->z - ret->from->z;
	ret->plan[3] = - (ret->plan[0] * ret->from->x + ret->plan[1] * ret->from->y
			+ ret->plan[2] * ret->from->z);
	return (ret);
}
