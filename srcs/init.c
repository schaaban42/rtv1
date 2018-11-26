/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 16:41:47 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/21 18:43:15 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			s_init_camera(t_rt *rt)
{
	rt->camera.pos = (t_v3){0, 0, 0};
	rt->camera.rot = (t_v3){0, 0, 0};
	rt->camera.dir = v3_normalized((t_v3){0, 0, 1});
	rt->camera.v_up = v3_rot_x(rt->camera.dir, -90);
	rt->camera.v_right = v3_rot_y(rt->camera.dir, 90);
	rt->camera.fov = 70;
	rt->camera.vp_dist = ((double)RT_BASE_WIDTH / 2.0)
		/ tan(to_rad(rt->camera.fov / 2.0));
}

void				rtv1_init(t_rt *rt)
{
	rt->w = 640;
	rt->h = 480;
	rt->exit = 0;
	rt->light.pos = (t_v3){0, 0, 0};
	s_init_camera(rt);
}
