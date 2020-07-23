/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:24:39 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/23 16:24:40 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		*return_sphere(char **nums)
{
	t_sphere *sphere;

	sphere = (t_sphere*)malloc(sizeof(t_sphere));
	sphere->pos = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
	sphere->r = ft_atoi(nums[4]);
	return ((void*)sphere);
}

void		*return_plane(char **nums)
{
	t_plane *plane;

	plane = (t_plane*)malloc(sizeof(t_plane));
	plane->dir = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
	plane->d = ft_atoi(nums[4]);
	return ((void*)plane);
}

void		*return_cone(char **nums)
{
	t_cone *cone;

	cone = (t_cone*)malloc(sizeof(t_cone));
	cone->pos = init_p3(ft_atoi(nums[1]), ft_atoi(nums[2]), ft_atoi(nums[3]));
	cone->r = ft_atoi(nums[4]);
	cone->c = ft_atoi(nums[5]);
	return ((void*)cone);
}

void		*return_cylinder(char **nums)
{
	t_cylinder *cylinder;

	cylinder = (t_cylinder*)malloc(sizeof(t_cylinder));
	cylinder->pos = init_p3(ft_atoi(nums[1]),\
	ft_atoi(nums[2]), ft_atoi(nums[3]));
	cylinder->r = ft_atoi(nums[4]);
	return ((void*)cylinder);
}