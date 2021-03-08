/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: out-belov1-mv <out-belov1-mv@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:35:38 by out-belov1-       #+#    #+#             */
/*   Updated: 2021/03/06 13:40:32 by out-belov1-      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		camera_movement(SDL_Event event, t_scene *s)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_W)
		s->camera.pos = lin_comb(s->camera.pos, 1, s->camera.z_dir, 1);
	else if (event.key.keysym.scancode == SDL_SCANCODE_S)
		s->camera.pos = lin_comb(s->camera.pos, 1, s->camera.z_dir, -1);
	else if (event.key.keysym.scancode == SDL_SCANCODE_A)
		s->camera.pos = lin_comb(s->camera.pos, 1, s->camera.x_dir, -1);
	else if (event.key.keysym.scancode == SDL_SCANCODE_D)
		s->camera.pos = lin_comb(s->camera.pos, 1, s->camera.x_dir, 1);
	else if (event.key.keysym.scancode == SDL_SCANCODE_LCTRL)
		s->camera.pos = lin_comb(s->camera.pos, 1, s->camera.y_dir, -1);
	else if (event.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
		s->camera.pos = lin_comb(s->camera.pos, 1, s->camera.y_dir, 1);
}

void		camera_rotation(SDL_Event event, t_scene *s)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
	{
		s->camera.x_dir = rotate(s->camera.x_dir, s->camera.y_dir, -2);
		s->camera.z_dir = rotate(s->camera.z_dir, s->camera.y_dir, -2);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
	{
		s->camera.x_dir = rotate(s->camera.x_dir, s->camera.y_dir, 2);
		s->camera.z_dir = rotate(s->camera.z_dir, s->camera.y_dir, 2);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_UP)
	{
		s->camera.y_dir = rotate(s->camera.y_dir, s->camera.x_dir, -2);
		s->camera.z_dir = rotate(s->camera.z_dir, s->camera.x_dir, -2);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
	{
		s->camera.y_dir = rotate(s->camera.y_dir, s->camera.x_dir, 2);
		s->camera.z_dir = rotate(s->camera.z_dir, s->camera.x_dir, 2);
	}
}

void		object_movement(SDL_Event event, t_scene *s, t_object *object)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_W)
		object->pos = lin_comb(object->pos, 1, s->camera.z_dir, 1);
	else if (event.key.keysym.scancode == SDL_SCANCODE_S)
		object->pos = lin_comb(object->pos, 1, s->camera.z_dir, -1);
	else if (event.key.keysym.scancode == SDL_SCANCODE_A)
		object->pos = lin_comb(object->pos, 1, s->camera.x_dir, -1);
	else if (event.key.keysym.scancode == SDL_SCANCODE_D)
		object->pos = lin_comb(object->pos, 1, s->camera.x_dir, 1);
	else if (event.key.keysym.scancode == SDL_SCANCODE_LCTRL)
		object->pos = lin_comb(object->pos, 1, s->camera.y_dir, -1);
	else if (event.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
		object->pos = lin_comb(object->pos, 1, s->camera.y_dir, 1);
}

void		object_rotation(SDL_Event event, t_scene *s, t_object *object)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
	{
		object->t.x_dir = rotate(object->t.x_dir, s->camera.y_dir, 2);
		object->t.y_dir = rotate(object->t.y_dir, s->camera.y_dir, 2);
		object->t.z_dir = rotate(object->t.z_dir, s->camera.y_dir, 2);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
	{
		object->t.x_dir = rotate(object->t.x_dir, s->camera.y_dir, -2);
		object->t.y_dir = rotate(object->t.y_dir, s->camera.y_dir, -2);
		object->t.z_dir = rotate(object->t.z_dir, s->camera.y_dir, -2);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
	{
		object->t.x_dir = rotate(object->t.x_dir, s->camera.x_dir, -2);
		object->t.y_dir = rotate(object->t.y_dir, s->camera.x_dir, -2);
		object->t.z_dir = rotate(object->t.z_dir, s->camera.x_dir, -2);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_UP)
	{
		object->t.x_dir = rotate(object->t.x_dir, s->camera.x_dir, 2);
		object->t.y_dir = rotate(object->t.y_dir, s->camera.x_dir, 2);
		object->t.z_dir = rotate(object->t.z_dir, s->camera.x_dir, 2);
	}
}

void		object_shrink(SDL_Event event, t_object *object)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_I)
		object->t.y_dir = lin_comb(object->t.y_dir, 1.1, init_p3(0, 0, 0), 0);
	else if (event.key.keysym.scancode == SDL_SCANCODE_K)
		object->t.y_dir = lin_comb(object->t.y_dir,\
			1 / 1.1, init_p3(0, 0, 0), 0);
	else if (event.key.keysym.scancode == SDL_SCANCODE_L)
		object->t.x_dir = lin_comb(object->t.x_dir, 1.1, init_p3(0, 0, 0), 0);
	else if (event.key.keysym.scancode == SDL_SCANCODE_J)
		object->t.x_dir = lin_comb(object->t.x_dir,\
			1 / 1.1, init_p3(0, 0, 0), 0);
	else if (event.key.keysym.scancode == SDL_SCANCODE_O)
		object->t.z_dir = lin_comb(object->t.z_dir, 1.1, init_p3(0, 0, 0), 0);
	else if (event.key.keysym.scancode == SDL_SCANCODE_U)
		object->t.z_dir = lin_comb(object->t.z_dir,\
			1 / 1.1, init_p3(0, 0, 0), 0);
}
