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

t_ray			init_ray(t_p3 pos, t_p3 dir)
{
	t_ray ret;

	ret.dir = dir;
	ret.pos = pos;
	return (ret);
}

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
			if (min(roots.x, roots.y) > min(new_roots.x, new_roots.y) && min(new_roots.x, new_roots.y) >= 0.0001)
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
	ret.dir = lin_comb(norm, -2*sc_mult(norm, ray.dir), ray.dir, 1);
	normalize(&(ret.dir));
	return ret;
}

t_rgb			trace_ray(t_ray ray, t_scene scene, int depth)
{
	t_rgb		colour;
	double		root;
	t_object	*current;
	t_rgb		reflected_colour;
	t_ray 		reflected;

	root = get_intersection(ray, scene, &current, &colour);
	if (!current)
		return (colour);
    if (current && current == scene.chosen)
        colour = init_rgb(255, 255, 0, 255);
    if (current->type == T_SPHERE) {
        t_p3 inter;
        double alpha;
        double beta;
        inter = lin_comb(ray.pos, 1, ray.dir, root);
        inter = transform_pos(inter, current->i_t, current->pos);
        normalize(&inter);
        alpha = acos(inter.x);
        beta = atan2(inter.y, inter.z);
        if (beta < 0)
            beta += 3.14;
        alpha = alpha * 10 / 3.14;
        beta = beta * 10 / 3.14;
        if ((int) alpha % 2 == (int) beta % 2) {
            colour = init_rgb(250, 0, 0, 255);
        } else {
            colour = init_rgb(0, 0, 255, 255);
        }
    }

	colour = colour_mult(colour,\
	current->light_funk(scene.lights, *current, ray, root));

	if (depth == DEPTH)
		return (colour);

	reflected = reflect(ray, current->norm_funk(*current, ray, root), root);
	reflected_colour = trace_ray(reflected, scene, depth + 1);

	t_rgb ret;
	ret.r = colour.r*0.6 + reflected_colour.r*0.4;
	ret.g = colour.g*0.6 + reflected_colour.g*0.4;
	ret.b = colour.b*0.6 + reflected_colour.b*0.4;
	ret.a = 255;

	return (ret);
}

int				draw_scene(t_scene scene, unsigned char *win_buff, int pitch)
{
	t_i2			count;
	t_p_data		*data;
	pthread_t		*threads;
	pthread_attr_t	attr;

	init_threads(&data, &threads, &attr);
	if (!data || !threads)
		return (0);
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
	collect_threads(threads, data);
	return (1);
}
