/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 10:02:35 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/02 18:27:55 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

static double			**give_final_matrix(t_cam *cam)
{
	double			**m_ori_translation;
	double			**m_theta_rot;
	double			**m_phi_rot;
	double			**m_miror;
	double			**ret;

	m_ori_translation = give_translation_matrix(
			new_3Dpoint(-cam->eye_coord->x, -cam->eye_coord->y, -cam->eye_coord->z));
	print_matrix(4,m_ori_translation);
	m_theta_rot = give_rotation_matrix(new_3Dpoint(0,0,1), - 1.57 + cam->eye_theta);
	print_matrix(4,m_theta_rot);
	m_phi_rot = give_rotation_matrix(new_3Dpoint(1,0,0),  1.57 + cam->eye_theta);
	print_matrix(4,m_phi_rot);
	m_miror = give_homothety_matrix(1);
	print_matrix(4,m_miror);
	m_miror[0][0] = -1;
	ret = mult_matrix(m_ori_translation, mult_matrix(m_theta_rot, mult_matrix(m_phi_rot, m_miror, 4), 4), 4);
	print_matrix(4, ret);
	return (ret);
}

static t_pix		*point_to_pix(double **matrix, int x, int y, int z)
{
	t_3Dpoint	*point;
	t_pix		*ret;

	point = new_3Dpoint(x,y,z);
	matrix_on_point(point, matrix);
	point_homo_to_cart(point);
	ret = new_pix((int)(point->x / z), (int)(point->y / z), z);
	return (ret);
}


t_map				*new_map(int ***readed, t_cam *cam)
{
	int			i;
	int			j;
	t_map		*map;
	double			**final_matrix;

	final_matrix = give_final_matrix(cam);
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
			map->map[i][j] = point_to_pix(final_matrix, i * PAS, j * PAS,
					*(readed[i][j]));
		map->map[i][j] = NULL;
	}
	return (map);
}
