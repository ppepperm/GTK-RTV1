/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 20:09:59 by ppepperm          #+#    #+#             */
/*   Updated: 2021/02/28 18:52:42 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray			get_ray(t_camera camera, double x, double y)
{
	t_ray	ray;
	t_p3	tmp;

	ray.pos = camera.pos;
	tmp = lin_comb(camera.x_dir, x / 1000, camera.y_dir, y / 1000);
	ray.dir = lin_comb(tmp, 1, camera.z_dir, C_Z);
	normalize(&ray.dir);
	return (ray);
}

double			get_intersection(t_ray ray,
		t_scene scene, t_object **current, t_rgb *colour)
{
	t_p2	roots;
	t_p2	new_roots;

	*colour = init_rgb(250, 250, 250, 255);
	*current = NULL;
	roots = init_p2(3000000, 3000000);
	while (scene.objects)
	{
		new_roots = scene.objects->intersect(ray, *(scene.objects));
		if (new_roots.x >= 0 && new_roots.y >= 0)
		{
			if (min(roots.x, roots.y) > min(new_roots.x, new_roots.y) &&\
				min(new_roots.x, new_roots.y) >= 0.0001)
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

t_ray			reflect(t_ray ray, t_p3 norm, double root)
{
	t_ray ret;

	ret.pos = lin_comb(ray.pos, 1, ray.dir, root);
	ret.dir = lin_comb(norm, -2 * sc_mult(norm, ray.dir), ray.dir, 1);
	normalize(&(ret.dir));
	return (ret);
}

t_rgb			trace_ray(t_ray ray, t_scene scene, int depth)
{
	t_rgb		colour;
	double		root;
	t_object	*current;
	t_rgb		reflected_colour;
	t_ray		reflected;
	t_rgb		ret;

	root = get_intersection(ray, scene, &current, &colour);
	if (!current)
		return (colour);
	if (current && current == scene.chosen)
		return (init_rgb(255, 0, 255, 255));
	if (scene.effect == 1)
		colour = checkers(current, root, ray);
	colour = colour_mult(colour,\
		current->light_funk(scene.lights, *current, ray, root));
	if (depth == DEPTH || current->mirror == 0)
		return (colour);
	reflected = reflect(ray, current->norm_funk(*current, ray, root), root);
	reflected_colour = trace_ray(reflected, scene, depth + 1);
	ret.r = colour.r * (1 - current->mirror) +\
		reflected_colour.r * current->mirror;
	ret.g = colour.g * (1 - current->mirror) +\
		reflected_colour.g * current->mirror;
	ret.b = colour.b * (1 - current->mirror) +\
		reflected_colour.b * current->mirror;
	ret.a = 255;
	return (ret);
}

int				draw_scene(t_scene scene, unsigned char *win_buff, int pitch)
{
	t_i2			count;
	t_p_data		data[(size_t)(W_W)];
	pthread_t		threads[(size_t)(W_W)];
	pthread_attr_t	attr;

	pthread_attr_init(&attr);
	count.x = 0;
	while (count.x < W_W)
	{
		data[count.x].scene = scene;
		data[count.x].win_buff = win_buff;
		data[count.x].pitch = pitch;
		data[count.x].coll = count.x;
		pthread_create(&(threads[count.x]),\
		&attr, thread_trace, (void *)(&data[count.x]));
		count.x++;
	}
	collect_threads(threads);
	return (1);
}
