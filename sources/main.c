/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/01 19:37:17 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

//TEMP
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
	t_map		*map;
	t_3Dpoint	*from;
	t_3Dpoint	*to;
	t_cam		*cam;

	from = new_3Dpoint(10, 10, 100);
	to = new_3Dpoint(0, 0, -50);
	cam = new_cam(from, to, 0.6); 
	map = new_map(readed, cam);

	t_3Dpoint *test;

	test = vector_on_screen(new_3Dpoint(1,1,10), cam);
	ft_putendl("test de vector on screen");
	ft_putstr("Coordonnees : ( ");
	ft_putnbr(test->x);
	ft_putstr(" ; ");
	ft_putnbr(test->y);
	ft_putstr("; ");
	ft_putnbr(test->z);
	ft_putendl(" )");
/*
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
	draw_map(mlx, map);
	t_pix *gaetrym = new_pix(250,350, 0xFFFF00);
	put_pix(mlx, gaetrym);
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
