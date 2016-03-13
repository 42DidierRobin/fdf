/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 10:02:35 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/10 18:31:06 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

static t_pix		*point_to_pix(double **matrix, t_3Dpoint *point, int fov)
{
	t_pix		*pix;

	matrix_on_point(point, matrix);
	pix = new_pix(fov / point->z * point->x, 
			fov / point->z * point->y, point->z);
	// TEMP
	//ft_putstr("Point apres passage de la matrice : \n");
	//print_point(point);
	//print_pix(pix);
	// TEMP
	
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
	(*map)->map = (t_pix***)malloc(sizeof(t_pix**) * i);
	(*map)->map[i] = NULL;
	ret[0] = i / 2;
	i = -1;
	while ((*map)->readed[++i])
	{
		j = -1;
		while ((*map)->readed[i][++j])
			ret[1]++;
		(*map)->map[i] = (t_pix**)malloc(sizeof(t_pix*) * j);
		(*map)->map[i][j] = NULL;
	}
	ft_putnbr(j);
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
	//TEMP
	//ft_putstr("Matrice de camera : \n");
	//print_matrix(4, to_cam_matrix);
	//TEMP
	return (to_cam_matrix);
}

void                update_map(t_map *map, t_cam *cam)
{
    int     i;
    int     j;
    
    i = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            del_pix(&(map->map[i][j]));
            map->map[i][j] = NULL;
            j++;
        }
        free(map->map[i]);
        i++;
    }
    free(map->map);
    map = new_map(map->readed, cam);
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
	mid = pre_map(&map);
	i = -1;
	while (readed[++i])
	{
		j = -1;
		while (readed[i][++j])
		{
			point = new_3Dpoint((i - mid[0]) * PAS, (j - mid[1]) * PAS, *readed[i][j] * PAS);
			//TEMP
			//ft_putstr("\n\nPoint avant creation map :\n");
			//print_point(point);
			//ft_putnbr(cam->fov);
			//TEMP
			map->map[i][j] = point_to_pix(final_matrix, point, cam->fov);
		}
	}
	return (map);
}
