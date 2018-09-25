/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:38:34 by schaaban          #+#    #+#             */
/*   Updated: 2018/09/11 17:36:37 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			s_init_pointers(t_rt *rt)
{
	rt->win = NULL;
	rt->render = NULL;
}

int					main(void)
{
	t_rt	rt;

	s_init_pointers(&rt);
	rtv1_init(&rt);
	sdl_init(&rt);
	rtv1_compute(&rt);
	sdl_loop(&rt);
	rtv1_exit(&rt);
	return (0);
}
