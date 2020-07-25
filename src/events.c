/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:07:55 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/25 12:07:57 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		init_sdl_sequence(t_sdl_sequence *sq)
{
	sq->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,\
	SDL_WINDOWPOS_UNDEFINED, W_W, W_H, SDL_WINDOW_SHOWN);
	sq->renderer = SDL_CreateRenderer(sq->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(sq->renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(sq->renderer);
	sq->win_tex = SDL_CreateTexture(sq->renderer,\
	SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, W_W, W_H);
}

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
