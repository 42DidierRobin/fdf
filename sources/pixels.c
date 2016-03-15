/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:53:21 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/15 22:06:28 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fil_de_fer.h"

t_color				*give_color(int z, t_map *map)
{
	double		coef;
	double		rgb[3];

	if (z == 0)
		return (new_color(map->clr_from->r,
					map->clr_from->g, map->clr_from->b));
	else if (z < 0)
		z = -z;
	else if (z == map->zmax)
		return (new_color(map->clr_to->r, map->clr_to->g, map->clr_to->b));
	coef = (double)z / (double)(map->zmax);
	if (map->clr_to->r - map->clr_from->r)
		rgb[0] = (double)(map->clr_to->r - map->clr_from->r) * coef;
	else
		rgb[0] = map->clr_to->r;
	if (map->clr_to->g - map->clr_from->g)
		rgb[1] = (double)(map->clr_to->g - map->clr_from->g) * coef;
	else
		rgb[1] = map->clr_to->g;
	if (map->clr_to->b - map->clr_from->b)
		rgb[2] = (double)(map->clr_to->b - map->clr_from->b) * coef;
	else
		rgb[2] = map->clr_to->b;
	return (new_color((char)rgb[0], (char)rgb[1], (char)rgb[2]));
}

t_color				*new_color(char r, char g, char b)
{
	t_color		*clr;

	clr = (t_color*)malloc(sizeof(t_color));
	clr->r = r;
	clr->g = g;
	clr->b = b;
	return (clr);
}

t_pix				*new_pix(int x, int y, int oldz)
{
	t_pix		*ret;

	ret = (t_pix*)malloc(sizeof(t_pix));
	ret->x = x;
	ret->y = y;
	ret->oldz = oldz;
	return (ret);
}

void				put_pix(t_mlx *mlx, t_pix *pix, t_color *clr)
{
	unsigned int	color;

	color = clr->r * 65536 + clr->g * 256 + clr->b;
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, WINDOW_W / 2 + pix->y,
			WINDOW_L / 2 + pix->x, color);
}
