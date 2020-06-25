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
	int				i, j;
	t_sphere		sphere;
	t_camera		camera;
	t_ray			ray;
	t_p2			roots;

	SDL_Init( SDL_INIT_VIDEO );
	window = SDL_CreateWindow( "RTv1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W_W, W_H, SDL_WINDOW_SHOWN );
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0xff, 0xff, 0xff);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	win_tex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, W_W, W_H);

	camera = init_camera(init_p3(0, 0, 0), init_p3(1, 0, 0), init_p3(0, 1, 0), init_p3(0, 0, 1));
	sphere = init_sphere(init_p3(2, 1 , 15), 1);
	SDL_LockTexture(win_tex, NULL, &tmp, &pitch);
	win_buff = (unsigned char *)tmp;
	i = 0;
	while(i < W_W)
	{
		j = 0;
		while (j < W_H)
		{
			ray = get_ray(camera, i - W_W/2, W_H/2 - j);
			roots = ray_trace(ray, sphere);
			roots = roots;
			if (roots.x >= 0 && roots.y >= 0)
			{
				win_buff[i * 4 + 0 + j * pitch] = 0xff;
				win_buff[i * 4 + 1 + j * pitch] = 0x0;
				win_buff[i * 4 + 2 + j * pitch] = 0x0;
				win_buff[i * 4 + 3 + j * pitch] = 0xff;
			}
			else
			{
				win_buff[i * 4 + 0 + j * pitch] = 0xff;
				win_buff[i * 4 + 1 + j * pitch] = 0xff;
				win_buff[i * 4 + 2 + j * pitch] = 0xff;
				win_buff[i * 4 + 3 + j * pitch] = 0xff;
			}
			j++;
		}
		i++;
	}
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