/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:53:21 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/14 10:18:01 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

void                del_pix(t_pix **pix)
{
    //Delete de la struct couleur a faire
    free(*pix);
}

t_color             *new_color(int z, t_map *map)
{
    t_color *clr;

	z++;
	if (map)
   		ft_putstr("youpi");	
	clr = (t_color*)malloc(sizeof(t_color));
	
	return (clr);
}

t_pix				*new_pix(int x, int y, int clr)
{
	t_pix		*ret;

	ret = (t_pix*)malloc(sizeof(t_pix));
	ret->x = x;
	ret->y = y;
	/* ANTI WARNING */clr++;
	//ret->rgb = clr;
	return (ret);
}

void				put_pix(t_mlx *mlx, t_pix *pix)
{
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, WINDOW_W / 2 + pix->y,
			WINDOW_L / 2 + pix->x, 0xFF0000);
}
