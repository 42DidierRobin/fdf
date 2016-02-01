/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_de_fer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:17:07 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/01 19:32:34 by rdidier          ###   ########.fr       */
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

//INTERDIT
#include <stdio.h>

#define TAB_SIZE_MAX 1000
#define SEPARATOR ' '
#define WINDOW_L 600
#define WINDOW_W 1200
#define MARGE_L 150
#define MARGE_W 150
#define	PAS		5

typedef struct		s_3Dpoint
{
	int		x;
	int		y;
	int		z;
}					t_3Dpoint;

typedef struct		s_cam
{
	struct s_3Dpoint	*from;
	struct s_3Dpoint	*to;
	double				fov;
	int					plan[4];

}					t_cam;

typedef struct		s_pix
{
	int		x;
	int		y;
//	int		z;
//	t_color	color;
}					t_pix;

typedef struct		s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
}					t_mlx;

typedef struct		s_map
{
	t_pix			*center;
	struct s_pix	***map;
}					t_map;

// Camera.c
t_3Dpoint		*new_3Dpoint(int x, int y, int z);
t_cam			*new_cam(t_3Dpoint *ori, t_3Dpoint *fuite, double fov);

// Map.c
t_map			*new_map(int ***readed, t_cam *cam);

// Read.c
int				***read_it(char *file_name);

// Window.c
t_mlx			*init_window(void);

// math.c
double			give_angle(t_3Dpoint *u, t_3Dpoint *v);
double			give_angle_test(t_3Dpoint *u, t_3Dpoint *v);
t_3Dpoint		*vector_on_screen(t_3Dpoint *u, t_cam *cam);

// Draw.c
void			draw_map(t_mlx *mlx, t_map *map);
void			draw_line(t_mlx *mlx, t_pix *a, t_pix *b);

// Pixels.c
t_pix			*new_pix(int x, int y, int clr);
void			put_pix(t_mlx *mlx, t_pix *pix);

#endif
