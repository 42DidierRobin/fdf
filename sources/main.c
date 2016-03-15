/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/15 22:45:07 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fil_de_fer.h"

int		check_color(char *arg)
{
	char **temp;

	if (ft_strlen(arg) < 5 || ft_strlen(arg) > 11)
		return (0);
	temp = ft_strsplit(arg, ',');
	if (!temp || !temp[0] || !temp[1] || !temp[2])
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int	ret;

	ret = 1;
	if (argc == 2)
		ret = launch_it(argv[1],
				ft_strsplit("255,255,255", ','),
				ft_strsplit("0,0,0", ','));
	else if (argc == 4)
	{
		if (check_color(argv[2]) && check_color(argv[3]))
			ret = launch_it(argv[1],
					ft_strsplit(argv[2], ','),
					ft_strsplit(argv[3], ','));
		else
			ft_putendl("Error color. Example : ../map.fdf 0,0,0 255,255,255");
	}
	else
		ft_putstr("Error : nb of arguments");
	if (!ret)
		ft_putstr("file error.");
	return (0);
}
