/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 15:14:06 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/16 19:00:36 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				sdl_loop(t_rt *rt)
{
	while (!rt->exit)
	{
		sdl_events(rt);
		SDL_UpdateWindowSurface(rt->win);
	}
}
