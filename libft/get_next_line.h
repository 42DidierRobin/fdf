/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:24:40 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/17 10:59:33 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>

# define BUFF_SIZE 32

typedef struct		s_gnld
{
	int				fd;
	char			*buff;
	struct s_data	*next;
}					t_gnld;

int					get_next_line(int const fd, char **line);

#endif
