/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:53:21 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/31 19:16:50 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

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
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, /*MARGE_L +*/  pix->x,
			/*MARGE_W +*/ pix->y, 0xFF0000);
}
