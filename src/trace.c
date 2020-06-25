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
	tmp = lin_comb(camera.x_dir, x*V_W/W_W, camera.y_dir, y*V_H/W_H);
	ray.dir = lin_comb(tmp, 1, camera.z_dir, C_Z);
	/*ray.dir = lin_comb(ray.dir, 1/sqrt(ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y + ray.dir.z * ray.dir.z),\
	init_p3(0, 0, 0), 0);*/
	return (ray);
}

t_p2	ray_trace(t_ray ray, t_sphere sphere)
{
	t_p2 roots;
	t_p3 k;
	t_p3 co;
	double d;

	co = lin_comb(ray.pos, 1, sphere.pos, -1);
	//co = init_p3(ray.pos.x - sphere.pos.x, ray.pos.y - sphere.pos.y, ray.pos.z - sphere.pos.z);
	k.x = sc_mult(ray.dir, ray.dir);
	//k.x = ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y + ray.dir.z * ray.dir.z;
	k.y = 2*sc_mult(ray.dir, co);
	//k.y = 2*(ray.dir.x*co.x + ray.dir.y*co.y + ray.dir.z*co.z);
	k.z = sc_mult(co, co) - sphere.r * sphere.r;
	//k.z = co.x*co.x + co.y*co.y + co.z*co.z - sphere.r*sphere.r;

	d = k.y * k.y - 4 * k.x * k.z;
	if (d >= 0)
	{
		//printf("%f %f %f %f\n",ray.dir.x, ray.dir.y, ray.dir.x ,d);
		roots.x = (-k.y - sqrt(d))/(2*k.x);
		roots.y = (-k.y + sqrt(d))/(2*k.x);
	}
	else
		roots = init_p2(-1, -1);
	return roots;
}
