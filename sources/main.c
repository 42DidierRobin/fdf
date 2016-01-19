/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/19 16:46:13 by rdidier          ###   ########.fr       */
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
		}
		ft_putchar('\n');
	}
	ft_putstr("fin du tableau\n");
	ft_putchar('\n');
}
//TEMP

int		main(int argc, char **argv)
{
	t_grid		*grid;

	argc = argc;
	grid = reat_it(argv[1]);
	print_grid(&grid);
	return (0);
}
