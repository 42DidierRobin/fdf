/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 10:02:35 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/01 19:32:45 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

t_pix				*point_to_pix(t_cam *cam, int x, int y, int z)
{
	t_pix		*ret;
	t_3Dpoint	*vector1;
	t_3Dpoint	*vector2;
	t_3Dpoint	*temp;
	double		angle1;
	double		angle2;

	temp = new_3Dpoint(0, 1, 0);
	vector1 = new_3Dpoint(cam->plan[0], cam->plan[1], cam->plan[2]);
	vector2 = new_3Dpoint(x - cam->from->x, y - cam->from->y,
			z - cam->from->z);
	ret = (t_pix*)malloc(sizeof(t_pix));
	angle1 = fabs(give_angle(vector1, vector2)); 
	angle2 = give_angle_test(temp, vector_on_screen(new_3Dpoint(x, y, z), cam));
	printf("point (%d, %d). Angle1 = %f, angle2 = %f", x/PAS, y/PAS, angle1 * 57.2958, angle2 * 57.2958);
	angle1 = angle1 * ((WINDOW_L) / 2) / cam->fov;
	ret->x = MARGE_L + (int)(angle1 * cos(angle2));
	ret->y = MARGE_W + (int)(angle1 * sin(angle2));
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
