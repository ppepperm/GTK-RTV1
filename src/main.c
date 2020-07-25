/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:11:29 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/23 13:12:19 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	draw_to_texture(t_scene scene, SDL_Texture *win_tex)
{
	unsigned char	*win_buff;
	void			*tmp;
	int				pitch;

	SDL_LockTexture(win_tex, NULL, &tmp, &pitch);
	win_buff = (unsigned char *)tmp;
	draw_scene(scene, win_buff, pitch);
	SDL_UnlockTexture(win_tex);
}

int		main(void)
{
	t_sdl_sequence	sq;
	t_scene			scene;
	t_i2			mouse;

	SDL_Init(SDL_INIT_VIDEO);
	init_sdl_sequence(&sq);
	validation("scene");
	scene = read_scene("scene");
	draw_to_texture(scene, sq.win_tex);
	while (!(SDL_PollEvent(&(sq.event)) && sq.event.type == SDL_QUIT))
	{
		if (sq.event.type == SDL_KEYDOWN)
		{
			if (!(scene.chosen))
				camera_control(sq.event, &scene);
			else
				object_control(sq.event, &scene, scene.chosen);
			if (sq.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				break ;
			draw_to_texture(scene, sq.win_tex);
		}
		if (sq.event.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&mouse.x, &mouse.y);
			scene.chosen = return_chosen(scene, mouse.x, mouse.y);
			draw_to_texture(scene, sq.win_tex);
		}
		SDL_RenderCopy(sq.renderer, sq.win_tex, NULL, NULL);
		SDL_RenderPresent(sq.renderer);
	}
	//freee(scene)
	SDL_DestroyWindow(sq.window);
	SDL_DestroyRenderer(sq.renderer);
	SDL_Quit();
	return (0);
}
