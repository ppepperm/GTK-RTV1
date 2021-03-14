/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 05:06:31 by jabilbo           #+#    #+#             */
/*   Updated: 2021/03/13 17:54:17 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static bool	chek_chek(char **str, char *xyz, int num)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strstr(str[0], xyz);
	if (tmp == NULL)
		return (false);
	while (i < num)
	{
		if (!str[i + 1])
		{
			printf("malo\n");
			return (false);
		}
		i++;
	}
	if (str[i + 1])
	{
		printf("mnogo\n");
		return (false);
	}
	return (true);
}

static int	chek_obj(char *str, t_scene *scene)
{
	int		error;
	char	**nums;

	error = 1;
	nums = ft_strsplit(str, ',');
	if (chek_chek(nums, "sphere", 9))
		error &= push_sphere(scene, nums);
	else if (chek_chek(nums, "plane", 8))
		error &= push_plane(scene, nums);
	else if (chek_chek(nums, "cone", 9))
		error &= push_cone(scene, nums);
	else if (chek_chek(nums, "cylinder", 8))
		error &= push_cylinder(scene, nums);
	else if (chek_chek(nums, "hyperboloid", 9))
		error &= push_hyperboloid(scene, nums);
	else if (chek_chek(nums, "dot_source", 3))
		error &= push_dot(scene, nums);
	else if (chek_chek(nums, "dir_source", 3))
		error &= push_dir(scene, nums);
	if (!error)
		read_malloc_exit(scene);
	free_nums(nums);
	return (error);
}

static void	bespolezno(char **nums, t_scene *scene)
{
	int		i;

	i = 0;
	while (nums[i])
	{
		chek_obj(nums[i], scene);
		i++;
	}
}

static void	read_obj(int fd, t_scene *scene)
{
	char	*str;
	char	**nums;
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	tmp = (char*)malloc(sizeof(char));
	*tmp = ';';
	while (get_next_line(fd, &str))
	{
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, str);
		if (tmp2)
			free(tmp2);
		if (str)
			free(str);
	}
	nums = ft_strsplit(tmp, ';');
	bespolezno(nums, scene);
	free_nums(nums);
	free(tmp);
}

t_scene		read_scene(char *fname)
{
	t_scene	scene;
	int		fd;

	fd = open(fname, O_RDWR);
	if (fd < 0)
		exit(0);
	scene.camera = init_camera(init_p3(0, 0, 0),\
	init_p3(1, 0, 0), init_p3(0, 1, 0), init_p3(0, 0, 1));
	scene.objects = NULL;
	scene.lights = NULL;
	scene.chosen = NULL;
	scene.effect = 0;
	read_obj(fd, &scene);
	remember_head(scene);
	return (scene);
}
