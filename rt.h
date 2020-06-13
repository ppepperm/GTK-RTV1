/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 19:36:24 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/13 19:36:27 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
#define RT_H
#define W_H 800
#define W_W 800
#define C_Z 1.0

#include <gtk/gtk.h>
#include "libft/includes/libft.h"

typedef struct		s_p2
{
	double			x;
	double			y;
}					t_p2;

typedef struct		s_p3
{
	double			x;
	double			y;
	double			z;
}					t_p3;

typedef struct		s_i2
{
	int				x;
	int				y;
}					t_i2;

typedef struct		s_sphere
{
	t_p3 pos;
	double r;
}					t_sphere;

typedef struct		s_camera
{
	t_p3 pos;
	t_p3 dir;
}					t_camera;

void put_pixel(cairo_t *cr, double x, double y);

t_p3	init_p3(double x, double y, double z);
t_p2	init_p2(double x, double y);
t_i2	init_i2(int x, int y);
t_sphere init_sphere(t_p3 pos, double r);
t_camera init_camera(t_p3 pos, t_p3 dir);

#endif