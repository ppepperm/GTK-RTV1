/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:16:48 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/21 21:16:50 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_p3	lin_comb(t_p3 a, double k1, t_p3 b, double k2)
{
	t_p3 ret;

	ret.x = k1 * a.x + k2 * b.x;
	ret.y = k1 * a.y + k2 * b.y;
	ret.z = k1 * a.z + k2 * b.z;
	return (ret);
}

double	sc_mult(t_p3 a, t_p3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	min(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

void	normalize(t_p3 *vec)
{
	double abs;

	abs = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	vec->x /= abs;
	vec->y /= abs;
	vec->z /= abs;
}

t_p3	return_norm_cone(t_cone cone, t_p3 inter)
{
	t_p3	ret;
	double	y;

	ret = inter;
	y = sqrt(ret.x * ret.x + ret.z * ret.z);
	y = y * cone.r / cone.c;
	if (ret.y < 0)
		ret.y = y;
	else
		ret.y = -y;
	return (ret);
}
