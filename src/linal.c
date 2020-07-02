/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:16:48 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/21 21:16:50 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_p3	lin_comb(t_p3 a, double k1, t_p3 b, double k2)
{
	t_p3 ret;

	ret.x = k1*a.x + k2*b.x;
	ret.y = k1*a.y + k2*b.y;
	ret.z = k1*a.z + k2*b.z;
	return (ret);
}

double	sc_mult(t_p3 a, t_p3 b)
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

double min(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

t_ray ray_transform(t_ray ray, t_transform t, t_p3 pos)
{
	t_ray new_ray;
	t_transform inv;
	double	  det;

	det = t.x_dir.x*(t.y_dir.y * t.z_dir.z - t.y_dir.z * t.z_dir.y) -\
	t.y_dir.x*(t.x_dir.y * t.z_dir.z - t.x_dir.z * t.z_dir.y) +\
	t.z_dir.x*(t.x_dir.y * t.y_dir.z - t.x_dir.z * t.y_dir.y);
	inv.x_dir = init_p3((t.y_dir.y*t.z_dir.z - t.y_dir.z*t.z_dir.y),\
	-(t.x_dir.y*t.z_dir.z - t.x_dir.z*t.z_dir.y),\
	(t.x_dir.y*t.z_dir.z - t.x_dir.z*t.y_dir.y));
	inv.x_dir = lin_comb(inv.x_dir, 1/det, init_p3(0, 0, 0), 0);
	inv.y_dir = init_p3(-(t.y_dir.x*t.z_dir.z - t.y_dir.z*t.z_dir.x),\
	(t.x_dir.x*t.z_dir.z - t.x_dir.z*t.z_dir.x),\
	-(t.x_dir.x*t.y_dir.z - t.x_dir.z*t.y_dir.x));
	inv.y_dir = lin_comb(inv.y_dir, 1/det, init_p3(0, 0, 0), 0);
	inv.z_dir = init_p3((t.y_dir.x*t.z_dir.y - t.y_dir.y*t.z_dir.x),\
	-(t.x_dir.x*t.z_dir.y - t.x_dir.y*t.z_dir.x),\
	(t.x_dir.x*t.y_dir.y - t.x_dir.y*t.y_dir.x));
	inv.z_dir = lin_comb(inv.z_dir, 1/det, init_p3(0, 0, 0), 0);

	ray.pos = lin_comb(ray.pos, 1, pos, -1);
	new_ray.pos = lin_comb(inv.x_dir, ray.pos.x, inv.y_dir, ray.pos.y);
	new_ray.pos = lin_comb(new_ray.pos, 1, inv.z_dir, ray.pos.z);
	new_ray.dir = lin_comb(inv.x_dir, ray.dir.x, inv.y_dir, ray.dir.y);
	new_ray.dir = lin_comb(new_ray.dir, 1, inv.z_dir, ray.pos.z);

	return (new_ray);
}

void	normalize(t_p3 *vec)
{
	double abs;

	abs = sqrt(vec->x*vec->x + vec->y*vec->y + vec->z*vec->z);
	vec->x /= abs;
	vec->y /= abs;
	vec->z /= abs;
}

t_p3    return_norm_sphere(t_sphere sphere, t_p3 inter)
{
    t_p3 ret;

    ret = lin_comb(inter, 1, sphere.pos, -1);
    normalize(&ret);
    return (ret);
}

t_p3    return_norm_plane(t_plane plane)
{
    return (plane.dir);
}

t_p3    return_norm_cylinder(t_cylinder cylinder, t_p3 inter)
{
    t_p3 ret;

    ret = lin_comb(inter, 1, cylinder.pos, -1);
    ret.y = 0;
    return (ret);
}

t_p3    return_norm_cone(t_cone cone, t_p3 inter)
{
    t_p3 ret;
    double y;

    ret = lin_comb(inter, 1, cone.pos, -1);
    y = sqrt(ret.x*ret.x + ret.z*ret.z);
    y = y*cone.r/cone.c;
    if (ret.y < 0)
        ret.y = y;
    else
        ret.y = -y;
    return (ret);
}