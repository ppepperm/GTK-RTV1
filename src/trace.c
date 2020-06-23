/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 20:09:59 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/22 20:10:04 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray	get_ray(t_camera camera, double x, double y)
{
	t_ray ray;
	t_p3 tmp;

	ray.pos = camera.pos;
	tmp = lin_comb(camera.x_dir, x/100, camera.y_dir, y/100);
	ray.dir = lin_comb(tmp, 1, camera.z_dir, C_Z);
	return (ray);
}

t_p2	ray_trace(t_ray ray, t_sphere sphere)
{
	t_p2 roots;
	t_p3 k;
	t_p3 co;
	double d;

	co = lin_comb(ray.pos, 1, sphere.pos, -1);
	//printf("%f %f %f\n", co.x, co.y, co.z);
	k.x = sc_mult(ray.dir, ray.dir);
	k.y = 2*sc_mult(ray.dir, co);
	k.z = sc_mult(co, co) - sphere.r * sphere.r;

	d = k.y * k.y - 4 * k.x * k.z;
	if (d >= 0)
	{
		roots.x = (-k.y - sqrt(d))/(2*k.x);
		roots.y = (-k.y + sqrt(d))/(2*k.x);
	}
	else
	{
		roots = init_p2(-1, -1);
	}
	//printf("%f %f %f %f\n", k.x, sc_mult(ray.dir, co), k.z, d);
	return roots;
}
