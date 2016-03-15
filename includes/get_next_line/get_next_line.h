/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:24:40 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/15 22:14:01 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>

# define BUFF_SIZE 1000

typedef struct		s_data
{
	int				fd;
	char			*buff;
	struct s_data	*next;
}					t_data;

int					get_next_line(int const fd, char **line);
#endif
