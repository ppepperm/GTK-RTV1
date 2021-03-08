/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:01:07 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/23 13:02:33 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		get_light(t_object *objects,
		t_light *lights, t_light_arg arg, t_ray ray)
{
	t_p3	light;
	double	i;
	double	cosa;
	t_p3	r;

	i = 0.5;
	while (lights)
	{
		prep_light(lights, &light, arg);
		if (check_shadow(objects, *lights, arg.inter))
		{
			lights = lights->next;
			continue;
		}
		cosa = -sc_mult(arg.norm, light);
		inc_i(cosa, lights, &i, 1);
		r = lin_comb(arg.norm, 2 * cosa, light, 1);
		normalize(&r);
		cosa = -sc_mult(r, ray.dir);
		inc_i(cosa, lights, &i, ray.pos.x);
		lights = lights->next;
	}
	return (i);
}

double		sphere_light(t_light *lights,
		t_object object, t_ray ray, double root)
{
	t_p3		inter;
	t_p3		norm;
	t_light_arg	arg;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	norm = object.norm_funk(object, ray, root);
	ray.pos.x = object.reflect;
	arg.norm = norm;
	arg.inter = inter;
	return (get_light(object.head, lights, arg, ray));
}

double		plane_light(t_light *lights,
		t_object object, t_ray ray, double root)
{
	t_p3		norm;
	t_p3		inter;
	t_light_arg	arg;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	norm = object.norm_funk(object, ray, root);
	ray.pos.x = object.reflect;
	arg.norm = norm;
	arg.inter = inter;
	return (get_light(object.head, lights, arg, ray));
}

double		cylinder_light(t_light *lights,
		t_object object, t_ray ray, double root)
{
	t_p3		norm;
	t_p3		inter;
	t_light_arg	arg;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	norm = object.norm_funk(object, ray, root);
	ray.pos.x = object.reflect;
	arg.norm = norm;
	arg.inter = inter;
	return (get_light(object.head, lights, arg, ray));
}

double		cone_light(t_light *lights, t_object object, t_ray ray, double root)
{
	t_p3		norm;
	t_p3		inter;
	t_light_arg	arg;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	norm = object.norm_funk(object, ray, root);
	ray.pos.x = object.reflect;
	arg.norm = norm;
	arg.inter = inter;
	return (get_light(object.head, lights, arg, ray));
}

