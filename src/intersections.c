/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:49:52 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/23 12:57:31 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_p2			intersect_sphere(t_ray ray, t_object object)
{
	t_p3		k;
	t_sphere	*sphere;
	double		d;

	sphere = (t_sphere*)object.data;
	ray = ray_transform(ray, object.i_t, object.pos);
	k.x = sc_mult(ray.dir, ray.dir);
	k.y = 2 * sc_mult(ray.dir, ray.pos);
	k.z = sc_mult(ray.pos, ray.pos) - sphere->r * sphere->r;
	d = k.y * k.y - 4 * k.x * k.z;
	if (d >= 0)
		return (init_p2((-k.y - sqrt(d)) / (2 * k.x), (-k.y + sqrt(d)) / (2 * k.x)));
	else
		return (init_p2(-1, -1));
}

t_p2			intersect_plane(t_ray ray, t_object object)
{
	t_plane	*plane;
	double	den;
	double	num;

	plane = (t_plane*)object.data;
	ray = ray_transform(ray, object.i_t, object.pos);
	den = sc_mult(ray.dir, plane->dir);
	if (den == 0)
		return (init_p2(-1, -1));
	num = plane->d - sc_mult(ray.pos, plane->dir);
	return (init_p2(num / den, num / den));
}

t_p2			intersect_cone(t_ray ray, t_object object)
{
	t_cone	*cone;
	t_p3	k;
	double	c;
	double	d;

	cone = (t_cone*)object.data;
	ray = ray_transform(ray, object.i_t, object.pos);
	c = cone->r / cone->c;
	k.x = (ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z - ray.dir.y * ray.dir.y * c * c);
	k.y = 2 * (ray.dir.x * ray.pos.x + ray.dir.z * ray.pos.z - ray.dir.y * ray.pos.y * c * c);
	k.z = (ray.pos.x * ray.pos.x + ray.pos.z * ray.pos.z - ray.pos.y * ray.pos.y * c * c);
	d = k.y * k.y - 4 * k.x * k.z;
	if (d >= 0)
		return (init_p2((-k.y - sqrt(d)) / (2 * k.x), (-k.y + sqrt(d)) / (2 * k.x)));
	else
		return (init_p2(-1, -1));
}

t_p2			intersect_cylinder(t_ray ray, t_object object)
{
	t_cylinder	*cylinder;
	t_p3		k;
	double		d;

	cylinder = (t_cylinder*)object.data;
	ray = ray_transform(ray, object.i_t, object.pos);
	k.x = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	k.y = 2 * (ray.pos.x * ray.dir.x + ray.pos.z * ray.dir.z);
	k.z = ray.pos.x * ray.pos.x + ray.pos.z * ray.pos.z - cylinder->r * cylinder->r;
	d = k.y * k.y - 4 * k.x * k.z;
	if (d >= 0)
		return (init_p2((-k.y - sqrt(d)) / (2 * k.x), (-k.y + sqrt(d)) / (2 * k.x)));
	else
		return (init_p2(-1, -1));
}

double			get_intersection(t_ray ray, t_scene scene, t_object **current, t_rgb *colour)
{
	t_p2	roots;
	t_p2	new_roots;

	*colour = init_rgb(255, 255, 255, 255);
	*current = NULL;
	roots = init_p2(3000000, 3000000);
	while (scene.objects)
	{
		new_roots = scene.objects->intersect(ray, *(scene.objects));
		if (new_roots.x >= 0 && new_roots.y >= 0)
		{
			if (min(roots.x, roots.y) > min(new_roots.x, new_roots.y))
			{
				roots = new_roots;
				*colour = scene.objects->colour;
				*current = scene.objects;
			}
		}
		scene.objects = scene.objects->next;
	}
	return (min(roots.x, roots.y));
}

int				check_shadow(t_object *objects, t_light light, t_p3 inter)
{
	t_p2	roots;
	t_ray	shadow_ray;

	if (light.type == L_DIR)
	{
		shadow_ray.pos = inter;
		shadow_ray.dir = lin_comb(light.data, -1, init_p3(0, 0, 0), 0);
		while (objects)
		{
			roots = objects->intersect(shadow_ray, *(objects));
			if (roots.x > 0.0001 || roots.y > 0.0001)
				return (1);
			objects = objects->next;
		}
	}
	else if (light.type == L_DOT)
	{
		shadow_ray.pos = light.data;
		shadow_ray.dir = lin_comb(inter, 1, light.data, -1);
		while (objects)
		{
			roots = objects->intersect(shadow_ray, *(objects));
			if ((roots.x > 0.0001 && roots.x < 0.9999) || (roots.y > 0.0001 && roots.y < 0.9999))
				return (1);
			objects = objects->next;
		}
	}
	return (0);
}
