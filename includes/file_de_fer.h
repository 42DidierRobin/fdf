/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_de_fer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:17:07 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/03 13:24:56 by rdidier          ###   ########.fr       */
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
#define	PAS		20

// Coordonnees dite homogene. 
typedef struct		s_3Dpoint
{
	double		x;
	double		y;
	double		z;
}					t_3Dpoint;

typedef struct		s_cam
{
	double		theta;
	double		phi;
	double		r;
	t_3Dpoint	*carth;
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

//Camera
t_cam			*new_cam(double theta, double phi, double r);
void			vision_zoom(t_cam *c, int zoom);
void			vision_rot1(t_cam *c, double angle);
void			vision_rot2(t_cam *c, double angle);

//Matrix.c
double			**give_null_matrix(int size);
double			**give_homothety_matrix(int factor);
double			**give_translation_matrix(t_3Dpoint *vector);
double			**add_matrix(double **m, double **n, int size);
double			**mult_matrix(double **m, double **n, int size);

//Matrix_2.c
double			**give_rotation_matrix(t_3Dpoint *vector, double a);
void			matrix_on_point(t_3Dpoint *point, double **m);

//Math_plan.c
void			point_homo_to_cart(t_3Dpoint *point);
t_3Dpoint		*new_3Dpoint(double x, double y, double z);

// Map.c
t_map			*new_map(int ***readed, t_cam *cam);

// Read.c
int				***read_it(char *file_name);

// Window.c
t_mlx			*init_window(void);

// Draw.c
void			draw_map(t_mlx *mlx, t_map *map);
void			draw_line(t_mlx *mlx, t_pix *a, t_pix *b);

// Pixels.c
t_pix			*new_pix(int x, int y, int clr);
void			put_pix(t_mlx *mlx, t_pix *pix);

//temp
void		print_matrix(int size, double **m);
void		print_point(t_3Dpoint *point);
#endif
