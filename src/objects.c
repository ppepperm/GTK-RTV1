/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:57:58 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/23 16:58:01 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int	push_sphere(t_scene *scene, char **nums)
{
	t_object	*object;

	object = (t_object*)malloc(sizeof(t_object));
	object->type = T_SPHERE;
	object->data = return_sphere(nums);
	object->pos = init_p3(ft_atoi(nums[1]),\
	ft_atoi(nums[2]), ft_atoi(nums[3]));
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoi(nums[5]),\
	ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
	object->reflect = ft_atoi(nums[8]);
	object->intersect = intersect_sphere;
	object->light_funk = sphere_light;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int	push_plane(t_scene *scene, char **nums)
{
	t_object	*object;

	object = (t_object*)malloc(sizeof(t_object));
	object->type = T_PLANE;
	object->data = return_plane(nums);
	object->pos = init_p3(0, 0, 0);
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoi(nums[5]),\
	ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
	object->reflect = ft_atoi(nums[8]);
	object->intersect = intersect_plane;
	object->light_funk = plane_light;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int	push_cone(t_scene *scene, char **nums)
{
	t_object	*object;

	object = (t_object*)malloc(sizeof(t_object));
	object->type = T_CONE;
	object->data = return_cone(nums);
	object->pos = init_p3(ft_atoi(nums[1]),\
	ft_atoi(nums[2]), ft_atoi(nums[3]));
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoi(nums[6]),\
	ft_atoi(nums[7]), ft_atoi(nums[8]), 255);
	object->reflect = ft_atoi(nums[9]);
	object->intersect = intersect_cone;
	object->light_funk = cone_light;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int	push_cylinder(t_scene *scene, char **nums)
{
	t_object	*object;

	object = (t_object*)malloc(sizeof(t_object));
	object->type = T_CYLINDER;
	object->data = return_cylinder(nums);
	object->pos = init_p3(ft_atoi(nums[1]),\
	ft_atoi(nums[2]), ft_atoi(nums[3]));
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoi(nums[5]),\
	ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
	object->reflect = ft_atoi(nums[8]);
	object->intersect = intersect_cylinder;
	object->light_funk = cylinder_light;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}
