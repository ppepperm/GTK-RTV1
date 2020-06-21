/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:27:33 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/21 21:27:35 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_p2	init_p2(double x, double y)
{
	t_p2 ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_p3	init_p3(double x, double y, double z)
{
	t_p3 ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_ray	init_ra