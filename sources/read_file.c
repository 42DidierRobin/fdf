/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:42:55 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/31 18:42:29 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

static void			readed_to_map(int ***tab, char **readed, int size)
{
	int			j;
    int         i;
	int			length;
	char		**split_ret;

    i = 0;
    size--;
	while (size - i + 1)
	{
		length = 0;
		split_ret = ft_strsplit((char const*)readed[i], SEPARATOR);
		while (split_ret[++length])
            ;
        
        //TEMP
        ft_putnbr(length);
        ft_putchar('\n');
		//TEMP

        tab[size - i] = (int**)malloc(sizeof(int*) * length + 1);	
		tab[size - i][length] = NULL;
		j = -1;
		while (++j < length)
		{
			(tab[size - i][length - j - 1]) = (int*)malloc(sizeof(int));
			*(tab[size - i][length - j - 1]) = ft_atoi(split_ret[j]);
			ft_strdel(&split_ret[j]);
		}
        i++;
	}
	free(split_ret);
}

//	Retourne le tableau de int lu delimite par des pointeurs nulls. (donnee temporaire)
int				***read_it(char *file_name)
{
	int			***ret;
	int			fd;
	int			gnl_ret;
	int			i;
	char		**tab;

	i = -1;
	tab = (char**)malloc(sizeof(char*) * TAB_SIZE_MAX);
	fd = open(file_name, O_RDONLY);
	while ((gnl_ret = get_next_line(fd, &(tab[++i]))))
	{
		if (i > TAB_SIZE_MAX)
			return (NULL);
	}
	tab[i] = NULL;
	ret = (int***)malloc(sizeof(int**) * i + 1);
	ret[i] = NULL;
	readed_to_map(ret, tab, i);
	i = -1;
	while (tab[++i])
		ft_strdel(&(tab[i]));
	free(tab);
	close(fd);
	return (ret);
}
