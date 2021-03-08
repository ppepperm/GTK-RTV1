/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:13:03 by ppepperm          #+#    #+#             */
/*   Updated: 2021/02/28 18:19:59 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		inc_i(double cosa, t_light *lights, double *i, double pw)
{
	if (cosa < 0)
		cosa = 0;
	cosa = pow(cosa, pw);
	*i += cosa * lights->i;
}

t_rgb		colour_mult(t_rgb base, double k)
{
	double r;
	double g;
	double b;

	r = base.r * k;
	if (r > 255)
		r = 255;
	g = base.g * k;
	if (g > 255)
		g = 255;
	b = base.b * k;
	if (b > 255)
		b = 255;
	return (init_rgb((unsigned char)r,\
	(unsigned char)g, (unsigned char)b, 255));
}

void		prep_light(t_light *lights, t_p3 *light, t_light_arg arg)
{
	if (lights->type == L_DIR)
		*light = lights->data;
	else if (lights->type == L_DOT)
		*light = lin_comb(arg.inter, 1, lights->data, -1);
	normalize(light);
}

int			push_dot(t_scene *scene, char **nums)
{
	t_light *light;

	if (!(light = (t_light*)malloc(sizeof(t_light))))
		return (0);
	light->type = L_DOT;
	light->data = init_p3(ft_atoip(nums[0]),\
	ft_atoip(nums[1]), ft_atoip(nums[2]));
	light->i = ft_atoip(nums[3]) / 10.0;
	light->next = scene->lights;
	scene->lights = light;
	return (1);
}

int			push_dir(t_scene *scene, char **nums)
{
	t_light *light;

	if (!(light = (t_light*)malloc(sizeof(t_light))))
		return (0);
	light->type = L_DIR;
	light->data = init_p3(ft_atoip(nums[0]),\
	ft_atoip(nums[1]), ft_atoip(nums[2]));
	light->i = ft_atoip(nums[3]) / 10.0;
	light->next = scene->lights;
	scene->lights = light;
	return (1);
}
