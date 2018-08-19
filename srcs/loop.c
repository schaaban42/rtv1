/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 15:14:06 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/03 16:04:23 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				sdl_loop(t_rt *rt)
{
	SDL_Surface		*screen;

	if (!(screen = SDL_GetWindowSurface(rt->win)))
		error_handler(RT_ERR_MALLOC, rt);
	while (!rt->exit)
	{
		sdl_events(rt);
		SDL_BlitSurface(rt->render, NULL, screen, NULL);
		SDL_UpdateWindowSurface(rt->win);
	}
}
