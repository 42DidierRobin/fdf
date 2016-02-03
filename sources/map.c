/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 10:02:35 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/03 13:18:10 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

static t_pix		*point_to_pix(int x, int y, int z)
{
	t_pix	*pix;

	pix = new_pix(x,y,z);
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

t_map				*new_map(int ***readed, t_cam *cam)
{
	int			i;
	int			j;
	int			*mid;
	t_map		*map;

	cam++;
	map = (t_map*)malloc(sizeof(t_map));
	mid = pre_map(readed, &map);
	i = -1;
	while (readed[++i])
	{
		j = -1;
		while (readed[i][++j])
			map->map[i][j] = point_to_pix((i - mid[0]), (j - mid[1]),
					*(readed[i][j]));
	}
	return (map);
}
