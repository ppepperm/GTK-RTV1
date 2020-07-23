/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:13:03 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/23 17:13:05 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int	push_dot(t_scene *scene, char **nums)
{
	t_light *light;

	light = (t_light*)malloc(sizeof(t_light));
	light->type = L_DOT;
	light->data = init_p3(ft_atoi(nums[1]),\
	ft_atoi(nums[2]), ft_atoi(nums[3]));
	light->i = ft_atoi(nums[4]) / 10.0;
	light->next = scene->lights;
	scene->lights = light;
	return (1);
}

int	push_dir(t_scene *scene, char **nums)
{
	t_light *light;

	light = (t_light*)malloc(sizeof(t_light));
	light->type = L_DIR;
	light->data = init_p3(ft_atoi(nums[1]),\
	ft_atoi(nums[2]), ft_atoi(nums[3]));
	light->i = ft_atoi(nums[4]) / 10.0;
	light->next = scene->lights;
	scene->lights = light;
	return (1);
}
