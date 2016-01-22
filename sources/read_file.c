/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:42:55 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/22 12:41:45 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

static void			readed_to_map(t_map **obj, char **readed)
{
	int			i;
	int			j;
	int			length;
	char		**split_ret;

	i = -1;
	while (readed[++i])
	{
		length = 0;
		split_ret = ft_strsplit((char const*)readed[i], SEPARATOR);
		while (split_ret[++length]);
		(*obj)->map[i] = (t_pix**)malloc(sizeof(t_pix*) * length);
		(*obj)->map[i][length] = NULL;
		j = -1;
		while (++j < length)
		{
			(*obj)->map[i][j] = new_pix(j, i, ft_atoi(split_ret[j]), 0);
			ft_strdel(&split_ret[j]);
		}
	}
	free(split_ret);
}

t_map				*read_it(char *file_name)
{
	t_map		*ret;
	int			fd;
	int			gnl_ret;
	int			i;
	char		**tab;

	i = -1;
	ret = (t_map*)malloc(sizeof(t_map));
	tab = (char**)malloc(sizeof(char*) * TAB_SIZE_MAX);
	fd = open(file_name, O_RDONLY);
	while ((gnl_ret = get_next_line(fd, &(tab[++i]))))
	{
		if (i > TAB_SIZE_MAX)
			return (NULL);
	}
	tab[i] = NULL;
	ret->map = (t_pix***)malloc(sizeof(t_pix**) * i);
	ret->map[i] = NULL;
	readed_to_map(&ret, tab);
	i = -1;
	while (tab[++i])
		ft_strdel(&(tab[i]));
	free(tab);
	close(fd);
	return (ret);
}
