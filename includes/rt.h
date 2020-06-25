/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:08:08 by ppepperm          #+#    #+#             */
/*   Updated: 2020/05/26 19:48:03 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/includes/libft.h"
# include "../SDL2/SDL.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define W_H		800.0
# define W_W		1000.0
# define V_W		1.0
# define V_H		0.8
# define C_Z		2.0

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

typedef struct		s_ray
{
	t_p3 pos;
	t_p3 dir;
}					t_ray;

typedef struct		s_sphere
{
	t_p3 pos;
	double r;
}					t_sphere;

typedef struct		s_camera
{
	t_p3 pos;
	t_p3 x_dir;
	t_p3 y_dir;
	t_p3 z_dir;
}					t_camera;

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_rgb;

t_p3	lin_comb(t_p3 a, double k1, t_p3 b, double k2);
double	sc_mult(t_p3 a, t_p3 b);

t_ray	get_ray(t_camera camera, double x, double y);
t_p2	ray_trace(t_ray ray, t_sphere sphere);

t_p2		init_p2(double x, double y);
t_p3		init_p3(double x, double y, double z);
t_ray		init_ray(t_p3 pos, t_p3 dir);
t_camera	init_camera(t_p3 pos, t_p3 x, t_p3 y, t_p3 z);
t_sphere	init_sphere(t_p3 pos, double r);
t_rgb		init_rgb(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

#endif
