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
	normalize(&ray.dir);
	return (ray);
}

static t_rgb	trace_ray(t_ray ray, t_scene scene)
{
	t_rgb       colour;
	double      root;
	t_object    *current;

    root = get_intersection(ray, scene, &current, &colour);
	if(!current)
	    return (colour);
    if (current && current == scene.chosen)
        return (init_rgb(255, 255, 0, 255));

    colour = colour_mult(colour, current->light_funk(scene.objects, scene.lights, *current, ray, root));
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