/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 10:02:35 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/14 18:31:04 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

static t_pix		*point_to_pix(double **matrix, t_3Dpoint *point, t_cam *cam, t_map *map)
{
	t_pix		*pix;
	int			oldz;

	oldz = point->z;
	if (point->z < map->zmin)
		map->zmin = point->z;
	if (point->z > map->zmax)
		map->zmax = point->z;
	point->z = point->z * PAS * cam->amp;
	matrix_on_point(point, matrix);
	pix = new_pix((cam->fov / point->z) * point->x, 
			(cam->fov / point->z) * point->y, oldz);
	return (pix);
}

static int			*pre_map(t_map **map)
{
	int		i;
	int		j;
	int		*ret;

	ret = (int*)malloc(sizeof(int) * 2);
	ret[1] = 0;
	i = -1;
	while ((*map)->readed[++i])
		;
	(*map)->map = (t_pix***)malloc(sizeof(t_pix**) * i + 1);
	(*map)->map[i] = NULL;
	ret[0] = i / 2;
	i = -1;
	while ((*map)->readed[++i])
	{
		j = -1;
		while ((*map)->readed[i][++j])
			ret[1]++;
		(*map)->map[i] = (t_pix**)malloc(sizeof(t_pix*) * j + 1);
		(*map)->map[i][j] = NULL;
	}
	ret[1] = ret[1] / j;
	return (ret);
}

static double		**give_final_matrix(t_cam *cam)
{
	double			**to_cam_matrix;
	t_3Dpoint		*p;

	p = new_3Dpoint(-cam->pos->x, -cam->pos->y, -cam->pos->z);
	to_cam_matrix = mult_matrix(mult_matrix(give_rotation_matrix_z(-cam->rot->z), 
				give_rotation_matrix_y(-cam->rot->y), 4),
			give_rotation_matrix_x(-cam->rot->x), 4);
	to_cam_matrix = add_matrix(to_cam_matrix,give_translation_matrix(p),4);
	to_cam_matrix[3][3] = 1;
	return (to_cam_matrix);
}

t_map                *update_map(t_map *map, t_cam *cam)
{
    int     i;
    int     j;
    t_map	*newm;

    i = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            free(map->map[i][j]);
            j++;
        }
        free(map->map[i]);
        i++;
    }
    free(map->map);
    newm = new_map(map->readed, cam);
	newm->clr_from = map->clr_from;
	newm->clr_to = map->clr_to;
	map->readed = NULL;
	free(map);
	return (newm);
}

t_map				*new_map(int ***readed, t_cam *cam)
{
	int			i;
	int			j;
	int			*mid;
	t_map		*map;
	t_3Dpoint	*point;
	double		**final_matrix;

	final_matrix = give_final_matrix(cam);
	map = (t_map*)malloc(sizeof(t_map));
    map->readed = readed;
	map->zmin = 0;
	map->zmax = 0;
	mid = pre_map(&map);
	i = -1;
	while (readed[++i])
	{
		j = -1;
		while (readed[i][++j])
		{
			point = new_3Dpoint((i - mid[0]) * PAS, (j - mid[1]) * PAS, *readed[i][j]);
			map->map[i][j] = point_to_pix(final_matrix, point, cam, map);
		}
	}
	return (map);
}
