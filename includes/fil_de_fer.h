/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_de_fer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:17:07 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/15 22:12:25 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIL_DE_FER_H
# define __FIL_DE_FER_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"

# define TAB_SIZE_MAX	100000
# define SEPARATOR 		' '
# define WINDOW_L 		800
# define WINDOW_W	 	1700
# define PAS			5
# define CAM_STEP		10

typedef struct		s_3dpoint
{
	double			x;
	double			y;
	double			z;
}					t_3dpoint;

typedef struct		s_cam
{
	double			amp;
	double			fov;
	t_3dpoint		*pos;
	t_3dpoint		*rot;
	char			line;
}					t_cam;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_pix
{
	int				x;
	int				y;
	int				oldz;
}					t_pix;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
}					t_mlx;

typedef struct		s_map
{
	t_color			*clr_from;
	t_color			*clr_to;
	int				zmax;
	int				***readed;
	struct s_pix	***map;
}					t_map;

typedef struct		s_fdf_data
{
	t_map			*map;
	t_cam			*cam;
	t_mlx			*mlx;
}					t_fdf_data;

t_cam				*new_cam(t_3dpoint *pos, t_3dpoint *rot, double fov);
void				move_cam(t_cam *cam, int key, t_mlx *mlx);
double				**give_null_matrix(int size);
double				**give_homothety_matrix(int factor);
double				**give_translation_matrix(t_3dpoint *vector);
double				**add_matrix(double **m, double **n, int size);
double				**mult_matrix(double **m, double **n, int size);
double				**give_rotation_matrix_z(double a);
double				**give_rotation_matrix_y(double a);
double				**give_rotation_matrix_x(double a);
void				matrix_on_point(t_3dpoint *point, double **m);
t_3dpoint			*new_3dpoint(double x, double y, double z);
t_map				*update_map(t_map *map, t_cam *cam);
t_map				*new_map(int ***readed, t_cam *cam);
int					***read_it(char *file_name);
t_mlx				*init_window(void);
int					window_event(int keycode, void *d);
int					launch_it(char *file, char **from, char **to);
void				draw_map(t_mlx *mlx, t_map *map);
void				draw_map_point(t_mlx *mlx, t_map *map);
void				draw_line(t_mlx *mlx, t_pix *a, t_pix *b, t_map *map);
t_pix				*new_pix(int x, int y, int oldz);
t_color				*new_color(char r, char g, char b);
t_color				*give_color(int z, t_map *map);
void				put_pix(t_mlx *mlx, t_pix *pix, t_color *clr);
#endif
