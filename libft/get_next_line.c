/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 20:20:33 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/17 10:59:21 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			update_data(t_gnld **dataf, t_gnld **data, int fd)
{
	if (*dataf == NULL)
	{
		*dataf = (t_gnld*)malloc(sizeof(t_gnld));
		(*dataf)->fd = fd;
		(*dataf)->buff = NULL;
		(*dataf)->next = (t_gnld*)malloc(sizeof(t_gnld));
		(*dataf)->next->fd = -1;
		*data = *dataf;
	}
	*data = *dataf;
	while ((*data)->fd >= 0 && (*data)->fd != fd)
		(*data) = (*data)->next;
	if ((*data)->fd < 0)
	{
		(*data)->fd = fd;
		(*data)->buff = NULL;
		(*data)->next = (t_gnld*)malloc(sizeof(t_gnld));
		(*data)->next->fd = -1;
	}
}

static char			*concatain(t_gnld *data, char *str)
{
	int		i;
	int		len;
	int		len2;
	char	*ret;

	i = -1;
	len = ft_strlen(data->buff);
	len2 = ft_strlen(str);
	ret = ft_strnew(len + len2);
	if (!(data->buff))
		return (ft_strdup(str));
	while (++i < len)
		ret[i] = data->buff[i];
	i = -1;
	while (++i < len2)
		ret[len + i] = str[i];
	ft_strdel(&data->buff);
	return (ret);
}

int					get_next_buff(t_gnld *data)
{
	char	*tmp;
	int		ret;

	tmp = ft_strnew(BUFF_SIZE);
	if ((ret = read(data->fd, tmp, BUFF_SIZE)) > 0)
		data->buff = concatain(data, tmp);
	ft_strdel(&tmp);
	if (ret > 0)
		return (1);
	return (ret);
}

void				update(t_gnld **data, int i, int ret)
{
	char	*tmp;
	t_gnld	*tmp2;

	tmp2 = NULL;
	if (ret != 0)
	{
		tmp = ft_strsub((*data)->buff, i + 1, ft_strlen((*data)->buff));
		ft_strdel(&(*data)->buff);
		(*data)->buff = tmp;
	}
	else
		ft_strdel(&(*data)->buff);
}

int					get_next_line(int const fd, char **line)
{
	int				ret;
	int				i;
	char			*line_ret;
	t_gnld			*data;
	static t_gnld	*dataf;

	ret = 1;
	line_ret = NULL;
	if (fd < 0 || !line)
		return (-1);
	update_data(&dataf, &data, fd);
	while (((i = ft_str_find_char(data->buff, '\n')) < 0)
			&& (ret > 0))
		ret = get_next_buff(data);
	if (ret < 0)
		return (-1);
	else if (ret == 0)
		line_ret = ft_strdup(data->buff);
	else
		line_ret = ft_strsub((const char*)data->buff, 0, i);
	*line = (line_ret);
	update(&data, i, ret);
	if (!ret && ft_strlen(line_ret) > 0)
		return (1);
	return (ret);
}
