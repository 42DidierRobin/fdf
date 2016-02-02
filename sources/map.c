/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 10:02:35 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/02 12:08:05 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"
/*
t_pix				*point_to_pix(t_cam *cam, int x, int y, int z)
{

}
*/

t_map				*new_map(int ***readed, t_cam *cam)
{
	int			i;
	int			j;
	t_map		*map;

//TEMP
	cam = cam + 1;

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
			//map->map[i][j] = point_to_pix(cam, i * PAS, j * PAS,
			//		*(readed[i][j]));
		map->map[i][j] = NULL;
	}
	return (map);
}
