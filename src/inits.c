/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:27:33 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/21 21:27:35 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_p2		init_p2(double x, double y)
{
	t_p2 ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_p3		init_p3(double x, double y, double z)
{
	t_p3 ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_ray		init_ray(t_p3 pos, t_p3 dir)
{
	t_ray ret;

	ret.dir = dir;
	ret.pos = pos;
	return (ret);
}

t_camera	init_camera(t_p3 pos, t_p3 x, t_p3 y, t_p3 z)
{
	t_camera camera;

	camera.pos = pos;
	camera.x_dir = x;
	camera.y_dir = y;
	camera.z_dir = z;
	return (camera);
}

t_sphere	init_sphere(t_p3 pos, double r)
{
	t_sphere ret;

	ret.pos = pos;
	ret.r = r;
	return (ret);
}

t_rgb		init_rgb(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	t_rgb ret;

	ret.r = r;
	ret.g = g;
	ret.b = b;
	ret.a = a;
	return (ret);
}