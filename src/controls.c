/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:31:57 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/15 15:32:01 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	camera_control(SDL_Event event, t_scene *scene)
{
	camera_movement(event, scene);
	camera_rotation(event, scene);
	if (event.key.keysym.scancode == SDL_SCANCODE_Q)
	{
		scene->camera.x_dir = rotate(scene->camera.x_dir,\
		scene->camera.z_dir, 2);
		scene->camera.y_dir = rotate(scene->camera.y_dir,\
		scene->camera.z_dir, 2);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_E)
	{
		scene->camera.x_dir = rotate(scene->camera.x_dir,\
		scene->camera.z_dir, -2);
		scene->camera.y_dir = rotate(scene->camera.y_dir,\
		scene->camera.z_dir, -2);
	}
}

void	object_control(SDL_Event event, t_scene *scene, t_object *object)
{
	object_movement(event, scene, scene->chosen);
	object_rotation(event, scene, scene->chosen);
	if (event.key.keysym.scancode == SDL_SCANCODE_E)
	{
		object->t.x_dir = rotate(object->t.x_dir, scene->camera.z_dir, -2);
		object->t.y_dir = rotate(object->t.y_dir, scene->camera.z_dir, -2);
		object->t.z_dir = rotate(object->t.z_dir, scene->camera.z_dir, -2);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_Q)
	{
		object->t.x_dir = rotate(object->t.x_dir, scene->camera.z_dir, 2);
		object->t.y_dir = rotate(object->t.y_dir, scene->camera.z_dir, 2);
		object->t.z_dir = rotate(object->t.z_dir, scene->camera.z_dir, 2);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_F)
	{
		scene->chosen = NULL;
		return ;
	}
	object->i_t = i_transform(object->t);
}
