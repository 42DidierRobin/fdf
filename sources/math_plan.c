/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:11:53 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/02 17:47:12 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

void				point_homo_to_cart(t_3Dpoint *p)
{
	p->x = p->x / p->t;
	p->y = p->y / p->t;
	p->z = p->z / p->t;
	p->t = 1;
}

t_3Dpoint			*new_3Dpoint(double x, double y, double z)
{
	t_3Dpoint		*ret;

	ret = (t_3Dpoint*)malloc(sizeof(t_3Dpoint));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	ret->t = 1;
	return (ret);
}
