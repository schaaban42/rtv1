/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:49:18 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/02 17:04:30 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				sdl_init(t_rt *rt)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		error_handler(RT_ERR_SDL_INIT, rt);
	rt->win = SDL_CreateWindow("RT - v1",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		rt->w, rt->h, SDL_WINDOW_SHOWN);
	rt->render = SDL_CreateRGBSurface(0, rt->w, rt->h, 32,
		RT_SDL_RMASK, RT_SDL_GMASK, RT_SDL_BMASK, RT_SDL_AMASK);
	if (!rt->win || !rt->render)
		error_handler(RT_ERR_MALLOC, rt);
}
