/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:57:58 by ppepperm          #+#    #+#             */
/*   Updated: 2021/03/10 03:47:05 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int				push_sphere(t_scene *scene, char **nums)
{
	t_object	*object;

	if (!(object = (t_object*)malloc(sizeof(t_object))))
		return (0);
	object->type = T_SPHERE;
	if (!(object->data = return_sphere(nums)))
	{
		free(object);
		return (0);
	}
	object->pos = init_p3(ft_atoip(nums[0]),\
	ft_atoip(nums[1]), ft_atoip(nums[2]));
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoip(nums[4]),\
	ft_atoip(nums[5]), ft_atoip(nums[6]), 255);
	object->reflect = ft_atoip(nums[7]);
	object->mirror = (double)ft_atoip(nums[8]) / 100;
	object->intersect = intersect_sphere;
	object->light_funk = sphere_light;
	object->norm_funk = sphere_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int				push_plane(t_scene *scene, char **nums)
{
	t_object	*object;

	if (!(object = (t_object*)malloc(sizeof(t_object))))
		return (0);
	object->type = T_PLANE;
	if (!(object->data = return_plane(nums)))
	{
		free(object);
		return (0);
	}
	object->pos = init_p3(0, 0, 0);
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoip(nums[4]),\
	ft_atoip(nums[5]), ft_atoip(nums[6]), 255);
	object->reflect = ft_atoip(nums[7]);
	object->mirror = (double)ft_atoip(nums[8]) / 100;
	object->intersect = intersect_plane;
	object->light_funk = plane_light;
	object->norm_funk = plane_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int				push_cone(t_scene *scene, char **nums)
{
	t_object	*object;

	if (!(object = (t_object*)malloc(sizeof(t_object))))
		return (0);
	object->type = T_CONE;
	if (!(object->data = return_cone(nums)))
	{
		free(object);
		return (0);
	}
	object->pos = init_p3(ft_atoip(nums[0]),\
	ft_atoip(nums[1]), ft_atoip(nums[2]));
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoip(nums[5]),\
	ft_atoip(nums[6]), ft_atoip(nums[7]), 255);
	object->reflect = ft_atoip(nums[8]);
	object->mirror = (double)ft_atoip(nums[9]) / 100;
	object->intersect = intersect_cone;
	object->light_funk = cone_light;
	object->norm_funk = cone_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int				push_cylinder(t_scene *scene, char **nums)
{
	t_object	*object;

	if (!(object = (t_object*)malloc(sizeof(t_object))))
		return (0);
	object->type = T_CYLINDER;
	if (!(object->data = return_cylinder(nums)))
	{
		free(object);
		return (0);
	}
	object->pos = init_p3(ft_atoip(nums[0]),\
	ft_atoip(nums[1]), ft_atoip(nums[2]));
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoip(nums[4]),\
	ft_atoip(nums[5]), ft_atoip(nums[6]), 255);
	object->reflect = ft_atoip(nums[7]);
	object->mirror = (double)ft_atoip(nums[8]) / 100;
	object->intersect = intersect_cylinder;
	object->light_funk = cylinder_light;
	object->norm_funk = cylinder_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int				push_hyperboloid(t_scene *scene, char **nums)
{
	t_object	*object;

	if (!(object = (t_object*)malloc(sizeof(t_object))))
		return (0);
	object->type = T_HYPERBOLOID;
	if (!(object->data = return_hyperboloid(nums)))
	{
		free(object);
		return (0);
	}
	object->pos = init_p3(ft_atoip(nums[0]),\
	ft_atoi(nums[1]), ft_atoi(nums[2]));
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoip(nums[5]),\
	ft_atoip(nums[6]), ft_atoip(nums[7]), 255);
	object->reflect = ft_atoip(nums[8]);
	object->mirror = (double)ft_atoip(nums[9]) / 100;
	object->intersect = intersect_hyperboloid;
	object->light_funk = cone_light;
	object->norm_funk = hyperboloid_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}
// printf("%f %f %f\n", object->pos.x, object->pos.y, object->pos.z);
