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

t_ray			get_ray(t_camera camera, double x, double y)
{
	t_ray ray;
	t_p3 tmp;

	ray.pos = camera.pos;
	tmp = lin_comb(camera.x_dir, x/1000, camera.y_dir, y/1000);
	ray.dir = lin_comb(tmp, 1, camera.z_dir, C_Z);
	return (ray);
}

t_p2			intersect_sphere(t_ray ray, t_sphere sphere)
{
	t_p2 roots;
	t_p3 k;
	t_p3 co;
	double d;

	co = lin_comb(ray.pos, 1, sphere.pos, -1);
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
		roots = init_p2(-1, -1);
	return (roots);
}

t_p2			intersect_plane(t_ray ray, t_plane plane)
{
	t_p2 roots;
	double den;
	double num;

	den = sc_mult(ray.dir, plane.dir);
	if (den == 0)
		return (init_p2(-1, -1));
	num =-plane.d - sc_mult(ray.pos, plane.dir);
	roots = init_p2(num/den, num/den);
	return (roots);
}

t_p2		intersect_cone(t_ray ray, t_cone cone)
{
	t_p2 roots;
	t_p3 k;
	t_p3 t_pos;
	double c;
	double d;

	t_pos = lin_comb(ray.pos, 1, cone.pos, -1);
	c = cone.r/cone.c;
	k.x = (ray.dir.x*ray.dir.x + ray.dir.z*ray.dir.z - ray.dir.y*ray.dir.y*c*c);
	k.y = 2*(ray.dir.x*t_pos.x + ray.dir.z*t_pos.z - ray.dir.y*t_pos.y*c*c);
	k.z = (t_pos.x*t_pos.x + t_pos.z*t_pos.z + t_pos.y*t_pos.y*c*c);
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
	return (roots);
}


static t_rgb	trace_ray(t_ray ray, t_scene scene)
{
	t_rgb colour;
	t_p2 roots;
	t_p2 new_roots;

	colour = init_rgb(255, 255, 255, 255);
	roots = init_p2(1000000, 1000000);
	while (scene.objects)
	{
		if (scene.objects->type == T_SPHERE)
			new_roots = intersect_sphere(ray, *((t_sphere*)scene.objects->data));
		if (scene.objects->type == T_PLANE)
			new_roots = intersect_plane(ray, *((t_plane*)scene.objects->data));
		if (scene.objects->type == T_CONE)
			new_roots = intersect_cone(ray, *((t_cone *) scene.objects->data));

		if(new_roots.x >= 0 && new_roots.y >= 0)
		{
			if (min(roots.x, roots.y) > min(new_roots.x, new_roots.y))
			{
				roots = new_roots;
				colour = scene.objects->colour;
			}
		}
		scene.objects = scene.objects->next;
	}
	return colour;
}

void			draw_scene(t_scene scene, unsigned char *win_buff, int pitch)
{
	t_ray	ray;
	t_i2	count;
	t_rgb	colour;

	count.x = 0;
	while (count.x < W_W)
	{
		count.y = 0;
		while (count.y < W_H)
		{
			ray = get_ray(scene.camera, count.x - W_W/2, W_H/2 - count.y);
			colour = trace_ray(ray, scene);
			win_buff[count.x * 4 + 0 + count.y * pitch] = colour.b; //b
			win_buff[count.x * 4 + 1 + count.y * pitch] = colour.g; //g
			win_buff[count.x * 4 + 2 + count.y * pitch] = colour.r; //r
			win_buff[count.x * 4 + 3 + count.y * pitch] = colour.a; //a
			count.y++;
		}
		count.x++;
	}
}