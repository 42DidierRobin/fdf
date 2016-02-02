/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/02 12:48:27 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

//TEMP

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

	ft_putendl("*--- Test des fonctions de math");
	t_3Dpoint	*p1;
	int			m_identite[3][3];
	int			m_translation[3][3];

	m_identite[0][0] = 1;
	m_identite[0][1] = 0;
	m_identite[0][2] = 0;
	m_identite[1][0] = 0;
	m_identite[1][1] = 1;
	m_identite[1][2] = 0;
	m_identite[2][0] = 0;
	m_identite[2][1] = 0;
	m_identite[2][2] = 1;
	
	m_translation[0][0] = 1;
	m_translation[0][1] = 1;
	m_translation[0][2] = 1;
	m_translation[1][0] = 1;
	m_translation[1][1] = 1;
	m_translation[1][2] = 1;
	m_translation[2][0] = 1;
	m_translation[2][1] = 1;
	m_translation[2][2] = 1;
	p1 = new_3Dpoint(1,2,3);

	print_point(p1);
	ft_putstr("Matrice identite : ");
	point_to_matrix(p1, m_identite);
	print_point(p1);
	ft_putstr("Matrice test : ");
	point_to_matrix(p1, m_translation);
	print_point(p1);

/*
	ft_putendl("*--- Creation de la fenetre");
	t_mlx	*mlx;
	mlx = init_window();
	
	ft_putendl("*--- Impression d'une ligne");
	t_pix *a = (t_pix*)malloc(sizeof(t_pix));
	t_pix *b = (t_pix*)malloc(sizeof(t_pix));

	a->x = -50;
	a->y = -50;
	b->x = 0;
	b->y = 350;
	draw_line(mlx, a, b);

	ft_putendl("*--- Transformation tableau int to matrix ");


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
*/
	ft_putendl("*--- Affichage map ");
/*	
	ft_putendl("!!! MISE EN BOUCLE INFINIE !!!");
	mlx_loop(mlx->mlx_ptr);
*/
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
