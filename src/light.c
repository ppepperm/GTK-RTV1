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

t_rgb		colour_mult(t_rgb base, double k)
{
	double r;
	double g;
	double b;

	r = base.r * k;
	if (r > 255)
		r = 255;
	g = base.g * k;
	if (g > 255)
		g = 255;
	b = base.b * k;
	if (b > 255)
		b = 255;
	return (init_rgb((unsigned char)r, (unsigned char)g, (unsigned char)b, 255));
}

double		get_light(t_object *objects, t_light *lights, t_p3 inter, t_p3 norm, t_ray ray)
{
	t_p3	light;
	double	i;
	double	cosa;
	t_p3	r;

	i = 0.2;
	while (lights)
	{
		if (lights->type == L_DIR)
			light = lights->data;
		else if (lights->type == L_DOT)
			light = lin_comb(inter, 1, lights->data, -1);
		normalize(&light);
		if (check_shadow(objects, *lights, inter))
		{
			lights = lights->next;
			continue;
		}
		cosa = -sc_mult(norm, light);
		if (cosa < 0)
			cosa = 0;
		i += cosa * lights->i;
		r = lin_comb(norm, 2 * cosa, light, 1);
		normalize(&r);
		cosa = -sc_mult(r, ray.dir);
		if (cosa < 0)
			cosa = 0;
		cosa = pow(cosa, ray.pos.x);
		i += cosa * lights->i;
		lights = lights->next;
	}
	return (i);
}

double		sphere_light(t_object *objects, t_light *lights, t_object object, t_ray ray, double root)
{
	t_p3 inter;
	t_p3 norm;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	norm = transform_pos(inter, object.i_t, object.pos);
	norm = transform_dir(norm, object.t);
	normalize(&norm);
	ray.pos.x = object.reflect;
	return (get_light(objects, lights, inter, norm, ray));
}

double		plane_light(t_object *objects, t_light *lights, t_object object, t_ray ray, double root)
{
	t_p3 norm;
	t_p3 inter;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	norm = ((t_plane*)(object.data))->dir;
	norm = transform_dir(norm, object.t);
	normalize(&norm);
	ray.pos.x = object.reflect;
	return (get_light(objects, lights, inter, norm, ray));
}

double		cylinder_light(t_object *objects, t_light *lights, t_object object, t_ray ray, double root)
{
	t_p3 norm;
	t_p3 inter;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	norm = transform_pos(inter, object.i_t, object.pos);
	norm.y = 0;
	norm = transform_dir(norm, object.t);
	normalize(&norm);
	ray.pos.x = object.reflect;
	return (get_light(objects, lights, inter, norm, ray));
}

double		cone_light(t_object *objects, t_light *lights, t_object object, t_ray ray, double root)
{
	t_p3 norm;
	t_p3 inter;
	t_p3 new_inter;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	new_inter = transform_pos(inter, object.i_t, object.pos);
	norm = return_norm_cone(*((t_cone*)object.data), new_inter);
	norm = transform_dir(norm, object.t);
	normalize(&norm);
	ray.pos.x = object.reflect;
	return (get_light(objects, lights, inter, norm, ray));
}
