/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:15:02 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/17 11:31:56 by rdidier          ###   ########.fr       */
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
	{
		ret = launch_it(argv[1],
				ft_strsplit("255,255,255", ','),
				ft_strsplit("0,0,0", ','));
	}
	else if (argc == 4 && check_color(argv[2]) && check_color(argv[3]))
		ret = launch_it(argv[1],
				ft_strsplit("255,255,255", ','),
				ft_strsplit("0,0,0", ','));
	else
		ft_putendl("Error args. Example : ../map.fdf 0,0,0 255,255,255");
	if (!ret)
		ft_putstr("file error.");
	return (0);
}
