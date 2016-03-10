/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 10:02:35 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/10 16:08:08 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

static t_pix		*point_to_pix(double **matrix, t_3Dpoint *point, int d)
{
	t_pix		*pix;

	matrix_on_point(point, matrix);
	// TEMP
	ft_putstr("Point apres passage de la matrice : \n");
	print_point(point);
	// TEMP
	pix = new_pix(d*point->x, d*point->y, point->z);
	return (pix);
}

static int			*pre_map(int ***readed, t_map **map)
{
	int		i;
	int		j;
	int		*ret;

	ret = (int*)malloc(sizeof(int) * 2);
	ret[1] = 0;
	i = -1;
	while (readed[++i])
		;
	(*map)->map = (t_pix***)malloc(sizeof(t_pix**) * i);
	(*map)->map[i] = NULL;
	ret[0] = i / 2;
	i = -1;
	while (readed[++i])
	{
		j = -1;
		while (readed[i][++j])
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
	double			**final;

	cam->pos->x = cam->pos->x + 1 - 1;
	final = give_null_matrix(4);
	final[0][0] = 1;
	final[1][1] = 1;
	final[2][2] = 1;
	return (final);
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
	cam++;
	map = (t_map*)malloc(sizeof(t_map));
	mid = pre_map(readed, &map);
	i = -1;
	while (readed[++i])
	{
		j = -1;
		while (readed[i][++j])
		{
			point = new_3Dpoint((i - mid[0]) * PAS, (j - mid[1]) * PAS, *readed[i][j] * PAS);
			//TEMP
			ft_putstr("\n\nPoint avant creation map :\n");
			print_point(point);
			//TEMP
			map->map[i][j] = point_to_pix(final_matrix, point, 1);
		}
	}
	return (map);
}
