/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/22 12:40:37 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

//TEMP
void		print_tests(t_map **m)
{
	int			i;
	int			j;
	t_map		*map;

	map = *m;
	ft_putendl("*-----* Demarrage des tests *-----*");
	ft_putendl("*--- Lecture et transformation en MAP");
	i = 0;
	ft_putendl("	Tableau de pix enregistre :");
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != NULL)
		{
			ft_putnbr(map->map[i][j]->z);
			if (map->map[i][j + 1] != NULL && map->map[i][j+1]->z != 0)
				ft_putstr(".");
			else if (map->map[i][j + 1] != NULL && map->map[i][j+1]->z == 0)
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
	a->rgb = 0xFF0000;
	b->x = 0;
	b->y = 350;
	b->rgb = 0x00FF00;
	//draw_line(mlx, a, b);

	ft_putendl("*--- Impression de la map");
	//draw_map(mlx, map);
	ft_putendl("!!! MISE EN BOUCLE INFINIE !!!");
	//mlx_loop(mlx->mlx_ptr);
}
//TEMP

int		main(int argc, char **argv)
{
	t_map		*map;

	if (argc != 2)
		ft_putendl("Error : nbr of argument(s)");
	else
	{
		map = read_it(argv[1]);
		ft_putchar('\n');
		if (map)
			print_tests(&map);
		else
			ft_putendl("Error : incorrect file. You may want to check the max size of tab in define");
	}
	return (0);
}
