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

void	read_obj(int fd, t_scene *scene)
{
	t_object	*object;
	char 		*str;
	char 		**nums
	t_sphere	*sphere;

	while (get_next_line(fd, &str))
	{
		object = (t_object*)malloc(sizeof(t_object));
		nums = ft_strsplit(str, ';');
		if(!ft_strcmp(nums[0], "sphere"))
		{
			object->type = T_SPHERE;
			sphere = (t_sphere*)malloc(sizeof(t_sphere));
			sphere->pos = init_p3(ft_atoi(nums[1]), ft_atoi(nums[3]), ft_atoi(nums[3]));
			sphere->r = ft_atoi(nums[4]);
			object->data = (void*)sphere;
			object->colour = init_rgb(ft_atoi(nums[5]), ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
			free(sphere);
			free(nums[0]);
			free(nums[1]);
			free(nums[2]);
			free(nums[3]);
			free(nums[4]);
			free(nums[5]);
			free(nums[6]);
			free(nums[7]);
			free(nums);
		}
		object->next = scene->objects;
		scene->objects = object;
	}
}

t_scene		read_scene(char *fname)
{
	t_scene scene;
	int fd

	fd = open(fname, O_RDWR);
	scene.camera = camera = init_camera(init_p3(0, 0, 0), init_p3(1, 0, 0), init_p3(0, 1, 0), init_p3(0, 0, 1));
	scene.objects = NULL;
	read_obj(fd, &scene);
	return scene;
}
