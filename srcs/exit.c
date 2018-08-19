/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:55:47 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/02 17:03:01 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			s_check_sdl(t_rt *rt)
{
	if (rt->render)
		SDL_FreeSurface(rt->render);
	if (rt->win)
		SDL_DestroyWindow(rt->win);
}

void				rtv1_exit(t_rt *rt)
{
	s_check_sdl(rt);
	SDL_Quit();
	exit(0);
}
