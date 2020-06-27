/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:05:18 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/25 21:05:21 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	read_obj(int fd, t_scene *scene)
{
	t_object	*object;
	char 		*str;
	char 		**nums;

	while (get_next_line(fd, &str))
	{
		object = (t_object*)malloc(sizeof(t_object));
		nums = ft_strsplit(str, ';');
		if(!ft_strcmp(nums[0], "sphere"))
		{
			object->type = T_SPHERE;
			object->data = return_sphere(nums);
			object->colour = init_rgb(ft_atoi(nums[5]), ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
		}
		else if(!ft_strcmp(nums[0], "plane"))
		{
			object->type = T_PLANE;
			object->data = return_plane(nums);
			object->colour = init_rgb(ft_atoi(nums[5]), ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
		}
		object->next = scene->objects;
		scene->objects = object;
		free_nums(nums);
		free(str);
	}
}

t_scene		read_scene(char *fname)
{
	t_scene scene;
	int fd;

	fd = open(fname, O_RDWR);
	scene.camera = init_camera(init_p3(0, 0, 0), init_p3(1, 0, 0), init_p3(0, 1, 0), init_p3(0, 0, 1));
	scene.objects = NULL;
	read_obj(fd, &scene);
	return scene;
}
