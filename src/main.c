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

int main( void)
{
	SDL_Window* window = NULL;
	SDL_Event	event;
	SDL_Renderer* renderer;
	SDL_Texture *win_tex;
	unsigned char	*win_buff;
	void			*tmp;
	int 			pitch;
	//t_sphere		*iter_s;
	t_scene			scene;

	SDL_Init( SDL_INIT_VIDEO );
	window = SDL_CreateWindow( "RTv1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W_W, W_H, SDL_WINDOW_SHOWN );
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	win_tex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, W_W, W_H);

	scene = read_scene("scene");
	/*while (scene.objects)
	{
		if (scene.objects->type == T_SPHERE)
		{
			iter_s = (t_sphere*)scene.objects->data;
			printf("%f %f %f %f %d %d %d\n", iter_s->pos.x, iter_s->pos.y, iter_s->pos.z, iter_s->r, (int)scene.objects->colour.r,
				   (int)scene.objects->colour.g, (int)scene.objects->colour.b);

		}
		scene.objects = scene.objects->next;
	}*/

	SDL_LockTexture(win_tex, NULL, &tmp, &pitch);
	win_buff = (unsigned char *)tmp;
	draw_scene(scene, win_buff, pitch);
	SDL_UnlockTexture(win_tex);

	while (!(SDL_PollEvent(&event) && event.type == SDL_QUIT))
	{
		SDL_RenderCopy(renderer, win_tex, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow( window );
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}