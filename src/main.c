/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:11:29 by ppepperm          #+#    #+#             */
/*   Updated: 2021/02/21 16:51:13 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		show_help(t_sdl_sequence *sq)
{
	SDL_Rect rect;
	rect.x = 1080;
	rect.y = 1;
	rect.w = 360;
	rect.y = 720;
	SDL_SetRenderDrawColor(sq->renderer, 255, 0, 0, 255);
	SDL_Color color = { 255, 255, 255, 255 };
	TTF_Font *font = TTF_OpenFont("Arial.ttf", 14);
    SDL_Surface *surf = TTF_RenderText_Blended(font, "Authors:\ngjigglyp\njablilbo\nsreyne\nppepperm\n", color);
	SDL_CreateTextureFromSurface(sq->renderer, surf);
	SDL_RenderClear(sq->renderer);
	SDL_RenderFillRect(sq->renderer, &rect);
	SDL_RenderPresent(sq->renderer);
}

int			init_sdl_sequence(t_sdl_sequence *sq)
{
	sq->window = NULL;
	sq->renderer = NULL;
	sq->win_tex = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (0);
	sq->window = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,\
	SDL_WINDOWPOS_UNDEFINED, 1440, W_H, SDL_WINDOW_SHOWN);
	sq->renderer = SDL_CreateRenderer(sq->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(sq->renderer, 0xff, 0xff, 0xff, 0xff);
	show_help(sq);
	SDL_RenderClear(sq->renderer);
	sq->win_tex = SDL_CreateTexture(sq->renderer,\
	SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, 1440, W_H);
	if (!sq->window || !sq->renderer || !sq->win_tex)
		return (0);
	return (1);
}

int			draw_to_texture(t_scene scene, SDL_Texture *win_tex)
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

void		init_exit(t_scene *scene, t_sdl_sequence sq)
{
	free_scene(scene);
	end_sdl(sq);
	ft_putstr("sdl initialisation error\n");
	exit(EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	t_sdl_sequence	sq;
	t_scene			scene;

	if (argc != 2)
		ft_error(NULL);
	validation(argv[1]);
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
		SDL_RenderPresent(sq.renderer);
	}
	free_scene(&scene);
	end_sdl(sq);
	return (0);
}
