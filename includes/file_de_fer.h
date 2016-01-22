/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_de_fer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:17:07 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/21 16:48:46 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILE_DE_FER_H
# define __FILE_DE_FER_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <math.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "mlx.h"

#define TAB_SIZE_MAX 1000
#define SEPARATOR ' '
#define WINDOW_L 600
#define WINDOW_W 1200
#define MAP_MARGIN_L 150
#define MAP_MARGIN_H 150
#define PIX_MARGIN 25

typedef struct		s_pix
{
	int		x;
	int		y;
	int		z;
	int		rgb;
}					t_pix;

typedef struct		s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
}					t_mlx;

typedef struct		s_map
{
	struct s_pix	**map;
	int				nbr_pix_l;
	int				nbr_pix_h;
	int				border_l;
	int				border_h;
}					t_map;

typedef struct		s_grid
{
	int		**tab;
	int		length;
	int		height;
}					t_grid;

void			draw_line(t_mlx *mlx, t_pix *a, t_pix *b);

void			draw_map(t_mlx *mlx, t_map *map);

t_mlx			*init_window(void);

t_pix			*new_pix(int x, int y, int z, int clr);
void			put_pix(t_mlx *mlx, t_pix *pix);

t_map			*grid_to_map(t_grid *grid);
t_grid			*read_it(char *file_name);
	char	*yo;

#endif
