/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 20:03:52 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/13 20:03:53 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_p3	init_p3(double x, double y, double z)
{
	t_p3 ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_p2	init_p2(double x, double y)
{
	t_p2 ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_i2	init_i2(int x, int y)
{
	t_i2 ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_sphere init_sphere(t_p3 pos, double r)
{
	t_sphere ret;

	ret.pos = pos;
	ret.r = r;
	return (ret);
}

t_camera init_camera(t_p3 pos, t_p3 dir)
{
	t_camera ret;

	ret.pos = pos;
	ret.dir = dir;
	return (ret);
}