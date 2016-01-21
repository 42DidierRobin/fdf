/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:53:21 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/21 16:14:36 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

t_pix				*new_pix(int x, int y, int z, int clr)
{
	t_pix		*ret;

	ret = (t_pix*)malloc(sizeof(t_pix));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	ret->rgb = clr;
	return (ret);
}

void				put_pix(t_mlx *mlx, t_pix *pix)
{
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, MAP_MARGIN_L + pix->x,
			MAP_MARGIN_H + pix->y, pix->rgb);
}

/*
void				print_map(t_map *map, t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->nbr_pix_h)
	{
		j = -1;
		while (++j < map->nbr_pix_l)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, 
					map->map[i][j].x + MAP_MARGIN_L,
					map->map[i][j].y + MAP_MARGIN_H,
					map->map[i][j].rgb);
		}
	}
}
*/
