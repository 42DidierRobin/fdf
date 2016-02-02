/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:27:04 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/02 14:42:33 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

int			**give_null_matrix(int size)
{
	int[size][size]	ret;
	int				i;
	int				j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ret[i][j] = 0;
	}
	return (ret);
}

int[4][4]	give_translation_matrix(t_3Dpoint *vector)
{
	int[4][4]	ret;

	ret = give_null_matrix(4);
	ret[0][0] = 1;
	ret[1][1] = 1;
	ret[2][2] = 1;
	ret[3][3] = 1;
	ret[3][0] = vector->x;
	ret[3][1] = vector->y;
	ret[3][2] = vector->z;
	return (ret);
}
	
int[4][4]	give_homothety_matrix(int factor)
{
	int[4][4]	ret;

	ret = give_null_matrix(4);
	ret[0][0] = factor;
	ret[1][1] = factor;
	ret[2][2] = factor;
	ret[3][3] = 1;
	return (ret);
}

int			**mult_matrix(int **m, int **n, int size)
{
	int[size][size]	ret;
	int				i;
	int				j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while(++j < size)
			ret[i][j] = m[i][j] * n[i][j];
	}
	return (ret);
}

int			**add_matrix(int **m, int **n, int size)
{
	int[size][size]	ret;
	int				i;
	int				j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while(++j < size)
			ret[i][j] = m[i][j] + n[i][j];
	}
	return (ret);
}
