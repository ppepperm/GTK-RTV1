/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:48:31 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/05 15:48:33 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void    camera_control(SDL_Event event, t_scene *scene)
{
    if (event.key.keysym.scancode == SDL_SCANCODE_W)
        scene->camera.pos = lin_comb(scene->camera.pos, 1, scene->camera.z_dir, 1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_S)
        scene->camera.pos = lin_comb(scene->camera.pos, 1, scene->camera.z_dir, -1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_A)
        scene->camera.pos = lin_comb(scene->camera.pos, 1, scene->camera.x_dir, -1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_D)
        scene->camera.pos = lin_comb(scene->camera.pos, 1, scene->camera.x_dir, 1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_LCTRL)
        scene->camera.pos = lin_comb(scene->camera.pos, 1, scene->camera.y_dir, -1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
        scene->camera.pos = lin_comb(scene->camera.pos, 1, scene->camera.y_dir, 1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
    {
        scene->camera.x_dir = rotate(scene->camera.x_dir, scene->camera.y_dir, -2);
        scene->camera.z_dir = rotate(scene->camera.z_dir, scene->camera.y_dir, -2);
    }
    else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
    {
        scene->camera.x_dir = rotate(scene->camera.x_dir, scene->camera.y_dir, 2);
        scene->camera.z_dir = rotate(scene->camera.z_dir, scene->camera.y_dir, 2);
    }
    else if (event.key.keysym.scancode == SDL_SCANCODE_UP)
    {
        scene->camera.y_dir = rotate(scene->camera.y_dir, scene->camera.x_dir, -2);
        scene->camera.z_dir = rotate(scene->camera.z_dir, scene->camera.x_dir, -2);
    }
    else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
    {
        scene->camera.y_dir = rotate(scene->camera.y_dir, scene->camera.x_dir, 2);
        scene->camera.z_dir = rotate(scene->camera.z_dir, scene->camera.x_dir, 2);
    }
    else if (event.key.keysym.scancode == SDL_SCANCODE_Q)
    {
        scene->camera.x_dir = rotate(scene->camera.x_dir, scene->camera.z_dir, 2);
        scene->camera.y_dir = rotate(scene->camera.y_dir, scene->camera.z_dir, 2);
    }
    else if (event.key.keysym.scancode == SDL_SCANCODE_E)
    {
        scene->camera.x_dir = rotate(scene->camera.x_dir, scene->camera.z_dir, -2);
        scene->camera.y_dir = rotate(scene->camera.y_dir, scene->camera.z_dir, -2);
    }
}

void    object_control(SDL_Event event, t_object *object)
{
    if (event.key.keysym.scancode == SDL_SCANCODE_W)
        object->pos = lin_comb(object->pos, 1, init_p3(0, 0, 1), 1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_S)
        object->pos = lin_comb(object->pos, 1, init_p3(0, 0, 1), -1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_A)
        object->pos = lin_comb(object->pos, 1, init_p3(1, 0, 0), -1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_D)
        object->pos = lin_comb(object->pos, 1, init_p3(1, 0, 0), 1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_LCTRL)
        object->pos = lin_comb(object->pos, 1, init_p3(0, 1, 0), -1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
        object->pos = lin_comb(object->pos, 1, init_p3(0, 1, 0), 1);
    else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
    {
        object->t.x_dir = rotate(object->t.x_dir, object->t.y_dir, -2);
        object->t.z_dir = rotate(object->t.z_dir, object->t.y_dir, -2);
    }
    else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
    {
        object->t.x_dir = rotate(object->t.x_dir, object->t.y_dir, 2);
        object->t.z_dir = rotate(object->t.z_dir, object->t.y_dir, 2);
    }
    else if (event.key.keysym.scancode == SDL_SCANCODE_UP)
    {
        object->t.y_dir = rotate(object->t.y_dir, object->t.x_dir, -2);
        object->t.z_dir = rotate(object->t.z_dir, object->t.x_dir, -2);
    }
    else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
    {
        object->t.y_dir = rotate(object->t.y_dir, object->t.x_dir, 2);
        object->t.z_dir = rotate(object->t.z_dir, object->t.x_dir, 2);
    }
    else if (event.key.keysym.scancode == SDL_SCANCODE_Q)
    {
        object->t.x_dir = rotate(object->t.x_dir, object->t.z_dir, 2);
        object->t.y_dir = rotate(object->t.y_dir, object->t.z_dir, 2);
    }
    else if (event.key.keysym.scancode == SDL_SCANCODE_E)
    {
        object->t.x_dir = rotate(object->t.x_dir, object->t.z_dir, -2);
        object->t.y_dir = rotate(object->t.y_dir, object->t.z_dir, -2);
    }
    object->i_t = i_transform(object->t);
}