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

	ret.x = k1*a.x + k2*a.x;
	ret.x = k1*a.y + k2*a.y;
	ret.x = k1*a.z + k2*a.z;
	return (ret);
}

double	sc_mult(t_p3 a, t_p3 b)
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}