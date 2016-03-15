/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:40:09 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/15 22:07:25 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fil_de_fer.h"

t_mlx		*init_window(void)
{
	t_mlx		*it;

	it = (t_mlx*)malloc(sizeof(t_mlx));
	it->mlx_ptr = mlx_init();
	it->mlx_win = mlx_new_window(it->mlx_ptr, WINDOW_W, WINDOW_L,
			"Fil de fer by Mathiisss");
	return (it);
}

void		print_cam(t_fdf_data *data)
{
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 0, 0, 16777215,
			" Position de la camera en x:");
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 289, 0, 16777215,
			ft_itoa(data->cam->pos->x));
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 0, 20, 16777215,
			"                      --  y:");
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 289, 20, 16777215,
			ft_itoa(data->cam->pos->y));
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 0, 40, 16777215,
			"                      --  z:");
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 289, 40, 16777215,
			ft_itoa(data->cam->pos->z));
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 0, 60, 16777215,
			"    Angle de la camera en x:");
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 289, 60, 16777215,
			ft_itoa((int)(57.3 * data->cam->rot->x)));
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 0, 80, 16777215,
			"                      --  y:");
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 289, 80, 16777215,
			ft_itoa((int)(57.3 * data->cam->rot->y)));
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 0, 100, 16777215,
			"                      --  z:");
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 289, 100, 16777215,
			ft_itoa((int)(57.3 * data->cam->rot->z)));
}

int			launch_it(char *file, char **from, char **to)
{
	t_color		*clr_from;
	t_color		*clr_to;
	t_fdf_data	*data;
	int			***read_ret;

	read_ret = read_it(file);
	if (!read_ret || !read_ret[0] || !read_ret[0][0])
		return (0);
	data = (t_fdf_data*)malloc(sizeof(t_fdf_data));
	data->mlx = init_window();
	data->map = (t_map*)malloc(sizeof(t_map));
	clr_from = new_color((unsigned char)ft_atoi(from[0]),
			(unsigned char)ft_atoi(from[1]), (unsigned char)ft_atoi(from[2]));
	clr_to = new_color((unsigned char)ft_atoi(to[0]),
			(unsigned char)ft_atoi(to[1]), (unsigned char)ft_atoi(to[2]));
	data->cam = new_cam(new_3dpoint(0, 0, 1000), new_3dpoint(0, 0, 0), 2600);
	data->map = new_map(read_it(file), data->cam);
	data->map->clr_from = clr_from;
	data->map->clr_to = clr_to;
	draw_map(data->mlx, data->map);
	print_cam(data);
	if (mlx_key_hook(data->mlx->mlx_win, window_event, (void*)data))
		mlx_loop(data->mlx->mlx_ptr);
	return (1);
}

int			window_event(int keycode, void *d)
{
	t_fdf_data	*data;

	data = (t_fdf_data*)d;
	move_cam(data->cam, keycode, data->mlx);
	if (keycode == 53)
		return (0);
	data->map = update_map(data->map, data->cam);
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->mlx_win);
	if (!data->cam->line)
		draw_map_point(data->mlx, data->map);
	else
		draw_map(data->mlx, data->map);
	print_cam(data);
	return (1);
}
