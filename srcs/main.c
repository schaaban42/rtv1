/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:38:34 by schaaban          #+#    #+#             */
/*   Updated: 2018/09/26 21:31:16 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			s_init_pointers(t_rt *rt)
{
	rt->win = NULL;
	rt->render = NULL;
	rt->objs = NULL;
}

int					main(int argc, char **argv)
{
	t_rt	rt;

	s_init_pointers(&rt);
	rtv1_init(&rt);
	parse_args(&rt, argc, argv);
	sdl_init(&rt);
	rtv1_compute(&rt);
	sdl_loop(&rt);
	rtv1_exit(&rt);
	return (0);
}
