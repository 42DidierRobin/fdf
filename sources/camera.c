/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:30:10 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/02 14:18:28 by rdidier          ###   ########.fr       */
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
	ret->t = 1; 
	return (ret);
}
/*
t_cam				*new_cam(t_3Dpoint *ori, t_3Dpoint *fuite,  double fov)
{
	t_cam		*ret;

	return (ret);
}
*/
