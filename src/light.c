/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:51:28 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/03 14:51:29 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_rgb   colour_mult(t_rgb base, double k)
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
    return (init_rgb((unsigned char)r, (unsigned char)g, (unsigned char)b, 255));
}

double  get_light(t_scene scene, t_p3 inter, t_p3 norm)
{
    t_p3 light;
    double i;
    double cosa;

    i = 0;
    while (scene.lights)
    {
        if (scene.lights->type == L_DIR)
            light = scene.lights->data;
        else if(scene.lights->type == L_DOT)
            light = lin_comb(inter , 1, scene.lights->data, -1);
        normalize(&light);
        cosa = -sc_mult(norm, light);
        if (cosa <0)
            cosa = 0;
        i += cosa*scene.lights->i;
        scene.lights = scene.lights->next;
    }
    return i;
}

double  get_light_p(t_scene scene, t_p3 inter, t_p3 norm)
{
    t_p3 light;
    double i;
    double cosa;

    i = 0;
    while (scene.lights)
    {
        if (scene.lights->type == L_DIR)
            light = scene.lights->data;
        else if(scene.lights->type == L_DOT)
            light = lin_comb(inter , 1, scene.lights->data, -1);
        normalize(&light);
        cosa = -sc_mult(norm, light);
        if (cosa <0)
            cosa *= -1;
        i += cosa*scene.lights->i;
        scene.lights = scene.lights->next;
    }
    return i;
}