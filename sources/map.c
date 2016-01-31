/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 10:02:35 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/31 19:27:21 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

t_pix				*point_to_pix(t_cam *cam, int x, int y, int z)
{
	t_pix		*ret;
	t_3Dpoint	*vector1;
	t_3Dpoint	*vector2;
	t_3Dpoint	*temp;
	double		angleOx;
	double		angleOz;

	temp = new_3Dpoint(0, 1, 0);
	vector1 = new_3Dpoint(cam->plan[0], cam->plan[1], cam->plan[2]);
	vector2 = new_3Dpoint(x - cam->from->x, y - cam->from->y,
			z - cam->from->z);
	ret = (t_pix*)malloc(sizeof(t_pix));
	angleOx = fabs(give_angle(vector1, vector2) 
			* ((WINDOW_L) / 2) / cam->fov);
	angleOz = give_angle(temp, vector_on_screen(new_3Dpoint(x, y, z), cam));
	ret->x = (WINDOW_L) / 2 + (int)(angleOx * cos(angleOz));
	ret->y = (WINDOW_L) / 2 + (int)(angleOx * sin(angleOz));
	return (ret);
}

t_map				*new_map(int ***readed, t_cam *cam)
{
	int			i;
	int			j;
	t_map		*map;

	i = -1;
	map = (t_map*)malloc(sizeof(t_map));
	while (readed[++i])
		;
	map->map = (t_pix***)malloc(sizeof(t_pix**) * i);
	map->map[i] = NULL;
	i = -1;
	while (readed[++i])
	{
		j = -1;
		while (readed[i][++j])
			;
		map->map[i] = (t_pix**)malloc(sizeof(t_pix*) * j);
		j = -1;
		while (readed[i][++j])
			map->map[i][j] = point_to_pix(cam, i * PAS, j * PAS,
					*(readed[i][j]));
		map->map[i][j] = NULL;
	}
	return (map);
}
