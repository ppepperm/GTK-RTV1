/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_n_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 05:03:24 by jabilbo           #+#    #+#             */
/*   Updated: 2021/03/10 05:03:26 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	destroy_n_free(SDL_Surface *surf[2], SDL_Texture *text[2])
{
	SDL_DestroyTexture(text[0]);
	SDL_FreeSurface(surf[0]);
	SDL_DestroyTexture(text[1]);
	SDL_FreeSurface(surf[1]);
}

void	show_text_help(t_sdl_sequence *sq, TTF_Font *fnt, SDL_Color color)
{
	write_aut(sq, fnt, color);
	show_cont_guide(sq, fnt, color);
	show_cont_guide2(sq, fnt, color);
	show_cont_guide3(sq, fnt, color);
	show_cont_guide4(sq, fnt, color);
}
