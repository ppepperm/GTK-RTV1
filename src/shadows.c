/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 11:03:10 by ppepperm          #+#    #+#             */
/*   Updated: 2021/03/10 03:55:10 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int				dir_shadow(t_object *objects, t_light light, t_p3 inter)
{
	t_ray		shadow_ray;
	t_p2		roots;

	shadow_ray.pos = inter;
	shadow_ray.dir = lin_comb(light.data, -1, init_p3(0, 0, 0), 0);
	while (objects)
	{
		roots = objects->intersect(shadow_ray, *(objects));
		if (roots.x > 0.0001 || roots.y > 0.0001)
			return (1);
		objects = objects->next;
	}
	return (0);
}

int				dot_shadow(t_object *objects, t_light light, t_p3 inter)
{
	t_ray		shadow_ray;
	t_p2		roots;

	shadow_ray.pos = light.data;
	shadow_ray.dir = lin_comb(inter, 1, light.data, -1);
	while (objects)
	{
		roots = objects->intersect(shadow_ray, *(objects));
		if ((roots.x > 0.0001 && roots.x < 0.9999)\
			|| (roots.y > 0.0001 && roots.y < 0.9999))
			return (1);
		objects = objects->next;
	}
	return (0);
}

int				check_shadow(t_object *objects, t_light light, t_p3 inter)
{
	if (light.type == L_DIR)
	{
		if (dir_shadow(objects, light, inter))
			return (1);
	}
	else if (light.type == L_DOT)
	{
		if (dot_shadow(objects, light, inter))
			return (1);
	}
	return (0);
}

static int		ft_kost(int mult)
{
	if (mult < 0)
		return (0);
	return (-1);
}

int				ft_atoip(const char *str)
{
	long long	mult;
	long long	nb;

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
