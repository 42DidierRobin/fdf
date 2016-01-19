/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_de_fer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:17:07 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/19 15:51:04 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILE_DE_FER_H
# define __FILE_DE_FER_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <math.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

#define SIZE_MAX 1000

typedef struct		s_grid
{
	int		tab[][];
	int		length;
	int		height;
}					t_grid;



#endif
