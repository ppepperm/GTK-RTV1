/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_panel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 00:26:21 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/28 00:38:16 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void    write_aut(t_sdl_sequence *sq, TTF_Font * fnt)
{
    SDL_Rect rect;
	
	rect.x = 0;
	rect.y = 600;
	rect.w = W_W;
	rect.h = W_H;
	SDL_Color color = { 255, 255, 255, 255 };
    SDL_Surface *surf = TTF_RenderText_Solid(fnt, \
		"RT project was created by:", color);
	SDL_Texture * text = SDL_CreateTextureFromSurface(sq->renderer, surf);
	SDL_QueryTexture(text, NULL, NULL, &(rect.w), &(rect.h));
	SDL_Rect rct = {rect.x, rect.y, rect.w, rect.h};
	SDL_RenderCopy(sq->renderer, text, NULL, &rct);
    SDL_Surface *surf0 = TTF_RenderText_Solid(fnt, \
		"gjigglyp\tjablilbo\tsreyne\tppepperm", color);
	SDL_Texture * text0 = SDL_CreateTextureFromSurface(sq->renderer, surf0);
	SDL_QueryTexture(text0, NULL, NULL, &(rect.w), &(rect.h));
	SDL_Rect rct0 = {rect.x, rect.y + 30, rect.w, rect.h};
	SDL_RenderCopy(sq->renderer, text0, NULL, &rct0);
	SDL_DestroyTexture(text);
	SDL_FreeSurface(surf);
}

void    show_cont_guide(t_sdl_sequence *sq, TTF_Font * fnt)
{
	SDL_Rect rect;
	
	rect.x = 0;
	rect.y = 600;
	rect.w = W_W;
	rect.h = W_H;
	SDL_Color color = { 255, 255, 255, 255 };
    SDL_Surface *surf2 = TTF_RenderText_Solid(fnt, \
		"Arrows - moving camera", color);
	SDL_Texture * text2 = SDL_CreateTextureFromSurface(sq->renderer, surf2);
	SDL_QueryTexture(text2, NULL, NULL, &(rect.w), &(rect.h));
	SDL_Rect rct2 = {rect.x + 400, rect.y, 200, rect.h};
	SDL_RenderCopy(sq->renderer, text2, NULL, &rct2);
    SDL_Surface *surf3 = TTF_RenderText_Solid(fnt, \
		"ESC - close the program", color);
	SDL_Texture * text3 = SDL_CreateTextureFromSurface(sq->renderer, surf3);
	SDL_QueryTexture(text3, NULL, NULL, &(rect.w), &(rect.h));
	SDL_Rect rct3 = {rect.x + 400, rect.y + 30, 200, rect.h};
	SDL_RenderCopy(sq->renderer, text3, NULL, &rct3);
	SDL_RenderPresent(sq->renderer);
}