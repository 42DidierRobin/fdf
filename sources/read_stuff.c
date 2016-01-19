/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:42:55 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/19 18:53:55 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

static int			char_to_int_tab_help(t_grid **obj, char *line, int i)
{
	int		j;
	char	**split_ret;

	ft_putendl("On rentre dans help");
	j = -1;
	(*obj)->tab[i] = (int*)malloc(sizeof(int) * (*obj)->length);
	split_ret = ft_strsplit((const char*)line, SEPARATOR);
	while (split_ret[++j])
	{
		if (j > (*obj)->length)
			return (0);
		(*obj)->tab[i][j] = ft_atoi((const char*)split_ret[j]);
	}
	if (j != (*obj)->length)
		return (0);
	j = -1;
	/* A DEBUGUER
	while (split_ret[++j])
		ft_strdel(&(split_ret[j]));
	*/
	ft_putendl("on sort de help");
	return (1);
}

static int			char_to_int_tab(t_grid **obj, char **readed)
{
	int			i;
	char		**split_ret;

	i = -1;
	split_ret = ft_strsplit((char const*)readed[0], SEPARATOR);
	while (split_ret[++i])
		ft_strdel(&(split_ret[i]));
	(*obj)->length = i;
	i = -1;
	while (readed[++i])
	{
		ft_putstr("Readed[i] = ");
		ft_putendl(readed[i]);
		if(!(char_to_int_tab_help(obj, readed[i], i)))
			return (0);
	}
	free(split_ret);
	return (1);
}

t_grid				*read_it(char *file_name)
{
	t_grid		*ret;
	int			fd;
	int			gnl_ret;
	int			err;
	int			i;
	char		**tab;

	i = -1;
	ret = (t_grid*)malloc(sizeof(t_grid));
	tab = (char**)malloc(sizeof(char*) * TAB_SIZE_MAX);
	fd = open(file_name, O_RDONLY);
	while ((gnl_ret = get_next_line(fd, &(tab[++i]))));
	tab[i] = NULL;
	ret->height = i;
	ret->tab = (int**)malloc(sizeof(int*) * i + 1);
	ret->tab[i + 1] = NULL;
	ft_putendl("fin de la lecture");
	err = char_to_int_tab(&ret, tab);
	i = -1;
	while (tab[++i])
		ft_strdel(&(tab[i]));
	free(tab);
	close(fd);
	if (!err)
		return (NULL);
	return (ret);
}
