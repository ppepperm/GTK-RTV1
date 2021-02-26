/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:57:58 by ppepperm          #+#    #+#             */
/*   Updated: 2021/02/26 14:10:29 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	ft_kost(int mult)
{
	if (mult < 0)
		return (0);
	return (-1);
}

int			ft_atoip(const char *str)
{
	long long mult;
	long long nb;

	mult = 1;
	nb = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\v') || (*str == '\f')\
			|| (*str == '\r') || (*str == '\n') || (((*str < '0') || (*str > '9')) && (*str != '-')))
		str++;
	if (*str == '-')
	{
		str++;
		mult = -1;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if ((*str < '0') || (*str > '9'))
			return (nb * mult);
		if (nb > nb * 10 + (*str - '0') && nb != 214748364)
			return (ft_kost(mult));
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return ((int)(nb * mult));
}

int	push_sphere(t_scene *scene, char **nums)
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
	object->intersect = intersect_sphere;
	object->light_funk = sphere_light;
	object->norm_funk = sphere_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int	push_plane(t_scene *scene, char **nums)
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
	object->intersect = intersect_plane;
	object->light_funk = plane_light;
	object->norm_funk = plane_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int	push_cone(t_scene *scene, char **nums)
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
	object->intersect = intersect_cone;
	object->light_funk = cone_light;
	object->norm_funk = cone_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int	push_cylinder(t_scene *scene, char **nums)
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
	object->intersect = intersect_cylinder;
	object->light_funk = cylinder_light;
	object->norm_funk = cylinder_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}
