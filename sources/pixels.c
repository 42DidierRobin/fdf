/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:53:21 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/10 17:47:44 by rdidier          ###   ########.fr       */
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
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, WINDOW_W / 2 + pix->y,
			WINDOW_L / 2 + pix->x, 0xFF0000);
}
