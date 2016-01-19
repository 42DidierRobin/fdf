/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/19 18:07:19 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

//TEMP
void		print_grid(t_grid **grid)
{
	int			i;
	int			j;

	i = 0;
	ft_putendl("Tableau enregistre :");
	while (i < (*grid)->height)
	{
		j = 0;
		while (j < (*grid)->length)
		{
			ft_putnbr((*grid)->tab[i][j]);
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
	ft_putnbr(grid->height);
	print_grid(&grid);
	return (0);
}
