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
	char		*str;
	char		**nums;

	while (get_next_line(fd, &str))
	{
		nums = ft_strsplit(str, ';');
		if (!ft_strcmp(nums[0], "sphere"))
			push_sphere(scene, nums);
		else if (!ft_strcmp(nums[0], "plane"))
			push_plane(scene, nums);
		else if (!ft_strcmp(nums[0], "cone"))
			push_cone(scene, nums);
		else if (!ft_strcmp(nums[0], "cylinder"))
			push_cylinder(scene, nums);
		else if (!ft_strcmp(nums[0], "dot_source"))
			push_dot(scene, nums);
		else if (!ft_strcmp(nums[0], "dir_source"))
			push_dir(scene, nums);
		free_nums(nums);
		free(str);
	}
}

t_scene		read_scene(char *fname)
{
	t_scene	scene;
	int		fd;

	fd = open(fname, O_RDWR);
	scene.camera = init_camera(init_p3(0, 0, 0),\
	init_p3(1, 0, 0), init_p3(0, 1, 0), init_p3(0, 0, 1));
	scene.objects = NULL;
	scene.lights = NULL;
	scene.chosen = NULL;
	read_obj(fd, &scene);
	return (scene);
}
