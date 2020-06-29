/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qaternion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:41:28 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/29 21:42:06 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_q init_rotor(t_p3 axis, double angle)
{
	t_q rotor;

	angle = angle * 0.0174533;
	normalize(&axis);
	rotor.s = cos(angle);
	rotor.i = axis.x * sin(angle);
	rotor.j = axis.y * sin(angle);
	rotor.k = axis.z * sin(angle);
	return (rotor);
}

t_q q_inverse(t_q base)
{
	t_q inverse;

	inverse.s = base.s;
	inverse.i = -base.i;
	inverse.j = -base.j;
	inverse.k = -base.k;
	return (inverse);
}

t_q q_multiply(t_q q, t_q p)
{
	t_q result;

	result.s = q.s * p.s -q.i * p.i - q.j * p.j - q.k * p.k;
	result.i = q.s * p.i + q.i * p.s + q.j * p.k - q.k * p.j;
	result.j = q.s * p.j + q.j * p.s - q.i * p.k + q.k * p.i;
	result.k = q.s * p.k + q.k * p.s + q.i * p.j - q.j * p.i;
	return result;
}

t_p3	rotate(t_p3 dot, t_p3 axis, double angle)
{
	t_p3	ret;
	t_q 	q_dot;
	t_q		rot;

	rot = init_rotor(axis, angle);
	q_dot = init_q(0, dot.x, dot.y, dot.z);
	q_dot = q_multiply(rot, q_dot);
	q_dot = q_multiply(q_dot, q_inverse(rot));
	ret = init_p3(q_dot.i, q_dot.j, q_dot.k);
	return (ret);
}