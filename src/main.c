/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:21:36 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/03/13 18:21:36 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void				show_help_panel(t_sdl_sequence *sq)
{
	SDL_Rect		rect;
	TTF_Font		*fnt;
	SDL_Color		color;

	rect.x = 0;
	rect.y = W_H - 120;
	rect.w = (W_W);
	rect.h = W_H - rect.y;
	color.a = 255;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	SDL_SetRenderDrawColor(sq->renderer, 1, 23, 32, 255);
	TTF_Init();
	SDL_RenderFillRect(sq->renderer, &rect);
	fnt = TTF_OpenFont("Roboto-Regular.ttf", 18);
	show_text_help(sq, fnt, color);
	SDL_RenderPresent(sq->renderer);
	SDL_RenderPresent(sq->renderer);
	TTF_CloseFont(fnt);
	TTF_Quit();
}

int					init_sdl_sequence(t_sdl_sequence *sq)
{
	sq->window = NULL;
	sq->renderer = NULL;
	sq->win_tex = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (0);
	sq->window = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,\
	SDL_WINDOWPOS_UNDEFINED, W_W, W_H, SDL_WINDOW_SHOWN);
	sq->renderer = SDL_CreateRenderer(sq->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(sq->renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(sq->renderer);
	sq->win_tex = SDL_CreateTexture(sq->renderer,\
	SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, W_W, W_H);
	if (!sq->window || !sq->renderer || !sq->win_tex)
		return (0);
	return (1);
}

int					draw_to_texture(t_scene scene, SDL_Texture *win_tex)
{
	unsigned char	*win_buff;
	void			*tmp;
	int				pitch;

	SDL_LockTexture(win_tex, NULL, &tmp, &pitch);
	win_buff = (unsigned char *)tmp;
	if (!draw_scene(scene, win_buff, pitch))
	{
		SDL_UnlockTexture(win_tex);
		return (0);
	}
	SDL_UnlockTexture(win_tex);
	return (1);
}

void				init_exit(t_scene *scene, t_sdl_sequence sq)
{
	free_scene(scene);
	end_sdl(sq);
	ft_putstr("sdl initialisation error\n");
	exit(EXIT_FAILURE);
}

int					main(int argc, char **argv)
{
	t_sdl_sequence	sq;
	t_scene			scene;

	if (argc != 2)
		ft_error(NULL);
	scene = read_scene(argv[1]);
	if (!init_sdl_sequence(&sq))
		init_exit(&scene, sq);
	draw_to_texture(scene, sq.win_tex);
	while (!(SDL_PollEvent(&(sq.event)) && sq.event.type == SDL_QUIT))
	{
		if (!control(sq.event, &scene, sq.win_tex))
			break ;
		if (control(sq.event, &scene, sq.win_tex) < 0)
			draw_exit(&scene, sq);
		SDL_RenderCopy(sq.renderer, sq.win_tex, NULL, NULL);
		show_help_panel(&sq);
		SDL_RenderPresent(sq.renderer);
	}
	SDL_RenderPresent(sq.renderer);
	free_scene(&scene);
	end_sdl(sq);
	return (0);
}
