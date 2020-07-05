/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 12:42:44 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/05 12:42:46 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_p2			intersect_sphere(t_ray ray, t_object object)
{
    t_p3 k;
    t_sphere *sphere;
    double d;

    sphere = (t_sphere*)object.data;
    ray = ray_transform(ray, object.i_t, object.pos);
    k.x = sc_mult(ray.dir, ray.dir);
    k.y = 2*sc_mult(ray.dir, ray.pos);
    k.z = sc_mult(ray.pos, ray.pos) - sphere->r * sphere->r;
    d = k.y * k.y - 4 * k.x * k.z;
    if (d >= 0)
        return(init_p2((-k.y - sqrt(d))/(2*k.x), (-k.y + sqrt(d))/(2*k.x)));
    else
        return ( init_p2(-1, -1));
}

t_p2			intersect_plane(t_ray ray, t_object object)
{
    t_plane *plane;
    double den;
    double num;

    plane = (t_plane*)object.data;
    ray = ray_transform(ray, object.i_t, object.pos);
    den = sc_mult(ray.dir, plane->dir);
    if (den == 0)
        return (init_p2(-1, -1));
    num =plane->d - sc_mult(ray.pos, plane->dir);
    return (init_p2(num/den, num/den));
}

t_p2			intersect_cone(t_ray ray, t_cone cone)
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
    k.z = (t_pos.x*t_pos.x + t_pos.z*t_pos.z - t_pos.y*t_pos.y*c*c);
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

t_p2			intersect_cylinder(t_ray ray, t_cylinder cylinder)
{
    t_p2 roots;
    t_p3 k;
    t_p3 t_pos;
    double d;

    t_pos = lin_comb(ray.pos, 1, cylinder.pos, -1);
    k.x = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
    k.y = 2 * (t_pos.x * ray.dir.x + t_pos.z * ray.dir.z);
    k.z = t_pos.x * t_pos.x + t_pos.z * t_pos.z - cylinder.r * cylinder.r;
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