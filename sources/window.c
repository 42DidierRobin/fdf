/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:40:09 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/31 15:19:55 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
