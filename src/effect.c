/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:22:54 by ppepperm          #+#    #+#             */
/*   Updated: 2021/02/18 15:22:56 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_rgb	sphere_ch(t_p3 inter)
{
	double	alpha;
	double	beta;

	normalize(&inter);
	alpha = acos(inter.x);
	beta = atan2(inter.y, inter.z);
	if (beta < 0)
		beta += 3.14;
	alpha = alpha * 10 / 3.14;
	beta = beta * 10 / 3.14;
	if ((int)alpha % 2 == (int)beta % 2)
		return (init_rgb(250, 0, 0, 255));
	else
		return (init_rgb(255, 255, 255, 255));
}

static t_rgb	plane_ch(t_p3 inter)
{
	double	alpha;
	double	beta;

	alpha = inter.x;
	beta = inter.z;
	beta = beta / 5;
	alpha = alpha / 5;
	if (beta < 0)
		beta = beta * -1 + 1;
	if (alpha < 0)
		beta = beta * -1 + 1;
	if ((int)alpha % 2 == (int)beta % 2)
		return (init_rgb(250, 0, 0, 255));
	else
		return (init_rgb(255, 255, 255, 255));
}

static t_rgb	cone_ch(t_p3 inter)
{
	double	alpha;
	double	beta;

	beta = inter.y;
	normalize(&inter);
	alpha = acos(inter.x);
	alpha = alpha * 20 / 3.14;
	beta = beta / 5;
	if (beta < 0)
		beta *= -1;
	if ((int)alpha % 2 == (int)beta % 2)
		return (init_rgb(250, 0, 0, 255));
	else
		return (init_rgb(255, 255, 255, 255));
}

static t_rgb	cylinder_ch(t_p3 inter)
{
	double	beta;

	beta = inter.y;
	beta = beta / 5;
	if (beta < 0)
		beta = beta * -1 + 1;
	if ((int)beta % 2 == 1)
		return (init_rgb(250, 0, 0, 255));
	else
		return (init_rgb(255, 255, 255, 255));
}

t_rgb			checkers(t_object *current, double root, t_ray ray)
{
	t_p3	inter;

	inter = lin_comb(ray.pos, 1, ray.dir, root);
	inter = transform_pos(inter, current->i_t, current->pos);
	if (current->type == T_SPHERE)
		return (sphere_ch(inter));
	else if (current->type == T_CONE || current->type == T_HYPERBOLOID)
		return (cone_ch(inter));
	else if (current->type == T_PLANE)
		return (plane_ch(inter));
	else if (current->type == T_CYLINDER)
		return (cylinder_ch(inter));
	return (init_rgb(0, 0, 255, 255));
}
