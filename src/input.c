/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:49:08 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/15 15:57:19 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	read_obj(int fd, t_scene *scene)
{
	t_object	*object;
	t_light		*light;
	char		*str;
	char		**nums;

	while (get_next_line(fd, &str))
	{
		nums = ft_strsplit(str, ';');
		if (!ft_strcmp(nums[0], "sphere"))
		{
			object = (t_object*)malloc(sizeof(t_object));
			object->type = T_SPHERE;
			object->data = return_sphere(nums);
			object->pos = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
			object->t = init_transform(init_p3(1, 0, 0), init_p3(0, 1, 0), init_p3(0, 0, 1));
			object->i_t = i_transform(object->t);
			object->colour = init_rgb(ft_atoi(nums[5]), ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
			object->reflect = ft_atoi(nums[8]);
			object->intersect = intersect_sphere;
			object->light_funk = sphere_light;
			object->next = scene->objects;
			scene->objects = object;
		}
		else if (!ft_strcmp(nums[0], "plane"))
		{
			object = (t_object*)malloc(sizeof(t_object));
			object->type = T_PLANE;
			object->data = return_plane(nums);
			object->pos = init_p3(0, 0, 0);
			object->t = init_transform(init_p3(1, 0, 0), init_p3(0, 1, 0), init_p3(0, 0, 1));
			object->i_t = i_transform(object->t);
			object->colour = init_rgb(ft_atoi(nums[5]), ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
			object->reflect = ft_atoi(nums[8]);
			object->intersect = intersect_plane;
			object->light_funk = plane_light;
			object->next = scene->objects;
			scene->objects = object;
		}
		else if (!ft_strcmp(nums[0], "cone"))
		{
			object = (t_object*)malloc(sizeof(t_object));
			object->type = T_CONE;
			object->data = return_cone(nums);
			object->pos = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
			object->t = init_transform(init_p3(1, 0, 0), init_p3(0, 1, 0), init_p3(0, 0, 1));
			object->i_t = i_transform(object->t);
			object->colour = init_rgb(ft_atoi(nums[6]), ft_atoi(nums[7]), ft_atoi(nums[8]), 255);
			object->reflect = ft_atoi(nums[9]);
			object->intersect = intersect_cone;
			object->light_funk = cone_light;
			object->next = scene->objects;
			scene->objects = object;
		}
		else if (!ft_strcmp(nums[0], "cylinder"))
		{
			object = (t_object*)malloc(sizeof(t_object));
			object->type = T_CYLINDER;
			object->data = return_cylinder(nums);
			object->pos = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
			object->t = init_transform(init_p3(1, 0, 0), init_p3(0, 1, 0), init_p3(0, 0, 1));
			object->i_t = i_transform(object->t);
			object->colour = init_rgb(ft_atoi(nums[5]), ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
			object->reflect = ft_atoi(nums[8]);
			object->intersect = intersect_cylinder;
			object->light_funk = cylinder_light;
			object->next = scene->objects;
			scene->objects = object;
		}
		else if (!ft_strcmp(nums[0], "dot_source"))
		{
			light = (t_light*)malloc(sizeof(t_light));
			light->type = L_DOT;
			light->data = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
			light->i = ft_atoi(nums[4]) / 10.0;
			light->next = scene->lights;
			scene->lights = light;
		}
		else if (!ft_strcmp(nums[0], "dir_source"))
		{
			light = (t_light*)malloc(sizeof(t_light));
			light->type = L_DIR;
			light->data = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
			light->i = ft_atoi(nums[4]) / 10.0;
			light->next = scene->lights;
			scene->lights = light;
		}
		free_nums(nums);
		free(str);
	}
}

t_scene		read_scene(char *fname)
{
	t_scene	scene;
	int		fd;

	fd = open(fname, O_RDWR);
	scene.camera = init_camera(init_p3(0, 0, 0), init_p3(1, 0, 0), init_p3(0, 1, 0), init_p3(0, 0, 1));
	scene.objects = NULL;
	scene.lights = NULL;
	scene.chosen = NULL;
	read_obj(fd, &scene);
	return (scene);
}
