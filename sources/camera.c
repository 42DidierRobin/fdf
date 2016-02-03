/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:30:10 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/03 09:57:33 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"


t_cam				*new_cam(double theta, double phi,  double r)
{
	t_cam		*ret;

	ret = (t_cam*)malloc(sizeof(t_cam));
	ret->theta = theta;
	ret->phi = phi;
	ret->r = r;
	ret->carth = new_3Dpoint(r * sin(theta) * cos(phi),
			r * sin(theta) * sin(phi), r * cos(phi)); 
	return (ret);
}

void				vision_zoom(t_cam *c, int zoom)
{
	c->r = c->r + zoom;

	c->carth->x = c->r * cos(c->theta) * cos(c->phi);
	c->carth->y = c->r * sin(c->theta) * cos (c->phi);
	c->carth->z = c->r * sin(c->phi); 
}

void				vision_rot1(t_cam *c, double angle)
{
	c->theta = c->theta + angle;

	c->carth->x = c->r * cos(c->theta) * cos(c->phi);
	c->carth->y = c->r * sin(c->theta) * cos (c->phi);
	c->carth->z = c->r * sin(c->phi); 
}

void				vision_rot2(t_cam *c, double angle)
{
	c->phi = c->phi + angle;

	c->carth->x = c->r * cos(c->theta) * cos(c->phi);
	c->carth->y = c->r * sin(c->theta) * cos (c->phi);
	c->carth->z = c->r * sin(c->phi); 
}
