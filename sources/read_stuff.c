/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:42:55 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/19 17:54:15 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer"

static int			char_to_int_tab_help(t_grid **obj, char *line, int i)
{
	int		j;
	char	**split_rec

	j = -1;
	(*obj)->tab[i] = (int*)malloc(sizeof(int) * (*obj)->length);
	split_rec = ft_str_split(line, SEPARATOR);
	while (split_rec[++j])
	{
		if (j > length)
			return (0)
		(*obj)->tab[i][j] = ft_atoi((const char*)split_rec[j]);
		ft_strdel(split_rec[j]);
		split_rec[j] = NULL;
	}
	free(split_rec);
	if (j < length)
		return (0);
	return (1);
}

static int			char_to_int_tab(t_grid **obj, char **readed)
{
	int			i;
	int			j;
	char		**split_ret;

	i = -1;
	err = 1;
	split_ret = ft_str_split((char const*)readed[0], SEPARATOR);
	while (split_rec[++i])
		ft_strdel(split_rec[i]);
	(*obj)->length = i;
	i = -1;
	while (read[++i])
	{
		if(!(char_to_int_tab_help(obj, read[i], i)))
			return (0);
	}
	free(split_rec);
	return (1);
}

t_grid				*read_it(char *file_name)
{
	t_grid		*ret;
	int			fd;
	int			gnl_ret;
	int			err;
	char		**tab;

	i = -1;
	ret = (t_grid*)malloc(sizeof(t_grid));
	tab = (char**)malloc(sizeof(char*) * SIZE_MAX);
	fd = open(file_name, O_RDONLY);
	while ((gnl_ret = get_next_line(fd, &(tab[++i]))));
	tab[i] = NULL;
	ret->height = i;
	ret->tab = (int**)malloc(sizeof(int*) * i + 1);
	ret->tab[i + 1] = NULL;
	err = char_to_int_tab(&ret, tab);
	i = -1;
	while (tab[++i])
		ft_strdel(tab[i]);
	free(tab);
	close(fd);
	if (!err)
		return (NULL);
	return (ret);
}
