/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_n_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 05:03:24 by jabilbo           #+#    #+#             */
/*   Updated: 2021/03/10 16:02:51 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
/*
void	destroy_n_free(SDL_Surface surf, SDL_Texture text)
{
	SDL_DestroyTexture(text);
	SDL_FreeSurface(surf);
}
*/
void	show_text_help(t_sdl_sequence *sq, TTF_Font *fnt, SDL_Color color)
{
	write_aut(sq, fnt, color);
	show_cont_guide(sq, fnt, color);
	show_cont_guide2(sq, fnt, color);
	show_cont_guide3(sq, fnt, color);
	show_cont_guide4(sq, fnt, color);
}
