/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:11:53 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/03 13:21:03 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

t_3Dpoint			*new_3Dpoint(double x, double y, double z)
{
	t_3Dpoint		*ret;

	ret = (t_3Dpoint*)malloc(sizeof(t_3Dpoint));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}
