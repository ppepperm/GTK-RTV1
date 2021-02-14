/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:43:44 by ppepperm          #+#    #+#             */
/*   Updated: 2021/02/14 14:43:46 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_p3	sphere_norm(t_object object, t_ray ray, double root)
{
	t_p3		inter;
	t_p3		norm;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	norm = transform_pos(inter, object.i_t, object.pos);
	norm = transform_dir(norm, object.t);
	normalize(&norm);
	return (norm);
}

t_p3	plane_norm(t_object object, t_ray ray, double root)
{
	t_p3		norm;

	ray.dir.x = root;
	norm = ((t_plane*)(object.data))->dir;
	norm = transform_dir(norm, object.t);
	normalize(&norm);
	return (norm);
}

t_p3	cylinder_norm(t_object object, t_ray ray, double root)
{
	t_p3		inter;
	t_p3		norm;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	norm = transform_pos(inter, object.i_t, object.pos);
	norm.y = 0;
	norm = transform_dir(norm, object.t);
	normalize(&norm);
	return (norm);
}

t_p3	cone_norm(t_object object, t_ray ray, double root)
{
	t_p3		inter;
	t_p3		norm;
	t_p3		new_inter;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	new_inter = transform_pos(inter, object.i_t, object.pos);
	norm = return_norm_cone(*((t_cone*)object.data), new_inter);
	norm = transform_dir(norm, object.t);
	normalize(&norm);
	return (norm);
}