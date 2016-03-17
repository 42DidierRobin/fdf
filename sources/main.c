/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/15 21:14:35 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fil_de_fer.h"

int		main(int argc, char **argv)
{
	int	ret;

	if (argc < 2 || argc > 4)
	{
		ft_putendl("Error : nbr of argument(s)");
		return (0);
	}
	else
	{
		if (argc == 2)
			ret = launch_it(argv[1],
					ft_strsplit("255,255,255", ','),
					ft_strsplit("0,0,0", ','));
		else
			ret = launch_it(argv[1],
					ft_strsplit(argv[2], ','),
					ft_strsplit(argv[3], ','));
	}
	if (!ret)
		ft_putstr("file error.");
	return (0);
}
