/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/19 18:53:58 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

//TEMP
void		print_grid(t_grid **grid)
{
	int			i;
	int			j;

	ft_putstr("height = ");
	ft_putnbr((*grid)->height);
	ft_putchar('\n');
	ft_putstr("length = ");
	ft_putnbr((*grid)->length);
	ft_putchar('\n');
	i = 0;
	ft_putendl("Tableau enregistre :");
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
	ft_putstr("fin du tableau\n");
	ft_putchar('\n');
}
//TEMP

int		main(int argc, char **argv)
{
	t_grid		*grid;

	argc = argc + 1 - 1;
	grid = read_it(argv[1]);
	ft_putendl("Fin de read_stuff");
	ft_putchar('\n');
	if (grid)
		print_grid(&grid);
	else
		ft_putendl("error");
	return (0);
}
