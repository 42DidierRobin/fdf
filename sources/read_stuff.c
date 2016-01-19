/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:42:55 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/19 16:46:30 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer"

static void			char_to_int(t_grid **grid)
{

}

t_grid				*read_it(char *file_name)
{
	t_grid		*ret;
	int			fd;
	int			gnl_ret;
	char		**tab;

	i = 0;
	ret = (t_grid*)malloc(sizeof(t_grid));
	char = (char**)malloc(sizeof(char*) * SIZE_MAX);
	fd = open(file_name, O_RDONLY);
	while ((gnl_ret = get_next_line(fd, &(tab[i]))))
		i++;
	ret->height = i;
	char_to_int_tab(&ret);
	return (ret);
}
