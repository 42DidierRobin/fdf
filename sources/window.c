/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:40:09 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/14 18:22:41 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TEMP
#include <stdio.h> 

#include "../includes/file_de_fer.h"

t_mlx		*init_window(void)
{
	t_mlx		*it;

	it = (t_mlx*)malloc(sizeof(t_mlx));
	it->mlx_ptr = mlx_init();
	it->mlx_win = mlx_new_window(it->mlx_ptr, WINDOW_W, WINDOW_L,
			"File de fer by Mathiisss");

	return (it);
}

int			window_event(int keycode, void *d)
{
	t_fdf_data	*data;

	data = (t_fdf_data*)d;
	move_cam(data->cam, keycode);
	data->map = update_map(data->map, data->cam);
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->mlx_win);
	ft_putendl("dessin :");
	draw_map(data->mlx, data->map);

	return (0);
}
