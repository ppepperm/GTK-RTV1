/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:09:20 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/27 17:09:22 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	free_nums(char **nums)
{
	int i;

	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	free_scene(t_scene *scene)
{
	t_object	*o_ptr;
	t_light		*l_ptr;

	scene->chosen = NULL;
	while (scene->objects)
	{
		free(scene->objects->data);
		o_ptr = scene->objects->next;
		free(scene->objects);
		scene->objects = o_ptr;
	}
	while (scene->lights)
	{
		l_ptr = scene->lights->next;
		free(scene->lights);
		scene->lights = l_ptr;
	}
}

void	end_sdl(t_sdl_sequence sq)
{
	SDL_DestroyTexture(sq.win_tex);
	SDL_DestroyRenderer(sq.renderer);
	SDL_DestroyWindow(sq.window);
	SDL_Quit();
}
