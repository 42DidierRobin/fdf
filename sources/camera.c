/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:30:10 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/14 18:22:04 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TEMP
#include <stdio.h>
//TEMP

#include "../includes/file_de_fer.h"

//TEMP
void				print_cam(t_cam *cam)
{
	ft_putstr("Valeur de la camera actuelle : \n    Position: ");
	print_point(cam->pos);
	ft_putstr("    Angle: ");
	printf(" (%f, %f, %f)\n", cam->rot->x, cam->rot->y, cam->rot->z);
	ft_putstr("    fov: ");
	ft_putnbr(cam->fov);
	ft_putchar('\n');
}
//TEMP

t_cam				*new_cam(t_3Dpoint *pos, t_3Dpoint *rot, double fov)
{
	t_cam		*ret;

	ret = (t_cam*)malloc(sizeof(t_cam));
	ret->amp = 1;
	ret->pos = pos;
	ret->rot = rot;
	ret->fov = fov;
	return (ret);
}


void				move_cam(t_cam *cam, int key)
{
	if (key == 12)
		cam->pos->x = cam->pos->x + CAM_STEP;
	else if (key == 0)
		cam->pos->x = cam->pos->x - CAM_STEP;
	else if (key == 13)
		cam->pos->y = cam->pos->y + CAM_STEP;
	else if (key == 1)
		cam->pos->y = cam->pos->y - CAM_STEP;
	else if (key == 14)
		cam->pos->z = cam->pos->z + CAM_STEP;
	else if (key == 2)
		cam->pos->z = cam->pos->z - CAM_STEP;
	else if (key == 15)
		cam->rot->x = cam->rot->x + (double)CAM_STEP / 100;
	else if (key == 3)
		cam->rot->x = cam->rot->x - (double)CAM_STEP / 100;
	else if (key == 16)
		cam->rot->y = cam->rot->y + (double)CAM_STEP / 100;
	else if (key == 4)
		cam->rot->y = cam->rot->y - (double)CAM_STEP / 100;
	else if (key == 17)
		cam->rot->z = cam->rot->z + (double)CAM_STEP / 100;
	else if (key == 5)
		cam->rot->z = cam->rot->z - (double)CAM_STEP / 100;
	else if (key == 32)
	{
		cam->amp = cam->amp + (double)CAM_STEP / 100;
		if (cam->amp == 0)
			cam->amp = (double)CAM_STEP / 100;
	}
	else if (key == 38)
	{
		cam->amp = cam->amp - (double)CAM_STEP / 100;
		if (!cam->amp == 0)
			cam->amp = -(double)CAM_STEP / 100;
	}
	else if (key == 24)
		cam->fov = cam->fov + CAM_STEP * 10;
	else if (key == 27)
		cam->fov = cam->fov - CAM_STEP * 10;
}
