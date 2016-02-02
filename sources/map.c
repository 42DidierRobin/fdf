/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 10:02:35 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/02 17:43:24 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

static int			**give_final_matrix(t_vision *cam)
{
	int				**m_ori_translation;
	int				**m_theta_rot;
	int				**m_phi_rot;
	int				**m_miror;
	int				**ret;

	m_ori_translation = give_translation_matrix(
			new_3Dpoint(-cam->eye_coord->x, -cam->eye_coord->y, -cam->eye_coord->z));
	//print_matrix(m_ori_translation);
	m_theta_rot = give_rotation_matrix(new_3Dpoint(0,0,1), - 1.57 + cam->eye_theta);
	//print_matrix(m_theta_rot);
	m_phi_rot = give_rotation_matrix(new_3Dpoint(1,0,0),  1.57 + cam->eye_theta);
	//print_matrix(m_phi_rot);
	m_miror = give_homothety_matrix(1);
	//print_matrix(m_miror);
	m_miror[0][0] = -1;
	ret = mult_matrix(m_oori_translation, mult_matrix(m_theta_rot, mult_matrix(m_phi_rot, m_miror)));
	return (ret);
}

static t_pix		*point_to_pix(t_cam *cam, int x, int y, int z)
{
	int			**final_matrix;

	final_matrix = give_final_matrix(cam);

}


t_map				*new_map(int ***readed, t_vision *cam)
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
