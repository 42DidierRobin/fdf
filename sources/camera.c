/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:30:10 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/15 22:04:07 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fil_de_fer.h"

t_cam				*new_cam(t_3dpoint *pos, t_3dpoint *rot, double fov)
{
	t_cam		*ret;

	ret = (t_cam*)malloc(sizeof(t_cam));
	ret->amp = 1;
	ret->pos = pos;
	ret->rot = rot;
	ret->fov = fov;
	ret->line = 1;
	return (ret);
}

static void			move_cam_2(t_cam *cam, int key)
{
	if (key == 13)
		cam->pos->y = cam->pos->y + CAM_STEP;
	else if (key == 1)
		cam->pos->y = cam->pos->y - CAM_STEP;
	else if (key == 14)
		cam->pos->z = (cam->pos->z == -CAM_STEP) ? CAM_STEP :
			cam->pos->z + CAM_STEP;
	else if (key == 2)
		cam->pos->z = (cam->pos->z == CAM_STEP) ? -CAM_STEP :
			cam->pos->z - CAM_STEP;
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
}

static void			move_cam_3(t_cam *cam, int key, t_mlx *mlx)
{
	if (key == 36)
	{
		free(cam->pos);
		free(cam->rot);
		cam->pos = new_3dpoint(0, 0, 1000);
		cam->rot = new_3dpoint(0, 0, 0);
	}
	else if (key == 53)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		exit(0);
	}
}

void				move_cam(t_cam *cam, int key, t_mlx *mlx)
{
	move_cam_2(cam, key);
	move_cam_3(cam, key, mlx);
	if (key == 12)
		cam->pos->x = cam->pos->x + CAM_STEP;
	else if (key == 0)
		cam->pos->x = cam->pos->x - CAM_STEP;
	else if (key == 32)
	{
		cam->amp = cam->amp + (double)CAM_STEP / 100;
		if (cam->amp == 0)
			cam->amp = (double)CAM_STEP / 100;
	}
	else if (key == 38)
	{
		cam->amp = cam->amp - (double)CAM_STEP / 100;
		if (cam->amp == 0)
			cam->amp = -(double)CAM_STEP / 100;
	}
	else if (key == 24)
		cam->fov = cam->fov + CAM_STEP * 10;
	else if (key == 27)
		cam->fov = cam->fov - CAM_STEP * 10;
	else if (key == 49)
		cam->line = (cam->line == 0) ? 1 : 0;
}
