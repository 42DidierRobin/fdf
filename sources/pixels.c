/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:53:21 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/20 12:17:10 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

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

t_map				*grid_to_map(t_grid *grid)
{
	t_map		*map;
	int			i;
	int			j;

	i = -1;
	map = (t_map*)malloc(sizeof(t_map));
	map->nbr_pix_l = grid->length;
	map->nbr_pix_h = grid->height;
	map->map = (t_pix**)malloc(sizeof(t_pix*) * map->nbr_pix_h);
	while (++i < map->nbr_pix_h)
		map->map[i] = (t_pix*)malloc(sizeof(t_pix) * map->nbr_pix_l);
	i = -1;
	while (++i < map->nbr_pix_h)
	{
		j = -1;
		while (++j < map->nbr_pix_l)
		{
			map->map[i][j].y = i * PIX_MARGIN;
			map->map[i][j].x = j * PIX_MARGIN;
			map->map[i][j].z = grid->tab[i][j];
			map->map[i][j].rgb = 0xFF0000;
		}
	}
	return (map);
}
