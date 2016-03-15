/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:20:18 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/15 14:13:40 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TEMP
#include <stdio.h>
//TEMP

#include "../includes/file_de_fer.h"

//TEMP
void			print_color(t_color *clr)
{
	ft_putstr("Couleur : (r=");
	ft_putnbr(clr->r);
	ft_putstr(" ;g=");
	ft_putnbr(clr->g);
	ft_putstr(" ;b=");
	ft_putnbr(clr->b);
	ft_putstr(")\n");
}
//TEMP

void			draw_line(t_mlx *mlx, t_pix *a, t_pix *b, t_map *map)
{
	double		xi;
	double		yi;
	double		zi;
	int			i;
	int			step;
	t_pix		*pix;
	t_color		*clr;

	i = -1;
	pix = new_pix(a->x, a->y, a->oldz);
	if (abs(a->x - b->x) <= abs(a->y - b->y))
		step = 1 + abs(a->y - b->y);
	else 
		step = 1 + abs(a->x - b->x);
	xi = (double)(b->x - a->x) / step;
	yi = (double)(b->y - a->y) / step;
	zi = (double)(b->oldz - a->oldz) / step;
	while (++i < step)
	{
		clr = give_color(pix->oldz, map);
		put_pix(mlx, pix, clr);
		pix->x = a->x + round((double)i * xi);
		pix->y = a->y + round((double)i * yi);
		pix->oldz = a->oldz + round((double)i * zi);
		free(clr);
	}
	free(pix);
}

static void		draw_map_column(t_mlx *mlx, t_map *map, int j)
{
		int	i;

		i = 0;
		while (map->map[i + 1])
		{
			draw_line(mlx, map->map[i][j], map->map[i + 1][j], map);
			i++;
		}
}

static void		draw_map_line(t_mlx *mlx, t_map *map, int i)
{
		int	j;

		j = 0;
		while (map->map[i][j + 1])
		{
			draw_line(mlx, map->map[i][j], map->map[i][j + 1], map);
			j++;
		}
}

void			draw_map(t_mlx *mlx, t_map *map)
{
	int i;

	i = 0;
	while (map->map[i])
	{
		draw_map_line(mlx, map, i);
		i++;
	}
	i = 0;
	while (map->map[0][i])
	{
		draw_map_column(mlx, map, i);
		i++;
	}
}
