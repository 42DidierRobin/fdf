/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/21 16:15:16 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

//TEMP
void		print_tests(t_grid **grid)
{
	int			i;
	int			j;

	ft_putendl("*-----* Demarrage des tests *-----*");
	ft_putendl("*--- Lecture et transformation en Grille");
	ft_putstr("	grid height = ");
	ft_putnbr((*grid)->height);
	ft_putchar('\n');
	ft_putstr("	grid length = ");
	ft_putnbr((*grid)->length);
	ft_putchar('\n');
	i = 0;
	ft_putendl("	Tableau enregistre :");
	while (i < (*grid)->height)
	{
		j = 0;
		while (j < (*grid)->length)
		{
			ft_putnbr((*grid)->tab[i][j]);
			if (j + 1 < (*grid)->length)
				ft_putchar('-');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putstr("		fin du tableau\n");
	ft_putchar('\n');
	

	ft_putendl("*--- Creation de la fenetre");
	t_mlx	*mlx;
	mlx = init_window();

	ft_putendl("*--- Creation de la map");
	t_map	*map;
	map = grid_to_map((*grid));
	
	ft_putendl("*--- Impression d'une ligne");
	t_pix *a = (t_pix*)malloc(sizeof(t_pix));
	t_pix *b = (t_pix*)malloc(sizeof(t_pix));

	a->x = -50;
	a->y = -50;
	a->rgb = 0xFF0000;
	b->x = 0;
	b->y = 350;
	b->rgb = 0x00FF00;
	draw_line(mlx, a, b);

	ft_putendl("*--- Impression de la map");
	draw_map(mlx, map);
	ft_putendl("!!! MISE EN BOUCLE INFINIE !!!");
	mlx_loop(mlx->mlx_ptr);
}
//TEMP

int		main(int argc, char **argv)
{
	t_grid		*grid;

	if (argc != 2)
		ft_putendl("Error : nbr of argument(s)");
	else
	{
		grid = read_it(argv[1]);
		ft_putchar('\n');
		if (grid)
			print_tests(&grid);
		else
			ft_putendl("Error : incorrect file");
	}
	return (0);
}
