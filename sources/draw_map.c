/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:20:18 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/22 12:27:55 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

void			draw_line(t_mlx *mlx, t_pix *a, t_pix *b)
{
	double		xi;
	double		yi;
	int			i;
	int			step;
	t_pix		*pix;

	i = -1;
	pix = new_pix(a->x, a->y, a->z, a->rgb);
	if (abs(a->x - b->x) <= abs(a->y - b->y))
		step = 1 + abs(a->y - b->y);
	else 
		step = 1 + abs(a->x - b->x);
	xi = (double)(b->x - a->x) / step;
	yi = (double)(b->y - a->y) / step;
	while (++i < step)
	{
		put_pix(mlx, pix);
		pix->x = a->x + round((double)i * xi);
		pix->y = a->y + round((double)i * yi);
		//rajouter la couleur
	}
	free(pix);
}

