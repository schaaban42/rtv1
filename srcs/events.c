/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:57:19 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/12 00:54:00 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			s_events_keys(t_rt *rt)
{
	if (rt->event.key.keysym.sym == SDLK_ESCAPE)
	{
		rt->exit = 1;
	}
	if (rt->event.key.keysym.sym == SDLK_e)
	{
		ft_put_pixel(264, 305, 0xffffffff, rt);
	}
	if (rt->event.key.keysym.sym == SDLK_r)
	{
		ft_clear_screen(0xffffffff, rt);
	}
}

static void			s_events_win(t_rt *rt)
{
	if (rt->event.type == SDL_WINDOWEVENT)
	{
		if (rt->event.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			rt->exit = 1;
		}
	}
	if (rt->event.type == SDL_QUIT)
	{
		rt->exit = 1;
	}

}

void				sdl_events(t_rt *rt)
{
	while (SDL_PollEvent(&rt->event))
	{
		s_events_win(rt);
		if (rt->event.type == SDL_KEYDOWN)
			s_events_keys(rt);
	}
}
