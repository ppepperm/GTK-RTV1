/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:11:10 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/22 13:11:12 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void draw_to_texture(t_scene scene, SDL_Texture *win_tex)
{
	unsigned char	*win_buff;
	void			*tmp;
	int 			pitch;

	SDL_LockTexture(win_tex, NULL, &tmp, &pitch);
	win_buff = (unsigned char *)tmp;
	draw_scene(scene, win_buff, pitch);
	SDL_UnlockTexture(win_tex);
}

int main( void)
{
	SDL_Window      *window = NULL;
	SDL_Event       event;
	SDL_Renderer    *renderer;
	SDL_Texture     *win_tex;
	t_scene			scene;
	t_i2            mouse;

	SDL_Init( SDL_INIT_VIDEO );
	window = SDL_CreateWindow( "RTv1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W_W, W_H, SDL_WINDOW_SHOWN );
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(renderer);
	win_tex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, W_W, W_H);
	scene = read_scene("scene");
	draw_to_texture(scene, win_tex);
	while (!(SDL_PollEvent(&event) && event.type == SDL_QUIT))
	{
		if (event.type == SDL_KEYDOWN)
		{
		    if (!(scene.chosen))
			    camera_control(event, &scene);
		    else
                object_control(event, scene, scene.chosen);
            draw_to_texture(scene, win_tex);
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_GetMouseState( &mouse.x, &mouse.y);
            scene.chosen = return_chosen(scene, mouse.x, mouse.y);
            draw_to_texture(scene, win_tex);
        }
		SDL_RenderCopy(renderer, win_tex, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow( window );
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}