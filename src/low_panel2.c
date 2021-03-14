/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_panel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 23:19:05 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/03/12 23:39:41 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			write_aut(t_sdl_sequence *sq, TTF_Font *fnt, SDL_Color color)
{
	SDL_Rect	rect;
	SDL_Surface	*surf;
	SDL_Texture	*text;

	rect.x = 0;
	rect.y = W_H - 120;
	rect.w = 350;
	rect.h = W_H;
	surf = TTF_RenderText_Solid(fnt, \
		"RT project was created and developed by:", color);
	text = SDL_CreateTextureFromSurface(sq->renderer, surf);
	SDL_QueryTexture(text, NULL, NULL, &(rect.w), &(rect.h));
	SDL_RenderCopy(sq->renderer, text, NULL, &rect);
	SDL_DestroyTexture(text);
	SDL_FreeSurface(surf);
}

void			write_aut2(t_sdl_sequence *sq, TTF_Font *fnt, SDL_Color color)
{
	SDL_Rect	rect2;
	SDL_Surface	*surf2;
	SDL_Texture	*text2;

	rect2.x = 0;
	rect2.y = W_H - 90;
	rect2.w = 350;
	rect2.h = W_H;
	surf2 = TTF_RenderText_Solid(fnt, \
		"gjigglyp\t\tjablilbo\t\tsreyne\t\tppepperm", color);
	text2 = SDL_CreateTextureFromSurface(sq->renderer, surf2);
	SDL_QueryTexture(text2, NULL, NULL, &(rect2.w), &(rect2.h));
	SDL_RenderCopy(sq->renderer, text2, NULL, &rect2);
	SDL_DestroyTexture(text2);
	SDL_FreeSurface(surf2);
}

void			show_cont_guide6(t_sdl_sequence *sq, TTF_Font *fnt,\
						SDL_Color color)
{
	SDL_Rect	rect;
	SDL_Surface	*surf;
	SDL_Texture	*text;

	rect.x = 700;
	rect.y = W_H - 30;
	rect.w = W_W;
	rect.h = W_H;
	surf = TTF_RenderText_Solid(fnt,\
	"J/I/K/L/O/U - change chosen shape's size", color);
	text = SDL_CreateTextureFromSurface(sq->renderer, surf);
	SDL_QueryTexture(text, NULL, NULL, &(rect.w), &(rect.h));
	SDL_RenderCopy(sq->renderer, text, NULL, &rect);
	SDL_DestroyTexture(text);
	SDL_FreeSurface(surf);
}
