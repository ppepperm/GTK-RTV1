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

void		draw_to_texture(t_scene scene, SDL_Texture *win_tex)
{
	unsigned char	*win_buff;
	void			*tmp;
	int				pitch;

	SDL_LockTexture(win_tex, NULL, &tmp, &pitch);
	win_buff = (unsigned char *)tmp;
	draw_scene(scene, win_buff, pitch);
	SDL_UnlockTexture(win_tex);
}

int			main(int argc, char **argv)
{
	t_sdl_sequence	sq;
	t_scene			scene;

	if (argc != 2)
		ft_error(NULL);
	validation(argv[1]);
	scene = read_scene(argv[1]);
	SDL_Init(SDL_INIT_VIDEO);
	init_sdl_sequence(&sq);
	draw_to_texture(scene, sq.win_tex);
	while (!(SDL_PollEvent(&(sq.event)) && sq.event.type == SDL_QUIT))
	{
		if (!control(sq.event, &scene, sq.win_tex))
			break ;
		SDL_RenderCopy(sq.renderer, sq.win_tex, NULL, NULL);
		SDL_RenderPresent(sq.renderer);
	}
	free_scene(&scene);
	end_sdl(sq);
	return (0);
}
