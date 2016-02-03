/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/03 13:28:23 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

//TEMP

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
	while (readed[i] != NULL)
	{
		j = 0;
		while (readed[i][j] != NULL)
		{
			ft_putnbr(*(readed[i][j]));
			if (readed[i][j + 1] != NULL && *(readed[i][j+1]) != 0)
				ft_putstr(".");
			else if (readed[i][j + 1] != NULL && *(readed[i][j+1]) == 0)
				ft_putstr("..");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putstr("	fin du tableau\n");
	ft_putchar('\n');

/*
	ft_putendl("*--- Test des fonctions de math");
	t_3Dpoint	*p1;
	t_3Dpoint	*p2;

	p1 = new_3Dpoint(- 0.33, 0.66, 0.66);
	double	 **m1;
	m1 = give_rotation_matrix(p1, 1.29);
	ft_putendl("Matrice Rotation avec ∂ = 1.29 (74) et");
	ft_putstr("Vecteur unitaire de reference = ");
	print_point(p1);
	print_matrix(4, m1);
	
	ft_putchar('\n');
	p2 = new_3Dpoint(1, 0, 0);
	double	 **m2;
	m2 = give_rotation_matrix(p2, -0.52);
	ft_putendl("Matrice Rotation avec ∂ = -0.52 (-30) et");
	ft_putstr("Vecteur unitaire de reference = ");
	print_point(p2);
	print_matrix(4, m2);

	ft_putchar('\n');
	double **m3;
	m3 = give_homothety_matrix(42);
	print_matrix(4, m3);
*/

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

	cam = new_cam(1.57, 1.57, 90);
	map = new_map(readed, cam);


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
			ft_putendl(")");
			j++;
		}
		i++;
	}

	ft_putendl("*--- Affichage map ");
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
