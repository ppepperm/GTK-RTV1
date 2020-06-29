/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:27:33 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/21 21:27:35 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_p2		init_p2(double x, double y)
{
	t_p2 ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_p3		init_p3(double x, double y, double z)
{
	t_p3 ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_q init_q(double s, double i, double j, double k)
{
	t_q ret;

	ret.s = s;
	ret.i = i;
	ret.j = j;
	ret.k = k;
	return ret;
}

t_ray		init_ray(t_p3 pos, t_p3 dir)
{
	t_ray ret;

	ret.dir = dir;
	ret.pos = pos;
	return (ret);
}

t_camera	init_camera(t_p3 pos, t_p3 x, t_p3 y, t_p3 z)
{
	t_camera camera;

	camera.pos = pos;
	camera.x_dir = x;
	camera.y_dir = y;
	camera.z_dir = z;
	return (camera);
}

t_sphere	init_sphere(t_p3 pos, double r)
{
	t_sphere ret;

	ret.pos = pos;
	ret.r = r;
	return (ret);
}

t_rgb		init_rgb(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	t_rgb ret;

	ret.r = r;
	ret.g = g;
	ret.b = b;
	ret.a = a;
	return (ret);
}

void *return_sphere(char** nums)
{
	t_sphere *sphere;

	sphere = (t_sphere*)malloc(sizeof(t_sphere));
	sphere->pos = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
	sphere->r = ft_atoi(nums[4]);
	return ((void*)sphere);
}

void *return_plane(char** nums)
{
	t_plane *plane;

	plane = (t_plane*)malloc(sizeof(t_plane));
	plane->dir = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
	plane->d = ft_atoi(nums[4]);
	return ((void*)plane);
}

void *return_cone(char** nums)
{
	t_cone *cone;

	cone = (t_cone*)malloc(sizeof(t_cone));
	cone->pos = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
	cone->r = ft_atoi(nums[4]);
	cone->c = ft_atoi(nums[5]);
	return ((void*)cone);
}

void *return_cylinder(char** nums)
{
	t_cylinder *cylinder;

	cylinder = (t_cylinder*)malloc(sizeof(t_cylinder));
	cylinder->pos = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
	cylinder->r = ft_atoi(nums[4]);
	return ((void*)cylinder);
}