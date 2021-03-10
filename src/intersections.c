/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:49:52 by ppepperm          #+#    #+#             */
/*   Updated: 2021/03/10 03:51:29 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_p2				intersect_sphere(t_ray ray, t_object object)
{
	t_p3			k;
	t_sphere		*sphere;
	double			d;

	sphere = (t_sphere*)object.data;
	ray = ray_transform(ray, object.i_t, object.pos);
	k.x = sc_mult(ray.dir, ray.dir);
	k.y = 2 * sc_mult(ray.dir, ray.pos);
	k.z = sc_mult(ray.pos, ray.pos) - sphere->r * sphere->r;
	d = k.y * k.y - 4 * k.x * k.z;
	if (d >= 0)
		return (init_p2((-k.y - sqrt(d))\
		/ (2 * k.x), (-k.y + sqrt(d)) / (2 * k.x)));
	else
		return (init_p2(-1, -1));
}

t_p2				intersect_plane(t_ray ray, t_object object)
{
	t_plane			*plane;
	double			den;
	double			num;

	plane = (t_plane*)object.data;
	ray = ray_transform(ray, object.i_t, object.pos);
	den = sc_mult(ray.dir, plane->dir);
	if (den == 0)
		return (init_p2(-1, -1));
	num = plane->d - sc_mult(ray.pos, plane->dir);
	return (init_p2(num / den, num / den));
}

t_p2				intersect_cone(t_ray ray, t_object object)
{
	t_cone			*cone;
	t_p3			k;
	double			c;
	double			d;

	cone = (t_cone*)object.data;
	ray = ray_transform(ray, object.i_t, object.pos);
	c = cone->r / cone->c;
	k.x = (ray.dir.x * ray.dir.x\
	+ ray.dir.z * ray.dir.z - ray.dir.y * ray.dir.y * c * c);
	k.y = 2 * (ray.dir.x * ray.pos.x\
	+ ray.dir.z * ray.pos.z - ray.dir.y * ray.pos.y * c * c);
	k.z = (ray.pos.x * ray.pos.x\
	+ ray.pos.z * ray.pos.z - ray.pos.y * ray.pos.y * c * c);
	d = k.y * k.y - 4 * k.x * k.z;
	if (d >= 0)
		return (init_p2((-k.y - sqrt(d))\
		/ (2 * k.x), (-k.y + sqrt(d)) / (2 * k.x)));
	else
		return (init_p2(-1, -1));
}

t_p2				intersect_cylinder(t_ray ray, t_object object)
{
	t_cylinder		*cylinder;
	t_p3			k;
	double			d;

	cylinder = (t_cylinder*)object.data;
	ray = ray_transform(ray, object.i_t, object.pos);
	k.x = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	k.y = 2 * (ray.pos.x * ray.dir.x + ray.pos.z * ray.dir.z);
	k.z = ray.pos.x * ray.pos.x + ray.pos.z\
	* ray.pos.z - cylinder->r * cylinder->r;
	d = k.y * k.y - 4 * k.x * k.z;
	if (d >= 0)
		return (init_p2((-k.y - sqrt(d))\
		/ (2 * k.x), (-k.y + sqrt(d)) / (2 * k.x)));
	else
		return (init_p2(-1, -1));
}

t_p2				intersect_hyperboloid(t_ray ray, t_object object)
{
	t_hyperboloid	*hyperboloid;
	t_p3			k;
	double			c;
	double			d;

	hyperboloid = (t_hyperboloid*)object.data;
	ray = ray_transform(ray, object.i_t, object.pos);
	c = hyperboloid->r / hyperboloid->c;
	k.x = (ray.dir.x * ray.dir.x\
	+ ray.dir.z * ray.dir.z - ray.dir.y * ray.dir.y * c * c);
	k.y = 2 * (ray.dir.x * ray.pos.x\
	+ ray.dir.z * ray.pos.z - ray.dir.y * ray.pos.y * c * c);
	k.z = (ray.pos.x * ray.pos.x\
	+ ray.pos.z * ray.pos.z - ray.pos.y * ray.pos.y\
	* c * c - hyperboloid->r * hyperboloid->r);
	d = k.y * k.y - 4 * k.x * k.z;
	if (d >= 0)
		return (init_p2((-k.y - sqrt(d))\
		/ (2 * k.x), (-k.y + sqrt(d)) / (2 * k.x)));
	else
		return (init_p2(-1, -1));
}
