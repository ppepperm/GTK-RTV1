/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_panel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 00:26:21 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/28 15:07:20 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			write_aut(t_sdl_sequence *sq, TTF_Font *fnt, SDL_Color color)
{
	SDL_Rect	rect[2];
	SDL_Surface	*surf[2];
	SDL_Texture	*text[2];

	rect[0].x = 0;
	rect[0].y = 600;
	rect[0].w = 360;
	rect[0].h = W_H;
	rect[1].x = rect[0].x;
	rect[1].y = rect[0].y + 30;
	rect[1].w = rect[0].w;
	rect[1].h = rect[0].h;
	surf[0] = TTF_RenderText_Solid(fnt, \
		"RT project was created and developed by:", color);
	text[0] = SDL_CreateTextureFromSurface(sq->renderer, surf[0]);
	SDL_QueryTexture(text[0], NULL, NULL, &(rect[0].w), &(rect[0].h));
	SDL_RenderCopy(sq->renderer, text[0], NULL, &rect[0]);
	surf[1] = TTF_RenderText_Solid(fnt, \
		"gjigglyp\tjablilbo\tsreyne\tppepperm", color);
	text[1] = SDL_CreateTextureFromSurface(sq->renderer, surf[1]);
	SDL_QueryTexture(text[1], NULL, NULL, &(rect[1].w), &(rect[1].h));
	SDL_RenderCopy(sq->renderer, text[1], NULL, &rect[1]);
	SDL_DestroyTexture(text[0]);
	SDL_FreeSurface(surf[0]);
}

void			show_cont_guide(t_sdl_sequence *sq, TTF_Font *fnt,\
						SDL_Color color)
{
	SDL_Rect	rect[2];
	SDL_Surface	*surf2[2];
	SDL_Texture	*text2[2];

	rect[0].x = 360;
	rect[0].y = 600;
	rect[0].w = W_W;
	rect[0].h = W_H;
	rect[1].x = rect[0].x;
	rect[1].y = rect[0].y + 30;
	rect[1].w = W_W - rect[0].x;
	rect[1].h = rect[0].h;
	surf2[0] = TTF_RenderText_Solid(fnt, "Arrows - moving the camera", color);
	text2[0] = SDL_CreateTextureFromSurface(sq->renderer, surf2[0]);
	SDL_QueryTexture(text2[0], NULL, NULL, &(rect[0].w), &(rect[0].h));
	SDL_RenderCopy(sq->renderer, text2[0], NULL, &rect[0]);
	surf2[1] = TTF_RenderText_Solid(fnt, "ESC - stop the program", color);
	text2[1] = SDL_CreateTextureFromSurface(sq->renderer, surf2[1]);
	SDL_QueryTexture(text2[1], NULL, NULL, &(rect[1].w), &(rect[1].h));
	SDL_RenderCopy(sq->renderer, text2[1], NULL, &rect[1]);
	SDL_RenderPresent(sq->renderer);
	SDL_RenderPresent(sq->renderer);
}

void			show_cont_guide2(t_sdl_sequence *sq, TTF_Font *fnt,\
						SDL_Color color)
{
	SDL_Rect	rect[2];
	SDL_Surface	*surf3[2];
	SDL_Texture	*text3[2];

	rect[0].x = 600;
	rect[0].y = 600;
	rect[0].w = W_W;
	rect[0].h = W_H;
	rect[1].x = rect[0].x;
	rect[1].y = rect[0].y + 30;
	rect[1].w = W_W - rect[0].x;
	rect[1].h = rect[0].h;
	surf3[0] = TTF_RenderText_Solid(fnt, "W - zoom in", color);
	text3[0] = SDL_CreateTextureFromSurface(sq->renderer, surf3[0]);
	SDL_QueryTexture(text3[0], NULL, NULL, &(rect[0].w), &(rect[0].h));
	SDL_RenderCopy(sq->renderer, text3[0], NULL, &rect[0]);
	surf3[1] = TTF_RenderText_Solid(fnt, "X - zoom out", color);
	text3[1] = SDL_CreateTextureFromSurface(sq->renderer, surf3[1]);
	SDL_QueryTexture(text3[1], NULL, NULL, &(rect[1].w), &(rect[1].h));
	SDL_RenderCopy(sq->renderer, text3[1], NULL, &rect[1]);
	SDL_RenderPresent(sq->renderer);
	SDL_RenderPresent(sq->renderer);
}

void			show_cont_guide3(t_sdl_sequence *sq, TTF_Font *fnt,\
						SDL_Color color)
{
	SDL_Rect	rect[2];
	SDL_Surface	*surf3[2];
	SDL_Texture	*text3[2];

	rect[0].x = 360;
	rect[0].y = 660;
	rect[0].w = W_W;
	rect[0].h = W_H;
	rect[1].x = 600;
	rect[1].y = rect[0].y;
	rect[1].w = W_W - rect[0].x;
	rect[1].h = rect[0].h;
	surf3[0] = TTF_RenderText_Solid(fnt, "Q/E - tilt the camera", color);
	text3[0] = SDL_CreateTextureFromSurface(sq->renderer, surf3[0]);
	SDL_QueryTexture(text3[0], NULL, NULL, &(rect[0].w), &(rect[0].h));
	SDL_RenderCopy(sq->renderer, text3[0], NULL, &rect[0]);
	surf3[1] = TTF_RenderText_Solid(fnt, "Left or right mouse button - click on the shape", color);
	text3[1] = SDL_CreateTextureFromSurface(sq->renderer, surf3[1]);
	SDL_QueryTexture(text3[1], NULL, NULL, &(rect[1].w), &(rect[1].h));
	SDL_RenderCopy(sq->renderer, text3[1], NULL, &rect[1]);
	SDL_RenderPresent(sq->renderer);
	SDL_RenderPresent(sq->renderer);
}

void			show_cont_guide4(t_sdl_sequence *sq, TTF_Font *fnt,\
						SDL_Color color)
{
	SDL_Rect	rect;
	SDL_Surface	*surf;
	SDL_Texture	*text;

	rect.x = 360;
	rect.y = 690;
	rect.w = W_W;
	rect.h = W_H;
	surf = TTF_RenderText_Solid(fnt, "A/S/D/W - move the clicked shape", color);
	text = SDL_CreateTextureFromSurface(sq->renderer, surf);
	SDL_QueryTexture(text, NULL, NULL, &(rect.w), &(rect.h));
	SDL_RenderCopy(sq->renderer, text, NULL, &rect);
	SDL_RenderPresent(sq->renderer);
	SDL_RenderPresent(sq->renderer);
}
