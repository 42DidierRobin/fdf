/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:20:18 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/20 13:48:46 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

void		draw_line(t_mlx *mlx, t_pix *a, t_pix *b)
{
	float		m;
	float		p;
	int			i;
	int			color;
	t_pix		*current;

	m = 0;
	i = 0;
	color = 0;
	current = (t_pix*)malloc(sizeof(t_pix));
	current->x = a->x;
	current->y = a->y;
	if (a->x != b->x)
		m = (b->y - a->y) / (b->x - a->x);
	p = a->y - (m * a->x);
	if (a->rgb != b->rgb)
		color = (b->rgb - a->rgb) / SHARPNESS;
	while (current->x < b->x)
	{
		current->x += i;
		current->y = m * (current->x) + p;
		current->rgb += color;
		mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, current->x,
				current->y, current->rgb);
		i += SHARPNESS;
	}
	ft_putstr("fini");
	free(current);
}
/*
void		draw_all_line(t_mlx *mlx, t_map *map)
{
	
}
*/
