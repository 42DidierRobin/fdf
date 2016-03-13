/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/10 18:31:04 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

//TEMP

void		print_pix(t_pix *pix)
{
	ft_putstr("Pixel coord :\n");
	ft_putstr("x : ");
	ft_putnbr(pix->x);
	ft_putchar('\n');
	ft_putstr("y : ");
	ft_putnbr(pix->y);
	ft_putchar('\n');
	ft_putchar('\n');
}

void		print_matrix(int size, double **m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			printf("%f -- ",m[i][j]);
		}
		printf("\n");
	}
	ft_putstr("\n\n");
}

void		print_point(t_3Dpoint *point)
{
	ft_putstr("Coordonne du point : (");
	ft_putnbr(point->x);
	ft_putstr(";");
	ft_putnbr(point->y);
	ft_putstr(";");
	ft_putnbr(point->z);
	ft_putendl(")");
}

void		print_tests(int ****r)
{
	int			i;
	int			j;
	int			***readed;

	readed = *r;
	ft_putendl("*-----* Demarrage des tests *-----*");
	ft_putendl("*--- Lecture du tableau de int ");
	i = 0;
	while (readed[i])
	{
		j = 0;
		while (readed[i][j])
		{
            ft_putnbr(*(readed[i][j]));
			if (readed[i][j + 1] && *(readed[i][j+1]) >= 9)
				ft_putstr(".");
			else if (readed[i][j + 1])
				ft_putstr("..");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putstr("	fin du tableau\n");
	ft_putchar('\n');

	ft_putendl("*--- Creation de la fenetre");
	t_mlx	*mlx;
	mlx = init_window();
/*	
	ft_putendl("*--- Impression d'une ligne");
	t_pix *a = (t_pix*)malloc(sizeof(t_pix));
	t_pix *b = (t_pix*)malloc(sizeof(t_pix));

	a->x = -50;
	a->y = -50;
	b->x = 0;
	b->y = 350;
	draw_line(mlx, a, b);
*/
	ft_putendl("*--- Transformation tableau int to matrix ");
	
	t_cam *cam;
	t_map *map;

	cam = new_cam(new_3Dpoint(0,0,500), new_3Dpoint(0.8,0.8,0.3), 100);
	map = new_map(readed, cam);

    ft_putchar('\n');
	ft_putendl("*--- Impression map ");
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			ft_putstr("(");
			ft_putnbr(map->map[i][j]->x);
			ft_putstr(";");
			ft_putnbr(map->map[i][j]->y);
            if (map->map[i][j+1])
			    ft_putstr(") - ");
		    else
                ft_putendl(") ||||");
		
            j++;
		}
		i++;
	}

	ft_putendl("*--- Affichage map ");
	draw_map(mlx, map);


	ft_putendl("*--- test de MAJ de map ");
    cam->fov = 1000;
    update_map(map, cam);
	draw_map(mlx, map);

	ft_putendl("!!! MISE EN BOUCLE INFINIE !!!");
	mlx_loop(mlx->mlx_ptr);

}
//TEMP

int		main(int argc, char **argv)
{
	int		***readed;

	if (argc != 2)
		ft_putendl("Error : nbr of argument(s)");
	else
	{
		readed = read_it(argv[1]);
		ft_putchar('\n');
		if (readed)
			print_tests(&readed);
		else
			ft_putendl("Error : incorrect file. You may want to check the max size of tab in define");
	}
	return (0);
}
