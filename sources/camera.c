/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:30:10 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/02 18:01:49 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"


t_cam				*new_cam(double theta, double phi,  double r)
{
	t_cam		*ret;

	ret = (t_cam*)malloc(sizeof(t_cam));
	ret->eye_theta = theta;
	ret->eye_phi = phi;
	ret->eye_r = r;
	ret->eye_coord = new_3Dpoint(r * cos(theta) * cos(phi),
			r * sin(theta) * cos (phi), r * sin(phi)); 
	return (ret);
}

void				vision_zoom(t_cam *c, int zoom)
{
	c->eye_r = c->eye_r + zoom;

	c->eye_coord->x = c->eye_r * cos(c->eye_theta) * cos(c->eye_phi);
	c->eye_coord->y = c->eye_r * sin(c->eye_theta) * cos (c->eye_phi);
	c->eye_coord->z = c->eye_r * sin(c->eye_phi); 
}

void				vision_rot1(t_cam *c, double angle)
{
	c->eye_theta = c->eye_theta + angle;

	c->eye_coord->x = c->eye_r * cos(c->eye_theta) * cos(c->eye_phi);
	c->eye_coord->y = c->eye_r * sin(c->eye_theta) * cos (c->eye_phi);
	c->eye_coord->z = c->eye_r * sin(c->eye_phi); 
}

void				vision_rot2(t_cam *c, double angle)
{
	c->eye_phi = c->eye_phi + angle;

	c->eye_coord->x = c->eye_r * cos(c->eye_theta) * cos(c->eye_phi);
	c->eye_coord->y = c->eye_r * sin(c->eye_theta) * cos (c->eye_phi);
	c->eye_coord->z = c->eye_r * sin(c->eye_phi); 
}
