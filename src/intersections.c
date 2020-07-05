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
    num =plane.d - sc_mult(ray.pos, plane.dir);
    roots = init_p2(num/den, num/den);
    return (roots);
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