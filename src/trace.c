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

static t_rgb	trace_ray(t_ray ray, t_scene scene)
{
	t_rgb       colour;
	t_p2        roots;
	t_p2        new_roots;
	t_object    *current;
    t_p3        norm;
    t_p3        inter;

	colour = init_rgb(255, 255, 255, 255);
	current = NULL;
	roots = init_p2(1000000, 1000000);
	while (scene.objects)
	{
		if (scene.objects->type == T_SPHERE)
			new_roots = intersect_sphere(ray, *(scene.objects));
		if (scene.objects->type == T_PLANE)
			new_roots = intersect_plane(ray, *(scene.objects));
		if (scene.objects->type == T_CONE)
            new_roots = intersect_cone(ray, *(scene.objects));
		if (scene.objects->type == T_CYLINDER)
			new_roots = intersect_cylinder(ray, *(scene.objects));
		if(new_roots.x >= 0 && new_roots.y >= 0)
		{
			if(min(roots.x, roots.y) > min(new_roots.x, new_roots.y))
			{
				roots = new_roots;
				colour = scene.objects->colour;
				current = scene.objects;
			}
		}
		scene.objects = scene.objects->next;
	}
	if(!current)
	    return (colour);
    if (current && current == scene.chosen)
        return (init_rgb(255, 255, 0, 255));
    inter = lin_comb(ray.pos, 1, ray.dir, min(roots.x, roots.y));
	if(current->type == T_SPHERE)
    {
	    norm = transform_pos(inter, current->i_t, current->pos);
	    norm = transform_dir(norm, current->t);
        normalize(&norm);
	    colour = colour_mult(colour, get_light(scene, inter, norm));
    }
	else if(current->type == T_PLANE)
    {
        norm = return_norm_plane(*((t_plane*)current->data));
        norm = transform_dir(norm, current->t);
        normalize(&norm);
        colour = colour_mult(colour, get_light_p(scene, inter, norm));

    }
	else if(current->type == T_CYLINDER)
    {
        norm = transform_pos(inter, current->i_t, current->pos);
        norm.y = 0;
        norm = transform_dir(norm, current->t);
        normalize(&norm);
        colour = colour_mult(colour, get_light(scene, inter, norm));
    }
	else if(current->type == T_CONE)
    {
        inter = transform_pos(inter, current->i_t, current->pos);
        norm = return_norm_cone(*((t_cone*)current->data), inter);
        norm = transform_dir(norm, current->t);
        normalize(&norm);
        colour = colour_mult(colour, get_light(scene, inter, norm));
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